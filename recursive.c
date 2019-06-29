//
// Created by lotha on 2019/6/18.
//

#include <stdio.h>

int factorial(int n);
int fibonacci(int n);
void hanoi(int n, char x, char y, char z);

int main(){
    hanoi(4, 'X', 'Y', 'Z');

    return 0;
}

int factorial(int n){
    if (n==0)
        return 1;
    else
        return n*factorial(n-1);
}

int fibonacci(int n){
    if (n==1)
        return 0;
    else if (n==2)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}

void hanoi(int n, char x, char y, char z){
    if(n==1)
        printf("move %d from %c to %c\n", n, x, z);
    else{
        hanoi(n-1, x, z, y);
        printf("move %d from %c to %c\n", n, x, z);
        hanoi(n-1, y, x, z);
    }
}