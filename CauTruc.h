//Khai bao du lieu
const int Up = -72, Down = -80, Left = -75, Right = -77, Enter = 13, ESC = 27, Delete = -83, F2 = -60, F3 = -61, Space = 32, Backspace = 8;
const int n = 11, maxDauSach = 1000, bang = 15, maxdocgia = 1000, ngayquahan = 7;
int nMT, nDMS;
const int x1 = 47, x2 = 0, y2 = 10, x3 = 0, y3 = 22;
string menu[n] = {"01. Nhap the doc gia                        ",
				  "02. Danh sach doc gia                       ",
				  "03. Them dau sach va danh ma tu dong        ",
				  "04. Danh sach cac dau sach theo the loai    ",
				  "05. Tim thong tin sach                      ",
				  "06. Muon sach                               ",
				  "07. Tra sach                                ",
				  "08. Danh sach cac sach 1 doc gia dang muon  ",
				  "09. Danh sach doc gia muon sach qua han     ",
				  "10. 10 sach co luot muon nhieu nhat         ",
				  "11. Mo khoa the                             "};
//-------------------------------------------------------------------------------------------------------------------------------------------
enum TrangThaiDMS {choMuonDuoc, daDuocMuon, daThanhLy};
struct DanhMucSach //Danh sach lien ket don
{
	string maSach; //1 cuon sach -> 1 ma
	TrangThaiDMS trangThai; //0: cho muon duoc, 1: da duoc muon, 2: da thanh ly
};
struct NodeDMS 
{
	DanhMucSach infor;
	NodeDMS* next;
};
typedef NodeDMS* DMSPTR;
//-------------------------------------------------------------------------------------------------------------------------------------------
struct DauSach //Danh sach tuyen tinh la mang con tro
{
	string ISBN; //Ma so tieu chuan quoc te cho sach
	string tenSach;
	int soTrang;
	string tacGia;
	int namXuatBan;
	string theLoai;
	int soLuong; //so luong danh muc sach
	int luotMuon; //so luot muon cho tung dau sach
	DMSPTR DMS = NULL; //con tro tro toi cac sach thuoc dau sach tuong ung
};
struct DSDauSach
{
	int n;
	DauSach *danhSach[maxDauSach];
};
//-------------------------------------------------------------------------------------------------------------------------------------------
struct Date //   2/4/2000
{
	int ngay;
	int thang;
	int nam;
};
enum TrangThaiMT { chuaTraSach, daTraSach, lamMatSach };
struct MuonTra //Danh sach lien ket kep
{
	string maSach;
	Date ngayMuon;
	Date ngayTra;
	TrangThaiMT trangThai; //0: chua tra sach, 1: da tra sach, 2: lam mat sach
};
struct NodeMT
{
	MuonTra infor;
	NodeMT* left, * right;
};
typedef NodeMT* MTPTR;
//-------------------------------------------------------------------------------------------------------------------------------------------
enum TrangThaiDG { biKhoaThe, conHoatDong };
struct DocGia //Cay nhi phan tim kiem
{
	string ho;
	string ten;
	string gioiTinh;
	TrangThaiDG trangThai; //0: bi khoa the, 1: con hoat dong
	MTPTR MT = NULL; //con tro tro toi cac cuon sach ma doc gia da va dang muon
	int thoiGian; //thoi gian qua han cua 1 doc gia
};
struct NodeDocGia
{
	int maThe; //random
	DocGia infor;
	int bf; //chi so can bang
	NodeDocGia* left, * right;
};
typedef NodeDocGia* DGPTR;
