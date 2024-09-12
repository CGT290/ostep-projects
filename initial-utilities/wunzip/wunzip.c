#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    if(argc < 2){
      printf("wunzip: file1 [file2 ...]\n");
      exit(1);

    }
    int count;
    FILE *fp;
    char c;

    for(int i = 1; i < argc; i++){
      fp = fopen(argv[i], "r");


      if(fp == NULL){
              printf("wunzip: cannot open file\n");
              exit(1);
    }

      while(fread(&count, sizeof(int), 1, fp) == 1){
            if(fread(&c, sizeof(char),1,fp) != 1){
             printf("wunzip: file is  malformed\n");
             exit(1);
        }

           
        for(int k = 0; k < count; k++){

                    printf("%c", c);
            }
	    
      }
      fclose(fp);

      }
  
        
        

        return 0;
}
