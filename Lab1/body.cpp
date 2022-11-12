#include "body.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    system("chcp 1251 >> null");
    language();
    int now = 0;
    int command;
    list* name = initialization();
    filling(name);
    now++;
    for (int exitParametr = 0; exitParametr != 1; )
    {
        if (now != 0)
        {
            cout<<"Вы на "<<now<<" элементе"<< endl;

        }
        else
        {
            for (int exit_s = 0; exit_s != 1;)
            {
                cout<<"Введите 1 чтобы создать структуру"<<endl;
                cout<<"Введите 2 выйти из программы"<<endl;
                _flushall();
                command = getchar();
                if (command == '1')
                {
                    list* name = initialization();
                    filling(name);
                    now++;
                    exit_s = 1;
                }
                if (command == '2')
                {
                    cout<<"Выход из программы";
                    exit(0);
                }
            }
        }
        system("cls");
        cout<<"1 - Проверка на наличие элементов в структуре данных \n2 - Получение количества элементов  в структуре данных \n3 - Добавление элемента  в структуру данных \n4 - Вставка элемента с одной или с другой стороны от текущего \n5 - Удаление текущего элемента структуры данных \n6 - Очистка структуры данных \n7 - Перемещение по элементам структуры данных \n8 - Чтение информации из текущего элемента структуры данных \n9 - выход из программы"<<endl;
        _flushall();
        cin >> command;
        system("cls");
        switch (command) {
        case 1:
            checkForAvailability(name);
            cout<<"Нажмите Enter";
            _flushall();
            getchar();
            break;
        case 2:
            cout<<"В структуре "<<amount(name)<<" элемента(-ов)"<<endl;
            cout<<"Нажмите Enter";
            getchar();
            _flushall();
            getchar();
            break;
        case 3:
            system("cls");
            addElement(name);
            now += 1;
            break;
        case 4:
            cout<<"Введите 1 чтобы вставить элемент слева"<<endl;
            cout<<"Введите 2 чтобы вставить элемент справа"<<endl;
            _flushall();
            cin >> command;
            if (command == 1)
            {
                system("cls");
                addLeftElement(name, now);
            }
            else if (command == 2)
            {
                system("cls");
                addRightElement(name, now);
                now += 1;
            }
            else
            {
                system("cls");
                cout<<"Некорректно введена команда"<<endl;
            }
            break;
        case 5:
            cout<<"Имя элемента - ";
            processorName(name, now);
            cout<<"Адрес удаленного элемента - ";
            printAddress(name, now);
            cout << endl;
            if (deleteElement(name, now) != 1)
            {
                now = now - 1;
            }
            cout<<"Нажмите Enter";
            getchar();
            _flushall();
            getchar();
            break;
        case 6:
            removeList(name);
            cout<<"Нажмите Enter";
            _flushall();
            getchar();
            now = 0;
            break;
        case 7:
            for (int exitMoveFunc = 0; exitMoveFunc != 1;)
            {
                getchar();
                cout << "Введите 1 чтобы перейти на 1 элемент назад" << endl;
                cout << "Введите 2 чтобы перейти на 1 элемент вперед" << endl;
                cout << "Введите 3 чтобы выйти из функции перемещения" << endl;
                _flushall();
                command = getchar();
                if (command == '1')
                {
                    if (now == 1)
                    {
                        cout<<"Это первый элемент движение назад невозможно !"<<endl;
                        cout<<"Нажмите Enter";
                        getchar();
                        _flushall();
                        getchar();
                        break;
                    }
                    printAddress(name, now);
                    now -= 1;
                    cout<<" -> ";
                    printAddress(name, now);
                    cout << endl;
                    cout<<"Вы на "<<now<<" элементе"<<endl;
                    cout << "Его имя - ";
                    processorName(name, now);
                }
                if (command == '2')
                {
                    if (now == amount(name))
                    {
                        cout<<"Это последний элемент, движение вперед невозможно !"<<endl;
                        cout<<"Нажмите Enter";
                        getchar();
                        _flushall();
                        getchar();
                        break;
                    }
                    printAddress(name, now);
                    now += 1;
                    cout<<" -> ";
                    printAddress(name, now);
                    cout << endl;
                    cout<<"Вы на "<<now<<" элементе"<<endl;
                    processorName(name, now);
                }
                if (command == '3')
                {
                    exitMoveFunc = 1;
                    system("cls");
                }
            }
            break;
        case 8:
            system("cls");
            printElements(name, now);
            getchar();
            break;
        case 9:
            removeList(name);
            exit(0);
        }
        system("cls");
    }
}