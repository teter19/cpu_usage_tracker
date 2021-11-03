#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/*// Guest time is already accounted in usertime
usertime = usertime - guest;                             # As you see here, it subtracts guest from user time
nicetime = nicetime - guestnice;                         # and guest_nice from nice time
// Fields existing on kernels >= 2.6
// (and RHEL's patched kernel 2.4...)
unsigned long long int idlealltime = idletime + ioWait;  # ioWait is added in the idleTime
unsigned long long int systemalltime = systemtime + irq + softIrq;
unsigned long long int virtalltime = guest + guestnice;
unsigned long long int totaltime = usertime + nicetime + systemalltime + idlealltime + steal + virtalltime;
*/

void cpu_usage_tracker (){
    printf("\n file cpu tracker");
}

/*int i=0;
void *myTurn(void *arg){
  int *iptr = (int *)malloc(sizeof(int));
*iptr=5;

  for(i;i<10; i++){
    sleep(1);
    printf("\nMy turn"); 
  }
  return iptr;
}*/
int Reader(){
    //char path[] = "/proc/stat";
    char path[] = "/proc/stat";
    FILE * stat;
    stat = fopen(path, "r");
    int numbers[3];
    char cpu[5];

    int *itr = (int *)malloc(sizeof(int));

    //buffer for reading data from file
    char buffer_stat_in[256], buffer_stat_out[256];

    fscanf(stat, "%s %d %d %d",&cpu, &numbers[0],&numbers[1],&numbers[2]);
    printf("aaaaaaa %s %d %d %d",cpu, numbers[0],numbers[1],numbers[2]);
    /*int i=0;
void *myTurn(void *arg){
  int *iptr = (int *)malloc(sizeof(int));
*iptr=5;

  for(i;i<10; i++){
    sleep(1);
    printf("\nMy turn"); 
  }
  return iptr;
}*/
    /*if (stat==NULL){
        return 1;
    }
    else {
        for (i =0; i<3; i++){
            fscanf(stat, "%d ",&numbers[i]);
        }
        
        
    }
    for (i =0; i<3; i++){
            printf("aaaaaaa %d ",&numbers[i]);
        }*/

    //while (!feof(stat)){
        //fgets(buffer_stat_in, 256,stat);
        //printf("/prot/stat file output %d\n",&buffer_stat_in);
    //}
    //check if it is possible to read file
    /*if (fgets(buffer_stat_in, 256, stat)==NULL){
        fclose(stat);
        return 1;
    }*/

    //sscanf_s(buffer_stat_in,"%c %d %d %d %d %d %d %d %d %d %d\n",buffer_stat_out);
    //sscanf(buffer_stat_in,"%c %d %d",&buffer_stat_out);
    //printf("/prot/stat file output %c %d %d",buffer_stat_out);

    fclose(stat);


}