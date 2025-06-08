/*Объявите в программе структуру с именем (типом) point и следующими приватными полями:

    x, y: целочисленные координаты точки.

Объявите в этой же структуре следующие публичные методы:

    int get_x(): возвращает значение координаты x;
    int get_y(): возвращает значение координаты y;
    void get_coords(int& x, int& y): возвращает через ссылки значение координат x и y;
    void set_coords(int x, int y): записывает в поля x, y переданные значения;
    static point sum(point& p1, point& p2): выполняет суммирование координат p1 и p2 (отдельно для x и отдельно для y) и возвращает результат суммирования в виде новой структуры point.

В функции main объявите две переменные типа point. Прочитайте из входного потока координаты (четыре целых числа, записанных через пробел)
в эти структуры: первые два числа - это координаты x, y первой точки, а вторые два числа - координаты x, y второй точки.
Затем, с помощью функции sum выполните суммирование координат этих точек и выведите в консоль результат суммирования в виде двух чисел, записанных через пробел, в формате:

<координата x> <координата y>

Sample Input:

5 7 -3 10

Sample Output:

2 17

*/
#include <iostream>
struct point{
    private:
    int x,y;
    public:
    int get_x(){return x;}
    int get_y(){return y;}
    void get_coords(int& x, int& y){
        x=get_x();
        y=get_y();
    }
    void set_coords(int x, int y){
        this->x=x;
        this->y=y;
    }
    static point sum(point& p1, point& p2){
        point res;
        res.x=p1.x+p2.x;
        res.y=p1.y+p2.y;
        return res;
    }
};
using std::cin;
int main(){
    point p1,p2;
    
    int x,y;
    cin>>x>>y;
    p1.set_coords(x, y);
    cin>>x>>y;
    p2.set_coords(x,y);
    point t = point::sum(p1,p2);
    std::cout<<t.get_x()<<" "<<t.get_y();
    return 0;
}

