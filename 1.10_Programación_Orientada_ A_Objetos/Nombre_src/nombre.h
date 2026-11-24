//*****************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Nombre.h)
//
// Este archivo contiene la especificación del tipo de dato
// abstracto Nombre. Se proporcionan dos constructores: uno recibe
// el primer nombre, el segundo nombre y el apellido como argumentos,
// mientras que el otro inicializa los tres componentes sin contenido.
//*****************************************************************

#ifndef NOMBRE_H
#define NOMBRE_H

#include <iostream>
#include <string>

using namespace std;

enum TipoRelacion { ANTES, IGUAL, DESPUES };

class Nombre
{
public:

    Nombre();
    // Constructor por omisión
    // Poscondición:
    // El primer nombre, el segundo nombre y el apellido
    // se inicializan como cadenas vacías.

    Nombre(/* in */ string primer_nombre,
           /* in */ string segundo_nombre,
           /* in */ string apellido);
    // Constructor parametrizado
    // Poscondición:
    // El objeto se inicializa con el primer nombre, el segundo
    // nombre y el apellido proporcionados como argumentos.

    void establecer(/* in */ string primer_nombre,
                    /* in */ string segundo_nombre,
                    /* in */ string apellido);
    // Poscondición:
    // El primer nombre, el segundo nombre y el apellido
    // del objeto se establecen con los valores proporcionados.

    void leer_nombre();
    // Poscondición:
    // Se solicitan y se leen el primer nombre, el segundo nombre
    // y el apellido desde el dispositivo de entrada estándar.

    string primer_nombre() const;
    // Poscondición:
    // El valor de retorno es el primer nombre de la persona.

    string apellido() const;
    // Poscondición:
    // El valor de retorno es el apellido de la persona.

    string segundo_nombre() const;
    // Poscondición:
    // El valor de retorno es el segundo nombre de la persona.

    char inicial_segundo_nombre() const;
    // Poscondición:
    // El valor de retorno es la inicial del segundo nombre
    // de la persona.

    TipoRelacion comparado_con(/* in */ Nombre otro_nombre) const;
    // Poscondición:
    // El valor de retorno indica la relación entre este nombre
    // y otro_nombre:
    // ANTES, si este nombre va antes que otro_nombre.
    // IGUAL, si ambos nombres son iguales.
    // DESPUES, si este nombre va después que otro_nombre.

private:

    string primer_nombre_;  // Primer nombre de la persona.
    string apellido_;       // Apellido de la persona.
    string segundo_nombre_; // Segundo nombre de la persona.

};

#endif