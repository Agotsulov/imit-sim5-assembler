// TaskThree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>


/*

	В задачах этого раздела точка --- это структура вида
	 struct Point
	 {
		  double x;
		  double y;
		  double z;
	 };
15.  Найти  точку, из указанного массива точек, расстояние от  которой  до
     заданной плоскости Ax+By+Cx+D=0 будет наименьшим. Вычисление расстояние от
     точки до плоскости выделить в отдельную подпрограмму.
*/
struct Point
{
	double x;
	double y;
	double z;
};

int main()
{
	Point **p = new Point*[2];
	Point b1;
	b1.x = 1.2;
	b1.y = 2.3;
	b1.z = 3.4;
	p[0] = &b1;
	Point b2;
	b2.x = 7.2;
	b2.y = 6.3;
	b2.z = 5.4;
	p[0] = &b2;

	_asm {
		mov eax, p[1]
	}
}
