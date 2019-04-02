#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h> 
 
 
	double Max3Num(double x1, double x2, double x3) 
	{
		double max = x1;
		if(max<x2) {
			max = x2;
		}
		if(max<x3) {
			max = x3;
		}
		return max;
	}
	int Rnd100(){
		
		return(rand() % 100 + 1);
	}
	int RndMy100(){
		
		return(rand() % 100 + 1);
	}
int main() {
	setlocale(LC_ALL, "Rus");
	
	// //Задание № 11: С клавиатуры вводятся числа, пока не будет введён 0. 
	// //Подсчитать среднее арифметическое всех положительных чётных чисел, оканчивающихся на 8.
	// int x;
	// double sum = 0;
	// int count = 0;
	// while(1){
	// 	printf("Введите число ('0' - завершить программу):");
    // 	scanf("%i", &x);
	// 	if(x==0) break;
	// 	if(x > 0 && x % 2 == 0 && x % 10 == 8){
	// 		sum += x;
	// 		count++;
	// 	} 
	// }
	// printf("среднее арифметическое всех положительных чётных чисел, оканчивающихся на 8 равно: %.2f", (sum/count));
	
//Задание №12: Написать функцию нахождения максимального из трёх чисел.
	// double x1;
	// double x2;
	// double x3;
	// printf("Введите x1:");
    // scanf("%lf", &x1);
	// printf("Введите x2:");
    // scanf("%lf", &x2);
	// printf("Введите x3:");
    // scanf("%lf", &x3);
	// printf("Максимальное из 3х чисел = %.2lf",Max3Num(x1, x2, x3));

// Задание №13*: Написать функцию, генерирующую случайное число от 1 до 100: 
	//a. С использованием стандартной функции rand().
	// srand(time(NULL));
	// printf("Случайное число: %i", Rnd100());

	//b. Без использования стандартной функции rand().
	int x, a, b, m;
    m = 100; // Вершина последовательности
    b = 3;
    a = 2;
    x = 2;
    int i;
    int modulus = 100;

    for (i = 0; i < modulus; i++)
    {
        x = (a * x + b) % m;
        printf("%d ", x);
    }

	
	return 0;
}