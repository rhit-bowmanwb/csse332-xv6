#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int sleep_time;
    if(argc <= 1){
    fprintf(2, "usage: sleep <number>\n");
    exit(0);
    }
    sleep_time = atoi(argv[1]);
    sleep(sleep_time);
    exit(0);
}