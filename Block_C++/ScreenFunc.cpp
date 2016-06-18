#include "ScreenFunc.h"
#include <windows.h>
#include <stdio.h>

void ScreenPrint( int x, int y, char *string )
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", string);
}

void RemoveCursor() //콘솔창의 커서 깜박임을 없애준다.
{

	CONSOLE_CURSOR_INFO cur;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
	cur.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}

void SetSize(int cols, int lines){
	char command[100];
	sprintf(command, "mode con: cols=%d lines=%d", cols, lines);
	system(command);
}

void ScreenInit() {
	RemoveCursor();
	SetSize(WIDTH, HEIGHT);
}
void gotoxy(int x, int y){
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
