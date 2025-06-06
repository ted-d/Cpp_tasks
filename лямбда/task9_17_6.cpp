/*

Подвиг 6. Продолжите программу. Необходимо в функции main прочитать два целых числа из входного потока, записанных через пробел, в переменные w и h.
Объявить лямбда-выражение, которое захватывает переменные w, h, складывает их и возвращает результат. Сама лямбда-функция не должна иметь никаких параметров.
С лямбда-выражением должна быть связана переменная sum_ab. Вызовите лямбда-функцию sum_ab и выведите в консоль возвращенное значение.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/9.17.6

Sample Input:

5 10

Sample Output:

15

*/
#include <iostream>

int main(void)
{
    // здесь продолжайте функцию main
 int w,h;
    std::cin>>w>>h;
    auto sum_ab = [w,h](){return w+h;};
    std::cout<<sum_ab();
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}
