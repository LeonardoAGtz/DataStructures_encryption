#include "nodoAL.h"

NodoAL::NodoAL() {
    caracter = '\0';
    frecuencia = 0;
    next = nullptr;
    prev = nullptr;
    left = nullptr;
    right = nullptr;
    }

NodoAL::NodoAL(const char& c, const int& i) {
    caracter = c;
    frecuencia = i;
    next = nullptr;
    prev = nullptr;
    left = nullptr;
    right = nullptr;
    }

char NodoAL::getChar() {
    return caracter;
    }

int NodoAL::getFrecuencia() {
    return frecuencia;
    }

NodoAL* NodoAL::getNext() {
    return next;
    }

NodoAL* NodoAL::getPrev() {
    return prev;
    }

NodoAL*& NodoAL::getRight() {
    return right;
    }

NodoAL*& NodoAL::getLeft() {
    return left;
    }

void NodoAL::setChar(const char& c) {
    caracter = c;
    }

void NodoAL::setFrecuencia(const int& i) {
    frecuencia = i;
    }

string NodoAL::getCodigo() {
    return codigo;
    }


void NodoAL::setNext(NodoAL* n) {
    next = n;
    }

void NodoAL::setPrev(NodoAL* n) {
    prev = n;
    }

void NodoAL::setRight(NodoAL*& n) {
    right = n;
    }

void NodoAL::setLeft(NodoAL*& n) {
    left = n;
    }

void NodoAL::setCodigo(const string& s) {
    codigo = s;
    }

