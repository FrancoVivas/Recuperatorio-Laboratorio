/*
 * Biblioteca.h
 *
 *  Created on: 4 ago. 2021
 *      Author: N3630024213
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <String.h>

//VALIDATIONS
int Validation_OnlyInt(char* numero);//Validacion de numero, ingluye tanto los positivos como los negativos
int Validate_OnlyNumberInt(char *pData);
int Validate_OnlyNumberFloat(char *pData);
int Validate_OnlyAlphabet(char *pData);
int Validate_OnlyAlphabetWithSpaces(char *pData);
int Validate_Exit_SN(char* MSJ, char* MSJERROR);
//GET'S
int Get_Int(char* MSJ, char* MSJERROR); //Pide un numero y lo valida usando Validation_OnlyInt
float Get_Float(char* MSJ, char* MSJERROR);
int Get_IntRange(char* MSJ, char*MSJERROR, int MIN, int MAX);
void Get_String(char* MSJ, char* MSJERROR, char* pArray, int MAX);
void Get_OnlyAlphabetStringWithSpaces(char* MSJ, char* MSJERROR,  char* pArray, int MAX);
int Get_IntPositive(char* MSJ, char* MSJERROR);

//FUNCIONES UTILES

void Menu(char* MSJ);

#endif /* BIBLIOTECA_H_ */
