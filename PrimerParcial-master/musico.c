#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define LIBRE 0
#define OCUPADO 1
#include "orquesta.h"
#include "musico.h"
int mus_initMusico(Musico* list, int len)
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

int mus_buscarLugarLibre(Musico* list,int len)
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

int mus_addMusico(Musico* list, int len, int id, char name[],char lastName[],int edad,int idOrquesta,int idInstrumento)
{
    int retorno=-1;
    int posLibre;

    posLibre=mus_buscarLugarLibre(list,len);
    if(list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL && edad>0 && idOrquesta>=0 && idInstrumento>=0)
    {
        if(posLibre!=-1)//si encuentra lugar Guardamos al musico
        {
            strncpy(list[posLibre].name,name,31);
            strncpy(list[posLibre].lastName,lastName,31);
            list[posLibre].edad=edad;
            list[posLibre].idOrquesta=idOrquesta;
            list[posLibre].idInstrumento=idInstrumento;
            list[posLibre].isEmpty=OCUPADO;
            list[posLibre].idMusico=id;
        }
        retorno=0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addMusica'\n");
    }
    return retorno;
}

int proximoIdMusico(void)
{
    static int idMax=1;
    return idMax++;
}

int mus_altaMusico(Musico* listMusico, int len,Orquesta* listOrquesta,int lenOrquesta,Instrumento* listInstrumento,int lenInstrumento)
{
    int retorno=-1;
    int auxIdMusico;
    char auxName[31];
    char auxApellido[31];
    int auxEdad;
    int auxIdOrquesta;
    int auxIdInstrumento;
    if((utn_getValidString("\nIngrese nombre: ","\nError","\nError,excediste el maximo de caracteres",auxName,31,3)==0) &&
        (utn_getValidString("\nIngrese apellido: ","\nError","\nError,excediste el maximo de caracteres",auxApellido,31,3)==0) &&
        (utn_getValidInt("\nIngrese edad: ","ERROR",&auxEdad,1,999999,3)==0) &&
        (utn_getValidInt("\nIngrese id de Orquesta: \n ","ERROR",&auxIdOrquesta,0,999999,3)==0) &&
        (utn_getValidInt("\nIngrese id de Instrumento: \n ","ERROR",&auxIdInstrumento,0,999999,3)==0))
        {
            auxIdMusico=proximoIdMusico();
            mus_addMusico(listMusico,len,auxIdMusico,auxName,auxApellido,auxEdad,auxIdOrquesta,auxIdInstrumento);
            printf("\nNombre: %s\nApellido: %s\nId: %d\nId Orquesta: %d\nId Instrumento: %d\n"
                    ,auxName,auxApellido,auxIdMusico,auxIdOrquesta,auxIdInstrumento);
            orq_mostrarOrquestaPorId(listOrquesta,len,auxIdOrquesta);
            ins_mostrarInstrumentoPorId(listInstrumento,len,auxIdInstrumento);
            retorno=0;
        }
    else
    {
        printf("\nNo se encontro Orquesta con ese ID \n");
    }
    return retorno;

}

int mus_findMusicoById(Musico* list, int len,int id)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0 && id>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].idMusico==id)
            {
                retorno=i;
            }
        }
    }
    return retorno;
}

int mus_findOrquestaById(Orquesta* list, int len,int id)
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

int mus_findInstrumentoById(Instrumento* list, int len,int id)
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

int mus_printMusicosEInstrumento(Musico* list, int len,Instrumento* listInstrumento,int lenInstrumento)
{
    int retorno=-1;

    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            retorno=0;
            printf("------------------------------------------------------------\n");
            printf("\nMusico en la posicion %d\n",i);
            printf("\nNombre: %s\nApellido: %s\nID Musico: %d\nId Orquesta: %d\n"
                   ,list[i].name, list[i].lastName,list[i].idMusico,list[i].idOrquesta);
            ins_mostrarInstrumentoPorId(listInstrumento,len,list[i].idInstrumento);
            printf("------------------------------------------------------------\n");
        }
    }
    return retorno;
}

int mus_printMusicos(Musico* list, int len)
{
    int retorno=-1;

    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            retorno=0;
            printf("------------------------------------------------------------\n");
            printf("\nMusico en la posicion %d\n",i);
            printf("\nNombre: %s\nApellido: %s\nID Musico: %d\n"
                   ,list[i].name, list[i].lastName,list[i].idMusico);
            printf("------------------------------------------------------------\n");
        }
    }
    return retorno;
}

int mus_bajaMusico(Musico* list, int len,int id)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0 && id>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].idMusico==id)
            {
                list[i].isEmpty=LIBRE;
                retorno=0;
            }
        }
    }
    return retorno;
}

int orq_bajaOrquestaYMusico(Orquesta* list, int len,int id,Musico * listaMusicos,int lenMusicos)
{
    int retorno=-1;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].idOrquesta==id)
        {
            for(int j=0;j<lenMusicos;j++)
            {
                if(listaMusicos[j].idOrquesta==id)
                {
                    orq_bajaOrquesta(list,len,id);
                    mus_bajaMusico(listaMusicos,lenMusicos,listaMusicos[j].idMusico);
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}

int mus_mostrarMusicoPorId(Musico* list, int len, int id)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0 && id>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].idMusico==id)
            {
                printf("\nNombre: %s\nApellido: %s\nID Musico: %d\n",list[i].name, list[i].lastName,list[i].idMusico);
                retorno=0;
            }
        }
    }
    return retorno;
}

int mus_modificarPorMusico(Musico* list, int len, int id,Orquesta* listOrquesta)
{
    int retorno=-1;
    int auxEdad;
    int auxIdOrquesta;
    int opciones;
    int indiceAModificar;
    do
    {
        if(list!=NULL && len>0 && id>0)
        {
            indiceAModificar=mus_findMusicoById(list,len,id);
            if(indiceAModificar!=-1)
            {
                if(mus_mostrarMusicoPorId(list,len,id)!=0)
                {
                    printf("No existe el Id");
                }
                if(utn_getValidInt("\n\nQue desea modificar?\n1-Modificar Edad\n2-Id Orquesta\n3-Cancelar\n\nEliga la opcion: ",
                                   "Error",&opciones,1,2,3)==0)
                {
                    switch(opciones)
                    {
                    case 1:
                        utn_getValidInt("\nIngrese nueva edad: ","Error",&auxEdad,1,90,3);
                        list[indiceAModificar].edad=auxEdad;
                        printf("\nNombre: %s\nApellido: %s\n ID: %d\nID Orquesta %d\n"
                               ,list[indiceAModificar].name,list[indiceAModificar].lastName,list[indiceAModificar].idMusico,list[indiceAModificar].idOrquesta);
                        break;
                    case 2:
                        utn_getValidInt("\nIngrese nuevo Id Orquesta: ","Error",&auxIdOrquesta,1,999999,3);
                        list[indiceAModificar].idOrquesta=auxIdOrquesta;
                        fflush(stdin);
                        printf("\nNombre: %s\nApellido: %s\n ID: %d\nID Orquesta %d\nNombre Orquesta: %s\nLugar: %s\nTipo: %d\n"
                               ,list[indiceAModificar].name,list[indiceAModificar].lastName,list[indiceAModificar].idMusico,list[indiceAModificar].idOrquesta,
                               listOrquesta[indiceAModificar].name,listOrquesta[indiceAModificar].lugar,listOrquesta[indiceAModificar].tipo);

                        retorno=0;
                    }
                }
            }
            else
            {
                printf("no se encontro usuario con ese ID");
            }


        }
        else
        {
            printf("los parametros estan mal en la funcion");
        }

        break;
    }
    while(opciones!=3);
    return retorno;
}

