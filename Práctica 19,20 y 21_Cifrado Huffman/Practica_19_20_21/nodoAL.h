#ifndef NODOAL_H_INCLUDED
#define NODOAL_H_INCLUDED

#include <iostream>

using namespace std;

class NodoAL {

    private:

        char caracter;
        int frecuencia;
        string codigo;

        NodoAL* next;
        NodoAL* prev;

        NodoAL* left;
        NodoAL* right;


    public:

        NodoAL();
        NodoAL(const char&, const int&);

        char getChar();
        int getFrecuencia();
        string getCodigo();

        NodoAL* getNext();
        NodoAL* getPrev();

        NodoAL*& getRight();
        NodoAL*& getLeft();

        void setChar(const char&);
        void setFrecuencia(const int&);
        void setCodigo(const string&);

        void setNext(NodoAL*);
        void setPrev(NodoAL*);

        void setRight(NodoAL*&);
        void setLeft(NodoAL*&);

    };

#endif // NODOAL_H_INCLUDED
