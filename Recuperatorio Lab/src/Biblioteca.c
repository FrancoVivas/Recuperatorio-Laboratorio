/*
 * Biblioteca.c
 *
 *  Created on: 4 ago. 2021
 *      Author: N3630024213
 */


#include "Biblioteca.h"

//*** VALIDACIONES - INICIO
int Validate_OnlyNumberInt(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isdigit(pData[i]) == 0) {
				if (i == 0) {
					if (pData[0] != '-') {
						rtn = 0;
						break;
					}
				} else {
					rtn = 0;
					break;
				}
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyNumberFloat(char *pData) {
	int countSigno = 0;
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {

			if (pData[i] == '.' || pData[i] == ',') {
				countSigno++;
			} else {
				if (isdigit(pData[i]) == 0) {
					if (i == 0) {
						if (pData[0] != '-') {
							rtn = 0;
							break;
						}
					} else {
						rtn = 0;
						break;
					}
				}
			}
		}

		if (countSigno > 1) {
			rtn = 0;
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyAlphabet(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				rtn = 0 ;
				break;
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyAlphabetWithSpaces(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				if (isspace(pData[i]) == 0) {
					rtn = 0;
					break;
				}
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}



//GETS
int Get_Int(char* MSJ, char* MSJERROR)
{
	char buffer [1000];
	int rtn;

	printf(MSJ);
	fflush(stdin);
	gets(buffer);

	while((Validate_OnlyNumberInt(buffer))==0)
	{
		printf(MSJERROR);
		fflush(stdin);
		gets(buffer);
	}

	rtn = atoi(buffer);

	return rtn;
}
int Get_IntRange(char* MSJ, char*MSJERROR, int MIN, int MAX)
{
	int rtn = Get_Int(MSJ, MSJERROR);

	while((rtn < MIN) ||( rtn > MAX))
	{
		printf("ERROR. Fuera de rango: MINIMO = %d   MAXIMO = %d. \n", MIN, MAX);
		rtn = Get_Int(MSJ, MSJERROR);
	}

	return rtn;
}
float Get_Float(char* MSJ, char* MSJERROR)
{
	char buffer[1000];
	float rtn = 0;

	printf(MSJ);
	fflush(stdin);
	gets(buffer);

	while((Validate_OnlyNumberInt(buffer))== 0)
	{
		printf(MSJERROR);
		fflush(stdin);
		gets(buffer);
	}


	rtn= atof(buffer);
	return rtn;
}
void Get_String(char* MSJ, char* MSJERROR, char* pArray, int MAX)
{
	char buffer[1000];

	printf(MSJ);
	fflush(stdin);
	gets(buffer);

	while((Validate_OnlyAlphabetWithSpaces(buffer)) == 0|| strlen(buffer) > MAX )
	{
		printf(MSJERROR);
		fflush(stdin);
		gets(buffer);

	}
	strcpy(pArray, buffer);
	atof(pArray);

}
void Get_OnlyAlphabetStringWithSpaces(char* MSJ, char* MSJERROR,  char* pArray, int MAX)
{
	char buffer[1000];


	printf(MSJ);
	fflush(stdin);
	gets(buffer);

	while(((Validate_OnlyAlphabetWithSpaces(buffer)) == 0) || (strlen(buffer) > MAX))
	{
		printf(MSJERROR);
		fflush(stdin);
		gets(buffer);

	}
	strcpy(pArray, buffer);
	atof(pArray);

}
int Get_IntPositive(char* MSJ, char* MSJERROR)
{
	int rtn = Get_Int(MSJ, MSJERROR);

	while(rtn <0)
	{
		puts(MSJERROR);
		rtn = Get_Int(MSJ, MSJERROR);
	}

	return rtn;
}
//FUNCIONES UTILES
int Validate_Exit_SN(char* MSJ, char* MSJERROR){
	char respuesta;
	int rtn;

	printf(MSJ);
	fflush(stdin);
	scanf("%c", &respuesta);

	respuesta =tolower(respuesta);
	while(respuesta != 'n' && respuesta != 's')
	{
		printf(MSJERROR);
		fflush(stdin);
		scanf("%c", &respuesta);
	}

	if(respuesta > 0)
	{
		respuesta = tolower(respuesta);

		if(respuesta == 's')
		{
			rtn = 1;
		}
		else{
			rtn=0;
		}

	}


	return rtn;

}
void Menu(char* MSJ)
{
	puts(MSJ);
}
