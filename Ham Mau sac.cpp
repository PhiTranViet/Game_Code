#include<iostream>
#include<cstring>
#include<Windows.h>
#include<ctime>

using namespace std;
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle
	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
int main()
{
	int i;
	for(i=1;i<=255;i++)
	{
		textcolor(i);
		cout<<"\n i = "<<i;	
	}
	return 0;
}
