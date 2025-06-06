/*Объявите в программе структуру с идентификатором (типом) book (книга) и следующими полями:

    title: название книги; строка, максимальной длины 200 символов;
    author: автор; строка, максимальной длины 100 символов;
    price: цена; целое число;
    npages: число страниц; целое число.

Объявите в структуре book метод с именем price_per_page, который возвращает цену за одну страницу (вещественное число), вычисленную по формуле:

price/npagesprice/npages

В функции main объявите массив lib с типом book длиной 10 элементов. Прочитайте из входного потока данные в массив lib (по порядку), представленные в формате:

<название книги>
<автор>
<цена> <число страниц>

Выведите в консоль в одну строчку через пробел цену за одну страницу прочитанных книг с точностью до сотых.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/10.1.4

Sample Input:

Программирование на Си
Кен Томпсон
540 230
Программирование на С++
Бьерн Страуструп
753 548
Лекции по C/C++
Сергей Балакирев
100 500

Sample Output:

2.35 1.37 0.20

*/#include <iostream>
#include <string.h>
struct book{
    char title[200];
    char author[100];
    int price;
    int npages;
    double price_per_page(){return (double)price/npages;}
};
int main(void)
{ book lib[10];
 int count=0;
 while(count<10&&std::cin>>lib[count].title){char temp[100];
                                             fgets(temp,100,stdin);
                                             strcat(lib[count].title,temp);
                                             temp[100]={'\0'};
                                             fgets(temp,100,stdin);
                                             strcat(lib[count].author,temp);
                                             std::cin>>lib[count].price>>lib[count].npages;
     count++;
 }
    // здесь продолжайте функцию main
    for(int i=0;i<count;i++){
       printf("%.2lf ",lib[i].price_per_page());
    }
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}
