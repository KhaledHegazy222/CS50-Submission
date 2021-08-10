#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int main(int argc,string argv[]){
    if(argc != 2){
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    for(int i = 0,n=strlen(argv[1]);i<n;i++){
        if (  !( (argv[1][i]>=65 && argv[1][i]<=90)  || (argv[1][i]>=97 && argv[1][i]<=122 ) ) ){
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }
    string s = get_string("plaintext: ");
    int k;
    printf("ciphertext: ");
    for(int i=0,j=0;i<strlen(s);i++,j++){
        if(j == strlen(argv[1])){
            j = 0;
        }
        k=0;
        if( argv[1][j]>=97  && argv[1][j] <= 122 ){
            k = argv[1][j] - 97;
        }
        else if( argv[1][j]>=65  && argv[1][j] <= 90  ){
            k = argv[1][j] - 65;

        }
        else {
            k=0;
        }


        if(k+s[i]>122 ){
                k-=26;
            }
        else if(k+s[i]>90 && s[i] <= 90){
                k-=26;
            }


        if( ( s[i]>=65 && s[i]<=90)  || (s[i]>=97 && s[i]<=122 )){
            printf("%c",k+s[i]);
        }
        else {
            printf("%c",s[i]);
            j--;
        }
    }
    printf("\n");
}
