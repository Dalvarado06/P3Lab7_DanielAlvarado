/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.h
 * Author: dalva
 *
 * Created on November 27, 2020, 1:19 PM
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Persona {
public:
    
    //default
    Persona();
    
    //sobre cargadao
    Persona(string, string, string);
    
    //copy
    Persona(const Persona& orig);
    
    //destructor
    virtual ~Persona();
    
    //Mutadores
    string getNombre();
    
    string getApellido();
    
    string getPassword();
    
    int getEncrypt();
    
    vector<string> getMensajes();
    
    void setNombre(string);
    
    void setApellido(string);
    
    void setPassword(string);
    
    void setEncrypt(int);
    
    void setMensajes(vector<string>);
    
    void operator=(const Persona& orig);
    
    void addMensaje(string);
    
private:
    
    string nombre;
    string apellido;
    string password;
    int encrypt;
    vector<string> mensajes;
};

#endif /* PERSONA_H */

