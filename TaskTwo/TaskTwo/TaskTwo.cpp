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

