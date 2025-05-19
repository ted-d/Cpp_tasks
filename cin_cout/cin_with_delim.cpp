/*Продолжите программу, которая читает в массив data целые числа из входного потока, записанные в одну строчку через точку с запятой
(или любой другой символьный не числовой разделитель). Необходимо контролировать максимальное количество читаемых значений не более max_size_ar.
Выведите в консоль в одну строчку через пробел значения массива data (по порядку от начала до конца).

P. S. Ввод/вывод данных реализовать через объекты cin/cout.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/9.3.6

Sample Input:

9; 11; 0; -9; 3; 100; 8; 7; 4

Sample Output:

9 11 0 -9 3 100 8 7 4

*/
#include <iostream>
#include <stdlib.h>
enum {max_size_ar=20};

int main()
{
    short data[max_size_ar];
  int count=0;
    char x[10];
    while(count<max_size_ar&&std::cin>>x){
        data[count]=atoi(x);
        count++;
    }
    // здесь продолжайте программу
    for(int i =0;i<count;i++){
       std::cout<<data[i]<<" ";
    }
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}
