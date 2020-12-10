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
//---------------------Запись в файл-----------------------
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
//---------------------Чтение из файла---------------------
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
//---------------------Вычисление среднего числа денег-----
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
//---------------------Сортировка по алфавиту--------------
//---------------------------------------------------------
void Alphabet(struct bank* s2, size_t count)
{
	const char Alph[34] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
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
//---------------------Нормализация слова------------------
//------------------------ИВАН-Иван------------------------
void fix_temp(char* str)
{
	str[0] = toupper(str[0]);
	for (int i = 1; i < strlen(str); i++)
	{
		str[i] = tolower(str[i]);
	}
}
//---------------------------------------------------------
//---------------------Нормализация------------------------
//-----Фамилии-Имени-Отчества-От-Текущего-Пользователя-----
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
//----------Вывод на экран текущего пользователя-----------
//------------------С-очищением-консоли--------------------
void print_current(struct bank* clients, int current)
{
	system("cls");
	printf("%s\t%s\t%s\t%s\t%s\t%u\n", clients[current].first_name, clients[current].last_name, clients[current].middle_name, clients[current].client_id, clients[current].date, clients[current].amount);
}
//---------------------------------------------------------
//----------Вывод на экран текущего пользователя-----------
//---------------------------------------------------------
void print_current2(struct bank* clients,int count)
{
	printf("%s\t%s\t%s\t%s\t%s\t%u\n", clients[count].first_name, clients[count].last_name, clients[count].middle_name, clients[count].client_id, clients[count].date, clients[count].amount);
}
//---------------------------------------------------------
//-----------------Считывание нажатой кнопки---------------
//---------------------------------------------------------
int get_key()
{
	int key = getch();
	if ((key == 0) || (key == 224)) key = getch();
	return key;
}
//---------------------------------------------------------
//---------------------Меню 1------------------------------
//-Просмотр данных-сортировка-сортировка2-запись в файл----
int menu1(int checker, int checker2)
{
	if (checker != 0 && checker2 != 0)
	{
		printf("\n");
		printf("Просмотр - Enter\nСортировка была выполнена, чтобы повторить - Space\nОставить пользователей у которых количество денег на счету больше чем среднее у всех - 1 (сортировка проведена)\nЗаписать данные в другой файл - Tab\nВыход - Esc\n");
		while (true)
		{
			int key = get_key();
			if ((key == 27) || (key == 32) || (key == 13) || (key == 9) || (key == 49)) return key;
		}
	}
	if (checker != 0)
	{
		printf("\n");
		printf("Просмотр - Enter\nСортировка была выполнена, чтобы повторить - Space\nОставить пользователей у которых количество денег на счету больше чем среднее у всех - 1\nЗаписать данные в другой файл - Tab\nВыход - Esc\n");
		while (true)
		{
			int key = get_key();
			if ((key == 27) || (key == 32) || (key == 13)||(key == 9)||(key==49)) return key;
		}
	}
	if (checker2 != 0)
	{
		printf("\n");
		printf("Просмотр - Enter\nВыполнить сортировку по алфавиту - Space\nОставить пользователей у которых количество денег на счету больше чем среднее у всех - 1 (сортировка проведена)\nЗаписать данные в другой файл - Tab\nВыход - Esc\n");
		while (true)
		{
			int key = get_key();
			if ((key == 27) || (key == 32) || (key == 13) || (key == 9) || (key == 49)) return key;
		}
	}
	printf("\n");
	printf("Просмотр - Enter\nВыполнить сортировку по алфавиту - Space\nОставить пользователей у которых количество денег на счету больше чем среднее у всех - 1\nЗаписать данные в другой файл - Tab\nВыход - Esc\n");
	while (true)
	{
		int key = get_key();
		if ((key == 27) || (key == 32) || (key == 13)|| (key==9)|| (key == 49)) return key;
	}
}
//---------------------------------------------------------
//-------------------------Меню 2---------------Добавление-
//-Просмотр пользователей-Изменение данных-Поиск-Удаление--
int menu2()
{
	printf("\n");
	printf("Вперед ->\nНазад <-\nИзменить данные этого пользователя - Enter\nУдалить этого пользователя - delete\nДобавить пользователя справа от текущего - 1\nДобавить пользователя слева от текущего -2\nПоиск пользователя - 3\nВыход - Esc");
	while (true)
	{
		int key = get_key();
		if ((key == 27) || (key == 75) || (key == 77) || (key == 13) || (key == 83) || (key == 49) || (key == 50) ||(key==51)) return key;
	}
}
//---------------------------------------------------------
//--------------------------Меню3--------------------------
//---------Изменение данных текущего пользователя----------
int menu3(bank* data, int current)
{
	while (true)
	{
loop2:
system("cls");
print_current(data, current);
printf("\nЧтобы изменить данные нажмите на кнопку напротив них\n");
printf(" Имя - 1\n Фамилия - 2 \n Отчество - 3\n Id Клиента - 4 \n Датa рождения - 5 \n Суммa денег на счет - 6\n Вернуться назад - Escape\n");
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
		printf("\nИзмените имя пользователя -  ");
		gets_s(data[current].last_name);
		const char Alph[34] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
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
				printf("\nОшибка ввода имени пользователя. Имя может состоять только из русских букв.Например - Иван, Артём, Миша\n");
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
		printf("\nИзмените фамилию пользователя -  ");
		gets_s(data[current].first_name);
		const char Alph[34] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
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
				printf("\nОшибка ввода имени пользователя. Имя может состоять только из русских букв.Например - Кузьми, Куракин, Борисычев\n");
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
		printf("\nИзмените отчество пользователя -  ");
		gets_s(data[current].middle_name);
		const char Alph[34] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
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
				printf("\nОшибка ввода имени пользователя. Имя может состоять только из русских букв.Например - Сергеевич, Артёмович, Александрович\n");
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
		printf("\nИзмените Id-клиента пользователя -  ");
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
				printf("\nОшибка ввода. Id клиента может состоять только из цифр.Например - 123456789\n");
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
	printf("\nИзмените дату рождения (формат -16.01.2002) пользователя -  ");
	const char number2[12] = "0123456789";
	const char last_check[11] = "zz.zz.zzzz";
	char xx[100];
	xx[0] = '\0';
	gets_s(xx);
	/*	if (strlen(xx) != 10)
		{
			printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
			goto loop666;
		}*/ //Чтобы не было 5-и значного года разкоменть
	if ((xx[0] == '0') && (xx[1] == '0'))
	{
		printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
		goto loop666;
	}
	if ((xx[0] != '1') && (xx[0] != '0') && (xx[0] != '2') && (xx[0] != '3'))
	{
		printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
		goto loop666;
	}
	if (xx[2] != '.')
	{
		printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
		goto loop666;
	}
	if ((xx[3] != '0') && (xx[3] != '1'))
	{
		printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
		goto loop666;
	}
	if ((xx[3] == '0') && (xx[4] == '0'))
	{
		printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
		goto loop666;
	}
	if ((xx[4] != '1') && (xx[4] != '2') && (xx[4] != '3') && (xx[4] != '4') && (xx[4] != '5') && (xx[4] != '6') && (xx[4] != '7') && (xx[4] != '8') && (xx[4] != '9') && (xx[4] != '0'))
	{
		printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
		goto loop666;
	}
	if ((xx[3] == '1') && (xx[4] != '0') && (xx[4] != '1') && (xx[4] != '2'))
	{
		printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
		goto loop666;
	}
	if ((xx[0] == '3') && (xx[1] != '1') && (xx[1] != '0'))
	{
		printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
		goto loop666;
	}
	if (xx[5] != '.')
	{
		printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
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
			printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
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
			printf("\n Измените сумму денег - ");
			int x = 0;
			if (1 != scanf("%d", &x))
			{
				printf("\nОшибка ввода. Сумма денег может записываться только цифрами 123456789\n");
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
//-------------------------Меню 4--------------------------
//----------Поиск пользователя по известным данным---------
int menu4(bank* data, int count, int* please)
{
	while (true) {
	loop5:
		system("cls");
		printf("Чтобы найти пользователя введите любую информацию, которую вы знаете о нём :");
		printf("\n Имя - 1\n Фамилия - 2 \n Отчество - 3\n Id Клиента - 4 \n Датa рождения - 5 \n Суммa денег на счет - 6\n Имя Фаимилия -7\n Вернуться назад - Escape\n");
		int key = get_key();
		if (key == 27)
		{
			return 15;
		}
		if (key == 49)
		{
			system("cls");
			printf("\nВведите имя пользователя -  ");
			char friendly[1000];
			gets_s(friendly);
			fix_temp(friendly);
			for (int i = 0; i < count; i++)
			{
				if (i + 1 == count && strcmp(data[i].last_name, friendly) != 0)
				{
					printf("\nПользователя с нужными вам данными нет в базе\nДля продолжения нажмите - Enter");
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
					printf("\nЭто нужный вам пользователь?\nДа - 1\nПродолжить поиск -2\nВернуться -Esc\n");
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
			printf("\nВведите фамилию пользователя -  ");
			char friendly[1000];
			gets_s(friendly);
			fix_temp(friendly);
			for (int i = 0; i < count; i++)
			{
				if (i + 1 == count && strcmp(data[i].first_name, friendly) != 0)
				{
					printf("\nПользователя с нужными вам данными нет в базе\nДля продолжения нажмите - Enter");
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
					printf("\nЭто нужный вам пользователь?\nДа - 1\nПродолжить поиск -2\nВернуться -Esc\n");
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
			printf("\nВведите отчество пользователя -  ");
			char friendly[1000];
			gets_s(friendly);
			fix_temp(friendly);
			for (int i = 0; i < count; i++)
			{
				if (i + 1 == count && strcmp(data[i].middle_name, friendly) != 0)
				{
					printf("\nПользователя с нужными вам данными нет в базе\nДля продолжения нажмите - Enter");
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
					printf("\nЭто нужный вам пользователь?\nДа - 1\nПродолжить поиск -2\nВернуться -Esc\n");
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
			printf("\nВведите Id-клиента пользователя -  ");
			char id[32] = { 0 };
			gets_s(id);
			for (int i = 0; i < count; i++)
			{
				if (i + 1 == count && data[i].client_id != id)
				{
					printf("\nПользователя с нужными вам данными нет в базе\nДля продолжения нажмите - Enter");
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
					printf("\nЭто нужный вам пользователь?\nДа - 1\nПродолжить поиск -2\nВернуться -Esc\n");
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
			printf("\nВведите дату рожденья (формат -16.01.2002) пользователя -  ");
			char friendly[1000];
			gets_s(friendly);
			for (int i = 0; i < count; i++)
			{
				if (i + 1 == count && strcmp(data[i].date, friendly) != 0)
				{
					printf("\nПользователя с нужными вам данными нет в базе\nДля продолжения нажмите - Enter");
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
					printf("\nЭто нужный вам пользователь?\nДа - 1\nПродолжить поиск -2\nВернуться -Esc\n");
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
			printf("\n Введите сумму денег - ");
			int value = 0;
			scanf("%d", &value);
			for (int i = 0; i < count; i++)
			{
				if (i + 1 == count && data[i].amount != value)
				{
					printf("\nПользователя с нужными вам данными нет в базе\nДля продолжения нажмите - Enter");
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
					printf("\nЭто нужный вам пользователь?\nДа - 1\nПродолжить поиск -2\nВернуться -Esc\n");
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
			printf("\n  Введите Имя  - ");
			char friendly[1000];
			gets_s(friendly);
			printf("\n  Введите Фамилию  - ");
			char friendly2[1000];
			gets_s(friendly2);
			for (int i = 0; i < count; i++)
			{
				if (i + 1 == count && strcmp(data[i].last_name, friendly) != 0 && (strcmp(data[i].first_name,friendly2)!=0))
				{
					printf("\nПользователя с нужными вам данными нет в базе\nДля продолжения нажмите - Enter");
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
					printf("\nЭто нужный вам пользователь?\nДа - 1\nПродолжить поиск -2\nВернуться -Esc\n");
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
//---------------Удаление текущего пользователя------------
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
//------------------Добавление пользователя----------------
//---------------------------------------------------------
void add_member(bank* data, int now)
{
	system("cls");
	const char number[12] = "1234567890.";
	const char number2[12] = "1234567890";
	const char Alph[34] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	int counter_check = 0;
	int counter_check2 = 0;
	bool proverka = true;
	while (proverka)
	{
		printf("\nВпишите имя пользователя - ");
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
				printf("\nОшибка ввода имени пользователя. Имя может состоять только из русских букв.Например - Иван, Артём, Миша\n");
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
		printf("\nВпишите фамилию пользователя - ");
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
				printf("\nОшибка ввода фамилии пользователя. Имя может состоять только из русских букв. Например - Борисычев, Кузьмин, Куракин\n");
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
		printf("\nВпишите отчество пользователя - ");
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
				printf("\nОшибка ввода отчества пользователя. Имя может состоять только из русских букв. Например - Сергеевич,Борисович,Александрович\n");
				break;
			}
		}
		if (counter_check != strlen(Alph) && counter_check2 == strlen(data[now].middle_name)) proverka = false;
	}
	fix_type(data, now);
	while (true)
	{
		loop11:
		printf("\nВпишите Id-пользователя - ");
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
				printf("\nНеправильный ввод. Id клиента состоит только из цифр.Например - 123456789\n");
				goto loop11;
			}
		}
		break;
	}
	while (true)
	{
		loop12:
		printf("\nВпишите дату рождения - ");
		char xx[12] = { 0};
		gets_s(xx);
		if ((xx[0] == '0') && (xx[1] == '0'))
		{
			printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
			goto loop12;
		}
		if ((xx[0] != '1') && (xx[0] != '0') && (xx[0] != '2') && (xx[0] != '3'))
		{
			printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
			goto loop12;
		}
		if (xx[2] != '.')
		{
			printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
			goto loop12;
		}
		if ((xx[3] != '0') && (xx[3] != '1'))
		{
			printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
			goto loop12;
		}
		if ((xx[3] == '0') && (xx[4] == '0'))
		{
			printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
			goto loop12;
		}
		if ((xx[4]!= '1') && (xx[4] !='2') && (xx[4] != '3')&& (xx[4] != '4')&& (xx[4] != '5')&&(xx[4] != '6')&& (xx[4] != '7')&& (xx[4] != '8')&& (xx[4] != '9')&& (xx[4] != '0'))
		{
			printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
			goto loop12;
		}
		if ((xx[3] == '1') && (xx[4] != '0') && (xx[4] != '1') && (xx[4] != '2' ))
		{
			printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
			goto loop12;
		}
		if ((xx[0] == '3')&& (xx[1]!='1') && (xx[1]!='0'))
		{
			printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
			goto loop12;
		}
		if (xx[5] != '.')
		{
			printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");
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
				printf("\nНеправильный ввод даты. Дата зaписывается - день.месяц.год - 16.01.2002\n");	
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
		printf("\nВпишите сумму денег на счету - ");
		if (1 != scanf("%d", &data[now].amount))
		{
			printf("\nОшибка ввода. Сумма денег может записываться только цифрами 123456789\n");
			goto loop9;
		}
		break;
	}
	fix_type(data, now);
}

//---------------------------------------------------------
//---------------------Ввод путя к файлу-------------------
//-Берёт по символу и расширяет память если некст символ!=\0
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
	printf("Введите путь к вашему текстому файлу в формате \nC:\\....\\....\\ txt.txt\n");
	char* path = read_line();
	bool check = ReadData(&data, &count, path);
	free(path);
	int count2 = count;
	if (!check)
	{
		printf("Ошибка ввода путя к файлу или ошибка данных в файле.\n");
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
			printf("Здравствуйте, это программа для просмотра клиентов банка.\n");
			int panel1 = menu1(checker,checker2);	
			if (panel1 == 9)
			{
				system("cls");
				printf("Введите путь к файлу, в которой вы хотите записать данные\n");
				char* path2 =read_line();			
				WriteData(data, count, path2);
				free(path2);
				printf("Если вы хотите продолжить работу в программе с другим файлом нажмите - Enter\n Если вы хотите продолжить работу с текущими данными - Space\nЕсли вы хотите закрыть программу нажмите - Esc\n");
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
				if (m2 == 51)//поиск пользователя
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
				if (m2 == 49) //добавить справа
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
				if (m2 == 50)//добавить слева	
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
						printf(" Поздравляем! Вы удалили всех пользователей\n");
						printf(" Для продолжеия работы программы вы должны добавить одного пользователя или изменить файл");
						printf("\n Для изменения файла нажмите - 1\n Для добавления пользователя нажмите - 2\n Для закрытия программы нажмите - Esc\n");
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