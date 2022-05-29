Date NgayHienTai() //Tra ve thoi gian hien tai
{
	Date n;
	time_t hientai = time(0);
	tm *ltm = localtime(&hientai);
	n.ngay = ltm->tm_mday;
	n.thang = 1 + ltm->tm_mon;
	n.nam = 1900 + ltm->tm_year;
	return n;
}
int Ngay(Date ngay) //Tinh so ngay tinh toi thoi diem do
{
	if(ngay.thang < 3)
	{
		ngay.nam--;
		ngay.thang += 12;
	}
	return 365 * ngay.nam + ngay.nam/ 4 - ngay.nam/ 100 + ngay.nam/ 400 + (153 * ngay.thang - 457)/ 5 + ngay.ngay - 306;
}
int TinhNgay(Date muon, Date tra) //Ngay trong khoang A -> B
{
	return Ngay(tra) - Ngay(muon);
}
//------------------------------------------------CAU A----------------------------------------------------------------
void BangDocGia(int x, int y) // In bang doc gia
{
	Normal();
	int i;
	GoToXY(x, y + 1); for (i = 0; i < 70; i++) cout << (char)196;
	GoToXY(x, y + 3); for (i = 0; i < 70; i++) cout << (char)196;
	GoToXY(x, y + 1); cout << (char)218;
	GoToXY(x, y + 2); cout << (char)179;
	GoToXY(x, y + 3); cout << (char)195;
	GoToXY(x + 12, y + 1); cout << (char)194;
	GoToXY(x + 12, y + 2); cout << (char)179;
	GoToXY(x + 12, y + 3); cout << (char)197;
	GoToXY(x + 40, y + 1); cout << (char)194;
	GoToXY(x + 40, y + 2); cout << (char)179;
	GoToXY(x + 40, y + 3); cout << (char)197;
	GoToXY(x + 50, y + 1); cout << (char)194;
	GoToXY(x + 50, y + 2); cout << (char)179;
	GoToXY(x + 50, y + 3); cout << (char)197;
	GoToXY(x + 70, y + 1); cout << (char)191;
	GoToXY(x + 70, y + 2); cout << (char)179;
	GoToXY(x + 70, y + 3); cout << (char)180;
	for (i = 0; i < 15; i++)
	{
		GoToXY(x, y + 4 + i); cout << (char)179;
		GoToXY(x + 12, y + 4 + i); cout << (char)179;
		GoToXY(x + 40, y + 4 + i); cout << (char)179;
		GoToXY(x + 50, y + 4 + i); cout << (char)179;
		GoToXY(x + 70, y + 4 + i); cout << (char)179;
	}
	GoToXY(x, y + 19); for (i = 0; i < 70; i++) cout << (char)196;
	GoToXY(x, y + 19); cout << (char)192;
	GoToXY(x + 12, y + 19); cout << (char)193;
	GoToXY(x + 40, y + 19); cout << (char)193;
	GoToXY(x + 50, y + 19); cout << (char)193;
	GoToXY(x + 70, y + 19); cout << (char)217;
	GoToXY(x + 1, y + 2); cout << "  MA THE";
	GoToXY(x + 13, y + 2); cout << "         HO VA TEN";
	GoToXY(x + 41, y + 2); cout << "  PHAI";
	GoToXY(x + 51, y + 2); cout << "  TRANG THAI THE";
}
void HuongDanBangDocGia() //Huong dan su dung bang doc gia
{
	DeleteSign();
	GoToXY(x3 + 15, y3); cout << "HUONG DAN";
	GoToXY(x3, y3 + 1); cout << "Di chuyen mui ten\tMui ten len xuong";
	GoToXY(x3, y3 + 2); cout << "Qua trang\t\tMui ten trai phai";
	GoToXY(x3, y3 + 3); cout << "Them doc gia\t\tF3";
	GoToXY(x3, y3 + 4); cout << "Xoa doc gia\t\tDelete";
	GoToXY(x3, y3 + 5); cout << "Hieu chinh doc gia\tEnter";
	GoToXY(x3, y3 + 6); cout << "Luu doc gia\t\tF2";
	GoToXY(x3, y3 + 7); cout << "Thoat\t\t\tESC";
}
void Preorder(DGPTR p, double &k) // Dem so node tren cay Doc gia -> Duyet theo LNR
{
	if(p != NULL)
	{
		k++;
		Preorder(p->left, k);
		Preorder(p->right, k);
	}
}
void Intrav(DGPTR root, int x, int y, int i) //In thong tin Doc Gia ra bang
{  	
	const int STACKSIZE = 500;
   	DGPTR Stack[STACKSIZE];
   	DGPTR p = root;
   	int bd = (i - 1) * bang; //Vi tri bat dau de in ra bang
   	int kt = i * bang; // Vi tri ket thuc luc in ra bang
   	int j = -1; //Dung de xuong dong khi in
   	int sp = -1;	 // Khoi tao Stack rong
   	do //LNR
	{
		while (p != NULL)
    	{
			Stack[++sp] = p;
			p = p->left;
    	}
      	if (sp != -1)
      	{	
			p = Stack[sp--];
			j++;
			if(j >= bd && j < kt)
			{
				GoToXY(x + 3, y + 4 + j - bd); cout << p->maThe;
				GoToXY(x + 15, y + 4 + j - bd); cout << p->infor.ho << " " << p->infor.ten;
				GoToXY(x + 43, y + 4 + j - bd); cout << p->infor.gioiTinh;
				GoToXY(x + 53, y + 4 + j - bd);
				switch (p->infor.trangThai)
				{
					case biKhoaThe: cout << "Bi Khoa The"; break;
					case conHoatDong: cout << "Con Hoat Dong"; break;
				}
			}
			p = p->right;
    	}
		else break;
	} while (1);
}
void XoaBangDocGia(int x, int y) //Xoa ben trong bang de in du lieu moi
{
	Normal();
	for(int j = 0; j < bang; j++)
	{
		GoToXY(x + 1, y + 4 + j); cout << "           ";
		GoToXY(x + 13, y + 4 + j); cout << "                          ";
		GoToXY(x + 41, y + 4 + j); cout << "        "; 
		GoToXY(x + 51, y + 4 + j); cout << "                  ";
	}
}
void XoaBangDocGiaF (int x, int y)
{
	for (int i = 0; i < 21; i++)                                                                                 
	{
		GoToXY (x + 7, y - 1 + i); cout<<"                                                                       ";
	}
}
void DSDocGia(DGPTR p, int x, int y, int i, double k) //In so trang hien tai va in thong tin Doc gia
{
	Intrav(p, x, y, i);
	GoToXY(x + 30, y + 20); cout << "Trang " << i << "/" << k;
}
void BangThemDocGia(int x, int y) // Bang goc tren ben phai de them Doc gia
{
	int i;
	for(i = 0; i < 40; i++)
	{
		GoToXY(x + i, y); cout << (char)196;
		GoToXY(x + i, y + 5); cout << (char)196;
	}
	for(i = 0; i < 5; i++)
	{
		GoToXY(x, y + i); cout << (char)179;
		GoToXY(x + 40, y + i); cout << (char)179;
	}
	GoToXY(x, y); cout << (char)218;
	GoToXY(x + 40, y); cout << (char)191;
	GoToXY(x, y + 5); cout << (char)192;
	GoToXY(x + 40, y + 5); cout << (char)217;
}
boolean CheckGioiTinh(string &s) //Kiem tra gioi tinh Nam or Nu
{
	ChuanHoaString(s);
	if(s.compare("Nam") == 0 || s.compare("Nu") == 0) return true;
	else false;
}
void Insert_node(DGPTR &p, int x, DocGia a) //Them 1 nut doc gia vao cay
{ 
	if(p == NULL)    // nut p hien tai se là nut la
	{
		p = new NodeDocGia;
		p->maThe = x;		p->infor = a;
		p->left = NULL;		p->right = NULL;  
   	}
   	else
    if(x < p->maThe) Insert_node(p->left, x, a);
    else if(x > p->maThe) Insert_node(p->right, x, a);
}
void ThemDocGia(DGPTR &root, int &sl) //Giai quyet phan them Doc gia theo yeu cau
{
	modifyCursor(1, true);
	int m[1000]; // mang chua so random tao san
	int n, vt = 0, ho = 0, ten = 0, phai = 0;
	DGPTR temp = new NodeDocGia; //Xai tam de gan vao cay sau khi nhap xong
	Normal();
	GoToXY(144, 12); cout << "NHAP THONG TIN DOC GIA";
	BangThemDocGia(135, 14);
	loadRandom(m, n);
	temp->maThe = m[n - 1];
	GoToXY(151, 15); cout << m[n - 1];	
	string MenuKT[4] = {"Ma The:       ",
						"Ho Doc Gia:   ",
						"Ten Doc Gia:  ",
						"Phai(Nam, Nu):"};
	for(int i = 0; i < 4; i++) { GoToXY(136, 15 + i); cout << MenuKT[i]; }					
	GoToXY(151, 16);
	char c;				
	do
	{
		c = GetKey();
		switch (c)
		{
			case Up: if(vt + 1 > 1) //Dua con nhay len tren
			{
				vt--;
				if(vt == 0) {GoToXY(151 + ho, 16 + vt);}
				else if(vt == 1) {GoToXY(151 + ten, 16 + vt);}
				else {GoToXY(151 + phai, 16 + vt);}
			} break;
			case Enter: if(vt + 1 < 3) //Xuong dong
			{
				vt++;
				if(vt == 0) {GoToXY(151 + ho, 16 + vt);}
				else if(vt == 1) {GoToXY(151 + ten, 16 + vt);}
				else {GoToXY(151 + phai, 16 + vt);}
			} break;
			case Down: if(vt + 1 < 3) //Xuong dong
			{
				vt++;
				if(vt == 0) {GoToXY(151 + ho, 16 + vt);}
				else if(vt == 1) {GoToXY(151 + ten, 16 + vt);}
				else {GoToXY(151 + phai, 16 + vt);}
			} break;
			case F2: //Luu doc gia
			{
				ChuanHoaString(temp->infor.ho);
				ChuanHoaString(temp->infor.ten);
				if(temp->infor.ho.compare("") == 0)
				{
					GoToXY(140, 22); cout << "                                ";
					GoToXY(140, 22); cout << "Khong duoc de trong Ho Doc Gia";
					GoToXY(140, 23); cout << "                                ";
				}
				else if(temp->infor.ten.compare("") == 0)
				{
					GoToXY(140, 22); cout << "                                ";
					GoToXY(140, 22); cout << "Khong duoc de trong Ten Doc Gia";
					GoToXY(140, 23); cout << "                                ";
				}
				else if(CheckGioiTinh(temp->infor.gioiTinh) == false)
				{
					GoToXY(140, 22); cout << "                                ";
					GoToXY(140, 22); cout << "Ban nhap sai Phai Doc Gia";
					GoToXY(140, 23); cout << "                                ";
				}
				else
				{
					temp->infor.trangThai = conHoatDong;
					Insert_node(root, temp->maThe, temp->infor);
					SaveDocGia(root);
					SaveRandom(m, n);
					GoToXY(140, 22); cout << "                                ";
					GoToXY(140, 22); cout << "Du lieu da duoc luu lai";
					GoToXY(140, 23); cout << "                                ";
					Sleep(2500);
					GoToXY(140, 22); cout << "                                ";
					sl++;
					return;
				}
				vt = 3;
				break;
			}
			case ESC: //Thoat ra
			{
				ChuanHoaString(temp->infor.ho);
				ChuanHoaString(temp->infor.ten);
				if(temp->infor.ho.compare("") == 0 || temp->infor.ten.compare("") == 0 || CheckGioiTinh(temp->infor.gioiTinh) == false)
				{
					GoToXY(140, 22); cout << "                                ";
					GoToXY(140, 22); cout << "Du lieu nhap chua dung";
					GoToXY(140, 23); cout << "                                ";
					GoToXY(140, 23); cout << "Nhan ESC neu ban van muon thoat";
					char kt = GetKey();
					if(kt == ESC) 
					{
						GoToXY(140, 22); cout << "                                ";
						GoToXY(140, 23); cout << "                                ";
						return;
					}
				}
				else
				{
					GoToXY(140, 22); cout << "                                ";
					GoToXY(140, 22); cout << "Ban co muon luu du lieu?";
					GoToXY(140, 23); cout << "                                ";
					GoToXY(140, 23); cout << "LUU (Y)\t KHONG LUU (N)";
					do
					{
						char kt = GetKey();
						if(kt == 'Y' || kt == 'y') 
						{
							GoToXY(140, 22); cout << "                                ";
							GoToXY(140, 23); cout << "                                ";
							GoToXY(140, 22); cout << "Du lieu da tu dong luu lai";
							GoToXY(140, 23); cout << "                                ";
							Sleep(2500);
							GoToXY(140, 22); cout << "                                ";
							temp->infor.trangThai = conHoatDong;
							Insert_node(root, temp->maThe, temp->infor);
							SaveDocGia(root);
							SaveRandom(m, n);
							sl++;
							return;
						}
						else if(kt == 'N' || kt == 'n') { return; }
					} while(1);
				}
				vt = 3;
				break;
			}
			default: switch(vt)
			{
				case 0: //Vi tri con tro o phan HO
				{
					if(c == Backspace)
					{
						if(ho > 0)
						{
							temp->infor.ho = temp->infor.ho.substr(0, --ho);
							GoToXY(151 + ho, 16 + vt); cout << " ";
							GoToXY(151 + ho, 16 + vt);
						}		
					}
					else if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32) //Lay chu cai hoa, chu thuong, khoang trang
					{
						temp->infor.ho += c;
						ho++;
						cout << c;
					}	
				} break;
				case 1: //Vi tri con tro o phan TEN
				{
					if(c == Backspace)
					{
						if(ten > 0)
						{
							temp->infor.ten = temp->infor.ten.substr(0, --ten);
							GoToXY(151 + ten, 16 + vt); cout << " ";
							GoToXY(151 + ten, 16 + vt);
						}	
					}
					else if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32) //Lay chu cai in thuong, in hoa vs khoang trang
					{
						temp->infor.ten += c;
						ten++;
						cout << c;
					}
				} break;
				case 2: //Vi tri con tro o phan PHAI
				{
					if(c == Backspace)
					{
						if(phai > 0)
						{
							temp->infor.gioiTinh = temp->infor.gioiTinh.substr(0, --phai);
							GoToXY(151 + phai, 16 + vt); cout << " ";
							GoToXY(151 + phai, 16 + vt);
						}	
					}
					else if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) //Chi lay chu cai in thuong, in hoa
					{
						temp->infor.gioiTinh += c;
						phai++;
						cout << c;
					}
				} break;
			}
		}
	} while(1);
}
void delKey(DGPTR &T, int x) // Xoa nut co key x
{
    if (T == NULL) return;
    else if (T->maThe > x) return delKey(T->left, x);
    else if (T->maThe < x) return delKey(T->right, x);
    else // T->key == x
    {
        if (T->left == NULL) T = T->right;    // Node chi co cay con phai
        else if (T->right == NULL) T = T->left;   // Node chi co cay con trai
        else // Node co ca 2 con
        {
            DGPTR Q = T->left;
            while (Q->right != NULL)
            {
                Q = Q->right;
            }
            T->maThe = Q->maThe;
            delKey(T->left, Q->maThe);
        }
    }
}
void XoaDocGia(DGPTR &root, int i, int vt, int &sl) //Xoa 1 doc gia
{
	Normal();
	const int STACKSIZE = 500;
	DGPTR Stack[STACKSIZE];
	DGPTR p = root;
	int key = (i - 1) * bang + vt; //Vi tri cua doc gia do
	int dem = -1;	//Dung de dem den vi tri cua doc gia
	int sp = -1;	 // Khoi tao Stack rong
	do
	{ 
		while (p != NULL)
		{
			Stack[++sp]= p;
			p = p->left;
    	}
		if (sp != -1)
		{	
			p = Stack[sp--];
			if(++dem == key) break; //Tai vi tri doc gia do thi dung
			p = p->right;
    	}
    	else break;
	} while(1);
	if(p->infor.MT != NULL)
	{
		GoToXY(135, 14); cout << "Khong the xoa vi doc gia da hoac dang muon sach";
		Sleep(2500);
	}
	else
	{
		GoToXY(140, 14); cout << "Ban co muon xoa doc gia?";
		GoToXY(140, 15); cout << "XOA (Y)\t KHONG XOA (N)";
		char kt;
		do
		{
			kt = GetKey();
			if(kt == 'Y' || kt == 'y')
			{
				delKey(root, p->maThe);
				SaveDocGia(root);
				GoToXY(135, 14); cout << "                                  ";
				GoToXY(135, 14); cout << "Da xoa doc gia thanh cong";
				GoToXY(135, 15); cout << "                                  ";
				sl--;
				Sleep(2500);
				return;
			}
			else if(kt == 'N' || kt == 'n') { return; }
		} while(1);
	}
}
void HieuChinh(DGPTR &root, int i, int k) //Hieu chinh doc gia
{
	Normal();
	modifyCursor(1, true);
	char c;
	int ho, ten, phai;
	int vt = 0;
	DGPTR tam = root;
	const int STACKSIZE = 500;
	DGPTR Stack[STACKSIZE];
	int key = (i - 1) * bang + k; //Vi tri cua doc gia do
	int dem = -1; // Dem toi vi tri cua doc gia do
	int sp = -1;	 // Khoi tao Stack rong
	do
	{ 
		while (tam != NULL)
  		{
			Stack[++sp] = tam;
			tam = tam->left;
    	}
		if (sp != -1)
		{	
			tam = Stack[sp--];
			if(++dem == key) break;
			tam = tam->right;
    	}
    	else break;
	} while(1);
	GoToXY(141, 12); cout << "HIEU CHINH THONG TIN DOC GIA";
	BangThemDocGia(135, 14);
	string MenuKT[4] = {"Ma The:       ",
						"Ho Doc Gia:   ",
						"Ten Doc Gia:  ",
						"Phai(Nam, Nu):"};
	for(i = 0; i < 4; i++) { GoToXY(136, 15 + i); cout << MenuKT[i]; }
	DocGia temp = tam->infor;
	int maThe = tam->maThe;
	GoToXY(151, 15); cout << maThe;							
	GoToXY(151, 16); cout << temp.ho;							
	GoToXY(151, 17); cout << temp.ten;							
	GoToXY(151, 18); cout << temp.gioiTinh;							
	ho = temp.ho.length();
	ten = temp.ten.length();
	phai = temp.gioiTinh.length();
	GoToXY(151 + ho, 16);
	do
	{
		c = GetKey();
		switch(c)
		{
			case Up: if(vt + 1 > 1) //Len dong tren
			{
				vt--;
				if(vt == 0) {GoToXY(151 + ho, 16 + vt);}
				else if(vt == 1) {GoToXY(151 + ten, 16 + vt);}
				else {GoToXY(151 + phai, 16 + vt);}
			} break;
			case Enter: if(vt + 1 < 3) //Xuong dong
			{
				vt++;
				if(vt == 0) {GoToXY(151 + ho, 16 + vt);}
				else if(vt == 1) {GoToXY(151 + ten, 16 + vt);}
				else {GoToXY(151 + phai, 16 + vt);}
			} break;
			case Down: if(vt + 1 < 3) //Xuong dong
			{
				vt++;
				if(vt == 0) {GoToXY(151 + ho, 16 + vt);}
				else if(vt == 1) {GoToXY(151 + ten, 16 + vt);}
				else {GoToXY(151 + phai, 16 + vt);}
			} break;
			case F2: //Save
			{
				ChuanHoaString(temp.ho);
				ChuanHoaString(temp.ten);
				if(temp.ho.compare("") == 0)
				{
					GoToXY(140, 22); cout << "                                ";
					GoToXY(140, 22); cout << "Khong duoc de trong Ho Doc Gia";
					GoToXY(140, 23); cout << "                                ";
				}
				else if(temp.ten.compare("") == 0)
				{
					GoToXY(140, 22); cout << "                                ";
					GoToXY(140, 22); cout << "Khong duoc de trong Ten Doc Gia";
					GoToXY(140, 23); cout << "                                ";
				}
				else if(CheckGioiTinh(temp.gioiTinh) == false)
				{
					GoToXY(140, 22); cout << "                                ";
					GoToXY(140, 22); cout << "Ban nhap sai Phai Doc Gia";
					GoToXY(140, 23); cout << "                                ";
				}
				else
				{
					tam->infor = temp;
					SaveDocGia(root);
					GoToXY(140, 22); cout << "                                ";
					GoToXY(140, 22); cout << "Du lieu da duoc luu lai";
					GoToXY(140, 23); cout << "                                ";
					Sleep(2500);
					GoToXY(140, 22); cout << "                                ";
					return;
				}
				vt = 3;
				break;
			}
			case ESC: //Thoat -> 2 truong hop
			{
				ChuanHoaString(temp.ho);
				ChuanHoaString(temp.ten);
				if(temp.ho.compare("") == 0 || temp.ten.compare("") == 0 || CheckGioiTinh(temp.gioiTinh) == false)
				{
					GoToXY(140, 22); cout << "                                ";
					GoToXY(140, 22); cout << "Du lieu nhap chua dung";
					GoToXY(140, 23); cout << "                                ";
					GoToXY(140, 23); cout << "Nhan ESC neu ban van muon thoat";
					char kt = GetKey();
					if(kt == ESC) 
					{
						GoToXY(140, 22); cout << "                                ";
						GoToXY(140, 23); cout << "                                ";
						return;
					}
				}
				else
				{
					GoToXY(140, 22); cout << "                                ";
					GoToXY(140, 22); cout << "Ban co muon luu du lieu?";
					GoToXY(140, 23); cout << "                                ";
					GoToXY(140, 23); cout << "LUU (Y)\t KHONG LUU (N)";
					do
					{
						char kt = GetKey();
						if(kt == 'Y' || kt == 'y') 
						{
							GoToXY(140, 22); cout << "                                ";
							GoToXY(140, 23); cout << "                                ";
							GoToXY(140, 22); cout << "Du lieu da tu dong luu lai";
							GoToXY(140, 23); cout << "                                ";
							Sleep(2500);
							GoToXY(140, 22); cout << "                                ";
							tam->infor = temp;
							SaveDocGia(root);
							return;
						}			
						else if(kt == 'N' || kt == 'n') { return; }
					} while(1);
				}
				vt = 3;
				break;
			}
			default: switch(vt)
			{
				case 0: //Vi tri con tro o phan HO
				{
					if(c == Backspace)
					{
						if(ho > 0)
						{
							temp.ho = temp.ho.substr(0, --ho);
							GoToXY(151 + ho, 16 + vt); cout << " ";
							GoToXY(151 + ho, 16 + vt);
						}		
					}
					else if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32) //Chu hoa, chu thuong, space
					{
						temp.ho += c;
						ho++;
						cout << c;
					}	
				} break;
				case 1: //Vi tri con tro o phan TEN
				{
					if(c == Backspace)
					{
						if(ten > 0)
						{
							temp.ten = temp.ten.substr(0, --ten);
							GoToXY(151 + ten, 16 + vt); cout << " ";
							GoToXY(151 + ten, 16 + vt);
						}	
					}
					else if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32) //Chu hoa, chu thuong, space
					{
						temp.ten += c;
						ten++;
						cout << c;
					}
				} break;
				case 2: //Vi tri con tro o phan PHAI
				{
					if(c == Backspace)
					{
						if(phai > 0)
						{
							temp.gioiTinh = temp.gioiTinh.substr(0, --phai);
							GoToXY(151 + phai, 16 + vt); cout << " ";
							GoToXY(151 + phai, 16 + vt);
						}	
					}
					else if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) //Chu hoa, chu thuong
					{
						temp.gioiTinh += c;
						phai++;
						cout << c;
					}
				} break;
			}
		} 
	} while(1);
}
void InDocGia(DGPTR root, int x, int y) //Giai quyet van de Them/ Xoa/ Hieu chinh doc gia
{
	int sl, i = 1, muiten = 0;
	double k = 0;
	Preorder(root, k);
	sl = k; //So luong doc gia
	k = ceil(k/ bang); //So trang
	DSDocGia(root, x, y, i, k);
	GoToXY(x - 3, y + 4); MuiTen();
	do
	{
		char kytu = GetKey();
		switch (kytu)
		{
			case Up: if(muiten + 1 > 1) //Mui ten di len
			{
				Normal();
				GoToXY(x - 3, y + 4 + muiten); cout << "   ";
				muiten--;
				GoToXY(x - 3, y + 4 + muiten); MuiTen();
			} break;
			case Down: if(muiten + 1 < bang && muiten < (sl - ((i - 1) * bang) - 1)) //Mui ten di xuong
			{
				Normal();
				GoToXY(x - 3, y + 4 + muiten); cout << "   ";
				muiten++;
				GoToXY(x - 3, y + 4 + muiten); MuiTen();
			} break;
			case Right: if(i < k) //Qua trang
			{
				XoaBangDocGia(x, y);
				DSDocGia(root, x, y, ++i, k);
				if(i == k && sl % bang != 0 && muiten > sl % bang - 1)
				{
					GoToXY(x - 3, y + 4 + muiten); cout << "   ";
					muiten = sl - ((i - 1) * bang) - 1;
					GoToXY(x - 3, y + 4 + muiten); MuiTen();
				}
			} break;
			case Left: if(i > 1) //Qua trang
			{
				XoaBangDocGia(x, y);
				DSDocGia(root, x, y, --i, k);
			} break;
			case F3: //Them doc gia
			{
				ThemDocGia(root, sl);
				DeleteGocPhai();
				k = 0;
				Preorder(root, k);
				k = ceil(k/ bang);
				XoaBangDocGia(x, y);
				DSDocGia(root, x, y, i, k);
				modifyCursor(1, false);
			} break;
			case Delete: //Xoa doc gia
			{
				XoaDocGia(root, i, muiten, sl);
				DeleteGocPhai();
				XoaBangDocGia(x, y);
				DSDocGia(root, x, y, i, k);
				if(sl - (i - 1) * bang == 0)
				{
					XoaBangDocGia(x, y);
					DSDocGia(root, x, y, --i, --k);
				}
				else if(muiten > sl - (i - 1) * bang - 1)
				{
					GoToXY(x - 3, y + 4 + muiten); cout << "   ";
					muiten = sl - ((i - 1) * bang) - 1;
					GoToXY(x - 3, y + 4 + muiten); MuiTen();
				}
				
			} break;
			case Enter: //Hieu chinh doc gia
			{
				HieuChinh(root, i, muiten);
				modifyCursor(1, false);
				DeleteGocPhai();
				XoaBangDocGia(x, y);
				DSDocGia(root, x, y, i, k);
			} break;
			case ESC: return;	
		}
	} while(1);
}
//------------------------------------------------------CAU B----------------------------------------------------------------
int BangChonThuTu(int x, int y) //In ra sap thu tu theo yeu cau ng dung
{
	modifyCursor(1, false);
	string YeuCauDocGia[3] = { "1. Thu tu tang dan theo ten + ho  ",
							   "2. Thu tu tang den theo ma doc gia",
							   "3. Thoat                          " };
	int i, c = 0;
	GoToXY(x, y - 2); cout << "       DANH SACH DOC GIA";
	for (i = 0; i < 3; i++)	{ GoToXY(x, y + i); cout << YeuCauDocGia[i]; }
	HighLight1();
	GoToXY(x, y); cout << YeuCauDocGia[c];
	char kytu;
	do
	{
		kytu = GetKey();
		switch (kytu)
		{
			case Up: if (c + 1 > 1) //Len dong tren
			{
				Normal();
				GoToXY(x, y + c);
				cout << YeuCauDocGia[c];
				c--;
				HighLight1();
				GoToXY(x, y + c);
				cout << YeuCauDocGia[c];
			} break;
			case Down:if (c + 1 < 3) //Xuong dong
			{
				Normal();
				GoToXY(x, y + c);
				cout << YeuCauDocGia[c];
				c++;
				HighLight1();
				GoToXY(x, y + c);
				cout << YeuCauDocGia[c];
			} break;
			case Enter: return c + 1;
			case ESC: return 3;
		}
	} while (1);
}
void HuongDanBangChonThuTu() //Huong dan bang chon thu tu
{
	DeleteSign();
	GoToXY(x3 + 15, y3); cout << "HUONG DAN";
	GoToXY(x3, y3 + 1); cout << "Di chuyen thanh sang\tMui ten len xuong";
	GoToXY(x3, y3 + 2); cout << "Qua trang\t\tMui ten trai phai";
	GoToXY(x3, y3 + 3); cout << "Chon\t\t\tEnter";
	GoToXY(x3, y3 + 4); cout << "Thoat\t\t\tESC";
}
void TreeToMang(DGPTR p, DGPTR *m, int &dem) // Chuyen cay nhi phan thanh mang
{
	if(p != NULL)
	{
		TreeToMang(p->left, m, dem);
		m[++dem] = p;
		TreeToMang(p->right, m, dem);
	}
}
void DSDocGiaMang(DGPTR *m, int x, int y, int i, int k, int dem) //In danh sach doc gia dua tren mang
{
	int u = 0;
	if(i * bang < dem) dem = i * bang; //kt -> ket thuc: bien dung de j chay toi phan tu cuoi cua mang
	for(int j = ((i - 1) * bang); j < dem; j++)
	{
		GoToXY(x + 3, y + 4 + u); cout << m[j]->maThe;
		GoToXY(x + 15, y + 4 + u); cout << m[j]->infor.ho << " " << m[j]->infor.ten;
		GoToXY(x + 43, y + 4 + u); cout << m[j]->infor.gioiTinh;
		GoToXY(x + 53, y + 4 + u);
	 	switch (m[j]->infor.trangThai)
		{
			case biKhoaThe: cout << "Bi Khoa The"; break;
			case conHoatDong: cout << "Con Hoat Dong"; break;
		}
		u++;
	}
	GoToXY(x + 30, y + 20); cout << "Trang " << i << "/" << k;
}
void TenDocGiaTangDan(DGPTR root, int x, int y) // Sap xep thu tu doc gia tang dan theo ten
{
	DGPTR m[maxdocgia];
	int i, j, dem = -1;
	DGPTR temp;
	TreeToMang(root, m, dem);
	dem++;
	for(i = 0; i < dem; i++)
	{
		for(j = i + 1; j < dem; j++)
		{
			if(m[i]->infor.ten > m[j]->infor.ten)
			{
				temp = m[i];
				m[i] = m[j];
				m[j] = temp;
			}
			else if(m[i]->infor.ten == m[j]->infor.ten)
			{
				if(m[i]->infor.ho > m[j]->infor.ho)
				{
					temp = m[i];
					m[i] = m[j];
					m[j] = temp;
				}
			}
		}
	}
	double k = dem;
	i = 1;
	k = ceil(k/ bang);
	DSDocGiaMang(m, x, y, i, k, dem);
	do
	{
		char kytu = GetKey();
		switch (kytu)
		{
			case Right: if(i < k) //Qua trang
			{
				XoaBangDocGia(x, y);
				DSDocGiaMang(m, x, y, ++i, k, dem);
			} break;
			case Left: if(i > 1) //Qua trang
			{
				XoaBangDocGia(x, y);
				DSDocGiaMang(m, x, y, --i, k, dem);
			} break;
			case ESC: return;	
		}
	} while(1);
}
void MaDocGiaTangDan(DGPTR root, int x, int y) // Sap xep thu tu doc gia tang dan theo ma
{
	double k = 0;
	int i = 1;
	SaveDocGia(root);
	loadDocGia(root); //Them nut theo kieu cay nhi phan tim kiem can bang
	Preorder(root, k);
	k = ceil(k/ bang);
	DSDocGia(root, x, y, i, k);
	do
	{
		char kytu = GetKey();
		switch (kytu)
		{
			case Right: if(i < k) //Qua trang
			{
				XoaBangDocGia(x, y);
				DSDocGia(root, x, y, ++i, k);
			} break;
			case Left: if(i > 1) //Qua trang
			{
				XoaBangDocGia(x, y);
				DSDocGia(root, x, y, --i, k);
			} break;
			case ESC: return;	
		}
	} while(1);
}
//------------------------------------------------------CAU C----------------------------------------------------------------
void BangDauSach(int x, int y) //Bang de in dau sach
{
	int i;
	GoToXY(x, y + 1); for (i = 0; i < 105; i++) cout << (char)196;
	GoToXY(x, y + 3); for (i = 0; i < 105; i++) cout << (char)196;
	GoToXY(x, y + 1); cout << (char)218;
	GoToXY(x, y + 2); cout << (char)179;
	GoToXY(x, y + 3); cout << (char)195;
	GoToXY(x + 12, y + 1); cout << (char)194;
	GoToXY(x + 12, y + 2); cout << (char)179;
	GoToXY(x + 12, y + 3); cout << (char)197;
	GoToXY(x + 40, y + 1); cout << (char)194;
	GoToXY(x + 40, y + 2); cout << (char)179;
	GoToXY(x + 40, y + 3); cout << (char)197;
	GoToXY(x + 50, y + 1); cout << (char)194;
	GoToXY(x + 50, y + 2); cout << (char)179;
	GoToXY(x + 50, y + 3); cout << (char)197;
	GoToXY(x + 75, y + 1); cout << (char)194;
	GoToXY(x + 75, y + 2); cout << (char)179;
	GoToXY(x + 75, y + 3); cout << (char)197;
	GoToXY(x + 90, y + 1); cout << (char)194;
	GoToXY(x + 90, y + 2); cout << (char)179;
	GoToXY(x + 90, y + 3); cout << (char)197;
	GoToXY(x + 105, y + 1); cout << (char)191;
	GoToXY(x + 105, y + 2); cout << (char)179;
	GoToXY(x + 105, y + 3); cout << (char)180;
	for (i = 0; i < 15; i++)
	{
		GoToXY(x, y + 4 + i); cout << (char)179;
		GoToXY(x + 12, y + 4 + i); cout << (char)179;
		GoToXY(x + 40, y + 4 + i); cout << (char)179;
		GoToXY(x + 50, y + 4 + i); cout << (char)179;
		GoToXY(x + 75, y + 4 + i); cout << (char)179;
		GoToXY(x + 75, y + 4 + i); cout << (char)179;
		GoToXY(x + 90, y + 4 + i); cout << (char)179;
		GoToXY(x + 105, y + 4 + i); cout << (char)179;
	}
	GoToXY(x, y + 19); for(i = 0; i < 105; i++) cout << (char)196;
	GoToXY(x, y + 19); cout << (char)192;
	GoToXY(x + 12, y + 19); cout << (char)193;
	GoToXY(x + 40, y + 19); cout << (char)193;
	GoToXY(x + 50, y + 19); cout << (char)193;
	GoToXY(x + 75, y + 19); cout << (char)193;
	GoToXY(x + 90, y + 19); cout << (char)193;
	GoToXY(x + 105, y + 19); cout << (char)217;
	GoToXY(x + 1, y + 2); cout << "   ISBN";
	GoToXY(x + 13, y + 2); cout << "         TEN SACH";
	GoToXY(x + 41, y + 2); cout << "SO TRANG";
	GoToXY(x + 51, y + 2); cout << "        TAC GIA";
	GoToXY(x + 76, y + 2); cout << " NAM XUAT BAN";
	GoToXY(x + 91, y + 2); cout << "   THE LOAI";
}
void XoaBangDauSach(int x, int y) //Xoa ben trong bang de in du lieu moi
{
	Normal();
	for(int i = 0; i < bang; i++)
	{
		GoToXY(x + 1, y + i + 4); cout << "          ";
		GoToXY(x + 13, y + i + 4); cout << "                         ";
		GoToXY(x + 41, y + i + 4); cout << "        ";
		GoToXY(x + 51, y + i + 4); cout << "                       ";
		GoToXY(x + 76, y + i + 4); cout << "             ";
		GoToXY(x + 91, y + i + 4); cout << "             ";
	}
}
void HuongDanThemDauSach() //Huong dan de them, xoa hieu chinh dau sach
{
	DeleteSign();
	GoToXY(x3 + 15, y3); cout << "HUONG DAN";
	GoToXY(x3, y3 + 1); cout << "Di chuyen mui ten\tMui ten len xuong";
	GoToXY(x3, y3 + 2); cout << "Qua trang\t\tMui ten trai phai";
	GoToXY(x3, y3 + 3); cout << "Them dau sach\t\tF3";
	GoToXY(x3, y3 + 4); cout << "Xoa dau sach\t\tDelete";
	GoToXY(x3, y3 + 5); cout << "Hieu chinh dau sach\tEnter";
	GoToXY(x3, y3 + 6); cout << "Luu dau sach\t\tF2";
	GoToXY(x3, y3 + 7); cout << "Thoat\t\t\tESC";
}
void InDauSach(DSDauSach m, int x, int y, int j, double page) //In du lieu dau sach vao bang
{
	Normal();
	int kt, dem = -1;
	if(j * bang > m.n) kt = m.n; //Vi tri ket thuc
	else kt = j * bang;
	for(int i = (j - 1) * bang; i < kt; i++)
	{
		dem++;
		GoToXY(x + 3, y + dem + 4); cout << m.danhSach[i]->ISBN;
		GoToXY(x + 15, y + dem + 4); cout << m.danhSach[i]->tenSach;
		GoToXY(x + 43, y + dem + 4); cout << m.danhSach[i]->soTrang;
		GoToXY(x + 53, y + dem + 4); cout << m.danhSach[i]->tacGia;
		GoToXY(x + 80, y + dem + 4); cout << m.danhSach[i]->namXuatBan;
		GoToXY(x + 92, y + dem + 4); cout << m.danhSach[i]->theLoai;
	}
	GoToXY(x + 47, y + 20); cout << "Trang " << j << "/" << page;
}
void BangThemDauSach(int x, int y) // Bang de them dau sach
{
	int i;
	for(i = 0; i < 60; i++) {GoToXY(x + i, y); cout << (char)196;}
	for(i = 0; i < 60; i++) {GoToXY(x + i, y + 8); cout << (char)196;}
	for(i = 0; i < 8; i++) {GoToXY(x, y + i); cout << (char)179;}
	for(i = 0; i < 8; i++) {GoToXY(x + 60, y + i); cout << (char)179;}
	GoToXY(x, y); cout << (char)218;
	GoToXY(x + 60, y); cout << (char)191;
	GoToXY(x, y + 8); cout << (char)192;
	GoToXY(x + 60, y + 8); cout << (char)217;
}
boolean CheckISBN(DSDauSach dsDauSach, string x, int vt) // Check ma ISBN xem co trung k
{
	for(int i = 0; i < dsDauSach.n; i++)
	{
		if(dsDauSach.danhSach[i]->ISBN.compare(x) == 0 && i != vt) return false;
	}
	return true;
}
void ChuanHoaDuLieuNhapVao(DauSach &a){
	ChuanHoaString(a.tenSach);
	ChuanHoaString(a.tacGia);
	ChuanHoaString(a.theLoai);
}

void TaoDMSChoDauSach(DSDauSach &dsDauSach, int l) {
	DMSPTR r;
	DMSPTR Last;
	for(int i = 1; i <= dsDauSach.danhSach[l]->soLuong; i++) {
		r = new NodeDMS;
		ostringstream convert; //Chuyen tu so sang chu
		convert << i;      
    	string w = convert.str();
    	r->infor.maSach = dsDauSach.danhSach[l]->ISBN + '_' + w;
    	r->infor.trangThai = choMuonDuoc;
    	if(dsDauSach.danhSach[l]->DMS == NULL) dsDauSach.danhSach[l]->DMS = r;
    	else Last->next = r;
    	Last = r;
    	Last->next = NULL;
	}
}
void ChuanHoaDuLieuNhapVao(DauSach *&a){
	ChuanHoaString(a->tenSach);
	ChuanHoaString(a->tacGia);
	ChuanHoaString(a->theLoai);
}
void ThemVaoCuoiDSDS(DSDauSach &dsDauSach, DauSach temp) {
	dsDauSach.danhSach[dsDauSach.n] = new DauSach;
	dsDauSach.danhSach[dsDauSach.n]->ISBN = temp.ISBN;
	dsDauSach.danhSach[dsDauSach.n]->tenSach = temp.tenSach;
	dsDauSach.danhSach[dsDauSach.n]->soTrang = temp.soTrang;
	dsDauSach.danhSach[dsDauSach.n]->tacGia = temp.tacGia;
	dsDauSach.danhSach[dsDauSach.n]->namXuatBan = temp.namXuatBan;
	dsDauSach.danhSach[dsDauSach.n]->theLoai = temp.theLoai;
	dsDauSach.danhSach[dsDauSach.n]->soLuong = temp.soLuong;
	dsDauSach.danhSach[dsDauSach.n]->luotMuon = 0;
	nDMS += dsDauSach.danhSach[dsDauSach.n]->soLuong;
	TaoDMSChoDauSach(dsDauSach, dsDauSach.n);				
	dsDauSach.n++;
}

void ThemDauSach(DSDauSach &dsDauSach, int x, int y) //Them 1 dau sach
{
	modifyCursor(1, true);
	int vt = 0, ISBN = 0, tensach = 0, sotrang = 0, tacgia = 0, namxb = 0, theloai = 0, soluong = 0;
	char c;
	DauSach temp; //Xai tam de them vao mang sau khi nhap xong
	temp.soTrang = 0;
	temp.namXuatBan = 0;
	temp.soLuong = 0;
	Normal();
	GoToXY(103, 12); cout << "THEM DAU SACH";
	BangThemDauSach(80, 14);
	string MenuDS[7] = {"ISBN:         ",
						"Ten Sach:     ",
						"So Trang:     ",
						"Tac Gia:      ",
						"Nam Xuat Ban: ",
						"The Loai:     ",
						"So Luong Sach:"};
	for(int i = 0; i < 7; i++) { GoToXY(x + 1, y + 1 + i); cout << MenuDS[i]; }								
	GoToXY(x + 16, y + 1);				
	do
	{
		c = GetKey();
		switch (c)
		{
			case Up: if(vt + 1 > 1) //Len dong tren
			{
				vt--;
				if(vt == 0) GoToXY(x + 16 + ISBN, y + 1 + vt);
				else if(vt == 1) GoToXY(x + 16 + tensach, y + 1 + vt);
				else if(vt == 2) GoToXY(x + 16 + sotrang, y + 1 + vt);
				else if(vt == 3) GoToXY(x + 16 + tacgia, y + 1 + vt);
				else if(vt == 4) GoToXY(x + 16 + namxb, y + 1 + vt);
				else if(vt == 5) GoToXY(x + 16 + theloai, y + 1 + vt);
				else if(vt == 6) GoToXY(x + 16 + soluong, y + 1 + vt);
			} break;
			case Enter: if(vt + 1 < 7) //Xuong dong
			{
				vt++;
				if(vt == 0) GoToXY(x + 16 + ISBN, y + 1 + vt);
				else if(vt == 1) GoToXY(x + 16 + tensach, y + 1 + vt);
				else if(vt == 2) GoToXY(x + 16 + sotrang, y + 1 + vt);
				else if(vt == 3) GoToXY(x + 16 + tacgia, y + 1 + vt);
				else if(vt == 4) GoToXY(x + 16 + namxb, y + 1 + vt);
				else if(vt == 5) GoToXY(x + 16 + theloai, y + 1 + vt);
				else if(vt == 6) GoToXY(x + 16 + soluong, y + 1 + vt);
			} break;
			case Down: if(vt + 1 < 7) //Xuong dong
			{
				vt++;
				if(vt == 0) GoToXY(x + 16 + ISBN, y + 1 + vt);
				else if(vt == 1) GoToXY(x + 16 + tensach, y + 1 + vt);
				else if(vt == 2) GoToXY(x + 16 + sotrang, y + 1 + vt);
				else if(vt == 3) GoToXY(x + 16 + tacgia, y + 1 + vt);
				else if(vt == 4) GoToXY(x + 16 + namxb, y + 1 + vt);
				else if(vt == 5) GoToXY(x + 16 + theloai, y + 1 + vt);
				else if(vt == 6) GoToXY(x + 16 + soluong, y + 1 + vt);
			} break;
			case F2: //Luu du lieu
			{
				ChuanHoaDuLieuNhapVao(temp);
				if(temp.ISBN.compare("") == 0)
				{
					GoToXY(x + 15, y + 12); cout << "                                 ";
					GoToXY(x + 15, y + 12); cout << "Khong duoc de trong ISBN";
					GoToXY(x + 15, y + 13); cout << "                                 ";
				}
				else if(CheckISBN(dsDauSach, temp.ISBN, -5) == false)
				{
					GoToXY(x + 15, y + 12); cout << "                                 ";
					GoToXY(x + 15, y + 12); cout << "Ma ISBN bi trung";
					GoToXY(x + 15, y + 13); cout << "                                 ";
				}
				else if(temp.tenSach.compare("") == 0)
				{
					GoToXY(x + 15, y + 12); cout << "                                 ";
					GoToXY(x + 15, y + 12); cout << "Khong duoc de trong Ten Sach";
					GoToXY(x + 15, y + 13); cout << "                                 ";
				}
				else if(temp.soTrang == 0)
				{
					GoToXY(x + 15, y + 12); cout << "                                 ";
					GoToXY(x + 15, y + 12); cout << "Khong duoc de trong So Trang";
					GoToXY(x + 15, y + 13); cout << "                                 ";
				}
				else if(temp.tacGia.compare("") == 0)
				{ 
					GoToXY(x + 15, y + 12); cout << "                                 ";
					GoToXY(x + 15, y + 12); cout << "Khong duoc de trong Tac Gia";
					GoToXY(x + 15, y + 13); cout << "                                 ";
				}
				else if(temp.namXuatBan == 0)
				{
					GoToXY(x + 15, y + 12); cout << "                                  ";
					GoToXY(x + 15, y + 12); cout << "Khong duoc de trong Nam Xuat Ban";
					GoToXY(x + 15, y + 13); cout << "                                 ";
				}
				else if(temp.namXuatBan > 2020)
				{
					GoToXY(x + 15, y + 12); cout << "                                  ";
					GoToXY(x + 15, y + 12); cout << "Nam Xuat Ban khong hop le";
					GoToXY(x + 15, y + 13); cout << "                                 ";
				}
				else if(temp.theLoai.compare("") == 0)
				{
					GoToXY(x + 15, y + 12); cout << "                                 ";
					GoToXY(x + 15, y + 12); cout << "Khong duoc de trong The Loai";
					GoToXY(x + 15, y + 13); cout << "                                 ";
				}
				else if(temp.soLuong == 0)
				{
					GoToXY(x + 15, y + 12); cout << "                                 ";
					GoToXY(x + 15, y + 12); cout << "Khong duoc de trong So Luong";
					GoToXY(x + 15, y + 13); cout << "                                 ";
				}
				else
				{
					ThemVaoCuoiDSDS(dsDauSach, temp);
					SaveDauSach(dsDauSach);
					SaveDanhMucSach(dsDauSach);
					GoToXY(x + 15, y + 12); cout << "                                 ";
					GoToXY(x + 15, y + 12); cout << "Du lieu da duoc luu lai";
					Sleep(2500);
					GoToXY(x + 15, y + 12); cout << "                                 ";
					return;
				}
				vt = 7;
				break;
			}
			case ESC: //Thoat ra
			{
				ChuanHoaDuLieuNhapVao(temp);
				if(temp.ISBN.compare("") == 0 || temp.tenSach.compare("") == 0 || temp.soTrang == 0 || temp.tacGia.compare("") == 0 || temp.namXuatBan == 0 || temp.namXuatBan > 2020 || temp.theLoai.compare("") == 0 || temp.soLuong == 0 || CheckISBN(dsDauSach, temp.ISBN, -5) == false)
				{
					GoToXY(x + 15, y + 12); cout << "                                 ";
					GoToXY(x + 15, y + 12); cout << "Du lieu nhap chua dung";
					GoToXY(x + 15, y + 13); cout << "                                 ";
					GoToXY(x + 15, y + 13); cout << "Nhan ESC neu ban van muon thoat";
					char kt = GetKey();
					if(kt == ESC) 
					{
						GoToXY(x + 15, y + 12); cout << "                                ";
						GoToXY(x + 15, y + 13); cout << "                                ";
						return;
					}
				}
				else
				{
					GoToXY(x + 15, y + 12); cout << "                                ";
					GoToXY(x + 15, y + 12); cout << "Ban co muon luu du lieu?";
					GoToXY(x + 15, y + 13); cout << "                                ";
					GoToXY(x + 15, y + 13); cout << "LUU (Y)\t KHONG LUU (N)";
					do
					{
						char kt = GetKey();
						if(kt == 'Y' || kt == 'y') 
						{
							ThemVaoCuoiDSDS(dsDauSach, temp);
							SaveDauSach(dsDauSach);
							SaveDanhMucSach(dsDauSach);
							GoToXY(x + 15, y + 12); cout << "                                 ";
							GoToXY(x + 15, y + 12); cout << "Du lieu da tu dong luu lai";
							GoToXY(x + 15, y + 13); cout << "                                 ";
							Sleep(2500);
							GoToXY(x + 15, y + 12); cout << "                                 ";
							return;
						}
						else if(kt == 'N' || kt == 'n') { return; }
					} while(1);
				}
				vt = 7;
				break;
			}
			default: switch(vt)
			{
				case 0: //Vi tri con tro o phan ISBN
				{
					if(c == Backspace)
					{
						if(ISBN > 0)
						{
							temp.ISBN = temp.ISBN.substr(0, --ISBN);
							GoToXY(x + 16 + ISBN, y + 1 + vt); cout << " ";
							GoToXY(x + 16 + ISBN, y + 1 + vt);
						}		
					}
					else if(c >= 48 && c <= 57) //Chi lay so
					{
						if(temp.ISBN.length() < 5)
						{
							temp.ISBN += c;
							ISBN++;
							cout << c;
						}
						else
						{
							GoToXY(x + 15, y + 12); cout << "Ma ISBN chi toi da 5 ky tu!";
							GoToXY(x + 16 + ISBN, y + 1 + vt);
						}
					}
				} break;
				case 1: //Vi tri con tro o phan Ten Sach
				{
					if(c == Backspace)
					{
						if(tensach > 0)
						{
							temp.tenSach = temp.tenSach.substr(0, --tensach);
							GoToXY(x + 16 + tensach, y + 1 + vt); cout << " ";
							GoToXY(x + 16 + tensach, y + 1 + vt);
						}		
					}
					else if(c >= 32 && c <= 126) //bao gom chu in hoa, in thuong, ky tu dac biet, dau cau, so
					{
						temp.tenSach += c;
						tensach++;
						cout << c;
					}
				} break;
				case 2: //Vi tri con tro o phan So Trang
				{
					if(c == Backspace)
					{
						if(sotrang > 0)
						{
							temp.soTrang = temp.soTrang/ 10;
							sotrang--;
							GoToXY(x + 16 + sotrang, y + 1 + vt); cout << " ";
							GoToXY(x + 16 + sotrang, y + 1 + vt);
						}		
					}
					else if(c >= 48 && c <= 57) //chi lay so
					{
						int k = temp.soTrang;
						switch(c)
						{
							case '0': temp.soTrang = temp.soTrang * 10 + 0; break;
							case '1': temp.soTrang = temp.soTrang * 10 + 1; break;
							case '2': temp.soTrang = temp.soTrang * 10 + 2; break;
							case '3': temp.soTrang = temp.soTrang * 10 + 3; break;
							case '4': temp.soTrang = temp.soTrang * 10 + 4; break;
							case '5': temp.soTrang = temp.soTrang * 10 + 5; break;
							case '6': temp.soTrang = temp.soTrang * 10 + 6; break;
							case '7': temp.soTrang = temp.soTrang * 10 + 7; break;
							case '8': temp.soTrang = temp.soTrang * 10 + 8; break;
							case '9': temp.soTrang = temp.soTrang * 10 + 9; break;
						}
						sotrang++;
						cout << c;
					}
				} break;
				case 3: //Vi tri con tro o phan Tac Gia
				{
					if(c == Backspace)
					{
						if(tacgia > 0)
						{
							temp.tacGia = temp.tacGia.substr(0, --tacgia);
							GoToXY(x + 16 + tacgia, y + 1 + vt); cout << " ";
							GoToXY(x + 16 + tacgia, y + 1 + vt);
						}		
					}
					else if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32)
					{
						temp.tacGia += c;
						tacgia++;
						cout << c;
					}	
				} break;
				case 4: //Vi tri con tro o phan Nam Xuat Ban
				{
					if(c == Backspace)
					{
						if(namxb > 0)
						{
							namxb--;
							temp.namXuatBan = temp.namXuatBan/ 10;
							GoToXY(x + 16 + namxb, y + 1 + vt); cout << " ";
							GoToXY(x + 16 + namxb, y + 1 + vt);
						}		
					}
					else if(c >= 48 && c <= 57) //Chi lay so
					{
						switch(c)
						{
							case '0': temp.namXuatBan = temp.namXuatBan * 10 + 0; break;
							case '1': temp.namXuatBan = temp.namXuatBan * 10 + 1; break;
							case '2': temp.namXuatBan = temp.namXuatBan * 10 + 2; break;
							case '3': temp.namXuatBan = temp.namXuatBan * 10 + 3; break;
							case '4': temp.namXuatBan = temp.namXuatBan * 10 + 4; break;
							case '5': temp.namXuatBan = temp.namXuatBan * 10 + 5; break;
							case '6': temp.namXuatBan = temp.namXuatBan * 10 + 6; break;
							case '7': temp.namXuatBan = temp.namXuatBan * 10 + 7; break;
							case '8': temp.namXuatBan = temp.namXuatBan * 10 + 8; break;
							case '9': temp.namXuatBan = temp.namXuatBan * 10 + 9; break;
						}
						namxb++;
						cout << c;
					}	
				} break;
				case 5: //Vi tri con tro o phan The Loai
				{
					if(c == Backspace)
					{
						if(theloai > 0)
						{
							temp.theLoai = temp.theLoai.substr(0, --theloai);
							GoToXY(x + 16 + theloai, y + 1 + vt); cout << " ";
							GoToXY(x + 16 + theloai, y + 1 + vt);
						}		
					}
					else if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32) //Chu hoa, chu thuong, space
					{
						temp.theLoai += c;
						theloai++;
						cout << c;
					}	
				} break;
				case 6: //Vi tri con tro o phan So Luong
				{
					if(c == Backspace)
					{
						if(soluong > 0)
						{
							soluong--;
							temp.soLuong = temp.soLuong/ 10;
							GoToXY(x + 16 + soluong, y + 1 + vt); cout << " ";
							GoToXY(x + 16 + soluong, y + 1 + vt);
						}		
					}
					else if(c >= 48 && c <= 57) //Chi lay so
					{
						switch(c)
						{
							case '0': temp.soLuong = temp.soLuong * 10 + 0; break;
							case '1': temp.soLuong = temp.soLuong * 10 + 1; break;
							case '2': temp.soLuong = temp.soLuong * 10 + 2; break;
							case '3': temp.soLuong = temp.soLuong * 10 + 3; break;
							case '4': temp.soLuong = temp.soLuong * 10 + 4; break;
							case '5': temp.soLuong = temp.soLuong * 10 + 5; break;
							case '6': temp.soLuong = temp.soLuong * 10 + 6; break;
							case '7': temp.soLuong = temp.soLuong * 10 + 7; break;
							case '8': temp.soLuong = temp.soLuong * 10 + 8; break;
							case '9': temp.soLuong = temp.soLuong * 10 + 9; break;
						}
						soluong++;
						cout << c;
					}	
				} break;
			}
		}
	} while(1);
}
void ThemSoLuongTrongDMS(DauSach *&b, int a) {
	DMSPTR m = b->DMS;
	int stt = 1;
	while(m->next != NULL) {
		m = m->next;
		stt++;
	}
	DMSPTR r;
	for(int i = 1; i <= a; i++) //Danh so va trang thai cac cuon sach duoc them sau
	{
		r = new NodeDMS;
		ostringstream convert; //Chuyen tu so sang chu
		convert << i + stt;      
    	string w = convert.str();
    	r->infor.maSach = b->ISBN + '_' + w;
    	r->infor.trangThai = choMuonDuoc;
    	m->next = r;
    	m = r;
	}
	m->next = NULL;
}
	
void CapNhatThongTin(DauSach &nhan, DauSach *cho) {
	nhan.ISBN = cho->ISBN;
	nhan.tenSach = cho->tenSach;
	nhan.soTrang = cho->soTrang;
	nhan.tacGia = cho->tacGia;
	nhan.namXuatBan = cho->namXuatBan;
	nhan.theLoai = cho->theLoai;
	nhan.luotMuon = cho->luotMuon;
	nhan.soLuong = cho->soLuong;
}
void CapNhatThongTin(DauSach *&nhan, DauSach cho) {
	nhan->ISBN = cho.ISBN;
	nhan->tenSach = cho.tenSach;
	nhan->soTrang = cho.soTrang;
	nhan->tacGia = cho.tacGia;
	nhan->namXuatBan = cho.namXuatBan;
	nhan->theLoai = cho.theLoai;
	nhan->luotMuon = cho.luotMuon;
	nhan->soLuong = cho.soLuong;
}


void CapNhatThongTin2(DSDauSach &dsDauSach, DauSach temp, int l, int soLuongThem) {
		dsDauSach.danhSach[l]->ISBN = temp.ISBN;
		dsDauSach.danhSach[l]->tenSach = temp.tenSach;
		dsDauSach.danhSach[l]->soTrang = temp.soTrang;
		dsDauSach.danhSach[l]->tacGia = temp.tacGia;
		dsDauSach.danhSach[l]->namXuatBan = temp.namXuatBan;
		dsDauSach.danhSach[l]->theLoai = temp.theLoai;
		dsDauSach.danhSach[l]->luotMuon = temp.luotMuon;
		ThemSoLuongTrongDMS(dsDauSach.danhSach[l], soLuongThem);
		dsDauSach.danhSach[l]->soLuong = temp.soLuong;
		SaveDanhMucSach(dsDauSach);
}

void HieuChinhDS(DSDauSach &dsDauSach, int x, int y, int l) // Hieu chinh 1 dau sach
{
	modifyCursor(1, true);
	int ISBN, tensach, tacgia, theloai;
	int namxb = 0, sotrang = 0, soluong = 0, vt = 0;
	char c;
	DauSach temp; //Xai tam de them vao mang sau khi nhap xong
	
	CapNhatThongTin(temp, dsDauSach.danhSach[l]);
	tensach = temp.tenSach.length();
	tacgia = temp.tacGia.length();
	theloai = temp.theLoai.length();
	int ok = temp.soTrang;
	
	while(ok > 0) //LAY SO CHU SO
	{
		ok = ok / 10;
		sotrang++;
	}
	ok = temp.namXuatBan;
	
	while(ok > 0)
	{
		ok = ok / 10;
		namxb++;
	}
	ok = temp.soLuong;
	while(ok > 0)
	{
		ok = ok / 10;
		soluong++;
	}
	Normal();
	GoToXY(100, 12); cout << "HIEU CHINH DAU SACH";
	BangThemDauSach(80, 14);
	string MenuDS[7] = {"ISBN:         ",
						"Ten Sach:     ",
						"So Trang:     ",
						"Tac Gia:      ",
						"Nam Xuat Ban: ",
						"The Loai:     ",
						"So Luong Sach:"};
	for(int i = 0; i < 7; i++) { GoToXY(x + 1, y + 1 + i); cout << MenuDS[i]; }
	
	GoToXY(x + 16, y + 1); cout << temp.ISBN;							
	GoToXY(x + 16, y + 2); cout << temp.tenSach;							
	GoToXY(x + 16, y + 3); cout << temp.soTrang;							
	GoToXY(x + 16, y + 4); cout << temp.tacGia;							
	GoToXY(x + 16, y + 5); cout << temp.namXuatBan;							
	GoToXY(x + 16, y + 6); cout << temp.theLoai;							
	GoToXY(x + 16, y + 7); cout << temp.soLuong;		
	GoToXY(x + 16 + tensach, y + 2);				
	do
	{
		c = GetKey();
		switch (c)
		{	
			case Up: if(vt + 1 > 1) //Len dong tren
			{
				vt--;
				if(vt == 0) GoToXY(x + 16 + tensach, y + 2 + vt);
				else if(vt == 1) GoToXY(x + 16 + sotrang, y + 2 + vt);
				else if(vt == 2) GoToXY(x + 16 + tacgia, y + 2 + vt);
				else if(vt == 3) GoToXY(x + 16 + namxb, y + 2 + vt);
				else if(vt == 4) GoToXY(x + 16 + theloai, y + 2 + vt);
				else if(vt == 5) GoToXY(x + 16 + soluong, y + 2 + vt);
			} break;
			case Enter: if(vt + 1 < 6) //Xuong dong
			{
				vt++;
				if(vt == 0) GoToXY(x + 16 + tensach, y + 2 + vt);
				else if(vt == 1) GoToXY(x + 16 + sotrang, y + 2 + vt);
				else if(vt == 2) GoToXY(x + 16 + tacgia, y + 2 + vt);
				else if(vt == 3) GoToXY(x + 16 + namxb, y + 2 + vt);
				else if(vt == 4) GoToXY(x + 16 + theloai, y + 2 + vt);
				else if(vt == 5) GoToXY(x + 16 + soluong, y + 2 + vt);
			} break;
			case Down: if(vt + 1 < 6) //Xuong dong
			{
				vt++;
				if(vt == 0) GoToXY(x + 16 + tensach, y + 2 + vt);
				else if(vt == 1) GoToXY(x + 16 + sotrang, y + 2 + vt);
				else if(vt == 2) GoToXY(x + 16 + tacgia, y + 2 + vt);
				else if(vt == 3) GoToXY(x + 16 + namxb, y + 2 + vt);
				else if(vt == 4) GoToXY(x + 16 + theloai, y + 2 + vt);
				else if(vt == 5) GoToXY(x + 16 + soluong, y + 2 + vt);
			} break;
			case F2: //Save
			{
				ChuanHoaDuLieuNhapVao(temp);
				if(temp.tenSach.compare("") == 0)
				{
					GoToXY(x + 15, y + 12); cout << "                                  ";
					GoToXY(x + 15, y + 12); cout << "Khong duoc de trong Ten Sach";
					GoToXY(x + 15, y + 13); cout << "                                  ";
				}
				else if(temp.soTrang == 0)
				{
					GoToXY(x + 15, y + 12); cout << "                                  ";
					GoToXY(x + 15, y + 12); cout << "Khong duoc de trong So Trang";
					GoToXY(x + 15, y + 13); cout << "                                  ";
				}
				else if(temp.tacGia.compare("") == 0)
				{ 
					GoToXY(x + 15, y + 12); cout << "                                  ";
					GoToXY(x + 15, y + 12); cout << "Khong duoc de trong Tac Gia";
					GoToXY(x + 15, y + 13); cout << "                                  ";
				}
				else if(temp.namXuatBan == 0)
				{
					GoToXY(x + 15, y + 12); cout << "                                   ";
					GoToXY(x + 15, y + 12); cout << "Khong duoc de trong Nam Xuat Ban";
					GoToXY(x + 15, y + 13); cout << "                                   ";
				}
				else if(temp.namXuatBan > 2020)
				{
					GoToXY(x + 15, y + 12); cout << "                                   ";
					GoToXY(x + 15, y + 12); cout << "Nam Xuat Ban khong hop le";
					GoToXY(x + 15, y + 13); cout << "                                   ";
				}
				else if(temp.theLoai.compare("") == 0)
				{
					GoToXY(x + 15, y + 12); cout << "                                  ";
					GoToXY(x + 15, y + 12); cout << "Khong duoc de trong The Loai";
					GoToXY(x + 15, y + 13); cout << "                                  ";
				}
				else if(temp.soLuong < dsDauSach.danhSach[l]->soLuong)
				{
					GoToXY(x + 15, y + 12); cout << "                                  ";
					GoToXY(x + 15, y + 12); cout << "So luong sach phai lon hon ban dau";
					GoToXY(x + 15, y + 13); cout << "                                  ";
				}
				else
				{
					int soLuongThem = temp.soLuong - dsDauSach.danhSach[l]->soLuong;
					if(soLuongThem == 0)  CapNhatThongTin(dsDauSach.danhSach[l], temp);
					else {
						CapNhatThongTin2(dsDauSach, temp, l, soLuongThem);
						nDMS+= soLuongThem;	
					} 
					SaveDauSach(dsDauSach);
					GoToXY(x + 15, y + 12); cout << "                                   ";
					GoToXY(x + 15, y + 12); cout << "Du lieu da duoc luu lai";
					Sleep(2500);
					GoToXY(x + 15, y + 12); cout << "                                   ";
					return;
				}
				vt = 6;
				break;
			}
			
			case ESC: //Thoat ra
			{
				ChuanHoaDuLieuNhapVao(temp);
					if(temp.soTrang == 0 || temp.tacGia.compare("") == 0 || temp.namXuatBan == 0 || temp.namXuatBan > 2020 || temp.theLoai.compare("") == 0 || temp.soLuong == 0 || temp.soLuong < dsDauSach.danhSach[l]->soLuong)
				{
					GoToXY(x + 15, y + 12); cout << "                                    ";
					GoToXY(x + 15, y + 12); cout << "Du lieu nhap chua dung";
					GoToXY(x + 15, y + 13); cout << "                                    ";
					GoToXY(x + 15, y + 13); cout << "Nhan ESC neu ban van muon thoat";
					char kt = GetKey();
					if(kt == ESC) 
					{
						GoToXY(x + 15, y + 12); cout << "                                ";
						GoToXY(x + 15, y + 13); cout << "                                ";
						return;
					}
				}
				else
				{
					GoToXY(x + 15, y + 12); cout << "                                   ";
					GoToXY(x + 15, y + 12); cout << "Ban co muon luu du lieu?";
					GoToXY(x + 15, y + 13); cout << "                                   ";
					GoToXY(x + 15, y + 13); cout << "LUU (Y)\t KHONG LUU (N)";
					do
					{
						char kt = GetKey();
						if(kt == 'Y' || kt == 'y') 
						{	
							int soLuongThem = temp.soLuong - dsDauSach.danhSach[l]->soLuong;
							if(soLuongThem == 0)  CapNhatThongTin(dsDauSach.danhSach[l], temp);
							else {
								CapNhatThongTin2(dsDauSach, temp, l, soLuongThem);
								nDMS+= soLuongThem;
								SaveDauSach(dsDauSach);	
							} 
							GoToXY(x + 15, y + 12); cout << "                                 ";
							GoToXY(x + 15, y + 12); cout << "Du lieu da tu dong luu lai";
							GoToXY(x + 15, y + 13); cout << "                                 ";
							Sleep(2500);
							GoToXY(x + 15, y + 12); cout << "                                 ";
							return;
						}
						else if(kt == 'N' || kt == 'n') { return; }
					} while(1);
				}
				vt = 6;
				break;
			}
		default: switch(vt)
			{
				case 0: //Vi tri con tro o phan Ten Sach
				{
					if(c == Backspace)
					{
						if(tensach > 0)
						{
							temp.tenSach = temp.tenSach.substr(0, --tensach);
							GoToXY(x + 16 + tensach, y + 2 + vt); cout << " ";
							GoToXY(x + 16 + tensach, y + 2 + vt);
						}		
					}
					else if(c >= 32 && c <= 126) //bao gom chu in hoa, in thuong, ky tu dac biet, dau cau, so
					{
						temp.tenSach += c;
						tensach++;
						cout << c;
					}
				} break;
				case 1: //Vi tri con tro o phan So Trang
				{
					if(c == Backspace)
					{
						if(sotrang > 0)
						{
							temp.soTrang = temp.soTrang/ 10;
							sotrang--;
							GoToXY(x + 16 + sotrang, y + 2 + vt); cout << " ";
							GoToXY(x + 16 + sotrang, y + 2 + vt);
						}		
					}
					else if(c >= 48 && c <= 57) //chi gom so
					{
						int k = temp.soTrang;
						switch(c)
						{
							case '0': temp.soTrang = temp.soTrang * 10 + 0; break;
							case '1': temp.soTrang = temp.soTrang * 10 + 1; break;
							case '2': temp.soTrang = temp.soTrang * 10 + 2; break;
							case '3': temp.soTrang = temp.soTrang * 10 + 3; break;
							case '4': temp.soTrang = temp.soTrang * 10 + 4; break;
							case '5': temp.soTrang = temp.soTrang * 10 + 5; break;
							case '6': temp.soTrang = temp.soTrang * 10 + 6; break;
							case '7': temp.soTrang = temp.soTrang * 10 + 7; break;
							case '8': temp.soTrang = temp.soTrang * 10 + 8; break;
							case '9': temp.soTrang = temp.soTrang * 10 + 9; break;
						}
						sotrang++;
						cout << c;
					}
				} break;
				case 2: //Vi tri con tro o phan Tac Gia
				{
					if(c == Backspace)
					{
						if(tacgia > 0)
						{
							temp.tacGia = temp.tacGia.substr(0, --tacgia);
							GoToXY(x + 16 + tacgia, y + 2 + vt); cout << " ";
							GoToXY(x + 16 + tacgia, y + 2 + vt);
						}		
					}
					else if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32) //Chu thuong, chu hoa, space
					{
						temp.tacGia += c;
						tacgia++;
						cout << c;
					}	
				} break;
				case 3: //Vi tri con tro o phan Nam Xuat Ban
				{
					if(c == Backspace)
					{
						if(namxb > 0)
						{
							namxb--;
							temp.namXuatBan = temp.namXuatBan/ 10;
							GoToXY(x + 16 + namxb, y + 2 + vt); cout << " ";
							GoToXY(x + 16 + namxb, y + 2 + vt);
						}		
					}
					else if(c >= 48 && c <= 57) //chi lay so
					{
						switch(c)
						{
							case '0': temp.namXuatBan = temp.namXuatBan * 10 + 0; break;
							case '1': temp.namXuatBan = temp.namXuatBan * 10 + 1; break;
							case '2': temp.namXuatBan = temp.namXuatBan * 10 + 2; break;
							case '3': temp.namXuatBan = temp.namXuatBan * 10 + 3; break;
							case '4': temp.namXuatBan = temp.namXuatBan * 10 + 4; break;
							case '5': temp.namXuatBan = temp.namXuatBan * 10 + 5; break;
							case '6': temp.namXuatBan = temp.namXuatBan * 10 + 6; break;
							case '7': temp.namXuatBan = temp.namXuatBan * 10 + 7; break;
							case '8': temp.namXuatBan = temp.namXuatBan * 10 + 8; break;
							case '9': temp.namXuatBan = temp.namXuatBan * 10 + 9; break;
						}
						namxb++;
						cout << c;
					}	
				} break;
				case 4: //Vi tri con tro o phan The Loai
				{
					if(c == Backspace)
					{
						if(theloai > 0)
						{
							temp.theLoai = temp.theLoai.substr(0, --theloai);
							GoToXY(x + 16 + theloai, y + 2 + vt); cout << " ";
							GoToXY(x + 16 + theloai, y + 2 + vt);
						}		
					}
					else if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32) //Chu thuong, chu hoa, space
					{
						temp.theLoai += c;
						theloai++;
						cout << c;
					}	
				} break;
				case 5: //Vi tri con tro o phan So Luong
				{
					if(c == Backspace)
					{
						if(soluong > 0)
						{
							soluong--;
							temp.soLuong = temp.soLuong/ 10;
							GoToXY(x + 16 + soluong, y + 2 + vt); cout << " ";
							GoToXY(x + 16 + soluong, y + 2 + vt);
						}		
					}
					else if(c >= 48 && c <= 57) //Chi lay so
					{
						switch(c)
						{
							case '0': temp.soLuong = temp.soLuong * 10 + 0; break;
							case '1': temp.soLuong = temp.soLuong * 10 + 1; break;
							case '2': temp.soLuong = temp.soLuong * 10 + 2; break;
							case '3': temp.soLuong = temp.soLuong * 10 + 3; break;
							case '4': temp.soLuong = temp.soLuong * 10 + 4; break;
							case '5': temp.soLuong = temp.soLuong * 10 + 5; break;
							case '6': temp.soLuong = temp.soLuong * 10 + 6; break;
							case '7': temp.soLuong = temp.soLuong * 10 + 7; break;
							case '8': temp.soLuong = temp.soLuong * 10 + 8; break;
							case '9': temp.soLuong = temp.soLuong * 10 + 9; break;
						}
						soluong++;
						cout << c;
					}	
				} break;
			}
		}
	} while(1);
}
void XoaDMS(DauSach *&m) {
	DMSPTR r = m->DMS;
	DMSPTR k;
	while(r != NULL) {
		k = r->next;
		delete r;
		r = k;
	}
}
void Xoa1PTTrongMang(DSDauSach &dsDauSach, int l){
	delete(dsDauSach.danhSach[l]);
	for(int i = l; i < dsDauSach.n; i++)
		dsDauSach.danhSach[i] = dsDauSach.danhSach[i + 1];
	dsDauSach.n--;
}
void XoaDauSach(DSDauSach &dsDauSach, int x, int y, int l) //Xoa dau sach
{
	Normal();
	if(dsDauSach.danhSach[l]->luotMuon > 0)
	{
		GoToXY(x, y); cout << "Ban khong the xoa dau sach nay vi co nguoi van dang muon";
		Sleep(2500);
	}
	else
	{
		GoToXY(x, y); cout << "Ban co muon xoa dau sach nay!";
		GoToXY(x, y + 1); cout << "XOA (Y)\t KHONG XOA (N)";
		do
		{
			char c = GetKey();
			if(c == 'Y' || c == 'y')
			{
				XoaDMS(dsDauSach.danhSach[l]);
				nDMS -= dsDauSach.danhSach[l]->soLuong;
				Xoa1PTTrongMang(dsDauSach, l);
				SaveDauSach(dsDauSach);
				SaveDanhMucSach(dsDauSach);
				GoToXY(x, y); cout << "                                             ";
				GoToXY(x, y + 1); cout << "                                           ";
				GoToXY(x, y); cout << "Da xoa thanh cong dau sach nay!";
				Sleep(2500);
				return;
			}
			else if(c == 'N' || c == 'n') { return; }
		} while(1);
	}
}
void HieuChinhDauSach(DSDauSach &dsDauSach, int x, int y) // Giai quyet van de them/ hieu chinh dau sach
{
	int sl, i = 1, muiten = 0;
	double k = 0;
	k = dsDauSach.n;
	k = ceil(k/ bang);
	GoToXY(100, 11); cout << "DANH SACH CAC DAU SACH";
	BangDauSach(60, 12);
	InDauSach(dsDauSach, 60, 12, i, k);
	GoToXY(57, 16); MuiTen();
	do
	{
		char kytu = GetKey();
		switch (kytu)
		{
			case Up: if(muiten + 1 > 1) //Mui di len
			{
				Normal();
				GoToXY(57, 16 + muiten); cout << "   ";
				muiten--;
				GoToXY(57, 16 + muiten); MuiTen();
			} break;
			case Down: if(muiten + 1 < bang && muiten < (dsDauSach.n - ((i - 1) * bang) - 1)) //Mui ten di xuong
			{
				Normal();
				GoToXY(57, 16 + muiten); cout << "   ";
				muiten++;
				GoToXY(57, 16 + muiten); MuiTen();
			} break;
			case Right: if(i < k) //Qua trang
			{
				XoaBangDauSach(60, 12);
				InDauSach(dsDauSach, 60, 12, ++i, k);
				if(i == k && dsDauSach.n % bang != 0 && muiten > dsDauSach.n % bang - 1)
				{
					GoToXY(57, 16 + muiten); cout << "   ";
					muiten = dsDauSach.n - ((i - 1) * bang) - 1;
					GoToXY(57, 16 + muiten); MuiTen();
				}
			} break;
			case Left: if(i > 1) //Qua trang
			{
				XoaBangDauSach(60, 12);
				InDauSach(dsDauSach, 60, 12, --i, k);
			} break;
			case F3: //Them dau sach
			{
				if(dsDauSach.n == maxDauSach) { GoToXY(x + 40, y + 22); cout << "Khong the them vi dau sach da bi day!"; }
				else
				{
					DeleteScreen();
					ThemDauSach(dsDauSach, x, y);
					DeleteScreen();
					BangDauSach(60, 12);
					k = dsDauSach.n;
					k = ceil(k/ bang);
					InDauSach(dsDauSach, 60, 12, i, k);
					modifyCursor(1, false);
					GoToXY(57, 16 + muiten); MuiTen();
				}
			} break;
			case Enter: //Hieu chinh dau sach
			{
				DeleteScreen();
				HieuChinhDS(dsDauSach, x, y, (i - 1) * bang + muiten);
				DeleteScreen();
				BangDauSach(60, 12);
				XoaBangDauSach(60, 12);
				InDauSach(dsDauSach, 60, 12, i, k);
				GoToXY(57, 16 + muiten); MuiTen();
				modifyCursor(1, false);
			} break;
			case Delete: //Xoa dau sach
			{
				DeleteScreen();
				XoaDauSach(dsDauSach, x, y, (i - 1) * bang + muiten);
				DeleteScreen();
				BangDauSach(60, 12);
				XoaBangDauSach(60, 12);
				InDauSach(dsDauSach, 60, 12, i, k);
				GoToXY(57, 16 + muiten); MuiTen();
				if(dsDauSach.n % bang == 0)
				{
					XoaBangDauSach(60, 12);
					InDauSach(dsDauSach, 60, 12, --i, --k);
				}
				else if(i == k && dsDauSach.n % bang != 0 && muiten > dsDauSach.n % bang - 2)
				{
					GoToXY(57, 16 + muiten); cout << "   ";
					muiten = dsDauSach.n - ((i - 1) * bang) - 1;
					GoToXY(57, 16 + muiten); MuiTen();
				}
				modifyCursor(1, false);
			} break;
			case ESC: return;	
		}
	} while(1);
}
//------------------------------------------------------CAU D-----------------------------------------------------------------
void HuongDanChonTheLoai() //Huong dan chon the loai
{
	DeleteSign();
	GoToXY(x3 + 15, y3); cout << "HUONG DAN";
	GoToXY(x3, y3 + 1); cout << "Di chuyen thanh sang\tMui ten len xuong";
	GoToXY(x3, y3 + 2); cout << "Qua trang\t\tMui ten trai phai";
	GoToXY(x3, y3 + 3); cout << "Chon\t\t\tEnter";
	GoToXY(x3, y3 + 4); cout << "Thoat\t\t\tESC";
}

void MangCacDauSachTheoTheLoai(DSDauSach a, DSDauSach &temp, string theLoaiDuocChon) {
	temp.n = 0;
	for(int i = 0; i < a.n; i++) {
		if(a.danhSach[i]->theLoai.compare(theLoaiDuocChon) == 0) {
			temp.danhSach[temp.n] = new DauSach;
			temp.danhSach[temp.n] = a.danhSach[i];
			temp.n++;
		}
	}
}
void InterChangeSort(DSDauSach &a) {
	for(int i = 0; i < a.n - 1; i++) {
		for(int j = i + 1; j < a.n; j++) {
			if(a.danhSach[i]->tenSach > a.danhSach[j]->tenSach) {
				DauSach *temp = a.danhSach[i];
				a.danhSach[i] = a.danhSach[j];
				a.danhSach[j] = temp;
			}			
		}
	}
}
void InTheoTheLoai(DSDauSach dsDauSach, string s, int x, int y) //In dau sach theo tung the loai
{
	Normal();
	DeleteScreen();
	GoToXY(x, y - 1); cout << "                                Danh Sach Cac Dau Sach The Loai "<< s;
	BangDauSach(x, y);
	DSDauSach m;
	double page; //So trang
	char c;
	MangCacDauSachTheoTheLoai(dsDauSach, m, s);
	InterChangeSort(m);
	int j = 1; //So trang hien tai
	page = m.n;
	page = ceil(page/ bang);
	if(page == 0) page = 1;
	InDauSach(m, x, y, j, page);
	do
	{
		c = GetKey();
		switch (c)
		{
			case Right: if(j < page) //Qua trang
			{
				XoaBangDauSach(x, y);
				InDauSach(m, x, y, ++j, page);
			} break;
			case Left: if(j > 1) //Qua trang
			{
				XoaBangDauSach(x, y);
				InDauSach(m, x, y, --j, page);
			} break;
			case ESC: return;	
		}
	} while(1);
}
void MangCacTheLoaiKhongTrung(string a[], int &j, DSDauSach b) {
	j = 0; 
	int temp;
	a[0] = b.danhSach[0]->theLoai;
 	for(int i = 1; i < b.n; i++) {
		temp = -1;
		for(int k = 0; k <= j; k++) {
			if(b.danhSach[i]->theLoai.compare(a[k]) == 0)	break;
			else temp++;
		}	
		if(temp == j) a[++j] = b.danhSach[i]->theLoai;
	}
}
void ChonTheLoai(DSDauSach dsDauSach, int x, int y) //Chon the loai dau sach de in
{
	modifyCursor(1, false);
	string TheLoai[maxDauSach];
	int i, vt = 0, j;
	MangCacTheLoaiKhongTrung(TheLoai, j, dsDauSach);
	GoToXY(x, y - 2); cout << "CAC THE LOAI";
	for (i = 0; i <= j; i++) { GoToXY(x, y + i); cout << i + 1 << ". " << TheLoai[i]; }
	HighLight1();
	GoToXY(x, y); cout << vt + 1 << ". " << TheLoai[vt];
	char kytu;
	do
	{
		kytu = GetKey();
		switch(kytu)
		{
			case Up: if (vt + 1 > 1) //Len dong tren
				{
					Normal();
					GoToXY(x, y + vt);
					cout << vt + 1 << ". " << TheLoai[vt];
					vt--;
					HighLight1();
					GoToXY(x, y + vt);
					cout << vt + 1 << ". " << TheLoai[vt];
				} break;
			case Down: if (vt + 1 <= j) //Xuong dong
				{
					Normal();
					GoToXY(x, y + vt);
					cout << vt + 1 << ". " << TheLoai[vt];
					vt++;
					HighLight1();
					GoToXY(x, y + vt);
					cout << vt + 1 << ". " << TheLoai[vt];
				} break;
			case Enter: //Chon
				{
					InTheoTheLoai(dsDauSach, TheLoai[vt], 57, 12);
					DeleteScreen();
					GoToXY(x, y - 2); cout << "CAC THE LOAI";
					for (i = 0; i <= j; i++) { GoToXY(x, y + i); cout << i + 1 << ". " << TheLoai[i]; }
					HighLight1();
					GoToXY(x, y + vt); cout << vt + 1 << ". " << TheLoai[vt];
				} break;
			case ESC: return;	
		}
	} while(1);
}
//------------------------------------------------------CAU E-----------------------------------------------------------------
void BangHuongDanTraTenSach() // Bang huong dan search Ten sach
{
	DeleteSign();
	Normal();
	GoToXY(x3 + 15, y3); cout << "HUONG DAN";
	GoToXY(x3, y3 + 1); cout << "Di chuyen mui ten\tMui ten len xuong";
	GoToXY(x3, y3 + 2); cout << "Qua trang\t\tMui ten trai phai";
	GoToXY(x3, y3 + 3); cout << "Chon\t\t\tEnter";
	GoToXY(x3, y3 + 4); cout << "Thoat chuong trinh\tESC";
}
void BangTraTenSach(int x, int y) //Bang de tra ten sach can tim
{
	GoToXY(x + 12, y - 2); cout << "TIM THONG TIN SACH";
	int i;
	for(i = 0; i < 40; i++) {GoToXY(x + i, y); cout << (char)196;}
	for(i = 0; i < 40; i++) {GoToXY(x + i, y + 2); cout << (char)196;}
	for(i = 0; i < 40; i++) {GoToXY(x + i, y + 18); cout << (char)196;}
	for(i = 0; i < 18; i++) {GoToXY(x, y + i); cout << (char)179;}
	for(i = 0; i < 18; i++) {GoToXY(x + 40, y + i); cout << (char)179;}
	GoToXY(x, y); cout << (char)218;
	GoToXY(x + 40, y); cout << (char)191;
	GoToXY(x, y + 2); cout << (char)195;
	GoToXY(x + 40, y + 2); cout << (char)180;
	GoToXY(x, y + 18); cout << (char)192;
	GoToXY(x + 40, y + 18); cout << (char)217;
}
void BangInThongTinSach(int x, int y) //Bang in thong tin sach
{
	int i;
	for(i = 0; i < 128; i++) {GoToXY(x + i, y); cout << (char)196;}
	for(i = 0; i < 128; i++) {GoToXY(x + i, y + 2); cout << (char)196;}
	for(i = 0; i < 128; i++) {GoToXY(x + i, y + bang + 3); cout << (char)196;}
	for(i = 0; i < 18; i++) {GoToXY(x, y + i); cout << (char)179;}
	for(i = 0; i < 18; i++) {GoToXY(x + 10, y + i); cout << (char)179;}
	for(i = 0; i < 18; i++) {GoToXY(x + 38, y + i); cout << (char)179;}
	for(i = 0; i < 18; i++) {GoToXY(x + 66, y + i); cout << (char)179;}
	for(i = 0; i < 18; i++) {GoToXY(x + 75, y + i); cout << (char)179;}
	for(i = 0; i < 18; i++) {GoToXY(x + 100, y + i); cout << (char)179;}
	for(i = 0; i < 18; i++) {GoToXY(x + 112, y + i); cout << (char)179;}
	for(i = 0; i < 18; i++) {GoToXY(x + 128, y + i); cout << (char)179;}
	GoToXY(x + 52, y - 2); cout << "THONG TIN SACH";
	GoToXY(x, y); cout << (char)218;
	GoToXY(x + 10, y); cout << (char)194;
	GoToXY(x + 38, y); cout << (char)194;
	GoToXY(x + 66, y); cout << (char)194;
	GoToXY(x + 75, y); cout << (char)194;
	GoToXY(x + 100, y); cout << (char)194;
	GoToXY(x + 112, y); cout << (char)194;
	GoToXY(x + 128, y); cout << (char)191;
	GoToXY(x, y + 2); cout << (char)195;
	GoToXY(x + 10, y + 2); cout << (char)197;
	GoToXY(x + 38, y + 2); cout << (char)197;
	GoToXY(x + 66, y + 2); cout << (char)197;
	GoToXY(x + 75, y + 2); cout << (char)197;
	GoToXY(x + 100, y + 2); cout << (char)197;
	GoToXY(x + 112, y + 2); cout << (char)197;
	GoToXY(x + 128, y + 2); cout << (char)180;
	GoToXY(x, y + 3 + bang); cout << (char)192;
	GoToXY(x + 10, y + 3 + bang); cout << (char)193;
	GoToXY(x + 38, y + 3 + bang); cout << (char)193;
	GoToXY(x + 66, y + 3 + bang); cout << (char)193;
	GoToXY(x + 75, y + 3 + bang); cout << (char)193;
	GoToXY(x + 100, y + 3 + bang); cout << (char)193;
	GoToXY(x + 112, y + 3 + bang); cout << (char)193;
	GoToXY(x + 128, y + 3 + bang); cout << (char)217;
	GoToXY(x + 1, y + 1); cout << "  ISBN";
	GoToXY(x + 11, y + 1); cout << "         TEN SACH";
	GoToXY(x + 39, y + 1); cout << "         TAC GIA";
	GoToXY(x + 67, y + 1); cout << "  NXB";
	GoToXY(x + 76, y + 1); cout << "       THE LOAI";
	GoToXY(x + 101, y + 1); cout << "  MA SACH";
	GoToXY(x + 113, y + 1); cout << "  TRANG THAI";
}
void XoaBangTenSach() //Xoa ben trong bang in thong tin sach
{
	for(int i = 0; i < bang; i++)
	{
		GoToXY(151, 15 + i); cout << "           ";
		GoToXY(163, 15 + i); cout << "              ";
	}
}
void InThongTinSach(DauSach *m) //In thong tin sach ra bang
{
	BangInThongTinSach(50, 12);
	GoToXY(53, 15); cout << m->ISBN;
	GoToXY(63, 15); cout << m->tenSach;
	GoToXY(91, 15); cout << m->tacGia;
	GoToXY(119, 15); cout << m->namXuatBan;
	GoToXY(132, 15); cout << m->theLoai;
	int j = 1, l = 0;
	int dem = -1;
	double k = m->soLuong;
	k = ceil(k/ bang);
	DMSPTR r = m->DMS;
	for(int i = 0; i < m->soLuong; i++)
	{
		dem++;
		if(dem >= (j - 1) * bang && dem < j * bang)
		{
			GoToXY(153, 15 + i); cout << r->infor.maSach;
			GoToXY(164, 15 + i);
			if(r->infor.trangThai == choMuonDuoc) cout << "Cho Muon Duoc";
			else if(r->infor.trangThai == daDuocMuon) cout << "Da Cho Muon";
			else if(r->infor.trangThai == daThanhLy) cout << "Da Thanh Ly";
			r = r->next;
		}
	}
	GoToXY(105, 31); cout << "Trang " << j << "/" << k;
	do
	{
		char c = GetKey();
		dem = -1;
		switch(c)
		{
			case Right: if(j < k) //Qua trang
				{
					XoaBangTenSach();
					l = 0;
					r = m->DMS;
					j++;
					GoToXY(105, 31); cout << "Trang " << j << "/" << k;
					for(int i = 0; i < m->soLuong; i++)
					{
						dem++;
						if(dem >= (j - 1) * bang && dem < j * bang)
						{
							GoToXY(153, 15 + l); cout << r->infor.maSach;
							GoToXY(164, 15 + l);
							if(r->infor.trangThai == choMuonDuoc) cout << "Cho Muon Duoc";
							else if(r->infor.trangThai == daDuocMuon) cout << "Da Cho Muon";
							else if(r->infor.trangThai == daThanhLy) cout << "Da Thanh Ly";
							l++;
						}
						r = r->next;
					}
				} break;
			case Left: if(j > 1) //Qua trang
				{
					XoaBangTenSach();
					l = 0;
					r = m->DMS;
					j--;
					GoToXY(105, 31); cout << "Trang " << j << "/" << k;
					for(int i = 0; i < m->soLuong; i++)
					{
						dem++;
						if(dem >= (j - 1) * bang && dem < j * bang)
						{
							GoToXY(153, 15 + l); cout << r->infor.maSach;
							GoToXY(164, 15 + l);
							if(r->infor.trangThai == 0) cout << "Cho Muon Duoc";
							else if(r->infor.trangThai == 1) cout << "Da Cho Muon";
							else if(r->infor.trangThai == 2) cout << "Da Thanh Ly";
							l++;
						}
						r = r->next;
					}
				} break;
			case ESC: return;	
		}
	} while(1);
}
void NhapTenSach(DSDauSach dsDauSach, int x, int y) //Tim ten sach dang nhung
{
	GoToXY(x + 1, y + 1); cout << "Nhap:";
	int i, j, contro = 0, muiten = 0;
	char kytu;
	string temp;
	DSDauSach m;
	GoToXY(x - 3, y + 3); MuiTen();
	GoToXY(x + 7, y + 1);
	do
	{
		modifyCursor(1, true);
		Normal();
		kytu = GetKey();
		if(kytu == Up)
		{
			if(muiten > 0)
			{
				GoToXY(x - 3, y + 3 + muiten); cout << "   ";
				muiten--;
				GoToXY(x - 3, y + 3 + muiten); MuiTen();
				Normal();
				GoToXY(x + 7 + contro, y + 1);
			}
		}
		else if(kytu == Down)
		{
			if(muiten < bang - 1 && muiten < m.n - 1)	// 
			{
				GoToXY(x - 3, y + 3 + muiten); cout << "   ";
				muiten++;
				GoToXY(x - 3, y + 3 + muiten); MuiTen();
				Normal();
				GoToXY(x + 7 + contro, y + 1);
			}	
		}
		else if(kytu == Enter && m.n != 0)
		{
			modifyCursor(1, false);
			DeleteScreen();
			InThongTinSach(m.danhSach[muiten]);
			DeleteScreen();
			contro = 0;
			muiten = 0;
			m.n = 0;
			temp = "";
			BangTraTenSach(80, 12);
			GoToXY(x + 1, y + 1); cout << "Nhap:";
			GoToXY(x - 3, y + 3 + muiten); MuiTen();
			Normal();
		}
		else if((kytu >= 32 && kytu <= 126) || (kytu == Backspace && contro > 0))
		{
			if(kytu >= 32 && kytu <= 126)
			{
				temp += kytu;
				GoToXY(x + 7 + contro, y + 1); cout << kytu;
				contro++;
			}
			else if(kytu == Backspace && contro > 0)
			{
				temp = temp.substr(0, --contro);
				GoToXY(x + 7 + contro, y + 1); cout << " ";
				GoToXY(x + 7 + contro, y + 1);
			}
			modifyCursor(1, false);
			for(i = 0; i < 15; i++) // Xoa trong bang tim ten sach
			{
				for(j = 0; j < 38; j++) { GoToXY(x + 1 + j, y + 3 + i); cout << " "; }
			}
			modifyCursor(1, true);
			m.n = 0;
			string temp2 = temp; //Dung bien temp2 de tim ten sach
			ChuanHoaString(temp2);
			for(i = 0; i < dsDauSach.n; i++)
			{
				if(dsDauSach.danhSach[i]->tenSach.find(temp2) != string::npos)
				{
					m.danhSach[m.n] = dsDauSach.danhSach[i];
					GoToXY(x + 2, y + 3 + m.n); cout << dsDauSach.danhSach[i]->tenSach;
					m.n++;
					if(m.n > bang - 1) break;
				}
			}
			if(m.n == 0) {GoToXY(x + 2, y + 3); cout << "Khong tim thay ket qua";}
			GoToXY(x + 7 + contro, y + 1);
		}
		else if(kytu == ESC)
		{
			DeleteScreen();
			return;
		}
	} while(1);
}

//------------------------------------------------------CAU F-----------------------------------------------------------------
void BangHuongDanMuonSach() // Bang huong dan muon sach
{
	DeleteSign();
	Normal();
	GoToXY(x3 + 15, y3); cout << "HUONG DAN";
	GoToXY(x3, y3 + 1); cout << "Di chuyen mui ten\tMui ten len xuong";
	GoToXY(x3, y3 + 2); cout << "Qua trang\t\tMui ten trai phai";
	GoToXY(x3, y3 + 3); cout << "Chon\t\t\tEnter";
	GoToXY(x3, y3 + 4); cout << "Thoat\t\t\tESC";
}
void BangNhapTheDocGia(int x, int y) //Bang nhap ma the doc gia
{
	int i;
	GoToXY (x - 8, y - 1); cout << "NHAP MA DOC GIA TAI DAY DE MUON SACH";
	for (i = 0; i < 20; i++)
	{
		GoToXY (x + i, y); cout << char(151);
		GoToXY (x + i, y + 2); cout << char(151);
	}
	for (i = 0; i < 3; i ++)
	{
		GoToXY (x, y + i); cout << char(124);
		GoToXY (x + 20, y + i); cout << char(124);
	}
	GoToXY (x, y); cout << char(218);
	GoToXY (x + 20, y); cout << char(191);
	GoToXY (x, y + 2); cout << char(192);
	GoToXY (x + 20, y + 2); cout << char(217);
}
void BangDSMuon(int x, int y) // Bang cac sach 1 doc gia dang muon
{
	for(int i = 0; i < 119; i++)
	{
		GoToXY(x + i, y); cout << (char)151;
		GoToXY(x + i, y + 2); cout << (char)151;
		GoToXY(x + i, y + 6); cout << (char)151;
	}
	for(int i = 0; i < 6; i++)
	{
		GoToXY(x, y + i); cout << (char)124;
		GoToXY(x + 15, y + i); cout << (char)124;
		GoToXY(x + 45, y + i); cout << (char)124;
		GoToXY(x + 72, y + i); cout << (char)124;
		GoToXY(x + 92, y + i); cout << (char)124;
		GoToXY(x + 119, y + i); cout << (char)124;
	}
	GoToXY(x, y + 2); cout << (char)195;
	GoToXY(x + 15, y + 2); cout << (char)134;
	GoToXY(x + 45, y + 2); cout << (char)134;
	GoToXY(x + 72, y + 2); cout << (char)134;
	GoToXY(x + 92, y + 2); cout << (char)134;
	GoToXY(x + 119, y + 2); cout << (char)180;
	GoToXY(x, y + 6); cout << (char)192;
	GoToXY(x + 15, y + 6); cout << (char)193;
	GoToXY(x + 45, y + 6); cout << (char)193;
	GoToXY(x + 72, y + 6); cout << (char)193;
	GoToXY(x + 92, y + 6); cout << (char)193;
	GoToXY(x + 119, y + 6); cout << (char)217;
	GoToXY(x, y); cout << (char)218;
	GoToXY(x + 15, y); cout << (char)194;
	GoToXY(x + 45, y); cout << (char)194;
	GoToXY(x + 72, y); cout << (char)194;
	GoToXY(x + 92, y); cout << (char)194;
	GoToXY(x + 119, y); cout << (char)191;
	GoToXY(x + 4, y + 1); cout << "MA SACH";
	GoToXY(x + 25, y + 1); cout << "TEN SACH";
	GoToXY(x + 54, y + 1); cout << "TAC GIA";
	GoToXY(x + 77, y + 1); cout << "THE LOAI";
	GoToXY(x + 102, y + 1); cout << "NGAY MUON";
}
void InCacSachDangMuon(DSDauSach dsDauSach, MTPTR r, int x, int y) // In cac sach ma 1 doc gia dang muon
{
	int i;
	string temp;
	for(i = 0; i < r->infor.maSach.length(); i++)
	{
		if(r->infor.maSach[i] == '_') break;
	}
	temp = r->infor.maSach.substr(0, i); //Lay ma ISBN
	for(i = 0; i < dsDauSach.n; i++)
	{
		if(dsDauSach.danhSach[i]->ISBN.compare(temp) == 0)
		{
			GoToXY(x + 4, y); cout << r->infor.maSach;
			GoToXY(x + 20, y); cout << dsDauSach.danhSach[i]->tenSach;
			GoToXY(x + 47, y); cout << dsDauSach.danhSach[i]->tacGia;
			GoToXY(x + 75, y); cout << dsDauSach.danhSach[i]->theLoai;
			GoToXY(x + 101, y); cout << r->infor.ngayMuon.ngay << "/" << r->infor.ngayMuon.thang << "/" << r->infor.ngayMuon.nam;
		}
	}
}
DGPTR TimDocGia(DGPTR root, int temp) {
	DGPTR p = root;
	while (p!=NULL) {
		if(p->maThe == temp) return p;
		else if(temp < p->maThe) p = p->left;
		else p = p->right;
	}
	return NULL;
}
int SoLuongSachDangMuon(DGPTR p) {
	int dem = 0;
	MTPTR r = p->infor.MT;
	while(r != NULL) {
		if(r->infor.trangThai == chuaTraSach) dem++;
		r = r->right;
	}
	return dem;
}
string LayISBN(MTPTR r) {
	string temp;
	for(int i = 0; i < r->infor.maSach.length(); i++) 
		if(r->infor.maSach[i] == '_') {
			temp = r->infor.maSach.substr(0, i);
			return temp;
		}
} 
int CheckQuaHan(DGPTR p) {
	int day;
	MTPTR r = p->infor.MT;
	while(r != NULL) {
		if(r->infor.trangThai == chuaTraSach) {
			day = TinhNgay(r->infor.ngayMuon, NgayHienTai());
			if (day > ngayquahan) return 1;
		}
		r = r->right;
	}
	return 0;
}
void InThongTinDocGia(DGPTR p, int x, int y) {
	GoToXY (x, y); cout << "Ten doc gia: " << p->infor.ho << " " << p->infor.ten;
	GoToXY (x, y + 1); cout << "Gioi tinh:   " << p->infor.gioiTinh;
} 
void In1CuonSachDangMuonTrongDMS(DSDauSach dsDauSach, MTPTR r, int x, int y) // In cac sach ma 1 doc gia dang muon
{
	for(int i = 0; i < dsDauSach.n; i++)
		if(dsDauSach.danhSach[i]->ISBN.compare(LayISBN(r)) == 0)
		{
			GoToXY(x + 4, y); cout << r->infor.maSach;
			GoToXY(x + 20, y); cout << dsDauSach.danhSach[i]->tenSach;
			GoToXY(x + 47, y); cout << dsDauSach.danhSach[i]->tacGia;
			GoToXY(x + 75, y); cout << dsDauSach.danhSach[i]->theLoai;
			GoToXY(x + 101, y); cout << r->infor.ngayMuon.ngay << "/" << r->infor.ngayMuon.thang << "/" << r->infor.ngayMuon.nam;
			break;
		}
		
}
void InCacSachDangMuon2(DGPTR p, DSDauSach ds, int x, int y) {
	GoToXY(x, y + 2); cout << "Dang muon cac cuon sach:";
	int dong = 0;
	MTPTR v = p->infor.MT;
	while (v != NULL) {
		if (v->infor.trangThai == chuaTraSach) {
			In1CuonSachDangMuonTrongDMS(ds, v, x, y + 6 + dong);
			dong++;
		} 
		v = v->right;
	}
}
void DMSKhiMuonSach(DauSach *&b, string ISBN_stt) {
	DMSPTR r;
	for(r = b->DMS; r != NULL; r = r->next)
		if(r->infor.maSach.compare(ISBN_stt) == 0) {
			r->infor.trangThai = daDuocMuon;
				break;
		}
}
void DSMTKhiMuonSach(DGPTR &p, string ISBN_stt) {
	MTPTR e = new NodeMT;
	e->infor.maSach = ISBN_stt;
	e->infor.ngayMuon = NgayHienTai();
	e->infor.ngayTra.nam = 0;
	e->infor.ngayTra.ngay = 0;
	e->infor.ngayTra.thang = 0;
	e->infor.trangThai = chuaTraSach;
	e->right = NULL;
	e->left = NULL;
	if(p->infor.MT == NULL) p->infor.MT = e;
	else {
		MTPTR w = p->infor.MT;
		while(w->right != NULL) w = w->right;
		w->right = e;
		e->left = w;
	}
}
void MangISBN_sttChoMuonDuoc(DauSach *a, string m[], int &sl) {
	sl = 0;
	DMSPTR r = a->DMS;
	for(int i = 0; i < a->soLuong; i++) {
		if(r->infor.trangThai == choMuonDuoc) {
			m[sl] = r->infor.maSach;
			sl++;
		}
		r = r->next;
		}
	}
void ChonDanhMucSach(DSDauSach &dsDauSach, DGPTR &root, DGPTR &p, DauSach *a, int x, int y) // Cho doc gia chon danh muc sach
{
	modifyCursor(1, false);
	BangInThongTinSach(50, 12);
	GoToXY(53, 15); cout << a->ISBN;
	GoToXY(63, 15); cout << a->tenSach;
	GoToXY(91, 15); cout << a->tacGia;
	GoToXY(119, 15); cout << a->namXuatBan;
	GoToXY(132, 15); cout << a->theLoai;
	int j = 1, l = 0, sl, muiten = 0;
	int dem = -1;
	string m[maxDauSach];
	MangISBN_sttChoMuonDuoc(a, m, sl);
	for(int i = 0; i < sl; i++)
	{
		dem++;
		if(dem >= (j - 1) * bang && dem < j * bang)
		{
			GoToXY(153, 15 + i); cout << m[i];
			GoToXY(164, 15 + i); cout << "Cho Muon Duoc";
		}
	}
	double k = sl;
	k = ceil(k/ bang);
	GoToXY(105, 31); cout << "Trang " << j << "/" << k;
	GoToXY(179, 15 + muiten); MuiTen2();
	do
	{
		char c = GetKey();
		dem = -1;
		switch(c)
		{
			case Up: if(muiten + 1 > 1) //Len tren
			{
				Normal();
				GoToXY(179, 15 + muiten); cout << "   ";
				muiten--;
				GoToXY(179, 15 + muiten); MuiTen2();
			} break;
			case Down: if(muiten + 1 < bang && muiten < (sl - ((j - 1) * bang) - 1)) //Xuong duoi
			{
				Normal();
				GoToXY(179, 15 + muiten); cout << "   ";
				muiten++;
				GoToXY(179, 15 + muiten); MuiTen2();
			} break;
			case Right: if(j < k) //Qua trang
				{
					Normal();
					XoaBangTenSach();
					l = 0;
					j++;
					GoToXY(105, 31); cout << "Trang " << j << "/" << k;
					if(muiten >  sl - ((j - 1) * bang) - 1)
					{
						GoToXY(179, 15 + muiten); cout << "   ";
						muiten = sl - ((j - 1) * bang) - 1;
						Normal();
						GoToXY(179, 15 + muiten); MuiTen2();
					}
					Normal();
					for(int i = 0; i < sl; i++)
					{
						dem++;
						if(dem >= (j - 1) * bang && dem < j * bang)
						{
							GoToXY(153, 15 + l); cout << m[i];
							GoToXY(164, 15 + l); cout << "Cho Muon Duoc";
							l++;
						}
					}
				} break;
			case Left: if(j > 1) //Qua trang
				{
					Normal();
					XoaBangTenSach();
					l = 0;
					j--;
					GoToXY(105, 31); cout << "Trang " << j << "/" << k;
					for(int i = 0; i < sl; i++)
					{
						dem++;
						if(dem >= (j - 1) * bang && dem < j * bang)
						{
							GoToXY(153, 15 + l); cout << m[i];
							GoToXY(164, 15 + l); cout << "Cho Muon Duoc";
							l++;
						}
					}
				} break;
			case Enter: if(sl > 0) //Chon
			{	
					
				a->luotMuon++; //Trang luot muon len 1 don vi
				DMSKhiMuonSach(a, m[muiten + (j - 1) * bang]);
				DSMTKhiMuonSach(p, m[muiten + (j - 1) * bang]);
				nMT++;
				SaveDauSach(dsDauSach);
				SaveDanhMucSach(dsDauSach);
				SaveMuonTra(root);
				return;
			}
			case ESC: return;	
		}
	} while(1);
}
int KiemTraConSach( DauSach *m) {
	DMSPTR r = m->DMS;
	while(r != NULL) {
		if(r->infor.trangThai == choMuonDuoc) {
			return 1;
		}
		r = r->next;
	}
	return 0;
}

int KiemTraTrungSachDaMuon (DGPTR p, DauSach *m) {
	MTPTR r = p->infor.MT;
	while(r != NULL) {
		if(r->infor.trangThai == chuaTraSach)
			if(LayISBN(r).compare(m->ISBN) == 0) return 1;
		r = r->right;
	}
	return 0; 
} 
void ChonDauSach(DSDauSach &dsDauSach, DGPTR &root, DGPTR &p, int x, int y) //Cho doc gia chon dau sach
{
	int sl, i = 1, muiten = 0;
	double k = 0;
	k = dsDauSach.n;
	k = ceil(k/ bang);
	GoToXY(100, 11); cout << "DANH SACH CAC DAU SACH";
	BangDauSach(60, 12);
	InDauSach(dsDauSach, 60, 12, i, k);
	GoToXY(57, 16); MuiTen();
	do
	{
		char kytu = GetKey();
		switch (kytu)
		{
			case Up: if(muiten + 1 > 1) //Len tren
			{
				Normal();
				GoToXY(57, 16 + muiten); cout << "   ";
				muiten--;
				GoToXY(57, 16 + muiten); MuiTen();
			} break;
			case Down: if(muiten + 1 < bang && muiten < (dsDauSach.n - ((i - 1) * bang) - 1)) //Xuong duoi
			{
				Normal();
				GoToXY(57, 16 + muiten); cout << "   ";
				muiten++;
				GoToXY(57, 16 + muiten); MuiTen();
			} break;
			case Right: if(i < k) //Qua trang
			{
				XoaBangDauSach(60, 12);
				InDauSach(dsDauSach, 60, 12, ++i, k);
				if(i == k && dsDauSach.n % bang != 0 && muiten > dsDauSach.n % bang - 1)
				{
					GoToXY(57, 16 + muiten); cout << "   ";
					muiten = dsDauSach.n - ((i - 1) * bang) - 1;
					GoToXY(57, 16 + muiten); MuiTen();
				}
			} break;
			case Left: if(i > 1) //Qua trang
			{
				XoaBangDauSach(60, 12);
				InDauSach(dsDauSach, 60, 12, --i, k);
			} break;
			case Enter: //Chon
			{
				 if(KiemTraTrungSachDaMuon(p, dsDauSach.danhSach[(i - 1) * bang + muiten]))
				{
					 GoToXY(100, 34); cout << "Sach ban chon da trung";
				
				}
			
				else 
				{
					DeleteScreen();
					ChonDanhMucSach(dsDauSach, root, p, dsDauSach.danhSach[(i - 1) * bang + muiten], x, y);
					return;
				}
			} break;
				 //Xet xem doc gia do da muon dau sach do chua?
				
			case ESC: return;
		}
	} while(1);
}
void NhanEnterDeTiepTuc(DSDauSach &dsDauSach, DGPTR &root, DGPTR &p, int x, int y) //Nhan Enter de muon sach sau khi in cac cuon sach dang muon
{
	MTPTR r = p->infor.MT;
	char c;
	do
	{
		c = GetKey();
		if(c == Enter)
		{
			DeleteScreen();
			ChonDauSach(dsDauSach, root, p, x, y);
			DeleteScreen();
			InThongTinDocGia(p, x, y);
			BangDSMuon(x, y + 3);
			InCacSachDangMuon2(p,dsDauSach, x, y);
			if(SoLuongSachDangMuon(p) == 3) {GoToXY(x + 35, y + 10); cout << "Ban da muon 3 cuon sach nen khong the muon them"; getch(); return;}
			GoToXY(x + 45, y + 10); cout << "NHAN ENTER DE MUON SACH!";
		}
		else if(c == ESC) { return; }
	} while(1);
}

void XetDieuKienDocGia(DSDauSach &dsDauSach, DGPTR &root, int temp, int x, int y) //Xet xem doc gia co the muon sach hay k
{
	DGPTR p = TimDocGia(root ,temp);
	if(p == NULL)
	{
		GoToXY(x + 45, y + 5); cout << "Ma the khong dung!";
		getch();
	}
	else {
		modifyCursor(1, false);	
		InThongTinDocGia(p, x, y);
		BangDSMuon(x, y + 3);
		InCacSachDangMuon2(p, dsDauSach, x, y);
		if(SoLuongSachDangMuon(p) == 3) {
			GoToXY(x + 35, y + 10); 
			cout << "Ban da muon 3 cuon sach nen khong the muon them"; 
			getch(); return;
		}
		else if(p->infor.trangThai == biKhoaThe) {
			GoToXY(x + 30, y + 10);
		 	cout << "The cua ban bi khoa, khong the muon them sach"; 
			getch(); return;
		}
		else if(CheckQuaHan(p)) {
			GoToXY(x + 30, y + 10); 
			cout << "Ban con sach muon qua han nen khong the muon them sach"; 
			getch(); return;
			}
		else if(SoLuongSachDangMuon(p) < 3) {
			GoToXY(x + 45, y + 10); cout << "NHAN ENTER DE MUON SACH!";
			NhanEnterDeTiepTuc(dsDauSach, root, p, 50, 15);
		}
	}
}
void NhapTheDocGia(DSDauSach &dsDauSach, DGPTR &root, int x, int y) //Nhap ma the doc gia de muon sach
{
	modifyCursor(1, true);
	int temp = 0, contro = 0;
	char kytu;
	BangNhapTheDocGia(x, y);
	GoToXY(x + 7, y + 1);
	do
	{
		kytu = GetKey();
		switch(kytu)
		{
			case '0':{temp = temp * 10 + 0; contro++; cout << kytu;} break;
			case '1':{temp = temp * 10 + 1; contro++; cout << kytu;} break;
			case '2':{temp = temp * 10 + 2; contro++; cout << kytu;} break;
			case '3':{temp = temp * 10 + 3; contro++; cout << kytu;} break;
			case '4':{temp = temp * 10 + 4; contro++; cout << kytu;} break;
			case '5':{temp = temp * 10 + 5; contro++; cout << kytu;} break;
			case '6':{temp = temp * 10 + 6; contro++; cout << kytu;} break;
			case '7':{temp = temp * 10 + 7; contro++; cout << kytu;} break;
			case '8':{temp = temp * 10 + 8; contro++; cout << kytu;} break;
			case '9':{temp = temp * 10 + 9; contro++; cout << kytu;} break;
			case Enter: //Chon
				{
					DeleteScreen();
					XetDieuKienDocGia(dsDauSach, root, temp, 50, 15);
					DeleteScreen();
					BangNhapTheDocGia(x, y);
					temp = 0;
					contro = 0;
					GoToXY(x + 7, y + 1);
					modifyCursor(1, true);
				}
			case Backspace: if(contro > 0)
				{
					temp = temp/ 10;
					contro--;
					GoToXY(x + 7 + contro, y + 1); cout << " ";
					GoToXY(x + 7 + contro, y + 1);
				} break;
			case ESC: //Thoat
				{
					modifyCursor(1, false);
					DeleteScreen();
					return;
				} break;	
		}
	} while(1);
}
