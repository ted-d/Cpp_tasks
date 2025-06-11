/*Объявите в программе структуру с именем (типом) thing и следующими публичными полями:

    id: идентификатор (целое число, тип unsigned long);
    name: название (строка, массив символов длиной 50 элементов);
    price: цена (целое число, тип unsigned int);
    weight: вес (вещественное число, тип double).

Объекты структуры thing допустимо создавать следующим образом:

thing th_1;
thing th_2("book");
thing th_3("mouse", 1024);
thing th_4("mouse", 1024, 0.2);

Если какие-либо значения не переданы, соответствующие поля должны быть равны нулю (или пустая строка).
Также при создании каждого нового объекта идентификатор id должен автоматически увеличиваться на единицу 
и для первого созданного в программе объекта thing принимать значение 1.

В функции main прочитайте из входного потока данные, представленные в формате:

<название (одно слово)> <цена (целое число)> <вес (вещественное число)>

Например:

Клавиатура 4300 0.34

Объявите указатель ptr_th с типом thing и создайте объект, используя оператор new. Выведите в консоль цену предмета.
В конце удалите объект (освободите память), используя оператор delete.

Sample Input:

Mouse 834 0.12

Sample Output:

834

*/
#include <iostream>
#include <string.h>
// здесь объявляйте структуру
struct thing{
   static int i;
   unsigned long id;
   char name[50];
   unsigned int price;
   double weight;
    thing(const char* n = "", unsigned int p = 0, double w = 0.0) {
    id = i++;  
    strncpy(name, n, sizeof(name)-1);  
    name[sizeof(name)-1] = '\0';  
    price = p;
    weight = w;
}

};
int thing::i=1;
int main(void)
{
    char name[50];
    unsigned int price;
   double weight;
    
    std::cin>>name>>price>>weight;
    struct thing *ptr_th;
    ptr_th=new thing(name,price,weight);
    std::cout<<ptr_th->price;
    delete ptr_th;
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}
