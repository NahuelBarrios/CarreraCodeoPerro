#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "subMenu.h"
#include "musico.h"
#include "informes.h"
#include "funcionesEspeciales.h"


int menuOrquesta(Orquesta* listOrquesta, int lenOrquesta,Musico * listaMusicos,int lenMusico)
{
    int opciones;
    int id;
    do
    {
        printf("\n-----------ALTA DE ORQUESTA-----------\n");
        utn_getValidInt("\n1-Alta \n2-Baja \n3-Listar\n4-Salir\nIngrese opcion: ","Error",&opciones,1,4,3);
        switch(opciones)
        {
        case 1:
            orq_altaOrquesta(listOrquesta,lenOrquesta);
            break;
        case 2:
            orq_printOrquestas(listOrquesta,lenOrquesta);
            if(utn_getValidInt("\nIngrese Id: ","\nError",&id,1,999999,3)==0)
            {
                orq_bajaOrquestaYMusico(listOrquesta,lenOrquesta,id,listaMusicos,lenMusico);
            }
            break;
        case 3:
            orq_printOrquestas(listOrquesta,lenOrquesta);
            break;
        }
    }
    while(opciones!=4);
    return 0;
}

int menuMusico(Musico* list, int len,Orquesta* listOrquesta,int lenOrquesta,Instrumento* listInstrumento,int lenInstrumento)
{
    int opciones;
    int id;
    do
    {
        printf("\n-----------ALTA DE MUSICO-----------");
        utn_getValidInt("\n\n1-Alta\n2-Modifica\n3-Baja\n4-Listar\n5-Salir\nIngrese opcion: "
                        ,"Error",&opciones,1,5,3);
        switch(opciones)
        {
        case 1:
            mus_altaMusico(list,len,listOrquesta,lenOrquesta,listInstrumento,lenInstrumento);
            break;
        case 2:
            mus_printMusicos(list,len);
            if(utn_getValidInt("Ingrese ID Musico: ","Error",&id,1,999999,3)==0)
            {
                mus_modificarPorMusico(list,len,id,listOrquesta);
                mus_mostrarMusicoPorId(list,len,id);
            }
            break;
        case 3:
            mus_printMusicos(list,len);
            if(utn_getValidInt("\nIngrese Id: ","\nError",&id,1,999999,3)==0)
            {
                mus_bajaMusico(list,len,id);
                printf("\nLa baja fue exitosa\n");
            }
            break;
        case 4:
            mus_printMusicosEInstrumento(list,len,listInstrumento,lenInstrumento);
            break;
        }
    }
    while(opciones!=5);
    return 0;
}

int menuInstrumento(Instrumento* list, int len)
{
    int opciones;
    do
    {
        printf("\n-----------ALTA DE INSTRUMENTO-----------\n");
        utn_getValidInt("\n1-Alta \n2-Listar \n3-Salir\nIngrese opcion: ","Error",&opciones,1,3,3);
        switch(opciones)
        {
        case 1:
            ins_altaInstrumento(list,len);
            break;
        case 2:
            ins_printInstrumentos(list,len);
            break;

        }
    }
    while(opciones!=3);
    return 0;
}

int subMenuimprimirOListar(Musico* listMusico,int lenMusico,Orquesta* listOrquesta,int lenOrquesta,Instrumento* listInstrumento,int lenInstrumento)
{
    int opciones;
    int auxIdOrquesta;
    char auxLugar[31];
    do
    {
        printf("\n-----------Imprimir o Listar-----------\n");
        utn_getValidInt("\n1-Listar orquestas con mas de cinco musicos\n2-Lista musicos de mas de 30 años\n3-Listar Orquesta Por Lugar\n4-Orquesta completa\n5-Listar musicos por Id de Orquesta\n6-Imprimir Orquesta con mas musico\n7-Promedio de musicos por orquesta\n8-Salir\nIngrese opcion:\n",
                        "Error",&opciones,1,8,3);
        switch(opciones)
        {
        case 1:
            mus_listaOrquestasConMasDeCincoMusicos(listMusico,lenMusico,listOrquesta,lenOrquesta);
            break;
        case 2:
            mus_listarMusicoMayorDeTreintaDeEdad(listMusico,lenMusico);
            break;
        case 3:
            if(utn_getValidStringAlfaNumerico("\nIngrese lugar: ","Error","Error, excediste el maximo de caracteres",auxLugar,999999,3)==0)
            {
                if(orq_listarOrquestasPorUnLugarEnParticular(listOrquesta,lenOrquesta,auxLugar)==-1)
                {
                    printf("\nEl lugar no existe");
                }
            }
            break;
        case 4:
            if(orquestaCompleta(listMusico,lenMusico,listOrquesta,lenOrquesta,listInstrumento,lenInstrumento)!=0)
            {
                printf("No hay");
            }
            break;
        case 5:
            if(utn_getValidInt("Ingrese Id: ","Error",&auxIdOrquesta,1,999999,3)==0)
            {
                if(mus_findOrquestaById(listOrquesta,lenOrquesta,auxIdOrquesta)!=-1)
                {
                    mus_listarMusicoPorUnaOrquestaDeterminada(listMusico,lenMusico,auxIdOrquesta,listInstrumento,lenInstrumento);
                }
                else{
                    printf("No hay");
                }
            }
            break;
        case 6:
            printOrquestaConMasMusicos(listMusico,lenMusico,listOrquesta,lenOrquesta);
            break;
        case 7:
            promedioDeMusicoPorOrquesta(listMusico,lenMusico,listOrquesta,lenOrquesta);
            break;
        }
    }
    while(opciones!=8);
    return 0;
}
