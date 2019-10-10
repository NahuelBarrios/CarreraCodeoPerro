#ifndef SUBMENU_H_INCLUDED
#define SUBMENU_H_INCLUDED
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"
/** \brief Se muestra el menu de orquesta(ABM)
 *
 * \param list es la lista de orquesta
 * \param len es el largo de la lista
 * \param listaMusico es la lista de musico
 * \param lenMusico es el largo de la lista de musico
 * \return
 *
 */

int menuOrquesta(Orquesta* list, int len,Musico *listaMusico,int lenMusico);
int menuMusico(Musico* list, int len,Orquesta* auxListO,int lenOrquesta,Instrumento* auxListI,int lenMusico);
int menuInstrumento(Instrumento* list, int len);
int subMenuimprimirOListar(Musico* listMusico,int lenMusico,Orquesta* listOrquesta,int lenOrquesta,Instrumento* listInstrumento,int lenInstrumento);

#endif // SUBMENU_H_INCLUDED
