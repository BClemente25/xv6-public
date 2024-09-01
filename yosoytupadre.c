#include "types.h"
#include "user.h"

int main() {
    // Llama a la syscall getppid() y guarda el ID del proceso padre del proceso actual
    int ppid = getppid();
    printf(1, "El ID del proceso padre es: %d\n", ppid);

    // getancestor explicado en sysproc.c

    int ancestro_0 = getancestor(0);
    int ancestro_1 = getancestor(1);
    int ancestro_2 = getancestor(2);
    int ancestro_invalid = getancestor(10); // Toma un ancestor más legano y compreba si exite o no, devolviendo un -1 
    // si es que no existe

    // Imprime los resultados de cada llamada a getancestor
    printf(1, "Ancestro 0 (mismo proceso): %d\n", ancestro_0);
    printf(1, "Ancestro 1 (padre): %d\n", ancestro_1);
    printf(1, "Ancestro 2 (abuelo): %d\n", ancestro_2);
    printf(1, "Ancestro inválido: %d\n", ancestro_invalid);

    exit();
}