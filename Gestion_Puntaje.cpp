// Gestion_Puntaje.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Usuario {
public:
    string nombre;
    int puntaje;

    Usuario(string nombre, int puntaje) : nombre(nombre), puntaje(puntaje) {}
};

class SistemaUsuarios {
private:
    vector<Usuario> usuarios;

public:
    void agregarUsuario(string nombre, int puntaje) {
        Usuario nuevoUsuario(nombre, puntaje);
        usuarios.push_back(nuevoUsuario);
        cout << "Usuario agregado: " << nombre << " con puntaje " << puntaje << endl;
    }

    void listarUsuarios() {
        if (usuarios.empty()) {
            cout << "No hay usuarios registrados." << endl;
            return;
        }

        cout << "\nLista de usuarios:" << endl;
        for (int i = 0; i < usuarios.size(); i++) {
            cout << i + 1 << ". Nombre: " << usuarios[i].nombre << ", Puntaje: " << usuarios[i].puntaje << endl;
        }
    }

    void actualizarPuntajePorIndice(int indice, int puntos) {
        if (indice >= 0 && indice < usuarios.size()) {
            usuarios[indice].puntaje += puntos;
            cout << "Puntaje actualizado para " << usuarios[indice].nombre << ". Nuevo puntaje: " << usuarios[indice].puntaje << endl;
        }
        else {
            cout << "Índice no válido." << endl;
        }
    }

    void quitarPuntajePorIndice(int indice, int puntos) {
        if (indice >= 0 && indice < usuarios.size()) {
            usuarios[indice].puntaje -= puntos;
            cout << "Puntaje actualizado para " << usuarios[indice].nombre << ". Nuevo puntaje: " << usuarios[indice].puntaje << endl;
        }
        else {
            cout << "Índice no válido." << endl;
        }
    }
};

int main() {
    SistemaUsuarios sistema;
    bool uwu = true;

    while (uwu) {
        cout << "\033[2J\033[1;1H";

        cout << "\nGestión de Usuarios:" << endl;
        cout << "1. Agregar Usuario" << endl;
        cout << "2. Listar Usuarios" << endl;
        cout << "3. Añadir Puntos" << endl;
        cout << "4. Quitar Puntos" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        int opcion;
        cin >> opcion;

        string nombre;
        int puntaje;
        int indice;

        switch (opcion) {
        case 1:
            cout << "Ingrese el nombre del usuario: ";
            cin >> nombre;
            cout << "Ingrese el puntaje del usuario: ";
            cin >> puntaje;
            sistema.agregarUsuario(nombre, puntaje);
            break;

        case 2:
            sistema.listarUsuarios();
            break;

        case 3:
            cout << "Ingrese el índice del usuario para añadir puntos: ";
            cin >> indice;
            cout << "Ingrese la cantidad de puntos a añadir: ";
            cin >> puntaje;
            sistema.actualizarPuntajePorIndice(indice - 1, puntaje);
            break;

        case 4:
            cout << "Ingrese el índice del usuario para quitar puntos: ";
            cin >> indice;
            cout << "Ingrese la cantidad de puntos a quitar: ";
            cin >> puntaje;
            sistema.quitarPuntajePorIndice(indice - 1, puntaje);
            break;

        case 5:
            uwu = false;
            cout << "Saliendo del sistema..." << endl;
            break;

        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }

        cout << "\nPresione cualquier tecla para continuar...";
        cin.ignore();
        cin.get();
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
