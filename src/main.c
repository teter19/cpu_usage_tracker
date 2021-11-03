#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "ReaderFile.c"
#include "AnalyzerFile.c"

int main(){ 
 pthread_t Reader,Analyzer;
 int *result; //this can store a ponter to anything, like struct etc
 //in my case i will return char table with 9 columns
 int i;
 int *result2;

 pthread_create(&Reader, NULL, Reader_function, NULL);
 pthread_join(Reader,(void *)&result);
 /*for (i=0; i<11; i++){
   printf("output: %d", *(result+i));
 }*/

 pthread_create(&Reader, NULL, Analyzer_function, (void *)result);
 pthread_join(Reader,(void *)&result2);
 /*for (i=0; i<11; i++){
  printf("output2: %d", *(result2+i));
 }*/
 //Reader();
  return 0;
}
