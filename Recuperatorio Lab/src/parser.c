/*
 * parser.c
 *
 *  Created on: 4 ago. 2021
 *      Author: N3630024213
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eLibro.h"
#include "parser.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeLibro LinkedList*
 * \return int
 *
 */
int parser_eLibroFromText(FILE* pFile , LinkedList* pArrayListeLibro)
{
	char buffer[5][128];
	int cant;
	int rtn =0;
	if(pFile == NULL)
	{
	  printf("No se pudo abrir el archivo. Me voy a cerrar.\n");
	  system("pause");
	  exit(EXIT_FAILURE);
	}

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

	while( !feof(pFile) )
	{
		cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
		if( cant < 4){
			break;
		}
		eLibro* nuevoEmpleado = eLibro_newParametros(buffer[0], buffer[1],buffer[2],buffer[3], buffer[4]);
		ll_add(pArrayListeLibro, nuevoEmpleado);
		rtn ++;
	}
	if(rtn==30)
		puts("SE LEYO CORRECTAMENTE");
	return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeLibro LinkedList*
 * \return int
 *
 */
int parser_eLibroFromBinary(FILE* pFile , LinkedList* pArrayListeLibro)
{
	int rtn =0;
	int validacion;
	if(pFile == NULL)
	{
	  printf("No se pudo abrir el archivo.\n");
	  system("pause");
	  exit(EXIT_FAILURE);
	}

	while( !feof(pFile) )
	{
		eLibro* nuevoEmpleado = eLibro_new();
		validacion=fread(nuevoEmpleado,sizeof(eLibro), 1, pFile);
		if(validacion ==1){
			ll_add(pArrayListeLibro, nuevoEmpleado);
			rtn ++;
		}
	}
	if(rtn==1000)
		puts("SE LEYO CORRECTAMENTE");
	return rtn;
}

int parser_obterenUltimoId(FILE* pFile){

	int id;
	char buffer[2000];
	if(pFile != NULL){
		fgets(buffer,2000,pFile);
		id=atoi(buffer);
	}
	return id;
}
