void SaveDauSach (DSDauSach ds) //Luu mang tuyen tinh con tro -> Danh sach dau Sach
{
	ofstream fout;
	fout.open("DauSach.txt", ios_base::out);
	fout << ds.n << endl;
	for (int i = 0; i < ds.n; i++)
	{
		fout << ds.danhSach[i]->ISBN << endl
		     << ds.danhSach[i]->tenSach << endl
		     << ds.danhSach[i]->soTrang << endl
		     << ds.danhSach[i]->tacGia << endl
		     << ds.danhSach[i]->namXuatBan << endl
			 << ds.danhSach[i]->theLoai << endl
			 << ds.danhSach[i]->soLuong << endl
			 << ds.danhSach[i]->luotMuon << endl;
	}
	fout.close();
} 
void SaveMuonTra(DGPTR root) //Luu danh sach lien ket kep -> Danh sach muon tra
{
	ofstream fout;
	fout.open("DanhSachMuonTra.txt", ios_base::out);
	fout << nMT << endl;
	const int STACKSIZE = 500;
	DGPTR Stack[STACKSIZE];
	DGPTR p = root;
   	int sp = -1;	 // Khoi tao Stack rong
   	do
   	{
		while (p != NULL)
		{	 
			Stack[++sp] = p;
			p = p->left;
    	}
    	if (sp != -1)
    	{	 
			p = Stack[sp--];
			MTPTR r = p->infor.MT;
    		while (r != NULL)
			{
				fout << p->maThe << endl
					 << r->infor.maSach << endl
					 << r->infor.ngayMuon.ngay << " " << r->infor.ngayMuon.thang << " " << r->infor.ngayMuon.nam << endl
					 << r->infor.ngayTra.ngay << " " << r->infor.ngayTra.thang << " " << r->infor.ngayTra.nam << endl
					 << r->infor.trangThai << endl; 
				r = r->right;
			}
			p = p->right;
		}
    	else break;
    } while (1);
	fout.close();
}
void Inorder1(DGPTR root, int &k) //Dem so doc gia
{
	if(root != NULL)
	{
		Inorder1(root->left, k);
		k++;
		Inorder1(root->right, k);
	}
}
void SaveDocGia (DGPTR root) //Luu cay nhi phan -> Danh sach doc gia
{
	int k = 0;
	ofstream fout;
	fout.open("DocGia.txt", ios_base::out);
	Inorder1(root, k);
	fout << k << endl;
	const int STACKSIZE = 500;
    DGPTR Stack[STACKSIZE];
    DGPTR p = root;
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
			fout << p->maThe << endl
				 << p->infor.ho << endl
				 << p->infor.ten << endl
				 << p->infor.gioiTinh << endl
				 << p->infor.trangThai << endl;
			p = p->right;
        }
        else break;
	} while (1);
    fout.close();
}
void SaveRandom(int m[], int n) //Luu vao file Random.txt
{
	ofstream fout;
	fout.open("Random.txt", ios_base::out);
	fout << --n << endl;
	for(int i = 0; i < n; i++)
		fout << m[i] << " ";
	fout.close();
}
void SaveDanhMucSach(DSDauSach dsDauSach) //Luu vao file DanhMucSach.txt
{
	ofstream fout;
	fout.open("DanhMucSach.txt", ios_base::out);
	fout << nDMS << endl;
	for(int i = 0; i < dsDauSach.n; i++)
	{
		DMSPTR r;
		for(r = dsDauSach.danhSach[i]->DMS; r != NULL; r = r->next)
		{
			fout << r->infor.maSach << endl << r->infor.trangThai << endl;
		}
	}
	fout.close();
}
