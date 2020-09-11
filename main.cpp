#include "Header.h"

int _tmain(int argc, _TCHAR argv[])
{
	int x;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Address* head = NULL;
	Address* last = NULL;
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: {	  char dname[NAME_SIZE];
			cout << "¬ведите им€: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {	  char fname[NAME_SIZE];
			cout << "¬ведите им€: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
		}
			  break;
		case 5: writeToFile(&head);
			break;
		case 6: readFromFile(&head, &last);
			break;
		case 7: cout << "¬ведите число от 432 до 463:"; cin >> x;
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			deleteX(x, &head, &last);
			break;
		case 8:exit(0);
		default: exit(1);
		}
	}
	return 0;
}
