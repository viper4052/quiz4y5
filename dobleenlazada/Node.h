#include <iostream>

#ifndef NODE 

#define NODE 1

using namespace std;

// 1. pasar este nodo a doblemente enlazado
template <class T>
class Node {
    private:
        T *data;
        Node *prev;
        Node *next;
    
    public:
        Node() {
            data = NULL;
            prev = NULL;
            next = NULL;
        };

        Node(T *pData) {
            this->data = pData;
            prev = NULL;
            next = NULL;
        };

        T* getData() {
            return data;
        };

        Node* getPrev() {
            return prev;
        };

        void setPrev(Node *pValue) {
            this->setPrev = pValue;
        };

        Node* getNext() {
            return next;
        };

        void setNext(Node *pValue) {
            this->next = pValue;
        };

};

#endif