DGPTR Rotate_Left(DGPTR root) //Xoay trai
{
	DGPTR p;
	if(root != NULL && root->right != NULL) 
    {
		p = root->right;
		root->right = p->left;
		p->left = root;
	}
	return p;
}
DGPTR Rotate_Right(DGPTR ya) //Xoay phai
{
	DGPTR s;
	if(ya != NULL && ya->left != NULL)
    {
		s = ya->left;
		ya->left = s->right;
		s->right = ya;
	}
   	return s;
}
void InsertTree(DGPTR &pavltree, int x, DocGia a) //Them nut vao cay nhi phan tim kiem can bang
{
	DGPTR 	fp, p, q,    	// fp là nut cha cua p, q la con cua p
			fya, ya,     	/* ya là nut truoc gan nhat co the mat can bang fya là nut cha cua ya */
			s;           	// s là nut con cua ya theo huong mat can bang
	int imbal;           	/* imbal =  1 neu bi lech ve nhánh trái
                                 	   	  = -1 neu bi lech ve nhánh phai */
	// Khoi dong các giá tri
	fp = NULL;   p = pavltree;
	fya = NULL;   ya = p;
	// tim nut fp, ya va fya, nut moi them vao la nut la con cua nut fp
	while(p != NULL)
	{
    	if (x == p->maThe) return; // bi trung khoa
    	if (x < p->maThe) q = p->left;
    	else q = p->right;
    	if(q != NULL)
    		if(q->bf != 0) // truong hop chi so can bang cua q la 1 hay -1
        	{
				fya = p;
            	ya = q;
        	}
    	fp = p;
    	p = q;
	}
	// Thêm nút moi (nut la) la con cua nut fp
	q = new NodeDocGia;	// cap phat vung nho
	q->maThe = x;  q->infor = a;  q->bf = 0;
	q->left = NULL;  q->right = NULL;
    if(x < fp->maThe) fp->left = q;
	else fp->right = q;
	/*Hieu chinh chi so can bang cua tat ca cac nut giua ya va q, neu bi lech
	ve phia trai thi chi so can bang cua tat ca cac nut giua ya va q deu la
    1, neu bi lech ve phia phai thi chi so can bang cua tat ca cac nut giua
    ya va q deu la -1 */
	if(x < ya->maThe) p = ya->left;
	else p = ya->right;
    s = p;     // s la con nut ya
    while(p != q)
    { 
		if(x < p->maThe)
    	{
			p->bf = 1;
    		p = p->left;
    	}
    	else
    	{
			p->bf = -1;
			p = p->right;
    	}
	}
   	// xac dinh huong lech
	if(x < ya->maThe) imbal = 1;
	else imbal = -1;
	if(ya->bf == 0)
	{
		ya->bf = imbal;
    	return;
	}
	if(ya->bf != imbal)
	{
		ya->bf = 0;
    	return;
	}
	if(s->bf == imbal)   // Truong hop xoay don
	{ 
		if(imbal == 1) p = Rotate_Right(ya); // xoay phai 
    	else p = Rotate_Left(ya); // xoay trai 
    	ya->bf = 0;
		s->bf = 0;
	}
	else // Truong hop xoay kep
	{ 
		if(imbal == 1)    // xoay kep trai-phai 
    	{
			ya->left = Rotate_Left(s);
        	p = Rotate_Right(ya);
    	}
    	else              // xoay kep phai-trai 
    	{
			ya->right = Rotate_Right(s);
			p = Rotate_Left(ya);
    	}
    	if(p->bf == 0)    // truong hop p la nut moi them vao
    	{
			ya->bf = 0;
			s->bf = 0;
    	}
    	else if(p->bf == imbal)
        {
			ya->bf = -imbal;
            s->bf = 0;
        }
        else
        {
			ya->bf = 0;
    		s->bf = imbal;
        }
    	p->bf = 0;
	}
	if(fya == NULL) pavltree = p;
	else if(ya == fya->right) fya->right = p;
    else fya->left = p;
}
void loadDocGia(DGPTR &root) //Doc file DocGia.txt
{
	int k, j, key;
	DocGia temp;
	string t;
	DGPTR p;
	ifstream fin;
	fin.open("DocGia.txt", ios_base::in);
	fin >> k;
	for(int i = 0; i < k; i++)
	{
		fin >> key;
		getline(fin, t);
		getline(fin, temp.ho);
		getline(fin, temp.ten);
		getline(fin, temp.gioiTinh);
		fin >> j;
		if(j == 0) temp.trangThai = biKhoaThe;
		else temp.trangThai = conHoatDong;
		getline(fin, t);
		if(root == NULL)
		{
			p = new NodeDocGia;
			p->maThe = key;
			p->infor = temp;
			p->bf = 0;
			p->left = NULL;		p->right = NULL;
			root = p;								
		}
		else InsertTree(root, key, temp);
	}
	fin.close();
}
void loadDauSach(DSDauSach &dsDauSach) //Doc file DauSach.txt
{
	string temp;
	ifstream fin;
	fin.open("DauSach.txt", ios_base::in);
	fin >> dsDauSach.n;
	getline(fin, temp);
	for(int i = 0; i < dsDauSach.n; i++)
	{
		dsDauSach.danhSach[i] = new DauSach;
		getline(fin, dsDauSach.danhSach[i]->ISBN);
		getline(fin, dsDauSach.danhSach[i]->tenSach);
		fin >> dsDauSach.danhSach[i]->soTrang;
		getline(fin, temp);
		getline(fin, dsDauSach.danhSach[i]->tacGia);
		fin >> dsDauSach.danhSach[i]->namXuatBan;
		getline(fin, temp);
		getline(fin, dsDauSach.danhSach[i]->theLoai);
		fin >> dsDauSach.danhSach[i]->soLuong;
		getline(fin, temp);
		fin >> dsDauSach.danhSach[i]->luotMuon;
		getline(fin, temp);
	}
	fin.close();
}
DGPTR search(DGPTR root, int x)
{
	DGPTR p;
	p = root;
	while(p != NULL && x != p->maThe)
		if(x < p->maThe) p = p->left;
		else p = p->right;
	return p; 
}
void loadDanhSachMuonTra(DGPTR &root) //Doc file DanhSachMuonTra.txt
{
	int j;
	DGPTR p;
	string temp;
	ifstream fin;
	fin.open("DanhSachMuonTra.txt", ios_base::in);
	fin >> nMT;
	getline(fin, temp);
	for(int i = 0; i < nMT; i++)
	{
		fin >> j;
		getline(fin, temp);
		p = search(root, j);
		if(p != NULL)
		{
			if(p->infor.MT == NULL)
			{
				p->infor.MT = new NodeMT;
				getline(fin, p->infor.MT->infor.maSach);
				fin >> p->infor.MT->infor.ngayMuon.ngay;
				fin >> p->infor.MT->infor.ngayMuon.thang;
				fin >> p->infor.MT->infor.ngayMuon.nam;
				fin >> p->infor.MT->infor.ngayTra.ngay;
				fin >> p->infor.MT->infor.ngayTra.thang;
				fin >> p->infor.MT->infor.ngayTra.nam;
				fin >> j;
				getline(fin, temp);
				if(j == 0) p->infor.MT->infor.trangThai = chuaTraSach;
				else if(j == 1) p->infor.MT->infor.trangThai = daTraSach;
				else p->infor.MT->infor.trangThai = lamMatSach;
				p->infor.MT->left = NULL;
				p->infor.MT->right = NULL;
			}
			else
			{
				MTPTR q = new NodeMT;
				MTPTR r = p->infor.MT; //con tro tam
				getline(fin, q->infor.maSach);
				fin >> q->infor.ngayMuon.ngay;
				fin >> q->infor.ngayMuon.thang;
				fin >> q->infor.ngayMuon.nam;
				fin >> q->infor.ngayTra.ngay;
				fin >> q->infor.ngayTra.thang;
				fin >> q->infor.ngayTra.nam;
				fin >> j;
				getline(fin, temp);
				if(j == 0) q->infor.trangThai = chuaTraSach;
				else if(j == 1) q->infor.trangThai = daTraSach;
				else q->infor.trangThai = lamMatSach;
				while(r->right != NULL)
					r = r->right;
				r->right = q;
				q->left = r;
				q->right = NULL;	
			}
		}
	}
	fin.close();
}
void loadRandom(int *m, int &n) //Load file Random.txt
{
	ifstream fin;
	fin.open("Random.txt", ios_base::in);
	fin >> n;
	for(int i = 0; i < n; i++)
		fin >> m[i];
	fin.close();	
}
void loadDanhMucSach(DSDauSach &dsDauSach) //Load file DanhMucSach.txt
{
	int n, i, j;
	string temp, temp2;
	ifstream fin;
	fin.open("DanhMucSach.txt", ios_base::in);
	fin >> nDMS;
	getline(fin, temp);
	for(i = 0; i < nDMS; i++)
	{
		getline(fin, temp);
		for(j = 0; j < temp.length(); j++)
		{
			if(temp[j] == '_')
			{
				temp2 = temp.substr(0, j);
				break;
			}
		}
		for(j = 0; j < dsDauSach.n; j++)
		{
			if(dsDauSach.danhSach[j]->ISBN.compare(temp2) == 0)
			{
				if(dsDauSach.danhSach[j]->DMS == NULL)
				{
					dsDauSach.danhSach[j]->DMS = new NodeDMS;
					dsDauSach.danhSach[j]->DMS->infor.maSach = temp;
					int k;
					fin >> k;
					getline(fin, temp2);
					if(k == 0) dsDauSach.danhSach[j]->DMS->infor.trangThai = choMuonDuoc;
					else if(k == 1) dsDauSach.danhSach[j]->DMS->infor.trangThai = daDuocMuon;
					else if(k == 2) dsDauSach.danhSach[j]->DMS->infor.trangThai = daThanhLy;
					dsDauSach.danhSach[j]->DMS->next = NULL;
				}
				else
				{
					DMSPTR r;
					DMSPTR q = new NodeDMS;
					q->infor.maSach = temp;
					int k;
					fin >> k;
					getline(fin, temp2);
					if(k == 0) q->infor.trangThai = choMuonDuoc;
					else if(k == 1) q->infor.trangThai = daDuocMuon;
					else if(k == 2) q->infor.trangThai = daThanhLy;
					for(r = dsDauSach.danhSach[j]->DMS; r->next != NULL; r = r->next);
					r->next = q;
					q->next = NULL;
				}
				break;
			}
		}
	}
	fin.close();
}
