#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define n 10

int main()
{
	int i, k, m = n;
	char* str;

	setlocale(LC_ALL, "Russian"); // � �������

	str = (char*)calloc(n + 1, sizeof(char)); // ������� ������

	if (!str) // �������� 
	{
		printf("������ ��������� ������");
		return 1;
	}

	printf("\n������� ������ �� %d ��������\n", n);
	fgets(str, n + 1, stdin); // ���� ������

	for(i = 0; i < n; i++)
	{
		if (!(int(str[i]) >= 32 && int(str[i]) <= 126))
		{
			i = 0;
			printf("�� ����� ������, ��� %d ��������\n", n);
			rewind(stdin);
			fgets(str, n + 1, stdin); // ���� ������
		}
	} 

	for (i = 0; i < n; i++) // �������� �������� *
		if (str[i] == '*')
		{
			for (k = i; k < n; k++)
				str[k] = str[k + 1];
			--m;
			--i;
			if (m <= 0)
			{
				printf("������������ ����");
				return 1;
			}

			str = (char*)realloc(str, m); // �������� ������ ����� �������� *
			
			if (!str) // �������� 
			{
				printf("������ ��������� ������");
				return 1;
			}
		}

	str = (char*)realloc(str, 2 * m + 1); // ������� ������ ������ ��� ���������� 

	if (!str) // �������� 
	{
		printf("������ ��������� ������");
		return 1;
	}

	for (i = 0; i < m; i++) // �������� ���������� 
	{
		str[i] = str[i];
		str[m + i] = str[i];
	}

	for (i = 0; i < 2 * m; i++) // �����
		printf("%c", str[i]);

	return 0;
}