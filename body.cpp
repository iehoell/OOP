#include "logic.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{   
    system("chcp 1251 >> null");
    language();
    int now = 0;
    int command;
    list *name = initialization();
    filling(name);
    now++;
        for(int exitParametr = 0; exitParametr != 1; )
        {       
        if(now != 0)
        {
            printf("Вы на %d элементе \n", now);
            
        }
        else
        {
            for(int exit_s = 0; exit_s !=1;)
            {
                printf("Введите 1 чтобы создать структуру \n");
                printf("Введите 2 выйти из программы \n");
                _flushall();
                command = getchar();
                if(command == '1')
                {
                    list *name = initialization();
                    filling(name);
                    now++;
                    exit_s =1;
                }
                if(command == '2')
                {
                    printf("Выход из программы");
                    exit(0);
                }
            }
        }
        printf("// 1 - Проверка на наличие элементов в структуре данных \n// 2 - Получение количества элементов  в структуре данных \n// 3 - Добавление элемента  в структуру данных \n// 4 - Вставка элемента с одной или с другой стороны от текущего \n// 5 - Удаление текущего элемента структуры данных \n// 6 - Очистка структуры данных \n// 7 - Перемещение по элементам структуры данных \n// 8 - Чтение информации из текущего элемента структуры данных \n// 9 - выход из программы\n");
        _flushall();
        scanf("%d", &command);
        switch (command){
            case 1:
                checkForAvailability(name);
                printf("Нажмите Enter");
                _flushall();
                getchar();
                break;
            case 2:
                printf("В структуре %d элемента(-ов) \n", amount(name));
                printf("Нажмите Enter");
                _flushall();
                getchar();
                break;
            case 3:
                addElement(name);
                now += 1;
                break;
            case 4:
                printf("Введите 1 чтобы вставить элемент слева \n");
                printf("Введите 2 чтобы вставить элемент справа \n");
                _flushall();
                scanf("%d", &command);
                if(command == 1)
                {
                    addLeftElement(name, now);
                }
                else if(command == 2)
                {
                    addRightElement(name, now);
                    now += 1;
                }
                else
                {
                    printf("Некорректно введена команда \n");
                }
                break;
            case 5:
                printf("Имя элемента - ");
                processorName(name,now);
                printf("Адрес удаленного элемента - ");
                printAddress(name, now);
                printf("\n");
                if(deleteElement(name, now) != 1)
                {
                    now = now - 1;
                }
                printf("Нажмите Enter");
                _flushall();
                getchar();
                break;
            case 6:
                removeList(name);
                printf("Нажмите Enter");
                _flushall();
                getchar();
                now = 0;
                break;
            case 7:
                for(int exitMoveFunc = 0; exitMoveFunc != 1;)
                {
                    printf("Введите 1 чтобы перейти на 1 элемент назад \n");
                    printf("Введите 2 чтобы перейти на 1 элемент вперед \n");
                    printf("Введите 3 чтобы выйти из функции перемещения \n");
                    _flushall();
                    command = getchar();
                    if(command == '1')
                    {
                        if(now == 1)
                        {
                            printf("Это первый эллемент движение назад не возможно ! \n");
                            printf("Нажмите Enter");
                            _flushall();
                            getchar();
                            break;
                        }
                        printAddress(name, now);
                        now -= 1;
                        printf(" -> ");
                        printAddress(name, now);
                        printf("\n");
                        printf("Вы на %d элементе \n", now);
                        processorName(name, now);    
                    }
                    if(command == '2')
                    {
                        if(now == amount(name))
                        {
                            printf("Это последний элемент движение вперед не возможно ! \n");
                            printf("Нажмите Enter");
                            _flushall();
                            getchar();
                            break;
                        }
                        printAddress(name, now);
                        now += 1;
                        printf(" -> ");
                        printAddress(name, now);
                        printf("\n");
                        printf("Вы на %d элементе \n", now);
                        processorName(name, now);    
                    }
                    if(command == '3')
                    {
                        exitMoveFunc = 1;
                        system("cls");

                    }                    
                }
                break;
            case 8:
                printElements(name, now);
                break;
            case 9:
                removeList(name);
                exit(0);
        }
        system("cls");
    }
}