#include "ArrayList.h"
typedef struct
{
    int Alumno;
    char Nombre[20];
    char apellido[20];
    int nota_1;
    int nota_2;
}eAlumno;

//typedef struct
//{
//    int Alumno;
//    int nota_1;
//    int nota_2;
//}eNotas;

int Lectuta(ArrayList*,eAlumno*,FILE*);

eAlumno* newAlumno();
void mostrar(ArrayList*);
void cambiarNota(ArrayList*);
void Finales(ArrayList*,FILE*);



