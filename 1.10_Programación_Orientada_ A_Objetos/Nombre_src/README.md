# Diseño E implementación Del TDA `Nombre`

Paralelo a lo que hemos venido haciendo con la clase `Time`, hemos a desarrollado una clase auxiliar `Nombre`, cuyo propósito es representar nombres de personas mediante tres componentes: primer nombre, segundo nombre y apellido. Se busca que tanto su dominio como sus operaciones sean lo suficientemente generales para poder utilizarse en cualquier programa que necesite almacenar y manipular nombres.

Como siempre, se han creado tanto su especificación como su implementación: 

## Especificación De `Nombre`

El dominio de la clase `Nombre` quedó conformado por nombres compuestos por un primer nombre, un segundo nombre y un apellido. Para representar este TDA en C++, declaramos una clase llamada `Nombre`, cuyas operaciones se definieron como funciones miembro públicas.

Las operaciones implementadas fueron las siguientes:

- **Construir un objeto `Nombre`:** se incorporó un constructor por omisión que permite crear un objeto sin proporcionar argumentos. Inicialmente, sus tres componentes se establecen como cadenas vacías, lo que representa un nombre que todavía no ha sido definido.

- **Establecer un nombre:** se proporcionaron dos mecanismos para asignar los componentes de un nombre. El primero consiste en un constructor parametrizado, que recibe como argumentos el primer nombre, el segundo nombre y el apellido durante la creación del objeto. El segundo corresponde a la función miembro `establecer`, que permite modificar esos valores después de que el objeto ya ha sido creado. En ambos casos, los tres argumentos se representan mediante cadenas de tipo `string`.

- **Leer un nombre:** se implementó una operación que solicita al usuario e introduce, mediante el dispositivo de entrada estándar, el primer nombre, el segundo nombre y el apellido. De esta manera, los valores pueden asignarse al objeto durante la ejecución del programa.

- **Consultar los componentes del nombre:** se incorporaron tres funciones miembro observadoras, denominadas `primer_nombre`, `segundo_nombre` y `apellido`. Cada una devuelve el valor de uno de los componentes del nombre, permitiendo que el código cliente consulte la información almacenada sin acceder directamente a los atributos privados de la clase.

  Se mantuvieron estos atributos como privados para proteger la integridad de los objetos. De esta forma, el cliente puede consultar sus valores mediante las funciones observadoras, pero no modificarlos directamente. Cualquier cambio debe realizarse a través de las operaciones proporcionadas por la propia clase.

- **Consultar la inicial del segundo nombre:** se añadió la función miembro `inicial_segundo_nombre`, cuya finalidad es obtener y devolver únicamente el primer carácter del segundo nombre. Para esta operación se utilizó el tipo de dato `char`, ya que únicamente se necesita representar un carácter.

- **Comparar dos nombres:** se incorporó una operación que permite comparar un objeto `Nombre` con otro para determinar si el primero se encuentra antes, es igual o se encuentra después del segundo. Para representar los posibles resultados se definió un tipo de enumeración denominado `TipoRelacion`, con los valores `ANTES`, `IGUAL` y `DESPUES`. La función miembro `comparado_con` devuelve uno de estos valores como resultado de la comparación.

En esta última operación, el objeto desde el cual se invoca la función se compara con el objeto recibido como argumento. Por ejemplo, el código cliente puede utilizar esta operación para determinar si un nombre se encuentra antes que otro y, a partir del resultado, ejecutar las instrucciones correspondientes.

## Representación De Los Datos

Para completar la declaración de la clase en C++, también se definió su sección privada, en la que se estableció la representación concreta de los datos. Se eligió utilizar tres variables de tipo `string`: una para almacenar el primer nombre, otra para el segundo nombre y una última para el apellido.

Esta representación permitió mantener la información encapsulada y controlar su manipulación mediante las funciones miembro públicas. Aunque la elección de una representación concreta corresponde conceptualmente a la etapa de implementación, fue necesario establecerla desde la declaración de la clase para satisfacer los requisitos de la sintaxis de C++.

Finalmente, se organizó el desarrollo mediante la separación de la especificación y la implementación. La declaración de la clase `Nombre`, junto con el tipo de enumeración `TipoRelacion`, se colocó en un archivo de encabezado con extensión `.h`. Esta la puedes escontrar [aquí.](https://github.com/EmmaLuc1984/C-Plus-Plus-Para-Estudiantes-De-Ciencias-/blob/main/1.10_Programaci%C3%B3n_Orientada_%20A_Objetos/Nombre_src/nombre.h)

## Implementación De `Nombre`

Una vez establecida la representación de los datos de la clase `Nombre`, mediante las variables de tipo `string` `primer_nombre`, `segundo_nombre` y `apellido`, el siguiente paso consiste en implementar sus funciones miembro. Para ello, se colocan sus definiciones en el archivo de implementación `nombre.cpp`.

La implementación de todas estas funciones son tan directas que no es necesaria explicación alguna. Pu8edes ver la implementación [aquí.](https://github.com/EmmaLuc1984/C-Plus-Plus-Para-Estudiantes-De-Ciencias-/blob/main/1.10_Programaci%C3%B3n_Orientada_%20A_Objetos/Nombre_src/nombre.cpp)