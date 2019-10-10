#include "orquesta.h"
#include "musico.h"

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

