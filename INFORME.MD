Explicación de las modificaciones realizadas:


Archivos modificados:


Proc.h: Implementacion de los campos boost y priority
sysproc.c: incorporacion de la funcion para obtener la prioridad de un proceso
syscall.h, syscall.c, user.h y usys.S: declaracion de la llamda al sistema de SYS_getpriority
proc.c: Cambio en el scheduler para implementar logica de prioridad y boost. Además en allocproc se inicializa los valores de boost y priority
Makefile: cambiar numero de CPU's de 3 a 1 ya que presenta problemas con los procesos

Archivos creados:


test_priority: programa de prueba que crea 20 forks en que tienen un nombre y pid determinado


Funcionamiento y lógica del sistema de prioridades:


El funcionamiento es simple, al utilizar el programa "test_priority" se crean 20 forks con nombre y pid unico para cada uno de ellos a lo cual el scheduler recorre los procesos que tengan el estado RUNNABLE para implementar la logica p->priority += p->boost que actualiza las prioridades dependiendo del boost que se tenga y como se inicia siempre en boost 1 y prioridad 0 al principio siempre se incrementa la prioridad para despues actualizar el boost a -1 o 1 dependiendo si la prioridad del proceso es 9 o 0 respectivamente y por ultimo se selecciona el proceso con mayor prioridad para asi volver al ciclo for hasta que se terminen los 20 forks.


Dificultades encontradas y soluciones implementadas:

Intenté implementar una logica que intenta mostrar primero los procesos con mayor prioridad (más que nada porque creí que eso me pedia el enunciado) pero terminé renunciando a esa idea y ahora cada que intento quitar las implementaciones de esto en el scheduler me tira error, por lo que es un error en la logica que no aun no puedo solucionar.

Otro problema que se presenta es que en la salida del programa de prueba los procesos se escriben sobre otros y se muestran de manera aleatoria, le pregunte al profesor que podria hacer con ello y me dijo que el problema podria estar con los diferentes CPU's que se inicializan por lo que cambie esta configuracion de 3 a 1 en el makefile pero el error no se soluciona.