/* Продолжите программу. Допишите функцию remove_elem, которая должна удалять все элементы из массива ar длиной len, для которых функция filter возвращает истинное значение. При этом значение переменной len должно быть равно количеству оставшихся значений в массиве ar.

В функции main вызовите функцию remove_elem для массива marks длиной count, а третьим аргументом пропишите лямбда-функцию для удаления из массива всех значений меньше 3. Результирующий массив marks (оставшиеся элементы после удаления) выведите в консоль по порядку в одну строчку через пробел.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/9.16.5

Sample Input:

5 4 3 2 -1 -100 6 7

Sample Output:

5 4 3 6 7

*/
#include <iostream>

enum {max_length_ar = 20};
using filter_func = bool (*)(short);

void remove_elem(short* ar, int& len, filter_func filter)
{
    short *ptr=&ar[0];
    short *ptrr=ptr;
    short *endptr=&ar[len-1];
    int i=0;
    while(ptr<=endptr){
      if(filter(*ptr)){ptrr=ptr;i++;
        while(ptrr<=endptr){
        *ptrr=*(ptrr+1);ptrr++;}
        endptr--;
        ptr--;
      }
  ptr++;
  
    }len=len-i;
}

int main(void)
{
    short marks[max_length_ar] = {0};
    int count = 0;
    while(count < max_length_ar && std::cin >> marks[count])
        count++;

    // здесь продолжайте функцию main
    
    remove_elem(marks,count,[](short x){return x<3;});
    for(int i = 0 ;i<count;i++){
       std::cout<<marks[i]<<" "; 
    }
    return 0;
}
