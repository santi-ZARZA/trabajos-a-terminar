#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Funciones.h"
///#include "LecturaArchivo.h"
#include "ArrayList.h"


int main()
{
    int continuacion = 1;
    char opcion;
    int bandera = 0;

    FILE* archivo;
    ArrayList* lista_alumnos = al_newArrayList();
    eAlumno* alumno;


    do
    {
        system("cls");
        printf("1- Cargar Alumnos\n");
        printf("2- Mostrar Alumnos\n");
        printf("3- Cambiar Nota Alumno\n");
        printf("4- Finales\n");
        printf("5- Salir\n");
        printf("\nIngrese la opcion deseada: ");
        opcion = getch();

        switch(opcion)
        {
            case '1':
                if(Lectuta(lista_alumnos,alumno,archivo) != -1)
                {
                    system("cls");
                    printf("\nCarga exitosa\n\n");
                    system("pause");
                    bandera = 1;
                }
                break;
            case '2':
                mostrar(lista_alumnos);
                system("pause");
                break;
            case '3':
                cambiarNota(lista_alumnos);
                break;
            case '4':
                if(bandera == 1)
                {
                    Finales(lista_alumnos,archivo);
                }
               else
               {
                   system("cls");
                   printf("\nNo se a cargado los alumnos para poder promediar los finales.\n\n");
                   system("pause");
               }
                break;
            case '5':
                continuacion = 0;
                break;
            default:
                printf("\n\nOpcion invalida.\n");
                system("pause");
        }

    }while(continuacion == 1);



    return 0;
}
