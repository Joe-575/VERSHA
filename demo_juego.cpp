#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>
#include <cstdlib>
#include "colors.hpp"
#include <limits>
#include "funciones.cpp"
#include <cstdlib>
#include <fstream>



using namespace std;

//----------------------------------------------------------------------------------------------
struct player {
    string nombre_jugador = "Versha";
    int score = 0;
    int id_player = 0;
    int vidas = 2;
};

struct questions {
    string preguntas;
    string opciones[4];
    string opcion_correcta = "a";
};

player *jugadores = new player[25];
questions *preguntas_juego = new questions[15];

void Registro_datos(int id) {
    cout << "Ingreso del apodo del jugador " << id + 1 << ": ";
    cin >> jugadores[id].nombre_jugador;
    jugadores[id].id_player = id;
}

void juego(int id_player) {
}

void insercion_datos(int casos, int id_) {
    switch (casos) {
        case 1: {
            ifstream preguntas("banco.txt");
            for (int i = 0; i < 15; i++) {
                getline(preguntas, preguntas_juego[i].preguntas);
                for (int j = 0; j < 4; j++) {
                    getline(preguntas, preguntas_juego[i].opciones[j]);
                }
            }
            preguntas.close();
            break;
        }
        case 2: {
            ifstream opcionc("opciones.txt");
            for (int i = 0; i < 15; i++) {
                getline(opcionc, preguntas_juego[i].opcion_correcta);
            }
            opcionc.close();
        }
        case 3: {
            ofstream puntuaciones_G("tabla_Pos.txt");
            puntuaciones_G << "Jugador: " << jugadores[id_].nombre_jugador << "  Puntuacion: " << jugadores[id_].score;
        }
    }
}

/*
void partida(int id_p) {
    int i = 0;
    string opcion;
    while (jugadores[id_p].vidas > 0 || i == 15) {
        cout << "Puntuacion: " << jugadores[id_p].score << "               " << "Vidas: " << jugadores[id_p].vidas <<
                endl;
        cout << preguntas_juego[i].preguntas << endl;
        for (int j = 0; j < 4; j++) {
            cout << preguntas_juego[i].opciones[j] << endl;
        }
        cout << "\nEscoga la opcion correcta";
        cin >> opcion;
        if (opcion == preguntas_juego[i].opcion_correcta) {
            jugadores[id_p].score = jugadores[id_p].score + 1000;
        } else {
            jugadores[id_p].vidas = jugadores[id_p].vidas - 1;
        }
        cout << "La opcion correcta...";
        cout << preguntas_juego[i].opcion_correcta << endl;
        i = i + 1;
    }
}
int comodines(int tipo,int pregunta,int id_) {
    int opcion_random;
    string opcion;
    string opcion_co=preguntas_juego[pregunta].opcion_correcta;
    switch (tipo) {
        case 1: {//Llamada al publico
            cout<<"LLamando a un experto ..."<<endl;
            cout<<"Yo creo que es .."<<preguntas_juego[pregunta].opcion_correcta;
        }
        case 2: {
            //Graficos en ascii con casos
            switch (opcion_co) {
                case "a": {

                }
                case "b": {

                }
                case "c": {

                }
                case "d": {

                }
            }
        }
        case 3: {//50 50
            cout << preguntas_juego[pregunta].preguntas << endl;
            switch (preguntas_juego[pregunta].opcion_correcta) {
                case 'a': {
                    cout << preguntas_juego[pregunta].opciones[0] << endl;
                    do{opcion_random=rand()%4;}while (opcion_random==0);
                    cout << preguntas_juego[pregunta].opciones[opcion_random] << endl;
                    break;
                }
                case 'b': {
                    do{opcion_random=rand()%4;}while (opcion_random==1);
                    cout << preguntas_juego[pregunta].opciones[1] << endl;
                    break;
                }
                case 'c': {
                    do{opcion_random=rand()%4;}while (opcion_random==2);
                    cout << preguntas_juego[pregunta].opciones[2] << endl;
                    break;
                }
                case 'd': {
                    do{opcion_random=rand()%4;}while (opcion_random==3);
                    cout << preguntas_juego[pregunta].opciones[3] << endl;
                    break;
                }
            }
            cout << "\nEscoga la opcion correcta";
            cin >> opcion;
            if (opcion == preguntas_juego[pregunta].opcion_correcta) {
                jugadores[id_].score = jugadores[id_].score + 1000;
            } else {
                jugadores[id_].vidas = jugadores[id_].vidas - 1;
            }
            cout << "La opcion correcta...";
            cout << preguntas_juego[pregunta].opcion_correcta << endl;
            return pregunta+1;
        }
    }
}
*/

void menu() {
    char option;
    int id = 0;
    //poner acento a la palabra
    char wordo = 162;
    char worde = 130;
    char worda = 160;
    //char wordu = 163;

     // Códigos de escape ANSI para colores
    const string RESET = "\033[0m";
    const string LINE_COLOR = "\033[0;31m"; // Rojo
    const string LINE_COLOR1 = "\033[0;33m"; // Amarillo

    do{
        system("cls");
        LogoMenu();
        cout<<"\t\t\t------------------------------------------------------------------ "<<endl;
        cout<<"\t\t\t|               1.- Nueva partida                                | "<<endl;
        cout<<"\t\t\t|               2.- Cr"<<worde<<"ditos                                     | "<<endl;
        cout<<"\t\t\t|               3.- Puntajes                                     | "<<endl;
        cout<<"\t\t\t|               4.- Salir                                        | "<<endl;
        cout<<"\t\t\t------------------------------------------------------------------ "<<endl;
        cout<<"\t\t\t------------------------------------------------------------------ "<<endl;
        cout<<"\t\t\t Ingrese opci"<<wordo<<"n: ";
        cout<<LINE_COLOR1;
        cin>>option;
        cout<<RESET;

        switch (option) {
            case '1': {
                InicarJuego();
                //Registro_datos(id);
                //partida(id);
                id = +0;
                break;
            }
            case '2': {
                system("cls");
                MostrarCreditos();
                break;
            }
            case '3': {
                system("cls");
                MostrarPuntaje();
                break;
            }
            case '4': {
                system("cls");
                SalirJuego();
                break;
            }
            default: {
                cout<<"\n";
                cout<<LINE_COLOR;
                cout<<"\t\t\t Opci"<<wordo<<"n no v"<<worda<<"lida..."<<endl;
                cout<<RESET;
                cout<<" "<<endl;
                system("pause");
                break;
            }
        }
    } while (option != 4);
}

int main() {
    LogoPrincipal();
    insercion_datos(1,0);
    menu();
    return 0;
}
