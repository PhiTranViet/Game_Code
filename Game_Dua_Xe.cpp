#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

char map[60][60]; 
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle
	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle
	(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle
	(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void VeDuongDua_1()
{
	for(int i = 0; i < 30; i++)
	{
		map[i][0] = '|';
		map[i][29] = '|';
		if(i % 2 == 0)
		{
			map[i][14] = '|';
		}

		for(int j = 1; j < 29 && j != 14; j++)
		{
			map[i][j] = ' ';
		}
	}
}

void VeDuongDua_2()
{
	for(int i = 0; i < 30; i++)
	{
		map[i][0] = '|';
		map[i][29] = '|';
		if(i % 2 != 0)
		{
			map[i][14] = '|';
		}

		for(int j = 1; j < 29 && j != 14; j++)
		{
			map[i][j] = ' ';
		}
	}
}

void InDuongDua()
{
	for(int i = 0; i < 30; i++)
	{
		cout << "\t\t\t\t";
		for(int j = 0; j < 30; j++)
		{
			if(j == 0 || j == 29)
			{
				textcolor(181);
				map[i][j] = ' ';
				cout << map[i][j];
				textcolor(7);
			}
			else if(j == 14)
			{
				textcolor(15);
				cout << map[i][j];
				textcolor(7);

				map[i][j] = ' ';
			}
			else if(map[i][j] == 'X' || map[i][j] == '@' || map[i][j] == '#')
			{
				textcolor(14);
				cout << map[i][j];
				textcolor(7);
			}
			else if(map[i][j] == '!')
			{
				textcolor(204);
				cout << map[i][j];
				textcolor(7);
			}
			else
			{
				cout << map[i][j];
			}
		}
		cout << endl;
	}
}

void VeXePlayer(int x, int y)
{
	map[x][y] = 'X';
	map[x][y - 1] = '#'; 
	map[x][y + 1] = '#'; 
	map[x - 1][y - 1] = '@'; 
	map[x + 1][y - 1] = '@'; 
	map[x - 1][y + 1] = '@';
	map[x + 1][y + 1] = '@';
}

void VeXeChuongNgaiVat(int x, int y)
{
	map[x][y] = '!'; 
	map[x][y - 1] = '!'; 
	map[x][y + 1] = '!';
	map[x - 1][y - 1] = '!';
	map[x + 1][y - 1] = '!'; 
	map[x - 1][y + 1] = '!'; 
	map[x + 1][y + 1] = '!';
}

void XoaXeChuongNgai(int x, int y)
{
	map[x][y] = ' '; 
	map[x][y - 1] = ' ';
	map[x][y + 1] = ' '; 
	map[x - 1][y - 1] = ' ';
	map[x + 1][y - 1] = ' '; 
	map[x - 1][y + 1] = ' ';
	map[x + 1][y + 1] = ' '; 
}

void DiChuyenXe(int &x, int &y) 
{
	if(GetAsyncKeyState(VK_LEFT))
	{
		if(y > 2)
		{
			if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!')
			{
				cout<<"\a";
				gotoxy(30,32);
				textcolor(12);
				cout<<"Game Over !!!, Thank You For Playing "<<endl;	
				Sleep(5000);
				exit(0);			
			}

			map[x][y] = ' '; 
			map[x][y - 1] = ' ';
			map[x][y + 1] = ' '; 
			map[x - 1][y - 1] = ' '; 
			map[x + 1][y - 1] = ' '; 
			map[x - 1][y + 1] = ' '; 
			map[x + 1][y + 1] = ' '; 
			y--; 
			VeXePlayer(x, y); 
			
		}
		
	}
	else if(GetAsyncKeyState(VK_RIGHT))
	{
		if(y <= 26)
		{
			if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!')
			{
				cout<<"\a";
				gotoxy(30,32);
				textcolor(12);
				cout<<"Game Over !!!, Thank You For Playing "<<endl;	
				Sleep(5000);
				exit(0); 
			}
			map[x][y] = ' ';
			map[x][y - 1] = ' '; 
			map[x][y + 1] = ' ';
			map[x - 1][y - 1] = ' '; 
			map[x + 1][y - 1] = ' ';
			map[x - 1][y + 1] = ' '; 
			map[x + 1][y + 1] = ' '; 
			y++; 
			VeXePlayer(x, y);
		}
	}
	else if(GetAsyncKeyState(VK_UP))
	{
		if(x > 1)
		{
			if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!')
			{
				cout<<"\a";
				gotoxy(30,32);
				textcolor(12);
				cout<<"Game Over !!!, Thank You For Playing "<<endl;	
				Sleep(5000);
				exit(0);
			}
			map[x][y] = ' '; 
			map[x][y - 1] = ' ';
			map[x][y + 1] = ' ';
			map[x - 1][y - 1] = ' '; 
			map[x + 1][y - 1] = ' '; 
			map[x - 1][y + 1] = ' '; 
			map[x + 1][y + 1] = ' ';
			x--; 
			VeXePlayer(x, y); 
		}
	}
	else if(GetAsyncKeyState(VK_DOWN))
	{
		if(x <= 27)
		{
			if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!')
			{	
				cout<<"\a";
				gotoxy(30,32);
				textcolor(12);
				cout<<"Game Over !!!, Thank You For Playing "<<endl;	
				Sleep(5000);		
				exit(0); 
			}
			map[x][y] = ' '; 
			map[x][y - 1] = ' '; 
			map[x][y + 1] = ' '; 
			map[x - 1][y - 1] = ' ';
			map[x + 1][y - 1] = ' ';
			map[x - 1][y + 1] = ' '; 
			map[x + 1][y + 1] = ' ';
			x++; 
			VeXePlayer(x, y); 
		}
	}
}
int main()
{
	resizeConsole(800, 600);
	int x = 20, y = 15; 
	int x1 = 2, y1;
	int x2 = 5, y2 = 10; 
	int x3 = 6, y3 = 7;
	int a = 0;
	int diem=0;
	int n=1,k=5;
	while(true)
	{
		a++;
		if(a % 2 != 0)
		{
			VeDuongDua_1();
		}
		else
		{
			VeDuongDua_2();
		}
		srand(time(0)); 
		y1 = 2 + rand() % 26;
		VeXePlayer(x, y);
		VeXeChuongNgaiVat(x1, y1); 
		VeXeChuongNgaiVat(x2, y2); 
		VeXeChuongNgaiVat(x3, y3); 
		XoaManHinh();	
		InDuongDua();
		DiChuyenXe(x, y);
		if(a >= 30)
		{
			a = 0;
		}
		if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!')
		{
			cout<<"\a";
			gotoxy(30,32);
			textcolor(12);
			cout<<"Game Over !!!, Thank You For Playing "<<endl;	
			Sleep(5000);
			return 0; 
		}
		
		XoaXeChuongNgai(x1, y1);
		x1++;
		if(x1 == 31)
		{
			x1 = 2;
			diem++;
			if(diem%8==0)
			{
				n++;
			}
			gotoxy(85,29);
			textcolor(11);
			cout<<" DIEM : "<<diem;
		}
		XoaXeChuongNgai(x2, y2);
		x2++;
		if(x2 == 31)
		{
			x2 = 5;
			y2 = 2 + rand() % 26;
			diem++;
			gotoxy(85,29);
			textcolor(11);
			cout<<" DIEM : "<<diem;
			if(diem%8==0)
			{
				n++;
			}
			gotoxy(85,30);
			textcolor(13);
			cout<<" LEVER : "<<n;
		}
		XoaXeChuongNgai(x3, y3);
		x3++;
		if(x3 == 31)
		{
			x3 = 6;
			y3 = 3 + rand() % 25;
			diem++;
			gotoxy(85,29);
			textcolor(11);
			cout<<" DIEM : "<<diem;
			if(diem%8==0)
			{
				n++;
			}
			gotoxy(85,30);
			textcolor(13);
			cout<<" LEVER : "<<n;
		}
		gotoxy(85,28);
		textcolor(13);
		cout<<" SLEEP "<<10-n;
		Sleep(10-n);
		if(n==10)
		{
			cout<<"\a";
			gotoxy(30,32);
			textcolor(14);
			cout<<"Game Over Congratulations!!! You Won The Cup"<<endl;	
			Sleep(5000);
			return 0;
		}
	}
	system("pause");
	getch();
	return 0;

}
