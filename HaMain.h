//-----------------------------------------CAU A---------------------------------------------------
void HieuChinhDocGia(DGPTR &root) //Them, xoa, hieu chinh doc gia
{
	GoToXY(55 + 22, 12 - 1); cout << "CAP NHAT THONG TIN DOC GIA" << endl;
	BangDocGia(55, 12);
	HuongDanBangDocGia();
	InDocGia(root, 55, 12);
}
//-----------------------------------------CAU B---------------------------------------------------
void InDanhSachDocGia(DGPTR root) //In danh sach doc gia theo yeu cau tang dan
{
	do
	{
		DeleteScreen();
		HuongDanBangChonThuTu();
		int k = BangChonThuTu(92, 15);
		if (k == 1)
		{
			DeleteScreen();
			GoToXY(75 + 24, 12 - 1); cout << "BANG THONG TIN DOC GIA";
			BangDocGia(75, 12);
			HuongDanBangChonThuTu();
			TenDocGiaTangDan(root, 75, 12);
		}
		else if (k == 2)
		{
			DeleteScreen();
			GoToXY(75 + 24, 12 - 1); cout << "BANG THONG TIN DOC GIA";
			BangDocGia(75, 12);
			HuongDanBangChonThuTu();
			MaDocGiaTangDan(root, 75, 12);
		}
		else { DeleteScreen(); return; }
	} while (1);
}
//-----------------------------------------CAU C---------------------------------------------------
void DanhMaSachTuDong(DSDauSach &dsDauSach) //Them, xoa, hieu chinh dau sach
{
	HuongDanThemDauSach();
	HieuChinhDauSach(dsDauSach, 80, 14);
}
//-----------------------------------------CAU D---------------------------------------------------
void InSachTheoTheLoai(DSDauSach dsDauSach) //In danh sach sach theo the loai
{
	DeleteScreen();
	HuongDanChonTheLoai();
	ChonTheLoai(dsDauSach, 95, 15);
}
//-----------------------------------------CAU E---------------------------------------------------
void TimThongTinSach(DSDauSach dsDauSach) //Tim thong tin sach dua tren Ten Sach
{
	BangHuongDanTraTenSach();
	BangTraTenSach(80, 12);
	NhapTenSach(dsDauSach, 80, 12);
}
//-----------------------------------------CAU F---------------------------------------------------
void MuonSach(DSDauSach dsDauSach, DGPTR root) //Muon sach
{
	BangHuongDanMuonSach();
	NhapTheDocGia(dsDauSach, root, 90, 15);
}
