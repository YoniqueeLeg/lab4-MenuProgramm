#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

struct bank
{
	char first_name[32];
	char last_name[32];
	char middle_name[32];
	char client_id[32];
	unsigned amount;
	char date[32];
};

//---------------------------------------------------------
//---------------------������ � ����-----------------------
//---------------------------------------------------------
bool WriteData(struct bank* clients, int n,  char* filename)
{
	FILE* output = NULL;
	char txt[] = ".txt";
	if (strstr(filename, txt) == NULL)
	{
		strcat(filename, txt);
	}
	output = fopen(filename, "w");
	if (output != NULL)
	{
		for (int i = 0; i < n; i++)
		{
			fprintf(output, "%s\t%s\t%s\t%s\t%s\t%u\n", clients[i].first_name, clients[i].last_name, clients[i].middle_name, clients[i].client_id, clients[i].date, clients[i].amount);
			fprintf(output, "\n");
		}
	}
	else
	{
		return false;
	}
	fclose(output);
	return true;
}
//---------------------------------------------------------
//---------------------������ �� �����---------------------
//---------------------------------------------------------
bool ReadData(struct bank** clients, int* n, const char* filename)
{
	struct bank* data = NULL;
	struct bank tmp;
	int count = 0;
	FILE* input = NULL;
	input = fopen(filename, "r");
	if (input != NULL)
	{
		while (!feof(input))
		{
			int r = fscanf(input, "%s\t%s\t%s\t%s\t%s\t%u\n", tmp.first_name, tmp.last_name, tmp.middle_name, &tmp.client_id, tmp.date, &tmp.amount);
			if (r == 6)
			{
				count++;
				data = (bank*)realloc(data, count * sizeof(bank));
				data[count - 1] = tmp;
			}
			else
			{
				fclose(input);
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	*clients = data;
	*n = count;
	fclose(input);
	return true;
}

//---------------------------------------------------------
//---------------------���������� �������� ����� �����-----
//---------------------------------------------------------
int AverageValue(struct bank* s1, size_t count)
{
	int average_value = 0;
	int summ = 0;
	int j = 0;
	for (size_t i = 0; i < count; i++)
	{
		summ += s1[i].amount;
	}
	average_value = summ / count;
	for (size_t i = 0; i < count; i++)
	{
		if (s1[i].amount > average_value)
		{
			s1[j] = s1[i];
			j++;
		}
	}
	return j;
}

//---------------------------------------------------------
//---------------------���������� �� ��������--------------
//---------------------------------------------------------
void Alphabet(struct bank* s2, size_t count)
{
	const char Alph[34] = "�����Ũ��������������������������";
	struct bank tmp;
	int checker = 1;
	char x;
	char y;
	for (int j = 0; j < count - 1; j++)
	{
		for (int i = 0; i < count-1-j; i++)
		{
			if (i - count == -1)
			{
				break;
			}
			if (strcmp(s2[i + 1].first_name, s2[i].first_name)!=0)
			{
				int j = 0;
				int k = 0;
				int j1 = 0;
				while (checker != 0)
				{
					j = 0;
					j1 = 0;
					x = toupper(s2[i].first_name[k]);
					while (x!= Alph[j])
					{
						if (x == Alph[j])
						{
							break;
						}
						j++;
					}
					y = toupper(s2[i + 1].first_name[k]);
					while (y != Alph[j1])
					{
						if (y == Alph[j1])
						{
							break;
						}
						j1++;
					}
					if (j > j1)
					{
						tmp = s2[i];
						s2[i] = s2[i + 1];
						s2[i + 1] = tmp;
						checker = 0;
					}
					if (j < j1)
					{
						checker = 0;
					}
					k++;
				}
				checker = 1;
			}
			else
			{
				int j = 0;
				int k = 0;
				int j1 = 0;
				while (checker != 0)
				{
					j1 = 0;
					j = 0;
					x = toupper(s2[i].last_name[k]);
					while (x != Alph[j])
					{
						if (x == Alph[j])
						{
							break;
						}
						j++;
					}
					y = toupper(s2[i + 1].last_name[k]);
					while (y != Alph[j1])
					{
						if (y == Alph[j1])
						{
							break;
						}
						j1++;
					}
					if (j > j1)
					{
						tmp = s2[i];
						s2[i] = s2[i + 1];
						s2[i + 1] = tmp;
						checker = 0;
					}
					if (j < j1)
					{
						checker = 0;
					}
					k++;
				}
				checker = 1;
			}
			if (strcmp(s2[i].first_name, s2[i + 1].first_name)==0 && strcmp(s2[i].last_name, s2[i + 1].last_name)==0)
			{
				int j = 0;
				int k = 0;
				int j1 = 0;
				while (checker != 0)
				{
					j1 = 0;
					j = 0;
					x = toupper(s2[i].middle_name[k]);
					while (x != Alph[j])
					{
						if (x == Alph[j])
						{
							break;
						}
						j++;
					}
					y = toupper(s2[i + 1].last_name[k]);
					while (y != Alph[j1])
					{
						if (y == Alph[j1])
						{
							break;
						}
						j1++;
					}
					if (j > j1)
					{
						tmp = s2[i];
						s2[i] = s2[i + 1];
						s2[i + 1] = tmp;
						checker = 0;
					}
					if (j < j1)
					{
						checker = 0;
					}
					k++;
				}
				checker = 1;
			}
			if (strcmp(s2[i].first_name , s2[i + 1].first_name)==0 && strcmp(s2[i].middle_name , s2[i + 1].middle_name)==0)
			{
				int j = 0;
				int k = 0;
				int j1 = 0;
				while (checker != 0)
				{
					j1 = 0;
					j = 0;
					x = toupper(s2[i].last_name[k]);
					while (x != Alph[j])
					{
						if (x == Alph[j])
						{
							break;
						}
						j++;
					}
					y = toupper(s2[i + 1].last_name[k]);
					while (y != Alph[j1])
					{
						if (y == Alph[j1])
						{
							break;
						}
						j1++;
					}
					if (j > j1)
					{
						tmp = s2[i];
						s2[i] = s2[i + 1];
						s2[i + 1] = tmp;
						checker = 0;
					}
					if (j < j1)
					{
						checker = 0;
					}
					k++;
				}
				checker = 1;
			}
		}
	}
}

//---------------------------------------------------------
//---------------------������������ �����------------------
//------------------------����-����------------------------
void fix_temp(char* str)
{
	str[0] = toupper(str[0]);
	for (int i = 1; i < strlen(str); i++)
	{
		str[i] = tolower(str[i]);
	}
}
//---------------------------------------------------------
//---------------------������������------------------------
//-----�������-�����-��������-��-��������-������������-----
void fix_type(bank* data, int current)
{
	data[current].first_name[0]=toupper(data[current].first_name[0]);
	for (int i = 1; i < strlen(data[current].first_name); i++)
	{
		data[current].first_name[i]=tolower(data[current].first_name[i]);
	}
	data[current].last_name[0]=toupper(data[current].last_name[0]);
	for (int i = 1; i < strlen(data[current].last_name); i++)
	{
		data[current].last_name[i]=tolower(data[current].last_name[i]);
	}
	data[current].middle_name[0]=toupper(data[current].middle_name[0]);
	for (int i = 1; i < strlen(data[current].middle_name); i++)
	{
		data[current].middle_name[i]=tolower(data[current].middle_name[i]);
	}
}
//---------------------------------------------------------
//----------����� �� ����� �������� ������������-----------
//------------------�-���������-�������--------------------
void print_current(struct bank* clients, int current)
{
	system("cls");
	printf("%s\t%s\t%s\t%s\t%s\t%u\n", clients[current].first_name, clients[current].last_name, clients[current].middle_name, clients[current].client_id, clients[current].date, clients[current].amount);
}
//---------------------------------------------------------
//----------����� �� ����� �������� ������������-----------
//---------------------------------------------------------
void print_current2(struct bank* clients,int count)
{
	printf("%s\t%s\t%s\t%s\t%s\t%u\n", clients[count].first_name, clients[count].last_name, clients[count].middle_name, clients[count].client_id, clients[count].date, clients[count].amount);
}
//---------------------------------------------------------
//-----------------���������� ������� ������---------------
//---------------------------------------------------------
int get_key()
{
	int key = getch();
	if ((key == 0) || (key == 224)) key = getch();
	return key;
}
//---------------------------------------------------------
//---------------------���� 1------------------------------
//-�������� ������-����������-����������2-������ � ����----
int menu1(int checker, int checker2)
{
	if (checker != 0 && checker2 != 0)
	{
		printf("\n");
		printf("�������� - Enter\n���������� ���� ���������, ����� ��������� - Space\n�������� ������������� � ������� ���������� ����� �� ����� ������ ��� ������� � ���� - 1 (���������� ���������)\n�������� ������ � ������ ���� - Tab\n����� - Esc\n");
		while (true)
		{
			int key = get_key();
			if ((key == 27) || (key == 32) || (key == 13) || (key == 9) || (key == 49)) return key;
		}
	}
	if (checker != 0)
	{
		printf("\n");
		printf("�������� - Enter\n���������� ���� ���������, ����� ��������� - Space\n�������� ������������� � ������� ���������� ����� �� ����� ������ ��� ������� � ���� - 1\n�������� ������ � ������ ���� - Tab\n����� - Esc\n");
		while (true)
		{
			int key = get_key();
			if ((key == 27) || (key == 32) || (key == 13)||(key == 9)||(key==49)) return key;
		}
	}
	if (checker2 != 0)
	{
		printf("\n");
		printf("�������� - Enter\n��������� ���������� �� �������� - Space\n�������� ������������� � ������� ���������� ����� �� ����� ������ ��� ������� � ���� - 1 (���������� ���������)\n�������� ������ � ������ ���� - Tab\n����� - Esc\n");
		while (true)
		{
			int key = get_key();
			if ((key == 27) || (key == 32) || (key == 13) || (key == 9) || (key == 49)) return key;
		}
	}
	printf("\n");
	printf("�������� - Enter\n��������� ���������� �� �������� - Space\n�������� ������������� � ������� ���������� ����� �� ����� ������ ��� ������� � ���� - 1\n�������� ������ � ������ ���� - Tab\n����� - Esc\n");
	while (true)
	{
		int key = get_key();
		if ((key == 27) || (key == 32) || (key == 13)|| (key==9)|| (key == 49)) return key;
	}
}
//---------------------------------------------------------
//-------------------------���� 2---------------����������-
//-�������� �������������-��������� ������-�����-��������--
int menu2()
{
	printf("\n");
	printf("������ ->\n����� <-\n�������� ������ ����� ������������ - Enter\n������� ����� ������������ - delete\n�������� ������������ ������ �� �������� - 1\n�������� ������������ ����� �� �������� -2\n����� ������������ - 3\n����� - Esc");
	while (true)
	{
		int key = get_key();
		if ((key == 27) || (key == 75) || (key == 77) || (key == 13) || (key == 83) || (key == 49) || (key == 50) ||(key==51)) return key;
	}
}
//---------------------------------------------------------
//--------------------------����3--------------------------
//---------��������� ������ �������� ������������----------
int menu3(bank* data, int current)
{
	while (true)
	{
loop2:
system("cls");
print_current(data, current);
printf("\n����� �������� ������ ������� �� ������ �������� ���\n");
printf(" ��� - 1\n ������� - 2 \n �������� - 3\n Id ������� - 4 \n ���a �������� - 5 \n ����a ����� �� ���� - 6\n ��������� ����� - Escape\n");
int key = getch();
if (key == 27)
{
	return 15;
}
if (key == 49)
{
	bool proverka = true;
	int counter_check = 0;
	int counter_check2 = 0;
	while (proverka)
	{
		printf("\n�������� ��� ������������ -  ");
		gets_s(data[current].last_name);
		const char Alph[34] = "�����Ũ��������������������������";
		counter_check2 = 0;
		for (int i = 0; i < strlen(data[current].last_name); i++)
		{
			counter_check2++;
			counter_check = 0;
			char symbol = toupper(data[current].last_name[i]);
			for (int j = 0; j < strlen(Alph); j++)
			{
				if (symbol != Alph[j]) counter_check++;
				if (symbol == Alph[j]) break;
			}
			if (counter_check == strlen(Alph))
			{
				printf("\n������ ����� ����� ������������. ��� ����� �������� ������ �� ������� ����.�������� - ����, ����, ����\n");
				break;
			}
		}
		if (counter_check != strlen(Alph) && counter_check2 == strlen(data[current].last_name)) proverka = false;
	}
	fix_type(data, current);
	goto loop2;
}
if (key == 50)
{
	bool proverka = true;
	int counter_check = 0;
	int counter_check2 = 0;
	while (proverka)
	{
		printf("\n�������� ������� ������������ -  ");
		gets_s(data[current].first_name);
		const char Alph[34] = "�����Ũ��������������������������";
		counter_check2 = 0;
		for (int i = 0; i < strlen(data[current].first_name); i++)
		{
			counter_check2++;
			counter_check = 0;
			char symbol = toupper(data[current].first_name[i]);
			for (int j = 0; j < strlen(Alph); j++)
			{
				if (symbol != Alph[j]) counter_check++;
				if (symbol == Alph[j]) break;
			}
			if (counter_check == strlen(Alph))
			{
				printf("\n������ ����� ����� ������������. ��� ����� �������� ������ �� ������� ����.�������� - ������, �������, ���������\n");
				break;
			}
		}
		if (counter_check != strlen(Alph) && counter_check2 == strlen(data[current].first_name)) proverka = false;
	}
	fix_type(data, current);
	goto loop2;
}
if (key == 51)
{
	bool proverka = true;
	int counter_check = 0;
	int counter_check2 = 0;
	while (proverka)
	{
		printf("\n�������� �������� ������������ -  ");
		gets_s(data[current].middle_name);
		const char Alph[34] = "�����Ũ��������������������������";
		counter_check2 = 0;
		for (int i = 0; i < strlen(data[current].middle_name); i++)
		{
			counter_check2++;
			counter_check = 0;
			char symbol = toupper(data[current].middle_name[i]);
			for (int j = 0; j < strlen(Alph); j++)
			{
				if (symbol != Alph[j]) counter_check++;
				if (symbol == Alph[j]) break;
			}
			if (counter_check == strlen(Alph))
			{
				printf("\n������ ����� ����� ������������. ��� ����� �������� ������ �� ������� ����.�������� - ���������, ��������, �������������\n");
				break;
			}
		}
		if (counter_check != strlen(Alph) && counter_check2 == strlen(data[current].middle_name)) proverka = false;
	}
	
	fix_type(data, current);
	goto loop2;
}
if (key == 52)
{
	while (true)
	{
	loop13:
		char id[32] = { 0 };
		char number[12] = "0123456789";
		printf("\n�������� Id-������� ������������ -  ");
		gets_s(id);
		for (int i = 0; i < strlen(id); i++)
		{
			int checker5 = 0;
			for (int j = 0; j < strlen(number); j++)
			{
				if (id[i] != number[j])
				{
					checker5++;
				}
			}
			if (checker5 == strlen(number))
			{
				printf("\n������ �����. Id ������� ����� �������� ������ �� ����.�������� - 123456789\n");
				goto loop13;
			}
		}
		for (int k = 0; k < strlen(id); k++)
		{
			data[current].client_id[k] = id[k];
		}
		data[current].client_id[strlen(id)] = '\0';
		goto loop2;
	}
}
if (key == 53)
{
loop666:
	printf("\n�������� ���� �������� (������ -16.01.2002) ������������ -  ");
	const char number2[12] = "0123456789";
	const char last_check[11] = "zz.zz.zzzz";
	char xx[100];
	xx[0] = '\0';
	gets_s(xx);
	/*	if (strlen(xx) != 10)
		{
			printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
			goto loop666;
		}*/ //����� �� ���� 5-� �������� ���� ����������
	if ((xx[0] == '0') && (xx[1] == '0'))
	{
		printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
		goto loop666;
	}
	if ((xx[0] != '1') && (xx[0] != '0') && (xx[0] != '2') && (xx[0] != '3'))
	{
		printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
		goto loop666;
	}
	if (xx[2] != '.')
	{
		printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
		goto loop666;
	}
	if ((xx[3] != '0') && (xx[3] != '1'))
	{
		printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
		goto loop666;
	}
	if ((xx[3] == '0') && (xx[4] == '0'))
	{
		printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
		goto loop666;
	}
	if ((xx[4] != '1') && (xx[4] != '2') && (xx[4] != '3') && (xx[4] != '4') && (xx[4] != '5') && (xx[4] != '6') && (xx[4] != '7') && (xx[4] != '8') && (xx[4] != '9') && (xx[4] != '0'))
	{
		printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
		goto loop666;
	}
	if ((xx[3] == '1') && (xx[4] != '0') && (xx[4] != '1') && (xx[4] != '2'))
	{
		printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
		goto loop666;
	}
	if ((xx[0] == '3') && (xx[1] != '1') && (xx[1] != '0'))
	{
		printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
		goto loop666;
	}
	if (xx[5] != '.')
	{
		printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
		goto loop666;
	}
	for (int i = 0; i < 4; i++)
	{
		int checker_work_please = 0;
		for (int j = 0; j < strlen(number2); j++)
		{
			if (xx[6+i] != number2[j]) checker_work_please++;
			if (xx[6+i] == number2[j]) break;
		}
		if (checker_work_please == strlen(number2))
		{
			printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
			goto loop666;
		}
	}
	for (int k = 0; k <= strlen(xx); k++)
	{
		data[current].date[k] = xx[k];
	}
		data[current].date[strlen(xx)-1] == '\0';
		goto loop2;
	}
	if (key == 54)
	{
		while (true)
		{
			loop0:
			printf("\n �������� ����� ����� - ");
			int x = 0;
			if (1 != scanf("%d", &x))
			{
				printf("\n������ �����. ����� ����� ����� ������������ ������ ������� 123456789\n");
				goto loop0;
			}
			data[current].amount = x;
			getchar();
			goto loop2;
		}
	}
		if (key == 27)
		{
			return 27;
		}
	}
}

//---------------------------------------------------------
//-------------------------���� 4--------------------------
//----------����� ������������ �� ��������� ������---------
int menu4(bank* data, int count, int* please)
{
	while (true) {
	loop5:
		system("cls");
		printf("����� ����� ������������ ������� ����� ����������, ������� �� ������ � �� :");
		printf("\n ��� - 1\n ������� - 2 \n �������� - 3\n Id ������� - 4 \n ���a �������� - 5 \n ����a ����� �� ���� - 6\n ��� �������� -7\n ��������� ����� - Escape\n");
		int key = get_key();
		if (key == 27)
		{
			return 15;
		}
		if (key == 49)
		{
			system("cls");
			printf("\n������� ��� ������������ -  ");
			char friendly[1000];
			gets_s(friendly);
			fix_temp(friendly);
			for (int i = 0; i < count; i++)
			{
				if (i + 1 == count && strcmp(data[i].last_name, friendly) != 0)
				{
					printf("\n������������ � ������� ��� ������� ��� � ����\n��� ����������� ������� - Enter");
					while (true)
					{
						int key4 = get_key();
						if (key4 == 13)
						{
							goto loop5;
						}
					}
				}
				if (strcmp(data[i].last_name, friendly) == 0)
				{
					print_current2(data, i);
					printf("\n��� ������ ��� ������������?\n�� - 1\n���������� ����� -2\n��������� -Esc\n");
					int key3 = get_key();
					if (key3 == 27)
					{
						goto loop5;
					}
					if (key3 == 49)
					{
						*please = 1;
						return i;
					}
					if (key == 50)
					{
						continue;
					}
				}
			}
		}
		if (key == 50)
		{
			system("cls");
			printf("\n������� ������� ������������ -  ");
			char friendly[1000];
			gets_s(friendly);
			fix_temp(friendly);
			for (int i = 0; i < count; i++)
			{
				if (i + 1 == count && strcmp(data[i].first_name, friendly) != 0)
				{
					printf("\n������������ � ������� ��� ������� ��� � ����\n��� ����������� ������� - Enter");
					while (true)
					{
						int key4 = get_key();
						if (key4 == 13)
						{
							goto loop5;
						}
					}
				}
				if (strcmp(data[i].first_name, friendly) == 0)
				{
					print_current2(data, i);
					printf("\n��� ������ ��� ������������?\n�� - 1\n���������� ����� -2\n��������� -Esc\n");
					int key3 = get_key();
					if (key3 == 27)
					{
						goto loop5;
					}
					if (key3 == 49)
					{
						*please = 1;
						return i;
					}
					if (key == 50)
					{
						continue;
					}
				}
			}
		}
		if (key == 51)
		{
			system("cls");
			printf("\n������� �������� ������������ -  ");
			char friendly[1000];
			gets_s(friendly);
			fix_temp(friendly);
			for (int i = 0; i < count; i++)
			{
				if (i + 1 == count && strcmp(data[i].middle_name, friendly) != 0)
				{
					printf("\n������������ � ������� ��� ������� ��� � ����\n��� ����������� ������� - Enter");
					while (true)
					{
						int key4 = get_key();
						if (key4 == 13)
						{
							goto loop5;
						}
					}
				}
				if (strcmp(data[i].middle_name, friendly) == 0)
				{
					print_current2(data, i);
					printf("\n��� ������ ��� ������������?\n�� - 1\n���������� ����� -2\n��������� -Esc\n");
					int key3 = get_key();
					if (key3 == 27)
					{
						goto loop5;
					}
					if (key3 == 49)
					{
						*please = 1;
						return i;
					}
					if (key == 50)
					{
						continue;
					}
				}
			}
		}
		if (key == 52)
		{
			system("cls");
			printf("\n������� Id-������� ������������ -  ");
			char id[32] = { 0 };
			gets_s(id);
			for (int i = 0; i < count; i++)
			{
				if (i + 1 == count && data[i].client_id != id)
				{
					printf("\n������������ � ������� ��� ������� ��� � ����\n��� ����������� ������� - Enter");
					while (true)
					{
						int key4 = get_key();
						if (key4 == 13)
						{
							goto loop5;
						}
					}
				}
				if (data[i].client_id == id)
				{
					print_current2(data, i);
					printf("\n��� ������ ��� ������������?\n�� - 1\n���������� ����� -2\n��������� -Esc\n");
					int key3 = get_key();
					if (key3 == 27)
					{
						goto loop5;
					}
					if (key3 == 49)
					{
						*please = 1;
						return i;
					}
					if (key == 50)
					{
						continue;
					}
				}
			}
		}
		if (key == 53)
		{
			system("cls");
			printf("\n������� ���� �������� (������ -16.01.2002) ������������ -  ");
			char friendly[1000];
			gets_s(friendly);
			for (int i = 0; i < count; i++)
			{
				if (i + 1 == count && strcmp(data[i].date, friendly) != 0)
				{
					printf("\n������������ � ������� ��� ������� ��� � ����\n��� ����������� ������� - Enter");
					while (true)
					{
						int key4 = get_key();
						if (key4 == 13)
						{
							goto loop5;
						}
					}
				}
				if (strcmp(data[i].date, friendly) == 0)
				{
					print_current2(data, i);
					printf("\n��� ������ ��� ������������?\n�� - 1\n���������� ����� -2\n��������� -Esc\n");
					int key3 = get_key();
					if (key3 == 27)
					{
						goto loop5;
					}
					if (key3 == 49)
					{
						*please = 1;
						return i;
					}
					if (key == 50)
					{
						continue;
					}
				}
			}
		}
		if (key == 54)
		{
			system("cls");
			printf("\n ������� ����� ����� - ");
			int value = 0;
			scanf("%d", &value);
			for (int i = 0; i < count; i++)
			{
				if (i + 1 == count && data[i].amount != value)
				{
					printf("\n������������ � ������� ��� ������� ��� � ����\n��� ����������� ������� - Enter");
					while (true)
					{
						int key4 = get_key();
						if (key4 == 13)
						{
							goto loop5;
						}
					}
				}
				if (data[i].amount == value)
				{
					print_current2(data, i);
					printf("\n��� ������ ��� ������������?\n�� - 1\n���������� ����� -2\n��������� -Esc\n");
					int key3 = get_key();
					if (key3 == 27)
					{
						goto loop5;
					}
					if (key3 == 49)
					{
						*please = 1;
						return i;
					}
					if (key == 50)
					{
						continue;
					}
				}
			}
		}
		if (key == 55)
		{
			system("cls");
			printf("\n  ������� ���  - ");
			char friendly[1000];
			gets_s(friendly);
			printf("\n  ������� �������  - ");
			char friendly2[1000];
			gets_s(friendly2);
			for (int i = 0; i < count; i++)
			{
				if (i + 1 == count && strcmp(data[i].last_name, friendly) != 0 && (strcmp(data[i].first_name,friendly2)!=0))
				{
					printf("\n������������ � ������� ��� ������� ��� � ����\n��� ����������� ������� - Enter");
					while (true)
					{
						int key4 = get_key();
						if (key4 == 13)
						{
							goto loop5;
						}
					}
				}
				if (strcmp(data[i].last_name, friendly) == 0 && strcmp(data[i].first_name,friendly2)==0)
				{
					print_current2(data, i);
					printf("\n��� ������ ��� ������������?\n�� - 1\n���������� ����� -2\n��������� -Esc\n");
					int key3 = get_key();
					if (key3 == 27)
					{
						goto loop5;
					}
					if (key3 == 49)
					{
						*please = 1;
						return i;
					}
					if (key == 50)
					{
						continue;
					}
				}
			}
		}
		if (key == 27)
		{
			return 27;
		}
	}
}
//---------------------------------------------------------
//---------------�������� �������� ������������------------
//---------------------------------------------------------
void kill(bank* data, int count, int current)
{
	while (current < count)
	{
		data[current] = data[current + 1];
		current++;
	}
}
//---------------------------------------------------------
//------------------���������� ������������----------------
//---------------------------------------------------------
void add_member(bank* data, int now)
{
	system("cls");
	const char number[12] = "1234567890.";
	const char number2[12] = "1234567890";
	const char Alph[34] = "�����Ũ��������������������������";
	int counter_check = 0;
	int counter_check2 = 0;
	bool proverka = true;
	while (proverka)
	{
		printf("\n������� ��� ������������ - ");
		gets_s(data[now].last_name);
		counter_check2 = 0;
		for (int i = 0; i < strlen(data[now].last_name); i++)
		{
			counter_check2++;
			counter_check = 0;
			char symbol = toupper(data[now].last_name[i]);
			for (int j = 0; j < strlen(Alph); j++)
			{
				if (symbol != Alph[j]) counter_check++;
				if (symbol== Alph[j]) break;
			}
			if (counter_check == strlen(Alph))
			{
				printf("\n������ ����� ����� ������������. ��� ����� �������� ������ �� ������� ����.�������� - ����, ����, ����\n");
				break;
			}
		}
		if (counter_check != strlen(Alph) && counter_check2 == strlen(data[now].last_name)) proverka = false;
	}
	proverka = true;
	counter_check = 0;
	counter_check2 = 0;
	while (proverka)
	{
		printf("\n������� ������� ������������ - ");
		gets_s(data[now].first_name);
		counter_check2 = 0;
		for (int i = 0; i < strlen(data[now].first_name); i++)
		{
			counter_check2++;
			counter_check = 0;
			char symbol = toupper(data[now].first_name[i]);
			for (int j = 0; j < strlen(Alph); j++)
			{
				if (symbol != Alph[j]) counter_check++;
				if (symbol == Alph[j]) break;
			}
			if (counter_check == strlen(Alph))
			{
				printf("\n������ ����� ������� ������������. ��� ����� �������� ������ �� ������� ����. �������� - ���������, �������, �������\n");
				break;
			}
		}
		if (counter_check != strlen(Alph) && counter_check2 == strlen(data[now].first_name)) proverka = false;
	}
	proverka = true;
	counter_check = 0;
	counter_check2 = 0;
	while (proverka)
	{
		printf("\n������� �������� ������������ - ");
		gets_s(data[now].middle_name);
		counter_check2 = 0;
		for (int i = 0; i < strlen(data[now].middle_name); i++)
		{
			counter_check2++;
			counter_check = 0;
			char symbol = toupper(data[now].middle_name[i]);
			for (int j = 0; j < strlen(Alph); j++)
			{
				if (symbol != Alph[j]) counter_check++;
				if (symbol == Alph[j]) break;
			}
			if (counter_check == strlen(Alph))
			{
				printf("\n������ ����� �������� ������������. ��� ����� �������� ������ �� ������� ����. �������� - ���������,���������,�������������\n");
				break;
			}
		}
		if (counter_check != strlen(Alph) && counter_check2 == strlen(data[now].middle_name)) proverka = false;
	}
	fix_type(data, now);
	while (true)
	{
		loop11:
		printf("\n������� Id-������������ - ");
		gets_s(data[now].client_id);
		for (int i = 0; i < strlen(data[now].client_id); i++)
		{
			int checker3 = 0;
			int checker4 = 0;
			for (int j = 0; j < strlen(number2); j++)
			{
				if (data[now].client_id[i] != number2[j])
				{
					checker3++;
				}
			}
			if (checker3 == strlen(number2))
			{
				printf("\n������������ ����. Id ������� ������� ������ �� ����.�������� - 123456789\n");
				goto loop11;
			}
		}
		break;
	}
	while (true)
	{
		loop12:
		printf("\n������� ���� �������� - ");
		char xx[12] = { 0};
		gets_s(xx);
		if ((xx[0] == '0') && (xx[1] == '0'))
		{
			printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
			goto loop12;
		}
		if ((xx[0] != '1') && (xx[0] != '0') && (xx[0] != '2') && (xx[0] != '3'))
		{
			printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
			goto loop12;
		}
		if (xx[2] != '.')
		{
			printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
			goto loop12;
		}
		if ((xx[3] != '0') && (xx[3] != '1'))
		{
			printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
			goto loop12;
		}
		if ((xx[3] == '0') && (xx[4] == '0'))
		{
			printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
			goto loop12;
		}
		if ((xx[4]!= '1') && (xx[4] !='2') && (xx[4] != '3')&& (xx[4] != '4')&& (xx[4] != '5')&&(xx[4] != '6')&& (xx[4] != '7')&& (xx[4] != '8')&& (xx[4] != '9')&& (xx[4] != '0'))
		{
			printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
			goto loop12;
		}
		if ((xx[3] == '1') && (xx[4] != '0') && (xx[4] != '1') && (xx[4] != '2' ))
		{
			printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
			goto loop12;
		}
		if ((xx[0] == '3')&& (xx[1]!='1') && (xx[1]!='0'))
		{
			printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
			goto loop12;
		}
		if (xx[5] != '.')
		{
			printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");
			goto loop12;
		}
		for (int i = 0; i < 4; i++)
		{
			int checker_work_please = 0;
			for (int j = 0; j < strlen(number2); j++)
			{
				if (xx[6 + i] != number2[j]) checker_work_please++;
				if (xx[6 + i] == number2[j]) break;
			}
			if (checker_work_please == strlen(number2))
			{
				printf("\n������������ ���� ����. ���� �a���������� - ����.�����.��� - 16.01.2002\n");	
				goto loop12;
			}
		}
		for (int k = 0; k <= strlen(xx); k++)
		{
			data[now].date[k] = xx[k];
		}
		data[now].date[strlen(xx) - 1] == '\0';
		break;
	}
	while (true)
	{
		loop9:
		printf("\n������� ����� ����� �� ����� - ");
		if (1 != scanf("%d", &data[now].amount))
		{
			printf("\n������ �����. ����� ����� ����� ������������ ������ ������� 123456789\n");
			goto loop9;
		}
		break;
	}
	fix_type(data, now);
}

//---------------------------------------------------------
//---------------------���� ���� � �����-------------------
//-���� �� ������� � ��������� ������ ���� ����� ������!=\0
char* read_line(void) 
{
	size_t capacity = 4;
	size_t size = 0;

	char* buffer = (char*)malloc(capacity);
	if (buffer == NULL)
		return NULL;

	while (true) {
		int c = fgetc(stdin);
		if (c == '\n' || c == EOF)
			break;
		buffer[size] = (char)c;
		++size;
		if (size == capacity) {
			capacity *= 2;
			char* new_buffer = (char*)realloc(buffer, capacity);
			if (new_buffer == NULL) {
				free(buffer);
				return NULL;
			}
			buffer = new_buffer;
		}
	}

	buffer[size] = 0;
	return buffer;
}
//---------------------------------------------------------
//---------------------------Main--------------------------
//---------------------------------------------------------
int main(void)
{
loop_repeat:
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");
	bank* data = NULL;
	int count = 0;
	printf("������� ���� � ������ �������� ����� � ������� \nC:\\....\\....\\ txt.txt\n");
	char* path = read_line();
	bool check = ReadData(&data, &count, path);
	free(path);
	int count2 = count;
	if (!check)
	{
		printf("������ ����� ���� � ����� ��� ������ ������ � �����.\n");
		goto loop_repeat;
	}
	if (check)
	{
		int checker = 0;
		int checker2 = 0;
		int current = 0;
		while (true)
		{
		loop:
			system("cls");
			printf("������������, ��� ��������� ��� ��������� �������� �����.\n");
			int panel1 = menu1(checker,checker2);	
			if (panel1 == 9)
			{
				system("cls");
				printf("������� ���� � �����, � ������� �� ������ �������� ������\n");
				char* path2 =read_line();			
				WriteData(data, count, path2);
				free(path2);
				printf("���� �� ������ ���������� ������ � ��������� � ������ ������ ������� - Enter\n ���� �� ������ ���������� ������ � �������� ������� - Space\n���� �� ������ ������� ��������� ������� - Esc\n");
				while (true)
				{
					int k = get_key();
					if (k == 13)
					{
						goto loop_repeat;
					}
					if (k == 32)
					{
						goto loop;
					}
					if (k == 27)
					{
						return 0;
					}
				}
			}
			if (panel1 == 27) break;
			if (panel1 == 49)
			{
				int k = 0;
				k = AverageValue(data, count);
				count = k;
				checker2++;
				goto loop;
			}
			if (panel1 == 32)
			{
				Alphabet(data, count);
				checker++;
				goto loop;
			}
			while (panel1 == 13)
			{
			loop3:
				print_current(data, current);
				int m2 = menu2();
				if (m2 == 51)//����� ������������
				{
					int please = 0;
					while (true)
					{
						int m4 = menu4(data, count, &please);
						if (m4 == 15)
						{
							break;
						}
						if (please != 0)
						{
							current = m4;
							break;
						}
					}
				}
				if (m2 == 49) //�������� ������
				{
					count++;
					if (count > count2)
					{
						data = (bank*)realloc(data, count * sizeof(bank));
					}
					for (int i=count-1; i>current; i--)
					{
						data[i] = data[i - 1];
					} 
					add_member(data, current+1);
					getchar();
				}
				if (m2 == 50)//�������� �����	
				{ 
					count++;
					if (count > count2)
					{
						data = (bank*)realloc(data, count * sizeof(bank));
					}
					for (int i = count - 1; i > current; i--)
					{
						data[i] = data[i - 1];
					}
					add_member(data, current);
					getchar();
				}
				if (m2 == 83)
				{
					kill(data, count, current);
					count--;
					if (count == 0)
					{
						system("cls");
						printf(" �����������! �� ������� ���� �������������\n");
						printf(" ��� ���������� ������ ��������� �� ������ �������� ������ ������������ ��� �������� ����");
						printf("\n ��� ��������� ����� ������� - 1\n ��� ���������� ������������ ������� - 2\n ��� �������� ��������� ������� - Esc\n");
						int key = get_key();
						if (key == 49)
						{
							system("cls");
							goto loop_repeat;
						}
						if (key == 50)
						{
							system("cls");
							int now = 0;
							add_member(data, now);
							goto loop;
						}
						if (key == 27)
						{
							system("cls");
							return 0;
						}

					}
					if (current != 0)
					{
						current--;
					}
					goto loop3;
				}
				if (m2 == 13)
				{
					while (true)
					{
						int m3 = menu3(data, current);
						if (m3 == 15)
						{
							break;
						}
					}
				}
				if (m2 == 27) break;
				switch (m2)
				{
				case 75:
					if (current > 0)
					{
						current--;
					} break;

				case 77:
					if (current < count - 1)
					{
						current++;
					} break;
				}
			}
		}
	}
}