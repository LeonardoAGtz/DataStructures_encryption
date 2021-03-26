#include "cifrados.h"
//Para evitar hacer un casteo de string a char y ahorrarme problemas con la escritura de caracteres adicionales
//Uso las funciones lenght para determinar tamaños y la funcion at para devolver el valor del ASCII sin tener que hacer el
//Respectivo casteo
Cifrados::Cifrados(){}

void Cifrados::cifrarCesar(const string &data)//Listo
{
    string encriptadoCesar; int desplazamiento(3);
    for (unsigned int i = 0; i < data.length(); ++i) {
        if (!data.at(i)== 13) {
            encriptadoCesar += data.at(i) + desplazamiento;
        }
    }

    ofstream save("EncriptadoCesar.txt", ios::app);
    save << encriptadoCesar;
    save.close();
}

void Cifrados::descifrarCesar()//Listo
{
    string data, uncripted;
    ifstream load("EncriptadoCesar.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            getline(load, temp);
            data += temp;
        }
    }load.close();


    for (unsigned int i = 0; i < data.length(); ++i) {
        uncripted += (data.at(i) - 3);
    }

    ofstream save("DescencriptadoCesar.txt", ios::app);
    save << uncripted;
    save.close();
}

void Cifrados::cifrarXor(const string &data, const char key)//Listo
{
    string encriptadoXor;
    for (unsigned int i = 0; i < data.length(); ++i) {
        encriptadoXor += data.at(i) ^ key;
    }

    ofstream save("CifradoXor.txt", ios::app);
    save << encriptadoXor;
    save.close();
}

void Cifrados::descifrarXor(const char key)//Listo
{
    string descifradoXor, data;
    ifstream load("CifradoXor.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            getline(load, temp);
            data += temp;
        }
    }load.close();

    for (unsigned int i = 0; i < data.length(); ++i) {
        descifradoXor += data.at(i) ^ key;
    }

    ofstream save("DescifradoXor.txt", ios::app);
    save << descifradoXor;
    save.close();
}

string Cifrados::cargarArchivo(const string &archivo)//Listo
{
    string data;

    ifstream load(archivo, ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            getline(load, temp);
            data += temp;
        }
    }load.close();

    return data;
}
