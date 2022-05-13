#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int
main(int argc, char *argv[])
{
    int p[2][2];
    pipe(p[0]);
    pipe(p[1]);
    write(p[0][1], "s", 1);
    close(p[0][1]);
    int pid = fork();
    if(pid == 0){
        char buf[1];
        read(p[0][0], buf, 1);
        close(p[0][0]);
        write(p[1][1], "s", 1);
        close(p[1][1]);
        printf("%d: received ping\n", getpid());
        exit(0);
    } else{
        char buf[1];
        read(p[1][0], buf, 1);
        close(p[1][0]);
        int status;
        wait(&status);
        printf("%d: received pong\n", getpid());
        exit(0);
    }
}