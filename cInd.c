#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *string;
int countNum;
int number[100];

// Сдвиг влево массива чисел, начиная с позиции numToShift
void numShift(int *numMass, int numToShift) { 
	for (int i = numToShift; i < countNum-1;i++)
	{	
		numMass[i] = numMass[i+1];
	}
	countNum--;
}

// Сдвиг влево массива символов, начиная с позиции symToShift
void symShift(char *symMas, int symToShift) {
	int i;
	for ( i = symToShift; i < strlen(symMas)-1;i++)
	{	 
		symMas[i] = symMas[i+1];
	}
	symMas[i]='\0';
	}

// Режет строку на числа
void tokenize(char *string) {

	int i=0;
    char *token;
	token = strtok(string, "+-*/");

	while( token != NULL ) {
		number[i] = atoi(token);
		i++;
		token = strtok(NULL, "+-*/");
	}
	
   countNum=i;
}


void main (int argc, char *argv[]) {    	 
   if (argc == 1 ) printf("Вы не ввели вычисляемое выражение\n");
   else if (argc == 2 ) {	
		string = argv[1];
		char checkStr[100];
		
		// Записывает строку из argv в массив символов
		for(int i = 0; i<strlen(argv[1])+1; i++)
		{
			checkStr[i] = (char)argv[1][i];
		}
		
		// Обрезаем строку
		tokenize(string);

		int i=0;
		int j=0;
		char symbols[countNum-1];
		while (checkStr[i++]!='\0'){	
			if (checkStr[i]=='*'||checkStr[i]=='/'||checkStr[i]=='+'||checkStr[i]=='-') { 
				symbols[j]= (char)checkStr[i]; 
				j++;
			}
		}
		symbols[j] = '\0';
		
		while (symbols[0]!='\0')
		// Вычисление умножения и деления
	{	i = 0;
		while(symbols[i] != '\0') {
			if (symbols[i] == '*') { 
				number[i]= number[i] * number[i+1];
				numShift(number, i + 1);
				symShift(symbols, i);
				
			}else
			if (symbols[i] == '/') { 
				number[i] = number[i] / number[i+1];
				numShift(number, i + 1);
				symShift(symbols, i);
				
			}
			i++;
		}

		// Вычисление сложения и вычитания
		i = 0;
		while(symbols[i] != '\0') {
			if (symbols[i] == '+') { 
				number[i] = number[i] + number[i+1];
				numShift(number, i + 1);
				symShift(symbols, i);
				
			}else
			if (symbols[i] == '-') { 
				number[i] = number[i] - number[i+1];
				numShift(number, i + 1);
				symShift(symbols, i);
				
			}
			i++;
		}
}
		printf("%s=%i\n", checkStr,number[0]);
	} else {
		// Добавить функцию слития всех argv в один string
		printf("Напишите выражение слитно");
	}
}
	
