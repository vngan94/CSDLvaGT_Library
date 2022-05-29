#include "MyLib.h"
#include "CauTruc.h"
#include "LoadFile.h"
#include "SaveFile.h"
#include "GiaoDien.h"
#include "HaLib.h"
#include "HaMain.h"
#include "NhatLib.h"
#include "NhatMain.h"
void LoadFile(DSDauSach &dsDauSach, DGPTR &root) //Doc toan bo du lieu trong notepad
{
	loadDocGia(root);
	loadDauSach(dsDauSach);
	loadDanhSachMuonTra(root);
	loadDanhMucSach(dsDauSach);
}
void ClearDMS(DSDauSach &dsDauSach) //Xoa danh sach lien ket don -> Danh Muc Sach
{
	DMSPTR p, q;
	for(int i = 0; i < dsDauSach.n; i++)
	{
		p = dsDauSach.danhSach[i]->DMS;
		while(p != NULL)
		{
			q = p->next;
			delete(p);
			p = q;
		}
	}
}
void ClearDS(DSDauSach &dsDauSach) //Xoa mang con tro -> Dau sach
{
	for(int i = 0; i < dsDauSach.n; i++)
		delete(dsDauSach.danhSach[i]);
}
void ClearDG(DGPTR &root) //Xoa cay nhi phan -> Doc Gia
{
	if(root == NULL) return;
	ClearDG(root->left);
	ClearDG(root->right);
	delete root;
	root = NULL;
}
void ClearMT(DGPTR &root) //Xoa danh sach lien ket kep -> Danh Sach Muon Tra
{
	MTPTR p;
	if(root == NULL) return;
	ClearMT(root->left);
	ClearMT(root->right);
	p = root->infor.MT;
	while (root->infor.MT != NULL)
	{
		p = root->infor.MT;
		if(root->infor.MT->right == NULL) root->infor.MT = NULL;
		else
		{
			root->infor.MT = root->infor.MT->right;
			root->infor.MT->left = NULL;
		}
		delete p;
	}
}
void ClearAll(DSDauSach &dsDauSach, DGPTR &root) //Xoa toan bo
{
	ClearDMS(dsDauSach);
	ClearDS(dsDauSach);
	ClearMT(root);
	ClearDG(root);
}
void GoodBye() //Tam biet
{
	system("cls");
	cout << "GOOD BYE!";
}
void Run(DSDauSach &dsDauSach, DGPTR &root) //Bat dau chay chuong trinh :))
{
	int choose = -5;
	do
	{
		system("cls");
		Outline();
		Title();
		Sign();
		choose = Menu();
		Normal();
		switch (choose)
		{
			case 1: HieuChinhDocGia(root); break;
			case 2: InDanhSachDocGia(root); break;
			case 3: DanhMaSachTuDong(dsDauSach); break;
			case 4: InSachTheoTheLoai(dsDauSach); break;
			case 5: TimThongTinSach(dsDauSach); break;
			case 6: MuonSach(dsDauSach, root); break;
			case 7: TraSach(root, dsDauSach); break;
			case 8: SachMotDocGiaDangMuon (root, dsDauSach); break;
			case 9: DanhSachDocGiaMuonQuaHan(root); break;
			case 10: MuoiSachMuonNhieuNhat (dsDauSach); break;
			case 11: MoKhoaThe(root); break;
			case 12: {GoodBye(); return; }
		}
		Normal();
	} while (1);
}
int main()
{
	Setup(); //Khoi tao trang thai ban dau
	DSDauSach dsDauSach;
	dsDauSach.n = 0;
	DGPTR treeDG = NULL;
	LoadFile(dsDauSach, treeDG);
	Run(dsDauSach, treeDG);
	ClearAll(dsDauSach, treeDG);
	return 0;
}

//Xap xi 5000 dong :))
