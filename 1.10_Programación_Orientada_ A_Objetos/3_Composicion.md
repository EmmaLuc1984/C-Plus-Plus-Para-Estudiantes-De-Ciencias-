# Composición

Hasta ahora, hemos visto que dos clases pueden relacionarse de dos maneras: pueden ser independientes o estar vinculadas mediante herencia. Bueno, resulta que hay una tercer manera de relacionarse y es por **composición**. Esta última ocurre cuando los datos miembro de una clase incluyen objetos de otras clases. En otras palabras, un objeto de una clase forma parte de otro objeto.

C++ no requiere una sintaxis especial para establecer esta relación; basta con declarar un objeto de otra clase como miembro. Veamos un ejemplo.

## Diseño De La Clase `Entrada`

Supongamos que estamos desarrollando un programa para administrar una agenda de citas. Cada día estará representado por una lista ordenada de citas. Para ello, podemos crear un tipo de dato abstracto llamado `Entrada`, que contenga dos objetos: uno de tipo `Nombre` y otro de tipo `Tiempo`.

Aunque más adelante podríamos incorporar otros datos, estos dos elementos son suficientes para comenzar. Además, su implementación resulta sencilla porque ya contamos con la clase `Tiempo` y podemos definir una clase `Nombre` para representar los datos personales.

Para este ejemplo, se decide utilizar únicamente el primer nombre y el apellido de una persona, así como las horas y los minutos de una cita, sin considerar el segundo nombre ni los segundos al momento de mostrar la información. También necesitamos operaciones que permitan obtener el nombre y la hora desde el programa cliente.

La clase `Entrada` ofrecerá dos funciones para este propósito:

- `obtener_nombre()`: devuelve una cadena formada por el primer nombre y el apellido, separados por un espacio.
- `obtener_hora()`: devuelve una cadena con las horas y los minutos, separados por dos puntos.

También necesitamos definir sus constructores. La clase `Nombre` contará con un constructor por omisión, que solicitará los datos mediante la entrada estándar, y otro parametrizado, que recibirá los componentes del nombre como argumentos. La clase `Tiempo` dispone de sus propios constructores.

Por consiguiente, `Entrada` también tendrá un constructor por omisión, que utilizará los constructores por omisión de `Nombre` y `Tiempo`, y otro parametrizado, que transmitirá los argumentos correspondientes a los constructores de ambas clases.

### Especificación De La Clase `Nombre`

Antes de definir `Entrada`, necesitamos disponer de la clase `Nombre`. Esta se encargará de almacenar el primer nombre, el segundo nombre y el apellido de una persona.

Su archivo de especificación, `nombre.h`, queda definido de la siguiente manera:

```cpp
//***************************************************************************
// ARCHIVO DE ESPECIFICACIÓN: nombre.h
// Este archivo contiene la declaración de la clase Nombre.
//***************************************************************************

#ifndef NOMBRE_H
#define NOMBRE_H

#include <string>

using namespace std;

class Nombre
{
public:
    Nombre();

    // Constructor por omisión.
    // Solicita y lee los componentes del nombre
    // desde la entrada estándar.

    Nombre(
        const string& primer_nombre_inicial,
        const string& segundo_nombre_inicial,
        const string& apellido_inicial);

    // Constructor parametrizado.
    // Inicializa los datos del objeto con los argumentos recibidos.

    string obtener_primer_nombre() const;

    // Devuelve el primer nombre.

    string obtener_segundo_nombre() const;

    // Devuelve el segundo nombre.

    string obtener_apellido() const;

    // Devuelve el apellido.

private:
    string primer_nombre;
    string segundo_nombre;
    string apellido;
};

#endif // NOMBRE_H
```

### Implementación De La Clase `Nombre`

El archivo de implementación `nombre.cpp` contiene las definiciones de los constructores y de las funciones miembro declaradas anteriormente:

```cpp
//***************************************************************************
// ARCHIVO DE IMPLEMENTACIÓN: nombre.cpp
// Este archivo contiene las definiciones de las funciones miembro
// de la clase Nombre.
//***************************************************************************

#include "nombre.h"
#include <iostream>

using namespace std;

//***************************************************************************
// Constructor por omisión
// Solicita los componentes del nombre mediante la entrada estándar.
//***************************************************************************

Nombre::Nombre()
{
    cout << "Ingrese el primer nombre: ";
    getline(cin >> ws, primer_nombre);

    cout << "Ingrese el segundo nombre: ";
    getline(cin, segundo_nombre);

    cout << "Ingrese el apellido: ";
    getline(cin, apellido);
}

//***************************************************************************
// Constructor parametrizado
//***************************************************************************

Nombre::Nombre(
    const string& primer_nombre_inicial,
    const string& segundo_nombre_inicial,
    const string& apellido_inicial)
    : primer_nombre(primer_nombre_inicial),
      segundo_nombre(segundo_nombre_inicial),
      apellido(apellido_inicial)
{
}

//***************************************************************************
// Devuelve el primer nombre.
//***************************************************************************

string Nombre::obtener_primer_nombre() const
{
    return primer_nombre;
}

//***************************************************************************
// Devuelve el segundo nombre.
//***************************************************************************

string Nombre::obtener_segundo_nombre() const
{
    return segundo_nombre;
}

//***************************************************************************
// Devuelve el apellido.
//***************************************************************************

string Nombre::obtener_apellido() const
{
    return apellido;
}
```

## Especificación De La Clase `Entrada`

Una vez definida la clase `Nombre`, podemos declarar `Entrada`. Observa que sus datos miembro son objetos de las clases `Nombre` y `Tiempo`. Esta declaración establece la relación de composición entre ellas.

El archivo de especificación `entrada.h` queda de la siguiente manera:

```cpp
//***************************************************************************
// ARCHIVO DE ESPECIFICACIÓN: entrada.h
// Este archivo contiene la declaración del TDA Entrada,
// que contiene objetos de las clases Nombre y Tiempo.
//***************************************************************************

#ifndef ENTRADA_H
#define ENTRADA_H

#include "nombre.h"
#include "tiempo.h"
#include <string>

using namespace std;

class Entrada
{
public:
    string obtener_nombre() const;

    // Devuelve una cadena formada por el primer nombre
    // y el apellido, separados por un espacio.

    string obtener_hora() const;

    // Devuelve una cadena formada por las horas y los minutos,
    // separados por dos puntos.

    bool es_menor_que(const Entrada& otra_entrada) const;

    // Devuelve true si la hora de este objeto es anterior
    // a la de otra_entrada.

    bool es_igual(const Entrada& otra_entrada) const;

    // Devuelve true si ambas entradas tienen la misma hora.

    Entrada();

    // Constructor por omisión.

    Entrada(
        const string& primer_nombre,
        const string& segundo_nombre,
        const string& apellido,
        int horas_iniciales,
        int minutos_iniciales,
        int segundos_iniciales);

    // Constructor parametrizado.

private:
    Nombre nombre;
    Tiempo tiempo;
};

#endif // ENTRADA_H
```

## Implementación De La Clase `Entrada`

La implementación de las funciones miembro de `Entrada` es sencilla, ya que basta con invocar las operaciones públicas proporcionadas por los objetos `Nombre` y `Tiempo`.

El constructor por omisión no necesita realizar ninguna operación adicional, pues los objetos `nombre` y `tiempo` se construyen automáticamente mediante sus respectivos constructores por omisión.

Por otro lado, el constructor parametrizado debe transmitir los argumentos correspondientes a los constructores de ambas clases. Para ello, utilizamos la **lista de inicialización del constructor**.

El siguiente código corresponde al archivo de implementación `entrada.cpp`:

```cpp
//***************************************************************************
// ARCHIVO DE IMPLEMENTACIÓN: entrada.cpp
// Este archivo contiene las definiciones de las funciones miembro
// de la clase Entrada.
//***************************************************************************

#include "entrada.h"
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

//***************************************************************************
// Devuelve el primer nombre y el apellido.
//***************************************************************************

string Entrada::obtener_nombre() const
{
    return nombre.obtener_primer_nombre() + ' ' +
           nombre.obtener_apellido();
}

//***************************************************************************
// Devuelve las horas y los minutos en formato HH:MM.
//***************************************************************************

string Entrada::obtener_hora() const
{
    ostringstream resultado;

    resultado << setfill('0')
              << setw(2) << tiempo.obtener_horas()
              << ':'
              << setw(2) << tiempo.obtener_minutos();

    return resultado.str();
}

//***************************************************************************
// Compara la hora de esta entrada con la de otra entrada.
//***************************************************************************

bool Entrada::es_menor_que(const Entrada& otra_entrada) const
{
    return tiempo.es_menor_que(otra_entrada.tiempo);
}

//***************************************************************************
// Comprueba si ambas entradas tienen la misma hora.
//***************************************************************************

bool Entrada::es_igual(const Entrada& otra_entrada) const
{
    return tiempo.es_igual(otra_entrada.tiempo);
}

//***************************************************************************
// Constructor por omisión.
//***************************************************************************

Entrada::Entrada()
{
}

//***************************************************************************
// Constructor parametrizado.
//***************************************************************************

Entrada::Entrada(
    const string& primer_nombre,
    const string& segundo_nombre,
    const string& apellido,
    int horas_iniciales,
    int minutos_iniciales,
    int segundos_iniciales)
    : nombre(primer_nombre, segundo_nombre, apellido),
      tiempo(horas_iniciales, minutos_iniciales, segundos_iniciales)
{
}
```
