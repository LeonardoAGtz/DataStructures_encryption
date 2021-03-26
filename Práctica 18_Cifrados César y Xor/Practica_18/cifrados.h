#ifndef CIFRADOS_H
#define CIFRADOS_H
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Cifrados
{
public:
    Cifrados();
    string cargarArchivo(const string &archivo);
    void cifrarCesar(const string &data);
    void descifrarCesar();
    void cifrarXor(const string &data, const char key);
    void descifrarXor(const char key);
};

#endif // CIFRADOS_H
