#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED
typedef struct
{
    int isEmpty;
    int idInstrumento;
    char name[31];
    int tipo;
}Instrumento;
/** \brief Inicializa toda la lista y cambia el isEmpty a 0(Libre)
 *
 * \param List es un lista de instrumento que se va a recorrer
 * \param Len es el largo de la lista
 * \return retorno 0 si todo esta ok
 *
 */
int ins_initInstrumento(Instrumento* list, int len);
/** \brief Busco un lugar libre en la lista
 *
 * \param List es la lista instrumento que se va a recorrer
 * \param Len es el largo de la lista
 * \return Retorna (-1) si no hay lugar libre o (0) si hay lugar libre
 *
 */
int ins_buscarLugarLibre(Instrumento* list,int len);
/** \brief Busca un lugar libre y da un alta de orquesta
 *
 * \param List es la lista instrumento
 * \param Len es el largo de la lista
 * \param Id es el id de la instrumetno
 * \param name es el nombre de la instrumento
 * \param tipo es el tipo de Instrumento(Cuerda,viento-madera,viento metal o percusion)
 * \return retorna -1 si hay error o retorna 0 si los datos fueron cargados
 *
 */
int ins_addInstrumento(Instrumento* list, int len, int id, char name[],int tipo);
/** \brief Se da la Alta a un instrumento
*
 * \param List es la lista instrumento
 * \param Len es el largo de la lista
 * \return retorna -1 si hay error o retorna 0 si todo esta ok
 *
 */
int ins_altaInstrumento(Instrumento* listInstrumento, int len);
/** \brief Busca un instrumento por id
 *
 * \param ListInstrumento es la lista instrumento
 * \param Len es el largo de la lista
 * \return retorna -1 si hay error o retorna la posicion que se encuentra el id
 *
 */
int ins_findInstrumentoById(Instrumento* list, int len,int id);
/** \brief Imprimo por pantalla todos los instrumentos
 *
 * \param List es la lista instrumento
 * \param Len es el largo de la lista
 * \return retorna -1 si hay error o rertona 0 si todo esta ok
 *
 */
int ins_printInstrumentos(Instrumento* list, int len);
/** \brief Imprimo por pantalla un instrumento con id
 *
 * \param List es la lista de instrumento
 * \param Len es el largo de la lista
  * \param id es el id que se encuentra el instrumento
 * \return retorna -1 si hay un error o retorna 0 si todo esta ok
 *
 */
int ins_mostrarInstrumentoPorId(Instrumento* list, int len, int id);
/** \brief Se autogenera un id
 *
 * \param void no recibe parametro
 * \param
 * \return no retorna nada
 *
 */
int proximoIdInstrumento(void);



#endif // INSTRUMENTO_H_INCLUDED
