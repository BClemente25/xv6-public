#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
  for(int i = 0; i < 20; i++) {
    int pid = fork();
    if(pid == 0) {
      // Proceso hijo
      int priority = getpriority();  // Llamada a la nueva syscall
      printf(1, "Ejecutando proceso %d %d con prioridad %d\n", i, getpid(), priority);
      sleep(50);  // Pausa para que el proceso se detenga unos segundos
      exit();     // Llamada a exit sin argumentos
    }
  }

  for(int i = 0; i < 20; i++) {
    wait();  // Esperar a que todos los hijos terminen
  }

  exit();  // Llamada a exit sin argumentos
}
