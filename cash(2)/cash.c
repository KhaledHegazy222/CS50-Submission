#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void){
    float change;
    do {
        change = get_float("Change owed: ");
    }
    while(change <0);
        
    int x = round(change * 100);
    int n = 0;
    while (x >= 25){
        n++;
        x-=25;
    }

    while (x >= 10){
        n++;
        x-=10;
    }

    while (x >= 5){
        n++;
        x-=5;
    }

    while (x >= 1){
        n++;
        x-=1;
    }
    printf("%i\n",n);

}