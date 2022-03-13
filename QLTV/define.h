#pragma once
#define MAX_MENU 5
#define DIS_MENUX 30 //Khoang cach giua 2 muc menu
#define DIS_MENUY 30
//****************//
#define WD_WIDTH 1900 //L+R
#define WD_HEIGHT 1000 //U+D
#define OBJ_PER_PAGE 22
#define OBJ_PER_PAGE_dms 20
#define DELAY_NOTI 1100
//****************//
char MenuChinh[MAX_MENU+1][30] = {"Quan ly dau sach", "Quan ly doc gia", "Muon tra sach", "Thong tin", "Huong dan"};
char Menudausach[][30]={"Them","Xoa","Hieu chinh", "Tim kiem", "Danh muc sach", "Top 10"};
char Menudocgia[][30]={"Them","Xoa","Hieu chinh","Danh sach doc gia","Danh sach qua han","Sach dang muon"};
char Menumuontra[][30]={"Muon sach","Tra sach"};
//
int ViTriKhung[]={500,800,900,400};
int ViTriMucMenu[MAX_MENU+1]={20};
int ViTriMucMenuPhu[7]={0, 40, 80, 120, 160, 200, 240};
int KichThuocMenuPhu[MAX_MENU+1]={200, 225, 180, 180, 120, 200};
int ViTriMucMenuCuoi[5]={220,180,60};
int ViTriKhungDauSach[]={0,250,340,430,520,610,700};
int ViTriKhungDocGia[]={0,250,340,430,520,610};
//
char KhungNoiDung[][30]={"Thong tin doc gia","OK","Thoat","Ho","Ten","Trang thai","Phai"};
char KhungDauSach[][30]={"Thong tin dau sach","OK","Thoat","ISBN","Ten sach","So trang","Tac gia","Nam xuat ban","The loai"};
char KhungXoa[][30]={"ISBN","Ma the","Danh sach sach","OK","Thoat","Dach sach doc gia"};
char Khunginsach[][30]={"","Ma sach","Ten sach","Trang thai","Vi tri"};
//
char KhungDocgia[][30]={"Thong tin doc gia","OK","Thoat","Ma the","Ho & ten dem", "Ten", "Trang thai","Phai"};
char Sex[][30] 	= {"Nam", "Nu"};
//
char Success[][50] = {"Them thanh cong!", "Xoa thanh cong!", "Chinh sua thanh cong!", "Save Successfully!","Muon thanh cong!","Tra thanh cong!","Bao mat sach thanh cong!","Ban bi khoa the!"};
char Fail[][50]    = {"Khong duoc de trong!", "Khong tim thay!", "Sai trang thai!","Sach da duoc muon!", "Sach da co!", 
					  "Sach da thanh ly!", "The dang bi khoa!","Da muon qua 3 quyen!", "Giu sach qua han (> 7 ngay)!",
					   "Doc gia khong muon sach nay!","Nam xuat ban khong the lon hon hien tai!","Khong the xoa doc gia dang muon sach!","Khong co du lieu!","Nam xuat ban khong the bang 0!"};
//
int  sizeDanhSachDausach[] 	 = {10, 30, 100, 10, 65, 10, 55, 20};
int  sizeDanhSachDocgia[] 	 = {10, 40, 150, 100, 50, 38, 20};
char danhSachDausach[][30]   = {"STT","ISBN","Ten sach","So trang","Tac gia","Nam xuat ban","The loai","So luot muon"};
char danhSachDanhmucsach[][30] = {"STT", "Ma sach", "Trang thai", "Vi tri"};
char danhSachDocgia[][30] = {"STT", "Ma the", "Ho", "Ten", "Phai", "Trang thai the","So ngay qua han"};
int sizeDanhmucsach[] = {20, 40, 60, 80, 100};
int sizeSachdangmuon[] = {30, 100, 50, 30, 60};
//
char checkDS[][30]={"Thong tin dau sach","Xac nhan","Thoat","ISBN","Ten sach","So trang","Tac gia","Nam xuat ban","The loai"};
//DMS
//int ViTriMucMenuDms[] = {20};
int ViTrichuDms[] = {0,550,605,660};
int ViTrimucmenuDms[] = {0,535,590,645};
char khungdms[][30] = {"Them","",""};
char Khungmuon[][30] = {"","Muon sach","Thoat"};
char Khungtra[][30] = {"Tra sach","Thoat","Mat sach"};
char Khunginsachmuon[][30] = {"Ma sach","Ten sach","Ngay muon","Trang thai","Thong tin sach"};
// Doc gia //
char khunginfonhap[][30] = {"Nhap ma the", "Nhap ma sach"};
char khungsort[][30] = {"Ten","Ma the"};










