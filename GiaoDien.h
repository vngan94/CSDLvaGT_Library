void Normal() //Nen den, chu trang
{
	Color(15);
	BGColor(0);
}
void HighLight() //Nen hong, chu trang
{
	Color(15);
	BGColor(12);
}
void HighLight1() //Nen xanh, chu trang
{
	Color(15);
	BGColor(1);
}
void Setup() //Khoi tao trang thai ban dau
{
	resizeConsole(1400, 700);
}
void Outline() //Tao khung
{
	int i;
	GoToXY(0, 8); for (i = 0; i < 185; i++) cout << (char)196;
	GoToXY(44, y2 - 2); cout << (char)194;
	for (i = -1; i < (n + 10); i++)
	{
		if (i == 11) { GoToXY(44, y2 + i); cout << (char)180; }
		else { GoToXY(44, y2 + i); cout << (char)179; }
	}
	GoToXY(44, y2 + 20); cout << (char)217;
	GoToXY(x3, y3 - 1); for (i = 0; i < 44; i++) cout << (char)196;
	GoToXY(x3, y3 + 8); for (i = 0; i < 44; i++) cout << (char)196;
}
void Title() //Tieu de
{
	Color(11);
	GoToXY(x1, 0); cout << "  ____                      _             _______ _           __      ___                    ";
	GoToXY(x1, 1); cout << " / __ \\                    | |           |__   __| |          \\ \\    / (_)                 ";
	GoToXY(x1, 2); cout << "| |  | |_   _  __ _ _ __   | |    _   _     | |  | |__  _   _  \\ \\  / / _  ___ _ __         ";
	GoToXY(x1, 3); cout << "| |  | | | | |/ _` | '_ \\  | |   | | | |    | |  | '_ \\| | | |  \\ \\/ / | |/ _ \\ '_ \\    ";
	GoToXY(x1, 4); cout << "| |__| | |_| | (_| | | | | | |___| |_| |    | |  | | | | |_| |   \\  /  | |  __/ | | |        ";
	GoToXY(x1, 5); cout << " \\___\\_\\\\__,_|\\__,_|_| |_| |______\\__, |    |_|  |_| |_|\\__,_|    \\/   |_|\\___|_| |_|";
	GoToXY(x1, 6); cout << "                                   __/ |                                                      ";
	GoToXY(x1, 7); cout << "                                  |___/                                                       ";
	Color(8);
	GoToXY(x1 + 107, 6); cout << "NGO THU HA - N18DCCN052";
	GoToXY(x1 + 107, 7); cout << "NGUYEN QUOC NHAT - N18DCCN142";
}
int Menu() //Tao menu
{
	Normal();
	modifyCursor(1, false);
	int i, choose = 0;
	char kytu;
	GoToXY(x2 + 18, y2 - 1); cout << "MENU";
	for (i = 0; i < n; i++) { GoToXY(x2, y2 + i); cout << menu[i] << endl; }
	GoToXY(x2, y2);
	HighLight();
	cout << menu[choose];
	do
	{
		kytu = GetKey();
		switch (kytu)
		{
			case Up:	if (choose + 1 > 1)
			{
				Normal();
				GoToXY(x2, y2 + choose);
				cout << menu[choose];
				choose--;
				HighLight();
				GoToXY(x2, y2 + choose);
				cout << menu[choose];
			} break;
			case Down:	if (choose + 1 < n)
			{
				Normal();
				GoToXY(x2, y2 + choose);
				cout << menu[choose];
				choose++;
				HighLight();
				GoToXY(x2, y2 + choose);
				cout << menu[choose];
			} break;
			case ESC: return 12;
			case Enter: return choose + 1;
		}
	} while (1);
}
void Sign() //Huong dan
{
	Normal();
	GoToXY(x3 + 15, y3); cout << "HUONG DAN";
	GoToXY(x3, y3 + 1); cout << "Di chuyen thanh sang\tMui ten len xuong";
	GoToXY(x3, y3 + 2); cout << "Chon\t\t\tEnter";
	GoToXY(x3, y3 + 3); cout << "Thoat chuong trinh\tESC";
}
void DeleteSign() //Xoa bang huong dan
{
	Normal();
	int i, j;
	for (i = 0; i < 7; i++)
	{
		GoToXY(x3, y3 + i);
		for (j = 0; j < 44; j++) cout << " ";
	}
}
void DeleteScreen() //Xoa nguyen man hinh tru menu, huong dan, tieu de
{
	Normal();
	int i, j;
	for (i = 0; i < 30; i++)
	{
		GoToXY(45, 9 + i);
		for (j = 0; j < 140; j++) cout << " ";
	}
}
void DeleteGocPhai() //Xoa man hinh goc phai phia tren
{
	for(int i = 0; i <= 12; i++)
	{
		for(int j = 0; j <= 50; j++)
		{
			GoToXY(132 + j, 11 + i); cout << " ";
		}
	}
}
void MuiTen() //Mui ten tu trai qua phai -->
{
	Color(14);
	BGColor(0);
	cout << (char)196 << (char)196 << ">";
}
void MuiTen2() //Mui ten tu phai qua trai <--
{
	Color(14);
	BGColor(0);
	cout << "<" << (char)196 << (char)196;
}
