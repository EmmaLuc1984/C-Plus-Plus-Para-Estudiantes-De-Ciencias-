# Herencia

En muchos casos, es posible organizar distintos conceptos mediante una **jerarquía de herencia**, en la que cada concepto adquiere las propiedades del concepto que se encuentra inmediatamente por encima de él. Un ejemplo consiste en clasificar distintos tipos de vehículos de acuerdo con una jerarquía de este tipo: 


![Diagrama](https://github.com/EmmaLuc1984/C-plus-plus-para-principiantes-parte-2/blob/main/f5e9d2f6-9ca6-43c8-8099-063e54c2ca42.webp)


A medida que se desciende en la jerarquía, cada tipo de vehículo se vuelve más específico que su concepto padre y que los demás conceptos de los que desciende. Al mismo tiempo, es más general que sus propios conceptos hijos y que todos los que se encuentran por debajo de ellos.

Por ejemplo, un vehículo con ruedas hereda las características comunes a todos los vehículos, como transportar a una o varias personas de un lugar a otro, y añade una característica particular: tener ruedas. Por su parte, un automóvil hereda las propiedades de los vehículos con ruedas y agrega otras características más específicas, como tener cuatro ruedas, un motor y una carrocería.

La herencia representa una relación de tipo **"es un"** entre distintos conceptos. Por ejemplo, un automóvil de dos puertas es un automóvil, un automóvil es un vehículo con ruedas y un vehículo con ruedas es un vehículo.

Los lenguajes de programación orientada a objetos permiten establecer relaciones de herencia entre clases. La **herencia** es un mecanismo mediante el cual una clase puede adquirir las propiedades y operaciones definidas en otra clase.

Para comprender cómo funciona, consideremos una clase `A`, denominada **clase base** o **superclase**, a partir de la cual se define una nueva clase `B`, llamada **clase derivada** o **subclase**. Mediante la herencia, la clase `B` puede disponer de las propiedades y operaciones heredables de `A`. Esto significa que los datos y las operaciones definidos en la clase base también pueden formar parte de la clase derivada, de acuerdo con las reglas de acceso del lenguaje. De esta manera, se mantiene la relación **"es un"**: todo objeto de la clase `B` también pertenece al tipo `A` en el sentido de la herencia.

A partir de esta relación, es posible especializar la clase derivada incorporando nuevas propiedades y operaciones que complementen las heredadas de la clase base. Así, se pueden construir clases más específicas sin tener que volver a definir desde cero las características que ya comparten con otras clases.

## Derivar Una Clase De Otra 

Supongamos que queremos ampliar nuestra ya conocida clase `Tiempo` para que también almacene información sobre el huso horario. Para ello, podemos agregar un miembro privado de tipo enumeración que permita representar los siguientes husos horarios de Estados Unidos: `EST` (*Eastern Standard Time*), `CST` (*Central Standard Time*), `MST` (*Mountain Standard Time*), `PST` (*Pacific Standard Time*), `EDT` (*Eastern Daylight Time*), `CDT` (*Central Daylight Time*), `MDT` (*Mountain Daylight Time*) y `PDT` (*Pacific Daylight Time*).

Esta modificación requiere ampliar la función `establecer` y los constructores para que, además de las horas, los minutos y los segundos, reciban un valor que indique el huso horario. Asimismo, la función `escribir` deberá mostrar esta información junto con la hora. Por ejemplo:

```text
12:34:10 CST
```

Por otro lado, no es necesario modificar la función `incrementar`, ya que su propósito sigue siendo avanzar el tiempo un segundo, independientemente del huso horario almacenado.

Una alternativa para incorporar estas características consistiría en modificar directamente el código fuente de la clase `Tiempo`, analizar su implementación en el archivo `Tiempo.cpp` y volver a compilar el programa. Sin embargo, este procedimiento presenta varios inconvenientes.

En primer lugar, es posible que el código fuente de la clase no esté disponible, especialmente si forma parte de una biblioteca o de un sistema desarrollado por terceros. Además, aunque tuviéramos acceso a él, modificar una implementación que ya funciona correctamente podría introducir errores nuevos. Por último, depender del conocimiento de los detalles internos de una clase contradice uno de los objetivos de la abstracción: permitir que los usuarios aprovechen sus funcionalidades sin necesidad de conocer cómo están implementadas.

En C++, como en otros lenguajes orientados a objetos, existe una alternativa que permite extender las funcionalidades de una clase sin modificar directamente su implementación original: **la herencia**. Mediante este mecanismo, podemos definir una nueva clase a partir de `Tiempo` y añadirle las características necesarias. Llamaremos `Tiempo_extendido` a esta nueva clase, que heredará los miembros accesibles de su clase base.

La declaración de `Tiempo_extendido` podría escribirse de la siguiente manera:

```cpp
enum Tipo_zona_horaria
{
    est,
    cst,
    mst,
    pst,
    edt,
    cdt,
    mdt,
    pdt
};

class Tiempo_extendido : public Tiempo
{
public:
    void establecer(
        int horas,
        int minutos,
        int segundos,
        Tipo_zona_horaria zona);

    void escribir() const;

    Tipo_zona_horaria obtener_zona_horaria() const;

    Tiempo_extendido(
        int horas_iniciales,
        int minutos_iniciales,
        int segundos_iniciales,
        Tipo_zona_horaria zona_inicial);

    Tiempo_extendido();

private:
    Tipo_zona_horaria zona_horaria;
};
```

La expresión `class Tiempo_extendido : public Tiempo` indica que `Tiempo_extendido` es una clase derivada de `Tiempo`. El especificador `public` establece una relación de herencia pública, mediante la cual los miembros públicos de la clase base continúan siendo accesibles a través de los objetos de la clase derivada, siempre que no exista alguna restricción adicional.

Por ejemplo, las funciones `establecer`, `incrementar` y `escribir` forman parte de la interfaz pública de `Tiempo`. La nueva clase proporciona sus propias declaraciones de `establecer` y `escribir` para incorporar el tratamiento del huso horario, mientras que puede seguir utilizando la función heredada `incrementar`, pues su comportamiento no necesita cambiar. También se añade la función `obtener_zona_horaria`, que permite consultar el huso horario asociado al objeto.

En la sección privada de `Tiempo_extendido` se declara el nuevo miembro `zona_horaria`, cuyo tipo es `Tipo_zona_horaria`. De esta manera, la clase derivada incorpora información adicional a la que ya proporciona `Tiempo`. Los miembros privados de la clase base, en cambio, siguen perteneciendo a la implementación de `Tiempo` y no pueden manipularse directamente desde las funciones miembro de la clase derivada; para trabajar con ellos deben utilizarse las operaciones accesibles proporcionadas por la clase base.

Esta relación puede entenderse mediante la idea de que cada objeto de tipo `Tiempo_extendido` contiene un subobjeto correspondiente a `Tiempo`. Por tanto, un objeto de `Tiempo_extendido` puede considerarse un `Tiempo` al que se han añadido características adicionales: conserva las funcionalidades heredadas y dispone de información sobre el huso horario.

En C++, se utilizan los términos **clase base** y **clase derivada** para describir esta relación. También es posible encontrar las denominaciones *superclase* y *subclase*, aunque las primeras son las empleadas habitualmente en la terminología de C++. El término *subclase* puede resultar confuso, ya que una clase derivada no necesariamente es más pequeña que su clase base; de hecho, con frecuencia incorpora más datos y operaciones.

Por último, cuando una función de la clase base se hereda públicamente y no se declara una función equivalente en la clase derivada, su funcionalidad sigue estando disponible para los usuarios de esta última. Así ocurre con `incrementar`: como `Tiempo_extendido` no necesita redefinirla, puede utilizar la implementación heredada de `Tiempo` para avanzar el tiempo un segundo. Esta continuidad permite ampliar una clase sin tener que repetir las operaciones que ya funcionan correctamente.


## Especificación De La Clase `Tiempo_extendido`

A continuación, veremos la especificación de la clase `Tiempo_extendido`, acompañada de su documentación correspondiente.

Como nota importante, la directiva del preprocesador `#include "tiempo.h"` permite incluir la declaración de la clase `Tiempo` antes de definir `Tiempo_extendido`. Esto es necesario para que el compilador conozca la clase base y pueda comprobar que la relación de herencia está correctamente declarada.

El siguiente código corresponde al archivo de especificación `tiempo_extendido.h`:

```cpp
//***************************************************************************
// ARCHIVO DE ESPECIFICACIÓN: tiempo_extendido.h
// Este archivo define la interfaz del tipo de dato abstracto
// Tiempo_extendido.
//
// La clase Tiempo es una clase base pública de Tiempo_extendido.
// Por ello, las operaciones públicas heredadas de Tiempo también
// pueden utilizarse mediante objetos de Tiempo_extendido.
//***************************************************************************

#include "tiempo.h"

enum Tipo_zona_horaria
{
    est,
    cst,
    mst,
    pst,
    edt,
    cdt,
    mdt,
    pdt
};

class Tiempo_extendido : public Tiempo
{
public:
    void establecer(
        int horas,
        int minutos,
        int segundos,
        Tipo_zona_horaria zona);

    // Precondición:
    // 0 <= horas <= 23, 0 <= minutos <= 59 y
    // 0 <= segundos <= 59.
    // zona debe ser un valor válido de Tipo_zona_horaria.
    //
    // Poscondición:
    // El tiempo y el huso horario del objeto se establecen
    // de acuerdo con los argumentos recibidos.

    void escribir() const;

    // Poscondición:
    // Se muestra el tiempo en el formato HH:MM:SS ZZZ,
    // donde ZZZ representa la abreviatura del huso horario.

    Tipo_zona_horaria obtener_zona_horaria() const;

    // Poscondición:
    // El valor devuelto corresponde al huso horario
    // almacenado en el objeto.

    Tiempo_extendido(
        int horas_iniciales,
        int minutos_iniciales,
        int segundos_iniciales,
        Tipo_zona_horaria zona_inicial);

    // Precondición:
    // 0 <= horas_iniciales <= 23,
    // 0 <= minutos_iniciales <= 59 y
    // 0 <= segundos_iniciales <= 59.
    // zona_inicial debe ser un valor válido de
    // Tipo_zona_horaria.
    //
    // Poscondición:
    // Se construye un objeto Tiempo_extendido cuyo
    // tiempo y huso horario corresponden a los
    // argumentos recibidos.

    Tiempo_extendido();

    // Poscondición:
    // Se construye un objeto cuyo tiempo es 00:00:00
    // y cuyo huso horario es el estándar del este (EST).

private:
    Tipo_zona_horaria zona_horaria;
};
```

Mediante esta clase, el programador puede establecer una hora junto con su huso horario, ya sea utilizando el constructor con argumentos o la función `establecer`. También puede mostrar ambos datos mediante la función `escribir` y consultar el huso horario con `obtener_zona_horaria`.

Además, la clase conserva la funcionalidad heredada de `Tiempo` para avanzar el reloj un segundo mediante la función `incrementar`. No es necesario volver a implementarla, pues su comportamiento no cambia al añadir el huso horario.


Por otro lado, el siguiente programa muestra cómo utilizar la clase `Tiempo_extendido` desde un programa cliente. En él se crean dos objetos, se muestran sus valores iniciales, se modifica uno de ellos y se comprueba el funcionamiento de la operación heredada `incrementar`.

El código corresponde al archivo `demostracion_tiempo.cpp`:

```cpp
//***************************************************************************
// Programa: demostracion_tiempo.cpp
// Ejemplo de uso de la clase Tiempo_extendido.
//***************************************************************************

#include <iostream>
#include "tiempo_extendido.h"

 using namespace std;


int main()
{
    // Se utiliza el constructor con argumentos.
    Tiempo_extendido tiempo1(5, 30, 0, cdt);

    // Se utiliza el constructor por omisión.
    Tiempo_extendido tiempo2;

    int contador;

    cout << "tiempo1: ";
    tiempo1.escribir();

    cout << "\ntiempo2: ";
    tiempo2.escribir();

    cout << '\n';

    // Se establece una nueva hora para tiempo2.
    tiempo2.establecer(23, 59, 55, pst);

    cout << "Nuevo tiempo2: ";
    tiempo2.escribir();

    cout << "\nIncrementando tiempo2:\n";

    for (contador = 1; contador <= 10; contador++)
    {
        tiempo2.escribir();
          cout << ' ';

        tiempo2.incrementar();
    }

    return 0;
}
```

Al ejecutar el programa, se obtiene una salida coo esta:

```text
tiempo1: 05:30:00 CDT
tiempo2: 00:00:00 EST
Nuevo tiempo2: 23:59:55 PST
Incrementando tiempo2:
23:59:55 PST 23:59:56 PST 23:59:57 PST 23:59:58 PST 23:59:59 PST
00:00:00 PST 00:00:01 PST 00:00:02 PST 00:00:03 PST 00:00:04 PST
```

## Implementación De La Clase `Tiempo_extendido`

La implementación de `Tiempo_extendido` debe centrarse únicamente en las características que la diferencian de su clase base, `Tiempo`. Por lo tanto, es necesario definir los constructores y proporcionar implementaciones propias de las funciones `establecer` y `escribir`, así como de la función que permite consultar el huso horario.

En las clases derivadas, los constructores siguen ciertas reglas particulares. Cuando se crea un objeto de una clase derivada, *el constructor de la clase base se ejecuta antes que el cuerpo del constructor de la clase derivada*. Además, cuando el constructor de la clase base requiere argumentos, estos deben proporcionarse explícitamente desde el constructor de la clase derivada.

Para comprender cómo se aplican estas reglas, examinemos el archivo de implementación `tiempo_extendido.cpp`.


```cpp
//***************************************************************************
// ARCHIVO DE IMPLEMENTACIÓN: tiempo_extendido.cpp
// Este archivo contiene las definiciones de las funciones miembro
// de la clase Tiempo_extendido.
//
// Tiempo es la clase base pública de Tiempo_extendido.
//***************************************************************************

#include "tiempo_extendido.h"
#include <iostream>
#include <string>

//***************************************************************************
// Constructor con argumentos
//
// Precondición:
// 0 <= horas_iniciales <= 23,
// 0 <= minutos_iniciales <= 59 y
// 0 <= segundos_iniciales <= 59.
// zona_inicial debe ser un valor válido de Tipo_zona_horaria.
//
// Poscondición:
// El tiempo se establece mediante el constructor de la clase base
// y el huso horario se establece de acuerdo con zona_inicial.
//***************************************************************************

Tiempo_extendido::Tiempo_extendido(
    int horas_iniciales,
    int minutos_iniciales,
    int segundos_iniciales,
    Tipo_zona_horaria zona_inicial)
    : Tiempo(horas_iniciales, minutos_iniciales, segundos_iniciales)
{
    zona_horaria = zona_inicial;
}

//***************************************************************************
// Constructor por omisión
//
// Poscondición:
// El tiempo se establece en 00:00:00 mediante el constructor por
// omisión de la clase base y el huso horario se establece en EST.
//***************************************************************************

Tiempo_extendido::Tiempo_extendido()
{
    zona_horaria = est;
}

//***************************************************************************
// Función establecer
//
// Precondición:
// 0 <= horas <= 23,
// 0 <= minutos <= 59 y
// 0 <= segundos <= 59.
// zona debe ser un valor válido de Tipo_zona_horaria.
//
// Poscondición:
// El tiempo se establece de acuerdo con los argumentos recibidos
// y el huso horario se actualiza con el valor de zona.
//***************************************************************************

void Tiempo_extendido::establecer(
    int horas,
    int minutos,
    int segundos,
    Tipo_zona_horaria zona)
{
    Tiempo::establecer(horas, minutos, segundos);
    zona_horaria = zona;
}

//***************************************************************************
// Función obtener_zona_horaria
//
// Poscondición:
// El valor devuelto corresponde al huso horario del objeto.
//***************************************************************************

Tipo_zona_horaria Tiempo_extendido::obtener_zona_horaria() const
{
    return zona_horaria;
}

//***************************************************************************
// Función escribir
//
// Poscondición:
// Se muestra el tiempo en el formato HH:MM:SS ZZZ,
// donde ZZZ representa la abreviatura del huso horario.
//***************************************************************************

void Tiempo_extendido::escribir() const
{
    static const std::string nombres_zonas[8] =
    {
        "EST", "CST", "MST", "PST",
        "EDT", "CDT", "MDT", "PDT"
    };

    Tiempo::escribir();
    std::cout << ' ' << nombres_zonas[zona_horaria];
}
```


Observa como un constructor transmite argumentos a su constructor de clase base:

```cpp
Tiempo_extendido::Tiempo_extendido(
    int horas_iniciales,
    int minutos_iniciales,
    int segundos_iniciales,
    Tipo_zona_horaria zona_inicial)
    : Tiempo(horas_iniciales, minutos_iniciales, segundos_iniciales)
{
    zona_horaria = zona_inicial;
}
```

Después de la lista de parámetros del constructor y antes de su cuerpo, se escribe una *lista de inicialización*, que comienza con dos puntos (`:`), seguida del nombre de la clase base y los argumentos que recibirá su constructor.

Ahora supongamos que creamos un objeto mediante la siguiente declaracin:

```cpp
Tiempo_extendido tiempo1(8, 35, 0, pst);
```

En este caso, el constructor de `Tiempo_extendido` recibe cuatro argumentos. Los tres primeros se transmiten al constructor de `Tiempo` mediante la lista de inicialización. Una vez que termina la construcción del subobjeto correspondiente a la clase base, se ejecuta el cuerpo del constructor de `Tiempo_extendido`, donde se asigna el cuarto argumento al miembro `zona_horaria`.

De esta manera, cada clase se encarga de inicializar la parte del objeto que le corresponde: `Tiempo` establece las horas, los minutos y los segundos, mientras que `Tiempo_extendido` asigna el huso horario.

El segundo constructor, que corresponde al constructor por omisión, no necesita una lista de inicialización explícita para la clase base, ya que no hay argumentos que transmitir:

```cpp
Tiempo_extendido::Tiempo_extendido()
{
    zona_horaria = est;
}
```

Cuando se crea un objeto mediante una declaración como:

```cpp
Tiempo_extendido tiempo2;
```

se invoca automáticamente el constructor por omisión de `Tiempo`. Este establece la hora en `00:00:00`. Posteriormente, se ejecuta el cuerpo del constructor de `Tiempo_extendido`, que asigna `est` al miembro `zona_horaria`, estableciendo así el huso horario `EST`.

Ahora examinemos la función `establecer`. Esta proporciona una versión propia de la operación heredada de `Tiempo`, adaptada para recibir también un argumento que indique el huso horario.

Por lo tanto, existen dos funciones con el mismo nombre: una pertenece a la clase base y otra a la clase derivada. Podemos distinguirlas mediante sus nombres completos: `Tiempo::establecer` y `Tiempo_extendido::establecer`.

La implementación de la función de la clase derivada comienza invocando explícitamente la operación correspondiente de la clase base:

```cpp
void Tiempo_extendido::establecer(
    int horas,
    int minutos,
    int segundos,
    Tipo_zona_horaria zona)
{
    Tiempo::establecer(horas, minutos, segundos);
    zona_horaria = zona;
}
```

La llamada a `Tiempo::establecer` permite actualizar las horas, los minutos y los segundos. Esto es necesario porque los miembros privados de `Tiempo` no pueden manipularse directamente desde las funciones miembro de `Tiempo_extendido`.

Después de establecer la hora mediante la operación heredada, se asigna el valor recibido al miembro privado `zona_horaria`, que pertenece exclusivamente a la clase derivada.

Así, `Tiempo_extendido` aprovecha la funcionalidad existente en `Tiempo` para establecer la hora y añade únicamente el comportamiento necesario para almacenar el huso horario.

La función `escribir` sigue un procedimiento semejante al de `establecer`: primero utiliza la operación de la clase base para mostrar las horas, los minutos y los segundos, y después añade la abreviatura correspondiente al huso horario.

```cpp
void Tiempo_extendido::escribir() const
{
    static const std::string nombres_zonas[8] =
    {
        "EST", "CST", "MST", "PST",
        "EDT", "CDT", "MDT", "PDT"
    };

    Tiempo::escribir();
    std::cout << ' ' << nombres_zonas[zona_horaria];
}
```

Para mostrar el huso horario, se utiliza un arreglo de ocho cadenas de caracteres llamado `nombres_zonas`. Cada posición contiene una de las abreviaturas disponibles: `EST`, `CST`, `MST`, `PST`, `EDT`, `CDT`, `MDT` y `PDT`.

La utilización de este arreglo es necesaria porque los valores de un tipo enumerado no se muestran directamente mediante sus nombres. Por ejemplo, si intentáramos imprimir directamente el valor de `zona_horaria`, obtendríamos su representación numérica, que en este caso corresponde a un entero entre 0 y 7. Esto sucede porque los enumeradores se representan internamente mediante valores enteros consecutivos, comenzando desde cero cuando no se especifican otros valores.

Para obtener la abreviatura correspondiente, se utiliza el valor de `zona_horaria` como índice del arreglo. De esta manera, cada valor de la enumeración permite seleccionar la cadena asociada a su huso horario.

Por otra parte, el arreglo `nombres_zonas` se declara con el especificador `static`. Esto significa que su almacenamiento tiene duración estática: no se crea y destruye en cada llamada a la función, sino que permanece durante toda la ejecución del programa. Su inicialización se realiza cuando el flujo de ejecución alcanza por primera vez su declaración. Así, se evita repetir la creación del arreglo cada vez que se invoca `escribir`. Además, el especificador `const` impide modificar las cadenas almacenadas.

## Compilación Y Enlace Del Programa

Una vez terminado el archivo de implementación `tiempo_extendido.cpp`, podemos compilarlo para generar su correspondiente archivo de código objeto, por ejemplo, `tiempo_extendido.obj`.

De igual manera, después de escribir un programa de prueba en el archivo `pruebas.cpp`, podemos compilarlo para obtener `pruebas.obj`.

Finalmente, para generar el archivo ejecutable, es necesario enlazar los tres archivos de código objeto:

1. `pruebas.obj`: contiene el código del programa de prueba.
2. `tiempo_extendido.obj`: contiene la implementación de la clase derivada.
3. `tiempo.obj`: contiene la implementación de la clase base.

Una vez realizado el enlace, obtenemos un programa ejecutable que permite comprobar el funcionamiento de la clase `Tiempo_extendido`.

Una de las principales ventajas de la herencia es que permite ampliar las funcionalidades de una clase sin necesidad de modificar su implementación original. Incluso cuando no se dispone del código fuente de la clase base, es posible desarrollar nuevas clases a partir de ella, siempre que se cuente con los archivos necesarios para su declaración y enlace.

Por ejemplo, una clase como `Tiempo` puede utilizarse directamente en distintos programas o servir como punto de partida para crear versiones más especializadas, como `Tiempo_extendido`. De esta manera, los lenguajes orientados a objetos facilitan la **reutilización de código**, ya que permiten aprovechar las operaciones existentes y adaptarlas a nuevas necesidades.

La herencia también permite construir **abstracciones de datos extensibles**. Esto significa que una clase derivada puede ampliar las capacidades de su clase base mediante la incorporación de nuevos miembros privados, nuevas operaciones públicas o ambas cosas. Al mismo tiempo, conserva las funcionalidades heredadas que siguen siendo necesarias, evitando tener que implementarlas nuevamente.


## Evitar Inclusiones Múltiples De Archivos De Encabezado

Anteriormente, vimos que el archivo de especificación `tiempo_extendido.h` incluye `tiempo.h` para disponer de la declaración de la clase `Tiempo`:

```cpp
#include "tiempo.h"

enum Tipo_zona_horaria
{
    est, cst, mst, pst,
    edt, cdt, mdt, pdt
};

class Tiempo_extendido : public Tiempo
{
    // ...
};
```

Supongamos que un programador incluye ambos archivos en su programa:

```cpp
#include "tiempo.h"
#include "tiempo_extendido.h"
```

En este caso, `tiempo.h` se procesa dos veces: primero por su inclusión directa y después porque `tiempo_extendido.h` también lo incluye. Esto provoca un error de compilación, ya que la clase `Tiempo` queda declarada más de una vez.

Para evitar este problema, utilizamos algo conocido como **guardas de inclusión**, que impiden procesar varias veces el contenido de un mismo archivo de encabezado. Para implementarlas, podemos modificar `tiempo.h` de la siguiente manera:

```cpp
#ifndef TIEMPO_H
#define TIEMPO_H

class Tiempo
{
    // ...
};

#endif // TIEMPO_H
```

Las directivas `#ifndef` y `#define` trabajan conjuntamente para controlar la inclusión del archivo. En este caso, `TIEMPO_H` es una **macro del preprocesador** que funciona como una marca para indicar si el archivo ya fue procesado.

Su funcionamiento es sencillo:

1. `#ifndef TIEMPO_H` comprueba si la macro `TIEMPO_H` aún no ha sido definida.
2. Si no está definida, `#define TIEMPO_H` la registra y permite procesar el contenido del archivo.
3. Cuando se intenta incluir nuevamente el archivo, la macro ya está definida y el contenido protegido se omite.

De esta manera, se evita que las declaraciones de una clase se procesen varias veces, previniendo errores de redefinición durante la compilación.