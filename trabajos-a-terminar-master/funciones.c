#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"


void setearestados(EMovie* movie)
{
    int i;

    for(i=0; i<MAX; i++)
    {
        (movie+i)->estado = 0;
    }
}

int espacioLibre(EMovie* movie)
{
    int i;
    int retorno;
    int bandera = -1;

    for(i=0; i<MAX; i++)
    {
        if((movie+i)->estado == 0)
        {
            retorno = i;
            bandera = 1;
            break;
        }
    }
    if(bandera == -1)
    {
        retorno = bandera;
    }
    return retorno;
}

void NEWpelicula(EMovie* pelicula,char titulo[],char genero[],int duracion,char descripcion[],int puntaje,char link[],int estado)
{
    strcpy(pelicula->titulo,titulo);
    strcpy(pelicula->genero,genero);
    strcpy(pelicula->descripcion,descripcion);
    strcpy(pelicula->linkImagen,link);
    pelicula->duracion = duracion;
    pelicula->puntaje = puntaje;
    pelicula->estado = estado;
}

void generarArchivobinario(EMovie* movie)
{
    int i;
    FILE* Elarchivo;

        Elarchivo = fopen("archivo-binario.o","rb");
        if(Elarchivo != NULL)
        {
           Elarchivo = fopen("archivo-binario.o","wb");
           if(Elarchivo != NULL)
           {
               for(i=0;i<MAX;i++)
               {
                   if(movie->estado == 1)
                   {
                       fwrite((movie+i),sizeof(EMovie),1,Elarchivo);
                   }
               }
           }
           fclose(Elarchivo);

        }
        else
        {
             Elarchivo = fopen("archivo-binario.o","wb");
               if(Elarchivo != NULL)
               {
                   for(i=0;i<MAX;i++)
                   {
                       if(movie->estado == 1)
                       {
                           fwrite((movie+i),sizeof(EMovie),1,Elarchivo);
                       }
                   }
               }
              fclose(Elarchivo);
        }
        fclose(Elarchivo);
}

int agregarPelicula(EMovie* movie)
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[100];
    int estado;

    int ubicacion;
    int bandera = 0;

    int retorno = 0;

    if(bandera == 0)
    {
        setearestados(movie);
        bandera = 1;
    }
    ubicacion = espacioLibre(movie);
    if(ubicacion != -1)
    {
            system("cls");
            printf("ingrese el titulo: ");
            fflush(stdin);
            gets(titulo);
            printf("ingrese el genero: ");
            fflush(stdin);
            gets(genero);
            printf("ingrese la duracion: ");
            scanf("%d",&duracion);
            printf("ingrese la descripcion: ");
            fflush(stdin);
            gets(descripcion);
            printf("ingrese un puntaje: ");
            scanf("%d",&puntaje);
            printf("ingrese el Link a la imagen: ");
            fflush(stdin);
            gets(linkImagen);
            estado = 1;
            retorno= 1;

            NEWpelicula((movie+ubicacion),titulo,genero,duracion,descripcion,puntaje,linkImagen,estado);
    }
    return retorno;
}

int borrarPelicula(EMovie* movie)
{
    int i;
    int retorno = 0;
    char titulo[30];
    char confirma;

        system("cls");
        printf("PELICULAS CARGADAS:\n");
        for(i=0;i<MAX;i++)
        {
            if((movie+i)->estado == 1)
            {
                printf("%s\n",(movie+i)->titulo);
            }
        }

        printf("\n\nIngrese el titulo de la pelicula a dar de baja: ");
        fflush(stdin);
        gets(titulo);

        for(i=0;i<MAX;i++)
        {
            if(strcmp((movie+i)->titulo,titulo) == 0)
            {
                system("cls");
                printf("%s\n\n",(movie+i)->titulo);
                printf("Desea borrar la pelicula? (s/n): ");
                fflush(stdin);
                confirma = tolower(getch());

                if(confirma == 's')
                {
                   (movie+i)->estado = 0;
                   retorno = 1;
                   printf("\n\nla baja fue exitosa.\n");
                   system("pause");
                   break;
                }
                else
                {
                   printf("\n\nla baja no fue posible de realizarse.\n");
                   system("pause");
                   break;
                }
            }
        }
        if(retorno != 1)
        {
            printf("\n\nno se a encontrado ninguna pelicula con ese nombre.\n\n");
            system("pause");
        }

    return retorno;
}

void generarPagina(EMovie* lista)
{
    char nombreHTML[50];
    int i;

        system("cls");
        printf("PELICULAS A CARGAR EN HTML.\n\n");
        for(i=0;i<MAX;i++)
        {
            if((lista+i)->estado == 1)
            {
                printf("%s\n",(lista+i)->titulo);
            }
        }

        printf("\nIngrese el nombre de la pagina a crear: ");
        fflush(stdin);
        gets(nombreHTML);

        generaHTML(lista,nombreHTML);

}

void generaHTML(EMovie* lista,char nombreHTML[])
{
    char buffer[2000]={};
   // char* Ppuntaje;
   // char* Pduracion;
    char puntaje[2]= {};
    char duracion[3]= {};
    int i;
    FILE* pelicula;

        strcat(nombreHTML,".html");

        pelicula = fopen(nombreHTML,"w");
        if(pelicula != NULL)
        {
            for(i=0;i<MAX;i++)
            {
                if((lista+i)->estado == 1)
                {
                    strcat(buffer,"<html><head></head><body><article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='");
                    strcat(buffer,(lista+i)->linkImagen);
                    strcat(buffer,"'alt=''></a><h3><a href='#'>");
                    strcat(buffer,(lista+i)->titulo);
                    strcat(buffer,"</a></h3><ul><li>Género:");
                    strcat(buffer,(lista+i)->genero);
                    strcat(buffer,"</li><li>Puntaje:");

     /*Ppuntaje = */itoa((lista+i)->puntaje,puntaje,10);

                    strcat(buffer,puntaje);
                    strcat(buffer,"</li><li>Duración:");

     /*Pduracion = */itoa((lista+i)->duracion,duracion,10);

                    strcat(buffer,duracion);
                    strcat(buffer,"</li></ul><p>");
                    strcat(buffer,(lista+i)->descripcion);
                    strcat(buffer,"</p></article></body></html>");



                    fwrite(buffer,sizeof(char),strlen(buffer),pelicula);
                }
            }
        }
        fclose(pelicula);


}

