//-------------------------------------CAU G----------------------------------
void TraSach (DGPTR root, DSDauSach ds)
{
	DeleteSign ();
	HuongDanG ();
	BangNhapMaG (0, 15);
	CauG (root, ds, 50, 15);
}
/*
//-------------------------------------CAU H----------------------------------
void SachMotDocGiaDangMuon (DGPTR root, DSDauSach ds)
{
	DeleteSign ();
	HuongDanH (1, 22);
	KhungBangDocGiaH (45, 11);
	BangNhapMaH (45, 11);
	CauH (root, ds, 51, 10);
}
*/
//-------------------------------------CAU I----------------------------------
void DanhSachDocGiaMuonQuaHan (DGPTR root)
{
	BangI (45, 12);
	HuongDanI ();
	CauI (root);
}

//-------------------------------------CAU J----------------------------------
void MuoiSachMuonNhieuNhat (DSDauSach ds)
{
	HuongDanJ ();
	CauJ(ds, 48, 14);
	BangJ (48, 12);
	do
	{
		char kt = GetKey();
		if (kt == ESC) return; 
	} while(1);
}
//--------------------------------MO KHOA THE----------------------------------
void MoKhoaThe (DGPTR root)
{
	DeleteSign ();
	HuongDanMoKhoa ();
	BangNhapMaH (0, 12);
	GoToXY (119, 11); cout << "MO KHOA THE";
	CauMoKhoaThe (root);
}
