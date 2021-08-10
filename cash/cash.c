#include <stdio.h>
#include <cs50.h>
int main(void){
    float x;
    do{
        x =get_float("Change Owed: ");
    }
    while(x <= 0);
        x+=0.00001;

    int j=0;
    int i = x*100;
    printf("i = %i",i);
    while(i >= 25){
        i -=25;
        j++;
        printf("25\n");
    }
    while(i >= 10){
        i -=10;
        j++;
        printf("10\n");
    }
    while(i >= 5){
        i -=5;
        j++;
        printf("5\n");
    }
    while(i >= 1){
        i -=1;
        j++;
        printf("1\n");
    }
    printf("%i\n",j);
}
