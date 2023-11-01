#pragma once
#include "Cola.h"
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include <iostream>
#include <queue>
#include <map>

namespace fs = std::filesystem;

Lista^ leer_canciones(std::ifstream& cd_abierto, std::map<std::string, 
    std::string>& canciones_ya_guardadas, std::string cd, std::string &errores);

Lista^ Leer_dirrecci�n(std::string dir) {
    //Guarda todos los errores encontrados
    std::string errores = "";
    //Lista de los cds le�dos
    Lista^ cds = gcnew Lista(lista_cd);
    //Direcciones de los archivos .txt
    std::queue<std::string> direcciones;
    //Hash map utilizado para saber que canciones con el mismo artista se han repetido
    std::map<std::string, std::string> canciones_ya_guardadas;
    //Obtiene todas las direcciones de los archivos .txt del folder y los guarda a la variable "direcciones"
    for (const auto& entry : fs::directory_iterator(dir)) {
        std::string path_string = entry.path().string();
        if (entry.path().extension() == ".txt") {
            direcciones.push(path_string);
            continue;
        }
        errores += "Error: " +
            path_string.substr(path_string.find_last_of('\\') + 1)
            + " no es de extensi�n .txt\n";
    }
    if (direcciones.empty()) {
        System::String^ msg = gcnew System::String("Folder sin ning�n archivo .txt");
        System::Windows::Forms::MessageBox::Show(msg, "Vaci�");
        return nullptr;
    }
    //Se repite hasta haber le�do todos los archivos .txt
    while (!direcciones.empty()) {
        //Abre el archivo .txt
        std::ifstream cd_abierto;
        cd_abierto.open(direcciones.front());
        std::string cd;
        //Guarda la direcci�n del archivo
        cd = direcciones.front();
        cd = cd.substr(cd.find_last_of('\\') + 1);
        cd.erase(cd.size() - 4);
        direcciones.pop();
        //Crea una lista con las canciones le�das del archivo .txt
        Lista^ lista_canciones_del_cd = leer_canciones(cd_abierto, canciones_ya_guardadas, cd, errores);
        if (!lista_canciones_del_cd->isEmpty()) {
            //Cli be like
            System::String^ system_cd = gcnew System::String(cd.c_str());
            //A�ade la lista del cd a una lista donde est�n todos los cds
            cds->Add(system_cd, lista_canciones_del_cd);
            continue;
        }
        errores += "Error: " + cd + " est� vaci�\n";
    }
    //Despliega los errores encontrados
    System::String^ msg;
    if (!errores.empty()) {
        msg = gcnew System::String(errores.c_str());
    }
    else msg = gcnew System::String("Archivo abierto exitosamente");
    System::Windows::Forms::MessageBox::Show(msg, "Lectura del folder");
    return cds;
}

Lista^ leer_canciones(std::ifstream& cd_abierto, std::map<std::string,
    std::string>& canciones_ya_guardadas, std::string cd, std::string &errores) {
    //Lista de las canciones le�das
    Lista^ canciones = gcnew Lista(lista_cancion);
    std::string linea = "";
    int index_linea = 0;
    //Lee cada linea del cd y crea un objeto canci�n para guardarlo en la lista de canciones
    while (getline(cd_abierto, linea)) {
        try {
            index_linea++;
            std::string nombre;
            std::string artista;
            int duraci�n_segundos;

            std::string temp;
            std::stringstream input(linea);

            getline(input, nombre, '|');
            getline(input, temp, '|');
            if (nombre.empty() || nombre.find_first_not_of(' ') == std::string::npos)throw 0;

            getline(input, artista, '|');
            getline(input, temp, '|');
            if (artista.empty() || artista.find_first_not_of(' ') == std::string::npos) throw 0;

            getline(input, temp, ':');
            if (temp.size() > 2 || temp.empty() || temp.find_first_not_of(' ') == std::string::npos) throw 0;
            //Revisa que el formato de la duraci�n est� correcto
            {
                int i;
                std::stringstream ss(temp);
                if ((ss >> i).fail() || !(ss >> std::ws).eof()) throw 2;
            }
            duraci�n_segundos = atoi(temp.c_str()) * 60;

            getline(input, temp);
            if (temp.size() > 2 || temp.empty()) throw 0;
            //Revisa que el formato de la duraci�n est� correcto
            {
                int i;
                std::stringstream ss(temp);
                if ((ss >> i).fail() || !(ss >> std::ws).eof()) throw 2;
            }
            if(atoi(temp.c_str()) >= 60) throw 1;
            duraci�n_segundos += atoi(temp.c_str());

            linea = "";
            //Revisa si la canci�n le�da est� repetida
            if (canciones_ya_guardadas[nombre] == artista) {
                errores += "La canci�n " + nombre + " del artista "
                    + artista + " est� repetida\n";
                continue;
            }

            //Cli be like
            System::String^ system_nombre = gcnew System::String(nombre.c_str());
            System::String^ system_artista = gcnew System::String(artista.c_str());
            System::String^ system_cd = gcnew System::String(cd.c_str());

            canciones_ya_guardadas[nombre] = artista;

            canciones->Add(system_nombre, system_artista, system_cd, duraci�n_segundos);
        }
        catch (int err) {
            switch (err) {
                case 0:
                    errores += "Error: Formato de linea incorrecta en la linea #" + std::to_string(index_linea) +
                        " del cd " + cd + '\n';
                    break;
                case 1:
                    errores += "Error: Formato de la duraci�n incorrecto en la linea #" + std::to_string(index_linea) +
                        " del cd " + cd + " (hay m�s de 59 segundos)\n";
                    break;
                case 2:
                    errores += "Error: Formato de la duraci�n incorrecto en la linea #" + std::to_string(index_linea) +
                        " del cd " + cd + " (solo se acepta el siguiente formato: min:seg)\n";
            }
        }
    }
    return canciones;
}

#pragma once