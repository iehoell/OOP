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
	PCs* newPC = new PCs;
	pc->create_list();
	while (true)
	{
		do
		{
			change = menu();
		} while (change < 1 || change > 12);
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
				cout << "0 - добавление эл справа от текущего" << endl;
				cout << "1 - добавление эл слева от текущего" << endl;
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
		case 9:
			pc->Check_Op_Rav();
			break;
		case 10:
			*newPC = *pc;
			cout << "start - " << newPC->get_start() << endl;
			cout << "now - " << newPC->get_now() << endl;
			newPC->print_all();
			cout << "------------------------------------------------" << endl;
			break;
		case 11:
			cout << "сравнение двух элементов структуры" << endl;
			pc->PeregruzkaElementov();
			system("pause");
			break;
		case 12:
			cout << "сравнение двух структур" << endl;
			cout << "проверка на == ";
			if (*pc == *newPC) { cout << "true" << endl; }
			else { cout << "false" << endl; }
			cout << "проверка на != ";
			if (*pc != *newPC) { cout << "true" << endl; }
			else { cout << "false" << endl; }
			cout << "проверка на < ";
			if (*pc < *newPC) { cout << "true" << endl; }
			else { cout << "false" << endl; }
			cout << "проверка на > ";
			if (*pc > *newPC) { cout << "true" << endl; }
			else { cout << "false" << endl; }
			cout << "проверка на >= ";
			if (*pc >= *newPC) { cout << "true" << endl; }
			else { cout << "false" << endl; }
			cout << "проверка на <= ";
			if (*pc <= *newPC) { cout << "true" << endl; }
			else { cout << "false" << endl; }
			system("pause");
			break;
		}
	}
}