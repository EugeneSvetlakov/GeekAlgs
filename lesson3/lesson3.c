#define _CRT_SECURE_NO_WARNINGS
#define MaxN 100
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
//Выполнил Светлаков Е.С.
int i;
int j;
int flag;
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
// Распечатываем массив
void print(int N, int *a)
{
    int i;
    for(i = 0; i < N; i++)
        printf("%6i", a[i]);
    printf("\n");
}
int Rnd100(){
	return(rand() % 100 + 1);
}
    
int RndN(int N){
	return(rand() % N + 1);
}

int bsort(int N, int *a){
    int count = 0;
    for(i = 0; i < N; i++){
        for(j = 0; j < N - 1; j++){
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
            count++;
        }
    }
    return(count);
}
int bsort_opt(int N, int *b){
    int count = 0;
    for(i = 0; i < N; i++){
        flag = 0;
        for(j = 0; j < N - 1; j++){
            if (b[j] > b[j + 1])
            {
                swap(&b[j], &b[j + 1]);
                flag = 1;
            }
            count++;
        }
        if (flag == 0) {
            break;
        }
    }
    return(count);
}

int shsort(int N, int *c){
    int count = 0;
    for(i = 0; i < N; i++){
        if (i % 2 == 0){
            for(j = 0; j < N - 1; j++)
            {
                if (c[j] > c[j + 1])
                {
                    swap(&c[j], &c[j + 1]);
                }
                count++;
            }
        } 
        else {
            for(j = N - 1; j > 0; j--){
                if (c[j - 1] > c[j])
                {
                    swap(&c[j], &c[j - 1]);
                }
                count++;
            }
        }
    }
    return(count);
}

int shsort_opt(int N, int *c){
    int L = 0, R = N - 1;
    int flag;
    int count = 0;
    for(i = 0; i < N; i++){
        flag = 0;
        if (i % 2 == 0){
            for(j = L; j < R; j++)
            {
                if (c[j] > c[j + 1])
                {
                    swap(&c[j], &c[j + 1]);
                    flag = 1;
                }
                count++;
            }

        } 
        else {
            for(j = R; j > L; j--){
                if (c[j - 1] > c[j])
                {
                    swap(&c[j], &c[j - 1]);
                    flag = 1;
                }
                count++;
            }
        }
        if (flag == 0) {
            break;
        }
        if (i % 2 == 0){
            R--;
        }
        else {
            L++;
        }
        count++;
    }
    return(count);
}

int findVal(int value, int *a, int SizeArr){
    int Left = 0, Right = SizeArr - 1;
    int m = Left + (Right - Left) / 2;
    while(Left <= Right && a[m] != value)
    {
        if (a[m] < value) 
            {
                Left = m + 1;
            }
        else 
            {
                Right = m - 1;
            }
        m = Left + (Right - Left) / 2;
    }
    if (a[m] == value)
        {
            return(m);
        }
    else
        {
            return(-1);
        }
}
int main() {
	setlocale(LC_ALL, "Rus");
//1. Попробовать оптимизировать пузырьковую сортировку. 
//Сравнить количество операций сравнения оптимизированной и неоптимизированной программы. 
//Написать функции сортировки, которые возвращают количество операций.
//srand(time(NULL));
int NN = 500000;
int a[NN];
int b[NN];
int c[NN];
int d[NN];
int N;
//Запись массива в файл
// int val = NN / 10;
// FILE *out;
// out = fopen("//home//advuser//Документы//Обучение Geekbrains//Algoritms//dz//lesson3//data.txt","a"); 
// for(i = 0; i < NN; i++)
// {
//     fprintf(out, "%8i", RndN(val));
// }
// fclose(out);

//Чтение массива из файла
FILE *in;
in = fopen("//home//advuser//Документы//Обучение Geekbrains//Algoritms//dz//lesson3//data.txt","r");
for(i = 0; i < NN; i++)
{
    fscanf(in, "%i", &a[i]);
}
fclose(in);
in = fopen("//home//advuser//Документы//Обучение Geekbrains//Algoritms//dz//lesson3//data.txt","r");
for(i = 0; i < NN; i++)
{
    fscanf(in, "%i", &b[i]);
}
fclose(in);
in = fopen("//home//advuser//Документы//Обучение Geekbrains//Algoritms//dz//lesson3//data.txt","r");
for(i = 0; i < NN; i++)
{
    fscanf(in, "%i", &c[i]);
}
fclose(in);
in = fopen("//home//advuser//Документы//Обучение Geekbrains//Algoritms//dz//lesson3//data.txt","r");
for(i = 0; i < NN; i++)
{
    fscanf(in, "%i", &d[i]);
}
fclose(in);
// printf("Массив до сортировки:\n");
// print(MaxN, a);
//Сортировка не оптимизированным алгоритмом
int count1 = bsort(NN, a);
// printf("\nМассив после сортировки не оптимизированным пузырьковым алгоритмом):\n");
// print(MaxN, a);
//Улучшенный алгоритм сортировки
int count2 = bsort_opt(NN, b);
// printf("\nМассив после сортировки оптимизированным пузырьковым алгоритмом:\n");
// print(MaxN, b);
//Шейкерный алгоритм сортировки
int count3 = shsort(NN, c);
// printf("\nМассив после сортировки шейкерным алгоритмом:\n");
// print(MaxN, c);
//Шейкерный оптимизированный алгоритм сортировки
int count4 = shsort_opt(NN, d);
// printf("\nМассив после сортировки шейкерным оптимизированным алгоритмом:\n");
// print(NN, d);
//Вывод количества операций сортировки разными методами
printf("\nКоличество операций сортировки не оптимизированным пузырьковым алгоритмом: %d", count1);
printf("\nКоличество операций сортировки оптимизированным пузырьковым алгоритмом: %d", count2);
printf("\nКоличество операций сортировки шейкерным алгоритмом: %d", count3);
printf("\nКоличество операций сортировки шейкерным оптимизированным алгоритмом: %d", count4);

//3. Реализовать бинарный (половинного деления) алгоритм поиска в виде функции, которой передаётся отсортированный массив. 
//Функция возвращает индекс найденного элемента или –1, если элемент не найден.
// int value = a[15];
// printf("\nЭлемент = %d в массиве имеет индекс: %d",value,findVal(value, a, NN));

//2. *Реализовать шейкерную сортировку.

//4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.
return 0;
}