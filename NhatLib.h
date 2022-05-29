//--------------------------------Cau G---------------------------------------------------------------------
void BangNhapMaG (int x, int y)
{
	int i;
	GoToXY (x + 92, y - 1); cout << "NHAP MA DOC GIA TAI DAY DE TRA SACH";
	for (i = 0; i < 20; i++)
	{
		GoToXY (x + 100 + i, y);     cout << char(196);
		GoToXY (x + 100 + i, y + 2); cout << char(196);
	}
	
	for (i = 0; i < 3; i ++)
	{
		GoToXY (x + 100, y + i); cout << char(179);
		GoToXY (x + 120, y + i); cout << char(179);
	}
	
	GoToXY (x + 100, y); cout << char(218);
	GoToXY (x + 120, y); cout << char(191);
	
	GoToXY (x + 100, y + 2); cout << char(192);
	GoToXY (x + 120, y + 2); cout << char(217);
}

void XoaBangNhapMaG ()
{
	for (int i = 0; i < 4; i++)
	{
		GoToXY (92, 14 + i); cout << "                                        ";
	}
}

void HuongDanG ()
{
	GoToXY (17, 22); cout << "HUONG DAN";
	GoToXY (0, 23); cout << "Di chuyen mui ten\tPhim Len/Xuong";
	GoToXY (0, 24); cout << "Tra sach\t\tEnter";
	GoToXY (0, 25); cout << "Bao mat sach va den\t\tF3";
	GoToXY (0, 25); cout << "Bao mat sach khong den\t\tF3";
	GoToXY (0, 26); cout << "Thoat\t\t\tESC";
	
}

void XoaNoiDungG (int x, int y)
{
	for (int i = 0; i < 3; i++)
	{
							  
		GoToXY (x + 1, y + 6 + i);  cout <<"              ";
		GoToXY (x + 16, y + 6 + i);  cout << "                             ";
		GoToXY (x + 16 + 30, y + 6 + i); cout << "                          ";
		GoToXY (x + 16 + 30 + 27, y + 6 + i); cout << "                   ";
		GoToXY (x + 16 + 30 + 27 + 23, y + 6 + i); cout << "                        ";
	}
} 


void TraSachBt(DGPTR &p, DSDauSach &dsds, int muiten) {
	MTPTR v = p->infor.MT;
	int viTriNode = 0;
	string a;
	while (v != NULL){
		if(v->infor.trangThai == chuaTraSach) {
			if (viTriNode == muiten) {
				v->infor.trangThai = daTraSach;
				v->infor.ngayTra = NgayHienTai();
				a = v->infor.maSach;
				break;
			}
			viTriNode++;
		}
		v = v->right;
	}
	for(int i = 0; i < dsds.n; i++) 
		if(dsds.danhSach[i]->ISBN.compare(LayISBN(v)) == 0) {
			DMSPTR r = dsds.danhSach[i]->DMS;
			while(r != NULL) {
				if(r->infor.maSach == a) {
					r->infor.maSach = choMuonDuoc;
					return;
				}
			r = r->next;
			}
		}
}
void BaoMatSachVaDen(DGPTR &p, DSDauSach &dsds, int muiten) {
	MTPTR v = p->infor.MT;
	int viTriNode = 0;
	string a;
	while (v != NULL){
		if(v->infor.trangThai == chuaTraSach) {
			if (viTriNode == muiten) {
				v->infor.trangThai = lamMatSach;
				a = v->infor.maSach;
				break;
			}
			viTriNode++;
		}
		v = v->right;
	}
	for(int i = 0; i < dsds.n; i++) 
		if(dsds.danhSach[i]->ISBN.compare(LayISBN(v)) == 0) {
			DMSPTR r = dsds.danhSach[i]->DMS;
			while(r != NULL) {
				if(r->infor.maSach == a) {
					r->infor.maSach = daThanhLy;
					return;
				}
			r = r->next;
			}
		}
}
void BaoMatSachVaKhongDen(DGPTR &p, DSDauSach &dsds, int muiten) {
	p->infor.trangThai = biKhoaThe;
	MTPTR v = p->infor.MT;
	int viTriNode = 0;
	string a;
	while (v != NULL){
		if(v->infor.trangThai == chuaTraSach) {
			if (viTriNode == muiten) {
				v->infor.trangThai = lamMatSach;
				a = v->infor.maSach;
				break;
			}
			viTriNode++;
		}
		v = v->right;
	}
	for(int i = 0; i < dsds.n; i++) 
		if(dsds.danhSach[i]->ISBN.compare(LayISBN(v)) == 0) {
			DMSPTR r = dsds.danhSach[i]->DMS;
			while(r != NULL) {
				if(r->infor.maSach == a) {
					r->infor.maSach = daThanhLy;
					return;
				}
			r = r->next;
			}
		}
}

void CauG (DGPTR &root, DSDauSach &ds, int x, int y)
{
	modifyCursor (1, true);
	int a = 0;
	int contro = 0;
	string temp;    // lay phan dau cua ma sach de duoc ISBN
	GoToXY (102, 16); 
	do {
		char kytu = GetKey ();
		switch (kytu) {
			case Enter:	{	
					DGPTR p = TimDocGia(root, a);
					if (p == NULL) {
						modifyCursor (1, false);
						GoToXY (87, 18);  cout << "Khong tim thay doc gia nay, hay nhap lai ma doc gia!"; 
						getch ();
						GoToXY (87, 18);  cout << "                                                       ";
						modifyCursor (1, true);
						GoToXY (102 + contro, 16);
					}
					else {	
						XoaBangNhapMaG ();
						modifyCursor (1, false);
						boolean check;
						InThongTinDocGia(p, x, y);
						int sl = SoLuongSachDangMuon(p);
						if(sl == 0) {
							GoToXY (x + 43, y + 11); cout<< "So luong sach dang muon la 0.";
							GoToXY (x + 43, y + 12); cout<< ".Hay muon sach va quay lai day.";
							getch();
							break;
						}
						else {
						BangDSMuon (x, y + 3);
						InCacSachDangMuon2(p, ds, x, y);
						GoToXY(x - 3, y + 6); MuiTen(); Normal();
						int muiten = 0;
						boolean check = true;             // khi nhan ESC
						do
						{
							char kytu2 = GetKey ();
							switch (kytu2)
							{
								case Up: if (muiten + 1 > 1)
									{
										GoToXY (x - 3, y + 6 + muiten); cout << "   ";
										muiten--;
										GoToXY (x - 3, y + 6 + muiten); MuiTen();
										Normal ();
									} break;
								case Down: if (muiten + 1 < sl)
									{
										GoToXY (x - 3, y + 6 + muiten); cout << "   ";
										muiten++;
										GoToXY (x - 3, y + 6 + muiten); MuiTen();
										Normal ();
									} break;
								case Enter: //if (sl > 0)
									{	
							 			TraSachBt(p, ds, muiten);
										SaveMuonTra (root);
										SaveDanhMucSach (ds);
										GoToXY (85, 25); cout << "Tra sach thanh cong, du lieu da duoc luu lai!";
											Sleep(1000);
										GoToXY (85, 25); cout << "                                             ";
										XoaNoiDungG(x, y);
										sl--;
										if(sl > 0) {
											InCacSachDangMuon2(p, ds, x, y);
											GoToXY(x - 3, y + 6); MuiTen(); Normal();
											GoToXY (x - 3, y + 7); cout << "   "; 
											GoToXY (x - 3, y + 8); cout << "   ";    // xoa het mui ten
											muiten = 0;
										}
										else {
											GoToXY (x + 43, y + 11); cout<< "So luong sach dang muon la 0.";
											GoToXY (x + 43, y + 12); cout<< ".Hay muon sach va quay lai day.";
											getch();
											return;
										}		
									} break;
								case F3: 
									{
											BaoMatSachVaDen(p, ds, muiten);
											GoToXY (85, 25); cout << "Den sach thanh cong, du lieu da duoc luu lai!";
												Sleep(1000);
											GoToXY (85, 25); cout << "                                             ";
											SaveMuonTra (root);
											SaveDanhMucSach(ds);
											XoaNoiDungG(x, y);
											sl--;
											if(sl > 0) {
												InCacSachDangMuon2(p, ds, x, y);
												GoToXY(x - 3, y + 6); MuiTen(); Normal();
												GoToXY (x - 3, y + 7); cout << "   "; 
												GoToXY (x - 3, y + 8); cout << "   ";    // xoa het mui ten
												muiten = 0;
											}
											else {
												GoToXY (x + 43, y + 11); cout<< "So luong sach dang muon la 0.";
												GoToXY (x + 43, y + 12); cout<< ".Hay muon sach va quay lai day.";
												getch();
												break;
												}		
										}break;
								case F2: {
												BaoMatSachVaKhongDen(p, ds, muiten);
												SaveDocGia (root);
												SaveMuonTra (root);
												SaveDanhMucSach(ds);
												GoToXY (93, 25); cout << "The da bi khoa do khong den sach!";
												Sleep(1000);
												GoToXY (85, 25); cout << "                                             ";
												XoaNoiDungG(x, y);
												sl--;
												if(sl > 0) {
													InCacSachDangMuon2(p, ds, x, y);
													GoToXY(x - 3, y + 6); MuiTen(); Normal();
													GoToXY (x - 3, y + 7); cout << "   "; 
													GoToXY (x - 3, y + 8); cout << "   ";    // xoa het mui ten
													muiten = 0;
												}
												else {
													GoToXY (x + 43, y + 11); cout<< "So luong sach dang muon la 0.";
													getch();
													break;
												}							
								}break;
										
												
											
								case ESC:
								{
									DeleteScreen ();
									BangNhapMaG (0, 15);
									GoToXY (102, 16); 
									contro = 0;
									a = 0;
									modifyCursor (1, true);
									check = false;
								} break;
							}
						} while (check == true);
					}
					}
				} break;
			case Backspace:
				if (contro > 0)
				{
					contro--;
					GoToXY (102 + contro, 16); cout << " ";
					GoToXY (102 + contro, 16);
					a = a / 10;
				} break;
			case ESC: return;
			default:
				{
					if (kytu >= 48 && kytu <= 57)
					{
						switch(kytu)
						{	
							case '0': a = a * 10 + 0; break;
							case '1': a = a * 10 + 1; break;
							case '2': a = a * 10 + 2; break;
							case '3': a = a * 10 + 3; break;
							case '4': a = a * 10 + 4; break;
							case '5': a = a * 10 + 5; break;
							case '6': a = a * 10 + 6; break;
							case '7': a = a * 10 + 7; break;
							case '8': a = a * 10 + 8; break;
							case '9': a = a * 10 + 9; break;
						}
						contro++;
						cout << kytu;
					}
				} 
		}
	} while (1);
}
/*
//---------------------------------------------Cau H---------------------------------------------------------------------
void XoaNoiDungBangDocGia (int x, int y)
{
	Normal ();
	for (int i = 0; i < 15; i++)
	{
		GoToXY (x + 2, y + 4 + i); cout << "           ";
		GoToXY (x + 14, y + 4 + i); cout << "                           ";
		GoToXY (x + 42, y + 4 + i); cout << "         ";
		GoToXY (x + 52, y + 4 + i); cout << "                   ";
	}
}

void KhungBangDocGiaH (int x, int y)
{
	BangDocGia (52, 10);
	GoToXY (x + 24, y - 2); cout << "                                   ";
	GoToXY (x + 34, y - 1); cout << "DANH SACH DOC GIA";
}


void BangNhapMaH (int x, int y)
{
	int i;
	GoToXY (x + 92, y - 1); cout << "NHAP MA DOC GIA TAI DAY DE TRA CUU";
	for (i = 0; i < 20; i++)
	{
		GoToXY (x + 100 + i, y); cout << char(196);
		GoToXY (x + 100 + i, y + 2); cout << char(196);
	}
	
	for (i = 0; i < 3; i ++)
	{
		GoToXY (x + 100, y + i); cout << char(179);
		GoToXY (x + 120, y + i); cout << char(179);
	}
	
	GoToXY (x + 100, y); cout << char(218);
	GoToXY (x + 120, y); cout << char(191);
	
	GoToXY (x + 100, y + 2); cout << char(192);
	GoToXY (x + 120, y + 2); cout << char(217);
}

void BangH (int x, int y)
{
	int i;
	y = y +1;
	for (i = 0; i < 123; i++)
	{
		GoToXY (x + 10 + i, y - 1);  cout << char(196);
		GoToXY (x + 10 + i, y + 1);  cout << char(196);
		GoToXY (x + 10 +  i, y + 5); cout << char(196);
	}
	for (i = 0; i < 7; i++)
	{
		GoToXY (x + 10, y - 1 + i);  cout << char(179);
		GoToXY (x + 28, y - 1 + i);  cout << char(179);
		GoToXY (x + 59, y - 1 + i);  cout << char(179);
		GoToXY (x + 70, y - 1 + i);  cout << char(179);
		GoToXY (x + 95, y - 1 + i);  cout << char(179);
		GoToXY (x + 110, y - 1 + i); cout << char(179);
		GoToXY (x + 133, y - 1 + i); cout << char(179);
	}
	GoToXY (x + 10, y - 1);   cout << char (218);
	GoToXY (x + 28, y - 1 );  cout << char (194);
	GoToXY (x + 59, y - 1 );  cout << char (194);
	GoToXY (x + 70, y - 1 );  cout << char (194);
	GoToXY (x + 95, y - 1 );  cout << char (194);
	GoToXY (x + 110, y - 1 ); cout << char (194);
	GoToXY (x + 133, y - 1);  cout << char(191);
	
	GoToXY (x + 10, y + 1);   cout << char (195);
	GoToXY (x + 28, y + 1 );  cout << char (197);
	GoToXY (x + 59, y + 1 );  cout << char (197);
	GoToXY (x + 70, y + 1 );  cout << char (197);
	GoToXY (x + 95, y + 1 );  cout << char (197);
	GoToXY (x + 110, y + 1 ); cout << char (197);
	GoToXY (x + 133, y + 1);  cout << char(180);
	
	GoToXY (x + 10, y + 5);   cout << char (192);
	GoToXY (x + 28, y + 5 );  cout << char (193);
	GoToXY (x + 59, y + 5 );  cout << char (193);
	GoToXY (x + 70, y + 5 );  cout << char (193);
	GoToXY (x + 95, y + 5 );  cout << char (193);
	GoToXY (x + 110, y + 5 ); cout << char (193);
	GoToXY (x + 133, y + 5);  cout << char(217);
	
	GoToXY (x + 16, y);  cout << "MA SACH";
	GoToXY (x + 40, y);  cout << "TEN SACH";
	GoToXY (x + 61, y);  cout << "SO TRANG";
	GoToXY (x + 79, y);  cout << "TAC GIA";
	GoToXY (x + 97, y);  cout << "NAM XUAT BAN";
	GoToXY (x + 118, y); cout << "THE LOAI";
}
void XoaBangDocGiaH (int x, int y)
{
	for (int i = 0; i < 21; i++)                                                                                 
	{
		GoToXY (x + 7, y - 1 + i); cout<<"                                                                       ";
	}
}
void HuongDanH (int x, int y)
{
	GoToXY (x + 15, y);    cout << "HUONG DAN";
	GoToXY (x - 1, y + 1); cout << "Qua Trang\t\tMui ten trai/phai";
	GoToXY (x - 1, y + 2); cout << "Chon\t\t\tEnter";
	GoToXY (x - 1, y + 3); cout << "Thoat\t\t\tESC";
}

void CauH (DGPTR root, DSDauSach ds, int x, int y)
{
	modifyCursor (1, true);
	int a = 0;
	int contro = 0;
	bool xet = true;
	double k = 0, i = 1;
	Preorder (root, k);
	k = ceil(k/ bang);
	DSDocGia(root, x, y, i, k);
	GoToXY (151, 12); 
	do
	{
		char kytu = GetKey ();
		switch (kytu)
		{
			case Right: if (i < k && xet == true)
			{
				XoaNoiDungBangDocGia (x, y);
				DSDocGia (root, x, y, ++i, k);
				GoToXY (151 + contro, 12); 
			} break;
			case Left: if (i > 1  && xet == true)
			{
				XoaNoiDungBangDocGia (x, y);
				DSDocGia (root, x, y, --i, k);
				GoToXY (151 + contro, 12); 
			} break;
			case ESC: return;
			case Backspace:
				if (xet == true && contro > 0)
				{
					contro--;
					GoToXY (151 + contro, 12); cout << " ";
					GoToXY (151 + contro, 12);
					a = a / 10;
				} break;
			case Enter: if (xet == true)
				{
					DGPTR p = TimDocGia(root, a);
					if (p == NULL) {
						modifyCursor (1, false);
						GoToXY (87, 18);  cout << "Khong tim thay doc gia nay, hay nhap lai ma doc gia!"; 
						getch ();
						GoToXY (87, 18);  cout << "                                                       ";
						modifyCursor (1, true);
						GoToXY (102 + contro, 16);
					}
					else {	
						XoaBangNhapMaG ();
						modifyCursor (1, false);
						boolean check;
						InThongTinDocGia(p, x, y);
						int sl = SoLuongSachDangMuon(p);
						if(sl == 0) {
							GoToXY (x + 43, y + 11); cout<< "So luong sach dang muon la 0.";
							GoToXY (x + 43, y + 12); cout<< ".Hay muon sach va quay lai day.";
							getch();
							break;
						}
						else {
						BangDSMuon (x, y + 3);
						InCacSachDangMuon2(p, ds, x, y);
						
					DGPTR p = TimDocGia (root, a);
					if(p = NULL) {
						GoToXY (130, 15); modifyCursor (1, false); cout << "Khong tim thay doc gia nay, hay nhap lai ma doc gia!";
						getch ();
						GoToXY (130, 15); cout << "                                                       ";
						GoToXY (151, 12); cout << "            ";
						modifyCursor (1, true);
						contro = 0;
						a = 0;
						GoToXY (151, 12);
					}
					else
					{
						modifyCursor (1, false);
						XoaBangDocGiaH (45, 11);
						BangH (45, 17);
						GoToXY (55, 14); cout << " Ten doc gia: " << p->infor.ho << " " << p->infor.ten;
						GoToXY (55, 15); cout << " Gioi tinh:   " << p->infor.gioiTinh;
						GoToXY (55, 16); cout << " Dang muon cac sach sau: ";
						xet = false;
						int dong = 0;
						MTPTR v = p->infor.MT;
						while (v != NULL)
						{
							if (v->infor.trangThai == 0)
							{
								GoToXY (59, 20 + dong); cout << v->infor.maSach;
								int u;
								string temp;
								for (u = 0; u < v->infor.maSach.length(); u++)
								{
									if(v->infor.maSach[u] == '_') break;
								}
								temp = v->infor.maSach.substr(0, u);
								for (u = 0; u < ds.n; u++)
								{
									string bd = ds.danhSach[u]->ISBN;
									if (bd.compare(temp) == 0) break;
								}
								GoToXY (76, 20 + dong);  cout << ds.danhSach[u]->tenSach;
								GoToXY (108, 20 + dong); cout << ds.danhSach[u]->soTrang;
								GoToXY (119, 20 + dong); cout << ds.danhSach[u]->tacGia;
								GoToXY (145, 20 + dong); cout << ds.danhSach[u]->namXuatBan;
								GoToXY (158, 20 + dong); cout << ds.danhSach[u]->theLoai;
								dong++;
							} 
							v = v->right;
						}
						do
						{
							char kt = GetKey ();
							if(kt == ESC) break;
						}
						while (1);
						DeleteScreen ();
						KhungBangDocGiaH (45, 11);
						BangNhapMaH (45, 11);
						DSDocGia (root, x, y, i, k);
						GoToXY (151, 12);
						contro = 0;
						xet = true;
						a = 0;
						modifyCursor (1, true);
					}
				} break;
			default:
			{
				if (kytu >= 48 && kytu <= 57 && xet == true)
				{
					switch (kytu)
					{
						case '0': a = a * 10 + 0; break;
						case '1': a = a * 10 + 1; break;
						case '2': a = a * 10 + 2; break;
						case '3': a = a * 10 + 3; break;
						case '4': a = a * 10 + 4; break;
						case '5': a = a * 10 + 5; break;
						case '6': a = a * 10 + 6; break;
						case '7': a = a * 10 + 7; break;
						case '8': a = a * 10 + 8; break;
						case '9': a = a * 10 + 9; break;
					}
					contro++;
					cout << kytu;
				}
			} 
		}
	} while(1);
}
*/
//--------------------------------Cau I-----------------------------------------------------------------------
void BangI (int x, int y)
{
	int i;
	GoToXY (x, y -2); cout << "                     DANH SACH DOC GIA MUON SACH QUA HAN THEO THU TU THOI GIAN QUA HAN GIAM DAN";
	for (i = 0; i < 98; i++)
	{
		GoToXY (x + 10 + i, y - 1);  cout << char(196);
		GoToXY (x + 10 + i, y + 2);  cout << char(196);
		GoToXY (x + 10 + i, y + 18); cout << char(196);
	} 
	
	for (i = 0; i < 18; i++)
	{
		GoToXY (x + 10, y + i);  cout << char(179);
		GoToXY (x + 26, y + i);  cout << char(179);
		GoToXY (x + 55, y + i);  cout << char(179);
		GoToXY (x + 67, y + i);  cout << char(179);
		GoToXY (x + 87, y + i);  cout << char(179);
		GoToXY (x + 107, y + i); cout << char(179);
 	}
	
	GoToXY (x + 10, y - 1);  cout << char(218);
	GoToXY (x + 26, y - 1);  cout << char(194);
	GoToXY (x + 55, y - 1);  cout << char(194);
	GoToXY (x + 67, y - 1);  cout << char(194);
	GoToXY (x + 87, y - 1);  cout << char(194);
	GoToXY (x + 107, y - 1); cout << char(191);
	
	GoToXY (x + 10, y + 2);  cout << char(195);
	GoToXY (x + 26, y + 2);  cout << char(197);
	GoToXY (x + 55, y + 2);  cout << char(197);
	GoToXY (x + 67, y + 2);  cout << char(197);
	GoToXY (x + 87, y + 2);  cout << char(197);
	GoToXY (x + 107, y + 2); cout << char(180);
	
	GoToXY (x + 10, y + 18);  cout << char(192);
	GoToXY (x + 26, y + 18);  cout << char(193);
	GoToXY (x + 55, y + 18);  cout << char(193);
	GoToXY (x + 67, y + 18);  cout << char(193);
	GoToXY (x + 87, y + 18);  cout << char(193);
	GoToXY (x + 107, y + 18); cout << char(217);
	
	GoToXY (x + 15, y + 1); cout << "MA THE";
	GoToXY (x + 35, y + 1); cout << "HO VA TEN";
	GoToXY (x + 57, y + 1); cout << "GIOI TINH";
	GoToXY (x + 72, y + 1); cout << "TRANG THAI";
	GoToXY (x + 94, y);		cout << "SO NGAY"; 
	GoToXY (x + 94, y + 1); cout << "QUA HAN";
	
}

void HuongDanI ()
{
	Normal();
	GoToXY(x3 + 15, y3); cout << "HUONG DAN";
	GoToXY(x3, y3 + 1);  cout << "Qua Trang               Mui ten trai/phai";
	GoToXY(x3, y3 + 2);  cout << "Thoat \t\t\tESC      ";
	GoToXY(x3, y3 + 3);  cout << "                             ";
}

void XoaNoiDungBangI ()
{
	for (int i = 0; i < 15; i++)
	{
		GoToXY (56, 15 + i);  cout << "               "; 
		GoToXY (73, 15 + i);  cout << "                           "; 
		GoToXY (101, 15 + i); cout << "          "; 
		GoToXY (113, 15 + i); cout << "                   "; 
		GoToXY (133, 15 + i); cout << "                  ";
	}
} 

void CauI (DGPTR root)
{
	const int STACKSIZE = 500;
    DGPTR Stack [STACKSIZE];
    DGPTR p = root;
    int sp = -1;	 // Khoi tao Stack rong
    
    do              // Thoi gian qua han ban dau = 0
	{ 
		while (p != NULL)
		{	 
			Stack[++sp] = p;
			p = p->left;
        }
        if (sp != -1)
        {	 
			p = Stack[sp--];
			p->infor.thoiGian = 0;
			p = p->right;
        }
        else break;
	} while (1);
    p = root;
    sp = -1;
    
    do               // Tinh so ngay qua han
	{ 
		while (p != NULL)
		{	 
			Stack[++sp] = p;
			p = p->left;
        }
        if (sp != -1)
        {	 
			p = Stack[sp--];
			MTPTR v = p->infor.MT;
			
			while (v != 0)
			{
				if (v->infor.ngayTra.ngay == 0)              // truong hop chua tra
				{
					int tg = TinhNgay (v->infor.ngayMuon, NgayHienTai ());
					if (tg > ngayquahan) p->infor.thoiGian += (tg - ngayquahan);
				}
				else                                         // da tra
				{
					int tg = TinhNgay (v->infor.ngayMuon, v->infor.ngayTra);
					if (tg > ngayquahan) p->infor.thoiGian += (tg - ngayquahan);
				}
				v = v->right;
			}
			p = p->right;
        }
        else break;
	} while (1);
	
	DGPTR m[maxdocgia]; // chuyen cay sang mang 
	int dem = -1;
	TreeToMang (root, m, dem);
	dem++;
	
	for (int i = 0; i < (dem - 1); i++) // Sap xep lai mang theo thu tu thoi gian qua han giam dan
	{
		for (int j = i + 1; j < dem; j++)
		{
			if (m[i]->infor.thoiGian < m[j]->infor.thoiGian)
			{
			    DGPTR temp = m[j];
				m[j] = m[i];
				m[i] = temp;
			}
		}
	}
	
	for (int i = 0; i < dem; i++) 
	{
		if (m[i]->infor.thoiGian == 0)
		{
			dem = i;                        // so luong phan tu muon qua han = dem
			break;
		}
	}
	 
	double k = ceil ((double)dem / (double)bang); // Tong so trang
	int trang = 1;
	for (int i = 0; i < 15; i++)
	{
			if (m[i]->infor.thoiGian == 0) break;
			GoToXY (61,  15 + i); cout << m[i]->maThe;
			GoToXY (74,  15 + i); cout << m[i]->infor.ho << " " << m[i]->infor.ten;
			GoToXY (104, 15 + i); cout << m[i]->infor.gioiTinh;
			GoToXY (115, 15 + i); if (m[i]->infor.trangThai == 0) cout << "Bi Khoa The"; else cout << "Con Hoat Dong";
			GoToXY (140, 15 + i); cout << m[i]->infor.thoiGian;
	}
	GoToXY (98, 31); cout << "Trang " << trang << "/" << k;
	do 
	{
		char kytu = GetKey ();
		switch (kytu)
		{
			case Right: if (trang < k)
				{
					XoaNoiDungBangI ();
					trang ++; 
					GoToXY (104, 31); cout << trang;
					int bd = (trang - 1) * bang;
					int dong = 0;
					int dem2 = 0;
					for (int i = bd;i < dem; i++)
					{
						if ((m[i]->infor.thoiGian == 0) || (dem2 == bang)) break;
						GoToXY (61,  15 + dong); cout << m[i]->maThe;
						GoToXY (74,  15 + dong); cout << m[i]->infor.ho << " " << m[i]->infor.ten;
						GoToXY (104, 15 + dong); cout << m[i]->infor.gioiTinh;
						GoToXY (115, 15 + dong); if (m[i]->infor.trangThai == 0) cout << "Bi Khoa The"; else cout << "Con Hoat Dong";
						GoToXY (140, 15 + dong); cout << m[i]->infor.thoiGian;
						dong++;
						dem2++; 
					}
				} break;
			case Left: if (trang > 1)
				{
					XoaNoiDungBangI ();
					trang --; 
					GoToXY (104, 31); cout << trang;
					int bd = (trang - 1) * bang;
					int dong = 0;
					int dem2 = 0;
					for (int i = bd; i < dem; i++)
					{
						if ((m[i]->infor.thoiGian == 0) || (dem2 == bang)) break;
						GoToXY (61,  15 + dong); cout << m[i]->maThe;
						GoToXY (74,  15 + dong); cout << m[i]->infor.ho << " " << m[i]->infor.ten;
						GoToXY (104, 15 + dong); cout << m[i]->infor.gioiTinh;
						GoToXY (115, 15 + dong); if (m[i]->infor.trangThai == 0) cout << "Bi Khoa The"; else cout << "Con Hoat Dong";
						GoToXY (140, 15 + dong); cout << m[i]->infor.thoiGian;
						dong++;
						dem2++;
					}
				} break;
			case ESC: return;
		}
	} while (1);
	
}

//--------------------------------Cau J-------------------------------------------------------------------------------------
void BangJ (int x, int y)
{
	int i;
	GoToXY (x, y - 2); cout << "                                                DANH SACH 10 SACH CO LUOT MUON NHIEU NHAT";
	for (i = 0; i < 135; i++)
	{
		GoToXY (x + i, y - 1);  cout << char(196);
		GoToXY (x + i, y + 1);  cout << char(196);
	}
	
	for (i =0; i < 2; i++)
	{
		GoToXY (x, y + i);       cout << char(179);
		GoToXY (x + 5, y + i);   cout << char(179);
	    GoToXY (x + 20, y + i);  cout << char(179);
	    GoToXY (x + 50, y + i);  cout << char(179);
	    GoToXY (x + 62, y + i);  cout << char(179);
	    GoToXY (x + 85, y + i);  cout << char(179);
	    GoToXY (x + 100, y + i); cout << char(179);
	    GoToXY (x + 122, y + i); cout << char(179);
	    GoToXY (x + 134, y + i); cout << char(179);
	}
	
	GoToXY (x, y - 1);       cout << char(218);
	GoToXY (x + 5, y - 1);   cout << char(194);
	GoToXY (x + 20, y - 1);  cout << char(194);	
	GoToXY (x + 50, y - 1);  cout << char(194);
	GoToXY (x + 62, y - 1);  cout << char(194);
	GoToXY (x + 85, y - 1);  cout << char(194);
	GoToXY (x + 100, y - 1); cout << char(194);
	GoToXY (x + 122, y - 1); cout << char(194);
	GoToXY (x + 134, y - 1); cout << char(191);
	
	GoToXY (x, y + 1); cout << char(195);
	GoToXY (x + 5, y + 1);   cout << char(197);
	GoToXY (x + 20, y + 1);  cout << char(197);	
	GoToXY (x + 50, y + 1);  cout << char(197);
	GoToXY (x + 62, y + 1);  cout << char(197);
	GoToXY (x + 85, y + 1);  cout << char(197);
	GoToXY (x + 100, y + 1); cout << char(197);
	GoToXY (x + 122, y + 1); cout << char(197);
	GoToXY (x + 134, y + 1); cout << char(180);
	
	GoToXY (x + 1, y);   cout << "STT";
	GoToXY (x + 10, y);  cout << "ISBN";
	GoToXY (x + 30, y);  cout << "TEN SACH";
	GoToXY (x + 52, y);  cout << "SO TRANG";
	GoToXY (x + 70, y);  cout << "TAC GIA";
	GoToXY (x + 87, y);  cout << "NAM XUAT BAN";
	GoToXY (x + 107, y); cout << "THE LOAI";
	GoToXY (x + 124, y); cout << "LUOT MUON";
}

void HuongDanJ ()
{
	DeleteSign ();
	GoToXY(x3 + 15, y3); cout << "HUONG DAN";
	GoToXY(x3, y3 + 1); cout << "Thoat\t\t\tESC";
}

void CauJ (DSDauSach ds, int x, int y) 
{
	
	for (int i = 0; i < (ds.n - 1); i++)
	{
		for (int j = i + 1; j < ds.n; j++)
		{
			if (ds.danhSach[j]->luotMuon > ds.danhSach[i]->luotMuon)
			{
				DauSach * temp = ds.danhSach[j];
				ds.danhSach[j] = ds.danhSach[i];
				ds.danhSach[i] = temp;
			}
		}
	}
	for (int i = 0; i < ds.n; i++)
	{
		if ((ds.danhSach[i]->luotMuon == 0) || ((i >= 10) && (ds.danhSach[i]->luotMuon < ds.danhSach[i - 1]->luotMuon)))
		{
			for (int j = 0; j < 135; j++)    
			{
				GoToXY (x + j, y + i);  cout << char(196);  
			}
			GoToXY (x, y + i); 	     cout << char(192);
			GoToXY (x + 5, y + i);   cout << char(193);
			GoToXY (x + 20, y + i);  cout << char(193);	
			GoToXY (x + 50, y + i);  cout << char(193);
			GoToXY (x + 62, y + i);  cout << char(193);
			GoToXY (x + 85, y + i);  cout << char(193);
			GoToXY (x + 100, y + i); cout << char(193);
			GoToXY (x + 122, y + i); cout << char(193);
			GoToXY (x + 134, y + i); cout << char(217);
			break;
		}
		else
		{
			GoToXY (x, y + i);       cout << char(179);
			GoToXY (x + 5, y + i);   cout << char(179);
	   		GoToXY (x + 20, y + i);  cout << char(179);
	    	GoToXY (x + 50, y + i);  cout << char(179);
	   		GoToXY (x + 62, y + i);  cout << char(179);
	   		GoToXY (x + 85, y + i);  cout << char(179);
	   		GoToXY (x + 100, y + i); cout << char(179);
	    	GoToXY (x + 122, y + i); cout << char(179);
	    	GoToXY (x + 134, y + i); cout << char(179);
			
			GoToXY (50, 14 + i);  cout << i + 1; 
			GoToXY (58, 14 + i);  cout << ds.danhSach[i]->ISBN;
			GoToXY (70, 14 + i);  cout << ds.danhSach[i]->tenSach;
			GoToXY (102, 14 + i); cout << ds.danhSach[i]->soTrang;
			GoToXY (112, 14 + i); cout << ds.danhSach[i]->tacGia;
			GoToXY (138, 14 + i); cout << ds.danhSach[i]->namXuatBan;
			GoToXY (150, 14 + i); cout << ds.danhSach[i]->theLoai;
			GoToXY (175, 14 + i); cout << ds.danhSach[i]->luotMuon;
		}
    }
}

//---------------------------------------------------------MO KHOA THE-----------------------------------------------------------------------------
void HuongDanMoKhoa ()
{
	GoToXY (17, 22); cout << "HUONG DAN";
	GoToXY (0, 23);  cout << "Chon\t\t\tEnter";
	GoToXY (0, 24);  cout << "Thoat\t\t\tESC";
}

void CauMoKhoaThe (DGPTR &root)
{
	modifyCursor(1, true);
	int a = 0;
	int contro = 0;
	GoToXY (102, 13);
	do
	{
		char KyTu = GetKey ();
		switch (KyTu)
		{
			case Enter:
				{
					DGPTR p = TimDocGia(root, a);
					if ( p == NULL)
					{
						modifyCursor (1, false);
						GoToXY (85, 15); cout << "Khong tim thay doc gia nay, hay nhap lai ma doc gia!";
						getch ();
						GoToXY (85, 15); cout << "                                                    ";
						GoToXY (102, 13); cout << "           ";
						contro = 0;
						a = 0; 
						GoToXY (102 + contro, 13);
						modifyCursor (1, true);
					}
					else
					{
						modifyCursor (1, false);
						if (p->infor.trangThai == conHoatDong)
						{
							GoToXY (95, 15); cout << "The doc gia nay khong bi khoa!";
							getch ();
							GoToXY (95, 15); cout << "                              ";
							GoToXY (102, 13); cout << "           ";
							contro = 0;
							a = 0;
							modifyCursor (1, true);
							GoToXY (102 + contro, 13);
						}
						else
						{
							GoToXY (90, 15); cout << "Xac nhan mo khoa the doc gia " << p->infor.ho << " " << p->infor.ten;
							GoToXY (100, 16); cout << " MO (Y)\tKHONG MO (N)";
							do
							{
								char xet = GetKey ();
								{
									if (xet == 'Y' || xet == 'y')
									{
										p->infor.trangThai = conHoatDong;   
										SaveDocGia(root);                       
										GoToXY (90, 15); cout << "                                                                            ";
										GoToXY (100, 16); cout << "                               ";
										GoToXY (90, 15); cout << "Da mo khoa the cho doc gia " << p->infor.ho << " " << p->infor.ten;
										Sleep (2500);
										GoToXY (90, 15); cout << "                                                                   ";
										GoToXY (102, 13); cout << "           ";
										contro = 0;
										a = 0;
										modifyCursor(1, true);
										GoToXY (102 + contro, 13);
										break;
									}
									else if (xet == 'N' || xet == 'n' || xet == ESC)
									{
										modifyCursor(1, true);
										GoToXY (90, 15); cout << "                                                                             ";
										GoToXY (100, 16); cout << "                                 ";
										GoToXY (102, 13); cout << "           ";
										contro = 0;
										a = 0;
										GoToXY (102 + contro, 13);
										break;
									}
								}
							} while (1);
						}
					}
				} break;
			default:
				{
					if(KyTu >= 48 && KyTu <= 57)
					{
						switch (KyTu)
						{
							case '0': a = a * 10 + 0; break;
							case '1': a = a * 10 + 1; break;
							case '2': a = a * 10 + 2; break;
							case '3': a = a * 10 + 3; break;
							case '4': a = a * 10 + 4; break;
							case '5': a = a * 10 + 5; break;
							case '6': a = a * 10 + 6; break;
							case '7': a = a * 10 + 7; break;
							case '8': a = a * 10 + 8; break;
							case '9': a = a * 10 + 9; break;
						}
						contro++;
						cout << KyTu;
					}
				} break;
			case Backspace:
				if (contro > 0)
				{
					contro--;
					GoToXY (102 + contro, 13); cout << " ";
					GoToXY (102 + contro, 13);
					a = a / 10;
				}break;
			case ESC: return;
		}
	} while (1);
}
