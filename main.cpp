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

/*
 * 
 */
int main(int argc, char** argv) {
    
    vector <Persona> listaPersonas;
    int opcion = 0;
    
    while(opcion != 3){
        
        switch((opcion = mainMenu())){
            
            case 1:{
                
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
            
            }case 2:{
                
                cout << "LOG IN" << endl << endl;
                
                string nombre, password;
                
                cout << "Ingrese su nombre: ";
                cin >> nombre;
                cout << endl;
                
                cout << "Ingrese su password: ";
                cin >> password;
                cout << endl;
                
                bool logIn = false;
                
                int size = listaPersonas.size();
                
                for (int i = 0; i < size; i++){
                    
                    Persona p = listaPersonas[i];
                    string uNombre = "";
                    string uPassword = "";
                    
                    uNombre = p.getNombre();
                    uPassword = p.getPassword();
                    
                    cout << uNombre << " ejemplo " << nombre << endl;
                    
                    if(nombre == uNombre && password == uPassword){
                        cout << "Im in if" << endl;
                        logIn = true;
                    }
                }
                
                
                
                if(logIn){
                    
                    int option = 0;
                    
                    while (option != 4){
                        
                        switch((option = logInMenu())){
                            
                            case 1:{
                                
                                break;
                            
                            }case 2:{
                                
                                break;
                            
                            }case 3:{
                                
                                break;
                            
                            }case 4:{
                                
                                cout << "Regresando al menu principal..." << endl
                                << endl;
                                
                                break;
                            }
                            
                        }
                    }
                    
                    
                    
                    
                }else{
                    
                    cout << "Password y Usuario no se encontraron! " << endl << endl;
                }
                
                
                break;
            
            }case 3:{
                
                cout << "Ha salido del sistema" << endl;
                
                break;
            }
        }
    }
    
    return 0;
}

int mainMenu(){
    
    int opcion = 0;
    
    do{
        
        cout << "------MENU------\n" 
             << "1. Registrarse" << endl
             << "2. Ingresar" << endl
             << "3. Salir" << endl
             << "Ingrese su opcion: ";
        
        cin >> opcion;
        cout << endl;
        
        
    }while(opcion > 3 || opcion < 1);

    return opcion;
}

int logInMenu(){
    
    int option = 0;
    
    do{
        
        cout << "------LOG IN MENU------" << endl
             << "1. Enviar Mensaje" << endl
             << "2. Ver Mensaje" << endl
             << "3. Ver llave de encriptacion" << endl
             << "4. Salir" << endl
             << "Ingrese una opcion: ";
        
        cin >> option;
        
        cout << endl << endl;
                
        
        
    }while(option < 1 || option > 4);
    
    return option;
}