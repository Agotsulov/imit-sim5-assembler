// TaskOne.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <stdio.h>
#include <cstring>
#include <cstdlib>

/*15.  Удалить все пробелы в конце строки.*/

char* read() {
	char *s = new char[256];
	const char *format = " %[^\n]";
	__asm {

		mov   s, eax // усли не удалось выделить память
		push  eax
		mov   eax, format
		push  eax
		call  scanf
		add   esp, 8
	}
	return s;
}

void write(char* s) {
	const char *format = "%s|";
	__asm {
		mov    eax, s
		push   eax
		mov	   ebx, format
		push   ebx
		call   printf
		add	   esp, 8
	}
}

char* delete_last_spaces(char *s) {
	int *len = 0;
	char *i = 0;
	char *res;
	
	_asm {
		mov    eax, s
		push   eax
		call   strlen
		add    esp, 4
		mov    len, eax

		mov    esi, len
		dec    esi
		mov    ebx, s
	
	CHECK:
		cmp	   byte ptr[ebx + esi],' '
		je     NEXT
		jmp    END
	NEXT:
		dec    esi
		jmp    CHECK
	END:
		inc    esi

		push   esi //Выделяем новую строку размером который нам нужен
		call   malloc 
		add    esp, 4
		cmp    eax, 0
		je     ERR
		mov    res, eax

		mov    i, esi
		mov    eax, i
		push   eax
		push   s
		push   res
		call   strncpy
		add    esp, 12

		mov    eax, res
		mov    [eax][esi], '\0'  //\(O_O)/
	ERR:
	}
	return res;
}

int main() {
	char *buff = read();
	
	write(delete_last_spaces(buff));
	
	return 0;
}
