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
int bsort(int N, int *a){
    int count = 0;
    for(i = 0; i < MaxN; i++){
        for(j = 0; j < MaxN - 1; j++){
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
    for(i = 0; i < MaxN; i++){
    flag = 0;
    for(j = 0; j < MaxN - 1; j++){
        if (b[j] > b[j + 1])
        {
            swap(&b[j], &b[j + 1]);
            flag = 1;
        }
    }
    if (flag == 0) {
        break;
    }
    count++;
    }
    return(count);
}
int main() {
	setlocale(LC_ALL, "Rus");
//1. Попробовать оптимизировать пузырьковую сортировку. 
//Сравнить количество операций сравнения оптимизированной и неоптимизированной программы. 
//Написать функции сортировки, которые возвращают количество операций.
//srand(time(NULL));
int a[MaxN];
int b[MaxN];
int N;
FILE *in;
in = fopen("//home//advuser//Документы//Обучение Geekbrains//Algoritms//dz//lesson3//data.txt","r");
for(i = 0; i < MaxN; i++)
{
    fscanf(in, "%i", &a[i]);
}
fclose(in);
in = fopen("//home//advuser//Документы//Обучение Geekbrains//Algoritms//dz//lesson3//data.txt","r");
for(i = 0; i < MaxN; i++)
{
    fscanf(in, "%i", &b[i]);
}
fclose(in);
printf("Массив a[i] до сортировки:\n");
print(MaxN, a);
//Сортировка не оптимизированным алгоритмом
int count1 = bsort(MaxN, a);
printf("\nМассив после сортировки не оптимизированным алгоритмом):\n");
print(MaxN, a);
printf("\nКоличество операций сортировки: %d", count1);
//Улучшенный алгоритм сортировки
int count2 = bsort_opt(MaxN, b);
printf("\nМассив после сортировки оптимизированным алгоритмом:\n");
print(MaxN, b);
printf("\nКоличество операций сортировки: %d", count2);
//3. Реализовать бинарный (половинного деления) алгоритм поиска в виде функции, которой передаётся отсортированный массив. 
//Функция возвращает индекс найденного элемента или –1, если элемент не найден.

//2. *Реализовать шейкерную сортировку.

//4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.
return 0;
}