#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include "Header.h"
using namespace std;

void main()
{
	//generar array 1-100
	srand(time(NULL));
	int numberList[100];

	for (int i = 0; i < 100; i++)
	{
		numberList[i] = i+1;
	}
	printScreen(numberList);
	char myChar;

	do
	{
		scanf_s("%c", &myChar);
	  //for (int y = 0; y < 100; y++)
	//{

		//seleccion de dos numeros distintos de esa lista (a,b)

		int rand1;
		int rand2;

		do
		{
			selectTwoRand(rand1, rand2);
		} while (numberList[rand1] == 0 || numberList[rand2] == 0);

		printf("\n");
		printf("Chosen numbers: %d", numberList[rand1]);
		printf(", %d \n", numberList[rand2]);


		//retirar a,b y añadir a+b-1

		int a;
		int b;
		int r;
		a = numberList[rand1];
		b = numberList[rand2];
		r = numberList[rand1] + numberList[rand2] - 1;
		printf("Result: %d\n", r);

		numberList[rand1] = r;
		numberList[rand2] = 0;

		printScreen(numberList);
	//}
	} while (myChar != '*');

	
}

void printScreen(int list[100])
{
	for (int i = 0; i < 100; i++)
		printf("%3d ", list[i]);
	
}

void selectTwoRand(int &rand1, int &rand2)
{
	rand1 = rand() % 100;

	do
	{
		rand2 = rand() % 100;
	} while (rand1 == rand2);

}