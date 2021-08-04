/*
 * Controller.c
 *
 *  Created on: 4 ago. 2021
 *      Author: N3630024213
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eLibro.h"
#include "parser.h"
#include "Biblioteca.h"
#include "Controller.h"


/** \brief Carga los datos de los Libros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeLibro LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListeLibro)
{
	int rtn=1;
	FILE* pFile;

	pFile = fopen(path,"r");
	if(pFile!= NULL){
		parser_eLibroFromText(pFile , pArrayListeLibro);
		rtn=0;
	}else{
		puts("NO SE PUDO ABRIR EL ARCHIVO:");
	}
	fclose(pFile);
    return rtn;
}

/*
int controller_loadFromBinary(char* path , LinkedList* pArrayListeLibro)
{
	int rtn=1;
	FILE* pFile;
	pFile = fopen(path,"rb");
	if(pFile!= NULL){
		parser_eLibroFromBinary(pFile, pArrayListeLibro);
		rtn=0;
	}
	fclose(pFile);
    return rtn;
}
int controller_addeLibro(LinkedList* pArrayListeLibro, int id){
	eLibro* nuevoLibro = eLibro_new();
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int rtn =-1;
	Get_String("INGRESE EL NOMBRE DEL NUEVO Libro: ", "ERROR. REINGRESE EL NOMBRE", nombre, 128);
	horasTrabajadas =Get_IntRange("INGRESE LAS HORAS TRABAJADAS: ", "ERROR. REINGRESE LAS HORAS TRABAJADAS: ", 0, 720);
	sueldo=Get_IntRange("INGRESE EL SUELDO DEL Libro: ", "ERROR. REINGRESE EL SUELDO DEL Libro: ", 10000, 100000);
	if(Validate_Exit_SN("ESTA SEGURO QUE DESEA INGRESAR ESTS DATOS ? [S]-SI [N]-NO", "ERROR. REINGRESE: ")){
		eLibro_setId(nuevoLibro, id);
		eLibro_setNombre(nuevoLibro, nombre);
		eLibro_setHorasTrabajadas(nuevoLibro, horasTrabajadas);
		eLibro_setSueldo(nuevoLibro, sueldo);
		ll_add(pArrayListeLibro, nuevoLibro);
		rtn=1;
	}
	controller_EscribirUltimoId();
    return rtn;
}
int controller_editeLibro(LinkedList* pArrayListeLibro)
{
	eLibro* emp;
	int id;
	int rtn= -1;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	id = Get_IntPositive("INGRESE EL ID DEL Libro A MODIFICAR: ", "ERROR. REINGRESE: ");
	//id--;
	emp =ll_get(pArrayListeLibro, (id-1));
	if(eLibro_printOne(emp)!=1){
		puts("\tNO SE PUDO ENCONTRAR EL Libro CON ESE ID\n");
	}else{
		Get_String("INGRESE EL NOMBRE DEL NUEVO Libro: ", "ERROR. REINGRESE EL NOMBRE", nombre, 128);
		horasTrabajadas =Get_IntRange("INGRESE LAS HORAS TRABAJADAS: ", "ERROR. REINGRESE LAS HORAS TRABAJADAS: ", 0, 720);
		sueldo=Get_IntRange("INGRESE EL SUELDO DEL Libro: ", "ERROR. REINGRESE EL SUELDO DEL Libro: ", 10000, 100000);
		if(Validate_Exit_SN("ESTA SEGURO QUE DESEA INGRESAR ESTS DATOS ? [S]-SI [N]-NO", "ERROR. REINGRESE: ")){
			eLibro_setId(emp, id);
			eLibro_setNombre(emp, nombre);
			eLibro_setHorasTrabajadas(emp, horasTrabajadas);
			eLibro_setSueldo(emp, sueldo);
			rtn =1;
			puts("DATOS CARGADOS EXITOSAMENTE");
			eLibro_printOne(emp);
		}
	}
	return rtn;
}
int controller_removeeLibro(LinkedList* pArrayListeLibro)
{
	int index;
	if(pArrayListeLibro!= NULL){
		index = Get_IntRange("INGRESE EL INDICE DEL Libro QUE QUIERE BORRAR: ", "ERROR. REINGRESE: ", 1, ll_len(pArrayListeLibro));
		index--;
		ll_remove(pArrayListeLibro, index);
	}
    return 1;
}
 */
int controller_ListLibro(LinkedList* pArrayListeLibro)
{
	int i;
	int id;
	int rtn=0;
	char nombre[128];
	char autor[128];
	int precio;
	char editorial[128];
	int len = ll_len(pArrayListeLibro);
	eLibro* auxLibro =NULL;

	printf("\n");
	printf("ID,                                                       NOMBRE,                 AUTOR, PRECIO,  EDITORIAL\n");
	if(pArrayListeLibro != NULL){
		for(i=0; i< len; i++)
		{
			auxLibro =ll_get(pArrayListeLibro, i);
			if(auxLibro != NULL){
				eLibro_getId(auxLibro, &id);
				eLibro_getNombreLibro(auxLibro, nombre);
				eLibro_getPrecio(auxLibro , &precio);
				eLibro_getAutor(auxLibro, autor);
				eLibro_getEditorialId(auxLibro, editorial);

				printf("%4d, %60s, %20s, %6d, %s\n",  id , nombre, autor, precio, editorial);
				rtn=1;
			}
		}
	}
    return rtn;
}

int controller_ordenar(LinkedList* this)
{
	int rtn =0;
	int (*pFunc)(void*, void*);
	pFunc = &controller_ordenarPorAutor;
	if(this != NULL && pFunc != NULL)
	{
		ll_sort(this, pFunc, 0);
		rtn =1;
	}
	return rtn;
}


int controller_ordenarPorAutor(void* libroUno, void* libroDos)
{
	int rtn=0;
	char auxAutorUno[128];
	char auxAutorDos[128];
	if(libroUno != NULL && libroDos != NULL)
	{
		eLibro_getAutor((eLibro*)libroUno, auxAutorUno);
		eLibro_getAutor((eLibro*)libroDos, auxAutorDos);
		if(strcmp(auxAutorDos, auxAutorUno)>0)
		{
			rtn=1;
		}
		else{
			rtn=-1;
		}
	}
	return rtn;
}

int controller_descuento(LinkedList* this)
{
	int rtn =0;
	void (*pFunc)(void*);
	pFunc = &controller_calcularDescuento;
	if(this != NULL && pFunc != NULL)
	{
		ll_map(this, pFunc);
		rtn=1;
	}
	return rtn;
}

void controller_calcularDescuento(void* pElement)
{
	int precio;
	char editorial[128];

	if(eLibro_getPrecio((eLibro*)pElement, &precio)&& eLibro_getEditorialId((eLibro*) pElement, editorial))
	{

		if(strcmp(editorial, "Planeta")==0)
		{
			if(precio > 299)
			{
				precio *= 0.80;
				eLibro_setPrecio((eLibro*)pElement , precio);
			}
		}
		if(strcmp(editorial, "SIGLO XXI EDITORES")==0)
		{
			if(precio < 201)
			{
				precio *= 0.90;
				eLibro_setPrecio((eLibro*)pElement , precio);
			}
		}
	}

}


int controller_Filter(LinkedList* this)
{
	int rtn=0;
	int (*pFunc)(void*);

	pFunc = &controller_filtraAutor;
	if(this != NULL && pFunc!= NULL)
	{
		if(ll_filter(this, pFunc)!= 0)
		{
			rtn=1;
		}
	}
	return rtn;
}


int controller_filtraAutor(void* pElement)
{
	int rtn=0;
	char auxAutror[128];
	if(pElement != NULL)
	{
		eLibro_getAutor((eLibro*)pElement, auxAutror);
		if(strcmp(auxAutror, "Rowling")==0)
		{
			rtn =1;
		}
	}
	return rtn;
}

void controller_count(LinkedList* this)
{
	int rtn;
	int (*pFunc)(void*);

	pFunc = &controller_contarPorAutor;
	if(this != NULL && pFunc!= NULL)
	{
		rtn = ll_count(this, pFunc);

		printf("LA CANTIDAD DE LIBROS DE ROWLING ES %d", rtn);
	}
}

int controller_contarPorAutor(void* pElement)
{
	int rtn=0;
	char auxAutror[128];
	if(pElement != NULL)
	{
		eLibro_getAutor((eLibro*)pElement, auxAutror);
		if(strcmp(auxAutror, "Rowling")==0)
		{
			rtn =1;
		}
	}
	return rtn;
}



/*
int controller_sorteLibro(LinkedList* pArrayListeLibro)
{
	int rtn = 1;
	int criterio;
	int opc;
	int idI;
	int idJ;
	char nombreI[128];
	char nombreJ[128];
	int horasTrabajadasI;
	int horasTrabajadasJ;
	int sueldoI;
	int sueldoJ;
	eLibro* eLibro_I = NULL;
	eLibro* eLibro_J = NULL;
	eLibro aux;
	printf("QUE CRITERIO DE ORDENAMIENTO DESEA ELEGIR? [1]-MENOR A MAYOR  [2]-MAYOR A MENOR");
    scanf("%d", &criterio);
    while(criterio != 1 && criterio!= 2){
    	printf("ERROR. REINGRESE QUE CRITERIO DE ORDENAMIENTO DESEA ELEGIR? [1]-MENOR A MAYOR  [2]-MAYOR A MENOR");
		scanf("%d", &criterio);
    }
    printf("QUE DESEO ORDENAR CON ESE CRITERIO?\n"
    		"[1]-ID\n"
    		"[2]-NOMBRE\n"
    		"[3]-HORAS TRABAJADAS\n"
    		"[4]-SUELDO\n");
    scanf("%d", &opc);
    while(opc != 1 && opc!= 2 && opc!=3 &&opc!=4){
        printf("QUE DESEO ORDENAR CON ESE CRITERIO?\n"
        		"[1]-ID\n"
        		"[2]-NOMBRE\n"
        		"[3]-HORAS TRABAJADAS\n"
        		"[4]-SUELDO\n");
        scanf("%d", &opc);
    }
	if (pArrayListeLibro != NULL) {
		switch (criterio) {
		case 1:
			puts("ESTA OPERACION PUEDE TARDAR UNOS SEGUNDOS. ESPERE, POR FAVOR");
			for (int i = 0; i < (ll_len(pArrayListeLibro)  - 1); i++) {
				eLibro_I = ll_get(pArrayListeLibro, i);
				for (int j = i + 1; j < (ll_len(pArrayListeLibro)) ; j++) {
					eLibro_J = ll_get(pArrayListeLibro, j);
					switch(opc){
					case 1:
						eLibro_getId(eLibro_I, &idI);
						eLibro_getId(eLibro_J, &idJ);
						if ( idI > idJ) {
							aux = *(eLibro_I);
							*(eLibro_I) = *(eLibro_J);
							*(eLibro_J) = aux;
							rtn = 0;
						}
						break;
					case 2:
						eLibro_getNombre(eLibro_I, nombreI);
						eLibro_getNombre(eLibro_J, nombreJ);
						if (strcmp(nombreI, nombreJ)>0) {
							aux = *(eLibro_I);
							*(eLibro_I) = *(eLibro_J);
							*(eLibro_J) = aux;
							rtn = 0;
							}
						break;
					case 3:
						eLibro_getHorasTrabajadas(eLibro_I, &horasTrabajadasI);
						eLibro_getHorasTrabajadas(eLibro_J, &horasTrabajadasJ);
						if (horasTrabajadasI > horasTrabajadasJ) {
							aux = *(eLibro_I);
							*(eLibro_I) = *(eLibro_J);
							*(eLibro_J) = aux;
							rtn = 0;
						}
						break;
					case 4:
						eLibro_getSueldo(eLibro_I, &sueldoI);
						eLibro_getSueldo((eLibro_J), &sueldoJ);
						if (sueldoI > sueldoJ) {
							aux = *(eLibro_I);
							*(eLibro_I) = *(eLibro_J);
							*(eLibro_J) = aux;
							rtn = 0;
						}
						break;
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < (ll_len(pArrayListeLibro)  - 1); i++) {
				eLibro_I = ll_get(pArrayListeLibro, i);
				for (int j = i + 1; j < ll_len(pArrayListeLibro) ; j++) {
					eLibro_J = ll_get(pArrayListeLibro, j);
					switch(opc){
					case 1:
						eLibro_getId(eLibro_I, &idI);
						eLibro_getId(eLibro_J, &idJ);
						if (idI < idJ) {
							aux = *(eLibro_I);
							*(eLibro_I) = *(eLibro_J);
							*(eLibro_J) = aux;
							rtn = 0;
						}
						break;
					case 2:
						eLibro_getNombre(eLibro_I, nombreI);
						eLibro_getNombre(eLibro_J, nombreJ);
						if (strcmp(nombreI, nombreJ)<0) {
							aux = *(eLibro_I);
							*(eLibro_I) = *(eLibro_J);
							*(eLibro_J) = aux;
							rtn = 0;
						}
						break;
					case 3:
						eLibro_getHorasTrabajadas(eLibro_I, &horasTrabajadasI);
						eLibro_getHorasTrabajadas(eLibro_J, &horasTrabajadasJ);
						if (horasTrabajadasI < horasTrabajadasJ) {
							aux = *(eLibro_I);
							*(eLibro_I) = *(eLibro_J);
							*(eLibro_J) = aux;
							rtn = 0;
						}
						break;
					case 4:
						eLibro_getSueldo(eLibro_I, &sueldoI);
						eLibro_getSueldo(eLibro_J, &sueldoJ);
						if (sueldoI < sueldoJ) {
							aux = *(eLibro_I);
							*(eLibro_I) = *(eLibro_J);
							rtn = 0;
						}
						break;
					}
				}
			}
			break;
		}
	}
	if(rtn ==0){
		puts("ORDENAMIENTO EXITOSO!");
		if(Validate_Exit_SN("DESEA MOSTRAR LA LISTA ORENADA? [S]-SI [N]-NO","ERROR. REINGRESE: ")){
			controller_ListeLibro(pArrayListeLibro);
		}
	}else{
		puts("ALGO SALIÓ MAL");
	}
	return rtn;
}
int controller_saveAsBinary(char* path , LinkedList* pArrayListeLibro)
{
	int rtn=0;
	int validacion;
	FILE* File;
	eLibro* emp;
	File = fopen(path,"wb");
	if(File != NULL){
		for(int i =0; i< ll_len(pArrayListeLibro); i++){
			emp = ll_get(pArrayListeLibro, i);
			if(emp!=NULL){
				validacion =fwrite(emp,sizeof(eLibro), 1, File);
				if(validacion !=1){
					free(emp);
					break;
				}else{
					rtn ++;
				}
			}
		}
		if(rtn==1000){
			puts("GUARDADO CON EXITO");
		}
		printf("%d", rtn);
	}
	fclose(File);
    return rtn;
}
*/

int controller_saveAsText(char* path , LinkedList* pArrayListeLibro)
{
	int rtn=-1;
	int cant;
	int id;
	char nombre[128];
	char autor[128];
	int precio;
	char editorial[128];
	eLibro* auxLibro;
	FILE* aux;

	aux = fopen(path,"w");
	if(aux != NULL){
		fprintf(aux,"ID, NOMBRE, AUTOR, PRECIO, EDITORIAL\n");
		for(int i =0; i< ll_len(pArrayListeLibro); i++){
			auxLibro = ll_get(pArrayListeLibro, i);
			if(auxLibro!=NULL){
				eLibro_getId(auxLibro, &id);
				eLibro_getNombreLibro(auxLibro, nombre);
				eLibro_getAutor(auxLibro, autor);
				eLibro_getPrecio(auxLibro, &precio);
				eLibro_getEditorialId(auxLibro, editorial);

				cant =fprintf(aux, "%d, %s, %s, %d, %s\n",  id , nombre, autor, precio, editorial);
				if(cant<0){
					puts("ERROR AL CARGAR");
					exit(1);
				}
			}
		rtn =1;
		}
		if(rtn==1){
			puts("GUARDADO CON EXITO");
		}

	}
	fclose(aux);
    return rtn;
}


int controller_leeUltimoId(){

	FILE* pFile = NULL;
	int id=-1;
	pFile = fopen("Ultimo.txt", "r");

	if(pFile != NULL){
		id = parser_obterenUltimoId(pFile);
		id++;
	}
	fclose(pFile);

	return id;
}


void controller_EscribirUltimoId(){

	FILE* pFile =NULL;
	int id = controller_leeUltimoId();
	pFile = fopen("Ultimo.txt", "w");
	if(pFile!=NULL){

		fprintf(pFile,"%d", id);
	}
	fclose(pFile);
}
