#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/sysinfo.h>
void* Reader_function(void *arg){
    char path[] = "/proc/stat";
    FILE * stat;
    stat = fopen(path, "r");

    char cpu[5];

    int i;
    int **pointer_to_arrays=(int**)malloc((get_nprocs()+1)*sizeof(int*)); //tablica wskaznikow na tablice malloca patrz wyzej cwelu
    
    for (i=0; i<get_nprocs()+1; i++){

    int *iptr = (int *)malloc(10*sizeof(int));
    pointer_to_arrays[i]=iptr;

    fscanf(stat, "%s %d %d %d %d %d %d %d %d %d %d",&cpu, 
    &iptr[0],&iptr[1],&iptr[2],&iptr[3],
    &iptr[4],&iptr[5],&iptr[6],
    &iptr[7],&iptr[8],&iptr[9]);
    }

    fclose(stat);
    return pointer_to_arrays;
    
}