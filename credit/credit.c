#include <stdio.h>
#include <cs50.h>
#include <string.h>
int main(void){
    long long number = get_long_long("Number:");
    long long test = number;
    int counter = 0;
    long long recent = number;
    int last_2_digits=0,last_digit=0;
    while (test >= 1){
        counter++;
        test /=10;
    }
    long long last;
    int j=1;
    int d;
    int sum=0;
    while(recent >=1){
        last = recent;
        last %= 10;
        if(j%2==1){
            sum += last;
        }
        else if(last < 5) {
            sum += 2*last;
        }
        else {
          d = 2*last;
          sum += (d/10) + (d%10);
        }
        j++;
        recent /= 10;
        if(j == counter -1){
            last_2_digits = recent;
        }
        if(j == counter  ){
            last_digit = recent;
        }

    }

   if(sum % 10 == 0){
        if(last_2_digits == 34 || last_2_digits == 37){
            printf("AMEX\n");
        }
        else if ( last_digit == 4 && ( (counter >= 13) && (counter <= 16) )   ){
            printf("VISA\n");
        }
        else if (last_2_digits == 51 || last_2_digits == 52 || last_2_digits == 53 || last_2_digits == 54 || last_2_digits == 55){
            printf("MASTERCARD\n");
        }
        else {
            printf("INVALID\n");
        }
    }
    else {
        printf("INVALID\n");
    }
}
