/* С помощью оператора using объявите в программе тип THING, описывающий структуру со следующими полями:

    name - название предмета; строка максимальной длиной 50 символов;
    weight - вес предмета (тип double).

В функции main объявите массив с именем th типа THING из max_things элементов.
Константа max_things = 20 должна быть определена с помощью перечисления. Прочитайте из входного потока данные по предметам в формате:

<название_1> <вес_1> <название_2> <вес_2> ... <название_N> <вес_N> 

Общее количество прочитанных из входного потока предметов не должно превышать значения max_things (это нужно контролировать в программе).

Выполните сортировку массива th по возрастанию весов предметов. Выведите в консоль названия предметов в порядке сортировки в одну строчку через пробел.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/9.5.7

Sample Input:

карандаш 20 зеркальце 100 зонт 500 рубашка 300

Sample Output:

карандаш зеркальце рубашка зонт

*/
#include <iostream>
enum{ max_things = 20};
using THING=struct{
    
   char name[50];
   double weight;

};
using std::cin;
using std::cout;
int main(){
    int count=0;
    THING th[max_things];
    while(count<max_things&&cin>>th[count].name>>th[count].weight)count++;
    for(int i = 0 ; i < count-1;i++){
       for(int j = 0 ; j < count-i-1;j++){
        if(th[j].weight>th[j+1].weight){THING temp=th[j];
                                          th[j]=th[j+1];
                                          th[j+1]=temp;}
       }  
    }
     for(int i = 0 ; i < count;i++){
      cout<<th[i].name<<" ";
    }
 return 0;   
}

