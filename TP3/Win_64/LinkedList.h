/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index); //Te da una copia del puntero que apunta al elemento.
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList* this,int index); //Lo saca de la lista.
int ll_clear(LinkedList* this); //Hace como un remove de todos.
int ll_deleteLinkedList(LinkedList* this); //Libera la memoria.
int ll_indexOf(LinkedList* this, void* pElement); //Es como un buscar.
int ll_isEmpty(LinkedList* this); //Si está vacio o no está vacio.
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to); //Desde donde hasta donde, y devuelve una copia de eso.
LinkedList* ll_clone(LinkedList* this); //Copia el linkedlist anterior y devuelve el puntero del primer elemento.
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); //Es el ordenamiento
