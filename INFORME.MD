Funcionamiento de las systemcalls:

El funcionamiento de estas esta detallado en sysproc.c con comentarios 

Archivos Modificados:

sysproc.c: Se agregaron las funciones sys_getppid() y sys_getancestor() para implementar la lógica de las llamadas al sistema.

syscall.h: Se definieron los números de las nuevas llamadas al sistema (SYS_getppid y SYS_getancestor).

syscall.c: Se actualizaron las tablas de syscalls para incluir las nuevas llamadas.

usys.S: Se añadieron los stubs para getppid y getancestor, permitiendo que las funciones sean llamadas desde programas de usuario.

Pasos Realizados:

Se definen los números de las nuevas syscalls en syscall.h

Después se añaden las funciones de implementación (sys_getppid y sys_getancestor) en sysproc.c

Se actualizan las tablas de syscalls en syscall.c para que el kernel reconozca las nuevas funciones

Añado las entradas correspondientes en usys.S

Y por ultimo modifico el Makefile para que se puedan ejecutar las syscalls

Archivos Agregados:

yosoytupadre.c: Archivo de prueba que consulta getancestors 0, 1 y 2, además de consultar un ancestro 10

Dificultades encontradas:

Practicamente tuve que instalar xv6 de nuevo e instalar xv6-public, debido a que como lo tenia antes no parecia poder ejecutar el programa

Tuve que ver muchos tutoriales para poder saber donde cambiar y agregar cosas, cosa que me llevo a equivocarme varias veces hasta
llegar a una buena ejecucion

