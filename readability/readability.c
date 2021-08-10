#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
int main(void){
    string s = get_string("Text: ");
    int letters = 0;
    float words = 1;
    int sentences = 0;
    
    for(int i = 0 ,n = strlen(s);i<n;i++){
        if( (s[i] >= 65 && s[i] <=90 ) || (s[i] >= 97 && s[i] <=122 )){
            letters++;
        }
        if(s[i] == 32){
            words++;
        }
        if(s[i] == 63 ||s[i] == 33 ||s[i] == 46){
            sentences++;
        }
    }
    float index = 0.0588 * ( (letters / words)*100 ) - 0.296 * (sentences / words ) * 100 - 15.8;
    int l = round(index);
    if(l > 16) {
        printf("Grade 16+\n");
    }
    else if(l <1){
        printf("Before Grade 1\n");
    }
    else {
        printf("Grade %i\n",l);
    }
}