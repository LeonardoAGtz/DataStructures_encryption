#include <iostream>
#include "cifrados.h"

using namespace std;

int main()
{
    string op, data;
    Cifrados c;
    while (true) {
        system("cls");
        cout << "Menu Practica 18 by EvoSenpai(Leonardo Aranda 217761528 INNI)" << endl;
        cout << "1) Cargar archivo a memoria con extancion .txt" << endl;
        cout << "2) Cifrar con Cesar" << endl;
        cout << "3) Cifrar con Xor" << endl;
        cout << "4) Descifrar con Cesar" << endl;
        cout << "5) Descifrar con Xor" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {
            string temp;
            cout << "Ingresa el nombre del archivo que quieres cargar: ";
            getline(cin, temp);
            data = c.cargarArchivo(temp);
        } else if (op == "2") {
            c.cifrarCesar(data);
        } else if (op == "3") {
            c.cifrarXor(data, '@');
        } else if (op == "4") {
            c.descifrarCesar();
        } else if (op == "5") {
            c.descifrarXor('@');
        } else if (op == "0") {
            break;
        }
    }
    return 0;
}
