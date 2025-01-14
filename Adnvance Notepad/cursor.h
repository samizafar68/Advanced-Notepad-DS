#ifndef CursorManip_H
#define CursorManip_H
#include <windows.h>
#include <strsafe.h>
#include <iostream>
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
#endif