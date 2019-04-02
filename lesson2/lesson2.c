#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 100
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
//Выполнил Светлаков Е.С.
int bin[ARR_SIZE] = {0};
int size = 0;
int a;

void tobin(long N){
    if(N > 0){
        bin[size] = N % 2;
        //printf("%ld",bin[size]);
        size++;
        tobin(N/2);
    } 
}
void printBin(int size){
    while(size >= 0){
        printf("%ld",bin[size]);
        size--;
    }
}
long pow(int a, int b){
    long c = 1;
    while(b){
        c *= a;
        b--;
    }
    return c;
}
long powR(int a, int b){
    if(b>1){
        return a * powR(a,b-1);
    } else {
        return a;
    }
}
long pow2R(int a, int b){
    if(b % 2 == 0){
        return powR(a,2) * powR(a,b / 2);
    } else {
        return powR(a,b);
    }
}
int main() {
	setlocale(LC_ALL, "Rus");
//1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
	tobin(14);
 printBin(size-1);
//2. Реализовать функцию возведения числа a в степень b:
//Без рекурсии.
    int a = 2;
    int b = 5;
printf("\nБез ркурсии: %d ^ %d = %ld",a,b,pow(a,b));
//рекурсивно
printf("\nРекурсивно: %d ^ %d = %ld",a,b,powR(a,b));
//Рекурсивно используя свойство четности степени
    printf("\nРекурсивно, используя св-во четности: %d ^ %d = %ld",a,b,pow2R(a,b));
return 0;
}