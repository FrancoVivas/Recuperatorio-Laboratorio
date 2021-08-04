/*
 * Controller.h
 *
 *  Created on: 4 ago. 2021
 *      Author: N3630024213
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayListLibro);
int controller_loadFromBinary(char* path , LinkedList* pArrayListLibro);
int controller_addLibro(LinkedList* pArrayListLibro, int id);
int controller_editLibro(LinkedList* pArrayListLibro);
int controller_removeLibro(LinkedList* pArrayListLibro);
int controller_ListLibro(LinkedList* pArrayListLibro);
int controller_sortLibro(LinkedList* pArrayListLibro);
int controller_saveAsText(char* path , LinkedList* pArrayListLibro);
int controller_saveAsBinary(char* path , LinkedList* pArrayListLibro);
int controller_leeUltimoId();
void controller_EscribirUltimoId();

/** \brief Llama a ll_sort y pasa por parametro una funcion con dos elementos void*
 * \param LinkedList* Puntero a la lista
 *
 *
 * \return int Retorna  (0) Error
						(1) Si llamo a la funcion sort con exito
 */
int controller_ordenar(LinkedList* this);

/** \brief compara dos nombres de autores por orden alfabetico
 * \param void* libroUno
 * \param void* libroDos
 *
 * \return int Retorna  (0) Error
						( 1) Si LibroDos es mayor que libroUno
						(-1) Si LibroUno es mayor que libroDos
 */
int controller_ordenarPorAutor(void* libroUno, void* LibroDos);

/** \brief llama a ll_map y le pasa una funcion por parametro
 * \param LinkedList* puntero a linkedlist
 *
 *
 * \return int Retorna  (0) Error
						( 1) Si Pudo llamar a ll_map
 */
int controller_descuento(LinkedList* this);

/** \brief calcula el 20% de descuento de la editorial "Planeta" a partir de $300
 * y calcula el 10% de descuento de la editorial "SIGLO XXI EDITORES" con precio menor a 200
 * \param void* puntero a void
 *
 *
 * \return void
 */
void controller_calcularDescuento(void* pElement);

/** \brief llama a la funicon ll_filter y le pasa un puntero a una funcion como parametro
 *
 * \param LinkedList* puntero a linkedlist
 *
 *
 * \return int Retorna (0) ERROR
						(1)Si pudo filtrar la LL
 */
int controller_Filter(LinkedList* this);

/** \brief Compara un autor de la LinkedList con "Rowling"
 *
 * \param void* puntero a void
 *
 *
 * \return int Retorna (0) ERROR
						(1)Si es el autor es el mismo
 */
int controller_filtraAutor(void* pElement);

/** \brief llama a la funicon ll_count y le pasa un puntero a una funcion como parametro
 * y imprime la cantidad de libros de Rowling
 *
 * \param LinkedList* puntero a linkedlist
 *
 *
 * \return void
 */
void controller_count(LinkedList* this);

/** \brief Compara un autor de la LinkedList con "Rowling"
 *
 * \param void* puntero a void
 *
 *
 * \return int Retorna (0) ERROR
						(1)Si es el autor es el mismo
 */
int controller_contarPorAutor(void* pElement);

#endif /* CONTROLLER_H_ */
