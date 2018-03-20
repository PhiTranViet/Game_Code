int main()
{
	srand(time(NULL));
	resizeConsole(800, 600);
	game();
	gotoxt(30, 21);
	textcolor(11);
	cout<<"BAM PHIM 1,2,3,4 DE LUA CHON :";
	gotoxt(40, 23);
	cout<<"1. PLAY ");
	gotoxt(40, 24);
	cout<<"2. HUONG DAN");
	gotoxt(40, 25);
	cout<<"3. NGUOI SAN XUAT ");
	gotoxt(40, 26);
	cout<<"4. THOAT");
	int m = _getch();
	if (m == '1')
	{
	gotoxt(25, 12);
	cout<<"NHAP TEN NGUOI CHOI: ";
	gets_s(ten);		
	pause();
	int x = 20, y = 15; 
	int x1 = 2, y1;
	int x2 = 5, y2 = 10; 

	int a = 0;
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
		y1 = 2 + rand() % 26; // [2, 27]

		VeXePlayer(x, y);
		VeXeChuongNgaiVat(x1, y1); 
		VeXeChuongNgaiVat(x2, y2); 

		XoaManHinh();
	
		InDuongDua();

		DiChuyenXe(x, y);

		Sleep(0);

		if(a >= 30)
		{
			a = 0;
		}
		if(map[x][y] == '!' || map[x][y - 1] == '!' || map[x][y + 1] == '!' || map[x - 1][y - 1] == '!' || map[x + 1][y - 1] == '!' || map[x - 1][y + 1] == '!' || map[x + 1][y + 1] == '!')
		{
			return 0; 
		}

		XoaXeChuongNgai(x1, y1);
		x1++;
		if(x1 == 31)
		{
			x1 = 2;
		}
		XoaXeChuongNgai(x2, y2);
		x2++;
		if(x2 == 31)
		{
			x2 = 5;
			y2 = 2 + rand() % 26;
		}
	}
	if (m == 2)
	{
		gotoxy(30, 10);
		printf("Ban su dung cac phim :\n				Phim 'a' de di chuyen sang trai\n				Phim 'd' de di chuyen sang phai\n				Phim 'w' de di chuyen di len\n				Phim 's' de di chuyen di xuong\n				Phim '4' de tro lai\n				Phim '5' de dung tro choi\n				Phim '6' de tiep tuc");
		gotoxy(50, 20);
		printf("4. TRO LAI ");
		
	} 
	if (m == 3)
	{
		huudai();

		gotoxy(29, 27);
		printf("4. TRO LAI ");
		while (_getch() != 52);
	}
	if (m == 4)
		return 0;
}
