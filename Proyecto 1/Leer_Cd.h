#pragma once
#include "Lista.h"
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include <iostream>
#include <queue>
#include <map>

namespace fs = std::filesystem;

Lista^ leer_canciones(std::ifstream& cd_abierto, std::map<std::string, 
    std::string>& canciones_ya_guardadas, std::string cd);

Lista^ Leer_dirrección(std::string dir) {

    Lista^ cds = gcnew Lista(lista_cd);
    std::queue<std::string> direcciones;
    std::map<std::string, std::string> canciones_ya_guardadas;

    for (const auto& entry : fs::directory_iterator(dir)) {
        std::string path_string = entry.path().string();
        if (entry.path().extension() == ".txt") {
            direcciones.push(path_string);
            continue;
        }
        std::cout << "Error: " <<
            path_string.substr(path_string.find_last_of('\\') + 1)
            << " no es de extensión .txt" << std::endl;
    }

    while (!direcciones.empty()) {
        std::ifstream cd_abierto;
        cd_abierto.open(direcciones.front());
        std::string cd;
        cd = direcciones.front();
        cd = cd.substr(cd.find_last_of('\\') + 1);
        direcciones.pop();
        Lista^ lista_canciones_del_cd = leer_canciones(cd_abierto, canciones_ya_guardadas, cd);
        if (!lista_canciones_del_cd->isEmpty()) {
            //Cli be like
            System::String^ system_cd = gcnew System::String(cd.c_str());
            cds->Add(system_cd, lista_canciones_del_cd);
            continue;
        }
        std::cout << "Error: " << cd << " está vació" << std::endl;
    }
    return cds;
}

Lista^ leer_canciones(std::ifstream& cd_abierto, std::map<std::string,
    std::string>& canciones_ya_guardadas, std::string cd) {
    Lista^ canciones = gcnew Lista(lista_cancion);
    std::string linea = "";
    int index_linea = 0;
    while (getline(cd_abierto, linea)) {
        try {
            index_linea++;
            std::string nombre;
            std::string artista;
            int duración_segundos;

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
            duración_segundos = atoi(temp.c_str()) * 60;

            getline(input, temp);
            if (temp.size() > 2 || temp.empty()) throw 0;
            duración_segundos += atoi(temp.c_str());

            linea = "";

            if (canciones_ya_guardadas[nombre] == artista) {
                std::cout << "La canción " << nombre << " del artista "
                    << artista << " está repetida" << std::endl;
                continue;
            }

            //Cli be like
            System::String^ system_nombre = gcnew System::String(nombre.c_str());
            System::String^ system_artista = gcnew System::String(artista.c_str());
            System::String^ system_cd = gcnew System::String(cd.c_str());

            canciones_ya_guardadas[nombre] = artista;

            canciones->Add(system_nombre, system_artista, system_cd, duración_segundos);
        }
        catch (...) {
            std::cout << "Error: Formato de linea incorrecta en la linea #" << index_linea << std::endl;
        }
    }
    return canciones;
}

#pragma once
//System::String^ msg = gcnew System::String(entry.path().extension().c_str());
//System::Windows::Forms::MessageBox::Show(msg);