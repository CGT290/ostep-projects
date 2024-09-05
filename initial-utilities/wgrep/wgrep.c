#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFFER_SIZE 512

int main( int argc, char *argv[]){
   if(argc < 2){
      printf("wgrep: searchterm [file ...]\n");
      exit(1);
   }

   char buffer[BUFFER_SIZE];
   char *targetTerm = argv[1];

   FILE *fp;

   if(argc == 2){
     while(fgets(buffer,BUFFER_SIZE, stdin) != NULL){
       if(strstr(buffer, targetTerm) != NULL){
         printf("%s", buffer);
       }
     }

   } else {
     for(int i = 2; i < argc; i++){
     fp = fopen(argv[i], "r");

     if(fp == NULL){
        printf("wgrep: cannot open file\n");
	exit(1);
     }
      
     
     while(fgets(buffer,BUFFER_SIZE, fp) != NULL){
        if(strstr(buffer, targetTerm)!= NULL){
	     printf("%s", buffer);

     } 
     }
      
     fclose(fp);

   }
  }
    return 0;
} 
