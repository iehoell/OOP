#include <iostream>
#include <string>
using namespace std;
// 1 - Проверка на наличие элементов в структуре данных
// 2 - Получение количества элементов  в структуре данных
// 3 - Добавление элемента  в структуру данных 
// 4 - Вставка элемента с одной или с другой стороны от текущего
// 5 - Удаление текущего элемента структуры данных
// 6 - Очистка структуры данных
// 7 - Перемещение по элементам структуры данных
// 8 - Чтение информации из текущего элемента структуры данных
void language ()
{
  setlocale(LC_ALL, "Russian");
}
void help()
{

}

//--------------------------------------------------------------------

struct list
{
  list *next; // указатель на следующий элемент
  list *prev; // указатель на предыдущий элемент
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

struct list *initialization()  // инициализация списка
{
  struct list *lst = new list; // выделение памяти под корень списка
  lst->next = NULL; // указатель на следующий узел
  lst->prev = NULL; // указатель на предыдущий узел
}

//--------------------------------------------------------------------
struct list *getAddress(struct list* lst, int N)
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
  for (int count = 0; count < N-1; count++)
  {
    tmp = tmp->next;
  }
  return tmp;
}

//--------------------------------------------------------------------

void filling(struct list *tmp)
{
  cout << "Введите название процессора - ";
  cin >> tmp->processor;
  cout << "Введите название видеокарты - ";
  cin >> tmp->videocard;
  cout << "Введите объем оперативной памяти - ";
  cin >> tmp->RAM;
  cout << "Введите объем SSD накопителя - ";
  cin >> tmp->SSD;
  cout << "Введите объем HDD накопителя - ";
  cin >> tmp->HDD;
  cout << "Введите название материнской платы - ";
  cin >> tmp->motherboard;
  cout << "Введите название корпуса - ";
  cin >> tmp->Case;
  cout << "Введите количество кулеров - ";
  cin >> tmp->cooler;
  cout << "Введите количество мониторов - ";
  cin >> tmp->monitor;
  cout << "Введите мощность блока питания - ";
  cin >> tmp->powerUnit;
}

//--------------------------------------------------------------------

void propertyChange(struct list *tmp1,struct list *tmp2) // 1-параметр куда вносим свойства 2-параметр откуда берем
{
  tmp1->processor = tmp2->processor;
  tmp1->videocard = tmp2->videocard;
  tmp1->RAM = tmp2->RAM;
  tmp1->SSD = tmp2->SSD;
  tmp1->HDD = tmp2->HDD;
  tmp1->motherboard = tmp2->motherboard;
  tmp1->Case = tmp2->Case;
  tmp1->cooler = tmp2->cooler;
  tmp1->monitor = tmp2->monitor;
  tmp1->powerUnit = tmp2->powerUnit;
}

//--------------------------------------------------------------------

void addElement(list *lst)
{
  struct list *tmp, *preev;
  preev = getAddress(lst,amount(lst));
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
  printf("Процессор - ");
  cout << tmp->processor <<endl;
  printf("Видеокарта - ");
  cout << tmp->videocard <<endl;
  printf("Объем RAM - ");
  cout << tmp->RAM <<endl;
  printf("Объем SSD - ");
  cout << tmp->SSD<<endl;
  printf("Объем HDD -");
  cout << tmp->HDD <<endl;
  printf("Материнская плата -");
  cout << tmp->motherboard <<endl;
  printf("Корпус - ");
  cout << tmp->Case <<endl;
  printf("Количество кулеров - ");
  cout << tmp->cooler <<endl;
  printf("Количество мониторов - ");
  cout << tmp->monitor <<endl;
  printf("Мощность БП - ");
  cout << tmp->powerUnit <<endl;
  printf("Нажмите Enter");
  _flushall();
  getchar();
}
//--------------------------------------------------------------------

void addRightElement(list *lst, int numell)
{
  struct list *left, *right, *tmp;
  left = getAddress(lst, numell);
  tmp = new list;
  if(left->next != NULL)
  {
    right = getAddress(lst, numell + 1);
    left->next = tmp;
    tmp->next = right;
    tmp->prev = left;
    right->prev = tmp;
    filling(tmp);
  }
  if(left->next == NULL)
  {
    left->next = tmp;
    tmp->prev = left;
    tmp->next = NULL;
    filling(tmp);
  }
}

//--------------------------------------------------------------------

void addLeftElement(list *lst, int numell)
{
  struct list *left, *now, *tmp, *buf1;
  tmp = new list;
  now = getAddress(lst, numell);
  if(now->prev == NULL)
  {
    if(now->next == NULL)
    {
      now->next = tmp;
      tmp->prev = now;
      tmp->next = NULL;
      propertyChange(tmp,now);
      filling(now);
    }
    else
    {
      buf1 = getAddress(lst, numell + 1);
      now->next = tmp;
      tmp->prev = now;
      tmp->next = buf1;
      buf1->prev = tmp;
      propertyChange(tmp,now);
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
  printf("%s \n", tmp->processor.c_str());
  printf("%d || %d \n", tmp->next, tmp->prev);

}

//--------------------------------------------------------------------

void checkForAvailability(struct list* lst)
{
  if(amount(lst) == 0)
  {
    printf("в структуре нет элементов \n");
  }
  else
  {
    printf("в структуре %d элементов \n", amount(lst)) ; 
  }
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
  struct list *left, *now, *right;
  now = getAddress(lst, numell);
  if(now->prev == NULL)
  {
    printf("удаление головного элемента невозможно\n");
    return 1;
  }
  if(now->next == NULL)
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
  printf("Деструктор начал свою работу\n");
    list * tmp;
    while (lst){
        tmp = lst->next;
        delete(lst);
        lst = tmp;
    }
  printf("Деструктор завершил свою работу\n");
}

void printAddress(struct list* lst, int numell)
{
  list * tmp;
  tmp = getAddress(lst, numell); 
  cout << tmp;
}