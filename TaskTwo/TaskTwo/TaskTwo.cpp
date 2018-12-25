// TaskTwo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

/*
15.  
 Сравнение: сначала сравниваются поля count, а, в случае равенства, вершины  в
 лексикографическом порядке.Отсортировать фигуры по убыванию.
*/

struct Shape
{
	int count; 
	int* vertexes;
};

int compare(Shape *first, Shape *second) {
	int res = 0;
	res = second->count - first->count;
	return res;
}

void * sort(Shape **shapes, int n) {
	int i = 0, j = 0;
	int size_n = 0;
	Shape *buff = 0;
	Shape *a = 0; //DEBUG
	Shape *b = 0; //DEBUG
	__asm {
	SET:
		mov eax, n;
		dec eax;
		dec eax;
		mov ecx, 4;
		mul ecx;
		mov size_n, eax;
		jmp START;
	ADD_I:
		add i, 4;
		mov j, 0;
		jmp START;
	ADD_J:
		add j, 4;
		jmp START;
		
	START:
		mov edx, shapes;
		mov esi, j;
		mov ebx, [edx + esi];
		mov ecx, [edx + esi + 4];		
	CHECK:
		mov a, ebx; //DEBUG
		mov b, ecx; //DEBUG
		push ebx;
		push ecx;
		call compare;
		add esp, 8;
		cmp eax, 0;
		jg SWAP;
		jmp FOR_J;
	SWAP:
		mov edx, shapes;
		mov esi, j;
		mov ebx, [edx + esi];
		mov ecx, [edx + esi + 4];
		mov a, ebx; //DEBUG
		mov b, ecx; //DEBUG
		mov buff, ebx;
		mov [edx + esi], ecx;
		mov eax, buff;
		mov [edx + esi + 4], eax;
		jmp FOR_J;
	FOR_J:
		mov ecx, size_n;
		mov esi, j;
		cmp esi, ecx;
		jl ADD_J;
		jmp FOR_I;
	FOR_I:
		mov ecx, size_n;
		mov esi, i;
		cmp esi, ecx;
		jl ADD_I;
		jmp END;
	END:
	}
}

int main()
{
	Shape **s = new Shape*[5];

	Shape *s1 = new Shape();
	s1->count = 10;
	Shape *s2 = new Shape();
	s2->count = 2;
	Shape *s3 = new Shape();
	s3->count = 11;
	Shape *s4 = new Shape();
	s4->count = 6;
	Shape *s5 = new Shape();
	s5->count = 1;

	s[0] = s1;
	s[1] = s2;
	s[2] = s3;
	s[3] = s4;
	s[4] = s5;

	sort(s, 5);

	for (int i = 0; i < 5; i++) {
		printf("%i ", s[i]->count);
	}
	Shape *a = new Shape();
	a->count = 1;
}

// ConsoleApplication23.cpp: определяет точку входа для консольного приложения.
//

/*15.  
	
     Сортировка и поиск экземпляров структур данных

     Задачи   этой   группы  предполагают  работу  с  массивом  фиксированной
размерности   указателей   на  структуры  определенного   типа.   С   помощью
ассемблерных  вставок  необходимо  написать  функции:  создание  и   удаление
экземпляра структуры; печать экземпляра на экране; сравнение двух экземпляров
по критерию, указанному в задании (если есть); операцию, указанную в задании.

	struct Shape
     {
          int count; //количество вершин
          int* vertexes;  одномерный массив вершин, то есть
                        координаты  каждой  вершины  содержатся  в  элементах
               массива с индексами
                    2n и 2n+1
	 };
 Сравнение: сначала сравниваются поля count, а, в случае равенства, вершины  в
	 лексикографическом порядке.Отсортировать фигуры по убыванию.
	 */

#include "stdafx.h"
#include <stdio.h>

struct Shape
{
	int count; 
	int* vertexes;
};


int compare(Shape *s1, Shape *s2) {
	int res = 0;
	int c = 0;
	_asm {
		mov eax, s1;
		mov eax, [eax];
		mov ebx, s2;
		mov ebx, [ebx];
		cmp eax, ebx;
		je START;
		ja MORE;
		jb LESS;
		jmp START;
	MORE:
		mov res, -1;
		jmp FIN;
	LESS:
		mov res, 1;
		jmp FIN;
	START:
		mov eax, s1;
		mov eax, [eax];
		mov ebx, 4;
		mul ebx;
		mov c, eax;
		jmp END;
	INCSD:
		add esi, 4;
	END:
		cmp esi, c;
		je EQL;
		mov eax, s1;
		mov eax, [eax + 4];
		mov eax, [eax + esi];
		mov ebx, s2;
		mov ebx, [ebx + 4];
		mov ebx, [ebx + esi];
		cmp eax, ebx;
		je INCSD;
		jg MORE;
		jl LESS;
		jmp EQL;
	EQL:
		mov dword ptr[res], 0;
	FIN:
	}
	return res;
}

int len(Shape *s) {
	int res = 0;
	_asm {
		mov eax, s;
		mov eax, [eax];
		mov ebx, 4;
		mul ebx;
		mov res, eax;
	}
	return res;
}


void * sort(Shape **shapes, int n) {
	int i = 0, j = 0;
	int size_n = 0;
	Shape *buff = 0;
	Shape *a = 0; //DEBUG
	Shape *b = 0; //DEBUG
	__asm {
	SET:
		mov eax, n;
		dec eax;
		dec eax;
		mov ecx, 4;
		mul ecx;
		mov size_n, eax;
		jmp START;
	ADD_I:
		add i, 4;
		mov j, 0;
		jmp START;
	ADD_J:
		add j, 4;
		jmp START;

	START:
		mov edx, shapes;
		mov esi, j;
		mov ebx, [edx + esi];
		mov ecx, [edx + esi + 4];
	CHECK:
		mov a, ebx; //DEBUG
		mov b, ecx; //DEBUG
		push ebx;
		push ecx;
		call compare;
		add esp, 8;
		cmp eax, 0;
		jg SWAP;
		jmp FOR_J;
	SWAP:
		mov edx, shapes;
		mov esi, j;
		mov ebx, [edx + esi];
		mov ecx, [edx + esi + 4];
		mov a, ebx; //DEBUG
		mov b, ecx; //DEBUG
		mov buff, ebx;
		mov[edx + esi], ecx;
		mov eax, buff;
		mov[edx + esi + 4], eax;
		jmp FOR_J;
	FOR_J:
		mov ecx, size_n;
		mov esi, j;
		cmp esi, ecx;
		jl ADD_J;
		jmp FOR_I;
	FOR_I:
		mov ecx, size_n;
		mov esi, i;
		cmp esi, ecx;
		jl ADD_I;
		jmp END;
	END:
	}
}

int main()
{
	Shape **s = new Shape*[5];

	int * m1 = new int[4];
	m1[0] = 10;
	m1[1] = 1;
	m1[2] = 2;
	m1[3] = 3;

	int * m2 = new int[4];
	m2[0] = 3;
	m2[1] = 3;
	m2[2] = 3;
	m2[3] = 3;


	Shape *s1 = new Shape();
	s1->count = 4;
	s1->vertexes = m2;
	Shape *s2 = new Shape();
	s2->count = 2;
	Shape *s3 = new Shape();
	s3->count = 11;
	Shape *s4 = new Shape();
	s4->count = 4;
	s4->vertexes = m1;
	Shape *s5 = new Shape();
	s5->count = 1;

	s[0] = s1;
	s[1] = s2;
	s[2] = s3;
	s[3] = s4;
	s[4] = s5;



	for (int i = 0; i < 5; i++) {
		printf("%i ", s[i]->count);
	}
	for (int i = 0; i < 5; i++) {
		printf("\n %i ", s[i]);
	}

	printf("_________________________\n");


	sort(s, 5);

	for (int i = 0; i < 5; i++) {
		printf("%i ", s[i]->count);
	}
	for (int i = 0; i < 5; i++) {
		printf("\n %i ", s[i]);
	}
	Shape *a = new Shape();
	a->count = 1;
}



