#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"
#define LIBRE 0
#define OCUPADO 1
int orq_initOrquesta(Orquesta* list, int len)
{
    int retorno;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty=LIBRE;
            retorno=0;
        }
    }
    return retorno;
}

int orq_buscarLugarLibre(Orquesta* list,int len)
{
    int retorno=-1;//-1 devuelve si no hay lugar libre
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==LIBRE)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int orq_addOrquesta(Orquesta* list, int len, int id, char name[],char lugar[],int tipo)
{
    int retorno=-1;
    int posLibre;

    posLibre=orq_buscarLugarLibre(list,len);
    if(list!=NULL && len>0 && id>0 && name!=NULL && lugar!=NULL && tipo>0)
    {
        if(posLibre!=-1)
        {
            strncpy(list[posLibre].name,name,31);
            strncpy(list[posLibre].lugar,lugar,31);
            list[posLibre].tipo=tipo;
            list[posLibre].isEmpty=OCUPADO;
            list[posLibre].idOrquesta=id;
        }
        retorno=0;
    }
    return retorno;
}

int orq_altaOrquesta(Orquesta* list, int len)
{
    int retorno=-1;
    int auxIdOrquesta;
    char auxName[31];
    char auxLugar[31];
    int auxTipo;
    if((utn_getValidName(auxName)==0) &&
    (utn_getValidString("\nIngrese Lugar: ","\nError","\nError, excediste el maximo de caracteres",auxLugar,31,3)==0) &&
    (utn_getValidInt("\nIngrese tipo\n1-Sinfonica\n2-Filarmonica\n3-Camara\n","\nError",&auxTipo,1,3,3)==0))
    {
        auxIdOrquesta=proximoIdOrquesta();
        orq_addOrquesta(list,len,auxIdOrquesta,auxName,auxLugar,auxTipo);
        printf("\nId: %d\nNombre: %s\nLugar: %s\n",auxIdOrquesta,auxName,auxLugar);
        switch(auxTipo)
        {
      case 1:
        printf("Tipo: Sinfonica");
        break;
      case 2:
        printf("Tipo: Filarmonica");
        break;
      case 3:
        printf("Tipo: Camara");
        break;
        }
           retorno=0;
    }
    return retorno;
}

int orq_findOrquestaById(Orquesta* list, int len,int id)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0 && id>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].idOrquesta==id)
            {
                retorno=i;
            }
        }
    }
    return retorno;
}

int orq_printOrquestas(Orquesta* list, int len)
{
    int retorno=-1;
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            printf("------------------------------------------------------------\n");
            printf("\nOrquesta en la posicion %d\n",i);
            printf("\nNombre: %s\nLugar: %s\nID Orquesta: %d\n",list[i].name, list[i].lugar,list[i].idOrquesta);
            switch(list[i].tipo)
            {
              case 1:
                printf("Tipo 1: Sinfonica\n");
                break;
              case 2:
                printf("Tipo 2: Filarmonica\n");
                break;
              case 3:
                printf("Tipo 3: Camara\n");
                break;
            }
                retorno=0;
            printf("------------------------------------------------------------\n");
            retorno=0;
        }
    }
    return retorno;
}

int orq_bajaOrquesta(Orquesta* list, int len,int id)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0 && id>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].idOrquesta==id)
            {
                list[i].isEmpty=LIBRE;
                retorno=0;
            }
        }
    }
    return retorno;
}

int orq_mostrarOrquestaPorId(Orquesta* list, int len, int id)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0 && id>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].idOrquesta==id)
            {
                printf("\nNombre: %s\nLugar: %s\nID Orquesta: %d\n",list[i].name, list[i].lugar,list[i].idOrquesta);
                switch(list[i].tipo)
                {
                    case 1:
                    printf("Tipo 1: Sinfonica\n");
                    break;
                    case 2:
                    printf("Tipo 2: Filarmonica\n");
                    break;
                    case 3:
                    printf("Tipo 3: Camara\n");
                    break;
                }
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int proximoIdOrquesta(void)
{
    static int idMax=1;
    return idMax++;
}

int orq_listarOrquestasPorUnLugarEnParticular(Orquesta* listOrquesta,int lenOrquesta,char* auxLugar)
{
    int retorno=-1;
    int i;
    if(listOrquesta!=NULL && lenOrquesta>0 && auxLugar!=NULL)
    {
        for(i=0;i<lenOrquesta;i++)
        {
            if(strncmp(listOrquesta[i].lugar,auxLugar,31)==0)
            {
                printf("\nId Orquesta: %d\nNombre: %s\nTipo: %d\nLugar: %s\n",
                       listOrquesta[i].idOrquesta,listOrquesta[i].name,listOrquesta[i].tipo,listOrquesta[i].lugar);
                retorno=0;
            }
        }
    }
    return retorno;
}

int orq_findOrquestaByPlace(Orquesta* list, int len,char* auxLugar)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0 && auxLugar!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if(strncmp(list[i].lugar,auxLugar,31))
            {
                retorno=i;
            }
        }
    }
    return retorno;
}
