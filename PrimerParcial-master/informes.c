#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define LIBRE 0
#define OCUPADO 1
#include "orquesta.h"
#include "musico.h"
#include "informes.h"

int mus_listaOrquestasConMasDeCincoMusicos(Musico* listMusicos,int lenMusico,Orquesta* listOrquestas, int lenOrquesta)
{
    int retorno=-1;
    int i,j;
    int cantidadDeMusicos;
    if(listMusicos!=NULL && lenMusico>0 && listOrquestas!=NULL && lenOrquesta>0)
    {
        for(i=0; i<lenOrquesta; i++)
        {
            cantidadDeMusicos=0;
            for(j=0; j<lenMusico; j++)
            {
                if(listOrquestas[i].idOrquesta==listMusicos[j].idOrquesta)
                {
                    cantidadDeMusicos++;
                }
            }
            if(cantidadDeMusicos>3&&listOrquestas[i].isEmpty==OCUPADO)
            {
                // printf("este tiene mas de 5\n");
                printf("\nNombre: %s\nLugar: %s\nTipo: %d\nId Orquesta: %d\n",
                       listOrquestas[i].name,listOrquestas[i].lugar,listOrquestas[i].tipo,listOrquestas[i].idOrquesta);
                retorno=0;
            }
        }
    }
    return retorno;
}

int mus_listarMusicoMayorDeTreintaDeEdad(Musico* list,int len)
{
    int retorno=-1;
    int i;
    int cantidadOrquesta=0;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==OCUPADO)
            {
                if(list[i].edad>30)
                {
                    printf("\nID: %d\nNombre: %s\nApellido: %s\nEdad: %d\nId Instrumento : %d\nId Orquesta : %d\n",
                           list[i].idMusico,list[i].name,list[i].lastName,list[i].edad,list[i].idInstrumento,list[i].idOrquesta);
                    cantidadOrquesta++;
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}

int mus_listarMusicoPorUnaOrquestaDeterminada(Musico* listMusico,int lenMusico,int auxIdOrquesta,Instrumento* listInstrumento,int lenIstrumento)
{
    int retorno=-1;
    int i;
    if(listMusico!=NULL && lenMusico>0 && auxIdOrquesta>0 &&listInstrumento!=NULL)
    {
        for(i=0; i<lenMusico; i++)
            if(listMusico[i].idOrquesta==auxIdOrquesta)
            {
                printf("\nNombre: %s\nApellido: %s\nEdad: %d\n",listMusico[i].name,listMusico[i].lastName,listMusico[i].edad);
                ins_mostrarInstrumentoPorId(listInstrumento,lenIstrumento,listMusico[i].idInstrumento);
            }
        retorno=0;
    }
    return retorno;
}

int printOrquestaConMasMusicos(Musico* listMusico,int lenMusico,Orquesta* listOrquesta,int lenOrquesta)
{
    int retorno=-1;
    int i,j;
    int cantidadMusico;
    int cantidadMusicoMax=0;
    int idOrquestaConMasMusicos;
    if(listMusico!=NULL && lenMusico>0 && listOrquesta!=NULL && lenOrquesta>0)
    {
        for(i=0; i<lenOrquesta; i++)
        {
            cantidadMusico=0;
            for(j=0; j<lenMusico; j++)
            {
                if((listOrquesta[i].idOrquesta==listMusico[j].idOrquesta)  && (listMusico[j].isEmpty==OCUPADO))
                {
                    cantidadMusico++;
                }
            }
            if(cantidadMusico>cantidadMusicoMax)
            {
                cantidadMusicoMax=cantidadMusico;
                idOrquestaConMasMusicos=listOrquesta[i].idOrquesta;
            }
        }
        if(cantidadMusicoMax!=0)
        {
            orq_mostrarOrquestaPorId(listOrquesta,lenOrquesta,idOrquestaConMasMusicos);
            printf("Cantidad %d\n",cantidadMusicoMax);
            mus_mostrarMusicosPorIdDeOrquesta(listMusico,lenMusico,idOrquestaConMasMusicos);
            retorno=0;
        }
    }
    return retorno;
}

int mus_mostrarMusicosPorIdDeOrquesta(Musico* listMusicos,int lenMusico,int idOrquesta)
{
    int retorno=-1;
    int i;
    if(listMusicos!=NULL && lenMusico>0 && idOrquesta>0)
    {
        for(i=0; i<lenMusico; i++)
        {
            if(listMusicos[i].idOrquesta==idOrquesta && listMusicos[i].isEmpty==OCUPADO)
            {
                mus_mostrarMusicoPorId(listMusicos,lenMusico,listMusicos[i].idMusico);
                retorno=0;
            }
        }
    }
    return retorno;
}

int listarMusicosQueTocanInstCuerda(Musico* listMusico,int lenMusico,Instrumento* listInstrumento,int lenInstrumento)
{
    int retorno=-1;
    int i,j;
    if(listMusico!=NULL && lenMusico>0 && listInstrumento!=NULL && lenInstrumento>0)
    {
        for(i=0; i<lenInstrumento; i++)
        {
            for(j=0; j<lenMusico; j++)
            {
                if(listInstrumento[i].idInstrumento==listMusico[j].idInstrumento)
                {
                    if(listInstrumento[i].tipo==1 && listMusico[j].isEmpty==OCUPADO)
                    {
                        printf("\nNombre: %s\nApellido: %s\nEdad: %d\n",listMusico[j].name,listMusico[j].lastName,listMusico[j].edad);
                        printf("Nombre: %s\nId instrumento: %d\n",listInstrumento[i].name,listInstrumento[i].idInstrumento);
                        retorno=0;
                    }
                }
            }

        }
    }
    return retorno;
}

int orquestaCompleta(Musico* listMusico,int lenMusico,Orquesta* listOrquesta,int lenOrquesta,Instrumento* listInstrumento,int lenInstrumento)
{
    int retorno=-1;
    int i,j,k;
    int cantidadInstrumentoDeCuerda;
    int cantidadInstrumentoDeViento;
    int cantidadInstrumentoDePercusion;
    if(listMusico!=NULL && lenMusico>0 && listOrquesta!=NULL && lenOrquesta>0 && listInstrumento && lenInstrumento>0)
    {
        for(i=0; i<lenOrquesta; i++)
        {
            cantidadInstrumentoDeCuerda=0;
            cantidadInstrumentoDePercusion=0;
            cantidadInstrumentoDeViento=0;
            for(j=0; j<lenInstrumento; j++)
            {
                for(k=0; k<lenMusico; k++)
                {
                    if(listOrquesta[i].idOrquesta==listMusico[k].idOrquesta &&
                            listInstrumento[j].idInstrumento==listMusico[k].idInstrumento)
                    {
                        if(listInstrumento[j].tipo==1)
                        {
                            cantidadInstrumentoDeCuerda++;
                        }
                        else if((listInstrumento[j].tipo==2 && listInstrumento[j].tipo==3) ||
                                (listInstrumento[j].tipo==2 || listInstrumento[j].tipo==3))
                        {
                            cantidadInstrumentoDeViento++;
                        }
                        else if(listInstrumento[j].tipo==4)
                        {
                            cantidadInstrumentoDePercusion++;
                        }
                    }
                }
            }
            if(cantidadInstrumentoDeCuerda>4 && listMusico[k].isEmpty==OCUPADO)
            {
                if(cantidadInstrumentoDeViento>2 && listMusico[k].isEmpty==OCUPADO)
                {
                    if(cantidadInstrumentoDePercusion>1 && listMusico[k].isEmpty==OCUPADO)
                    {
                        printf("--------------------------------------------------");
                        printf("\n\tORQUESTAS COMPLETAS\n");
                        printf("\nId Orquesta: %d\nNombre: %s\nLugar: %s\nTipo: %d\n",
                               listOrquesta[i].idOrquesta,listOrquesta[i].name,listOrquesta[i].lugar,listOrquesta[i].tipo);
                        printf("--------------------------------------------------");
                        retorno=0;
                    }
                }
            }
        }
    }
    return retorno;
}

int promedioDeMusicoPorOrquesta(Musico* listMusico,int lenMusico,Orquesta* listOrquesta,int lenOrquesta)
{
    int retorno=-1;
    int i,j;
    float cantidadMusicos=0;
    float cantidadOrquesta=0;
    if(listMusico!=NULL && lenMusico>0 && listOrquesta!=NULL && lenOrquesta>0)
    {
        for(i=0;i<lenOrquesta;i++)
        {
            if(listOrquesta[i].isEmpty==OCUPADO)
            {
                cantidadOrquesta++;
            }
        }
        for(j=0;j<lenMusico;j++)
        {
            if(listMusico[j].isEmpty==OCUPADO)
            {
                cantidadMusicos++;
            }
        }
    }
    printf("El promedio es: %.2f",cantidadMusicos/cantidadOrquesta);
    return retorno;
}
