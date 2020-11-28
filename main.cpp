/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dalva
 *
 * Created on November 27, 2020, 1:01 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "Persona.h"

using namespace std;

//prototypes

int mainMenu();
int logInMenu();
string encryptar(string, int, string);
string decypher(string, int, string);

/*
 * 
 */
int main(int argc, char** argv) {

    vector <Persona> listaPersonas;
    int opcion = 0;

    while (opcion != 3) {

        switch ((opcion = mainMenu())) {

            case 1:
            {

                cout << "Registro a Mensajeria" << endl << endl;

                string nombre, apellido, password;

                cout << "Ingrese su nombre: ";
                cin >> nombre;
                cout << endl;

                cout << "Ingrese su apellido: ";
                cin >> apellido;
                cout << endl;

                cout << "Ingrese su nuevo password: ";
                cin >> password;
                cout << endl << endl;

                Persona nPersona(nombre, apellido, password);

                cout << "Sus datos son: " << endl
                        << "Nombre: " << nPersona.getNombre() << endl
                        << "Apellido: " << nPersona.getApellido() << endl
                        << "Password: " << nPersona.getPassword()
                        << endl << endl;

                listaPersonas.push_back(nPersona);

                cout << "Bienvenido " << nPersona.getNombre() << endl << endl;


                break;

            }
            case 2:
            {

                cout << "LOG IN" << endl << endl;

                string nombre, password;


                cout << "Ingrese su nombre: ";
                cin >> nombre;
                cout << endl;

                cout << "Ingrese su password: ";
                cin >> password;
                cout << endl;

                bool logIn = false;

                string name, surename, pass;
                int cypher = 0;
                vector<string> textos;

                int size = listaPersonas.size();

                for (int i = 0; i < size; i++) {

                    Persona p = listaPersonas[i];
                    string uNombre = "";
                    string uPassword = "";

                    uNombre = p.getNombre();
                    uPassword = p.getPassword();

                    //cout << uNombre << " ejemplo " << nombre << endl;

                    if (nombre == uNombre && password == uPassword) {
                        
                        logIn = true;

                        name = p.getNombre();
                        surename = p.getApellido();
                        pass = p.getPassword();
                        cypher = p.getEncrypt();

                        for (int i = 0; i < p.getMensajes().size(); i++) {
                            string message = p.getMensajes().at(i);

                            textos.push_back(message);

                        }
                    }
                }


                Persona logedIn(name, surename, pass);

                logedIn.setMensajes(textos);

                logedIn.setEncrypt(cypher);

                if (logIn) {

                    int option = 0;

                    while (option != 4) {

                        switch ((option = logInMenu())) {

                            case 1:
                            {

                                cout << "Enviar un mensaje" << endl;

                                if (listaPersonas.empty()) {
                                    cout << "No hay miembros en la lista!" << endl
                                            << endl;
                                } else {

                                    cout << "Estos son los usuarios disponibles: "
                                            << endl << endl;

                                    int size = listaPersonas.size();

                                    for (int i = 0; i < size; i++) {

                                        cout << i << ". " <<listaPersonas[i].getNombre()
                                                << " " << listaPersonas[i].getApellido();

                                        cout << endl << endl;
                                    }

                                    int indice = -1;

                                    cout << "Elija el indice de destinatario: ";
                                    cin >> indice;
                                    cout << endl;

                                    while (indice < 0 || indice >= size) {
                                        cout << "Ingrese un indice correcto: ";
                                        cin >> indice;
                                        cout << endl;
                                    }

                                    string texto = "";
                                    string mensaje = "";

                                    mensaje += "De " + logedIn.getNombre() + ": ";

                                    cout << "Ingrese el texto del mensaje: ";
                                    cin >> texto;
                                    cout << endl;


                                    int cypher = listaPersonas[indice].getEncrypt();
                                    
                                  
                                    
                                    texto = encryptar(texto, cypher, "");

                                    mensaje += texto;

                                    listaPersonas[indice].addMensaje(mensaje);


                                    cout << "El mensaje ha sido enviado exitosamente"
                                            << endl << endl;
                                }


                                break;

                            }
                            case 2:
                            {
                                cout << "Ver mensajes" << endl << endl;

                                if (logedIn.getMensajes().empty()) {
                                    cout << "La lista de mensajes esta vacia!"
                                            << endl << endl;
                                } else {
                                    int size = logedIn.getMensajes().size();

                                    for (int i = 0; i < size; i++) {

                                        cout <<  i << ". " <<logedIn.getMensajes().at(i);
                                        cout << endl << endl;
                                    }

                                    int index = -1;

                                    cout << "Elija el mensaje a descifrar: ";
                                    cin >> index;
                                    cout << endl;

                                    while (index < 0 || index >= size) {
                                        cout << "Ingrese un indice correcto: ";
                                        cin >> index;
                                        cout << endl;
                                    }

                                    string mensaje, texto;
                                    
                                    texto = logedIn.getMensajes().at(index);

                                    
                                    int indice = texto.find(":");
                                    
                                    if(indice != -1){
                                        
                                        mensaje = texto.substr(0, indice+2);
                                        texto = texto.substr(indice+2);
                                    }
                                    
                                    cout << mensaje << endl;
                                    cout << texto << endl;
                                    
                                    int rotaciones = logedIn.getEncrypt();
                                    string message = "";
                                    
                                    message = decypher(texto, rotaciones, "");

                                    cout << "El texto es: " << message << " "
                                            << texto << endl << endl;

                                }

                                break;

                            }
                            case 3:
                            {
                                cout << "Ver clave de Cypher" << endl;

                                int confirm = 0;
                                cout << "Desea mostrar su clave? (1== si): ";
                                cin >> confirm;
                                cout << endl;

                                if (confirm == 1) {

                                    cout << "Su clave de cifrado es: "
                                            << logedIn.getEncrypt()
                                            << endl << endl;
                                }

                                break;

                            }
                            case 4:
                            {

                                cout << "Regresando al menu principal..." << endl
                                        << endl;

                                break;
                            }

                        }
                    }




                } else {

                    cout << "Password y Usuario no se encontraron! " << endl << endl;
                }


                break;

            }
            case 3:
            {

                cout << "Ha salido del sistema" << endl;

                break;
            }
        }
    }

    return 0;
}

int mainMenu() {

    int opcion = 0;

    do {

        cout << "------MENU------\n"
                << "1. Registrarse" << endl
                << "2. Ingresar" << endl
                << "3. Salir" << endl
                << "Ingrese su opcion: ";

        cin >> opcion;
        cout << endl;


    } while (opcion > 3 || opcion < 1);

    return opcion;
}

int logInMenu() {

    int option = 0;

    do {

        cout << "------LOG IN MENU------" << endl
                << "1. Enviar Mensaje" << endl
                << "2. Ver Mensaje" << endl
                << "3. Ver llave de encriptacion" << endl
                << "4. Salir" << endl
                << "Ingrese una opcion: ";

        cin >> option;

        cout << endl << endl;



    } while (option < 1 || option > 4);

    return option;
}

string encryptar(string texto, int rotaciones, string result) {

    //caso base
    if (rotaciones == 0) {
        //asignar el valor de texto al result
        result = texto;

        //devuelve el resultado
        return result;

    } else {

        //variables
        vector <string> parsedText;
        vector <string> cypherText;
        string parsed = "";
        int contador = 0;

        //separacion por rotaciones
        for (int i = 0; i < texto.length(); i++) {

            parsed += texto[i];

            if (contador == rotaciones - 1) {

                parsedText.push_back(parsed);

                parsed = "";
                contador = 0;
            } else if (i == texto.length() - 1) {

                parsedText.push_back(parsed);\

                parsed = "";
                contador = 0;

            } else {
                contador++;
            }


        }


        //ciclo de cifrado cesar
        int size = parsedText.size();

        //recorre el vector con los textos separados
        for (int i = 0; i < size; i++) {

            string toCypher = parsedText.at(i);

            if (i == 0 || i % 2 == 0) {

                //front cesar
                string resultCypher = "";
                for (int j = 0; j < toCypher.length(); j++) {
                    char number = toCypher[j];

                    number += rotaciones;

                    resultCypher += number;
                }

                cypherText.push_back(resultCypher);


            } else {
                //back cesar
                string resultCypher = "";
                for (int j = 0; j < toCypher.length(); j++) {
                    char number = toCypher[j];

                    number -= rotaciones;

                    resultCypher += number;
                }

                cypherText.push_back(resultCypher);
            }
        }

        texto = "";

        //asignacion de las partes del texto a la cadena original
        int length = cypherText.size();

        for (int i = 0; i < length; i++) {

            texto += cypherText[i];
        }


        //llamado al metodo recursivo
        return result = encryptar(texto, rotaciones - 1, result);
    }
}

string decypher(string texto, int rotaciones, string result) {
    //caso base
    if (rotaciones == 0) {
        result = texto;

        return result;

    } else {

        //variables
        vector <string> parsedText;
        vector <string> cypherText;
        string parsed = "";
        int contador = 0;

        //separacion por rotaciones
        for (int i = 0; i < texto.length(); i++) {

            parsed += texto[i];

            if (contador == rotaciones - 1) {

                parsedText.push_back(parsed);\

                parsed = "";
                contador = 0;
            } else if (i == texto.length() - 1) {

                parsedText.push_back(parsed);\

                parsed = "";
                contador = 0;
            } else {
                contador++;
            }


        }

        //ciclo de cifrado cesar
        int size = parsedText.size();

        //recorre el vector con los textos separados
        for (int i = 0; i < size; i++) {

            string toCypher = parsedText.at(i);

            if (i != 0 || (i % 2) != 0) {

                //front cesar
                string resultCypher = "";
                for (int j = 0; j < toCypher.length(); j++) {
                    char number = toCypher[j];

                    number += rotaciones;

                    resultCypher += number;
                }

                cypherText.push_back(resultCypher);


            } else {
                //back cesar
                string resultCypher = "";
                for (int j = 0; j < toCypher.length(); j++) {
                    char number = toCypher[j];

                    number -= rotaciones;

                    resultCypher += number;
                }

                cypherText.push_back(resultCypher);
            }
        }

        texto = "";

        //asignacion de las partes del texto a la cadena original
        int length = cypherText.size();

        for (int i = 0; i < length; i++) {

            texto += cypherText[i];
        }

        //llamado al metodo recursivo
        return result = encryptar(texto, rotaciones - 1, result);
    }



}