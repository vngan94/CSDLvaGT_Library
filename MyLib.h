#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <cmath>
#include <sstream>
#include <ctime>
using namespace std;
void GoToXY(short x, short y) //Di chuyen con tro toi toa do
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordinate = { x, y };
	SetConsoleCursorPosition(output, coordinate);
}
void Color(int x) //Mau chu
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}
void modifyCursor(int size, bool visibility) //An, hien con nhay tren console
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = size;
	cursor.bVisible = visibility;
	SetConsoleCursorInfo(output, &cursor);
}
void BGColor(WORD color) //Mau nen
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void resizeConsole(int width, int height) //Dieu chinh kich thuoc console
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
int GetKey() //Dung de phan biet phim mui ten vs phim thuong
{
	char key;
	key = getch();
	if(key == -32 || key == 0)
		return (- getch());
	return key;	
}
void ChuanHoaString(string &s) // Xoa khoang trang thua vs in hoa chu cai dau
{
	for(size_t i = 0; i < s.length(); i++) //Xoa khoang trang thua
	{
		if(s[0] == ' ')
		{
			s.erase(0, 1);
			i--;
		}
		else if(s[i] == ' ' && s[i + 1] == ' ')
		{
			s.erase(i, 1);
			i--;
		}
		else if(s[s.length() - 1] == ' ') s.erase(s.length() - 1, 1);
	}
	for(size_t i = 0; i < s.length(); i++) //In hoa chu cau dau
	{
		if(s[0] >= 97 && s[0] <= 122)
		{
			s[0] = s[0] - 32;
		}
		if(s[i] == ' ')
		{
			if(s[i + 1] >= 97 && s[i + 1] <= 122) s[i + 1] = s[i + 1] - 32;
		}
		if(s[i] != ' ')
		{
			if(s[i + 1] >= 65 && s[i + 1] <= 90) s[i + 1] = s[i + 1] + 32;
		}
	}
}
