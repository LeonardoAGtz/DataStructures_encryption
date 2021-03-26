#include "menu.h"
#include <math.h>

Menu::Menu()
{
    string op;
    while (true) {
        system("cls");
        cout << "Menu Practica 19, 20 y 21 by EvoSenpai(Leonardo Aranda 217761528 INNI)" << endl;
        cout << "   1) Crear Cancion" << endl;
        cout << "   2) Mostrar Canciones" << endl;
        cout << "   3) Contar Canciones" << endl;
        cout << "   4) Eliminar Fisicamente" << endl;
        cout << "   5) Eliminar Logicamente" << endl;
        cout << "   6) Editar Cancion" << endl;
        cout << "   7) Buscar Cancion" << endl;
        cout << "   8) Activar Registro" << endl;
        cout << "   9) Comprimir" << endl;
        cout << "   10)Descomprimir" << endl;
        cout << "   0) Salir" << endl;
        cout << endl;
        cout << "   >>";
        getline(cin, op);

        if (op == "1") {
            create();
        }else if (op == "2") {
            read();
            system("pause");
        }else if (op == "3") {
            count();
            system("cls");
        }else if (op == "4") {
            delete_F();
        }else if (op == "5") {
            delete_L();
        }else if (op == "6") {
            update();
        }else if (op == "7") {
            system("cls");
            string code;
            cout << "Ingresa el id de la cancion que buscas: ";
            getline(cin, code);
            cout << endl;
            find(code);
            system("pause");
        }else if (op == "8") {
            activate();
        }else if (op == "9") {
            comprimir();
        }else if (op == "10") {
            descomprimir();
        }else if (op == "0") {
            break;
        }
    }
}

void Menu::create()
{
    system("cls");
    Song song;
    string temp;

    song.setId(lastcode());
    cout << "Nombre de la cancion: ";
    getline(cin, temp);
    song.setNombre(temp);
    cout << "Interprete de la cancion: ";
    getline(cin, temp);
    song.setInterprete(temp);
    cout << "Genero de la cancion: ";
    getline(cin, temp);
    song.setGenero(temp);
    temp = "1";
    song.setStatus(temp);


    ofstream save("Canciones_W_D.txt", ios::app);
    save << song.getId() << endl;
    save << song.getNombre() << endl;
    save << song.getInterprete() << endl;
    save << song.getGenero() << endl;
    save << song.getStatus() << endl << endl;
    save.close();

}

void Menu::read()
{
    system("cls");
    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);

            if (song.getStatus() == "1") {
                cout << "Cancion:    " << song.getId() << endl;
                cout << "Nombre:     " << song.getNombre() << endl;
                cout << "Interprete: " << song.getInterprete() << endl;
                cout << "Genero:     " << song.getGenero() << endl;
                cout << "Status:     " << song.getStatus() << endl << endl;
            }
        }
    }load.close();
}

void Menu::update()
{
    read();
    string code;

    cout << endl << endl << "Ingresa el ID de la cancion que deseas editar: ";
    getline(cin, code);

    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);

            if (song.getId() == code and song.getStatus() == "1") {
                string temp2;
                cout << "Cancion:          " << song.getId() << endl;
                cout << "Nuevo Nombre:     ";
                getline(cin, temp2);
                song.setNombre(temp2);
                cout << "Nuevo Interprete: ";
                getline(cin, temp2);
                song.setInterprete(temp2);
                cout << "Nuevo Genero:     ";
                getline(cin, temp2);
                song.setGenero(temp2);
            }

            ofstream save("Temp_C_W_D.txt", ios::app);
            save << song.getId() << endl;
            save << song.getNombre() << endl;
            save << song.getInterprete() << endl;
            save << song.getGenero() << endl;
            save << song.getStatus() << endl << endl;
            save.close();

        }
    }load.close();

    remove("Canciones_W_D.txt");
    rename("Temp_C_W_D.txt","Canciones_W_D.txt");
}

void Menu::delete_F()
{
    read();
    string code;

    cout << endl << endl << "Ingresa el ID de la cancion que deseas eliminar: ";
    getline(cin, code);

    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);

            if (song.getId() != code and song.getStatus() == "1") {
                ofstream save("Temp_C_W_D.txt", ios::app);
                save << song.getId() << endl;
                save << song.getNombre() << endl;
                save << song.getInterprete() << endl;
                save << song.getGenero() << endl;
                save << song.getStatus() << endl << endl;
                save.close();
            }
        }
    }load.close();

    remove("Canciones_W_D.txt");
    rename("Temp_C_W_D.txt","Canciones_W_D.txt");
}

void Menu::delete_L()
{
    read();
    string code;

    cout << endl << endl << "Ingresa el ID de la cancion que deseas desactivar: ";
    getline(cin, code);

    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);

            if (song.getId() == code and song.getStatus() == "1") {
                string temp2 = "0";
                song.setStatus(temp2);
            }

            ofstream save("Temp_C_W_D.txt", ios::app);
            save << song.getId() << endl;
            save << song.getNombre() << endl;
            save << song.getInterprete() << endl;
            save << song.getGenero() << endl;
            save << song.getStatus() << endl << endl;
            save.close();

        }
    }load.close();

    remove("Canciones_W_D.txt");
    rename("Temp_C_W_D.txt","Canciones_W_D.txt");
}

void Menu::find(const string &code)
{
    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);

            if (song.getId() == code and song.getStatus() == "1") {
                cout << "Cancion:    " << song.getId() << endl;
                cout << "Nombre:     " << song.getNombre() << endl;
                cout << "Interprete: " << song.getInterprete() << endl;
                cout << "Genero:     " << song.getGenero() << endl;
                cout << "Status:     " << song.getStatus() << endl << endl;
            }
        }
    }load.close();
}

void Menu::count()
{
    system("cls");
    int counter = 0;
    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);
            counter++;
        }
    }load.close();

    cout << "Hay: " << counter << "canciones registradas :D" << endl;
}

void Menu::activate()
{
    system("cls");
    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);

            if (song.getStatus() == "0") {
                cout << "Cancion:    " << song.getId() << endl;
                cout << "Nombre:     " << song.getNombre() << endl;
                cout << "Interprete: " << song.getInterprete() << endl;
                cout << "Genero:     " << song.getGenero() << endl;
                cout << "Status:     " << song.getStatus() << endl << endl;
            }
        }
    }load.close();

    string code;
    cout << endl << endl << "Ingresa el id de la cancion que quieres activar: ";
    getline(cin, code);

    ifstream load2("Canciones_W_D.txt", ios::in);
    if (load2.is_open()) {
        while (!load2.eof()) {
            string temp;
            Song song;
            getline(load2, temp);
            if (load2.eof()){break;}
            song.setId(temp);
            getline(load2, temp);
            song.setNombre(temp);
            getline(load2, temp);
            song.setInterprete(temp);
            getline(load2, temp);
            song.setGenero(temp);
            getline(load2, temp);
            song.setStatus(temp);
            getline(load2, temp);

            if (song.getId() == code and song.getStatus() == "0") {
                string temp2 = "1";
                song.setStatus(temp2);
            }

            ofstream save("Temp_C_W_D.txt", ios::app);
            save << song.getId() << endl;
            save << song.getNombre() << endl;
            save << song.getInterprete() << endl;
            save << song.getGenero() << endl;
            save << song.getStatus() << endl << endl;
            save.close();

        }
    }load2.close();

    remove("Canciones_W_D.txt");
    rename("Temp_C_W_D.txt","Canciones_W_D.txt");
}

void Menu::comprimir()
{
    TDA_Huffman TDA;
    string cadena, myStr, x;;

    system("cls");
    cout << "Paso 1: Cargar archivo a memoria" << endl << endl;


    ifstream readOfDisk("Canciones_W_D.txt");
    if(!readOfDisk.good()) {
        cout << "No puedes comprimir un archivo que no existe o esta comprimido." << endl;
        cout << "Presiona [enter], para continuar." << endl;
        getline(cin, myStr);
        readOfDisk.close();
        return;

    }
    else {
        while(!readOfDisk.eof()) {
            getline(readOfDisk, x);
            cadena += x;
        }
        readOfDisk.close();

    }

    cout << cadena << endl << endl;
    system("pause");

    cout << endl << "Paso 2: Construir TDA."  << endl << endl;
    TDA.llenar(cadena);

    NodoAL* aux(TDA.getPrimeraPos());

    while(aux != TDA.getUltimaPos()->getNext()) {
        cout << aux->getChar() << ":" << aux->getFrecuencia() << " -> ";
        aux = aux->getNext();
    }
    cout << endl << endl;
    system("pause");

    cout << endl << "Paso 3: Ordenar TDA."  << endl << endl;
    TDA.ordenarLista();

    aux = TDA.getPrimeraPos();

    while(aux != TDA.getUltimaPos()->getNext()) {
        cout << aux->getChar() << ":" << aux->getFrecuencia() << " -> ";
        aux = aux->getNext();
    }
    cout << endl << endl;
    system("pause");

    cout << endl << "Paso 4: Construir arbol."  << endl << endl;
    TDA.construirArbol();

    TDA.mostrarArbol();
    cout << endl << endl;
    system("pause");

    cout << endl << "Paso 5: Crear diccionario de datos."  << endl << endl;
    TDA.construirDiccionario();
    aux = TDA.getPrimeraPos();

    while(aux != TDA.getUltimaPos()->getNext()) {
        cout << aux->getChar() << " -> " << aux->getCodigo() << endl;
        aux = aux->getNext();
    }

    cout << endl << endl;
    system("pause");

    cout << endl << "Paso 6: Traduccion de la cadena original."  << endl << endl;
    string binaria;
    binaria = TDA.traducirCadena(cadena);
    cout << binaria;
    cout << endl << endl;
    system("pause");

    cout << endl << "Paso 7: Empaquetamiento de Datos."  << endl << endl;
    ///Hacer la cadena divisible de 7
    while(binaria.length() % 7 != 0) {
        binaria += '0';
    }

    int i(0);
    char paquetes[binaria.length()];

    strcpy(paquetes, binaria.c_str());

    while(i < binaria.length()) {
        cout << endl;//aqui iba un " | "
        for(int y(i); y < i + 7; y++) {
            cout << paquetes[y];
        }
        i += 7;
    }

    cout << endl << endl;
    system("pause");


    cout << endl << "Paso 8: Traducir cadena final."  << endl << endl;

    int b(0), c(0), d(0), e(0);
    unsigned char u;
    string a, traduccion;
    i = 0;
    while(i < binaria.length()) {
        a = "";
        for(int z(i); z < i + 7; z++) {
            a += paquetes[z];
        }

        b = atoi(a.c_str());
        d = 0;
        e = 0;
        if(b > 0) {
            while(b >= 10) {
                c = 0;
                while(b >= 10) {
                    b = b - 10;
                    c++;
                }
                d = d + b * pow(2,e);
                e++;
                b=c;
            }
            d = d + c * pow(2,e);
        }
        d = d + 32;
        u = d;
        traduccion += u;
        i += 7;
    }
    cout << traduccion;


    ///Guardar datos

    fstream file1("ArchivoEncriptado.txt", ios::app|ios::in|ios::out);
    file1.seekg(0, ios::beg);
    file1 << traduccion;
    file1.close();

    char cFlujo[10];
    char charF;

    fstream file2("DiccionarioDatos.txt", ios::app|ios::in|ios::out);
    file2.seekg(0, ios::beg);
    aux = TDA.getPrimeraPos();

    while(aux != TDA.getUltimaPos()->getNext()) {
        charF = aux->getChar();
        strcpy(cFlujo, aux->getCodigo().c_str());

        file2.write((char*)&cFlujo, 10);

        file2.write((char*)&charF, 1);

        aux = aux->getNext();
    }
    file2.close();

    fstream file3("LongitudOriginal.txt", ios::app|ios::in|ios::out);
    file3.seekg(0, ios::beg);
    file3 << cadena.length();
    file3.close();

    cout << "Texto guardado en fichero aparte" << endl;

    system("pause");
}

void Menu::descomprimir()
{
    TDA_Huffman TDA;
    string myStr, x, comprimida, longitud, a, b;
    char a2[2];
    NodoAL* aux;

    system("cls");

    fstream file1("ArchivoEncriptado.txt", ios::in|ios::out);
    if(!file1.good()) {
        cout << "No puedes descomprimir una archivo ya descomprimido." << endl;
        cout << "Presiona [enter], para continuar." << endl;
        getline(cin, myStr);
        file1.close();
        return;

    }
    file1.seekg(0, ios::beg);
    while(!file1.eof()) {
        file1.read(&a[0], 1);

        if(file1.eof()) {
            break;
        }
        comprimida += a[0];
    }
    file1.close();

    char cFlujo[10];
    char charF;

    fstream file2("DiccionarioDatos.txt", ios::app|ios::in|ios::out);
    file2.seekg(0, ios::beg);
    while(!file2.eof()) {

        file2.read((char*)&cFlujo, 10);
        file2.read((char*)&charF, 1);

        if(file2.eof()) {
            break;
        }

        a = string(cFlujo);

        aux = new NodoAL();
        aux->setChar(charF);
        aux->setCodigo(a);

        TDA.insertarLista(aux);

    }
    file2.close();

    fstream file3("LongitudOriginal.txt", ios::app|ios::in|ios::out);
    file3.seekg(0, ios::beg);
    while(!file3.eof()) {
        getline(file3, x);
        longitud += x;
    }
    file3.close();

    //                remove("Longitud.txt");
    //                remove("Diccionario.txt");
    //                remove("Compresion.txt");

    cout << endl << "Vaceando cadena encriptada..." << endl << endl;
    cout << "Encriptado: " << comprimida << endl << endl;
    cout << "Longitud original: " << longitud << endl << endl;
    cout << "Diccionario de datos: " << endl << endl;

    aux = TDA.getPrimeraPos();

    while(aux != TDA.getUltimaPos()->getNext()) {
        cout << aux->getChar() << "->" << aux->getCodigo() << endl;
        aux = aux->getNext();
    }
    cout << endl << endl;
    system("pause");

    cout << endl << "Convirtiendo a binario el texto encriptado" << endl << endl;
    string binario, finalb, ceros("0000000");
    char comprimidaN[comprimida.length()], b1[8], b2[8];
    int i(0), numero(0), i2(0);
    unsigned char u;

    strcpy(comprimidaN, comprimida.c_str());

    while(i < comprimida.length()) {
        binario = "";
        u = comprimidaN[i];
        numero = int(u);
        numero = numero - 32;
        if (numero > 0) {
            while (numero > 0) {
                if (numero%2 == 0) {
                    binario = "0" + binario;
                }
                else {
                    binario = "1" + binario;
                }
                numero = (int) numero/2;
            }

            strcpy(b1, binario.c_str());

            strcpy(b2, ceros.c_str());

            numero = 7 - binario.length();

            i2 = 0;
            while(i2 < binario.length()) {
                b2[numero] = b1[i2];
                numero++;
                i2++;
            }

        }
        else {
            binario = "0";
            strcpy(b2, ceros.c_str());
        }


        finalb += b2;

        i++;
    }

    cout << endl << finalb << endl;

    cout << endl << endl;
    system("pause");

    cout << endl << "Revirtiendo encriptacion..." << endl << endl;
    string aux1, original;
    char binaria[finalb.length()];
    int j(0);

    strcpy(binaria, finalb.c_str());

    i = 0;
    j = 0;

    numero = atoi(longitud.c_str());

    while(i < numero) {

        aux1 = "";

        while(j < finalb.length()) {

            aux1 += binaria[j];

            aux = TDA.buscarDiccionario(aux1);

            if(aux != nullptr) {
                original += aux->getChar();

                j++;
                break;
            }
            else {
                j++;
            }

        }
        i++;
    }

    cout << endl << original << endl;

    cout << endl << endl;
    system("pause");


    fstream fileo("ProfesoresDesencriptado.txt", ios::app|ios::in|ios::out);
    fileo.seekg(0, ios::beg);
    fileo << original;

    cout << "Texto guardado en fichero aparte" << endl;
}

string Menu::lastcode()
{
    int counter = 0;
    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            counter = stoi(temp);//Obtener id
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);
        }
    }load.close();

    counter++;
    char ident[5];
    sprintf(ident, "%d", counter);
    string id(ident);

    return ident;
}
