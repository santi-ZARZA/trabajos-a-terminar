#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


void setearestados(EMovie* movie)
{
    int i;

        for(i=0;i<MAX;i++)
        {
            (movie+i)->estado = 0;
        }
}

void NEWpelicula(EMovie* movie,char titulo[],char genero[],int duracion,char descripcion[],int puntaje,char linkImagen[],int estado)
{
    strcpy(movie->titulo,titulo);
    strcpy(movie->genero,genero);
    movie->duracion = duracion;
    strcpy(movie->descripcion,descripcion);
    movie->puntaje = puntaje;
    strcpy(movie->linkImagen,linkImagen);
    movie->estado = estado;
}

int espacioLibre(EMovie* movie)
{
    int i;
    int retorno;
    int bandera = -1;

        for(i=0;i<MAX;i++)
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
    FILE* pArchivo;

    int retorno = 0;

    if(bandera == 0)
    {
        setearestados(movie);
        bandera = 1;
    }

    system("cls");
        pArchivo = fopen("archivo-binario.o","rb");

            if(pArchivo != NULL)
            {
                pArchivo = fopen("archivo-binario.o","wb");

                    if(pArchivo != NULL)
                    {
                        ubicacion = espacioLibre(movie);

                            if(ubicacion != -1)
                            {
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

                                    NEWpelicula((movie+ubicacion),titulo,genero,duracion,descripcion,puntaje,linkImagen,estado);

                                    fwrite((movie+ubicacion),sizeof(EMovie),1,pArchivo);
                                    fprintf(pArchivo,"\n\n");

                                    retorno = 1;
                            }
                            else
                            {
                                system("cls");
                                printf("No hay espacio para cargar mas peliculas.\n\n");
                                system("pause");
                            }
                    }
                    else
                    {
                        system("cls");
                        printf("el archivo no pudo ser abierto.\n\n");
                        system("pause");
                    }

                fclose(pArchivo);
            }
            else
            {
                pArchivo = fopen("archivo-binario.o","wb");

                    if(pArchivo != NULL)
                    {
                        ubicacion = espacioLibre(movie);

                            if(ubicacion != -1)
                            {
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

                                    NEWpelicula((movie+ubicacion),titulo,genero,duracion,descripcion,puntaje,linkImagen,estado);

                                    fwrite((movie+ubicacion),sizeof(EMovie),1,pArchivo);
                                    fprintf(pArchivo,"\n\n");

                                    retorno = 1;
                            }
                            else
                            {
                                system("cls");
                                printf("No hay espacio para cargar mas peliculas.\n\n");
                                system("pause");
                            }
                    }
                    else
                    {
                        system("cls");
                        printf("el archivo no pudo ser creado.\n\n");
                        system("pause");
                    }

                fclose(pArchivo);
            }


        fclose(pArchivo);

    return retorno;
}

int borrarPelicula(EMovie* movie);

void generarPagina(EMovie* lista)
{
    int i;

    int contado= 0;

    char nombrearchivo[50];

    EMovie auxiliar_html[MAX];
    FILE* pArchivo;
    FILE*pArchivo_HTML;

        system("cls");

            pArchivo = fopen("archivo-binario.o","rb");

            if(pArchivo != NULL)
            {
                printf("peliculas a cargar en el HTML:\n\n");
                for(i=0;i<MAX;i++)
                {
                    if((lista+i)->estado == 1)
                    {
                        printf("%s\n",(lista+i)->titulo);
                    }
                }
                printf("\n\ningrese el nombre del archivo a crear: ");
                fflush(stdin);
                gets(nombrearchivo);

                strcat(nombrearchivo,".html");

                i=0;
                while(!feof(pArchivo))
                {
                    fread((auxiliar_html+i),sizeof(EMovie),1,pArchivo);
                    i++;
                }

                /////////"continuar desde aca"/////////////////
            }
            else
            {
                system("cls");
                printf("No hay ninguna pelicula cargada.\n\n");
                system("pause");
            }

            fclose(pArchivo);




}

