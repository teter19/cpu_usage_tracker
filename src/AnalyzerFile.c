#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void * Analyzer_function(void *arg){

    int * iptr = (int*)arg;
    /*int i;
    printf("outputAnalyzer: ");
    for (i=0; i<10; i++){
    printf("%d ", *(iptr+i));
    }*/
    int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    user = *(iptr);
    nice = *(iptr+1);
    system =*(iptr+2);
    idle = *(iptr+3);
    iowait = *(iptr+4);
    irq = *(iptr+5);
    softirq = *(iptr+6);
    steal = *(iptr+7);
    guest = *(iptr+8);
    guest_nice = *(iptr+9);

    //printf("aaaaaaaaaaaaaaa %d ", guest_nice);

    //calculations
    //formula:
    //https://supportcenter.checkpoint.com/supportcenter/portal?eventSubmit_doGoviewsolutiondetails=&solutionid=sk65143&t=1635789403266&fbclid=IwAR1aRQ3aLA_Oc3cBju3zBV-bcGY9_O-6ufXEeHhFsCA8R5GR1_Z2xkvztIw
    float Average_Idle_percentage;

    Average_Idle_percentage = (idle *100)/(user + nice + system + idle + iowait + irq + softirq);
    printf("aaaaaaaaaaaaaaa %f ", Average_Idle_percentage);






}