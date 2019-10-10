#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "instrumento.h"
#define LIBRE 0
#define OCUPADO 1
int ins_initInstrumento(Instrumento* list, int len)
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

int ins_buscarLugarLibre(Instrumento* list,int len)
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

int ins_addInstrumento(Instrumento* list, int len, int id, char name[],int tipo)
{
    int retorno=-1;
    int posLibre;

    posLibre=ins_buscarLugarLibre(list,len);
    if(list!=NULL && len>0 && id>0 && name!=NULL && tipo>0)
    {
        if(posLibre!=-1)//si encuentra lugar Guardamos al empleado
        {
            strncpy(list[posLibre].name,name,31);
            list[posLibre].tipo=tipo;
            list[posLibre].isEmpty=OCUPADO;
            list[posLibre].idInstrumento=id;
        }

    }
    return retorno;
}

int proximoIdInstrumento(void)
{
    static int idMax=1;
    return idMax++;
}

int ins_altaInstrumento(Instrumento* listInstrumento, int len)
{
    int retorno=-1;
    int auxIdInstrumento;
    char auxName[31];
    int auxTipo;

    if((utn_getValidName(auxName)==0) &&
    (utn_getValidInt("\nIngrese tipo\n1-Cuerdas\n2-Viento-Madera\n3-Viento-Metal\n4-Percusion\n","\nError",&auxTipo,1,4,3)==0))
    {
        auxIdInstrumento=proximoIdInstrumento();
        ins_addInstrumento(listInstrumento,len,auxIdInstrumento,auxName,auxTipo);
        printf("\nId: %d\nNombre: %s\n",auxIdInstrumento,auxName);
        switch(auxTipo)
        {
      case 1:
        printf("Tipo: Cuerdas");
        break;
      case 2:
        printf("Tipo: Viento-Madera");
        break;
      case 3:
        printf("Tipo: Viento-Metal");
        break;
      case 4:
        printf("Tipo: Percusion");
        break;
        }
        retorno=0;
    }
    return retorno;
}

int ins_findInstrumentoById(Instrumento* list, int len,int id)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0 && id>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].idInstrumento==id)
            {
                retorno=i;
            }
        }
    }
    return retorno;
}

int ins_printInstrumentos(Instrumento* list, int len)
{
    int retorno=-1;
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            printf("------------------------------------------------------------\n");
            printf("\nInstrumento en la posicion %d\n",i);
            printf("\nNombre: %s\nID Instrumento: %d\n",list[i].name,list[i].idInstrumento);
            switch(list[i].tipo)
            {
          case 1:
            printf("Tipo: Cuerdas\n");
            break;
          case 2:
            printf("Tipo: Viento-Madera\n");
            break;
          case 3:
            printf("Tipo: Viento-Metal\n");
            break;
          case 4:
            printf("Tipo: Percusion\n");
            break;
            }
            printf("------------------------------------------------------------\n");
            retorno=0;
        }
    }
    return retorno;
}

int ins_bajaInstrumento(Instrumento* list, int len,int id)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0 && id>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].idInstrumento==id)
            {
                list[i].isEmpty=LIBRE;
                retorno=0;
            }
        }
    }
    return retorno;
}

int ins_mostrarInstrumentoPorId(Instrumento* list, int len, int id)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0 && id>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].idInstrumento==id)
            {
                printf("------------------------------------------------------------\n");
                printf("\nNombre: %s\nID Instrumento: %d\n",list[i].name,list[i].idInstrumento);
                switch(list[i].tipo)
                {
                case 1:
                    printf("Tipo: Cuerdas\n");
                    break;
                case 2:
                    printf("Tipo: Viento-Madera\n");
                    break;
                case 3:
                    printf("Tipo: Viento-Metal\n");
                    break;
                case 4:
                    printf("Tipo: Percusion\n");
                    break;
                }
                retorno=0;
            }
        }
    }
    return retorno;
}


