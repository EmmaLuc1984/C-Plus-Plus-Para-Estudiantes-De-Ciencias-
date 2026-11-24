# Composición

Hasta ahora, hemos visto que dos clases pueden relacionarse de dos maneras: pueden ser independientes o estar vinculadas mediante herencia. Bueno, resulta que hay una tercer manera de relacionarse y es por **composición**. Esta última ocurre cuando los datos miembro de una clase incluyen objetos de otras clases. En otras palabras, un objeto de una clase forma parte de otro objeto.

C++ no requiere una sintaxis especial para establecer esta relación. Simplemente se debe declarar un objeto de otra clase como atributo miembro de la clase que lo contiene. De esta manera, dicho objeto pasa a formar parte de su estructura interna y puede utilizarse mediante las operaciones públicas que ofrece su propia clase. Para que quede mas claro veamos un ejemplo.

## Diseño De La Clase `Entrada`

Vamos a desarrollar un programa de agenda de citas. En este contexto, cada día estará compuesto por una lista ordenada de citas. Para representar cada una de ellas, vamos a dieñar una clase denominada `Entrada`, que contiene dos objetos: uno perteneciente a la clase `Nombre` y otro a la clase `Tiempo`.

Aunque posteriormente podrían incorporarse otros datos relacionados con una cita, creemos que estos dos elementos eran suficientes para establecer una primera versión de la clase.

La construcción resulta sencilla, puesto que ya se dispone de las clases `Nombre` y `Tiempo`, cuyas operaciones pueden aprovecharse directamente. Para este ejemplo, hemos decidido mostrar únicamente el primer nombre y el apellido de la persona, omitiendo el segundo nombre. De igual manera, la representación de la hora únicamente incluirá las horas y los minutos, sin mostrar los segundos.

También vamos a estavblecer dos operaciones que permiten obtener esta información mediante cadenas de caracteres:

- **`nombre_como_cadena()`**: devuelve una cadena formada por el primer nombre y el apellido, separados por un espacio en blanco.
- **`hora_como_cadena()`**: devuelve una cadena que contiene las horas y los minutos, separados por dos puntos.

Por supuesto, es necesario incorporar constructores. Como las clases `Nombre` y `Tiempo` cuentan con constructores por omisión y parametrizados, se definieron dos constructores para `Entrada`. El primero utiliza los constructores por omisión de ambas clases, mientras que el segundo recibe los datos necesarios y los transmite a sus respectivos constructores parametrizados.

### Archivo De Especificación: `Entrada.h`

El siguiente archivo contiene la declaración de la clase `Entrada`, cuyos atributos privados incluyen un objeto de tipo `Nombre` y otro de tipo `Tiempo`.

```cpp
//*****************************************************************
// ARCHIVO DE ESPECIFICACIÓN (Entrada.h)
//
// Este archivo contiene la especificación de la clase Entrada,
// la cual contiene objetos de las clases Nombre y Tiempo.
//*****************************************************************

#ifndef ENTRADA_H
#define ENTRADA_H

#include "Nombre.h"
#include "Tiempo.h"
#include <string>

using namespace std;

class Entrada
{
public:

    string nombre_como_cadena() const;
    // Poscondición:
    // El valor de retorno es una cadena formada por el primer
    // nombre y el apellido del objeto Nombre, separados por
    // un espacio en blanco.

    string hora_como_cadena() const;
    // Poscondición:
    // El valor de retorno es una cadena formada por las horas
    // y los minutos del objeto Tiempo, separados por dos puntos.

    bool es_menor_que(Entrada otra_entrada) const;
    // Poscondición:
    // El valor de retorno es verdadero si la hora de esta
    // entrada es anterior a la de otra_entrada; falso en caso contrario.

    bool es_igual(Entrada otra_entrada) const;
    // Poscondición:
    // El valor de retorno es verdadero si las horas de ambas
    // entradas son iguales; falso en caso contrario.

    Entrada();
    // Constructor por omisión
    // Poscondición:
    // Se ha construido un objeto Entrada.

    Entrada(/* in */ string primer_nombre,
            /* in */ string segundo_nombre,
            /* in */ string apellido,
            /* in */ int horas_iniciales,
            /* in */ int minutos_iniciales,
            /* in */ int segundos_iniciales);
    // Constructor parametrizado
    // Poscondición:
    // Se ha construido un objeto Entrada utilizando los tres
    // primeros argumentos para inicializar el objeto Nombre
    // y los tres últimos para inicializar el objeto Tiempo.

private:

    Nombre nombre_;
    Tiempo tiempo_;

};

#endif
```

## Implementación De La Clase `Entrada`

Las funciones miembro de `Entrada` utilizan las operaciones públicas de las clases `Nombre` y `Tiempo`. Esto permite obtener y comparar sus respectivos valores sin acceder directamente a sus atributos privados.

Para construir los objetos contenidos se emplean los constructores de ambas clases. En el caso del constructor por omisión, estos se invocan automáticamente. Por otro lado, el constructor parametrizado utiliza una lista de inicialización para transmitir los argumentos correspondientes a cada objeto.

Esta lista de inicialización permite establecer los valores de los atributos que pertenecen a otras clases antes de ejecutar el cuerpo del constructor. Por esta razón, el cuerpo de ambos constructores puede permanecer vacío.

### Archivo De Implementación: `Entrada.cpp`

```cpp
//*****************************************************************
// ARCHIVO DE IMPLEMENTACIÓN (Entrada.cpp)
//
// Este archivo contiene las definiciones de las funciones miembro
// de la clase Entrada, que contiene objetos de las clases
// Nombre y Tiempo.
//*****************************************************************

#include "Entrada.h"
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string Entrada::nombre_como_cadena() const
// Devuelve el primer nombre y el apellido.
{
    return nombre_.primer_nombre() + " " + nombre_.apellido();
}

//******************************************************************

string Entrada::hora_como_cadena() const
// Devuelve las horas y los minutos separados por dos puntos.
{
    ostringstream salida;

    salida << setfill('0')
           << setw(2) << tiempo_.horas()
           << ":"
           << setw(2) << tiempo_.minutos();

    return salida.str();
}

//******************************************************************

bool Entrada::es_menor_que(Entrada otra_entrada) const
// Compara la hora de esta entrada con la de otra_entrada.
{
    return tiempo_.es_menor_que(otra_entrada.tiempo_);
}

//******************************************************************

bool Entrada::es_igual(Entrada otra_entrada) const
// Compara la hora de esta entrada con la de otra_entrada.
{
    return tiempo_.es_igual(otra_entrada.tiempo_);
}

//******************************************************************

Entrada::Entrada()
// Constructor por omisión
// Poscondición:
// Se ha construido un objeto Entrada.
    : nombre_(), tiempo_()
{
}

//******************************************************************

Entrada::Entrada(/* in */ string primer_nombre,
                 /* in */ string segundo_nombre,
                 /* in */ string apellido,
                 /* in */ int horas_iniciales,
                 /* in */ int minutos_iniciales,
                 /* in */ int segundos_iniciales)
// Lista de inicialización del constructor
// Constructor parametrizado
// Poscondición:
// El objeto Entrada se ha construido utilizando los tres primeros
// argumentos para inicializar Nombre y los tres últimos para
// inicializar Tiempo.
    : nombre_(primer_nombre, segundo_nombre, apellido),
      tiempo_(horas_iniciales, minutos_iniciales, segundos_iniciales)
{
}
```


