#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;
//variables constantes, para poner un limite de registros
 int maximo = 5000;
const int minimo = 100;

//variables globales, para saber quien se conecto y enque sucursal
string sucursal = "";
string sesion   = "";
/*Agrego el algoritmo de usuarios*/
#include "usuario.h" 
void iniciar();
/*Agrego el algorimo de peliculas*/
#include "peliculas.h" 
int opcion;
int main(){
    iniciar();
    return 0;
}

 

void iniciar(){
    LeerPeliculas();
    LeerUsuarios();
    InicioSesion();


    do
    {

        // Menu principal
        cout << "Usuario Conectado: " << sesion << endl <<" Sucursal: "<< sucursal << endl;
        cout << "Menu Principal:" << endl;
        cout << "1.-  Agregar Pelicula" << endl;
        cout << "2.-  Editar Pelicula" << endl;

        cout << "3.-  Mostrar todas las peliculas" << endl;
        cout << "4.-  Mostrar peliculas segun anio de produccion" << endl;
        cout << "5.-  Mostrar peliculas de estreno" << endl;
        cout << "6.-  Crear boleto" << endl;
        cout << "7.- Ver boletos" << endl;
        cout << "8.-  Agregar usuario" << endl;
        cout << "9.-  Mostrar usuarios" << endl;
        cout << "10.- Cambiar contrasenia usuario" << endl;
        cout << "11.- Salir" << endl;

        cin >> opcion;
        cin.sync();
        system("cls");

        // Hacemos una cosa u otra seg�n la opci�n escogida
        switch(opcion){
            case 1: //a�adir una pelicula
                //funcion();
                break;

            case 2://mostrar todas las peliculas
                //funcion();
                break;

            case 3: //editar pelicula
                //funcion();
                break;

            case 4:
                //funcion();
                break;

            case 5:
                //
                break;

            case 6:
                //funcion();
                break;

            case 7:
                //funcion();
                break;

            case 8:
                AgregarUsuarios();
                break;
            case 9:
                VerUsuarios();
                break;
            case 10:
                ModificarUsuarios();;
                break;
            case 11:
                cout << "Fin del programa" << endl;
                break;

            default:
                cout << "Opcion desconocida!" << endl;
                system("pause");
                system("cls");
                break;
        }
    } while (opcion != 11);  // Si la opcion es 5, terminamos
}
