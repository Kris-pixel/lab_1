#include <iostream>
#include <fstream>
#include<tchar.h>
#include<Windows.h>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};
int menu(void);
void insert(Address* e, Address** phead, Address** plast);
Address* setElement();
void outputList(Address** phead, Address** plast);
void find(char name[NAME_SIZE], Address** phead);
void delet(char name[NAME_SIZE], Address** phead, Address** plast);
void writeToFile(Address** phead);
void readFromFile(Address** phead, Address** plast);
void deleteX(int x, Address** phead, Address** plast);


//deleteX (int x) Ц функци€ удалени€ первого 
//встречающегос€ элемента с заданным значением x.	