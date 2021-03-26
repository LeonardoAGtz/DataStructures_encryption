#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <fstream>
#include "song.h"
#include "arbolHuffman.h"

using namespace std;

class Menu
{
public:
    Menu();

    void create();
    void read();
    void update();
    void delete_F();
    void delete_L();
    void find(const string &code);
    void count();
    void activate();
    void comprimir();
    void descomprimir();
    string lastcode();
};

#endif // MENU_H
