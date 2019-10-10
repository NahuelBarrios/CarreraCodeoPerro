#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"
typedef struct
{
    int isEmpty;
    int idMusico;
    char name[31];
    char lastName[31];
    int edad;
    int idOrquesta;
    int idInstrumento;
}Musico;
/** \brief Inicializa toda la lista y cambia el isEmpty a 0(Libre)
 *
 * \param List es un lista de musico que se va a recorrer
 * \param Len es el largo de la lista
 * \return retorno 0 si todo esta ok
 *
 */
int mus_initMusico(Musico* list, int len);
/** \brief Busco un lugar libre en la lista
 *
 * \param List es la lista de musico que se va a recorrer
 * \param Len es el largo de la lista
 * \return Retorna (-1) si no hay lugar libre o (0) si hay lugar libre
 *
 */
int mus_buscarLugarLibre(Musico* list,int len);
/** \brief Busca un lugar libre y da un alta de musico
 *
 * \param List es la lista musico
 * \param Len es el largo de la lista
 * \param Id es el id del musico
 * \param name es el nombre del musico
 * \param lastName es el apellido del musico
 * \param edad es la edad del musico
 * \param idOrquesta es el id en donde toca
 * \param idInstrumento es el id del instrumento que toca
 * \return retorna -1 si hay error o retorna 0 si los datos fueron cargados
 *
 */
int mus_addMusico(Musico* list, int len, int id, char name[],char lastName[],int edad,int idOrquesta,int idInstrumento);
/** \brief Se da la Alta a una orquesta
*
 * \param ListMusico es la lista de musico
 * \param Len es el largo de la lista
 * \param ListOrquesta es la lista de Orquesta
 * \param LenOrquesta es el largo de la lista de Orquesta
 * \param ListInstrumento es la lista de Instrumento
 * \param LenInstrumento es el largo de la lista de Instrumento
 * \return retorna -1 si hay error o retorna 0 si todo esta ok
 *
 */
int mus_altaMusico(Musico* listMusico, int len,Orquesta* listOrquesta,int lenOrquesta,Instrumento* listInstrumento,int lenInstrumento);
/** \brief Busca un musico por id
 *
 * \param List es la lista de musico
 * \param Len es el largo de la lista
 * \return retorna -1 si hay error o retorna la posicion que se encuentra el id
 *
 */
int mus_findMusicoById(Musico* list, int len,int id);
/** \brief Busca una orquesta por id
 *
 * \param List es la lista de Orquesta
 * \param Len es el largo de la lista
 * \return retorna -1 si hay error o retorna la posicion que se encuentra el id
 *
 */
int mus_findOrquestaById(Orquesta* list, int len,int id);
/** \brief Busca un instrumento por id
 *
 * \param List es la lista de instrumento
 * \param Len es el largo de la lista
 * \return retorna -1 si hay error o retorna la posicion que se encuentra el id
 *
 */
int mus_findInstrumentoById(Instrumento* list, int len,int id);
/** \brief Imprimo por pantalla todos los musicos con instrumentos
 *
 * \param List es la lista de musico
 * \param Len es el largo de la lista
 * \param ListInstrumento es la lista de Instrumento
 * \param LenInstrumento es el largo de la lista de Instrumento
 * \return retorna -1 si hay error o rertona 0 si todo esta ok
 *
 */
int mus_printMusicosEInstrumento(Musico* list, int len,Instrumento* listInstrumento,int lenInstrumento);
/** \brief se da la baja de un musico con id
 *
 * \param List es la lista de musico
 * \param Len es el largo de la lista
 * \param id es el id que se encuentra el musico
 * \return retorna -1 si hay error o retorna 0 si todo esta ok
 *
 */
int mus_bajaMusico(Musico* list, int len,int id);
/** \brief Se da la baja de orquesta y si tiene musico tambien
 *
 * \param list es la lista de orquesta
 * \param len es el largo de la lista
 * \param listaMusico es la lista de musico
 * \param lenMusico es el largo de la lista de musico
 * \return retorna -1 si hay error o retorna 0 si todo esta ok
 *
 */
int orq_bajaOrquestaYMusico(Orquesta* list, int len,int id,Musico * listaMusicos,int lenMusicos);
/** \brief Imprimo por pantalla todos los musicos con instrumentos
 *
 * \param List es la lista de musico
 * \param Len es el largo de la lista
 * \return retorna -1 si hay error o rertona 0 si todo esta ok
 *
 */
 int mus_printMusicos(Musico* list, int len);
/** \brief Imprimo por pantalla un musico con id
 *
 * \param List es la lista de musico
 * \param Len es el largo de la lista
  * \param id es el id que se encuentra la musico
 * \return retorna -1 si hay un error o retorna 0 si todo esta ok
 *
 */
int mus_mostrarMusicoPorId(Musico* list, int len, int id);
int mus_modificarPorMusico(Musico* list, int len, int id,Orquesta* listOrquesta);
/** \brief Se autogenera un id
 *
 * \param void no recibe parametro
 * \param
 * \return no retorna nada
 *
 */
int proximoIdMusico(void);

#endif // MUSICO_H_INCLUDED
