#include<iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include<string>

#include <omp.h>

using namespace std;

string intro="OMP- Open MultiProcessing API used to explicitly direct multi-threaded, shared memory parallelism. \nLINUX- export OMP_NUM_THREADS=8\n g++ filename.cpp -fopenmp -o filename.exe \n";

int main(int argc, char *argv[]) {

 int nthreads, tid;


 /* Fork a team of threads with each thread having a private tid variable */
 #pragma omp parallel private(tid)
   {

   /* Obtain and print thread id */
   tid = omp_get_thread_num();
   printf("Hello World from thread = %d\n", tid);

   /* Only master thread does this */
   if (tid == 0) 
     {
     nthreads = omp_get_num_threads();
     printf("Number of threads = %d\n", nthreads);
     }

   }  /* All threads join master thread and terminate */
 return 0;
 }