// Gestion_Usuarios.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Usuario {
public:
    string nombre;
    int puntos;

    Usuario(string nombre, int puntos) {
        this->nombre = nombre;
        this->puntos = puntos;
    }
};

class GestionUsuarios {
private:
    vector<Usuario> usuarios;

public:
    void agregarUsuario(string nombre, int puntos) {
        Usuario nuevoUsuario(nombre, puntos);
        usuarios.push_back(nuevoUsuario);
        cout << "Usuario agregado: " << nombre << " con puntos " << puntos << endl;
    }

    void listarUsuarios() {
        if (usuarios.empty()) {
            cout << "No hay usuarios registrados." << endl;
            return;
        }

        cout << "\nLista de usuarios:" << endl;
        for (int i = 0; i < usuarios.size(); i++) {
            cout << i + 1 << ". Nombre: " << usuarios[i].nombre << ", Puntos: " << usuarios[i].puntos << endl;
        }
    }

    void modificarPuntos(int indice, int puntos) {
        if (indice >= 0 && indice < usuarios.size()) {
            usuarios[indice].puntos += puntos;
            cout << "Puntos actualizados para " << usuarios[indice].nombre << ". Nuevos puntos: " << usuarios[indice].puntos << endl;
        }
        else {
            cout << "Índice no válido." << endl;
        }
    }

    void eliminarUsuario(int indice) {
        if (indice >= 0 && indice < usuarios.size()) {
            cout << "Usuario eliminado: " << usuarios[indice].nombre << endl;
            usuarios.erase(usuarios.begin() + indice);
        }
        else {
            cout << "Índice no válido." << endl;
        }
    }
};

int main() {
    GestionUsuarios gestion;
    bool continuar = true;

    while (continuar) {
        // Limpiar la pantalla (esto funciona en la mayoría de los sistemas UNIX y Windows).
        cout << "\033[2J\033[1;1H";

        cout << "\nGestión de Usuarios del Videojuego:" << endl;
        cout << "1. Agregar Usuario" << endl;
        cout << "2. Listar Usuarios" << endl;
        cout << "3. Modificar Puntos" << endl;
        cout << "4. Eliminar Usuario" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        int opcion;
        cin >> opcion;

        string nombre;
        int puntos;
        int indice;

        switch (opcion) {
        case 1:
            cout << "Ingrese el nombre del usuario: ";
            cin >> nombre;
            cout << "Ingrese los puntos del usuario: ";
            cin >> puntos;
            gestion.agregarUsuario(nombre, puntos);
            break;

        case 2:
            gestion.listarUsuarios();
            break;

        case 3:
            cout << "Ingrese el índice del usuario para modificar puntos: ";
            cin >> indice;
            cout << "Ingrese la cantidad de puntos a modificar (use negativo para restar): ";
            cin >> puntos;
            gestion.modificarPuntos(indice - 1, puntos);
            break;

        case 4:
            cout << "Ingrese el índice del usuario a eliminar: ";
            cin >> indice;
            gestion.eliminarUsuario(indice - 1);
            break;

        case 5:
            continuar = false;
            cout << "Saliendo del sistema..." << endl;
            break;

        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }

        cout << "\nPresione Enter para continuar...";
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
