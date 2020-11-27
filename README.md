# Laba_8




#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define n 10

int main()
{
	int i, k, m = n;
	char* str;

	setlocale(LC_ALL, "Russian"); // я русский

	str = (char*)calloc(n + 1, sizeof(char)); // выделяю память

	if (!str) // проверка 
	{
		printf("Ошибка выделения памяти");
		return 1;
	}

	printf("\nВведите строку из %d символов\n", n);
	fgets(str, n + 1, stdin); // ввод строки

	for(i = 0; i < n; i++)
	{
		if (!(int(str[i]) >= 32 && int(str[i]) <= 126))
		{
			i = 0;
			printf("Вы ввели меньше, чем %d символов\n", n);
			rewind(stdin);
			fgets(str, n + 1, stdin); // ввод строки
		}
	} 

	for (i = 0; i < n; i++) // механизм удаления *
		if (str[i] == '*')
		{
			for (k = i; k < n; k++)
				str[k] = str[k + 1];
			--m;
			--i;
			if (m <= 0)
			{
				printf("Некорректный ввод");
				return 1;
			}

			str = (char*)realloc(str, m); // уменьшаю память после удаления *
			
			if (!str) // проверка 
			{
				printf("Ошибка выделения памяти");
				return 1;
			}
		}

	str = (char*)realloc(str, 2 * m + 1); // выделяю больше памяти под повторения 

	if (!str) // проверка 
	{
		printf("Ошибка выделения памяти");
		return 1;
	}

	for (i = 0; i < m; i++) // механизм повторения 
	{
		str[i] = str[i];
		str[m + i] = str[i];
	}

	for (i = 0; i < 2 * m; i++) // вывод
		printf("%c", str[i]);

	return 0;
}
