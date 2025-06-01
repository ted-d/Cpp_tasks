/*Продолжите программу. Объявите функцию с именем set_tag и следующими параметрами (порядок важен):

    строка, которая заключается в тег (тип char*, эта строка будет меняться в функции);
    максимальная длина строки (целое число);
    тег (строка), в который заключается переданная строка, с начальным значением "h1".

(Все строки в параметрах функции должны быть представлены массивами символов.)

Например, при передаче в функцию set_tag строки "Hello C++", заключаем ее (по умолчанию) в тег "h1". В результате, переданная строка после обработки должна иметь вид:

"<h1>Hello C++</h1>"

То есть, сначала прописывается открывающийся тег <h1>, а в конце строки - закрывающийся </h1>. И так для любых указанных тегов.
При этом функция set_tag ничего не должна возвращать, только менять переданную строку, не выходя за пределы ее максимальной длины.

В функции main первый раз вызовите функцию set_tag только со строкой title, а второй раз - со строкой title (исходной) и tag.
Полученные строки выведите в консоль каждую с новой строки. В начале и конце строк не должно быть пробелов.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/9.14.5

Sample Input:

I love C
div

Sample Output:

<h1>I love C</h1>
<div>I love C</div>

*/
#include <iostream>
#include <string.h>
void pl_tag(char * ar,int l,char *tag){
    for(int i = 0;i<strlen(tag);i++){
      ar[l]=tag[i];
      l++;
    }
}
void set_tag(char *ar,int len,char tag[]="h1"){len = strlen(ar)+1;
    char *ptr = ar+strlen(ar)+strlen(tag)+2;
    char *ptr2 =ar+strlen(ar) ;
    while(ptr2>=ar){
        *ptr=*ptr2;
        ptr--;
        ptr2--;
    }
    ptr2=ar;
    *ptr2='<';
    ptr2++;
  pl_tag(ar,1,tag);
  ptr2+=strlen(tag);
    *ptr2='>';
    ptr2+=len;
    *ptr2='<';
    ptr2++;
    *ptr2='/';
    pl_tag(ar,strlen(ar),tag);
    ptr2+=strlen(tag)+1;
    *ptr2='>';
}
int main()
{
    std::string title, tag;

    getline(std::cin, title);
    getline(std::cin, tag);
    char ar[100];
    
    char tag2[10];
    strncpy(ar, title.c_str(), sizeof(ar) - 1);
    strncpy(tag2, tag.c_str(), sizeof(tag2) - 1);
    set_tag(ar,100);
    puts(ar);
   
    strncpy(ar, title.c_str(), sizeof(ar) - 1);
    set_tag(ar,100,tag2);
    
    puts(ar);
    // здесь продолжайте функцию main
    
    return 0;
}
