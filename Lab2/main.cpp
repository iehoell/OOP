#include "logic.hpp"
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

void endOfProgram()
{
	cout << "Вы вышли из программы." << endl;
	system("pause");
	exit(0);
}

int main()
{
	char chang;
	int change;
	int ch = 2;
	int ammount = 1;
	setlocale(LC_ALL, "Russian");
create:
	cout << "Вы хотите создать новый класс?" << endl << "Если да, нажмите 'y', если нет, то 'n'" << endl;
	while (chang != 'y' && chang != 'n')
	{
		cin >> chang;
		if (chang == 'n')
			endOfProgram();
	}
	PCs* pc = new PCs;
	pc->create_list();
	while (true)
	{
		do
		{
			change = menu();
		} while (change < 1 || change > 9);
		switch (change)
		{
		case 1:
			cout << "количество элементов - " << pc->ammount() << endl;
			system("pause");
			_flushall();
			break;
		case 2:
			cout << "количество элементов - " << pc->ammount() << endl;
			system("pause");
			_flushall();
			break;
		case 3:
			pc->add_element();
			break;
		case 4:
			while (ch != 1 && ch != 0)
			{
				cout << "0 - добавление элемента справа от текущего" << endl;
				cout << "1 - добавление элемента слева от текущего" << endl;
				cin >> ch;
			}
			if (ch == 0) { pc->add_element_right(); }
			if (ch == 1) { pc->add_element_left(); }
			ch = 2;
			break;
		case 5:
			if (pc->del_el() == 1) { goto create; }
			break;
		case 6:
			pc->del_PCs();
			system("pause");
			goto create;
			break;
		case 7:
			while (ch != 1 && ch != 0)
			{
				cout << "0 - движение на след эл" << endl;
				cout << "1 - движение на пред эл" << endl;
				cin >> ch;
			}
			if (ch == 0) { pc->nex(); }
			if (ch == 1) { pc->pre(); }
			ch = 2;
			break;
		case 8:
			cout << "now - " << pc->get_now() << endl;
			cout << "start - " << pc->get_start() << endl;
			pc->print_all();
			break;
		}
	}
}