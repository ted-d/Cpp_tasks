/*Объявите в программе пространство имен array_alg. В этом пространстве объявите функцию sorted_int со следующей сигнатурой:

void sorted_int(int* ar, size_t len_ar, TYPE_SORT type);

Здесь ar - сортируемый массив; len_ar - число первых сортируемых элементов массива ar; type - тип сортировки (по возрастанию или убыванию). 

Тип сортировки TYPE_SORT определяется в том же пространстве имен array_alg как перечисление с двумя константами:

    sort_asc - сортировка по возрастанию;
    sort_desc - сортировка по убыванию.

В функции main прочитайте из входного потока целые числа, записанные в одну строчку через пробел, в количестве не более 20.
Все эти значения занесите в массив (по порядку) и отсортируйте массив по убыванию с помощью функции sorted_int. Выведите в консоль отсортированные значения в одну строчку через пробел.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/9.4.5

Sample Input:

45 324 645 324 2 -10 11 0 -54 2

Sample Output:

645 324 324 45 11 2 2 0 -10 -54

*/
#include <iostream>
enum{max_len=20};
namespace array_alg{
   typedef enum{sort_asc,sort_desc}TYPE_SORT;
   void sorted_int(int* ar, size_t len_ar, TYPE_SORT type){
     switch(type){
         case sort_asc:
             for(int i=0;i<len_ar-1;i++){
                 for(int j=0;j<len_ar-i -1;j++){
                     if(ar[j]>ar[j+1]){int temp= ar[j];
                                       ar[j]=ar[j+1];
                                       ar[j+1]=temp;
                         
                     }
                 }
             }break;
         case sort_desc:
             for(int i = 0; i < len_ar - 1; i++) {
                for(int j = 0; j < len_ar - i - 1; j++) {
                    if(ar[j] < ar[j+1]) {
                        int temp = ar[j];
                        ar[j] = ar[j+1];
                        ar[j+1] = temp;
                    }
                }
            }
             
             
     };
   }
}
int main()
{ int ar[max_len];
 int count=0;
 while(count<max_len &&std::cin>>ar[count])count++;
 array_alg::sorted_int(ar, count, array_alg::sort_desc);
 for(int i =0;i<count;i++){
     std::cout<<ar[i]<<" ";
 }

    return 0;
}
