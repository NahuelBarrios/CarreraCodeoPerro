#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"
/** \brief Se lista las orquestas con mas de 5 musicos
 *
 * \param List es la lista de musico
 * \param Len es el largo de la lista
 * \param ListOrquesta es la lista de orquesta
 * \param LenOrquesta es el largo de la lista de orquesta
 * \return retorna -1 si hay error o retorna 0 si todo esta ok
 *
 */
int mus_listaOrquestasConMasDeCincoMusicos(Musico* list,int len,Orquesta* listOrquesta, int lenOrquesta);
/** \brief Se lista los musicos mayores de 30 años
 *
 * \param List es la lista de musico
 * \param Len es el largo de la lista
 * \return retorna -1 si hay error o retorna 0 si todo esta ok
 *
 */
int mus_listarMusicoMayorDeTreintaDeEdad(Musico* list,int len);
/** \brief Se lista los musicos por una orquesta que se le pide al usuario
 *
 * \param ListMusico es la lista de musico
 * \param LenMusico es el largo de la lista de musico
 * \param auxIdOrquesta es id de la orquesta que se le pide al usuario
 * \param listInstrumento es la la lista de instrumento
 * \param lenInstrumento es el largo de la lista de instrumento
 * \return retorna -1 si hay error o retorna 0 si todo esta ok
 *
 */
int mus_listarMusicoPorUnaOrquestaDeterminada(Musico* listMusico,int lenMusico,int auxIdOrquesta,Instrumento* listInstrumento,int lenIstrumento);
/** \brief Imprime una orquesta con mas musicos
 *
 * \param listMusico es la lista de musico
 * \param lenMusico es el largo de la lista
 * \param listOrquesta es la lista de orquesta
 * \param lenOrquesta es el largo de la lista de orquesta
 * \return retorna -1 si hay error o retorna 0 si todo esta ok
 *
 */
int printOrquestaConMasMusicos(Musico* listMusico,int lenMusico,Orquesta* listOrquesta,int lenOrquesta);
/** \brief Se lista los musicos por el id de orquesta que ingresa el usuario
 *
 * \param listMusicos es la lista de musico
 * \param lenMusico es el largo de la lista
 * \param idOrquesta es el id a comparar
 * \return retorna -1 si hay error o retorna 0 si todo esta ok
 *
 */

int mus_mostrarMusicosPorIdDeOrquesta(Musico* listMusicos,int lenMusico,int idOrquesta);
/** \brief Se lista los musicos que tocan tipo de instrumento CUERDAS
 *
 * \param listMusic es la lista de musico
 * \param lenMusico es el largo de la lista
 * \param listInstrumento es la lista de instrumento
 * \param lenInstrumento es el largo de la lista de instrumento
 * \return retorna -1 si hay error o retorna 0 si todo esta ok
 *
 */
int listarMusicosQueTocanInstCuerda(Musico* listMusico,int lenMusico,Instrumento* listInstrumento,int lenInstrumento);
int orquestaCompleta(Musico* listMusico,int lenMusico,Orquesta* listOrquesta,int lenOrquesta,Instrumento* listInstrumento,int lenInstrumento);
int promedioDeMusicoPorOrquesta(Musico* listMusico,int lenMusico,Orquesta* listOrquesta,int lenOrquesta);


#endif // INFORMES_H_INCLUDED
