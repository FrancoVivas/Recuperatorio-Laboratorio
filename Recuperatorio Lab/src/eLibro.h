/*
 * eLibro.h
 *
 *  Created on: 4 ago. 2021
 *      Author: N3630024213
 */

#ifndef ELIBRO_H_
#define ELIBRO_H_

typedef struct
{
    int id;
    char nombreLibro[128];
    char autor[128];
    int precio;
    char editorial[128];
}eLibro;

eLibro* eLibro_new();
eLibro* eLibro_newParametros(char* idStr,char* nombreStr,char* autorStr, char* sueldo, char* editorial);
void eLibro_delete();

int eLibro_setId(eLibro* this,int id);
int eLibro_getId(eLibro* this,int* id);

int eLibro_setNombreLibro(eLibro* this,char* nombre);
int eLibro_getNombreLibro(eLibro* this,char* nombre);

int eLibro_setAutor(eLibro* this,char* autorStr);
int eLibro_getAutor(eLibro* this,char* autorStr);

int eLibro_setPrecio(eLibro* this,int precio);
int eLibro_getPrecio(eLibro* this,int* precio);


int eLibro_setEditorialId(eLibro* this, char* editorial);
int eLibro_getEditorialId(eLibro* this, char* editorial);

int eLibro_printOne(eLibro* this);

#endif /* ELIBRO_H_ */
