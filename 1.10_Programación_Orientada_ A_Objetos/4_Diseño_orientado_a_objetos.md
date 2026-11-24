# Diseño orientado a objetos

Hasta ahora se han estudiado distintas características de C++ que permiten desarrollar programas siguiendo los principios de la programación orientada a objetos. El siguiente paso consiste en comprender cómo se aplica esta filosofía durante el diseño de una solución, proceso conocido como **diseño orientado a objetos (OOD)**.

Por lo general, un programa de computadora busca representar o resolver alguna situación del mundo real. Por ejemplo, un sistema bancario puede modelar las operaciones relacionadas con las cuentas de los clientes; una hoja de cálculo representa la organización de información mediante filas y columnas, y un programa de robótica puede representar distintos aspectos del movimiento y la percepción.

El entorno que se desea representar se conoce como **dominio del problema**. Este puede estar compuesto por distintos elementos, como cuentas bancarias, clientes, filas, columnas o partes de un robot. Por otro lado, el programa que se desarrolla para resolver dicho problema también contiene objetos propios, como ventanas, menús y listas, los cuales forman parte del **dominio de solución**.

El diseño orientado a objetos parte de la idea de que resulta más sencillo desarrollar y comprender un programa cuando los objetos que lo componen representan, en la medida de lo posible, los elementos del problema que se desea resolver.

Aunque existen diferentes metodologías para realizar un diseño orientado a objetos, en este apartado se seguirá un proceso general compuesto por tres etapas:

1. Identificar los objetos y sus operaciones.
2. Determinar las relaciones entre los objetos.
3. Diseñar el controlador.

A continuación, se describen los aspectos principales de cada una de estas etapas.

## Paso 1: Identificar Los Objetos Y Sus Operaciones

A diferencia del diseño estructurado, que comienza identificando las principales acciones que debe ejecutar un programa, el diseño orientado a objetos inicia reconociendo los objetos que intervienen en el problema y las operaciones que se pueden realizar sobre ellos.

Una manera de comenzar este proceso consiste en analizar la descripción del problema e identificar los sustantivos y los verbos más relevantes. Los sustantivos pueden sugerir posibles objetos, mientras que los verbos ayudan a reconocer las operaciones que estos deben realizar.

Por ejemplo, consideremos la siguiente descripción de un sistema bancario:

> El programa debe administrar la cuenta de ahorros de un cliente. El cliente puede depositar y retirar fondos, mientras que el banco debe calcular y pagar intereses trimestralmente.

A partir de esta descripción, pueden identificarse los siguientes elementos:

**Objetos potenciales:**
- Cuenta de ahorros.
- Cliente.

**Operaciones potenciales:**
- Depositar fondos.
- Retirar fondos.
- Pagar intereses.

Las operaciones identificadas podrían formar parte de la clase `Cuenta_De_Ahorros`. Sin embargo, todavía no es posible determinar qué funcionalidades tendría la clase `Cliente`, pues sería necesario analizar el resto de los requisitos del programa. Incluso podría ocurrir que este último no necesitara representarse mediante una clase independiente.

Por lo tanto, la identificación de sustantivos y verbos funciona únicamente como un punto de partida. No todos los sustantivos representan objetos necesarios y no todos los verbos se convierten necesariamente en operaciones. La selección depende de las necesidades específicas del problema.

Además, el dominio de solución no está formado exclusivamente por objetos que representan elementos del mundo real. También incluye **objetos propios de la aplicación**, cuya función es facilitar el desarrollo y funcionamiento del programa. Algunos ejemplos son las ventanas, los menús y los elementos que responden a las acciones del usuario, como los clics del ratón. Estos objetos suelen estar disponibles en bibliotecas de clases, por lo que pueden reutilizarse sin necesidad de desarrollarlos desde cero.

## Paso 2: Determinar Las Relaciones Entre Los Objetos

Una vez identificados los objetos y sus operaciones, el siguiente paso consiste en analizar cómo se relacionan entre sí. En particular, se debe determinar si algunas clases pueden vincularse mediante herencia o composición.

Estas relaciones permiten reutilizar código, simplificar la estructura del programa y representar de manera más adecuada los elementos del problema.

Por ejemplo, un sistema bancario podría necesitar diferentes tipos de cuentas de ahorro: una para clientes generales, otra para clientes preferentes y una más para menores de edad. Si todas comparten las características y operaciones fundamentales de una cuenta de ahorro, resulta conveniente establecer una relación de herencia.

Para ello, se puede desarrollar primero una clase base denominada `Cuenta_De_Ahorros`, que contenga las características comunes. Posteriormente, se pueden definir clases derivadas que incorporen las particularidades de cada tipo de cuenta, evitando repetir las funcionalidades que ya se encuentran implementadas en la clase base.

Por otro lado, la composición se utiliza cuando un objeto está formado por otros objetos pertenecientes a clases diferentes. Un ejemplo de esto fue la clase `Entrada`, desarrollada anteriormente, que contiene objetos de las clases `Nombre` y `Tiempo` como parte de sus atributos privados.

## Paso 3: Diseñar El Controlador

La última etapa consiste en diseñar el **controlador**, es decir, el algoritmo de nivel superior encargado de coordinar el funcionamiento general del programa. Su responsabilidad es organizar la interacción entre los objetos y determinar qué operaciones deben ejecutarse para resolver el problema.

Al implementar un diseño orientado a objetos en C++, el controlador se representa generalmente mediante la función `main()`, que suele encontrarse en el archivo `main.cpp`.

En este archivo se desarrolla el código que utiliza las clases previamente implementadas: se crean los objetos necesarios, se reciben los datos de entrada y se invocan sus funciones miembro de acuerdo con las necesidades del programa. Por esta razón, el controlador también forma parte del código cliente, ya que utiliza los servicios que ofrecen las distintas clases.

Es importante distinguir que el controlador no se encarga de implementar nuevamente las operaciones de cada objeto. Su función consiste en coordinar su utilización y delegar las tareas correspondientes. De esta manera, cada clase conserva la responsabilidad de administrar sus propios datos y proporcionar las operaciones necesarias.

Esto permite apreciar una diferencia importante entre el diseño estructurado y el diseño orientado a objetos. El primero comienza desarrollando el algoritmo general del programa y posteriormente organiza sus acciones en funciones. En cambio, el diseño orientado a objetos comienza identificando los objetos y definiendo sus operaciones, para finalmente construir el controlador que coordina su funcionamiento.

Como resultado, gran parte de la lógica del programa ya se encuentra distribuida entre las funciones miembro de las distintas clases, por lo que el controlador suele tener una estructura relativamente sencilla: recibe información, interpreta las acciones que deben realizarse y solicita a los objetos correspondientes que ejecuten las operaciones necesarias.

