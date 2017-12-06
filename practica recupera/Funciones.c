#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Funciones.h"
#include "ArrayList.h"

int Lectuta(ArrayList* lista,eAlumno* alumnos, FILE* archivo)
{
    int retorno = 0;



    ///int cont = 0;

    char identificador[2],nombres[20],apellidos[20],nota1[2],nota2[2];


        archivo = fopen("archivo que quiero leer.csv","r");

        if(archivo != NULL && lista != NULL)
        {
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",identificador,nombres,apellidos,nota1,nota2);

            while(!feof(archivo))
            {
                alumnos = newAlumno();
                if(alumnos != NULL)
                {
                    fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",identificador,nombres,apellidos,nota1,nota2);

                    alumnos->Alumno = atoi(identificador);
                    strcpy(alumnos->Nombre,nombres);
                    strcpy(alumnos->apellido,apellidos);
                    alumnos->nota_1 = atoi(nota1);
                    alumnos->nota_2 = atoi(nota2);


                    al_add(lista,alumnos);
                }
                else
                {
                    retorno = -1;
                }
            }
        }
        else
        {
            retorno = -1;
        }

        fclose(archivo);


    return retorno;
}

eAlumno* newAlumno()
{
    eAlumno* Auxiliar;

        Auxiliar = (eAlumno*) malloc(sizeof(eAlumno));

    return  Auxiliar;
}

void mostrar(ArrayList* lista)
{
    int i;
    eAlumno* aux;

    if(lista != NULL)
    {
        if(al_isEmpty(lista)== 0)
        {
            system("cls");
            printf("ALUMNOS\n");
            printf("----------------------------------------------------\n\n");
            for(i=0;i<al_len(lista);i++)
            {
                aux = (eAlumno*) al_get(lista,i);

                printf("Nombre: %s  Apellido: %s Parcial 1: %d Parcial 2: %d\n",aux->Nombre,aux->apellido,aux->nota_1,aux->nota_2);
                printf("----------------------------------------------------\n");
            }

        }
        else
        {
            system("cls");
            printf("\nno hay alumnos que Mostrar.\n");
            system("pause");
        }
    }
    else
    {
        system("cls");
        printf("\nhubo un error.\n");
        system("pause");
    }
}

void cambiarNota(ArrayList* lista)
{
    eAlumno* auxliar;
    int nota1,nota2;
    int opcion;
    char opcion2;
    int i;

        if(lista != NULL)
        {
             system("cls");
            printf("ALUMNOS\n");
            printf("----------------------------------------------------\n\n");
            for(i=0;i<al_len(lista);i++)
            {
                auxliar = (eAlumno*) al_get(lista,i);

                printf("[%d]--> Nombre: %s  Apellido: %s \n",i,auxliar->Nombre,auxliar->apellido);
                printf("----------------------------------------------------\n");
            }
            printf("\nIngrese la Posicion de el alumno a cambiar nota\as : ");
            scanf("%d",&opcion);

            auxliar = (eAlumno*) al_pop(lista,opcion);

            system("cls");
            printf("%s      %s\n\n",auxliar->Nombre,auxliar->apellido);
            printf("1- cambiar Nota parcial 1\n");
            printf("2- cambiar Nota parcial 2\n");
            printf("3- cambiar notas parciales\n");
            opcion2 = getch();

            switch(opcion2)
            {
                case '1':
                    system("cls");
                    printf("ingrese la nueva nota del alumno: ");
                    scanf("%d",&nota1);

                    auxliar->nota_1 = nota1;

                    al_push(lista,opcion,auxliar);
                    break;
                case '2':
                    system("cls");
                    printf("ingrese la nueva nota del alumno: ");
                    scanf("%d",&nota2);

                    auxliar->nota_2 = nota2;

                    al_push(lista,opcion,auxliar);
                    break;
                case '3':
                    system("cls");
                    printf("ingrese la 1° nueva nota del alumno: ");
                    scanf("%d",&nota1);
                    printf("ingrese la 2° nueva nota del alumno: ");
                    scanf("%d",&nota2);

                    auxliar->nota_1 = nota1;
                    auxliar->nota_2 = nota2;

                    al_push(lista,opcion,auxliar);
                    break;
                default:
                    printf("\n\nopcion ingresada invalida\n\n");
            }


        }
}

void Finales(ArrayList* lista,FILE* archivo)
{
    int i;
    ///int cont = 0;

    eAlumno* auxiliar;

        if(lista != NULL)
        {
            archivo = fopen("Finales.txt","w");
            if(archivo != NULL)
            {
                for(i=0;i<al_len(lista);i++)
                {
                    auxiliar = (eAlumno*) al_get(lista,i);

                    if(auxiliar->nota_1 > 3 && auxiliar->nota_2 > 3)
                    {
                        fprintf(archivo,"%d     %s      %s\n",auxiliar->Alumno,auxiliar->Nombre,auxiliar->apellido);
                    }
                }
            }
            fclose(archivo);

        }
}
