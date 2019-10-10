#ifndef FUNCIONESESPECIALES_H_INCLUDED
#define FUNCIONESESPECIALES_H_INCLUDED
#include "orquesta.h"
#include "musico.h"
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

/*void hardcodeoMusico(Musico * listaMusicos,int len,char * nombre,char * apellido,int edad,int isEmpty)
{
    int lugarLibre;
    lugarLibre=mus_buscarLugarLibre(listaMusicos,len);

    strncpy(listaMusicos[lugar libre].name,nombre,31);
    strncpy(listaMusicos[lugar libre].lastName,apellido,31);
    listaMusicos[lugar libre].edad=edad;
    listaMusicos[lugar libre].idInstrumento=proximoidinstrumento;
    listaMusicos[lugar libre].idOrquesta=proximoID orquesta;
    listaMusicos[lugar libre].isEmpty=1;
    listaMusicos[lugar libre].idMusico=proximo id Musico;
}*/

#endif // FUNCIONESESPECIALES_H_INCLUDED
