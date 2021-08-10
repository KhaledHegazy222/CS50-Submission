#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Missing Command Line Arguments\n");
        return 1;
    }
    FILE *read = fopen(argv[1],"r");
    char *name = malloc(8);
    BYTE data[512];
    bool state = false;
    FILE *write = NULL;
    int l = 0;
    int n;
    do{
        n = fread(data,1,512,read);
        if( data[0] == 0xff  && data[1] == 0xd8  && data[2] == 0xff  && (data[3] & 0xf0) == 0xe0 ){
            if(state == true){
                fclose(write);
                l++;
                sprintf(name,"%03i.jpg",l);
                write = fopen(name,"w");

            }
            else {
                sprintf(name,"%03i.jpg",l);
                write  = fopen(name,"w");
                state = true;

            }
        }

        if(n < 512){
            fwrite(data,1,n,write);
            break;
        }
        if( state == true){
            fwrite(data,1,512,write);
        }


    }
    while(true);
    free(name);
    free(write);
    fclose(write);
    fclose(read);

}
