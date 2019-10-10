#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "instrumento.h"
#include "funcionesEspeciales.h"
#define LIST_ORQUESTA 50
#define LIST_MUSICO 100
#define LIST_INSTRUMENTO 20
#include "orquesta.h"
#include "musico.h"
#include "subMenu.h"

int main()
{
    Orquesta listaOrquesta[LIST_ORQUESTA];
    orq_initOrquesta(listaOrquesta,LIST_ORQUESTA);
    Musico listaMusico[LIST_MUSICO];
    mus_initMusico(listaMusico,LIST_MUSICO);
    Instrumento listaInstrumento[LIST_INSTRUMENTO];
    ins_initInstrumento(listaInstrumento,LIST_INSTRUMENTO);
    orq_addOrquesta(listaOrquesta,LIST_ORQUESTA,proximoIdOrquesta(),"orquesta1","lugar1",1);
    orq_addOrquesta(listaOrquesta,LIST_ORQUESTA,proximoIdOrquesta(),"orquesta2","lugar1",2);
    orq_addOrquesta(listaOrquesta,LIST_ORQUESTA,proximoIdOrquesta(),"orquesta3","lugar3",3);
    orq_addOrquesta(listaOrquesta,LIST_ORQUESTA,proximoIdOrquesta(),"orquesta4","lugar4",4);
    ins_addInstrumento(listaInstrumento,LIST_INSTRUMENTO,proximoIdInstrumento(),"inst1",1);
    ins_addInstrumento(listaInstrumento,LIST_INSTRUMENTO,proximoIdInstrumento(),"inst2",2);
    ins_addInstrumento(listaInstrumento,LIST_INSTRUMENTO,proximoIdInstrumento(),"inst3",2);
    ins_addInstrumento(listaInstrumento,LIST_INSTRUMENTO,proximoIdInstrumento(),"inst4",3);
    ins_addInstrumento(listaInstrumento,LIST_INSTRUMENTO,proximoIdInstrumento(),"inst4",4);
    /*ins_addInstrumento(listaInstrumento,LIST_INSTRUMENTO,proximoIdInstrumento(),"inst4",2);
    ins_addInstrumento(listaInstrumento,LIST_INSTRUMENTO,proximoIdInstrumento(),"inst4",2);
    ins_addInstrumento(listaInstrumento,LIST_INSTRUMENTO,proximoIdInstrumento(),"inst4",3);
    ins_addInstrumento(listaInstrumento,LIST_INSTRUMENTO,proximoIdInstrumento(),"inst8",4);
    ins_addInstrumento(listaInstrumento,LIST_INSTRUMENTO,proximoIdInstrumento(),"inst8",4);
    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus1","Amus1",30,2,1);
    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus2","Amus2",20,2,2);
    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus3","Amus3",25,2,3);
    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus4","Amus4",27,2,4);
    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus5","Amus5",22,2,5);
    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus5","Amus5",22,2,6);
    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus5","Amus5",22,2,7);
    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus6","Amus6",35,2,8);
    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus6","Amus6",35,2,9);
    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus6","Amus6",35,2,10);
    //----*/

    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus1","Amus1",30,1,2);
    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus2","Amus2",20,2,5);
    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus3","Amus3",25,4,2);
    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus4","Amus4",27,4,1);
    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus5","Amus5",22,1,3);
    mus_addMusico(listaMusico,LIST_MUSICO,proximoIdMusico(),"Mus6","Amus6",35,3,4);

    int opciones;
    do
    {
        printf("\n------------------------\n");
        utn_getValidInt("\n1-Orquesta\n2-Instrumento\n3-Musico\n4-Informes\n5-Salir\nIngrese opcion: ","Error",&opciones,1,5,3);
        switch(opciones)
        {
        case 1:
        menuOrquesta(listaOrquesta,LIST_ORQUESTA,listaMusico,LIST_MUSICO);
            break;
        case 2:
        menuInstrumento(listaInstrumento,LIST_INSTRUMENTO);
            break;
        case 3:
        menuMusico(listaMusico,LIST_MUSICO,listaOrquesta,LIST_ORQUESTA,listaInstrumento,LIST_INSTRUMENTO);
            break;
        case 4:
            subMenuimprimirOListar(listaMusico,LIST_MUSICO,listaOrquesta,LIST_ORQUESTA,listaInstrumento,LIST_INSTRUMENTO);
            break;
        }
    }while(opciones!=5);

    return 0;
}
