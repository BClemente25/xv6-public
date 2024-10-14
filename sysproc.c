#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}


// Obtiene un puntero al proceso actual que está ejecutando la llamada al sistema y retorna el id del proceso padre

int
sys_getppid(void)
{
  struct proc *curproc = myproc();
  return curproc->parent ? curproc->parent->pid : -1;
}


 //sys_getancestor funciona parecido a sys_getppid ya que obtiene el proceso actual para asi recorrer hacia atras en los procesos
 //hasta que encuentra un ancestro y lo devuelve a la funcion, dando un -1 si es que no encuentra suficientes ancestros
 // Obtiene el argumento pasado a la syscall, que indica el nivel del ancestro
 // argint(0, &n) obtiene el primer argumento entero (índice 0) y lo guarda en 'n'
 // Recorre la cadena de procesos padres hasta encontrar el ancestro especificado
int
sys_getancestor(void)
{
    int n;
    struct proc *p = myproc();
    if (argint(0, &n) < 0)
        return -1;
    while (n > 0 && p->parent) {
        p = p->parent;
        n--;
    }
    return n == 0 ? p->pid : -1;
}

int
sys_getpriority(void)
{
  struct proc *p = myproc(); // Obtener el proceso actual
  return p->priority;        // Retornar la prioridad del proceso
}