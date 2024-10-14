#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
  for(int i = 0; i < 20; i++) {
    int pid = fork();
    if(pid == 0) {
      // Proceso hijo
      int priority = getpriority();  // Obtener la prioridad del proceso
      printf(1, "Se ejecuta el proceso (N°/PID) %d / %d con prioridad %d\n", i, getpid(), priority);
      sleep(50);  // Pausa para que el proceso se detenga unos segundos
      exit();     // Terminar el proceso
    }
  }

  for(int i = 0; i < 20; i++) {
    wait();  // Esperar a que todos los hijos terminen
  }

  exit();  // Terminar el proceso padre
}
