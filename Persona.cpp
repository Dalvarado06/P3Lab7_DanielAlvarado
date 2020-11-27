/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.cpp
 * Author: dalva
 * 
 * Created on November 27, 2020, 1:19 PM
 */

#include "Persona.h"
#include <ctime>

//default

Persona::Persona() {
}


//copia

Persona::Persona(const Persona& orig) {

    this->nombre = orig.nombre;
    this->apellido = orig.apellido;
    this->encrypt = orig.encrypt;
    this->password = orig.password;

    int size = orig.mensajes.size();

    for (int i = 0; i < size; i++) {

        string mensaje = orig.mensajes.at(i);

        this->mensajes.push_back(mensaje);
    }

}

Persona::Persona(string nombre, string apellido, string password) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->password = password;

    srand(time(0));

    this->encrypt = 1+(rand() % 15);

}

//destructor

Persona::~Persona() {
}

void Persona::setApellido(string apellido) {
    this->apellido = apellido;
}

void Persona::setNombre(string nombre) {
    this->nombre = nombre;
}

void Persona::setPassword(string password) {
    this->password = password;
}

string Persona::getNombre() {
    return nombre;
}

string Persona::getApellido() {
    return apellido;
}

string Persona::getPassword() {
    return password;
}

int Persona::getEncrypt() {
    return encrypt;
}

void Persona::operator=(const Persona& orig) {
    this->nombre = orig.nombre;
    this->apellido = orig.apellido;
    this->encrypt = orig.encrypt;
    this->password = orig.password;

    int size = orig.mensajes.size();

    for (int i = 0; i < size; i++) {

        string mensaje = orig.mensajes.at(i);

        this->mensajes.push_back(mensaje);
    }

}