#include <iostream>
#include <string>
using namespace std;
// 1 - �������� �� ������� ��������� � ��������� ������
// 2 - ��������� ���������� ���������  � ��������� ������
// 3 - ���������� ��������  � ��������� ������ 
// 4 - ������� �������� � ����� ��� � ������ ������� �� ��������
// 5 - �������� �������� �������� ��������� ������
// 6 - ������� ��������� ������
// 7 - ����������� �� ��������� ��������� ������
// 8 - ������ ���������� �� �������� �������� ��������� ������
void language()
{
    setlocale(LC_ALL, "Russian");
}
void help()
{

}

//--------------------------------------------------------------------

struct list
{
    list* next; // ��������� �� ��������� �������
    list* prev; // ��������� �� ���������� �������
    string processor, videocard, motherboard, Case;
    int cooler, monitor, powerUnit, RAM, SSD, HDD;
};

//--------------------------------------------------------------------

int amount(struct list* lst)
{
    struct list* tmp;
    tmp = lst;
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

//--------------------------------------------------------------------

struct list* initialization()  // ������������� ������
{
    struct list* lst = new list; // ��������� ������ ��� ������ ������
    lst->next = NULL; // ��������� �� ��������� ����
    lst->prev = NULL; // ��������� �� ���������� ����
    return lst;
}

//--------------------------------------------------------------------
struct list* getAddress(struct list* lst, int N)
{
    struct list* tmp;
    if (N < 1)
    {
        return lst;
    }
    if (N > amount(lst))
    {
        return NULL;
    }
    tmp = lst;
    for (int count = 0; count < N - 1; count++)
    {
        tmp = tmp->next;
    }
    return tmp;
}

//--------------------------------------------------------------------

void filling(struct list* tmp)
{
    cout << "������� �������� ���������� - ";
    cin >> tmp->processor;
    cout << "������� �������� ���������� - ";
    cin >> tmp->videocard;
    cout << "������� �������� ����������� ����� - ";
    cin >> tmp->motherboard;
    cout << "������� �������� ������� - ";
    cin >> tmp->Case;
    cout << "������� ����� ����������� ������ - ";
    cin >> tmp->RAM;
    cout << "������� ����� SSD ���������� - ";
    cin >> tmp->SSD;
    cout << "������� ����� HDD ���������� - ";
    cin >> tmp->HDD;
    cout << "������� ���������� ������� - ";
    cin >> tmp->cooler;
    cout << "������� ���������� ��������� - ";
    cin >> tmp->monitor;
    cout << "������� �������� ����� ������� - ";
    cin >> tmp->powerUnit;
    cout << endl;
}

//--------------------------------------------------------------------

void propertyChange(struct list* tmp1, struct list* tmp2) // 1-�������� ���� ������ �������� 2-�������� ������ �����
{
    tmp1->processor = tmp2->processor;
    tmp1->videocard = tmp2->videocard;
    tmp1->motherboard = tmp2->motherboard;
    tmp1->Case = tmp2->Case;
    tmp1->RAM = tmp2->RAM;
    tmp1->SSD = tmp2->SSD;
    tmp1->HDD = tmp2->HDD;
    tmp1->cooler = tmp2->cooler;
    tmp1->monitor = tmp2->monitor;
    tmp1->powerUnit = tmp2->powerUnit;
}

//--------------------------------------------------------------------

void addElement(list* lst)
{
    struct list* tmp, * preev;
    preev = getAddress(lst, amount(lst));
    tmp = new list;
    tmp->next = NULL;
    tmp->prev = preev;
    preev->next = tmp;
    filling(tmp);
    cout << tmp->processor << endl;
}

//--------------------------------------------------------------------

void printElements(struct list* lst, int numell)
{
    struct list* tmp;
    tmp = getAddress(lst, numell);
    cout<<"��������� - ";
    cout << tmp->processor << endl;
    cout<<"���������� - ";
    cout << tmp->videocard << endl;
    cout<<"����������� ����� - ";
    cout << tmp->motherboard << endl;
    cout<<"������ - ";
    cout << tmp->Case << endl;
    cout << "����� RAM - ";
    cout << tmp->RAM << endl;
    cout << "����� SSD - ";
    cout << tmp->SSD << endl;
    cout << "����� HDD - ";
    cout << tmp->HDD << endl;
    cout<<"���������� ������� - ";
    cout << tmp->cooler << endl;
    cout<<"���������� ��������� - ";
    cout << tmp->monitor << endl;
    cout<<"�������� �� - ";
    cout << tmp->powerUnit << endl;
    cout<<"������� Enter";
    _flushall();
    getchar();
}
//--------------------------------------------------------------------

void addRightElement(list* lst, int numell)
{
    struct list* left, * right, * tmp;
    left = getAddress(lst, numell);
    tmp = new list;
    if (left->next != NULL)
    {
        right = getAddress(lst, numell + 1);
        left->next = tmp;
        tmp->next = right;
        tmp->prev = left;
        right->prev = tmp;
        filling(tmp);
    }
    if (left->next == NULL)
    {
        left->next = tmp;
        tmp->prev = left;
        tmp->next = NULL;
        filling(tmp);
    }
}

//--------------------------------------------------------------------

void addLeftElement(list* lst, int numell)
{
    struct list* left, * now, * tmp, * buf1;
    tmp = new list;
    now = getAddress(lst, numell);
    if (now->prev == NULL)
    {
        if (now->next == NULL)
        {
            now->next = tmp;
            tmp->prev = now;
            tmp->next = NULL;
            propertyChange(tmp, now);
            filling(now);
        }
        else
        {
            buf1 = getAddress(lst, numell + 1);
            now->next = tmp;
            tmp->prev = now;
            tmp->next = buf1;
            buf1->prev = tmp;
            propertyChange(tmp, now);
            filling(now);
        }
    }
    else
    {
        buf1 = getAddress(lst, numell - 1);
        buf1->next = tmp;
        now->prev = tmp;
        tmp->next = now;
        tmp->prev = buf1;
        filling(tmp);
    }
}

//--------------------------------------------------------------------

void print(struct list* lst, int numell)
{
    struct list* tmp;
    tmp = getAddress(lst, numell - 1);
    cout<<tmp->processor.c_str()<<endl;
    cout<<tmp->next<<" || "<<tmp->prev<< endl;

}

//--------------------------------------------------------------------

void checkForAvailability(struct list* lst)
{
    if (amount(lst) == 0)
    {
        cout<<"� ��������� ��� ���������"<<endl;
    }
    else
    {
        cout<<"� ��������� "<<amount(lst)<<" ���������"<<endl;
    }
    getchar();
}

//--------------------------------------------------------------------

void processorName(struct list* lst, int numell)
{
    struct list* tmp;
    tmp = getAddress(lst, numell);
    cout << tmp->processor << endl;
}

//--------------------------------------------------------------------

int deleteElement(struct list* lst, int numell)
{
    struct list* left, * now, * right;
    now = getAddress(lst, numell);
    if (now->prev == NULL)
    {
        cout<<"�������� ��������� �������� ����������"<<endl;
        return 1;
    }
    if (now->next == NULL)
    {
        left = getAddress(lst, numell - 1);
        left->next = NULL;
        delete(now);
        return 0;
    }
    else
    {
        left = getAddress(lst, numell - 1);
        right = getAddress(lst, numell + 1);
        left->next = right;
        right->prev = left;
        delete(now);
        return 0;
    }
}

//--------------------------------------------------------------------

void removeList(struct list* lst)
{
    list* tmp;
    while (lst) {
        tmp = lst->next;
        delete(lst);
        lst = tmp;
    }
    cout<<"�������� ��������� ������ ���� ���������, ��� �������� ����� �� ���������"<<endl;
}

void printAddress(struct list* lst, int numell)
{
    list* tmp;
    tmp = getAddress(lst, numell);
    cout << tmp;
}