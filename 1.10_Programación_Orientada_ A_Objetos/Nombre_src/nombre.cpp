//*****************************************************************
// ARCHIVO DE IMPLEMENTACIÓN (Nombre.cpp)
//
// Este archivo contiene las definiciones de las funciones miembro
// de la clase Nombre.
//*****************************************************************

#include "Nombre.h"
#include <iostream>

using namespace std;

//******************************************************************
Nombre::Nombre()
// Constructor por omisión
// Poscondición:
// El primer nombre, el segundo nombre y el apellido
// se inicializan como cadenas vacías.
{
    primer_nombre_ = "";
    segundo_nombre_ = "";
    apellido_ = "";
}

//******************************************************************
Nombre::Nombre(/* in */ string primer_nombre,   // Primer nombre
               /* in */ string segundo_nombre,  // Segundo nombre
               /* in */ string apellido)        // Apellido
// Constructor parametrizado
// Poscondición:
// El primer nombre se almacena en primer_nombre_,
// el segundo nombre en segundo_nombre_ y el apellido en apellido_.
{
    primer_nombre_ = primer_nombre;
    segundo_nombre_ = segundo_nombre;
    apellido_ = apellido;
}

//******************************************************************
void Nombre::establecer(/* in */ string primer_nombre,
                        /* in */ string segundo_nombre,
                        /* in */ string apellido)
// Poscondición:
// El primer nombre, el segundo nombre y el apellido
// del objeto se establecen con los valores proporcionados.
{
    primer_nombre_ = primer_nombre;
    segundo_nombre_ = segundo_nombre;
    apellido_ = apellido;
}

//******************************************************************
void Nombre::leer_nombre()
// Poscondición:
// Se solicitan y se leen los tres componentes del nombre
// desde el dispositivo de entrada estándar.
{
    cout << "Introduzca el primer nombre: ";
    cin >> primer_nombre_;

    cout << "Introduzca el segundo nombre: ";
    cin >> segundo_nombre_;

    cout << "Introduzca el apellido: ";
    cin >> apellido_;
}

//******************************************************************
string Nombre::primer_nombre() const
// Poscondición:
// El valor de retorno es el primer nombre de la persona.
{
    return primer_nombre_;
}

//******************************************************************
string Nombre::apellido() const
// Poscondición:
// El valor de retorno es el apellido de la persona.
{
    return apellido_;
}

//******************************************************************
string Nombre::segundo_nombre() const
// Poscondición:
// El valor de retorno es el segundo nombre de la persona.
{
    return segundo_nombre_;
}

//******************************************************************
char Nombre::inicial_segundo_nombre() const
// Poscondición:
// El valor de retorno es la inicial del segundo nombre.
{
    if (segundo_nombre_.empty())
        return '\0';

    return segundo_nombre_[0];
}

//******************************************************************
TipoRelacion Nombre::comparado_con(/* in */ Nombre otro_nombre) const
// Precondición:
// El parámetro de entrada contiene un nombre válido.
//
// Poscondición:
// El valor de retorno indica la relación entre ambos nombres:
// ANTES, si este nombre va antes que otro_nombre.
// IGUAL, si ambos nombres son iguales.
// DESPUES, si este nombre va después que otro_nombre.
{
    if (apellido_ < otro_nombre.apellido_)
        return ANTES;

    else if (otro_nombre.apellido_ < apellido_)
        return DESPUES;

    else if (primer_nombre_ < otro_nombre.primer_nombre_)
        return ANTES;

    else if (otro_nombre.primer_nombre_ < primer_nombre_)
        return DESPUES;

    else if (segundo_nombre_ < otro_nombre.segundo_nombre_)
        return ANTES;

    else if (otro_nombre.segundo_nombre_ < segundo_nombre_)
        return DESPUES;

    else
        return IGUAL;
}