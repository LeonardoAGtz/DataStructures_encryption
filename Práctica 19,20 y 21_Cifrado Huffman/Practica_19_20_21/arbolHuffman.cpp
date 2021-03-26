#include "arbolHuffman.h"

TDA_Huffman::TDA_Huffman() {

    header = new NodoAL;


    header->setNext(header);
    header->setPrev(header);

    root = nullptr;
    }

bool TDA_Huffman::estaVacia() {
    return header->getNext() == header;
    }

void TDA_Huffman::insertarLista(NodoAL* n) {
    n->setNext(header);
    n->setPrev(header->getPrev());

    header->getPrev()->setNext(n);
    header->setPrev(n);
    }

void TDA_Huffman::borrarDatoLista(NodoAL* p) {
    p->getPrev()->setNext(p->getNext());
    p->getNext()->setPrev(p->getPrev());
    delete p;
    }

NodoAL* TDA_Huffman::getPrimeraPos() {
    if(estaVacia()) {
        return nullptr;
        }

    return header->getNext();
    }

NodoAL* TDA_Huffman::getUltimaPos() {
    if(estaVacia()) {
        return nullptr;
        }

    return header->getPrev();
    }

void TDA_Huffman::ordenarLista() {
    ordenarLista(getPrimeraPos(), getUltimaPos());
    burbuja();
    }

void TDA_Huffman::burbuja() {
    if(getPrimeraPos() == getUltimaPos()) {
        return;
        }

    NodoAL *aux(getPrimeraPos()), *aux2;


    while(aux->getNext() != getUltimaPos()) {
        aux2 = aux->getNext();
        while(aux2 != getUltimaPos() and aux->getFrecuencia() == aux2->getFrecuencia()) {

            if(aux2->getChar() < aux->getChar()) {
                cambiar(aux2, aux);
                }
            aux2 = aux2->getNext();
            }
        aux = aux->getNext();
        }

    }

void TDA_Huffman::cambiar(NodoAL* a, NodoAL* b) {
    NodoAL* aux;
    aux = new NodoAL();

    aux->setChar(a->getChar());
    aux->setFrecuencia(a->getFrecuencia());

    a->setChar(b->getChar());
    a->setFrecuencia(b->getFrecuencia());

    b->setChar(aux->getChar());
    b->setFrecuencia(aux->getFrecuencia());

    delete aux;

    }

void TDA_Huffman::ordenarLista(NodoAL* leftEdge, NodoAL* rightEdge) {
    if(leftEdge == rightEdge) {
        return;
        }

    NodoAL *i(leftEdge), *j(rightEdge);

    while(i != j) {
        while(i != j and i->getFrecuencia() <= rightEdge->getFrecuencia()) {
            i = i->getNext();
            }

        while(i != j and j->getFrecuencia() >= rightEdge->getFrecuencia()) {
            j = j->getPrev();
            }

        if(i != j) {
            cambiar(i, j);
            }
        }
    if(i != rightEdge) {
        cambiar(i, rightEdge);
        }
    if(i != leftEdge) {
        ordenarLista(leftEdge, i->getPrev());
        }
    if(i != rightEdge) {
        ordenarLista(i->getNext(), rightEdge);
        }
    }

void TDA_Huffman::insertarOrdenado(NodoAL* p) {
    if(estaVacia()) {
        insertarLista(p);
        return;
        }

    NodoAL* aux(getPrimeraPos());

    while(aux != header) {
        if(p->getFrecuencia() > aux->getPrev()->getFrecuencia() and p->getFrecuencia() <= aux->getFrecuencia()) {
            p->setNext(aux);
            p->setPrev(aux->getPrev());

            aux->getPrev()->setNext(p);
            aux->setPrev(p);
            return;
            }
        aux = aux->getNext();
        }

    insertarLista(p);

    }

void TDA_Huffman::construirArbol() {
    NodoAL* a(getPrimeraPos());
    NodoAL* b(a->getNext());
    NodoAL* aux;
    NodoAL* auxi;

    while(getPrimeraPos() != getUltimaPos()) {
        aux = new NodoAL();
        aux->setFrecuencia(a->getFrecuencia() + b->getFrecuencia());
        aux->setLeft(a);
        aux->setRight(b);

        header->setNext(b->getNext());
        header->getNext()->setPrev(header);

        a->setNext(nullptr);
        a->setPrev(nullptr);

        b->setNext(nullptr);
        b->setPrev(nullptr);

        insertarOrdenado(aux);

        a = getPrimeraPos();
        b = a->getNext();
        }

    root = getPrimeraPos();

    }

void TDA_Huffman::mostrarArbol(NodoAL* r, int cont) {
    if(r == nullptr) {
        return;
        }
    mostrarArbol(r->getRight(), cont+1);

    for(int i(0); i< cont; i++) {
        cout << "             ";
        }
    cout << r->getChar() << ":" << r->getFrecuencia() << endl;
    mostrarArbol(r->getLeft(), cont +1 );
    }

void TDA_Huffman::mostrarArbol() {
    x = 0;

    mostrarArbol(root, x);
    }

NodoAL* TDA_Huffman::buscar(const char& c) {
    if(estaVacia()) {
        return nullptr;
        }

    NodoAL* aux(getPrimeraPos());

    while(aux != header) {
        if(aux->getChar() == c) {
            return aux;
            }
        aux = aux->getNext();
        }

    return nullptr;

    }

NodoAL* TDA_Huffman::buscarDiccionario(const string& c) {
    if(estaVacia()) {
        return nullptr;
        }

    NodoAL* aux(getPrimeraPos());

    while(aux != header) {
        if(aux->getCodigo() == c) {
            return aux;
            }
        aux = aux->getNext();
        }

    return nullptr;

    }

void TDA_Huffman::llenar(const string& a) {
    int x(a.length()), contador(0);
    NodoAL* auxBusqueda(nullptr);
    char cadena[100000];
    NodoAL* nuevo;

    strcpy(cadena, a.c_str());

    for(int i(0); i < x; i++) {
        contador = 0;
        auxBusqueda = buscar(cadena[i]);

        if(auxBusqueda == nullptr) {
            for(int j(i); j < x; j++) {
                if(cadena[i] == cadena[j]) {
                    contador++;
                    }

                }
            nuevo = new NodoAL(cadena[i], contador);

            insertarLista(nuevo);
            }
        }

    }

void TDA_Huffman::construirDiccionario() {
    string a, b;
    a = '1';
    b = '0';

    construirDiccionario(root->getLeft(), a);
    construirDiccionario(root->getRight(), b);

    borrarArbol();
    }

void TDA_Huffman::construirDiccionario(NodoAL*& r, string& cadena) {

    if(r == nullptr) {
        return;
        }
    string a(cadena), b(cadena);
    a += '1';
    b += '0';

    if(r->getLeft() == nullptr and r->getRight() == nullptr) {
        NodoAL* nuevo = new NodoAL();
        nuevo->setChar(r->getChar());
        nuevo->setCodigo(cadena);
        insertarLista(nuevo);
        }

    construirDiccionario(r->getLeft(), a);
    construirDiccionario(r->getRight(), b);
    }

void TDA_Huffman::borrarArbol() {
    root->getPrev()->setNext(root->getNext());
    root->getNext()->setPrev(root->getPrev());
    borrarArbol(root);

    root = nullptr;
    }

void TDA_Huffman::borrarArbol(NodoAL* r) {
    if(r == nullptr) {
        return;
        }

    borrarArbol(r->getLeft());
    borrarArbol(r->getRight());

    delete r;
    }

string TDA_Huffman::traducirCadena(const string& cadena) {
    string nueva;
    int maxx(cadena.length()), i(0);
    char x[maxx];
    NodoAL* aux;

    strcpy(x, cadena.c_str());

    while(i < maxx) {
        aux = buscar(x[i]);
        if(aux == nullptr){
            break;
        }
        nueva += aux->getCodigo();
        i++;
        }

    return nueva;
    }


void TDA_Huffman::gotoxy(int x, int y) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwpos;
    dwpos.X = x;
    dwpos.Y = y;
    SetConsoleCursorPosition(hcon, dwpos);
    }
