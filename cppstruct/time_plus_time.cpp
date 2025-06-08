/*Продолжите программу. В структуре tag_time объявите метод со следующей сигнатурой:

char* get_time(char* str, size_t max_length);

Этот метод должен в переданную строку str записывать время в формате:

hh:mm:ss

и возвращать ее (адрес этой строки). Например, для переменных hours=12, minutes=8, seconds=43 должны получать строку:

12:08:43

Обратите внимание на наличие незначащего нуля перед числами меньше 10. Также нужно контролировать возможный выход за пределы строки str (длина строки max_length).

В структуре tag_time объявите еще один статический метод с сигнатурой:

static tag_time sum_time(const tag_time& t1, const tag_time& t2);

Этот метод должен формировать и возвращать новую структуру с суммой времен t1 и t2. Причем время нужно складывать так, чтобы минуты и секунды не выходили из пределов [0; 59].

В функции main объявите две переменные tm1 и tm2 структуры tag_time. Значения их полей (шесть целых неотрицательных чисел, записанных в одну строчку через пробел)
прочитайте из входного потока. Выполните сложение времен tm1 и tm2 с помощью метода sum_time и сохраните результат в переменной time_res.
Выведите в консоль время переменной time_res в виде строки, сформированной методом get_time.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/10.1.7

Sample Input:

12 45 16 4 23 48

Sample Output:

17:09:04

*/
#include <iostream>

struct tag_time {
    unsigned char hours;
    unsigned char minutes;
    unsigned char seconds;
    char* get_time(char* str, size_t max_length){
        snprintf(str, max_length, "%.2hhu:%.2hhu:%.2hhu",hours,minutes,seconds);
        return str;
    }
    static tag_time sum_time(const tag_time& t1, const tag_time& t2){
        tag_time t3;
       t3.hours = (((t1.hours + t2.hours)+((t1.minutes + t2.minutes)+((t1.seconds+t2.seconds)/59))/59)%24);
        t3.minutes = (t1.minutes+t2.minutes+(t1.seconds+t2.seconds)/59)%60;
        t3.seconds = (t1.seconds+t2.seconds)%60;
        return t3;
    }
        
        
    // здесь объявляйте методы
};

int main(void)
{
    // здесь продолжайте программу
    tag_time tm1,tm2;
    scanf("%hhu %hhu %hhu %hhu %hhu %hhu",&tm1.hours,&tm1.minutes,&tm1.seconds,&tm2.hours,&tm2.minutes,&tm2.seconds);
    tag_time time_res;
    time_res=tag_time::sum_time(tm1,tm2);
    char time[9]={'\0'};
    std::cout<<time_res.get_time(time,9);
    //printf("%hhu %hhu %hhu",time_res.hours,time_res.minutes,time_res.seconds);
   
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}
