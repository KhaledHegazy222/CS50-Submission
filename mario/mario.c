#include <cs50.h>
#include <stdio.h>
void pyramid(int x);
int main(void)
{
    int x;
    do {
        x = get_int("Height:");
    }
    while(x < 1 || x > 8);
    pyramid(x);

}

void pyramid(int x){
    for(int i =0;i<x;i++){
        for(int j =x-i-1;j>0;j--){
            printf(" ");
        }
        for(int j=0;j<=i;j++){
            printf("#");
        }
        printf("  ");
        for(int j=0;j<=i;j++){
            printf("#");
        }
        printf("\n");
    }
}
