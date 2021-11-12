#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/sysinfo.h>

void * Printer_function(void *arg){

    float * Average_Idle_percentage=(float *)malloc(sizeof(float));
    Average_Idle_percentage=arg;
    int i;
    int cores = get_nprocs()+1;

    printf("usage: %f % \n",*Average_Idle_percentage);
    return 0;
}