#ifndef FUNCIONES_C_INCLUDED
#define FUNCIONES_C_INCLUDED

#include "cabecera.h"
#include <stdio.h>
#include <string.h>

void agregarTarea(struct Tarea listaTareas[], int *numTareas) {
    printf("Ingrese el titulo de la tarea: ");
    scanf("%s", listaTareas[*numTareas].titulo);
    listaTareas[*numTareas].completada = 0; // La tarea se agrega como pendiente inicialmente
    (*numTareas)++;
    printf("Tarea agregada con exito.\n");
}

void marcarComoCompletada(struct Tarea listaTareas[], int numTareas) {
    int numTarea;
    listarTodasTareas(listaTareas, numTareas);
    printf("Ingrese el numero de la tarea que desea marcar como completada: ");
    scanf("%d", &numTarea);

    if (numTarea >= 1 && numTarea <= numTareas) {
        listaTareas[numTarea - 1].completada = 1;
        printf("Tarea marcada como completada.\n");
    } else {
        printf("Numero de tarea no valido.\n");
    }
}

void listarTareasPendientes(struct Tarea listaTareas[], int numTareas) {
    printf("Tareas pendientes:\n");
    for (int i = 0; i < numTareas; i++) {
        if (listaTareas[i].completada == 0) {
            printf("%d. %s (pendiente)\n", i + 1, listaTareas[i].titulo);
        }
    }
}

void listarTodasTareas(struct Tarea listaTareas[], int numTareas) {
    printf("Todas las tareas:\n");
    for (int i = 0; i < numTareas; i++) {
        printf("%d. %s (%s)\n", i + 1, listaTareas[i].titulo,
               listaTareas[i].completada ? "completada" : "pendiente");
    }
}

// Funcion recursiva para buscar una tarea por titulo
int buscarTareaRecursiva(struct Tarea listaTareas[], int inicio, int fin, char tituloBuscar[]) {
    if (inicio > fin) {
        return -1; // Tarea no encontrada
    }

    int medio = (inicio + fin) / 2;

    if (strcmp(listaTareas[medio].titulo, tituloBuscar) == 0) {
        return medio; // Tarea encontrada
    } else if (strcmp(listaTareas[medio].titulo, tituloBuscar) > 0) {
        return buscarTareaRecursiva(listaTareas, inicio, medio - 1, tituloBuscar);
    } else {
        return buscarTareaRecursiva(listaTareas, medio + 1, fin, tituloBuscar);
    }
}

// Funcion principal para buscar una tarea
void buscarTarea(struct Tarea listaTareas[], int numTareas) {
    char tituloBuscar[50];
    printf("Ingrese el titulo de la tarea que desea buscar: ");
    scanf("%s", tituloBuscar);

    int resultado = buscarTareaRecursiva(listaTareas, 0, numTareas - 1, tituloBuscar);

    if (resultado != -1) {
        printf("La tarea \"%s\" se encuentra en la lista y esta %s.\n", listaTareas[resultado].titulo,
               listaTareas[resultado].completada ? "completada" : "pendiente");
    } else {
        printf("La tarea \"%s\" no se encontro en la lista.\n", tituloBuscar);
    }
}


#endif // FUNCIONES_C_INCLUDED
