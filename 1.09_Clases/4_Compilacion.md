# Compilación

Una vez que se han creado el archivo de especificación y el archivo de implementación de la clase `Tiempo`, es necesario comprender cómo se utilizan ambos archivos dentro de un programa. Para ello, primero debemos estudiar el concepto de *compilación separada*, que permite organizar un programa de C++ en varios archivos de código fuente.

Un programa que se distribuye en distintos archivos de código fuente se conoce como *programa multiarchivo*. En C++, cada uno de estos archivos puede compilarse de manera independiente, sin necesidad de compilar nuevamente todo el programa cada vez que se realiza una modificación.

Durante la compilación, cada archivo de código fuente se traduce a un archivo de código objeto. Por ejemplo, si un programa está formado por los archivos `programa.cpp`, `archivo_2.cpp` y `archivo_3.cpp`, cada uno puede compilarse por separado para generar sus correspondientes archivos de código objeto: `programa.o`, `archivo_2.o` y `archivo_3.o`. Estos archivos contienen código máquina, pero todavía necesitan combinarse para producir un programa ejecutable.

Esta combinación se realiza mediante enlazador o linker. Su función consiste en reunir los archivos de código objeto y resolver las referencias entre ellos para generar el archivo ejecutable. Las extensiones utilizadas para estos archivos dependen del sistema y de las herramientas de compilación; por ejemplo, algunos entornos utilizan `.o` para los archivos de código objeto, mientras que otros emplean `.obj`.

Por lo general, los archivos secundarios de un programa contienen definiciones de funciones que son utilizadas por otros archivos. Una ventaja importante de la compilación separada es que, cuando se modifica uno de ellos, normalmente solo es necesario volver a compilar ese archivo y enlazar nuevamente el programa con los archivos de código objeto que no han cambiado.

Sin embargo, si una modificación afecta a otros archivos, también puede ser necesario actualizarlos y compilarlos de nuevo. Esto ocurre, por ejemplo, cuando se modifica la interfaz de una función y cambia el número o el tipo de sus parámetros, ya que las partes del programa que utilizan esa función deben adaptarse a la nueva declaración.

Ahora, para nuestro ejemplo, supongamos que ya se han creado los archivos `Tiempo.h` y `Tiempo.cpp`. El primero contiene la declaración de la clase, mientras que el segundo incluye las definiciones de sus funciones miembro.

El archivo de implementación puede compilarse por separado desde la línea de comandos mediante una instrucción como la siguiente:

```text g++ -c Tiempo.cpp -o Tiempo.o```

En este comando, g++ invoca al compilador de C++, mientras que la opción `-c` indica que se debe compilar el archivo sin realizar el enlazado final. Por su parte, `-o Tiempo.o` especifica el nombre del archivo de código objeto que se generará.

Una vez obtenido `Tiempo.o`, el archivo de implementación ya no necesita compilarse cada vez que otro programa utilice la clase, siempre que no sea necesario modificarla ni actualizar su archivo de código objeto.

Para utilizar la clase, otro programador puede escribir un archivo de código cliente que incluya `Tiempo.h` y declare objetos de tipo `Tiempo`. Por ejemplo, el archivo `agenda.cpp` podría contener lo siguiente:
```c++
#include "Tiempo.h"

int main()
{
    Tiempo cita;

    cita.establecer(15, 30, 0);
    cita.escribir();

    return 0;
}
```

En este caso, el programa incluye el archivo de especificación para conocer la declaración de la clase `Tiempo`. Después, crea un objeto llamado `cita`, establece su valor a las `15:30:00` e invoca la función miembro `escribir` para mostrar el tiempo.

Para generar el ejecutable, podemos compilar el archivo cliente y enlazarlo con el archivo de código objeto de la clase. Una forma de hacerlo es mediante el siguiente comando:

```text g++ agenda.cpp Tiempo.o -o agenda ```

Esta instrucción compila el código cliente y lo enlaza con `Tiempo.o` para producir un programa ejecutable llamado `agenda`. Los nombres y las extensiones de los archivos resultantes pueden variar según el sistema operativo y el compilador utilizado.

La forma de compilar, enlazar y ejecutar un programa depende de las herramientas disponibles en cada sistema. En los ejemplos anteriores se ha supuesto que se trabaja directamente con la terminal que te otorga Visual Studio Code.

Antes de concluir, conviene destacar un aspecto importante de la relación entre los archivos `Tiempo.h` y `Tiempo.cpp`. Para que otras personas puedan utilizar la clase `Tiempo`, es suficiente con proporcionarles el archivo de especificación y el archivo de código objeto correspondiente, siempre que este último sea compatible con su entorno de compilación. No es indispensable compartir el archivo `Tiempo.cpp`.

El archivo `Tiempo.h` permite conocer las operaciones disponibles y la forma de utilizarlas, mientras que `Tiempo.o` contiene el código compilado necesario para enlazar esas operaciones con el programa cliente. En cambio, el archivo `Tiempo.cpp` contiene los detalles de implementación de la clase y puede mantenerse separado.

Esta organización refleja el principio de ocultación de información: quienes utilizan una abstracción deben poder trabajar con ella a partir de su especificación, sin tener que estudiar cómo está implementada internamente. De igual manera, el código cliente no debería depender de los detalles particulares de esa implementación.

Separar la interfaz de la implementación facilita el mantenimiento del software. Siempre que se respete la interfaz pública, es posible modificar la implementación de una clase sin obligar a los usuarios a cambiar el código que la utiliza. Así, la abstracción reduce la complejidad que debe manejar el programador y permite desarrollar programas más modulares, flexibles y fáciles de mantener.