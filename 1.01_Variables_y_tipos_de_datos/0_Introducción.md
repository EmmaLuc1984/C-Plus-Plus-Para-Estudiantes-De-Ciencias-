# Variables y tipos de datos.
Un programa produce resultados mediante la manipulación de _datos_, estos son cualquier tipo de información que puede ser procesada por la computadora.

Los datos con los que un programa puede trabajar pueden ser obtenidos mediante una base de datos, la red o mediante input del usuario.

La unidad básica de los datos es conocida como _valor_, esta puede ser una letra (ej.: `z`), un número (ej.: `256`) o texto (ej.: `HolaMundo`).

C++ es un lenguaje de programación orientado a objetos, un *objeto* es una región de almacenamiento (léase: memoria) que puede guardar un valor y tiene ciertas propiedades asociadas. Dicho de manera muy burda: cuando trabajamos con C++, le estamos diciendo a la computadora *dame el valor resguardado por este objeto*, en vez de decirle *dame el valor que se encuentra en el espacio de memoria número tal*.
De este modo, no tenemos que preocuparnos sobre donde están nuestros objetos en la memoria, sino solamente en usarlos y recuperar valores.

Un objeto con un nombre asociado se llama _variable_. Nombrar a nuestros objetos nos permite poder referirnos a ellos más adelante en nuestros programas.

**Ojo:** En general la palabra *objeto* puede referirse a cualquier objeto en la memoria, en C++ los *objetos* excluyen a las funciones.

## Tipos De Datos Simples

C++ cuenta con distintos tipos de datos que permiten representar la información que utiliza un programa. Entre los más comunes se encuentran los siguientes:

- `short int` (o `short`): permite almacenar números enteros. Generalmente ocupa menos memoria que `int`, por lo que su dominio suele ser menor.
- `int`: permite almacenar números enteros, tanto positivos como negativos.
- `long int` (o `long`): permite almacenar números enteros y, dependiendo de la implementación, puede representar un dominio mayor que `int`.
- `float`: permite almacenar números de punto flotante, es decir, números que pueden tener una parte decimal. Ofrece aproximadamente 6 o 7 dígitos de precisión.
- `double`: también permite almacenar números de punto flotante, pero ofrece mayor precisión que `float`, aproximadamente 15 o 16 dígitos.
- `long double`: permite almacenar números de punto flotante con una precisión igual o mayor que `double`, dependiendo de la implementación del compilador.
- `bool`: permite representar valores lógicos. Únicamente puede tomar dos valores: `true` (verdadero) o `false` (falso).
- `char`: permite almacenar un carácter, como una letra, un dígito o un símbolo. Internamente, se representa mediante un código numérico asociado a una codificación de caracteres.
- `string`: permite almacenar cadenas de caracteres, es decir, secuencias de texto, como `"Hola Mundo"`. A diferencia de los tipos anteriores, `string` no es un tipo fundamental del lenguaje, sino una clase de la biblioteca estándar de C++, disponible mediante la biblioteca `<string>`. Las cadenas literales se escriben entre comillas dobles (`" "`), mientras que los caracteres individuales se escriben entre comillas simples (`' '`).

Los tipos fundamentales, como `short`, `int`, `long`, `float`, `double`, `long double`, `bool` y `char`, también suelen denominarse **tipos simples** o **atómicos**, ya que representan valores individuales. Por otro lado, cosas como `string` caen en una categoria diferente, pues son un tipo de dato especial conocido como *dato estructurado*.

## Dominio

Quizá te preguntes por qué C++ cuenta con distintos tipos de datos para representar información que, en algunos casos, parece muy similar. Por ejemplo, ¿por qué existen `float`, `double` y `long double` si todos permiten almacenar números con parte decimal?

La diferencia está principalmente en la cantidad de memoria que utilizan y en el dominio y la precisión de los valores que pueden representar. La memoria de una computadora se organiza en unidades de almacenamiento; una de ellas es el **byte**, que permite representar una pequeña cantidad de información. El tamaño de un tipo de dato indica cuánto espacio de memoria ocupa una variable de ese tipo y, por lo general, se expresa en bytes.

El espacio disponible influye en la cantidad y el tipo de valores que pueden representarse. Por ejemplo, un tipo entero con mayor capacidad puede almacenar números de mayor magnitud. De manera similar, `double` ofrece mayor precisión que `float`, por lo que resulta útil cuando se necesita representar números de punto flotante con más dígitos significativos.

Por otro lado, utilizar tipos de datos con tamaños menores puede ayudar a reducir el consumo de memoria cuando se trabaja con grandes cantidades de información. Por ello, elegir un tipo adecuado depende de los valores que se necesitan representar y de los recursos disponibles.

La siguiente tabla muestra algunos de los tipos de datos fundamentales más comunes, junto con sus tamaños y dominios aproximados:

| Tipo de dato | Descripción | Tamaño habitual | Dominio de valores aproximado |
|:--|:--|:--:|:--|
| `char` | Carácter o entero pequeño | 1 byte | Con signo: -128 a 127. Sin signo: 0 a 255. |
| `short int` (o `short`) | Entero corto | 2 bytes | Con signo: -32768 a 32767. Sin signo: 0 a 65535. |
| `int` | Entero | 4 bytes | Con signo: -2147483648 a 2147483647. Sin signo: 0 a 4294967295. |
| `long int` (o `long`) | Entero de mayor capacidad | 4 u 8 bytes | Depende de la implementación: puede utilizar un dominio de 32 o 64 bits. |
| `bool` | Valor lógico | 1 byte | `true` o `false`. |
| `float` | Número de punto flotante | 4 bytes | Aproximadamente ±3.4 × 10³⁸, con 6 o 7 dígitos de precisión. |
| `double` | Número de punto flotante de doble precisión | 8 bytes | Aproximadamente ±1.7 × 10³⁰⁸, con 15 o 16 dígitos de precisión. |
| `long double` | Número de punto flotante de precisión extendida | Variable | Depende de la implementación y del compilador. |

**Nota:** Los tamaños y dominios de esta tabla son habituales en muchas plataformas, pero no son universales. El estándar de C++ establece ciertos requisitos mínimos, mientras que el tamaño y la precisión concretos pueden variar según el compilador y la arquitectura del sistema. Por ejemplo, `long` puede ocupar 4 u 8 bytes, mientras que `long double` puede tener el mismo tamaño que `double` o proporcionar una precisión mayor.

El **dominio** de un tipo de dato hace referencia al conjunto de valores que puede representar. En los tipos numéricos, conocerlo permite determinar qué valores pueden almacenarse sin exceder la capacidad de representación del tipo.

### Tipos Con y Sin Signo

En la tabla anterior aparecen expresiones como *con signo* y *sin signo*. Estas indican si un tipo entero puede representar números negativos.

En C++, la palabra clave `unsigned` permite declarar tipos enteros sin signo, es decir, tipos que únicamente pueden almacenar valores iguales o mayores que cero. Por ejemplo:

- `unsigned int`
- `unsigned short`
- `unsigned long`

Al utilizar `unsigned`, una misma cantidad de memoria se aprovecha para representar un dominio distinto de valores. En lugar de incluir números negativos, el tipo puede representar una cantidad mayor de números positivos.

Esta característica se utiliza con los tipos enteros, como `char`, `short`, `int` y `long`. No se aplica a `float` ni a `double`, ya que C++ no define versiones sin signo de sus tipos de punto flotante.

## Reglas Importantes.
* Sobre nombrar variables:
    * El nombre de una variable debe empezar con una letra o con un guión bajo (_). En el nombre pueden usarse letras, números y más guiones bajos.
    * Los símbolos como '$' y '%' no se pueden usar para nombrar variables. Tampoco está permitido poner espacios dentro de los nombres de las variables. 
    * Para C++ (en general, esto es así en cualquier lenguaje de programación) las variables 'volumen_de_lata' y 'Volumen_de_lata' son distintas, esto porque distingue entre mayúsculas y minúsculas.
    * No se pueden usar _palabras reservadas_ para nombrar variables. Una palabra reservada es aquella que ya tiene un significado para el lenguaje de programación, por ejemplo en C++ no es posible llamar a una variable '`double`' porque esta palabra ya corresponde a un tipo de variable que puede almacenar valores decimales. 

* Crear variables:
    * De manera general, la sintaxis es: `tipo de variable nombre = valor;`. Donde `tipo de variable` es alguna de los tipos de variables de C++ (_int_ por ejemplo), `nombre` es el nombre de la variable ('volumen_de_lata' por ejemplo), `=` sirve para asignarle algún valor a la variable y `valor` es aquello que guardaremos en la variable.
        * `int latas_por_paquete = 6;` es una variable de tipo entero llamada 'latas_por_paquete' que guarda el valor 6.
        * `double decimal = 6.66;` es una variable de tipo decimal llamada 'decimal' que guarda el valor 6.66.
    * La palabra clave `const` se utiliza para especificar que el objeto o variable no se puede modificar.
        * `const double VOL_LATA = 0.355;` es una variable de tipo número decimal (`double`), llamada 'VOL_LATA' a la que se le asignó el valor 0.355. Le pusimos el prefijo `const` porque no la vamos a modificar más adelante.
        * Cuando vayamos a definir a una de nuestras variables usando la palabra reservada `const`, es buena práctica escribir su nombre usando sólo mayúsculas, para poder diferenciarla de variables regulares.

* Observaciones:
    * Siempre que creemos una variable es necesario que especifiquemos su tipo.
    * Una variable puede cambiar de valor tantas veces como queramos pero no puede cambiar de tipo.
    * Es común pensar que el símbolo `=` tiene el mismo significado en programación que el usual en matemáticas, esto es incorrecto. Cuando decimos que `latas_por_paquete = 6;`, estamos diciéndole al programa que guarde el valor 6 en la variable 'latas_por_paquete'; más adelante podemos incluir la línea `latas_por_paquete = 8;`, diciéndole al programa que ahora guarde el valor 8. De este modo, el símbolo `=` denota una asignación de valores en vez de una igualdad matemática.
        * Aunque se vea extraño, es perfectamente legal darle a C++ la instrucción: `latas_por_paquete = latas_por_paquete + 2;`. Esto le dice al programa que busque el valor guardado en la variable 'latas_por_paquete', le sume 2 y lo guarde en el mismo lugar.
        * El operador igualdad `==` es la igualdad matemática de siempre, este operador nos sirve para probar si dos operandos tienen el mismo valor.
    * C++ también le permite al usuario crear su propio tipo de variables personalizadas, esto es parte de lo que lo hace un lenguaje tan poderoso :ok_hand:

## Listado De Programas.
* En 'variables_comentado.cpp' viene un ejemplo de un programa en C++ que ilustra el uso de variables. Este ejemplo asume que la persona que lo está leyendo jamás ha visto en su vida un programa en C++, de modo que está lleno de comentarios que (espero) ayuden a que se entienda un poco mejor qué está pasando.
* 'variables.cpp' tiene el mismo programa que 'variables_comentado.cpp', pero sin los comentarios.
* 'saludo.cpp' trae un ejemplo de un programa que saluda al usuario y le pide su nombre.
* 'Comentarios.cpp' explica brevemente como funciona comentar en C++; dejar comentarios es una buena práctica al programar ya que estos sirven para que cualquiera que lea el programa (seamos nosotros en el futuro u otros compañeros de trabajo) pueda saber que está pasando.


