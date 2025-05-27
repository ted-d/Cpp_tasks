/*Четырехугольник описан четырьмя точками на плоскости:

Необходимо написать программу, которая бы проверяла, что произвольная точка с координатами (x, y) находится в пределах заданного четырехугольника.

Один из алгоритмов проверки следующий. Точку (x, y) нужно (условно) соединить со всеми вершинами четырехугольника (см. рисунок) и если сумма площадей образованных треугольников будет равна площади исходного четырехугольника, то точка (x, y) принадлежит этой фигуре. Площадь самого четырехугольника можно найти как сумму двух треугольников, на которые легко разбивается любой четырехугольник.

Для вычисления площади треугольника с произвольными сторонами a, b, c можно воспользоваться формулой Герона:

S=p⋅(p−a)⋅(p−b)⋅(p−c)
S=p⋅(p−a)⋅(p−b)⋅(p−c)

​

где p=(a+b+c)/2p=(a+b+c)/2 - полупериметр треугольника.

В программе ниже уже реализовано представление и считывание координат из входного потока. Продолжите ее, добавив проверку принадлежности точки pt четырехугольнику figure. Если точка принадлежит фигуре, то в консоль выведите строку "yes", а иначе - строку "no".

P. S. Повторяющиеся вычисления выносите в функции. Текст программы должен хорошо читаться.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/9.7.8

Sample Input:

5; 2 10; 15 20; 7 13; 1
11; 14

Sample Output:

yes*/
#include <iostream>
#include <math.h>
enum {corners = 4};

struct point {
    int x, y;
};
double len(int x1,int y1,int x2,int y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
double sq_tr(const point& p1,const point& p2,const point& p3){double a = len(p1.x,p1.y,p2.x,p2.y);
                                                              double b = len(p1.x,p1.y,p3.x,p3.y);
                                                              double c = len(p2.x,p2.y,p3.x,p3.y);
     double p = (a+b+c)/2;
     return sqrt(p*(p-a)*(p-b)*(p-c));
                                                              
}

int main()
{
    point figure[corners];
    point pt;

    int count = 0;
    while(count < corners && scanf("%d; %d", &figure[count].x, &figure[count].y) == 2)
        count++;

    if(count != corners) {
        puts("Неверное количество или формат входных данных.");
        return 1;
    }

    if(scanf("%d; %d", &pt.x, &pt.y) != 2) {
        puts("Неверное количество или формат входных данных.");
        return 2;        
    }
    double s_tri=0;
    double s_for=0;
    
    s_tri+=sq_tr(figure[0],pt,figure[1]);
    s_tri+=sq_tr(figure[0],pt,figure[3]);
    s_tri+=sq_tr(figure[1],pt,figure[2]);
    s_tri+=sq_tr(figure[2],pt,figure[3]); 
    
    s_for+=sq_tr(figure[0],figure[1],figure[3]);
    s_for+=sq_tr(figure[2],figure[1],figure[3]);
    
    std::cout<<((abs(s_for-s_tri)<0.00001)?"yes":"no");
    // здесь продолжайте функцию main

    return 0;
}

