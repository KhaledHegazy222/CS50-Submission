#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, string argv[]){
    if(argc != 2){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i=0;i<strlen(argv[1]);i++){
        if(argv[1][i] > 60) {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int k = atoi(argv[1]);
    while(k>26){
        k -=26;
    }
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    for(int i =0;i<strlen(text);i++){
        if( ( text[i] >= 65  && text[i] <=90 )    || ( text[i] >=97 && text[i]<=122)  ){
            if(text[i]>96){
                if(text[i]+k > 122){
                    printf("%c",96 + ((text[i] + k)-122));
                }
                else {
                    printf("%c",text[i]+k);
                }

            }
            else{
                if (text[i]+k > 90){
                    printf("%c",64 + ((text[i] + k)-90));
                }
                else {
                    printf("%c",text[i]+k);
                }
            }
        }
        else{
            printf("%c",text[i]);
        }
    }
    printf("\n");
}
