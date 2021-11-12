#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "ReaderFile.c"
#include "AnalyzerFile.c"
#include "PrinterFile.c"

int main(){ 
 pthread_t Reader,Analyzer[get_nprocs()+1], Printer[get_nprocs()+1];
 int **result;
 pthread_t Analyzer1;
 int i,j;
 int **result2[get_nprocs()+1];
 int **result3[get_nprocs()+1];
while(1){
 sleep(1);
 pthread_create(&Reader, NULL, Reader_function, NULL);
 pthread_join(Reader,(void *)&result);

 //creating get_nproc()+1 threads for Analyzer and Printer
 for (i=0; i<get_nprocs()+1; i++){
 pthread_create(&Analyzer[i], NULL, Analyzer_function, (void *)(*(result+i)));
 pthread_join(Analyzer[i],(void *)&result2[i]);
 if (i==0){
   printf("Whole Average Percentage ");
  pthread_create(&Printer[i], NULL, Printer_function,(void*)result2[i]);
  pthread_join(Printer[i],(void*)&result3[i]);
  
 } 

 else{
 printf("Core%d ",i-1);
 pthread_create(&Printer[i], NULL, Printer_function,(void*)result2[i]);
 pthread_join(Printer[i],(void*)&result3[i]);
 }

 }


 

}
 pthread_exit(NULL);
  return 0;
}
