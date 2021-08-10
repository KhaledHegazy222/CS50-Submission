#include <stdio.h>
#include <cs50.h>
int main(void){
    long number = get_long("Number: ");
    long test = number;
    long test2 = number;
    int n = 0;
    int last_digit;
    int last_2_digits;
    while(test >0){
        test /=10;
        n++;
    }
    int sum=0;
    for(int i = 1;i<=n;i++){
        if(i % 2 == 1 ){
            sum += test2%10;
        }
        else if( test2%10 >= 5){
            sum += 1 + ((test2%10)*2)%10; 
        }
        else {
            sum+=2*(test2 %10);
        }
        if(i == n-1){
            last_2_digits = test2;
        }
        if(i == n){
            last_digit = test2;
        }
        test2 /= 10;
    }
    if( sum %10 != 0){
        printf("INVALID\n");
        return 0;
    }
    
    if ( (n >= 13 && n <=16) && last_digit == 4 ){
        printf("VISA\n");
    }
    else if ( n ==15 && (last_2_digits == 34 || last_2_digits == 37) ){
        printf("AMEX\n");
    }
    else if(n == 16 && last_2_digits >=51 && last_2_digits  <=55 ){
        printf("MASTERCARD\n");
    }
    else{
        printf("INVALID\n");
    }
    return 0;

}