#include "Node.h"
#include "../eventos/event.h"
#include <typeinfo>
#include <iostream>

#ifndef LIST 

#define LIST 1

// 2. ajustar a que esta lista sea doblemente enlazada, cambia el add, find, insert y el remove
template <class T>
class List {
    private:
        Node<T> *first;
        Node<T> *last;
        int quantity;
        bool empty;
        Node<T> *searchPosition = NULL;
        Node<T> *searchFront = NULL; // para que busque el elemento al frente cuando se mueve de adelante para atras
        Node<T> *searchBehind = NULL;

    public:
        List() {
            first = NULL;
            last = NULL;
            quantity = 0;
            empty = true;
        }

        void add(T *pData) {
            Node<T> *newNode = new Node<T>(pData);

            if (quantity>0) {
                this->last->setNext(newNode);
                newNode->setPrev(this->last); // define el previo como el ultimo original de la lista

            } else {
                this->first = newNode;
            }
            this->last = newNode;

            empty = false;
            quantity++;
        }

        Node<T>* getFirst() {
            return this->first;
        }

        int getSize() {
            return quantity;
        }

        bool isEmpty() {
            return !quantity;
        }

        T* find(int pPosition) {
            T* result = NULL;
            searchPosition = this->first;
            searchFront = NULL;  // define en null lo que pueda retornar que es lo que hay al frente del nodo
            searchBehind = NULL;

            if (pPosition<getSize()) {
                while(pPosition>0) {
                    searchBehind = searchPosition;
                    searchPosition = searchPosition->getNext();
                    searchFront = searchPosition->getPrev(); // busca el nodo previo del elemento que pase "searchPosition"
                    pPosition--;
                }
                result = searchPosition->getData();
            }

            return result;
        }

        // es que si el position es mayor a la cantidad, entonces inserto al final
        void insert(int pPosition, T *pData) {
            
            if (pPosition<getSize() && first!=NULL) {
                Node<T> *newNodo = new Node<T>(pData);

                T* result = find(pPosition);
                
                newNodo->setNext(searchPosition);
                newNodo->setPrev(searchFront);

                if (searchBehind!=NULL) {
                    searchBehind->setNext(newNodo);
                    newNodo->setPrev(searchFront);
                    
                } else {
                    this->first = newNodo;
                }
                
                quantity++;
            } else {
                add(pData);
            }
        }

        bool remove(int pPosition) {
            bool result = false;
            if (first!=NULL && pPosition<getSize()) {
                Node<T> *search = first;
                if (pPosition!=0) {
                    T* data = find(pPosition);

                    searchBehind->setNext(searchPosition->getNext());
                    searchBehind->setPrev(searchPosition->getPrev());

                    searchFront->setNext(searchPosition->getNext());
                    searchFront->setPrev(searchPosition->getPrev());

                    if (searchPosition==last) {
                        last = searchBehind;
                    }
                    searchPosition->setNext(NULL);
                    searchPosition->setPrev(NULL);
                } else {
                    first = first->getNext();
                    search->setNext(NULL);
                    search->setPrev(NULL);
                    delete search;
                }
                quantity--;
            }
            return result;
        } 
}; //test

#endif