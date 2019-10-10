#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED
#include "orquesta.h"
#include "instrumento.h"
typedef struct
{
    int isEmpty;
    int idOrquesta;
    char name[31];
    char lugar[31];
    int tipo;
}Orquesta;

/** \brief Inicializa toda la lista y cambia el isEmpty a 0(Libre)
 *
 * \param List es un lista de musico que se va a recorrer
 * \param Len es el largo de la lista
 * \return retorno 0 si todo esta ok
 *
 */
int orq_initOrquesta(Orquesta* list, int len);
/** \brief Busco un lugar libre en la lista
 *
 * \param List es la lista orqueta que se va a recorrer
 * \param Len es el largo de la lista
 * \return Retorna (-1) si no hay lugar libre o (0) si hay lugar libre
 *
 */
int orq_buscarLugarLibre(Orquesta* list,int len);
/** \brief Busca un lugar libre y da un alta de orquesta
 *
 * \param List es la lista orqueta
 * \param Len es el largo de la lista
 * \param Id es el id de la orquesta
 * \param name es el nombre de la orquesta
 * \param lugar de la orquesta
 * \param tipo es el tipo de orquesta(Sinfonica,Filarmonica o Camara)
 * \return retorna -1 si hay error o retorna 0 si los datos fueron cargados
 *
 */
int orq_addOrquesta(Orquesta* list, int len, int id, char name[],char lugar[],int tipo);
/** \brief Se da la Alta a una orquesta
*
 * \param List es la lista orqueta
 * \param Len es el largo de la lista
 * \return retorna -1 si hay error o retorna 0 si todo esta ok
 *
 */
int orq_altaOrquesta(Orquesta* list, int len);
/** \brief Busca una orquesta por id
 *
 * \param List es la lista orqueta
 * \param Len es el largo de la lista
 * \return retorna -1 si hay error o retorna la posicion que se encuentra el id
 *
 */
int orq_findOrquestaById(Orquesta* list, int len,int id);
/** \brief Imprimo por pantalla todas las orquestas
 *
 * \param List es la lista orqueta
 * \param Len es el largo de la lista
 * \return retorna -1 si hay error o rertona 0 si todo esta ok
 *
 */
int orq_printOrquestas(Orquesta* list, int len);
/** \brief se da la baja de una orquesta con id
 *
 * \param List es la lista de orquesta
 * \param Len es el largo de la lista
 * \param id es el id que se encuentra la orquesta
 * \return retorna -1 si hay error o retorna 0 si todo esta ok
 *
 */
int orq_bajaOrquesta(Orquesta* list, int len,int id);
/** \brief Imprimo por pantalla una orquesta con id
 *
 * \param List es la lista de orquesta
 * \param Len es el largo de la lista
  * \param id es el id que se encuentra la orquesta
 * \return retorna -1 si hay un error o retorna 0 si todo esta ok
 *
 */
int orq_mostrarOrquestaPorId(Orquesta* list, int len, int id);
/** \brief Se autogenera un id
 *
 * \param void no recibe parametro
 * \param
 * \return no retorna nada
 *
 */
int proximoIdOrquesta(void);
//int orq_bajaOrquestaYMusico(Orquesta* list, int len,int id,Musico * listaMusicos);
int orq_listarOrquestasPorUnLugarEnParticular(Orquesta* listOrquesta,int lenOrquesta,char* auxLugar);
int orq_findOrquestaByPlace(Orquesta* list, int len,char* auxLugar);

#endif // ORQUESTA_H_INCLUDED
