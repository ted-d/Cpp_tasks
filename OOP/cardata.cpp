/*Далее в подвигах все классы следует объявлять с помощью ключевого слова class, если не будет явно указано другое.

Подвиг 6. Объявите класс с именем CartData, содержащий следующие элементы:

- приватные переменные:

    unsigned long id;
    char name[100];
    unsigned price;
    double weight;

- публичные методы:

    void get_data(unsigned long &id, unsigned &price, double &weight); // возвращает через ссылки перечисленные поля
    char* get_name(); // возвращает наименование товара (поле name)
    void set_data(unsigned long id, const char* name, unsigned price, double weight); // заносит в перечисленные поля переданные значения

Методы в этом и последующих подвигах должны быть с соответствующими реализациями.

В функции main создайте объект класса CartData в виде переменной с именем item (не указатель). Занесите в его поля (переменные) следующие данные:

    id: 10
    name: "Toy"
    price: 2000
    weight: 5.45

P.S. На экран ничего выводить не нужно.
 */
#include <iostream>
#include <string.h>
// здесь объявляйте класс
class CartData{
    unsigned long id;
    char name[100];
    unsigned price;
    double weight; 
    public:
    void get_data(unsigned long &id, unsigned &price, double &weight){
        id = this->id;
        price= this->price;
        weight = this->weight;
    }
    char* get_name(){
        return name;
    }
    void set_data(unsigned long id, const char* name, unsigned price, double weight){
        this->id=id;
        strcpy(this->name,name);
        this->price=price;
        this->weight=weight;
    }
};
int main(void)
{ CartData item;
 item.set_data(10,"Toy",2000,5.45);
    // здесь продолжайте функцию main

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}
