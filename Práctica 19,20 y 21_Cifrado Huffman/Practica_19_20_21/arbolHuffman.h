#ifndef ARBOLHUFFMAN_H_INCLUDED
#define ARBOLHUFFMAN_H_INCLUDED

#include <iostream>
#include <string.h>
#include "stdlib.h"
#include <stdio.h>
#include <string.h>

#include "nodoAL.h"
#include "conio.h"
#include "windows.h"

class TDA_Huffman {
    private:

        NodoAL* header;
        NodoAL* root;

        int x;

        void cambiar(NodoAL*, NodoAL*);

        void ordenarLista(NodoAL*, NodoAL*);
        void burbuja();

        void gotoxy(int, int);
        void mostrarArbol(NodoAL*, int);

        void construirDiccionario(NodoAL*&, string&);

        void borrarArbol();

public:

        TDA_Huffman();

        bool estaVacia();
        void insertarLista(NodoAL*);
        void insertarOrdenado(NodoAL*);
        void borrarDatoLista(NodoAL*);

        NodoAL* getPrimeraPos();
        NodoAL* getUltimaPos();

        NodoAL* buscar(const char&);
        NodoAL* buscarDiccionario(const string&);

        void ordenarLista();

        void construirArbol();
        void mostrarArbol();

        void llenar(const string&);

        void construirDiccionario();

        void borrarArbol(NodoAL*);

        string traducirCadena(const string&);

    };

#endif // ARBOLHUFFMAN_H_INCLUDED
