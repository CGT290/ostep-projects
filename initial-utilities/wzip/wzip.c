#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    if(argc < 2){
      printf("wzip: file1 [file2 ...]\n");
      exit(1);
    }

    FILE *fp;
    int count = 0;
    char character;
    char last_char;
    int first_char = 1;

    for(int i = 1; i < argc; i++){
       fp = fopen(argv[i], "r");

       if(fp == NULL){
         printf("wzip: cannot open file\n");
         exit(1);
       }


     while((character = fgetc(fp)) != EOF){
          if(first_char){
            last_char = character;
            count = 1;
            first_char = 0;
          }else{

          if(character == last_char){
            count++;
          }else{
            fwrite(&count, sizeof(int), 1, stdout);
            fwrite(&last_char, sizeof(char), 1, stdout);

            last_char = character;
            count = 1;
          }

          }
     }

     fclose(fp);

     

    }
     if(!first_char){
      //printf("write: %d of %c' (l write)\n", count,last_char);
      fwrite(&count, sizeof(int), 1, stdout);
      fwrite(&last_char, sizeof(char), 1, stdout);
    } 
    
return 0;
}


