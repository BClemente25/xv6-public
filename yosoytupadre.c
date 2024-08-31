#include "types.h"
#include "user.h"

int main() {
    int ppid = getppid();
    printf(1, "El ID del proceso padre es: %d\n", ppid);
    exit();
}