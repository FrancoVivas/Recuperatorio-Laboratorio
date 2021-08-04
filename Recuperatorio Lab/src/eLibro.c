/*
 * eLibro.c
 *
 *  Created on: 4 ago. 2021
 *      Author: N3630024213
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eLibro.h"
#include "LinkedList.h"

eLibro* eLibro_new(){

	return (eLibro*)malloc(sizeof(eLibro));
}
//int id;
//char nombreLibro[128];
//char autor[128];
//int precio;
//eEditoriales editorialId;

eLibro* eLibro_newParametros(char* idStr,char* nombreStr,char* autorStr, char* sueldo, char* editorial){

	eLibro* peLibro = eLibro_new();
	if(idStr != NULL && nombreStr != NULL && autorStr != NULL && sueldo != NULL){
		if(eLibro_setId(peLibro, atoi(idStr)) &&
			eLibro_setNombreLibro(peLibro, &(*nombreStr))&&
			eLibro_setAutor(peLibro, &(*autorStr))&&
			eLibro_setPrecio(peLibro, atoi(sueldo))&&
			eLibro_setEditorialId(peLibro, &(*editorial))){

		}else{
			peLibro =NULL;
		}
	}
	return peLibro;
}

int eLibro_setId(eLibro* this,int id){

	int rtn=0;
	if(this != NULL){
		(*this).id = id;
		rtn=1;
	}
	return rtn;
}
int eLibro_getId(eLibro* this,int* id){

	int rtn=0;
	if(this != NULL){

		*id = (*this).id;
		rtn=1;
	}
	return rtn;
}

int eLibro_setNombreLibro(eLibro* this,char* nombre){

	int rtn=0;
	if(this != NULL){
		strcpy((*this).nombreLibro , nombre);
		rtn=1;
	}
	return rtn;
}

int eLibro_getNombreLibro(eLibro* this,char* nombre){

	int rtn=0;
	if(this != NULL){
		strcpy(nombre,(*this).nombreLibro);
		rtn=1;
	}
	return rtn;
}

int eLibro_setAutor(eLibro* this,char* autorStr){
	int rtn=0;
	if(this != NULL){

		strcpy((*this).autor , autorStr);
		rtn=1;
	}
	return rtn;

}
int eLibro_getAutor(eLibro* this,char* autorStr){
	int rtn=0;
	if(this != NULL){

		strcpy(autorStr,(*this).autor);
		rtn=1;
	}
	return rtn;

}

int eLibro_setPrecio(eLibro* this,int precio){
	int rtn=0;
	if(this != NULL){

		(*this).precio = precio;
		rtn=1;
	}
	return rtn;

}

int eLibro_getPrecio(eLibro* this,int* precio){
	int rtn=0;
	if(this != NULL){

		*precio =(*this).precio;
		rtn=1;
	}
	return rtn;

}

int eLibro_setEditorialId(eLibro* this, char* editorial)
{
	int rtn =0;
	if(this != NULL)
	{
		strcpy((*this).editorial , editorial);
		rtn =1;
	}
	return rtn;
}

int eLibro_getEditorialId(eLibro* this, char* editorial)
{
	int rtn =0;
	if(this != NULL)
	{
		strcpy(editorial, (*this).editorial);
		rtn =1;
	}
	return rtn;
}

int eLibro_printOne(eLibro* this){

	int rtn =-1;

	if(this != NULL){
		printf("ID -  TITULO       -  AUTOR      - PRECIO\n");
		printf("%d, %5s, %10s, %10d\n", (*this).id, (*this).nombreLibro,(*this).autor,(*this).precio);
		rtn =1;
	}
	return rtn;
}
