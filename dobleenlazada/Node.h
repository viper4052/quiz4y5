#include <iostream>

#ifndef NODE 

#define NODE 1

using namespace std;

// 1. pasar este nodo a doblemente enlazado
template <class T>
class Node {
    private:
        T *data;
        Node *previous; // crea un puntero que sirva para apuntar al nodo anterior
        Node *next;
    
    public:
        Node() {
            data = NULL;
            previous = NULL; // define que el nodo anterior apunte a nulo
            next = NULL;
        }

        Node(T *pData) {
            this->data = pData;
            next = NULL;
        }

        T* getData() {
            return data;
        }

        Node* getPrevious() { // getter del nodo anterior
            return previous;
        }

        Node* getNext() {
            return next;
        }

        void setNext(Node *pValue) {
            this->next = pValue;
        }
};

#endif