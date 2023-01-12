#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

// 1 - Проверка на наличие элементов в структуре данных
// 2 - Получение количества элементов  в структуре данных
// 3 - Добавление элемента в структуру данных 
// 4 - Вставка элемента с одной или с другой стороны от текущего
// 5 - Удаление текущего элемента структуры данных
// 6 - Очистка структуры данных
// 7 - Перемещение по элементам структуры данных
// 8 - Чтение информации из текущего элемента структуры данных

void language()
{
    setlocale(LC_ALL, "Russian");
}

class PC_Info
{
protected:
    string pc_name, pc_processor, pc_videocard, pc_motherboard, pc_Case, pc_Monitor, pc_PowerUnit;
    int pc_HDD, pc_SSD, pc_fans;
    PC_Info* next = NULL;
    PC_Info* prev = NULL;

public:
    PC_Info()
    {
        cout << "создан элемент с адресом - " << this << endl;
        cout << "next - " << next << endl;
        cout << "prev - " << prev << endl;
        printf("нажмите Enter");
        _flushall();
        getchar();
        _flushall();
    }
    PC_Info(PC_Info* next_adr, PC_Info* prev_adr)
    {
        this->next = next_adr;
        this->prev = prev_adr;
        cout << "создан элемент с адресом - " << this << endl;
        cout << "next - " << next << endl;
        cout << "prev - " << prev << endl;
        printf("нажмите Enter");
        _flushall();
        getchar();
        _flushall();
    }
    PC_Info(string name, string processor, string videocard, string motherboard, string Case, string Monitor, string PowerUnit, int HDD, int SSD, int fans)
    {
        this->pc_name = name;
        this->pc_processor = processor;
        this->pc_videocard = videocard;
        this->pc_motherboard = motherboard;
        this->pc_Case = Case;
        this->pc_Monitor = Monitor;
        this->pc_PowerUnit = PowerUnit;
        this->pc_HDD = HDD;
        this->pc_SSD = SSD;
        this->pc_fans = fans;
        cout << "создан элемент с адресом - " << this << endl;
        cout << "next - " << next << endl;
        cout << "prev - " << prev << endl;
        printf("нажмите Enter");
        _flushall();
        getchar();
        _flushall();
    }
    PC_Info(string name, string processor, string videocard, string motherboard, string Case, string Monitor, string PowerUnit, int HDD, int SSD, int fans, PC_Info* next_adr, PC_Info* prev_adr)
    {
        this->pc_name = name;
        this->pc_processor = processor;
        this->pc_videocard = videocard;
        this->pc_motherboard = motherboard;
        this->pc_Case = Case;
        this->pc_Monitor = Monitor;
        this->pc_PowerUnit = PowerUnit;
        this->pc_HDD = HDD;
        this->pc_SSD = SSD;
        this->pc_fans = fans;
        this->next = next_adr;
        this->prev = prev_adr;
        cout << "создан элемент с адресом - " << this << endl;
        cout << "next - " << next << endl;
        cout << "prev - " << prev << endl;
        printf("нажмите Enter");
        _flushall();
        getchar();
        _flushall();
    }
    PC_Info(PC_Info* other, PC_Info* next_adr, PC_Info* prev_adr)
    {
        this->pc_name = other->get_name();
        this->pc_processor = other->get_processor();
        this->pc_videocard = other->get_videocard();
        this->pc_motherboard = other->get_motherboard();
        this->pc_Case = other->get_Case();
        this->pc_Monitor = other->get_Monitor();
        this->pc_PowerUnit = other->get_PowerUnit();
        this->pc_HDD = other->get_HDD();
        this->pc_SSD = other->get_SSD();
        this->pc_fans = other->get_fans();
        this->next = next_adr;
        this->prev = prev_adr;
        cout << "создан элемент с адресом - " << this << endl;
        cout << "next - " << next << endl;
        cout << "prev - " << prev << endl;
        printf("нажмите Enter");
        _flushall();
        getchar();
        _flushall();
    }
    ~PC_Info()
    {
        cout << "удален элемент с адресом - " << this << endl;
        printf("нажмите Enter");
        _flushall();
    }

    string get_name() { return this->pc_name; }
    string get_processor() { return this->pc_processor; }
    string get_videocard() { return this->pc_videocard; }
    string get_motherboard() { return this->pc_motherboard; }
    string get_Case() { return this->pc_Case; }
    string get_Monitor() { return this->pc_Monitor; }
    string get_PowerUnit() { return this->pc_PowerUnit; }
    int get_HDD() { return this->pc_HDD; }
    int get_SSD() { return this->pc_SSD; }
    int get_fans() { return this->pc_fans; }
    PC_Info* get_next() { return this->next; }
    PC_Info* get_last_adr()
    {
        PC_Info* tmp;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        return tmp;
    }
    PC_Info* get_prev() { return this->prev; }
    void set_next(PC_Info* next_adr) { this->next = next_adr; }
    void set_prev(PC_Info* prev_adr) { this->prev = prev_adr; }

    void add_el()
    {
        int create_val = 0;
        while (create_val != 1 && create_val != 2 && create_val != 3)
        {
            //system("cls");
            cout << "как заполнить параметры?" << endl;
            cout << "1 - не заполнять " << endl;
            cout << "2 - заполнить вручную" << endl;
            cout << "3 - скопировать имеющийся элемент" << endl;
            cin >> create_val;
        }
        if (create_val == 1)
        {
            PC_Info* tmp;
            tmp = this;
            while (true)
            {
                if (tmp->get_next() == NULL)
                {
                    break;
                }
                else
                {
                    tmp = tmp->get_next();
                }
            }
            tmp->set_next(new PC_Info(NULL, tmp));
        }
        if (create_val == 2)
        {
            string pc_name, pc_processor, pc_videocard, pc_motherboard, pc_Case, pc_Monitor, pc_PowerUnit;
            int pc_HDD, pc_SSD, pc_fans;
            PC_Info* tmp;
            tmp = this;
            while (true)
            {
                if (tmp->get_next() == NULL)
                {
                    break;
                }
                else
                {
                    tmp = tmp->get_next();
                }
            }

            _flushall();
            cout << endl << "Введите название компьютера:" << endl;
            getline(cin, pc_name);
            cout << "Введите название процессора:" << endl;
            getline(cin, pc_processor);
            cout << "Введите название видеокарты:" << endl;
            getline(cin, pc_videocard);
            cout << "Введите название материнской платы:" << endl;
            getline(cin, pc_motherboard);
            cout << "Введите название корпуса:" << endl;
            getline(cin, pc_Case);
            cout << "Введите название монитора:" << endl;
            getline(cin, pc_Monitor);
            cout << "Введите название Блока Питания:" << endl;
            getline(cin, pc_PowerUnit);
            cout << "Введите объем HDD-накопителя:" << endl;
            cin >>pc_HDD;
            cout << "Введите оббъем SSD-накопителя:" << endl;
            cin >> pc_SSD;
            cout << "Введите количество вентиляторов:" << endl;
            cin >> pc_fans;
            cout << endl;

            tmp->set_next(new PC_Info(pc_name, pc_processor, pc_videocard, pc_motherboard, pc_Case, pc_Monitor, pc_PowerUnit, pc_HDD, pc_SSD, pc_fans, NULL, tmp));
        }
        if (create_val == 3)
        {
            PC_Info* tmp, * last;
            int ammount = 1;
            int choice = 0;
            int ia = 1;
            tmp = this;
            while (true)
            {
                cout << tmp->pc_name << " - " << ammount << endl;
                if (tmp->get_next() == NULL)
                {
                    break;
                }
                else
                {
                    tmp = tmp->get_next();
                    ammount += 1;
                }
            }
            last = tmp;
            tmp = this;
            while (choice < 1 || choice > ammount)
            {
                _flushall();
                cout << "выберите компьютер для копирования: ";
                cin >> choice;
            }
            while (ia != choice)
            {
                tmp = tmp->get_next();
                ia++;
            }
            last->set_next(new PC_Info(tmp, NULL, tmp));
        }
    }
    void add_element_r()
    {
        PC_Info* tmp, * nex;
        tmp = this;
        nex = tmp->get_next();
        int create_val = 0;
        while (create_val != 1 && create_val != 2 && create_val != 3)
        {
            //system("cls");
            cout << "как заполнить параметры?" << endl;
            cout << "1 - не заполнять " << endl;
            cout << "2 - заполнить вручную" << endl;
            cout << "3 - скопировать имеющийся элемент" << endl;
            cin >> create_val;
        }
        if (create_val == 1)
        {
            this->set_next(new PC_Info(nex, this));
            nex->set_prev(this->get_next());
        }
        if (create_val == 2)
        {
            string pc_name, pc_processor, pc_videocard, pc_motherboard, pc_Case, pc_Monitor, pc_PowerUnit;
            int pc_HDD, pc_SSD, pc_fans;

            _flushall();
            cout << endl << "Введите название компьютера:" << endl;
            getline(cin, pc_name);
            cout << "Введите название процессора:" << endl;
            getline(cin, pc_processor);
            cout << "Введите название видеокарты:" << endl;
            getline(cin, pc_videocard);
            cout << "Введите название материнской платы:" << endl;
            getline(cin, pc_motherboard);
            cout << "Введите название корпуса:" << endl;
            getline(cin, pc_Case);
            cout << "Введите название монитора:" << endl;
            getline(cin, pc_Monitor);
            cout << "Введите название Блока Питания:" << endl;
            getline(cin, pc_PowerUnit);
            cout << "Введите объем HDD-накопителя:" << endl;
            cin >> pc_HDD;
            cout << "Введите объем SSD-накопителя:" << endl;
            cin >> pc_SSD;
            cout << "Введите количество вентиляторов:" << endl;
            cin >> pc_fans;
            cout << endl;

            this->set_next(new PC_Info(pc_name, pc_processor, pc_videocard, pc_motherboard, pc_Case, pc_Monitor, pc_PowerUnit, pc_HDD, pc_SSD, pc_fans, nex, this));
            nex->set_prev(this->get_next());
        }
        if (create_val == 3)
        {
            PC_Info* tmp, * last;
            int ammount = 1;
            int choice = 0;
            int ia = 1;
            tmp = this;

            while (true)
            {
                if (tmp->get_prev() == NULL)
                {
                    break;
                }
                else
                {
                    tmp = tmp->get_prev();
                }
            }
            while (true)
            {
                cout << tmp->pc_name << " - " << ammount << endl;
                if (tmp->get_next() == NULL)
                {
                    break;
                }
                else
                {
                    tmp = tmp->get_next();
                    ammount += 1;
                }
            }
            tmp = this;
            while (choice < 1 || choice > ammount)
            {
                _flushall();
                cout << "выберите компьютер для копирования: ";
                cin >> choice;
            }
            while (ia != choice)
            {
                tmp = tmp->get_next();
                ia++;
            }
            tmp->set_next(new PC_Info(tmp, nex, this));
            nex->set_prev(this->get_next());
        }
    }
    void add_element_ln()
    {
        int create_val = 0;
        while (create_val != 1 && create_val != 2 && create_val != 3)
        {
            //system("cls");
            cout << "как заполнить параметры?" << endl;
            cout << "1 - не заполнять " << endl;
            cout << "2 - заполнить вручную" << endl;
            cout << "3 - скопировать имеющийся элемент" << endl;
            cin >> create_val;
        }
        if (create_val == 1)
        {
            this->set_prev(new PC_Info(this, NULL));
        }
        if (create_val == 2)
        {
            string pc_name, pc_processor, pc_videocard, pc_motherboard, pc_Case, pc_Monitor, pc_PowerUnit;
            int pc_HDD, pc_SSD, pc_fans;
            cout << endl << "Введите название компьютера:" << endl;
            getline(cin, pc_name);
            cout << "Введите название процессора:" << endl;
            getline(cin, pc_processor);
            cout << "Введите название видеокарты:" << endl;
            getline(cin, pc_videocard);
            cout << "Введите название материнской платы:" << endl;
            getline(cin, pc_motherboard);
            cout << "Введите название корпуса:" << endl;
            getline(cin, pc_Case);
            cout << "Введите название монитора:" << endl;
            getline(cin, pc_Monitor);
            cout << "Введите название Блока Питания:" << endl;
            getline(cin, pc_PowerUnit);
            cout << "Введите объем HDD-накопителя:" << endl;
            cin >> pc_HDD;
            cout << "Введите объем SSD-накопителя:" << endl;
            cin >> pc_SSD;
            cout << "Введите количество вентиляторов:" << endl;
            cin >> pc_fans;
            cout << endl;
            this->set_prev(new PC_Info(pc_name, pc_processor, pc_videocard, pc_motherboard, pc_Case, pc_Monitor, pc_PowerUnit, pc_HDD, pc_SSD, pc_fans, this, NULL));
        }
        if (create_val == 3)
        {
            PC_Info* tmp;
            int ammount = 1;
            int choice = 0;
            int ia = 1;
            tmp = this;
            while (true)
            {
                cout << tmp->pc_name << " - " << ammount << endl;
                if (tmp->get_next() == NULL)
                {
                    break;
                }
                else
                {
                    tmp = tmp->get_next();
                    ammount += 1;
                }
            }
            tmp = this;
            while (choice < 1 || choice > ammount)
            {
                _flushall();
                cout << "выберите компьютер для копирования: ";
                cin >> choice;
            }
            while (ia != choice)
            {
                tmp = tmp->get_next();
                ia++;
            }
            this->set_prev(new PC_Info(tmp, this, NULL));
        }
    }
    void add_element_ll()
    {
        int create_val = 0;
        while (create_val != 1 && create_val != 2 && create_val != 3)
        {
            //system("cls");
            cout << "как заполнить параметры?" << endl;
            cout << "1 - не заполнять " << endl;
            cout << "2 - заполнить вручную" << endl;
            cout << "3 - скопировать имеющийся элемент" << endl;
            cin >> create_val;
        }
        if (create_val == 1)
        {
            PC_Info* pr;
            pr = this->get_prev();
            this->set_prev(new PC_Info(this, pr));
            pr->set_next(this->get_prev());
        }
        if (create_val == 2)
        {
            PC_Info* pr;
            pr = this->get_prev();
            string pc_name, pc_processor, pc_videocard, pc_motherboard, pc_Case, pc_Monitor, pc_PowerUnit;
            int pc_HDD, pc_SSD, pc_fans;
            cout << endl << "Введите название компьютера:" << endl;
            getline(cin, pc_name);
            cout << "Введите название процессора:" << endl;
            getline(cin, pc_processor);
            cout << "Введите название видеокарты:" << endl;
            getline(cin, pc_videocard);
            cout << "Введите название материнской платы:" << endl;
            getline(cin, pc_motherboard);
            cout << "Введите название корпуса:" << endl;
            getline(cin, pc_Case);
            cout << "Введите название монитора:" << endl;
            getline(cin, pc_Monitor);
            cout << "Введите название Блока Питания:" << endl;
            getline(cin, pc_PowerUnit);
            cout << "Введите объем HDD-накопителя:" << endl;
            cin >> pc_HDD;
            cout << "Введите объем SSD-накопителя:" << endl;
            cin >> pc_SSD;
            cout << "Введите количество вентиляторов:" << endl;
            cin >> pc_fans;
            cout << endl;
            this->set_prev(new PC_Info(pc_name, pc_processor, pc_videocard, pc_motherboard, pc_Case, pc_Monitor, pc_PowerUnit, pc_HDD, pc_SSD, pc_fans, this, pr));
            pr->set_next(this->get_prev());
        }
        if (create_val == 3)
        {
            PC_Info* tmp, * pr;
            pr = this->get_prev();
            int ammount = 1;
            int choice = 0;
            int ia = 1;
            tmp = this;
            while (true)
            {
                cout << tmp->pc_name << " - " << ammount << endl;
                if (tmp->get_next() == NULL)
                {
                    break;
                }
                else
                {
                    tmp = tmp->get_next();
                    ammount += 1;
                }
            }
            tmp = this;
            while (choice < 1 || choice > ammount)
            {
                _flushall();
                cout << "выберите компьютер для копирования: ";
                cin >> choice;
            }
            while (ia != choice)
            {
                tmp = tmp->get_next();
                ia++;
            }
            this->set_prev(new PC_Info(tmp, this, pr));
            pr->set_next(this->get_prev());
        }
    }
};
class PCs
{
protected:
    PC_Info* now;
    PC_Info* start;
public:
    void set_start(PC_Info* start_adr) { start = start_adr; }
    PC_Info* get_start() { return start; }
    void set_now(PC_Info* now_adr) { now = now_adr; }
    PC_Info* get_now() { return now; }
    PCs create_list()
    {
        int create_val = 0;
        while (create_val != 1 && create_val != 2)
        {
            system("cls");
            cout << "как заполнить параметры?" << endl;
            cout << "1 - не заполнять " << endl;
            cout << "2 - заполнить вручную" << endl;
            cin >> create_val;
        }
        if (create_val == 2)
        {
            string pc_name, pc_processor, pc_videocard, pc_motherboard, pc_Case, pc_Monitor, pc_PowerUnit;
            int pc_HDD, pc_SSD, pc_fans;

            _flushall();
            cout << endl << "Введите название компьютера:" << endl;
            getline(cin, pc_name);
            cout << "Введите название процессора:" << endl;
            getline(cin, pc_processor);
            cout << "Введите название видеокарты:" << endl;
            getline(cin, pc_videocard);
            cout << "Введите название материнской платы:" << endl;
            getline(cin, pc_motherboard);
            cout << "Введите название корпуса:" << endl;
            getline(cin, pc_Case);
            cout << "Введите название монитора:" << endl;
            getline(cin, pc_Monitor);
            cout << "Введите название Блока Питания:" << endl;
            getline(cin, pc_PowerUnit);
            cout << "Введите объем HDD-накопителя:" << endl;
            cin >> pc_HDD;
            cout << "Введите объем SSD-накопителя:" << endl;
            cin >> pc_SSD;
            cout << "Введите количество вентиляторов:" << endl;
            cin >> pc_fans;
            cout << endl;

            set_start(new PC_Info(pc_name, pc_processor, pc_videocard, pc_motherboard, pc_Case, pc_Monitor, pc_PowerUnit, pc_HDD, pc_SSD, pc_fans));
            set_now(get_start());
        }
        if (create_val == 1)
        {
            set_start(new PC_Info());
            set_now(get_start());
        }
    }
    PCs add_element()
    {
        PC_Info* tmp;
        tmp = start;
        tmp->add_el();
        set_now(tmp->get_next());
    }
    PCs add_element_right()
    {
        if (now->get_next() == NULL)
        {
            PC_Info* tmp;
            tmp = start;
            tmp->add_el();
            set_now(tmp->get_next());
        }
        else
        {
            now->add_element_r();
            set_now(now->get_next());
        }
    }
    PCs add_element_left()
    {
        if (now->get_prev() == NULL)
        {
            now->add_element_ln();
            set_now(now->get_prev());
            set_start(get_now());
        }
        else
        {
            now->add_element_ll();
            set_now(now->get_prev());
        }
    }
    del_PCs()
    {
        PC_Info* tmp;
        while (start)
        {
            cout << "Удаление объекта: " << start << endl;
            tmp = start->get_next();
            delete start;
            start = tmp;
        }
        cout << "Деструктор завершил свою работу" << endl << endl;
    }
    void print_all()
    {
        cout << "-----------------------------------" << endl;
        cout << "адрес текущего элемента - " << now << endl;
        cout << "адрес следущего элемента - " << now->get_next() << endl;
        cout << "адрес предыдущего  элемента - " << now->get_prev() << endl;
        cout << "-----------------------------------" << endl;
        cout << "название компьютера - " << now->get_name() << endl;
        cout << "материнская плата - " << now->get_motherboard() << endl;
        cout << "видеоткарта - " << now->get_videocard() << endl;
        cout << "процессор - " << now->get_processor() << endl;
        cout << "корпус - " << now->get_Case() << endl;
        cout << "монитор - " << now->get_Monitor() << endl;
        cout << "Блок питания - " << now->get_PowerUnit() << endl;
        cout << "объем HDD - " << now->get_HDD() << endl;
        cout << "объем SSD - " << now->get_SSD() << endl;
        cout << "количество вентиляторов - " << now->get_fans() << endl;
        cout << "-----------------------------------" << endl;
        printf("нажмите Enter");
        _flushall();
        getchar();
        _flushall();
    }
    void nex()
    {
        if (now->get_next() != NULL)
        {
            cout << "переход с " << now;
            now = now->get_next();
            cout << " на " << now << endl;
            printf("нажмите Enter");
            _flushall();
            getchar();
            _flushall();
        }
        else {
            cout << "это последний элемент" << endl;
            printf("нажмите Enter");
            _flushall();
            getchar();
            _flushall();
        }
    }
    void pre()
    {
        if (now->get_prev() != NULL)
        {
            cout << "переход с " << now;
            now = now->get_prev();
            cout << " на " << now << endl;
            printf("нажмите Enter");
            _flushall();
            getchar();
            _flushall();
        }
        else {
            cout << "это первый элемент" << endl;
            printf("нажмите Enter");
            _flushall();
            getchar();
            _flushall();
        }
    }
    int ammount()

    {
        PC_Info* tmp;
        tmp = start;
        int amm = 0;
        do
        {
            amm++;
            tmp = tmp->get_next();
        } while (tmp != NULL);
        return amm;
    }
    int del_el()
    {
        if (now->get_prev() == NULL && now->get_next() == NULL)
        {
            cout << "удален элемент с адресом - " << now << endl;
            delete now;
            printf("нажмите Enter");
            _flushall();
            getchar();
            _flushall();
            return 1;
        }
        else if (now->get_prev() == NULL)
        {
            PC_Info* nextt;
            nextt = now->get_next();
            cout << "удален элемент с адресом - " << now << endl;
            delete now;
            set_start(nextt);
            set_now(nextt);
            nextt->set_prev(NULL);
            printf("нажмите Enter");
            _flushall();
            getchar();
            _flushall();
            return 0;
        }
        else if (now->get_next() == NULL)
        {
            PC_Info* prevv;
            prevv = now->get_prev();
            cout << "удален элемент с адресом - " << now << endl;
            delete now;
            set_now(prevv);
            prevv->set_next(NULL);
            printf("нажмите Enter");
            _flushall();
            getchar();
            _flushall();
            return 0;
        }
        else
        {
            PC_Info* prevv, * nextt;
            prevv = now->get_prev();
            nextt = now->get_next();
            cout << "удален элемент с адресом - " << now << endl;
            delete now;
            prevv->set_next(nextt);
            nextt->set_prev(prevv);
            set_now(prevv);
            printf("нажмите Enter");
            _flushall();
            getchar();
            _flushall();
            return 0;
        }
    }
};
int menu()
{
    system("cls");
    int change = 0;
    cout << "1 - Проверка на наличие элементов в структуре данных" << endl;
    cout << "2 - Получение количества элементов  в структуре данных" << endl;
    cout << "3 - Добавление элемента  в структуру данных" << endl;
    cout << "4 - Вставка элемента с одной или с другой стороны от текущего" << endl;
    cout << "5 - Удаление текущего элемента структуры данных" << endl;
    cout << "6 - Очистка структуры данных" << endl;
    cout << "7 - Перемещение по элементам структуры данных" << endl;
    cout << "8 - Чтение информации из текущего элемента структуры данных" << endl;
    cin >> change;
    cout << endl;
    return change;
}