#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void* Reader_function(void *arg){
    char path[] = "/proc/stat";
    FILE * stat;
    stat = fopen(path, "r");

    int columns[9];
    char cpu[5];
    int *iptr = (int *)malloc(10*sizeof(int));

    /*fscanf(stat, "%s %d %d %d %d %d %d %d %d %d %d",&cpu, &columns[0],&columns[1],
    &columns[2],&columns[3],&columns[4],&columns[5],&columns[6],
    &columns[7],&columns[8],&columns[9]);
    printf("aaaaaaa %s %d %d %d %d %d %d %d %d %d %d",cpu, columns[0],columns[1],
    columns[2],columns[3],columns[4],columns[5],columns[6],
    columns[7],columns[8],columns[9]);*/

    fscanf(stat, "%s %d %d %d %d %d %d %d %d %d %d",&cpu, 
    &iptr[0],&iptr[1],&iptr[2],&iptr[3],
    &iptr[4],&iptr[5],&iptr[6],
    &iptr[7],&iptr[8],&iptr[9]);

    printf("aaaaa %s %d %d %d %d %d %d %d %d %d %d\n\n",cpu, iptr[0],
    iptr[1],iptr[2],iptr[3],iptr[4],
    iptr[5],iptr[6],iptr[7],iptr[8],
    iptr[9]);
    fclose(stat);
    
    return iptr;
    
}