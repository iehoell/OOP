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
            printf("�� �� %d �������� \n", now);
            
        }
        else
        {
            for(int exit_s = 0; exit_s !=1;)
            {
                printf("������� 1 ����� ������� ��������� \n");
                printf("������� 2 ����� �� ��������� \n");
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
                    printf("����� �� ���������");
                    exit(0);
                }
            }
        }
        printf("// 1 - �������� �� ������� ��������� � ��������� ������ \n// 2 - ��������� ���������� ���������  � ��������� ������ \n// 3 - ���������� ��������  � ��������� ������ \n// 4 - ������� �������� � ����� ��� � ������ ������� �� �������� \n// 5 - �������� �������� �������� ��������� ������ \n// 6 - ������� ��������� ������ \n// 7 - ����������� �� ��������� ��������� ������ \n// 8 - ������ ���������� �� �������� �������� ��������� ������ \n// 9 - ����� �� ���������\n");
        _flushall();
        scanf("%d", &command);
        switch (command){
            case 1:
                checkForAvailability(name);
                printf("������� Enter");
                _flushall();
                getchar();
                break;
            case 2:
                printf("� ��������� %d ��������(-��) \n", amount(name));
                printf("������� Enter");
                _flushall();
                getchar();
                break;
            case 3:
                addElement(name);
                now += 1;
                break;
            case 4:
                printf("������� 1 ����� �������� ������� ����� \n");
                printf("������� 2 ����� �������� ������� ������ \n");
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
                    printf("����������� ������� ������� \n");
                }
                break;
            case 5:
                printf("��� �������� - ");
                processorName(name,now);
                printf("����� ���������� �������� - ");
                printAddress(name, now);
                printf("\n");
                if(deleteElement(name, now) != 1)
                {
                    now = now - 1;
                }
                printf("������� Enter");
                _flushall();
                getchar();
                break;
            case 6:
                removeList(name);
                printf("������� Enter");
                _flushall();
                getchar();
                now = 0;
                break;
            case 7:
                for(int exitMoveFunc = 0; exitMoveFunc != 1;)
                {
                    printf("������� 1 ����� ������� �� 1 ������� ����� \n");
                    printf("������� 2 ����� ������� �� 1 ������� ������ \n");
                    printf("������� 3 ����� ����� �� ������� ����������� \n");
                    _flushall();
                    command = getchar();
                    if(command == '1')
                    {
                        if(now == 1)
                        {
                            printf("��� ������ �������� �������� ����� �� �������� ! \n");
                            printf("������� Enter");
                            _flushall();
                            getchar();
                            break;
                        }
                        printAddress(name, now);
                        now -= 1;
                        printf(" -> ");
                        printAddress(name, now);
                        printf("\n");
                        printf("�� �� %d �������� \n", now);
                        processorName(name, now);    
                    }
                    if(command == '2')
                    {
                        if(now == amount(name))
                        {
                            printf("��� ��������� ������� �������� ������ �� �������� ! \n");
                            printf("������� Enter");
                            _flushall();
                            getchar();
                            break;
                        }
                        printAddress(name, now);
                        now += 1;
                        printf(" -> ");
                        printAddress(name, now);
                        printf("\n");
                        printf("�� �� %d �������� \n", now);
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