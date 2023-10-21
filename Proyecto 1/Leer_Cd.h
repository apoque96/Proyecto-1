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
    std::string>& canciones_ya_guardadas, std::string cd, std::string &errores);

Lista^ Leer_dirrección(std::string dir) {
    //Guarda todos los errores encontrados
    std::string errores = "";
    //Lista de los cds leídos
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
            + " no es de extensión .txt\n";
    }
    //Se repite hasta haber leído todos los archivos .txt
    while (!direcciones.empty()) {
        //Abre el archivo .txt
        std::ifstream cd_abierto;
        cd_abierto.open(direcciones.front());
        std::string cd;
        //Guarda la dirección del archivo
        cd = direcciones.front();
        cd = cd.substr(cd.find_last_of('\\') + 1);
        cd.erase(cd.size() - 4);
        direcciones.pop();
        //Crea una lista con las canciones leídas del archivo .txt
        Lista^ lista_canciones_del_cd = leer_canciones(cd_abierto, canciones_ya_guardadas, cd, errores);
        if (!lista_canciones_del_cd->isEmpty()) {
            //Cli be like
            System::String^ system_cd = gcnew System::String(cd.c_str());
            //Añade la lista del cd a una lista donde están todos los cds
            cds->Add(system_cd, lista_canciones_del_cd);
            continue;
        }
        errores += "Error: " + cd + " está vació\n";
    }
    //Despliega los errores encontrados
    System::String^ msg;
    if (!errores.empty()) {
        msg = gcnew System::String(errores.c_str());
    }
    else msg = gcnew System::String("Archivo abierto exitosamente");
    System::Windows::Forms::MessageBox::Show(msg);
    return cds;
}

Lista^ leer_canciones(std::ifstream& cd_abierto, std::map<std::string,
    std::string>& canciones_ya_guardadas, std::string cd, std::string &errores) {
    //Lista de las canciones leídas
    Lista^ canciones = gcnew Lista(lista_cancion);
    std::string linea = "";
    int index_linea = 0;
    //Lee cada linea del cd y crea un objeto canción para guardarlo en la lista de canciones
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
            //Revisa si la canción leída está repetida
            if (canciones_ya_guardadas[nombre] == artista) {
                errores += "La canción " + nombre + " del artista "
                    + artista + " está repetida\n";
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
            errores += "Error: Formato de linea incorrecta en la linea #" + std::to_string(index_linea) +
                " del cd " + cd + '\n';
        }
    }
    return canciones;
}

#pragma once