#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char ** argv) {
int i;
int pid = getpid();
for (i = 0; i < 10; i++) {
sleep(1);
printf("slow %6d : %d\n", pid, i);
fflush(NULL);
}
return 0;
}