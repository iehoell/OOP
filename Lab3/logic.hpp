#include <windows.h>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// 1 - �������� �� ������� ��������� � ��������� ������
// 2 - ��������� ���������� ���������  � ��������� ������
// 3 - ���������� �������� � ��������� ������ 
// 4 - ������� �������� � ����� ��� � ������ ������� �� ��������
// 5 - �������� �������� �������� ��������� ������
// 6 - ������� ��������� ������
// 7 - ����������� �� ��������� ��������� ������
// 8 - ������ ���������� �� �������� �������� ��������� ������

void language()
{
    setlocale(LC_ALL, "Russian");
}

void filling_in_parameters(string* pc_n, string* pc_proc, string* pc_video, string* pc_mother, string* pc_case, string* pc_monitor, string* pc_PU, int* pc_HDD, int* pc_SSD, int* pc_fans)
{
    int che;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl << "������� �������� ����������:" << endl;
    getline(cin, *pc_n);
    cout << "������� �������� ����������:" << endl;
    getline(cin, *pc_proc);
    cout << "������� �������� ����������:" << endl;
    getline(cin, *pc_video);
    cout << "������� �������� ����������� �����:" << endl;
    getline(cin, *pc_mother);
    cout << "������� �������� �������:" << endl;
    getline(cin, *pc_case);
    cout << "������� �������� ��������:" << endl;
    getline(cin, *pc_monitor);
    cout << "������� �������� ����� �������:" << endl;
    getline(cin, *pc_PU);
    cout << "������� �������� �������� �����:" << endl;
    while (!(cin >> *pc_HDD) && !(cin >> che))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "������� �� ���������� ��������!!!" << endl;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "������� ����� SSD-����������:" << endl;
    while (!(cin >> *pc_SSD) && !(cin >> che))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "������� �� ���������� ��������!!!" << endl;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "������� ���-�� ������������:" << endl;
    while (!(cin >> *pc_fans) && !(cin >> che))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "������� �� ���������� ��������!!!" << endl;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    cin.clear();
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
        cout << "������ ������� � �������� - " << this << endl;
        cout << "next - " << next << endl;
        cout << "prev - " << prev << endl;
        printf("������� Enter");
        _flushall();
        getchar();
        _flushall();
    }
    PC_Info(PC_Info* next_adr, PC_Info* prev_adr)
    {
        this->next = next_adr;
        this->prev = prev_adr;
        cout << "������ ������� � �������� - " << this << endl;
        cout << "next - " << next << endl;
        cout << "prev - " << prev << endl;
        printf("������� Enter");
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
        cout << "������ ������� � �������� - " << this << endl;
        cout << "next - " << next << endl;
        cout << "prev - " << prev << endl;
        printf("������� Enter");
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
        cout << "������ ������� � �������� - " << this << endl;
        cout << "next - " << next << endl;
        cout << "prev - " << prev << endl;
        printf("������� Enter");
        _flushall();
        getchar();
        _flushall();
    }
    PC_Info(PC_Info* other,PC_Info* next_adr, PC_Info* prev_adr)
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
        cout << "������ ������� � ������� - " << this << endl;
        cout << "next - " << next << endl;
        cout << "prev - " << prev << endl;
        printf("������� Enter");
        _flushall();
        getchar();
        _flushall();
    }
    ~PC_Info()
    {
        cout << "������ ������� � ������� - " << this << endl;
        _flushall();
    }
    void set_name(string str) { this->pc_name = str; }
    void set_processor(string str) { this->pc_processor = str; }
    void set_videocard(string str) { this->pc_videocard = str; }
    void set_motherboard(string str) { this->pc_motherboard = str; }
    void set_Case(string str) { this->pc_Case = str; }
    void set_Monitor(string str) { this->pc_Monitor = str; }
    void set_PowerUnit(string str) { this->pc_PowerUnit = str; }
    void set_HDD(int intValue) { this->pc_HDD = intValue; }
    void set_SSD(int intValue) { this->pc_SSD = intValue; }
    void set_fans(int intValue) { this->pc_fans = intValue; }

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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "��� ��������� ���������?" << endl;
            cout << "1 - �� ��������� " << endl;
            cout << "2 - ��������� �������" << endl;
            cout << "3 - ����������� ��������� �������" << endl;
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
            filling_in_parameters(&pc_name, &pc_processor, &pc_videocard, &pc_motherboard, &pc_Case, &pc_Monitor, &pc_PowerUnit, &pc_HDD, &pc_SSD, &pc_fans);
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
                cout << "�������� ��������� ��� �����������: ";
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "��� ��������� ���������?" << endl;
            cout << "1 - �� ��������� " << endl;
            cout << "2 - ��������� �������" << endl;
            cout << "3 - ����������� ��������� �������" << endl;
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
            filling_in_parameters(&pc_name, &pc_processor, &pc_videocard, &pc_motherboard, &pc_Case, &pc_Monitor, &pc_PowerUnit, &pc_HDD, &pc_SSD, &pc_fans);
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
                cout << "�������� ��������� ��� �����������: ";
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "��� ��������� ���������?" << endl;
            cout << "1 - �� ��������� " << endl;
            cout << "2 - ��������� �������" << endl;
            cout << "3 - ����������� ��������� �������" << endl;
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
            filling_in_parameters(&pc_name, &pc_processor, &pc_videocard, &pc_motherboard, &pc_Case, &pc_Monitor, &pc_PowerUnit, &pc_HDD, &pc_SSD, &pc_fans);
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
                cout << "�������� ��������� ��� �����������: ";
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "��� ��������� ���������?" << endl;
            cout << "1 - �� ��������� " << endl;
            cout << "2 - ��������� �������" << endl;
            cout << "3 - ����������� ��������� �������" << endl;
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
            filling_in_parameters(&pc_name, &pc_processor, &pc_videocard, &pc_motherboard, &pc_Case, &pc_Monitor, &pc_PowerUnit, &pc_HDD, &pc_SSD, &pc_fans);
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
                cout << "�������� ��������� ��� �����������: ";
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
    void prThis()
    {
        cout << this << endl;
        system("pause");
    }
    void operator = (PC_Info& C1)
    {
        this->pc_motherboard = C1.pc_motherboard;
        this->pc_name = C1.pc_name;
        this->pc_videocard = C1.pc_videocard;
        this->pc_Case = C1.pc_Case;
        this->pc_Monitor = C1.pc_Monitor;
        this->pc_PowerUnit = C1.pc_PowerUnit;
        this->pc_processor = C1.pc_processor;
        this->pc_HDD = C1.pc_HDD;
        this->pc_SSD = C1.pc_SSD;
        this->pc_fans = C1.pc_fans;
    }
    bool operator == (PC_Info& C1)
    {
        if
            (
                this->pc_motherboard == C1.pc_motherboard && this->pc_name == C1.pc_name && this->pc_videocard == C1.pc_videocard &&
                this->pc_Case == C1.pc_Case && this->pc_Monitor == C1.pc_Monitor && this->pc_PowerUnit == C1.pc_PowerUnit && this->pc_processor == C1.pc_processor &&
                this->pc_HDD == C1.pc_HDD && this->pc_SSD == C1.pc_SSD && this->pc_fans == C1.pc_fans
                )
            return true;
        else
            return false;
    }
    bool operator != (PC_Info& C1)
    {
        if
            (
                this->pc_motherboard != C1.pc_motherboard || this->pc_name != C1.pc_name || this->pc_videocard != C1.pc_videocard ||
                this->pc_Case != C1.pc_Case || this->pc_Monitor != C1.pc_Monitor || this->pc_PowerUnit != C1.pc_PowerUnit || this->pc_processor != C1.pc_processor ||
                this->pc_HDD != C1.pc_HDD || this->pc_SSD != C1.pc_SSD || this->pc_fans != C1.pc_fans
                )
            return true;
        else
            return false;
    }
    bool operator < (PC_Info& C1)
    {
        if (this->pc_SSD < C1.pc_SSD)return true;
        else return false;
    }
    bool operator > (PC_Info& C1)
    {
        if (this->pc_SSD > C1.pc_SSD)return true;
        else return false;
    }
    bool operator <= (PC_Info& C1)
    {
        if (this->pc_SSD <= C1.pc_SSD)return true;
        else return false;
    }
    bool operator >= (PC_Info& C1)
    {
        if (this->pc_SSD >= C1.pc_SSD)return true;
        else return false;
    }
    friend std::istream& operator >> (std::istream& in, PC_Info* pc)
    {
        cout << "" << endl;
        string pc_name, pc_processor, pc_videocard, pc_motherboard, pc_Case, pc_Monitor, pc_PowerUnit;
        int pc_HDD, pc_SSD, pc_fans;

        in >> pc_name;
        in >> pc_processor;
        in >> pc_videocard;
        in >> pc_motherboard;
        in >> pc_Case;
        in >> pc_Monitor;
        in >> pc_PowerUnit;
        in >> pc_HDD;
        in >> pc_SSD;
        in >> pc_fans;

        pc->set_name(pc_name);
        pc->set_processor(pc_processor);
        pc->set_videocard(pc_videocard);
        pc->set_motherboard(pc_motherboard);
        pc->set_Case(pc_Case);
        pc->set_Monitor(pc_Monitor);
        pc->set_PowerUnit(pc_PowerUnit);
        pc->set_HDD(pc_HDD);
        pc->set_SSD(pc_SSD);
        pc->set_fans(pc_fans);
        return in;
    }
    friend std::istream& operator << (std::istream& in, PC_Info* pc)
    {
        cout << "�������� �� - " << pc->get_name() << endl;
        cout << "����������� ����� - " << pc->get_motherboard() << endl;
        cout << "���������� - " << pc->get_videocard() << endl;
        cout << "��������� - " << pc->get_processor() << endl;
        cout << "������ - " << pc->get_Case() << endl;
        cout << "������� - " << pc->get_Monitor() << endl;
        cout << "���� ������� - " << pc->get_PowerUnit() << endl;
        cout << "����� �������� ����� - " << pc->get_HDD() << endl;
        cout << "����� SSD-���������� - " << pc->get_SSD() << endl;
        cout << "���������� ������������ - " << pc->get_fans() << endl;
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "��� ��������� ���������?" << endl;
            cout << "1 - �� ��������� " << endl;
            cout << "2 - ��������� �������" << endl;
            cin >> create_val;
        }
        if (create_val == 2)
        {
            string pc_name, pc_processor, pc_videocard, pc_motherboard, pc_Case, pc_Monitor, pc_PowerUnit;
            int pc_HDD, pc_SSD, pc_fans;
            filling_in_parameters(&pc_name, &pc_processor, &pc_videocard, &pc_motherboard, &pc_Case, &pc_Monitor, &pc_PowerUnit, &pc_HDD, &pc_SSD, &pc_fans);
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
            //cout << "�������� �������: " << start << endl;
            tmp = start->get_next();
            delete start;
            start = tmp;
        }
        cout << "���������� �������� ���� ������" << endl << endl;
    }
    void print_all()
    {
        cout << "-----------------------------------" << endl;
        cout << "������ �������� �������� - " << now << endl;
        cout << "������ ��������� �������� - " << now->get_next() << endl;
        cout << "������ �����������  �������� - " << now->get_prev() << endl;
        cout << "-----------------------------------" << endl;
        cout << "��� ���������� - " << now->get_name() << endl;
        cout << "����������� ����� - " << now->get_motherboard() << endl;
        cout << "���������� - " << now->get_videocard() << endl;
        cout << "��������� - " << now->get_processor() << endl;
        cout << "������ - " << now->get_Case() << endl;
        cout << "������� - " << now->get_Monitor() << endl;
        cout << "���� ������� - " << now->get_PowerUnit() << endl;
        cout << "����� �������� ����� - " << now->get_HDD() << endl;
        cout << "����� SSD-���������� - " << now->get_SSD() << endl;
        cout << "���������� ������������ - " << now->get_fans() << endl;
        cout << "-----------------------------------" << endl;
        printf("������� Enter");
        _flushall();
        getchar();
        _flushall();
    }
    void nex()
    {
        if (now->get_next() != NULL)
        {
            cout << "������� � " << now;
            now = now->get_next();
            cout << " �� " << now << endl;
            printf("������� Enter");
            _flushall();
            getchar();
            _flushall();
        }
        else {
            cout << "��� ��������� �������" << endl;
            printf("������� Enter");
            _flushall();
            getchar();
            _flushall();
        }
    }
    void pre()
    {
        if (now->get_prev() != NULL)
        {
            cout << "������� � " << now;
            now = now->get_prev();
            cout << " �� " << now << endl;
            printf("������� Enter");
            _flushall();
            getchar();
            _flushall();
        }
        else {
            cout << "��� ������ �������" << endl;
            printf("������� Enter");
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
            cout << "������ ������� � �������� - " << now << endl;
            delete now;
            printf("������� Enter");
            _flushall();
            getchar();
            _flushall();
            return 1;
        }
        else if (now->get_prev() == NULL)
        {
            PC_Info* nextt;
            nextt = now->get_next();
            cout << "������ ������� � �������� - " << now << endl;
            delete now;
            set_start(nextt);
            set_now(nextt);
            nextt->set_prev(NULL);
            printf("������� Enter");
            _flushall();
            getchar();
            _flushall();
            return 0;
        }
        else if (now->get_next() == NULL)
        {
            PC_Info* prevv;
            prevv = now->get_prev();
            cout << "������ ������� � �������� - " << now << endl;
            delete now;
            set_now(prevv);
            prevv->set_next(NULL);
            printf("������� Enter");
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
            cout << "������ ������� � �������� - " << now << endl;
            delete now;
            prevv->set_next(nextt);
            nextt->set_prev(prevv);
            set_now(prevv);
            printf("������� Enter");
            _flushall();
            getchar();
            _flushall();
            return 0;
        }
    }
    void Check_Op_Rav()
    {
        PC_Info* tmp, * start_tmp;
        now = get_now();
        start_tmp = get_start();
        *now = *start_tmp;
        cout << "name 1 - " << now->get_name() << " name 2 - " << tmp->get_name() << endl;
        system("pause");
    }
    void PeregruzkaElementov()
    {
        PC_Info* tmp, * start_tmp;
        tmp = get_now();
        start_tmp = get_start();
        cout << "�������� �� == ";
        if (*tmp == *start_tmp) { cout << "true" << endl; }
        else { cout << "false" << endl; }
        cout << "�������� �� != ";
        if (*tmp != *start_tmp) { cout << "true" << endl; }
        else { cout << "false" << endl; }
        cout << "�������� �� > ";
        if (*tmp > *start_tmp) { cout << "true" << endl; }
        else { cout << "false" << endl; }
        cout << "�������� �� < ";
        if (*tmp < *start_tmp) { cout << "true" << endl; }
        else { cout << "false" << endl; }
        cout << "�������� �� >= ";
        if (*tmp >= *start_tmp) { cout << "true" << endl; }
        else { cout << "false" << endl; }
        cout << "�������� �� <= ";
        if (*tmp <= *start_tmp) { cout << "true" << endl; }
        else { cout << "false" << endl; }
    }
    void operator = (PCs& pc)
    {
        this->start = pc.start;
        this->now = pc.now;
    }
    bool operator == (PCs& pc)
    {
        if (this->ammount() == pc.ammount()) { return true; }  // ����� ����� �������� ��������� �� ����� � ���� ���� ������� ���� ��� �����,
        else { return false; }                                  // �� � ��������� �����
    }                                                       // �� ���� �� ��������� �� �� �� ��������� "!=" �� �������� ���������� �� ����� ���   
    bool operator != (PCs& pc)                         // �� ������� � ��� ��� ��� �� ����� 
    {
        if (this->ammount() != pc.ammount()) { return true; }
        else { return false; }
    }
    bool operator > (PCs& pc)
    {
        if (this->ammount() > pc.ammount()) { return true; }
        else { return false; }
    }
    bool operator < (PCs& pc)
    {
        if (this->ammount() < pc.ammount()) { return true; }
        else { return false; }
    }
    bool operator <= (PCs& pc)
    {
        if (this->ammount() <= pc.ammount()) { return true; }
        else { return false; }
    }
    bool operator >= (PCs& pc)
    {
        if (this->ammount() >= pc.ammount()) { return true; }
        else { return false; }
    }

};
int menu()
{
    system("cls");
    int change = 0;
    cout << "1 - �������� �� ������� ��������� � ��������� ������" << endl;
    cout << "2 - ��������� ���������� ���������  � ��������� ������" << endl;
    cout << "3 - ���������� ��������  � ��������� ������" << endl;
    cout << "4 - ������� �������� � ����� ��� � ������ ������� �� ��������" << endl;
    cout << "5 - �������� �������� �������� ��������� ������" << endl;
    cout << "6 - ������� ��������� ������" << endl;
    cout << "7 - ����������� �� ��������� ��������� ������" << endl;
    cout << "8 - ������ ���������� �� �������� �������� ��������� ������" << endl;
    cout << "9 - ��������� ���������� � ���������� �������� (��� �����������)" << endl;
    cout << "10 - �������� ������, ����������� �������" << endl;
    cout << "11 - �������� ���� ��������� ��������� �� == � !=" << endl;
    cout << "12 - �������� ���� �������� �� == � !=" << endl;
    cin >> change;
    cout << endl;
    return change;
}