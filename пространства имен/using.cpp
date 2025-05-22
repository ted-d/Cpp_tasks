/* С использованием оператора using объявите в программе структуру с типом AUTO, содержащую следующие поля:

    model - строка максимальной длины 50 символов;
    max_speed - максимальная скорость (тип unsigned short);
    weight - вес (тип double);
    m - габариты (тип MEASURE).

Тип MEASURE также следует определить с помощью оператора using и представлять собой структуру со следующими полями типа unsigned short:

    width - ширина;
    height - высота;
    depth - глубина (длина).

Продолжите функцию main. Занесите в поля переменной auto_sell данные из соответствующих переменных: model, weight, max_speed, width, height, depth.

P. S. В консоль ничего выводить не нужно.

Sample Input:

toyota 240 1540.3 230 120 545*/
#include <iostream>
#include <cstring>
using MEASURE=struct{
    
   unsigned short width;
   unsigned short height;
    unsigned short depth;

};
using AUTO = struct{
    
   char model[50];
   unsigned short max_speed;
   double weight;
   MEASURE m;

};
int main()
{
    AUTO auto_sell;
    char model[50];
    unsigned short max_speed, width, height, depth;
    double weight;

    std::cin >> model >> max_speed >> weight >>width >> height >> depth;
    strcpy(auto_sell.model,model);
    auto_sell.max_speed = max_speed;
    auto_sell.weight=weight;
    auto_sell.m={.width=width ,.height=height,.depth=depth};
    // здесь продолжайте функцию main
 //exit(0);
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}
