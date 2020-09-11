#include "Header.h"
using namespace std;
int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод имени" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Запись в файл" << endl;
	cout << "6. Чтение из файла" << endl;
	cout << "7. Удалить элемент" << endl;
	cout << "8. Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 8);
	return c;
}

void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	};
}

Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cout << "Ошибка выделения памяти памяти";
		return NULL;
	};
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	};
	cout << "" << endl;
}

void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}

void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имени {	struct Address *t = *phead;	
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))  break;
		t = t->next;
	};
if (!t)
{
	cerr << "Имя не найдено" << endl;
}
else
{
	if (*phead == t)
	{
		*phead = t->next;
		if (*phead)
			(*phead)->prev = NULL;
		else
			*plast = NULL;
	}
	else
	{
		t->prev->next = t->next;
		if (t != *plast)
			t->next->prev = t->prev;
		else
			*plast = t->prev;
	};
	delete t;
	cout << "Элемент удален" << endl;
};
}
void writeToFile(Address** phead)       //Запись в файл
{
	struct Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "wb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
//-----------------------------------------------------------
void readFromFile(Address** phead, Address** plast)          //Считывание из файла
{
	struct Address* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "Ошибка выделения памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}


void deleteX(int x, Address** phead, Address** plast)
{
	Address* t = *phead;
	char* ptr=NULL;
	char tmp;
	tmp = x + '0';
	cout << "Будет удалена первая запись, содержащая " << tmp << endl;
	while (t != NULL)
	{
		for (int i = 0;t->name[i]!='\0'; i++)
		{
			if (tmp ==t->name[i]) {
				ptr = t->name;
				break;
			}
		}
		for (int i = 0; t->city[i]!='\0'; i++)
		{
			if (tmp == t->city[i]) {
				ptr = t->city;
				break;
			}
		}
		if (ptr != NULL) break;
		t = t->next;
	}
		if (!t)
			cerr << "Имя не найдено" << endl;
		else
		{
			if (*phead == t)
			{
				*phead = t->next;
				if (*phead)
					(*phead)->prev = NULL;
				else
					*plast = NULL;
			}
			else
			{
				t->prev->next = t->next;
				if (t != *plast)
					t->next->prev = t->prev;
				else
					*plast = t->prev;
			};
			delete t;
			cout << "Элемент удален" << endl;
		};
}
