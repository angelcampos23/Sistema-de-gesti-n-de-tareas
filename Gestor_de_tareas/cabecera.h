#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED



// Estructura para representar una tarea
struct Tarea {
    char titulo[50];
    int completada;
};

// Funciones y procedimientos
void agregarTarea(struct Tarea listaTareas[], int *numTareas);
void marcarComoCompletada(struct Tarea listaTareas[], int numTareas);
void listarTareasPendientes(struct Tarea listaTareas[], int numTareas);
void listarTodasTareas(struct Tarea listaTareas[], int numTareas);
void buscarTarea(struct Tarea listaTareas[], int numTareas);




#endif // CABECERA_H_INCLUDED
