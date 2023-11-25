#include <stdio.h>
#include "cabecera.h"

int main() {
    struct Tarea listaTareas[100]; // Se supone un maximo de 100 tareas
    int numTareas = 0;
    int opcion;

    do {
        // Menu de opciones
        printf("\nBienvenido al Sistema de Gestion de Tareas!\n");
        printf("1. Agregar una nueva tarea.\n");
        printf("2. Marcar una tarea como completada.\n");
        printf("3. Listar todas las tareas pendientes.\n");
        printf("4. Listar todas las tareas.\n");
        printf("5. Buscar una tarea por titulo.\n");
        printf("6. Salir.\n");
        printf("> Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarTarea(listaTareas, &numTareas);
                break;
            case 2:
                marcarComoCompletada(listaTareas, numTareas);
                break;
            case 3:
                listarTareasPendientes(listaTareas, numTareas);
                break;
            case 4:
                listarTodasTareas(listaTareas, numTareas);
                break;
            case 5:
                buscarTarea(listaTareas, numTareas);
                break;
            case 6:
                printf("Gracias por usar el Sistema de Gestion de Tareas!\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
        }
    } while (opcion != 6);

    return 0;
}
