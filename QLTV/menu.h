#pragma once
#include <graphics.h>
#include "define.h"
#include "colors.h"
#include "cautrucdulieu.h"
#include "nhaplieu.h"
using namespace std;

//***************//
void KhoiTaoChuongTrinh();
void Guild();
void Thoat(DSDS &ListDausach, TreeDocgia &docgia);
void TaoManHinhLamViec();
void VeMenu();
void VeMenuPhu(int sttMenuChinh, char menu[][30]);
void InThongTin(int x, int y,char *s);
void noti(char khungNoiDung[]);
void ThongBao(int x, int y, char noti[50], int mauChu, int mauNen);
void infoText(int x, int y, char noiDung[],char info[],int MauChu);
void veKhung(int x, int y, char noiDung[], bool daChon, int mauNen, int mauChu);
void NoiBatMuc(int sttMenuChinh, int sttMenuPhu, char menu[][30], int HL_COLOR, int C_SIZE);
void VeKhungthemDausach(char KhungNoiDung[][30],DS_Dausach *listtmp,struct Dausach *tmp, int Mcase);
void VeKhungxoaDausach();
void VeKhungthemDocgia(char KhungNoiDung[][30], int Mcase);
void DanhMucsach(DSDS &ListDausach);

//***************//
//MENU
void Menu(DSDS &ListDausach);
void MenuPhu(int viTriMenuPhu, char menu[][30], int MAXMENU, int &chonMuc);
void addDausach(struct DS_Dausach &ListDausach);
void XoaDausach(struct DS_Dausach &ListDausach);
void chinhSuaDausach(struct DS_Dausach &ListDausach);
void TimKiem(DSDS &ListDausach);
void Top10sach(DSDS &ListDausach);
void ChonMenuPhu(int sttMenuChinh, DSDS &ListDausach, TreeDocgia &docgia);
void Docgia(TreeDocgia &docgia, DSDS &dsds);
void addDocgia(TreeDocgia &docgia);
void XoaDocgia(TreeDocgia &docgia);
void chinhSuaDocgia(TreeDocgia &docgia);
void DanhsachDocgia(TreeDocgia &docgia);
void DanhsachQuahan(TreeDocgia &docgia);
void SachdangMuon(TreeDocgia &docgia, DSDS &dsds);
void Dausach(struct DS_Dausach &ListDausach);
void Muontra(TreeDocgia &docgia, DSDS &dsds);
void Muonsach(TreeDocgia docgia, DSDS &dsds);
void Trasach(TreeDocgia docgia, DSDS &dsds);
void Huongdan();
void Thongtin();
//**************//
//Ham ve thanh cong cu 
void VeMenu(){
	// Ve nen menu chinh
	setbkcolor(MAU_NEN);
	cleardevice();
	setfillstyle(SOLID_FILL, MAU_MENU);
	
	// Ve cac muc menu chinh
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT, 0, 2);	
	for (int i = 0; i < MAX_MENU; i++){
		outtextxy(ViTriMucMenu[i], 15, MenuChinh[i]);
		ViTriMucMenu[i+1] = ViTriMucMenu[i] + textwidth(MenuChinh[i]) + DIS_MENUX;
	}
}

void TaoManHinhLamViec(){
	VeMenu();
	NoiBatMuc(0, 0, MenuChinh, HIGHTLIGHT, USER_CHAR_SIZE);
}

void KhoiTaoChuongTrinh(){
	initwindow(1920, 1080);
	TaoManHinhLamViec();
	Guild();
}

void NoiBatMuc(int sttMenuChinh, int sttMenuPhu, char menu[][30], int HL_COLOR, int C_SIZE){
	// * Ve cac muc duoc chon
	setbkcolor(HL_COLOR);
	setfillstyle(SOLID_FILL, HL_COLOR);
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT, 0, 2);
	
	// Highlight muc menu chinh
	if (sttMenuPhu == 0){
		bar(ViTriMucMenu[sttMenuChinh]-DIS_MENUX/2, 5, ViTriMucMenu[sttMenuChinh+1]-DIS_MENUX/2, 45);
		outtextxy(ViTriMucMenu[sttMenuChinh], 10, menu[sttMenuChinh]);
		
	}
	//Higlight muc menu phu
	else{
		bar(ViTriMucMenu[sttMenuChinh]-DIS_MENUX/2, 
		50+ViTriMucMenuPhu[sttMenuPhu-1], 
		ViTriMucMenu[sttMenuChinh]-DIS_MENUX/2+KichThuocMenuPhu[sttMenuChinh], 
		50+ViTriMucMenuPhu[sttMenuPhu]);
		outtextxy(ViTriMucMenu[sttMenuChinh], 45+ViTriMucMenuPhu[sttMenuPhu-1]+DIS_MENUY/2, menu[sttMenuPhu-1]);
	}	
}

void Menu(DSDS &ListDausach,  TreeDocgia &docgia){
	// Thao tac trong menu chinh
	int chiMuc = 0;
	NoiBatMuc(chiMuc, 0, MenuChinh, HIGHTLIGHT, USER_CHAR_SIZE);
	while(1)	{
		if(kbhit())	{
			VeMenu();
			char key = getch();
			if (key == 0) {
				char cNext = getch();
				switch(cNext){
					case KEY_LEFT: {
						chiMuc--;
						break;
					}
					case KEY_RIGHT: {
						chiMuc++;
						break;
					}
					case KEY_F9: {
						SaveDs(ListDausach);
						savedocgia(docgia);
						noti(Success[3]);
						delay(1000);
						VeMenu();
						break;
					}
				}
				if (chiMuc == MAX_MENU)
					chiMuc = 0;
				if (chiMuc < 0)
					chiMuc = MAX_MENU-1;
			}
			else if (key == '\r'){
				VeMenu();
				ChonMenuPhu(chiMuc,ListDausach,docgia);
			}
			NoiBatMuc(chiMuc, 0, MenuChinh, HIGHTLIGHT, USER_CHAR_SIZE);
		}
	}
}

void VeMenuPhu(int sttMenuChinh, char menu[][30]){
	int MAX;	//so luong muc trong menu phu
	switch(sttMenuChinh){
		case 0: {
			MAX = 6;
			break;
		}
		case 1: {
			MAX = 5;
			break;
		}
		case 2: {
			MAX = 2;
			break;
		}		
	}
	setbkcolor(HIGHTLIGHTS);
	setfillstyle(SOLID_FILL, HIGHTLIGHTS);
	setusercharsize(1, 2, 1, 2);
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT, 0, 2);
	
	// in nen menu phu
	bar(ViTriMucMenu[sttMenuChinh]-DIS_MENUX/2, 
	50, 
	ViTriMucMenu[sttMenuChinh]-DIS_MENUX/2+KichThuocMenuPhu[sttMenuChinh], 
	70+ViTriMucMenuCuoi[sttMenuChinh]);
	
	// in cac muc menu phu
	for (int i = 0; i < MAX; i++){
		outtextxy(ViTriMucMenu[sttMenuChinh], 45+ViTriMucMenuPhu[i]+DIS_MENUY/2, menu[i]);
	}
}

void MenuPhu(int viTriMenuPhu, char menu[][30], int MAXMENU, int &chonMuc){
	// Thao tac trong menu phu
	chonMuc = 1;
	NoiBatMuc(viTriMenuPhu, chonMuc, menu, HL_MENU_PHU, 2);
	while(1){
		if(kbhit()){
			VeMenuPhu(viTriMenuPhu, menu);
			char key = getch();
			if(key == 0){
				char cNext = getch();
				switch(cNext){
					case KEY_UP:{
						chonMuc--;
						break;
					}
					case KEY_DOWN: {
						chonMuc++;
						break;
					}
					default:{
							VeMenu();
							chonMuc = -1;
							return;
						}
				}
				if (chonMuc > MAXMENU)
					chonMuc = 1;
				if (chonMuc < 1)
					chonMuc = MAXMENU;
			}
			else if (key == '\r'){
				return VeMenu();
			}
			else if (key == 27){
				chonMuc = -1;
				VeMenu();
				return;
			}
			NoiBatMuc(viTriMenuPhu, chonMuc, menu, HL_MENU_PHU, 2);
		}
	}
}

void ChonMenuPhu(int sttMenuChinh, DSDS &ListDausach,TreeDocgia &docgia){
	switch(sttMenuChinh){
		case 0:	return Dausach(ListDausach);
		case 1: return Docgia(docgia, ListDausach);
		case 2:	return Muontra(docgia,ListDausach);
		case 3:	return Thongtin();
		case 4:	return Huongdan();
		default : return;
	}
}

void About(){
	MessageBox(NULL, 
	"Quan ly thu vien\n"
	"Sinh vien:\n"
	"Do Huy Hoang-N19DCCN063 \n",
	"About", MB_APPLMODAL | MB_ICONINFORMATION);
}

void Guild(){ 	
	MessageBox(NULL, 
	"Di chuyen		: Cac phim mui ten.\n"
	"Chon		: Enter.\n"
	"Thoat		: ESC.\n"
	"Luu		: F9.\n"
	"Chuyen trang	: PageUp, PageDown.\n",
	"Huong dan", MB_APPLMODAL | MB_ICONINFORMATION);
}
// in trong thong bao
void noti(char khungNoiDung[]){
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	int H = 100;
	int W = 250;
	setusercharsize(2, 1, 2, 1);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	
	//in thong bao
	setcolor(WHITE);
	setbkcolor(MAU_MENU);
	outtextxy(L+canLeGiua(khungNoiDung, W), U+(H-textheight(khungNoiDung))/2, khungNoiDung);
}

void ThongBao(int x, int y, char noti[50], int mauChu, int mauNen){	
	setbkcolor(mauNen);
	setcolor(mauChu);
	outtextxy(x, y, noti);
	Sleep(DELAY_NOTI);
	setfillstyle(SOLID_FILL, mauNen);
	bar(x, y, x + textwidth(noti), y + textheight(noti));
}

void Dausach(DSDS &ListDausach){
	int thaotac;
	VeMenuPhu(0,Menudausach);
	MenuPhu(0,Menudausach,6,thaotac);
	switch(thaotac){
		case 1:{
			return addDausach(ListDausach);
			break;
		}
		case 2:{
			return XoaDausach(ListDausach);
			break;
		}
		case 3:{
			return chinhSuaDausach(ListDausach);
			break;
		}
		case 4: {
			return TimKiem(ListDausach);
			break;
		}
		case 5:{
			return DanhMucsach(ListDausach);
			break;
		}
		case 6: {
			return Top10sach(ListDausach);
			break;
		}
	}
}

void Docgia(TreeDocgia &docgia, DSDS &dsds){
	int thaotac;
	VeMenuPhu(1,Menudocgia);
	MenuPhu(1,Menudocgia,5,thaotac);
	switch(thaotac){
		case 1: {
			return addDocgia(docgia);
		}
		case 2: {
			return XoaDocgia(docgia);
			break;
		}
		case 3: {
			return chinhSuaDocgia(docgia);
			break;
		}
		case 4: {
			return DanhsachDocgia(docgia);
			break;
		}
		case 5: {
			return DanhsachQuahan(docgia);
			break;
		}
	}
}

void Muontra(TreeDocgia &docgia, DSDS &dsds){
	int thaotac;
	VeMenuPhu(2,Menumuontra);
	MenuPhu(2,Menumuontra,2,thaotac);
	switch(thaotac){
		case 1: {
			return Muonsach(docgia,dsds);
			break;
		}
		case 2: {
			Trasach(docgia, dsds);
			break;
		}
	}
}

void Huongdan(){
	Guild();
}

void Thongtin(){
	About();
}

void InThongTin(int x, int y, char *s){
	setcolor(WHITE);
	setbkcolor(NEN_TEXT);
	outtextxy(x, y, s);
}		
				
void infoText(int x, int y, char noiDung[],char info[],int MauChu){
	setbkcolor(NEN_TEXT);
	setcolor(MauChu);
	outtextxy(x, y, noiDung);
	int dis = 175;	
	outtextxy(x+dis-1, y, info);
}

void veKhung(int x, int y, char noiDung[], bool daChon, int mauNen, int mauChu){
	setbkcolor(NEN_KHUNG);
	setcolor(mauChu);
	outtextxy(x, y, noiDung);
	int H = textheight(noiDung);
	int W = 575;
	int dis = 160;
	
	setfillstyle(SOLID_FILL, NEN_TEXT);
	bar(x+dis, y-H+5, x+W, y+H+10);
	if (daChon)
		setcolor(WHITE);
	else
		setcolor(BLACK);
	 //highligh vien ngoai neu da chon	 
	rectangle(x+dis, y-H+5, x+W, y+H+10);	
}

void veKhungNut(int H, int W, char khungNoiDung[][30], bool Left, bool reset, int n){
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	//tinh kich thuoc khung
	int L =	500;
	int U = 150;
	int R =	1400;
	int D =	850;
	
	
	
	//ve khung duoi
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	// In info khung
	/*setbkcolor(MAU_MENU);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(520, 165, KhungDauSach[0]);*/
	// Vi trí 2 nut cuoi
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	// In 2 nut cuoi
	/*setbkcolor(NEN_KHUNG);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);*/
	
	int MAU_NUT_HL = HL_MENU_PHU;
	if (reset)
			MAU_NUT_HL = NEN_KHUNG;
		
	setfillstyle(SOLID_FILL, MAU_NUT_HL);
	if (Left){
		bar (L, D-kichThuocNut, WD_WIDTH/2, D);
		setbkcolor(MAU_NUT_HL);
		setcolor(WHITE);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
		setbkcolor(NEN_KHUNG);
		outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[n+1]);
	} else{
		bar (WD_WIDTH/2, D-kichThuocNut, R, D);
		setcolor(WHITE);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
		setbkcolor(MAU_NUT_HL);
		outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[n+1]);
	}
	
	setcolor(BLACK);
	rectangle(L,D-kichThuocNut,WD_WIDTH/2,D);
	rectangle(WD_WIDTH/2,D-kichThuocNut,R,D);						//center line
	
}

void VeKhungthemDausach(char KhungNoiDung[][30], DSDS &listtmp, struct Dausach *tmp, bool &selected){
	selected = false;
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	// Kich thuoc khung
	int L =	500;
	int U = 150;
	int R =	1400;
	int D =	850;
	
	int H = 450;
	int W = 600;
	// Ve khung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(L,U,R,D);
	//	Ve khung info
	setbkcolor(MAU_NEN);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar(L,U,R,U+kichThuocSTT);
	
	// Ve vien khung
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L,U+kichThuocSTT,R,U+kichThuocSTT);
	rectangle(L,U,R,D);
	rectangle(L,D-kichThuocNut,WD_WIDTH/2,D);
	rectangle(WD_WIDTH/2,D-kichThuocNut,R,D);
	// In info khung
	setbkcolor(MAU_MENU);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(520, 165, KhungDauSach[0]);
	// Vi trí 2 nut cuoi
	int midText1 = ((R-L)/2 - textwidth(KhungDauSach[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(KhungDauSach[2]))/2;
	int midTextH = (kichThuocNut - textheight(KhungDauSach[1]))/2 + textheight(KhungDauSach[1]);
	setcolor(WHITE);
	// In 2 nut cuoi
	setbkcolor(NEN_KHUNG);
	outtextxy(L+midText1, D-midTextH, KhungDauSach[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, KhungDauSach[2]);
	// 
	int pos=1;
	int Soluongkhung=6;
	for (int i = 1; i <= Soluongkhung; i++){
		if (i == 1){
			veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 1, NEN_KHUNG, WHITE);
			
		} else{
			veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 0, NEN_KHUNG, WHITE);
		}
	}
		/*char tmpnxb[5];
		char tmpst[8];*/
	struct DetailDS{
	char tmpnxb[5];
	char tmpst[10];
	DetailDS(){
		tmpnxb[0] = '\0';
		tmpst[0] = '\0';
	}
	};
DetailDS tmpDS;	
	//===== Chon vi tri ======//
	while(1){
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
							pos--;
							break;
						}
					case KEY_DOWN:{
							pos++;
							break;
						}
				}
				cpos:
				if (pos == 0)
					pos = 7;
				if (pos > 7){
						pos = 1;
				}
			}
			else if (key == '\r'){
				if (pos <= 6)  //enter xuong o moi
					pos++;
//				else
//					return;
			}
			else if (key == 27){
				VeMenu();
				return;
			}
			
			
			for (int i = 1; i <= Soluongkhung; i++){
				veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 0, NEN_TEXT, WHITE);
			}
				
			
			setbkcolor(NEN_TEXT);
				InThongTin(830, ViTriKhungDauSach[1], tmp->ISBN);
				InThongTin(830, ViTriKhungDauSach[2], tmp->Tensach);
				InThongTin(830, ViTriKhungDauSach[3], tmpDS.tmpst);
				InThongTin(830, ViTriKhungDauSach[4], tmp->Tacgia);
				InThongTin(830, ViTriKhungDauSach[5], tmpDS.tmpnxb);
				InThongTin(830, ViTriKhungDauSach[6], tmp->Theloai);
				
				
			//===di chuyen trong menu===//
			switch(pos){
				case 1:{
						veKhung(650, 250, KhungDauSach[3], 1, NEN_TEXT, WHITE);
						Nhap(830,250,-1, key, tmp->ISBN,14);
						break;
					}
				case 2:{
						veKhung(650, 340, KhungDauSach[4], 1, NEN_TEXT, WHITE);
						Nhap(830,340,2, key, tmp->Tensach, 31);
						break;
					}
				case 3:{
						veKhung(650, 430, KhungDauSach[5], 1, NEN_TEXT, WHITE);
						Nhap(830,430,0, key, tmpDS.tmpst,9);
						break;
					}
				case 4:{
						veKhung(650, 520, KhungDauSach[6], 1, NEN_TEXT, WHITE);
						Nhap(830,520,2, key, tmp->Tacgia,27);
						break;
					}
				case 5:{
						veKhung(650, 610, KhungDauSach[7], 1, NEN_TEXT, WHITE);
						Nhap(830,610,1, key, tmpDS.tmpnxb,4);
						break;
				}
				case 6:{
						veKhung(650, 700, KhungDauSach[8], 1, NEN_TEXT, WHITE);
						Nhap(830,700,2, key, tmp->Theloai,24);
						break;
				}
				case 7:	{
						// Them dau sach
					
						bool buttonL = 1;
						veKhungNut(H, W, KhungNoiDung, buttonL, 0,1);
						while(1){
							if(kbhit())	{
								char key5 = getch();
								char c5Next;
								if (key5 == 0){
									c5Next = getch();
									switch(c5Next){
										case KEY_UP:{
												pos--;
												veKhungNut(H, W, KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_DOWN:{
												pos++;
												veKhungNut(H, W, KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_LEFT:{
												buttonL ^= 1;
												break;
											}
										case KEY_RIGHT:{
												buttonL ^= 1;
												break;
											}
									}
								}
								else if (key5 == '\r'){
									//return;
									if (buttonL == 1){
											
										if(strlen(tmp->ISBN)!=0 && strlen(tmpDS.tmpnxb)!=0 && strlen(tmpDS.tmpst)!=0 && strlen(tmp->Tacgia)!=0 && strlen(tmp->Tensach)!=0 && strlen(tmp->Theloai)!=0)
										{ 	tmp->Namxb = ChangeCharToNum(tmpDS.tmpnxb);
											if( tmp->Namxb > getyearsystem()){
												ThongBao(900, 165, Fail[10], LIGHTRED, MAU_MENU);
											} else {
												selected = true;
												tmp->Namxb = ChangeCharToNum(tmpDS.tmpnxb);
												tmp->Sotrang = ChangeCharToNum(tmpDS.tmpst);
												return;
											}
											
										}
										else{
											ThongBao(1150, 165, Fail[0], LIGHTRED, MAU_MENU);
										}
									}
									else{
										VeMenu();
										return;
									}
								}
								else if (key5 == 27){
									VeMenu();
									return;
								}
								veKhungNut(H, W, KhungNoiDung, buttonL, 0,1);
							}
						}
					}
				}
			}
		}
}

void addDausach(struct DS_Dausach &ListDausach){
	bool entered = false;
	do{
		struct Dausach *tmpD = new struct Dausach;
		VeKhungthemDausach(KhungDauSach,ListDausach, tmpD,entered);
		if(entered){
			if (isFull(ListDausach)){
				ThongBao(1150, 165, Fail[8], GREEN, MAU_MENU);
			}
			else{
				if (ListDausach.searchIsbn(tmpD->ISBN) == -1){
					Insert(ListDausach,tmpD);
					ThongBao(1150, 165, Success[0], GREEN, MAU_MENU);
				} else {
					ThongBao(1200, 165, Fail[4],LIGHTRED, MAU_MENU);
				}
			}	
		}
	}while(entered);
	VeMenu();
	
	
}

void showPage(int x, int y, int page, int limit){
	//  Page: page / limit
	setcolor(MAU_TEXT_KHUNG);
	setbkcolor(MAU_NEN);
	outtextxy(x, y, "Trang: ");
	x += textwidth("Trang: ");
	
	outtextxy(x, y, toChars(page));
	x += textwidth(toChars(page));
	
	outtextxy(x, y, " / ");
	x += textwidth(" / ");	
	
	outtextxy(x, y, toChars(limit));
}

void  VeKhungxoaDausach(char khungNoiDung[][30],  bool &list, char *findID, bool &selected){
	
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
		
	// Kich thuoc khung
	int L =	470;
	int U = 300;
	int R =	1430;
	int D =	515;
	
	int H = 450;
	int W = 600;

	//Ve cac khung ban dau===
	selected = false;
	bool choice = 1;
	bool chooseL = 1; 
	int posR = 1;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	setcolor(BLACK);
	rectangle(L-1, U-1, R+1, D+1);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[3]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[4]))/2;
	int midText3 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[2]);
	setcolor(WHITE);
	
	
	rectangle(L+14, ViTriKhung[3]-21, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+20+textheight(khungNoiDung[0]));
	// ve khung chon id
	setbkcolor(HL_MENU_PHU);
	setfillstyle(SOLID_FILL, HL_MENU_PHU);
	bar (L+15, ViTriKhung[3]-20, WD_WIDTH/2, ViTriKhung[3]+20+textheight(khungNoiDung[0]));
	outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, WD_WIDTH/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, WD_WIDTH/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0])); // khung nhap
	
	// ve khung chon list
	setbkcolor(NEN_KHUNG);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(WD_WIDTH/2, ViTriKhung[3]-20, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+20+ textheight(khungNoiDung[0]));
	outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[2]);	
	setfillstyle(SOLID_FILL, HL_MENU_PHU);	
	
	// 2 nut check and exit
	outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
	//make ur choice
	
	findID[0] = '\0';
	while(1)
	{
		InThongTin(L+35+2*textwidth(khungNoiDung[0]),ViTriKhung[3],findID);
		if(kbhit())
		{
			char keyR = getch();
			if(keyR==0)
			{
				char ckeyR = getch();
				switch(ckeyR)
				{
					case KEY_LEFT:
					{
						if(posR==1)
							choice ^= 1; // 1: trai 0: phai
						if(posR==2)
							chooseL ^= 1;	
						break;
					}
					case KEY_RIGHT:
					{
						if(posR==1)
							choice ^= 1; // 1: trai 0: phai
						if(posR==2)
							chooseL ^= 1;	
						break;
					}
					case KEY_UP:
					{
						if(posR == 1)
						{
							posR = 2;
							chooseL = true;
							break;
						}
						else
						{
							posR = 1;
							//choice = true;
							break;
						}		
					}
					case KEY_DOWN:
					{
						if(posR == 1)
						{
							posR = 2;
							chooseL = true;
							break;
						}
						else
						{
							posR = 1;
							//choice = true;
							break;
						}	
					}	
				}
			}
			if(keyR == '\r')
			{
				if(posR == 1)
				{
					posR = 2;
					chooseL = 1;
				}
				else
				{
					if(chooseL)
					{
						if(choice == 1)
						{
							list = false;
							selected = true;
							return;
						}
						else
						{
							list = true;
							selected = true;
							return;
						}
					}
					else
					{
						VeMenu();
						return;
					}
				}
			}
			if(keyR == 27)
			{
				VeMenu();
				return;
			}
			// hien thi
			if(posR == 1)	//ID/list
			{
				setcolor(WHITE);
				setfillstyle(SOLID_FILL, NEN_KHUNG);
				if(choice)
				{
					// ID
					setbkcolor(NEN_KHUNG);
					bar(WD_WIDTH/2, ViTriKhung[3]-20, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+20+ textheight(khungNoiDung[0]));
					outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[2]);
					setbkcolor(HL_MENU_PHU);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);									//do mau nen cho nut
					bar (L+15, ViTriKhung[3]-20,WD_WIDTH/2 , ViTriKhung[3]+20+ textheight(khungNoiDung[0]));
					outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
					setfillstyle(SOLID_FILL, TEXTBOX);
					bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, WD_WIDTH/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
					rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, WD_WIDTH/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
					Nhap(L+35+2*textwidth(khungNoiDung[0]),ViTriKhung[3],-1,keyR,findID,10);
				}
				else
				{
					// list
					setbkcolor(NEN_KHUNG);
					bar (L+15, ViTriKhung[3]-20,WD_WIDTH/2 , ViTriKhung[3]+20+ textheight(khungNoiDung[0]));
					outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
					setfillstyle(SOLID_FILL, TEXTBOX);
					bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-20, WD_WIDTH/2-15, ViTriKhung[3]+20+ textheight(khungNoiDung[0]));
					rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, WD_WIDTH/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
					setbkcolor(HL_MENU_PHU);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar(WD_WIDTH/2, ViTriKhung[3]-20, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+20+ textheight(khungNoiDung[0]));
					outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[2]);
				}
				
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, NEN_KHUNG);
				bar (L, D-kichThuocNut, WD_WIDTH/2, D);
				bar (WD_WIDTH/2, D-kichThuocNut, R, D);				
				setbkcolor(NEN_KHUNG);
				line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
				setcolor(WHITE);
				outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
				outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
			}
			else	//check/exit
			{
				setcolor(WHITE);
				setfillstyle(SOLID_FILL, NEN_KHUNG);	
				if(chooseL) //check
				{	
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
					setbkcolor(NEN_KHUNG);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
				}
				else	//exit
				{
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
					setbkcolor(NEN_KHUNG);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
				}
				setcolor(BLACK);
				line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
			}		
		}
	}
}

void XoaIsbn(DSDS &dsds, char khungNoiDung[][30], int H, int W, struct Dausach *Info){
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	// Kich thuoc khung
	int L =	500;
	int U = 150;
	int R =	1400;
	int D =	850;
	
	/*int H = 450;
	int W = 600;*/
	// Ve khung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(L,U,R,D);
	//	Ve khung info
	setbkcolor(MAU_NEN);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar(L,U,R,U+kichThuocSTT);
	
	// Ve vien khung
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L,U+kichThuocSTT,R,U+kichThuocSTT);
	rectangle(L,U,R,D);
	rectangle(L,D-kichThuocNut,WD_WIDTH/2,D);
	rectangle(WD_WIDTH/2,D-kichThuocNut,R,D);
	// In info khung
	setbkcolor(MAU_MENU);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(520, 165, KhungDauSach[0]);
	//
	//Ve cac khung ban dau===
	int pos=1;
	int Soluongkhung=6;
	for (int i = 1; i <= Soluongkhung; i++){
		veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 0, NEN_KHUNG, WHITE);
	}
	
	
	//info
	char tmpst[8];
	char tmpnxb[5];
	strcpy(tmpst,toChars(Info->Sotrang));
	strcpy(tmpnxb,toChars(Info->Namxb));
	
	InThongTin(830, ViTriKhungDauSach[1], Info->ISBN);
	InThongTin(830, ViTriKhungDauSach[2], Info->Tensach);
	InThongTin(830, ViTriKhungDauSach[3], tmpst);
	InThongTin(830, ViTriKhungDauSach[4], Info->Tacgia);
	InThongTin(830, ViTriKhungDauSach[5], tmpnxb);
	InThongTin(830, ViTriKhungDauSach[6], Info->Theloai);
	bool buttonL = 1;
	veKhungNut(H, W, khungNoiDung, buttonL, 0, 1);
	while(1){
		if(kbhit()){
			char key = getch();
			if(key==0){
				char ckey = getch();
				switch(ckey){
					case KEY_LEFT:{
						buttonL ^= 1;
						break;
					}
					case KEY_RIGHT:	{
						buttonL ^= 1;
						break;
					}
				}
			}
			else if(key == '\r'){
				if(buttonL){
					DeleteISBN(dsds,Info->ISBN);
					ThongBao(1150, 165, Success[1], GREEN, MAU_MENU);
				}
				VeMenu();
				return;
			}
			else if(key==27){
		 		VeMenu();
			 	return;
			}
			veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
		}
	}
}

void inDausach(struct Dausach *ds, int posX, int posY, bool mode){
	char tmpst[10];
	char tmpnxb[5];
	strcpy(tmpst,toChars(ds->Sotrang));
	strcpy(tmpnxb,toChars(ds->Namxb));
	// in ISBN
	outtextxy(posX + canLeGiua(ds->ISBN, textwidth(danhSachDausach[1])+sizeDanhSachDausach[1]*2), posY, ds->ISBN);
	posX += textwidth(danhSachDausach[1]) + sizeDanhSachDausach[1]*2;
	
	// in ten sach
	outtextxy(posX + 10, posY, ds->Tensach);
	posX += textwidth(KhungDauSach[2]) + sizeDanhSachDausach[2]*2;
	
	// in so trang
	outtextxy(posX + 70, posY, tmpst);
	posX += textwidth(KhungDauSach[3]) + sizeDanhSachDausach[3]*2;
	// in tac gia
	outtextxy(posX + 100, posY, ds->Tacgia);
	posX += textwidth(KhungDauSach[4]) + sizeDanhSachDausach[3]*2;
	// in nxb
	outtextxy(posX + 240, posY, tmpnxb);
	posX += textwidth(KhungDauSach[5]) + sizeDanhSachDausach[3]*2;
	// in the loai
	outtextxy(posX + 250, posY, ds->Theloai);
	posX += textwidth(KhungDauSach[6]) + sizeDanhSachDausach[3]*2;
	if(!mode){
		char tmpslm[10];
		strcpy(tmpslm, toChars(ds->Solanmuon));
		outtextxy(posX + 420, posY, tmpslm);
		posX += textwidth(KhungDauSach[6]) + sizeDanhSachDausach[3]*2;
	}
}

void inTrangDausach(DSDS &dsds, char khungNoiDung[][30], int sizeKhungNoiDung[], int start){
	int kichThuocSTT = 40;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 7; i++){
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	}
	
	//tinh kich thuoc khung
	int L =	350;
	int U = 100;
	int R =	1510;
	int D =	870;
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	
	settextstyle(COMPLEX_FONT, 0, 2);
	int dis = L;
	for (int i = 0; i < 7; i++){
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 22; i++){
		dis += h+10;
		line(L, dis, R, dis);
	}
	
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = dsds.n;
	for (int i = start; i < min(start+OBJ_PER_PAGE, Size); i++){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		
		dsds.sort(true);
		inDausach(dsds.nodes[i], disW, dis, 1);
		dis += h+5;
	}
	
	setbkcolor(MAU_NEN);
}

void chonTuDanhSach(DSDS &dsds, int &stt, int &startPage, bool &selected){	
	//in danh sach
	//int startPage = 1;
	selected = false;
	int limitPage = ceil(dsds.n*1.0/OBJ_PER_PAGE); // lam tron so 
	if (limitPage == 0){
		noti(Fail[2]);
	}
	else{
		// tinh thong so
		int kichThuocSTT = 40;
		int h = textheight(danhSachDausach[0])+10;
		int H = (h)*OBJ_PER_PAGE + kichThuocSTT;
		
		int W=1160;
		int U = 100;
		int L =	350;
		
		int x = 350, 
			y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
		int yOld = y;
		/*int L =	350;
		int U = 100;
		int R =	1510;
		int D =	895;*/
				
		inTrangDausach(dsds, danhSachDausach, sizeDanhSachDausach, (startPage-1)*OBJ_PER_PAGE);
		showPage(1370, 880, startPage, limitPage);
		
		setcolor(GREEN);
		rectangle(x, y, x+W, y+h);
		while(1){
			if(kbhit())	{
				char key = getch();
				if (key == 0){
					char nextK = getch();
					switch(nextK){
						case KEY_PGDN:{
								startPage--;
								if (startPage < 1)
									startPage = limitPage;
								inTrangDausach(dsds, danhSachDausach, sizeDanhSachDausach, (startPage-1)*OBJ_PER_PAGE);
								showPage(1370, 880, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_PGUP:{
								startPage++;
								if (startPage > limitPage)
									startPage = 1;
								inTrangDausach(dsds, danhSachDausach, sizeDanhSachDausach, (startPage-1)*OBJ_PER_PAGE);
								showPage(1370, 880, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_UP:{
								stt--;
								break;
							}
						case KEY_DOWN:{
								stt++;
								break;
							}
					}
					if (stt < (startPage-1)*OBJ_PER_PAGE)
						stt = min((startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1), dsds.n-1);
					else if (stt > (startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1) || stt > dsds.n-1)
						stt = (startPage-1)*OBJ_PER_PAGE;
						
					y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
					// to den hinh chu nhat cu
					setcolor(BLACK);
					rectangle(x, yOld, x+W, yOld+h);
					// ve hinh chu nhat moi
					setcolor(GREEN);
					rectangle(x, y, x+W, y+h);
					yOld = y;
				}
				else if (key == 27){ //exit
					VeMenu();
					return;
				}
				else if (key == '\r'){
					selected = true;
					return;
				}
			}
		}
	}
}

void DanhsachxoaDausach(DSDS &dsds){
	//sortEmp(ListEmployees.nodeListEmp, 0, ListEmployees.n-1);
	
	int removePos = 0;
	int page = 1;
	bool select;
	struct Dausach *tmp;
				
	while(1){
		chonTuDanhSach(dsds, removePos, page, select);
		if(select){
			tmp = dsds.Search_ISBN(dsds.nodes[removePos]->ISBN);
			XoaIsbn(dsds, checkDS, 450, 600, tmp);
//			DeleteDs(dsds,removePos);
		}
		else{
			break;
		}
	}
	VeMenu();
}	

void XoaDausach(struct DS_Dausach &ListDausach){
	bool entered = false;
	do
	{
		bool chooseList = false;
		char tmpISBN[15];
		VeKhungxoaDausach(KhungXoa, chooseList, tmpISBN, entered);
		if (entered){
			if (chooseList){
				return DanhsachxoaDausach(ListDausach);
			}
			else{
				struct Dausach *tmp;
				tmp = ListDausach.Search_ISBN(tmpISBN);
				if(tmp == NULL){
					//loi ko ton tai
					ThongBao(1180, 310, Fail[1], LIGHTRED, MAU_MENU);
				}
				else{	
					XoaIsbn(ListDausach, checkDS, 450, 600, tmp);
				}
			}
		}
	}while(entered);
}

void chinhThongTinDS(char khungNoiDung[][30], struct Dausach *tmp){
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	// Kich thuoc khung
	int L =	500;
	int U = 150;
	int R =	1400;
	int D =	850;
	
	int H = 450;
	int W = 600;
	// Ve khung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(L,U,R,D);
	//	Ve khung info
	setbkcolor(MAU_NEN);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar(L,U,R,U+kichThuocSTT);
	
	// Ve vien khung
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L,U+kichThuocSTT,R,U+kichThuocSTT);
	rectangle(L,U,R,D);
	rectangle(L,D-kichThuocNut,WD_WIDTH/2,D);
	rectangle(WD_WIDTH/2,D-kichThuocNut,R,D);
	// In info khung
	setbkcolor(MAU_MENU);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(520, 165, KhungDauSach[0]);
	// Vi trí 2 nut cuoi
	int midText1 = ((R-L)/2 - textwidth(KhungDauSach[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(KhungDauSach[2]))/2;
	int midTextH = (kichThuocNut - textheight(KhungDauSach[1]))/2 + textheight(KhungDauSach[1]);
	setcolor(WHITE);
	// In 2 nut cuoi
	setbkcolor(NEN_KHUNG);
	outtextxy(L+midText1, D-midTextH, KhungDauSach[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, KhungDauSach[2]);
	// 
	int pos=2;
	int Soluongkhung=6;
	for (int i = 1; i <= Soluongkhung; i++){
		if (i == 1){
//			veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 1, NEN_KHUNG, WHITE);
				setbkcolor(NEN_KHUNG);
				setcolor(WHITE);
				outtextxy(650, 250, KhungDauSach[3]);
				int H = textheight(KhungDauSach[3]);
				int W = 575;
				int dis = 160;
				
				setfillstyle(SOLID_FILL, NEN_TEXT);
				bar(650+dis, 255-H, 650+W, 260+H);
					setcolor(BLACK);
				 //highligh vien ngoai neu da chon	 
				rectangle(650+dis, 255-H, 650+W, 260+H);
			
		} else {
			if (i==2){
			veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 1, NEN_KHUNG, WHITE);
			} else {
			veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 0, NEN_KHUNG, WHITE);
			}
		
		}
	}
//	in thong tin
			char tmptensach[30];
			char tmptg[25];
			char tmptl[30];
			char tmpst[10];
			char tmpnxb[5];
			
			strcpy(tmpst,toChars(tmp->Sotrang));
			strcpy(tmpnxb,toChars(tmp->Namxb));	
			strcpy(tmptensach, tmp->Tensach);
			strcpy(tmptg, tmp->Tacgia);
			strcpy(tmptl, tmp->Theloai);

			InThongTin(830, ViTriKhungDauSach[1], tmp->ISBN);
			InThongTin(830, ViTriKhungDauSach[2], tmptensach);
			InThongTin(830, ViTriKhungDauSach[3], tmpst);
			InThongTin(830, ViTriKhungDauSach[4], tmptg);
			InThongTin(830, ViTriKhungDauSach[5], tmpnxb);
			InThongTin(830, ViTriKhungDauSach[6], tmptl);		
	//===== Chon vi tri ======//
	while(1){
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
							pos--;
							break;
						}
					case KEY_DOWN:{
							pos++;
							break;
						}
				}
				cpos:
				if (pos == 1)
					pos = 7;
				if (pos > 7){
						pos = 2;
				}
			}
			else if (key == '\r'){
				if (pos <= 6)  //enter xuong o moi
					pos++;
//				else
//					return;
			}
			else if (key == 27){
				VeMenu();
				return;
			}
			
			
			for (int i = 1; i <= Soluongkhung; i++){
				veKhung(650, ViTriKhungDauSach[i], KhungDauSach[i+2], 0, NEN_TEXT, WHITE);
			}
			setbkcolor(NEN_TEXT);
				
				/*strcpy(tmpDS.tMpst,toChars(tmp->Sotrang));
				strcpy(tmpDS.tMpnxb,toChars(tmp->Namxb));*/
														
				InThongTin(830, ViTriKhungDauSach[1], tmp->ISBN);
				InThongTin(830, ViTriKhungDauSach[2], tmptensach);
				InThongTin(830, ViTriKhungDauSach[3], tmpst);
				InThongTin(830, ViTriKhungDauSach[4], tmptg);
				InThongTin(830, ViTriKhungDauSach[5], tmpnxb);
				InThongTin(830, ViTriKhungDauSach[6], tmptl);
			//===di chuyen trong menu===//
			switch(pos){
				
				case 1:{
						veKhung(650, 250, KhungDauSach[3], 1, NEN_TEXT, WHITE);
						InThongTin(830, ViTriKhungDauSach[1], tmp->ISBN);
						break;
					}
				case 2:{
						veKhung(650, 340, KhungDauSach[4], 1, NEN_TEXT, WHITE);
						Nhap(830,340,2, key, tmptensach, 29);
						break;
					}
				case 3:{
						veKhung(650, 430, KhungDauSach[5], 1, NEN_TEXT, WHITE);
						Nhap(830,430,0, key, tmpst,9);
						break;
					}
				case 4:{
						veKhung(650, 520, KhungDauSach[6], 1, NEN_TEXT, WHITE);
						Nhap(830,520,2, key, tmptg,24);
						break;
					}
				case 5:{
						veKhung(650, 610, KhungDauSach[7], 1, NEN_TEXT, WHITE);
						Nhap(830,610,1, key, tmpnxb,4);
						break;
				}
				case 6:{
						veKhung(650, 700, KhungDauSach[8], 1, NEN_TEXT, WHITE);
						Nhap(830,700,2, key, tmptl,24);
						break;
				}
				case 7:	{
						// Them dau sach
						bool buttonL = 1;
						veKhungNut(H, W, KhungNoiDung, buttonL, 0,1);
						while(1){
							if(kbhit())	{
								char key5 = getch();
								char c5Next;
								if (key5 == 0){
									c5Next = getch();
									switch(c5Next){
										case KEY_UP:{
												pos--;
												veKhungNut(H, W, KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_DOWN:{
												pos++;
												veKhungNut(H, W, KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_LEFT:{
												buttonL ^= 1;
												break;
											}
										case KEY_RIGHT:{
												buttonL ^= 1;
												break;
											}
									}
								}
								else if (key5 == '\r'){
									//return;
									if (buttonL == 1){
										if(strlen(tmp->ISBN)!=0 && strlen(tmpnxb)!=0 && strlen(tmpst)!=0 && strlen(tmptg)!=0 && strlen(tmptensach)!=0 && strlen(tmptl)!=0){
											tmp->Namxb = ChangeCharToNum(tmpnxb);
											tmp->Sotrang = ChangeCharToNum(tmpst);
											strcpy(tmp->Tensach, tmptensach);
											strcpy(tmp->Tacgia, tmptg);
											strcpy(tmp->Theloai, tmptl);
											ThongBao(1140, 165, Success[2], GREEN, MAU_MENU);
											return;
										}
										else{
											ThongBao(1150, 165, Fail[0], LIGHTRED, MAU_MENU);
										}
									}
									else{
										VeMenu();
										return;
									}
								}
								else if (key5 == 27){
									VeMenu();
									return;
								}
								veKhungNut(H, W, KhungNoiDung, buttonL, 0,1);
							}
						}
					}
				}
			}
		}
}

void danhSachchinhthongtinDs(DSDS &dsds){
	int choosePos = 0;
	int page = 1;
	bool select;
	while(1){
		chonTuDanhSach(dsds, choosePos, page, select);
		if(select){
			struct Dausach *tmpD;
			tmpD = dsds.nodes[choosePos];
			chinhThongTinDS(KhungDauSach,tmpD);
		}
		else{
			break;
		}
	}
	VeMenu();
}

void chinhSuaDausach(DSDS &ListDausach){
	bool entered = false;
	do{
		bool chooseList = false;
		char tmpISBN[15];
		VeKhungxoaDausach(KhungXoa,  chooseList, tmpISBN, entered);
		if (entered){
			if (chooseList){
				return danhSachchinhthongtinDs(ListDausach);
			}
			else{
				struct Dausach *tmpD;
				tmpD = ListDausach.Search_ISBN(tmpISBN);
				if(tmpD == NULL){
					//loi ko ton tai
					ThongBao(1180, 310, Fail[1], LIGHTRED, MAU_MENU);
				}
				else{	
					chinhThongTinDS(KhungDauSach, tmpD);
				}
			}
			VeMenu();
		}
	}while(entered);
}

void Top10sach(DSDS &ListDausach){
	int kichThuocSTT = 40;
	int h = textheight(danhSachDausach[0]);
	int H = (h+5*2)*10 + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 8; i++){
		W += textwidth(danhSachDausach[i]) + sizeDanhSachDausach[i]*2;
	}
	
	//tinh kich thuoc khung
	int L =	270;
	int U = 200;
	int R =	1610;
	int D =	570;
	
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	
	settextstyle(COMPLEX_FONT, 0, 2);
	int dis = L;
	for (int i = 0; i < 8; i++){
		dis += sizeDanhSachDausach[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, danhSachDausach[i]);
		dis += textwidth(danhSachDausach[i]) + sizeDanhSachDausach[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 10; i++){
		dis += h+10;
		line(L, dis, R, dis);
	}
	
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
//	int Size = dsds.n;
	for (int i = 0; i < 10; i++){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(danhSachDausach[0])+sizeDanhSachDausach[0]*2), dis, d);
		disW += textwidth(danhSachDausach[0]) + sizeDanhSachDausach[0]*2;
		
		ListDausach.sort(false);
		inDausach(ListDausach.nodes[i], disW, dis,0);
		
		dis += h+5;
	}
	
	setbkcolor(MAU_NEN);
} 
// Search theo ten sach
void Insach(DSDS &dsds, char khungNoiDung[][30], int sizeKhungNoiDung[], int addpos);
void inthongtinDS(DSDS &dsds, char khungNoiDung[][30], struct Dausach tmp);

void veKhungNutthongtin(char khungNoiDung[][30], bool Left, bool reset, int n){
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	//tinh kich thuoc khung
	int L =	250;
	int U = 150;
	int R =	1050;
	int D =	850;

	//ve khung duoi
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	// In info khung

	// Vi trí 2 nut cuoi
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	
	int MAU_NUT_HL = HL_MENU_PHU;
	if (reset)
			MAU_NUT_HL = NEN_KHUNG;
		
	setfillstyle(SOLID_FILL, MAU_NUT_HL);
	if (Left){
		bar (L, D-kichThuocNut, (L+R)/2, D);
		setbkcolor(MAU_NUT_HL);
		setcolor(WHITE);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
		setbkcolor(NEN_KHUNG);
		outtextxy((L+R)/2+midText2, D-midTextH, khungNoiDung[n+1]);
	} else{
		bar ((L+R)/2, D-kichThuocNut, R, D);
		setcolor(WHITE);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
		setbkcolor(MAU_NUT_HL);
		outtextxy((L+R)/2+midText2, D-midTextH, khungNoiDung[n+1]);
	}
	
	setcolor(BLACK);
	rectangle(L,D-kichThuocNut,(L+R)/2,D);
	rectangle((L+R)/2,D-kichThuocNut,R,D);						//center line
	
}

void inDausach1(struct Dausach ds, int posX, int posY){
	char tmpst[10];
	char tmpnxb[5];
	strcpy(tmpst,toChars(ds.Sotrang));
	strcpy(tmpnxb,toChars(ds.Namxb));
	// in ISBN
	outtextxy(posX + canLeGiua(ds.ISBN, textwidth(danhSachDausach[1])+sizeDanhSachDausach[1]*2), posY, ds.ISBN);
	posX += textwidth(danhSachDausach[1]) + sizeDanhSachDausach[1]*2;
	
	// in ten sach
	outtextxy(posX + 10, posY, ds.Tensach);
	posX += textwidth(KhungDauSach[2]) + sizeDanhSachDausach[2]*2;
	
	// in so trang
	outtextxy(posX + 70, posY, tmpst);
	posX += textwidth(KhungDauSach[3]) + sizeDanhSachDausach[3]*2;
	// in tac gia
	outtextxy(posX + 100, posY, ds.Tacgia);
	posX += textwidth(KhungDauSach[4]) + sizeDanhSachDausach[3]*2;
	// in nxb
	outtextxy(posX + 240, posY, tmpnxb);
	posX += textwidth(KhungDauSach[5]) + sizeDanhSachDausach[3]*2;
	// in the loai
	outtextxy(posX + 250, posY, ds.Theloai);
	posX += textwidth(KhungDauSach[6]) + sizeDanhSachDausach[3]*2;
}

void inTrangDausach1(DSDS &dsds, char khungNoiDung[][30], int sizeKhungNoiDung[], int start, char *ten){
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(WHITE);
	setbkcolor(HIGHTLIGHTS);
	setfillstyle(SOLID_FILL, HIGHTLIGHTS);
	bar (510,70,1140,130);
	outtextxy(530, 88, "Nhap ten sach");
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (710,75,1130,125);
	rectangle(510,70,1140,130);
	InThongTin(730,85, ten);
	
	int kichThuocSTT = 40;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE_dms + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 7; i++){
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	}
	//tinh kich thuoc khung
	int L =	350;
	int U = 150;
	int R =	1510;
	int D =	850;
	
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	
	settextstyle(COMPLEX_FONT, 0, 2);
	int dis = L;
	for (int i = 0; i < 7; i++){
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 20; i++){
		dis += h+10;
		line(L, dis, R, dis);
	}
	
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = dsds.Arrds.n;
	for (int i = start; i < min(start+OBJ_PER_PAGE_dms, Size); i++){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		inDausach1(dsds.Arrds.arr[i], disW, dis);
		dis += h+5;
	}
	setbkcolor(MAU_NEN);
}

void chonTuDanhSach1(DSDS &dsds, int &stt, int &startPage, bool &selected, char *ten){	
	// Khung tim kiem
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(WHITE);
	setbkcolor(HIGHTLIGHTS);
	setfillstyle(SOLID_FILL, HIGHTLIGHTS);
	bar (510,70,1140,130);
	outtextxy(530, 85, "Nhap ten sach");
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (710,75,1130,125);
	rectangle(510,70,1140,130);
	InThongTin(730,85, ten);
	int choosepos;
	//in danh sach
	selected = false;
	int limitPage = ceil(dsds.Arrds.n*1.0/OBJ_PER_PAGE_dms); // lam tron so 
	if (limitPage == 0){
		return TimKiem(dsds);
	}
	else{
		// tinh thong so
		int kichThuocSTT = 40;
		int h = textheight(danhSachDausach[0])+10;
		int H = (h)*OBJ_PER_PAGE + kichThuocSTT;
		
		int W=1160;
		int U = 150;
		int L =	350;
		
		int x = 350, 
			y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
		int yOld = y;
		/*int L =	350;
		int U = 100;
		int R =	1510;
		int D =	895;*/
				
		inTrangDausach1(dsds, danhSachDausach, sizeDanhSachDausach, (startPage-1)*OBJ_PER_PAGE_dms, ten);
		showPage(1370, 870, startPage, limitPage);
		
		setcolor(GREEN);
		rectangle(x, y, x+W, y+h);
		int pos = 1;
		while(1){
			if(kbhit())	{
				char key = getch();
				if (key == 0){
					char nextK = getch();
					switch(nextK){
						case KEY_PGDN:{
								startPage--;
								if (startPage < 1)
									startPage = limitPage;
								inTrangDausach1(dsds, danhSachDausach, sizeDanhSachDausach, (startPage-1)*OBJ_PER_PAGE_dms, ten);
								showPage(1370, 870, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE_dms;
								break;
							}
						case KEY_PGUP:{
								startPage++;
								if (startPage > limitPage)
									startPage = 1;
								inTrangDausach1(dsds, danhSachDausach, sizeDanhSachDausach, (startPage-1)*OBJ_PER_PAGE_dms, ten);
								showPage(1370, 870, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE_dms;
								break;
							}
						case KEY_UP:{
								stt--;
								break;
							}
						case KEY_DOWN:{
								stt++;
								break;
							}
					}
					if (stt < (startPage-1)*OBJ_PER_PAGE)
						stt = min((startPage-1)*OBJ_PER_PAGE_dms+(OBJ_PER_PAGE_dms-1), dsds.Arrds.n-1);
					else if (stt > (startPage-1)*OBJ_PER_PAGE_dms+(OBJ_PER_PAGE_dms-1) || stt > dsds.Arrds.n-1)
						stt = (startPage-1)*OBJ_PER_PAGE_dms;
						
					y = U+kichThuocSTT+(stt%OBJ_PER_PAGE_dms)*h;
					// to den hinh chu nhat cu
					setcolor(BLACK);
					rectangle(x, yOld, x+W, yOld+h);
					// ve hinh chu nhat moi
					setcolor(GREEN);
					rectangle(x, y, x+W, y+h);
					yOld = y;
				}
				else if (key == 27){ //exit
					return TimKiem(dsds);
				}
				else if (key == '\r'){
					/*selected = true;
					return;*/
					struct Dausach tmpD;
					tmpD = dsds.Arrds.arr[stt];
					choosepos = dsds.searchIsbn(dsds.Arrds.arr[stt].ISBN);
					setfillstyle(SOLID_FILL, MAU_NEN);
					bar(350,150,1520,950);
					Insach(dsds,danhSachDanhmucsach,sizeDanhmucsach,choosepos);
					inthongtinDS(dsds,KhungDauSach,tmpD);
					return;
				}
			}
		}
	}
}

void inthongtinDS(DSDS &dsds,char khungNoiDung[][30], struct Dausach tmp){
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	// Kich thuoc khung
	int L =	250;
	int U = 150;
	int R =	1050;
	int D =	850;
	
	int H = 250;
	int W = 400;
	// Ve khung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(L,U,R,D);
	//	Ve khung info
	setbkcolor(MAU_NEN);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar(L,U,R,U+kichThuocSTT);
	
	// Ve vien khung
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L,U+kichThuocSTT,R,U+kichThuocSTT);
	rectangle(L,U,R,D);
	rectangle(L,D-kichThuocNut,WD_WIDTH/2,D);
	rectangle(WD_WIDTH/2,D-kichThuocNut,R,D);
	// In info khung
	setbkcolor(MAU_MENU);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(280, 165, KhungDauSach[0]);
 
	int pos=2;
	int Soluongkhung=6;
	for (int i = 1; i <= Soluongkhung; i++){
		veKhung(350, ViTriKhungDauSach[i], KhungDauSach[i+2], 0, NEN_KHUNG, WHITE);
	}
//	in thong tin
	char tmpst[10];
	char tmpnxb[5];
	
	strcpy(tmpst,toChars(tmp.Sotrang));
	strcpy(tmpnxb,toChars(tmp.Namxb));	

	InThongTin(530, ViTriKhungDauSach[1], tmp.ISBN);
	InThongTin(530, ViTriKhungDauSach[2], tmp.Tensach);
	InThongTin(530, ViTriKhungDauSach[3], tmpst);
	InThongTin(530, ViTriKhungDauSach[4], tmp.Tacgia);
	InThongTin(530, ViTriKhungDauSach[5], tmpnxb);
	InThongTin(530, ViTriKhungDauSach[6], tmp.Theloai);	
	bool buttonL = 1;
	veKhungNutthongtin(khungNoiDung, buttonL, 0, 1);
	while(1){
		if(kbhit()){
			char key = getch();
			if(key==0){
				char ckey = getch();
				switch(ckey){
					case KEY_LEFT:{
						buttonL ^= 1;
						break;
					}
					case KEY_RIGHT:	{
						buttonL ^= 1;
						break;
					}
				}
			}
			else if(key == '\r'){
				if(buttonL == 1){
					VeMenu();
					
					return TimKiem(dsds);
				} else {
					VeMenu();
					return;
				}
			}
			else if(key==27){
		 		VeMenu();
			 	return;
			}
			veKhungNutthongtin(khungNoiDung, buttonL, 0,1);
		}
	}		
}

void ghiSach(pDMS ds, int posX, int posY){
	char tmptt[8];
	if(ds->sach.Trangthai==0){
		strcpy(tmptt,"Cho muon duoc");
	} else if(ds->sach.Trangthai==1){
		strcpy(tmptt,"Da cho muon");
	} else if(ds->sach.Trangthai==2){
		strcpy(tmptt,"Da thanh ly");
	}
	
	// in Ma sach
	outtextxy(posX - 35, posY, ds->sach.Masach);
	posX += textwidth(danhSachDausach[2]) + sizeDanhmucsach[0]*2;
	
	// in Trang thai
	outtextxy(posX, posY, tmptt);
	posX += textwidth(danhSachDanhmucsach[3]) + sizeDanhmucsach[1]*2;
	
	// in Vi tri
	outtextxy(posX + 80, posY, ds->sach.Vitri);
	posX += textwidth(danhSachDanhmucsach[4]) + sizeDanhmucsach[2]*2;
}

void Insach(DSDS &dsds, char khungNoiDung[][30], int sizeKhungNoiDung[], int addpos){
	int kichThuocSTT = 40;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE_dms + kichThuocSTT;
	int W = 0;
	for (int i = 1; i < 3; i++){
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	}
	//tinh kich thuoc khung
	int L =	1060;
	int U = 150;
	int R =	1700;
	int D =	850;

	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	
	settextstyle(COMPLEX_FONT, 0, 2);
	int dis = L;
	for (int i = 1; i < 4; i++){
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D );
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 20; i++){
		dis += h+10;
		line(L, dis, R, dis);
	}
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	for(pDMS node = dsds.nodes[addpos]->dms; node != NULL; node = node->next){
		dis += 5;	
		// in STT
		int disW = L;
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		ghiSach(node, disW, dis);	
		dis += h+5;
	}
	
}

void TimKiem(DSDS &ListDausach){
	ListDausach.sort(true);
	ListDausach.Arrds.init();
	int removePos = 0;
	int choosepos;
	int page = 1;
	bool select;
	char findID[31];
	strcpy(findID,"");
	
	ListDausach.search(findID);
	inTrangDausach1(ListDausach, danhSachDausach, sizeDanhSachDausach, (page-1)*OBJ_PER_PAGE_dms, findID);
	while(1){
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
							return chonTuDanhSach1(ListDausach, removePos, page, select, findID);
						}
					case KEY_DOWN:{
							return chonTuDanhSach1(ListDausach, removePos, page, select, findID);
						}
				}
			}
			else if (key == '\r'){
				chonTuDanhSach1(ListDausach, removePos, page, select, findID);
				return;
			}
			else if (key == 27){
				VeMenu();
				return;
			}
			Nhap(730,85,2,key, findID, 30);
			ListDausach.Arrds.init();
			ListDausach.search(findID);
			inTrangDausach1(ListDausach, danhSachDausach, sizeDanhSachDausach, (page-1)*OBJ_PER_PAGE_dms, findID);
		}
	}

}

//======Danh muc sach=======//

void chondanhMucsach(DSDS &ListDausach);
void VeMenudms(DSDS &dsds, char khungNoiDung[][30], int sizeKhungNoiDung[], int addpos);
void MenuDms(DSDS &dsds, char menu[][30], int MAXMENU, int &chonMuc, int pos);
void VeKhungNhapMathe(char khungNoiDung[][30],  bool &selected, TreeDocgia &docgia, DSDS &dsds, node &tmp, char *findID);
void VeKhungindocgia(char khungNoiDung[][30], int ViTriKhung[], node tmpDG,DSDS &dsds, bool &selected, bool trasach);

// bang ben trai
void inTrangDms(DSDS &dsds, char khungNoiDung[][30], int sizeKhungNoiDung[], int start){ 
	int kichThuocSTT = 40;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 7; i++){
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	}
	
	//tinh kich thuoc khung
	int L =	20;
	int U = 100;
	int R =	1180;
	int D =	870;
	
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	
	settextstyle(COMPLEX_FONT, 0, 2);
	int dis = L;
	for (int i = 0; i < 7; i++){
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 22; i++){
		dis += h+10;
		line(L, dis, R, dis);
	}
	
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = dsds.n;
	for (int i = start; i < min(start+OBJ_PER_PAGE, Size); i++){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		dsds.sort(true);
		inDausach(dsds.nodes[i], disW, dis,1);		
		dis += h+5;
	}
	
	setbkcolor(MAU_NEN);
}
// in danh sach dau sach
void Vekhungdanhmucsach(DSDS &dsds, int &stt, int &startPage, bool &selected){
	//in danh sach
	//int startPage = 1;
	selected = false;
	int limitPage = ceil(dsds.n*1.0/OBJ_PER_PAGE); // lam tron so 
	if (limitPage == 0){
		noti(Fail[2]);
	}
	else{
		// tinh thong so
		int kichThuocSTT = 40;
		int h = textheight(danhSachDausach[0])+10;
		int H = (h)*OBJ_PER_PAGE + kichThuocSTT;
		
		int W=1160;
		int U = 100;
		int L =	350;
		
		int x = 20, 
			y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
		int yOld = y;
		/*int L =	350;
		int U = 100;
		int R =	1510;
		int D =	895;*/
				
		inTrangDms(dsds, danhSachDausach, sizeDanhSachDausach, (startPage-1)*OBJ_PER_PAGE);
		showPage(1040, 880, startPage, limitPage);
		
		setcolor(GREEN);
		rectangle(x, y, x+W, y+h);
		while(1){
			if(kbhit())	{
				char key = getch();
				if (key == 0){
					char nextK = getch();
					switch(nextK){
						case KEY_PGDN:{
								startPage--;
								if (startPage < 1)
									startPage = limitPage;
								inTrangDms(dsds, danhSachDausach, sizeDanhSachDausach, (startPage-1)*OBJ_PER_PAGE);
								showPage(1040, 880, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_PGUP:{
								startPage++;
								if (startPage > limitPage)
									startPage = 1;
								inTrangDms(dsds, danhSachDausach, sizeDanhSachDausach, (startPage-1)*OBJ_PER_PAGE);
								showPage(1040, 880, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_UP:{
								stt--;
								break;
							}
						case KEY_DOWN:{
								stt++;
								break;
							}
					}
					if (stt < (startPage-1)*OBJ_PER_PAGE)
						stt = min((startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1), dsds.n-1);
					else if (stt > (startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1) || stt > dsds.n-1)
						stt = (startPage-1)*OBJ_PER_PAGE;
						
					y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
					// to den hinh chu nhat cu
					setcolor(BLACK);
					rectangle(x, yOld, x+W, yOld+h);
					// ve hinh chu nhat moi
					setcolor(GREEN);
					rectangle(x, y, x+W, y+h);
					yOld = y;
				}
				else if (key == 27){ //exit
					VeMenu();
					break;
				}
				else if (key == '\r'){
					selected = true;				
					return;
				}
			}
		}
	}
}

void BatMuc(int sttmenu, char menu[][30], int HL_COLOR, int C_SIZE){
	// * Ve cac muc duoc chon
	setbkcolor(HL_COLOR);
	setfillstyle(SOLID_FILL, HL_COLOR);
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT, 0, 3);
	
	// Highlight muc menu 
	bar(1440,ViTrimucmenuDms[sttmenu], 1680, 55+ViTrimucmenuDms[sttmenu]);
	rectangle(1440,ViTrimucmenuDms[1], 1680, 55+ViTrimucmenuDms[1]);
	
	outtextxy(1535, ViTrichuDms[sttmenu], menu[sttmenu-1]);
	settextstyle(COMPLEX_FONT, 0, 2);
}

void veKhungNut1(char khungNoiDung[][30], bool Left, bool reset, int n){
int kichThuocSTT = 30;
	int kichThuocNut = 40;
	//tinh kich thuoc khung
	int L =	1245;
	int U = 150;
	int R =	1820;
	int D =	750;
	
	int H = 450;
	int W = 600;
	//ve khung duoi
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	// In info khung
	/*setbkcolor(MAU_MENU);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(520, 165, KhungDauSach[0]);*/
	// Vi trí 2 nut cuoi
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	// In 2 nut cuoi
	/*setbkcolor(NEN_KHUNG);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);*/
	
	int MAU_NUT_HL = HL_MENU_PHU;
	if (reset)
			MAU_NUT_HL = NEN_KHUNG;
		
	setfillstyle(SOLID_FILL, MAU_NUT_HL);
	if (Left){
		bar (L, D-kichThuocNut, (L+R)/2, D);
		setbkcolor(MAU_NUT_HL);
		setcolor(WHITE);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
		setbkcolor(NEN_KHUNG);
		outtextxy((L+R)/2+midText2, D-midTextH, khungNoiDung[n+1]);
	} else{
		bar ((L+R)/2, D-kichThuocNut, R, D);
		setcolor(WHITE);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
		setbkcolor(MAU_NUT_HL);
		outtextxy((L+R)/2+midText2, D-midTextH, khungNoiDung[n+1]);
	}
	
	setcolor(BLACK);
	rectangle(L,D-kichThuocNut,(L+R)/2,D);
	rectangle((L+R)/2,D-kichThuocNut,R,D);					//center line
	
}
// in sach
void inDms(pDMS ds, int posX, int posY){
	char tmptt[8];
	if(ds->sach.Trangthai==0){
		strcpy(tmptt,"Cho muon duoc");
	} else if(ds->sach.Trangthai==1){
		strcpy(tmptt,"Da cho muon");
	} else if(ds->sach.Trangthai==2){
		strcpy(tmptt,"Da thanh ly");
	}
	
	// in Ma sach
	outtextxy(posX + canLeGiua(ds->sach.Masach, textwidth(danhSachDausach[1])+sizeDanhmucsach[1]*2), posY, ds->sach.Masach);
	posX += textwidth(danhSachDausach[2]) + sizeDanhmucsach[1]*2;
	
	// in Trang thai
	outtextxy(posX + 10, posY, tmptt);
	posX += textwidth(danhSachDanhmucsach[3]) + sizeDanhmucsach[2]*2;
	
	// in Vi tri
	outtextxy(posX + 80, posY, ds->sach.Vitri);
	posX += textwidth(danhSachDanhmucsach[4]) + sizeDanhmucsach[3]*2;
}

void VekhungnhapSach(DSDS &dsds, int apos){
	lo:
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	int thaotac;
	
	int L = 1200;
	int U = 471;
	int R = 1890;
	int D = 870;
	
	setfillstyle(SOLID_FILL,NEN_KHUNG);
	bar(L,U,R,D);
	
	
	// Vi trí 2 nut cuoi
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (1245, 750-kichThuocNut, 1820, 750);
	
	int midText1 = (575/2 - textwidth(KhungDauSach[1]))/2;
	int midText2 = (575/2 - textwidth(KhungDauSach[2]))/2;
	int midTextH = (kichThuocNut - textheight(KhungDauSach[1]))/2 + textheight(KhungDauSach[1]);
	setcolor(WHITE);
	// In 2 nut cuoi
	setbkcolor(NEN_KHUNG);
	outtextxy(1245+midText1, 750-midTextH, KhungDauSach[1]);
	outtextxy((3065/2)+midText2, 750-midTextH, KhungDauSach[2]);
	setcolor(BLACK);
	rectangle(1245,750-kichThuocNut,(3065)/2,750);
	rectangle((3065)/2,750-kichThuocNut,1820,750);
	// in guild
	
	setcolor(WHITE);
	outtextxy(1250,770,"Trang thai:");
	outtextxy(1400,770,"0: Cho muon dc");
	outtextxy(1400,800,"1: Da duoc muon");
	outtextxy(1400,830,"2: Da thanh ly");
	int pos=2;
	for(int i=1; i<=3; i++){
		if(i==2){
			veKhung(1245,ViTrichuDms[i],danhSachDanhmucsach[i],1,NEN_TEXT,WHITE);
		} else {
			veKhung(1245,ViTrichuDms[i],danhSachDanhmucsach[i],0,NEN_TEXT,WHITE);
		}
	}
	Sach tmpD;
	char tmptt[2];
	strcpy(tmptt,"");
	strcpy(tmpD.Masach, dsds.randomDms(apos));
	InThongTin(1425,550,tmpD.Masach);
	
	
	// Di chuyen trong menu
	while(1){	
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
							pos--;
							break;
						}
					case KEY_DOWN:{
							pos++;
							break;
						}
				}
				cpos:
				if (pos == 1)
					pos = 4;
				if (pos > 4){
						pos = 2;
				}
			}
			else if (key == '\r'){
				if (pos <= 4)  //enter xuong o moi
					pos++;
//				else
//					return;
			}
			else if (key == 27){
				VeMenu();
				return;
			}
			for(int i=1; i<=3; i++){
				veKhung(1245,ViTrichuDms[i],danhSachDanhmucsach[i],0,NEN_TEXT,WHITE);
			}
			
			InThongTin(1425,550,tmpD.Masach);
			InThongTin(1425,605,tmptt);
			InThongTin(1425,660,tmpD.Vitri);
			switch(pos){
				case 1:{
					veKhung(1245,550,danhSachDanhmucsach[1],1,NEN_TEXT,WHITE);
					InThongTin(1425,550,tmpD.Masach);
					break;
				}
				case 2:{
					veKhung(1245,605,danhSachDanhmucsach[2],1,NEN_TEXT,WHITE);
					Nhap(1425,605,0,key,tmptt,1);
					break;
				}
				case 3:{
					veKhung(1245,660,danhSachDanhmucsach[3],1,NEN_TEXT,WHITE);
					Nhap(1425,660,2,key,tmpD.Vitri,50);
					break;
				}
				case 4:{
						// Them sach
						bool buttonL = 1;
						veKhungNut1(KhungNoiDung, buttonL, 0,1);
						while(1){
							if(kbhit()){
								char key5 = getch();
								char c5Next;
								if (key5 == 0){
									c5Next = getch();
									switch(c5Next){
										case KEY_UP:{
												pos--;
												veKhungNut1(KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_DOWN:{
												pos++;
												veKhungNut1( KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_LEFT:{
												buttonL ^= 1;
												break;
											}
										case KEY_RIGHT:{
												buttonL ^= 1;
												break;
											}
									}
								}
								else if (key5 == '\r'){	
//									return;
									if (buttonL == 1){
										tmpD.Trangthai=ChangeCharToNum(tmptt);
										if( (tmpD.Trangthai == 0 || tmpD.Trangthai == 1 ||tmpD.Trangthai == 2 ) && strlen(tmpD.Vitri)!=0){ 
											dsds.addsach(apos, tmpD);
											ThongBao(1500,500,Success[0],GREEN,NEN_KHUNG);
											VeMenudms(dsds,danhSachDanhmucsach,sizeDanhmucsach, apos);
											goto lo;
											return ;
										}
										else{
											if((tmpD.Trangthai != 0 || tmpD.Trangthai != 1 ||tmpD.Trangthai != 2) && strlen(tmpD.Vitri) !=0) 
												ThongBao(1500, 500, Fail[2], LIGHTRED, NEN_KHUNG);
											else
												ThongBao(1500, 500, Fail[0], LIGHTRED, NEN_KHUNG);
										}
									}
									else {	
										VeMenu();
										return;
									}
								}
								else if (key5 == 27){
								VeMenu();
								
								return;
								}
								veKhungNut1( KhungNoiDung, buttonL, 0,1);
							}
						}			
					}
				}				
			}
		}
	}
// Menu nhap sach & in danh sach sach
void VeMenudms(DSDS &dsds, char khungNoiDung[][30], int sizeKhungNoiDung[], int addpos){
	int kichThuocSTT = 40;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 3; i++){
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	}
	//tinh kich thuoc khung
	int L =	1200;
	int U = 100;
	int R =	1890;
	int D =	870;

	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	
	settextstyle(COMPLEX_FONT, 0, 2);
	int dis = L;
	for (int i = 0; i < 4; i++){
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D/2+36);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 10; i++){
		dis += h+10;
		line(L, dis, R, dis);
	}
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	settextstyle(COMPLEX_FONT,0,3);
	for(int i=0; i<3; i++){
		outtextxy(1535, ViTrichuDms[i+1], khungdms[i]);
		setcolor(BLACK);
		rectangle(1440,ViTrimucmenuDms[1], 1680, 55+ViTrimucmenuDms[1]);
		setcolor(WHITE);
	}
	settextstyle(COMPLEX_FONT,0,2);
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int i=1;
	for(pDMS node = dsds.nodes[addpos]->dms; node != NULL; node = node->next){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i++);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		inDms(node, disW, dis);	
		dis += h+5;
	}
	
}
// Menu them, xoa, sua
void MenuDms(DSDS &dsds, char menu[][30], int MAXMENU, int &chonMuc, int pos){
	chonMuc = 1;
	BatMuc(1,menu, HL_MENU_PHU, 2);
	while(1){
		if(kbhit()){
			VeMenudms(dsds,danhSachDanhmucsach,sizeDanhmucsach, pos);
			char key = getch();
			if(key == 0){
				char cNext = getch();
				switch(cNext){
					case KEY_UP:{
						chonMuc--;
						break;
					}
					case KEY_DOWN: {
						chonMuc++;
						break;
					}
					default:{
							VeMenu();
							chonMuc = -1;
							return;
						}
				}
				if (chonMuc > 3)
					chonMuc = 1;
				if (chonMuc < 1)
					chonMuc = 3;
			}
			else if (key == '\r'){
				return;
			}
			else if (key == 27){
				chonMuc = -1;
				VeMenu();
				return;
			}
			BatMuc(chonMuc, menu, HL_MENU_PHU, 2);
		}
	}
}
// thao tac trong menu dms
void chondanhMucsach(DSDS &ListDausach,int pos){
	int thaotac;
	VeMenudms(ListDausach,danhSachDanhmucsach,sizeDanhmucsach,pos);
	MenuDms(ListDausach,khungdms,3,thaotac,pos);
	switch(thaotac){
		case 1:{
			return VekhungnhapSach(ListDausach, pos); 
			break;
		}
		
	}		
}

void DanhMucsach(DSDS &ListDausach){
	bool select;
	int addPos = 0;
	int page = 1;
	while(1){
		Vekhungdanhmucsach(ListDausach,addPos,page,select);
		if(select){
			chondanhMucsach(ListDausach,addPos);
//			VekhungnhapSach(ListDausach, addPos, l);
		}else{
			break;
		}
		
	} 
	VeMenu();
}

//========Doc gia========//

void veMuc2Chon(int x, int y, char noiDung[], char noiDungMucChon[][30], bool chonTrai, int mauNen, int mauChu){
	setbkcolor(mauNen);
	setcolor(mauChu);
	outtextxy(x, y, noiDung);
	int H = textheight(noiDung);
	int W = 275;
	int rad = H/2-2;
	int dis1 = 180;
	int dis2 = 320;
	outtextxy(x+dis2+H, y, noiDungMucChon[1]);
	outtextxy(x+dis1+H, y, noiDungMucChon[0]);
	setfillstyle(SOLID_FILL, GREEN);
	
	if (chonTrai){
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis1, y+H/2, rad);
		setfillstyle(SOLID_FILL, GREEN);
		setcolor(BLACK);
		circle(x+dis1, y+H/2, rad-2);
		floodfill(x+dis1, y+H/2, BLACK);
		
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis2, y+H/2, rad);
		setfillstyle(SOLID_FILL, mauNen);
		setcolor(BLACK);
		circle(x+dis2, y+H/2, rad-2);
		floodfill(x+dis2, y+H/2, BLACK);
	}
	else{
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis1, y+H/2, rad);
		setfillstyle(SOLID_FILL, mauNen);
		setcolor(BLACK);
		circle(x+dis1, y+H/2, rad-2);
		floodfill(x+dis1, y+H/2, BLACK);
		
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis2, y+H/2, rad);
		setfillstyle(SOLID_FILL, GREEN);
		setcolor(BLACK);
		circle(x+dis2, y+H/2, rad-2);
		floodfill(x+dis2, y+H/2, BLACK);
	}
	
	setfillstyle(SOLID_FILL, TEXTBOX);
}

void VeKhungthemDocgia(struct Docgia &tmpDG, TreeDocgia &docgia, char khungNoiDung[][30], int ViTriKhung[], bool &selected){
	selected = false;
	int soLuongKhung = 5;
	
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	// Kich thuoc khung
	int L =	500;
	int U = 150;
	int R =	1400;
	int D =	850;
	
	int H = 450;
	int W = 600;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	//khung
	rectangle(L-1, U, R, D);
	
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(520, 165, khungNoiDung[0]);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	//ve khung nhap lieu
	for (int i = 1; i <= soLuongKhung; i++){
		if (i != soLuongKhung){
			if (i == 2) // 650
				veKhung(650, ViTriKhung[i], khungNoiDung[i+2], 1, NEN_KHUNG, WHITE);
			else
				veKhung(650, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
		}
		else{
			veMuc2Chon(650, ViTriKhung[i], khungNoiDung[7], Sex, 1, NEN_KHUNG, WHITE);
		}
	}
	
	int pos = 2;
	int fst = tmpDG.Phai;			//SEX
	char tmptt[2];
	char tmpmt[6];
	strcpy(tmptt,"1");
	strcpy(tmpmt,"");
	strcpy(tmpDG.Ho,"");
	strcpy(tmpDG.Ten,"");
	tmpDG.Mathe = docgia.sinhMathe();
	
	strcpy(tmpmt, toChars(tmpDG.Mathe));
	//in thong tin
	InThongTin(830, 250, tmpmt);
	InThongTin(830, 340, tmpDG.Ho);
	InThongTin(830, 430, tmpDG.Ten);
	InThongTin(830, 520, tmptt);
	veMuc2Chon(650, 610, khungNoiDung[7], Sex, fst, NEN_KHUNG, WHITE);
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	outtextxy(650, 700, "Trang thai the: ");
	outtextxy(850, 700, "0: Khoa ");
	outtextxy(850, 740, "1: Hoat dong ");
	
	while(1){
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
							pos--;
							break;
						}
					case KEY_DOWN:{
							pos++;
							break;
						}
				}
				cpos:
				if (pos == 1)
					pos = 6;
				if (pos > 6)
					pos = 2;
			}
			else if (key == '\r'){
				if (pos <= 5)
					pos++;
			}
			else if (key == 27){
				VeMenu();
				return;
			}
			
			setbkcolor(NEN_TEXT);	
			for (int i = 1; i <= 5; i++){
				if (i != 5)
					veKhung(650, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
				else
					veMuc2Chon(650, ViTriKhung[5], khungNoiDung[7], Sex, fst, NEN_KHUNG, WHITE);
				setcolor(WHITE);
			}
			setbkcolor(NEN_TEXT);
			InThongTin(830, 250, tmpmt);
			InThongTin(830, 340, tmpDG.Ho);
			InThongTin(830, 430, tmpDG.Ten);
			InThongTin(830, 520, tmptt);
			switch(pos){
				case 1:{
						veKhung(650, 250, khungNoiDung[3], 1, NEN_KHUNG, WHITE);
						InThongTin(830, 250, tmpmt);
						break;
					}
				case 2:{
						veKhung(650, 340, khungNoiDung[4], 1, NEN_KHUNG, WHITE);
						Nhap(830, 340, 2, key, tmpDG.Ho, 30);
						break;
					}
				case 3:{
						veKhung(650, 430, khungNoiDung[5], 1, NEN_KHUNG, WHITE);
						Nhap(830, 430, 2, key, tmpDG.Ten, 20);
						break;
					}
				case 4:{
						veKhung(650, 520, khungNoiDung[6], 1, NEN_KHUNG, WHITE);
						Nhap(830, 520, 0, key, tmptt, 1);
						break;
				}
				case 5:{
						veMuc2Chon(650, 610, khungNoiDung[7], Sex, fst, NEN_KHUNG, WHITE);
						while(1){
							if (kbhit()){
								char key4 = getch();
								if (key4 == 0){
									char c4Next = getch();
									switch(c4Next){
										case KEY_LEFT:{
												fst++;
												break;
											}
										case KEY_RIGHT:{
												fst--;
												break;
											}
										case KEY_UP:{
												pos--;
												goto cpos;
											}
										case KEY_DOWN:{
												pos++;
												goto cpos;
											}
									}
								}
								else if (key4 == '\r'){
									pos++;
									goto cpos;
									break;
								}
								else if (key4 == 27){
									return;
								}
								if (fst == -1)
									fst = 1;
								if (fst > 1)
									fst = 0;								
								veMuc2Chon(650, 610, khungNoiDung[7], Sex, fst, NEN_KHUNG, WHITE);
								tmpDG.Phai = fst;
							}
						}
						break;
					}
				case 6:{
						bool buttonL = 1;
						veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
						while(1){
							if(kbhit()){
								char key5 = getch();
								char c5Next;
								if (key5 == 0){
									c5Next = getch();
									switch(c5Next){
										case KEY_UP:{
												pos--;
												veKhungNut(H, W, khungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_DOWN:{
												pos++;
												veKhungNut(H, W, khungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_LEFT:{
												buttonL ^= 1;
												break;
											}
										case KEY_RIGHT:{
												buttonL ^= 1;
												break;
											}
									}
								}
								else if (key5 == '\r'){
//									return;
									if (buttonL == 1){
										if(strlen(tmpDG.Ho) != 0 && strlen(tmpDG.Ten) != 0 && strlen(tmptt) != 0){
											tmpDG.Trangthai = ChangeCharToNum(tmptt);
											if(tmpDG.Trangthai != 0 && tmpDG.Trangthai != 1){
												ThongBao(1150, 165, Fail[2], LIGHTRED, MAU_MENU);
											} else {
												tmpDG.Mathe = ChangeCharToNum(tmpmt);
												selected = true;
												return;
											}
										}
										else{
											ThongBao(1150, 165, Fail[0], LIGHTRED, MAU_MENU);
										}
									}
									else{
										VeMenu();
										return;
									}
								}
								else if (key5 == 27){
									VeMenu();
									return;
								}
								veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
							}
						}
					}
			}
		}
	}
}

void addDocgia(TreeDocgia &docgia){
	bool entered = false;
	do{
		struct Docgia tmpDG;
		VeKhungthemDocgia(tmpDG, docgia, KhungDocgia, ViTriKhungDocGia, entered);
		if(entered){
			docgia.themDocgia(tmpDG);
			ThongBao(1150, 165, Success[0], GREEN, MAU_MENU);
		}else{
			break;
		}
	}while(entered);
	VeMenu();		
	
}

void  VeKhungxoaDocgia(char khungNoiDung[][30], bool &list, char *findID, bool &selected){
	
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
		
	// Kich thuoc khung
	int L =	470;
	int U = 300;
	int R =	1430;
	int D =	515;
	
	int H = 450;
	int W = 600;
	// Ve khung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(L,U,R,D);
	//	Ve khung info
	setbkcolor(MAU_NEN);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar(L,U,R,U+kichThuocSTT);
	
	// Ve vien khung
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L,U+kichThuocSTT,R,U+kichThuocSTT);
	rectangle(L,U,R,D);
	rectangle(L,D-kichThuocNut,(L+R)/2,D);
	rectangle((L+R)/2,D-kichThuocNut,R,D);
	// In info khung
	setbkcolor(MAU_MENU);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(470, 300, KhungXoa[1]);

			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
/*	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(470, 300, khungNoiDung[0]);*/
	
	//
	//Ve cac khung ban dau===
	selected = false;
	bool choice = 1;
	bool chooseL = 1; 
	int posR = 1;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	setcolor(BLACK);
	rectangle(L-1, U-1, R+1, D+1);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[3]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[4]))/2;
	int midText3 = ((R-L)/2 - textwidth(khungNoiDung[5]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[5]);
	setcolor(WHITE);
	
	
	rectangle(L+14, ViTriKhung[3]-21, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+20+textheight(khungNoiDung[1]));
	// ve khung chon id
	setbkcolor(HL_MENU_PHU);
	setfillstyle(SOLID_FILL, HL_MENU_PHU);
	bar (L+15, ViTriKhung[3]-20, WD_WIDTH/2, ViTriKhung[3]+20+textheight(khungNoiDung[1]));
	outtextxy(L+25, ViTriKhung[3], khungNoiDung[1]);
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (L+25+2*textwidth(khungNoiDung[1]), ViTriKhung[3]-10, WD_WIDTH/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[1]));
	rectangle(L+25+2*textwidth(khungNoiDung[1]), ViTriKhung[3]-10, WD_WIDTH/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[1])); // khung nhap
	
	// ve khung chon list
	setbkcolor(NEN_KHUNG);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(WD_WIDTH/2, ViTriKhung[3]-20, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+20+ textheight(khungNoiDung[1]));
	outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[5]);	
	setfillstyle(SOLID_FILL, HL_MENU_PHU);	
	
	// 2 nut check and exit
	outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
	//make ur choice
	
	findID[0] = '\0';
	while(1){
		InThongTin(L+35+2*textwidth(khungNoiDung[1]),ViTriKhung[3],findID);
		if(kbhit()){
			char keyR = getch();
			if(keyR==0){
				char ckeyR = getch();
				switch(ckeyR){
					case KEY_LEFT:{
						if(posR==1)
							choice ^= 1; // 1: trai 0: phai
						if(posR==2)
							chooseL ^= 1;	
						break;
					}
					case KEY_RIGHT:{
						if(posR==1)
							choice ^= 1; // 1: trai 0: phai
						if(posR==2)
							chooseL ^= 1;	
						break;
					}
					case KEY_UP:{
						if(posR == 1){
							posR = 2;
							chooseL = true;
							break;
						}
						else{
							posR = 1;
							//choice = true;
							break;
						}		
					}
					case KEY_DOWN:{
						if(posR == 1){
							posR = 2;
							chooseL = true;
							break;
						}
						else{
							posR = 1;
							//choice = true;
							break;
						}	
					}	
				}
			}
			if(keyR == '\r'){
				if(posR == 1){
					posR = 2;
					chooseL = 1;
				}
				else{
					if(chooseL){
						if(choice == 1){
							list = false;
							selected = true;
							return;
						}
						else{
							list = true;
							selected = true;
							return;
						}
					}
					else{
						VeMenu();
						return;
					}
				}
			}
			if(keyR == 27){
				VeMenu();
				return;
			}
			// hien thi
			if(posR == 1){	//ID/list
				setcolor(WHITE);
				setfillstyle(SOLID_FILL, NEN_KHUNG);
				if(choice){
					// ID
					setbkcolor(NEN_KHUNG);
					bar(WD_WIDTH/2, ViTriKhung[3]-20, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+20+ textheight(khungNoiDung[1]));
					outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[5]);
					setbkcolor(HL_MENU_PHU);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);									//do mau nen cho nut
					bar (L+15, ViTriKhung[3]-20,WD_WIDTH/2 , ViTriKhung[3]+20+ textheight(khungNoiDung[1]));
					outtextxy(L+25, ViTriKhung[3], khungNoiDung[1]);
					setfillstyle(SOLID_FILL, TEXTBOX);
					bar (L+25+2*textwidth(khungNoiDung[1]), ViTriKhung[3]-10, WD_WIDTH/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[1]));
					rectangle(L+25+2*textwidth(khungNoiDung[1]), ViTriKhung[3]-10, WD_WIDTH/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[1]));
					Nhap(L+35+2*textwidth(khungNoiDung[1]),ViTriKhung[3],0,keyR,findID,5);
				}
				else{
					// list
					setbkcolor(NEN_KHUNG);
					bar (L+15, ViTriKhung[3]-20,WD_WIDTH/2 , ViTriKhung[3]+20+ textheight(khungNoiDung[1]));
					outtextxy(L+25, ViTriKhung[3], khungNoiDung[1]);
					setfillstyle(SOLID_FILL, TEXTBOX);
					bar (L+25+2*textwidth(khungNoiDung[1]), ViTriKhung[3]-20, WD_WIDTH/2-15, ViTriKhung[3]+20+ textheight(khungNoiDung[1]));
					rectangle(L+25+2*textwidth(khungNoiDung[1]), ViTriKhung[3]-10, WD_WIDTH/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[1]));
					setbkcolor(HL_MENU_PHU);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar(WD_WIDTH/2, ViTriKhung[3]-20, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+20+ textheight(khungNoiDung[1]));
					outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[5]);
				}
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, NEN_KHUNG);
				bar (L, D-kichThuocNut, WD_WIDTH/2, D);
				bar (WD_WIDTH/2, D-kichThuocNut, R, D);				
				setbkcolor(NEN_KHUNG);
				line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
				setcolor(WHITE);
				outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
				outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
			}
			else{	//check/exit
				setcolor(WHITE);
				setfillstyle(SOLID_FILL, NEN_KHUNG);	
				if(chooseL){ //check
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
					setbkcolor(NEN_KHUNG);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
				}
				else{	//exit
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
					setbkcolor(NEN_KHUNG);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
				}
				setcolor(BLACK);
				line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
			}		
		}
	}
}

void inDocgia(struct Docgia &tmpDg, int posX, int posY){
	char tmpmt[10];
	char tmpgt[10];
	char tmptt[30];
	
	if(tmpDg.Phai == 1){
		strcpy(tmpgt,"Nam");
	} else {
		strcpy(tmpgt,"Nu");
	}
	if(tmpDg.Trangthai == 1){
		strcpy(tmptt,"Hoat dong");
	} else if (tmpDg.Trangthai == 0){
		strcpy(tmptt,"Khoa");
	}
	strcpy(tmpmt,toChars(tmpDg.Mathe));
	
	// in ma the
	outtextxy(posX + canLeGiua(tmpmt, textwidth(danhSachDausach[1])+sizeDanhSachDocgia[1]*2), posY, tmpmt);
	posX += textwidth(danhSachDocgia[1]) + sizeDanhSachDocgia[1]*2 + 20;
	// in ho
	outtextxy(posX + 10, posY, tmpDg.Ho);
	posX += textwidth(danhSachDocgia[2]) + sizeDanhSachDocgia[2]*2 - 5;
	// in ten
	outtextxy(posX + 80, posY, tmpDg.Ten);
	posX += textwidth(danhSachDocgia[3]) + sizeDanhSachDocgia[3]*2 - 55;
	// in gioi tinh
	outtextxy(posX + 100, posY, tmpgt);
	posX += textwidth(danhSachDocgia[4]) + sizeDanhSachDocgia[0]*2;
	// in trang thai the
	outtextxy(posX + 195, posY, tmptt);
}

void inTrangDocgia(TreeDocgia &docgia ,char khungNoiDung[][30], int sizeKhungNoiDung[], int start, bool mode){
	int kichThuocSTT = 40;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 6; i++){
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	}
	
	//tinh kich thuoc khung
	int L =	350;
	int U = 100;
	int R =	1510;
	int D =	870;
	
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	
	settextstyle(COMPLEX_FONT, 0, 2);
	int dis = L;
	for (int i = 0; i < 6; i++){
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 22; i++){
		dis += h+10;
		line(L, dis, R, dis);
	}
	
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = docgia.dataArr.n;
	for (int i = start; i < min(start+OBJ_PER_PAGE, Size); i++){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		if(mode){
			docgia.theotenmode();
			inDocgia(docgia.dataArr.arr[i], disW, dis);
		} else {
			docgia.theoidmode();
			inDocgia(docgia.dataArr.arr[i], disW, dis);
		}		
		dis += h+5;
	}
	
	setbkcolor(MAU_NEN);
}

void veKhungNutmode(char khungNoiDung[][30], bool Left, bool reset){
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	//tinh kich thuoc khung
	int L =	350;
	int U = 45;
	int R =	560;
	int D =	95;
	
	//ve khung duoi
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	// In info khung
	// Vi trí 2 nut cuoi
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[0]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	// In 2 nut cuoi
	int MAU_NUT_HL = HL_MENU_PHU;
	if (reset)
			MAU_NUT_HL = NEN_KHUNG;
		
	setfillstyle(SOLID_FILL, MAU_NUT_HL);
	if (Left){
		bar (L, D-kichThuocNut, (L+R)/2, D);
		setbkcolor(MAU_NUT_HL);
		setcolor(WHITE);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[0]);
		setbkcolor(NEN_KHUNG);
		outtextxy((L+R)/2+midText2, D-midTextH, khungNoiDung[1]);
	} else{
		bar ((L+R)/2, D-kichThuocNut, R, D);
		setcolor(WHITE);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[0]);
		setbkcolor(MAU_NUT_HL);
		outtextxy((L+R)/2+midText2, D-midTextH, khungNoiDung[1]);
	}
	
	setcolor(BLACK);
	rectangle(L,D-kichThuocNut,(L+R)/2,D);
	rectangle((L+R)/2,D-kichThuocNut,R,D);						//center line
	
}

void chonTuDanhSachDocgia(TreeDocgia &docgia,int &stt, int &startPage, bool &selected){	
	//in danh sach
	selected = false;
	int limitPage = ceil(docgia.dataArr.n*1.0/OBJ_PER_PAGE); // lam tron so 
	if (limitPage == 0){
		noti(Fail[2]);
	}
	else{
		// tinh thong so
		int kichThuocSTT = 40;
		int h = textheight(danhSachDausach[0])+10;
		int H = (h)*OBJ_PER_PAGE + kichThuocSTT;
		
		int W=1160;
		int U = 100;
		int L =	350;
		
		int x = 350, 
			y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
		int yOld = y;
		
		bool mode = 1;
				
		inTrangDocgia(docgia, danhSachDocgia, sizeDanhSachDocgia, (startPage-1)*OBJ_PER_PAGE,mode);
		showPage(1370, 880, startPage, limitPage);
		veKhungNutmode(khungsort, 1, 0);
		setcolor(GREEN);
		rectangle(x, y, x+W, y+h);
		while(1){
			if(kbhit())	{
				char key = getch();
				if (key == 0){
					char nextK = getch();
					switch(nextK){
						case KEY_PGDN:{
								startPage--;
								if (startPage < 1)
									startPage = limitPage;
								inTrangDocgia(docgia, danhSachDocgia, sizeDanhSachDocgia, (startPage-1)*OBJ_PER_PAGE, mode);
								showPage(1370, 880, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_PGUP:{
								startPage++;
								if (startPage > limitPage)
									startPage = 1;
								inTrangDocgia(docgia, danhSachDocgia, sizeDanhSachDocgia, (startPage-1)*OBJ_PER_PAGE, mode);
								showPage(1370, 880, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_UP:{
								stt--;
								break;
							}
						case KEY_DOWN:{
								stt++;
								break;
							}
						case KEY_LEFT:{
								mode ^= 1;
								veKhungNutmode(khungsort, mode, 0);
								inTrangDocgia(docgia, danhSachDocgia, sizeDanhSachDocgia, (startPage-1)*OBJ_PER_PAGE, mode);
								showPage(1370, 880, startPage, limitPage);
								break;
						}
						case KEY_RIGHT: {
								mode ^= 1;
								veKhungNutmode(khungsort, mode, 0);
								inTrangDocgia(docgia, danhSachDocgia, sizeDanhSachDocgia, (startPage-1)*OBJ_PER_PAGE, mode);
								showPage(1370, 880, startPage, limitPage);
								break;
						}
					}
					if (stt < (startPage-1)*OBJ_PER_PAGE)
						stt = min((startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1), docgia.dataArr.n- 1);
					else if (stt > (startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1) || stt > docgia.dataArr.n - 1)
						stt = (startPage-1)*OBJ_PER_PAGE;
						
					y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
					// to den hinh chu nhat cu
					setcolor(BLACK);
					rectangle(x, yOld, x+W, yOld+h);
					// ve hinh chu nhat moi
					setcolor(GREEN);
					rectangle(x, y, x+W, y+h);
					yOld = y;
				}
				else if (key == 27){ //exit
					VeMenu();
					return;
				}
				else if (key == '\r'){
					selected = true;
					return;
					
				}
			}
		}
	}
}

void XoaID(char khungNoiDung[][30], int ViTriKhung[], int mathe, TreeDocgia &docgia, node tmpDG){
	int soLuongKhung = 5;
	
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	// Kich thuoc khung
	int L =	500;
	int U = 150;
	int R =	1400;
	int D =	850;
	
	int H = 450;
	int W = 600;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	//khung
	rectangle(L-1, U, R, D);
	
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(520, 165, khungNoiDung[0]);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	//ve khung nhap lieu
	for (int i = 1; i <= soLuongKhung; i++){
		if (i != soLuongKhung){
			veKhung(650, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
		}
		else{
			veMuc2Chon(650, ViTriKhung[i], khungNoiDung[7], Sex, 1, NEN_KHUNG, WHITE);
		}
	}
	
	int fst = tmpDG->docgia.Phai;			//SEX	
	char tmpmt[20];
	char tmptt[2];
	strcpy(tmptt, toChars(tmpDG->docgia.Trangthai));
	strcpy(tmpmt,toChars(tmpDG->docgia.Mathe));
	//in thong tin
	InThongTin(830, 250, tmpmt);
	InThongTin(830, 340, tmpDG->docgia.Ho);
	InThongTin(830, 430, tmpDG->docgia.Ten);
	InThongTin(830, 520, tmptt);
	veMuc2Chon(650, 610, khungNoiDung[7], Sex, fst, NEN_KHUNG, WHITE);
	bool buttonL = 1;
	veKhungNut(H, W, checkDS, buttonL, 0, 1);
	while(1){
		if(kbhit()){
			char key = getch();
			if(key==0){
				char ckey = getch();
				switch(ckey){
					case KEY_LEFT:{
						buttonL ^= 1;
						break;
					}
					case KEY_RIGHT:	{
						buttonL ^= 1;
						break;
					}
				}
			}
			else if(key == '\r'){
				if(buttonL == 1){
					if(tmpDG->docgia.checkdangmuon()){
						ThongBao(900, 165, Fail[11], LIGHTRED, MAU_MENU);
						VeMenu();
						return;
					} else {
						docgia.xoaDocgia(mathe);
						ThongBao(1150, 165, Success[1], GREEN, MAU_MENU);
						VeMenu();
						return;
					}
					
				} else {
					VeMenu();
					return;
				}
				
			}
			else if(key==27){
		 		VeMenu();
			 	return;
			}
			veKhungNut(H, W, checkDS, buttonL, 0,1);
		}
	}
}

void DanhsachxoaDocgia(TreeDocgia &docgia){
	int removePos = 0;
	int page = 1;
	bool select;
	node tmp;
	docgia.initdocgia();
	while(1){
		chonTuDanhSachDocgia(docgia,removePos, page, select);
		if(select){
			tmp = docgia.timDocGia(docgia.dataArr.arr[removePos].Mathe);
			XoaID(KhungDocgia, ViTriKhungDocGia, docgia.dataArr.arr[removePos].Mathe, docgia, tmp);
//			docgia.xoaDocgia(docgia.dataArr.arr[removePos].Mathe);
		}
		else{
			break;
		}
	}
	VeMenu();
}
	
void XoaDocgia(TreeDocgia &docgia){
	bool entered = false;
	do{
		bool chooseList = false;
		char tmpID[20];
		int tmpId;
		VeKhungxoaDocgia(KhungXoa, chooseList, tmpID, entered);
		if (entered){
			if (chooseList){
				return DanhsachxoaDocgia(docgia);
			}
			else{
				node tmp;
				tmpId = ChangeCharToNum(tmpID);
				tmp = docgia.timDocGia(tmpId);
				if(tmp == NULL){
					//loi ko ton tai
					ThongBao(1180, 310, Fail[1], LIGHTRED, MAU_MENU);
				}
				else{	
					XoaID(KhungDocgia, ViTriKhungDocGia, tmpId , docgia, tmp);
				}
			}
		}
	}while(entered);
	VeMenu();
}

void chinhThongTinDG(char khungNoiDung[][30], int ViTriKhung[], node &tmpDG, TreeDocgia &docgia){
	int soLuongKhung = 5;
	
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	// Kich thuoc khung
	int L =	500;
	int U = 150;
	int R =	1400;
	int D =	850;
	
	int H = 450;
	int W = 600;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	//khung
	rectangle(L-1, U, R, D);
	
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(520, 165, khungNoiDung[0]);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	//ve khung nhap lieu
	for (int i = 1; i <= soLuongKhung; i++){
		if (i != soLuongKhung){
			if (i == 2) // 650
				veKhung(650, ViTriKhung[i], khungNoiDung[i+2], 1, NEN_KHUNG, WHITE);
			else
				veKhung(650, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
		}
		else{
			veMuc2Chon(650, ViTriKhung[i], khungNoiDung[7], Sex, 1, NEN_KHUNG, WHITE);
		}
	}
	
	int pos = 2;
	int fst = tmpDG->docgia.Phai;			//SEX
	char tmptt[2];
	char tmpmt[6];
	char tmpho[30];
	char tmpten[20];
	
	strcpy(tmptt, toChars(tmpDG->docgia.Trangthai));	
	strcpy(tmpmt, toChars(tmpDG->docgia.Mathe));
	strcpy(tmpho, tmpDG->docgia.Ho);
	strcpy(tmpten, tmpDG->docgia.Ten);
	
	//in thong tin
	InThongTin(830, 250, tmpmt);
	InThongTin(830, 340, tmpho);
	InThongTin(830, 430, tmpten);
	InThongTin(830, 520, tmptt);
	veMuc2Chon(650, 610, khungNoiDung[7], Sex, fst, NEN_KHUNG, WHITE);
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	outtextxy(650, 700, "Trang thai the: ");
	outtextxy(850, 700, "0: Khoa ");
	outtextxy(850, 740, "1: Hoat dong ");
	
	while(1){
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
							pos--;
							break;
						}
					case KEY_DOWN:{
							pos++;
							break;
						}
				}
				cpos:
				if (pos == 1)
					pos = 6;
				if (pos > 6)
					pos = 2;
			}
			else if (key == '\r'){
				if (pos <= 5)
					pos++;
			}
			else if (key == 27){
				VeMenu();
				return;
			}
			
			setbkcolor(NEN_TEXT);	
			for (int i = 1; i <= 5; i++){
				if (i != 5)
					veKhung(650, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
				else
					veMuc2Chon(650, ViTriKhung[5], khungNoiDung[7], Sex, fst, NEN_KHUNG, WHITE);
				setcolor(WHITE);
			}
			setbkcolor(NEN_TEXT);
			InThongTin(830, 250, tmpmt);
			InThongTin(830, 340, tmpho);
			InThongTin(830, 430, tmpten);
			InThongTin(830, 520, tmptt);
			switch(pos){
				case 1:{
						veKhung(650, 250, khungNoiDung[3], 1, NEN_KHUNG, WHITE);
						InThongTin(830, 250, tmpmt);
						break;
					}
				case 2:{
						veKhung(650, 340, khungNoiDung[4], 1, NEN_KHUNG, WHITE);
						Nhap(830, 340, 2, key, tmpho, 50);
						break;
					}
				case 3:{
						veKhung(650, 430, khungNoiDung[5], 1, NEN_KHUNG, WHITE);
						Nhap(830, 430, 2, key, tmpten, 20);
						break;
					}
				case 4:{
						veKhung(650, 520, khungNoiDung[6], 1, NEN_KHUNG, WHITE);
						Nhap(830, 520, 0, key, tmptt, 1);
						break;
				}
				case 5:{
						veMuc2Chon(650, 610, khungNoiDung[7], Sex, fst, NEN_KHUNG, WHITE);
						while(1){
							if (kbhit()){
								char key4 = getch();
								if (key4 == 0){
									char c4Next = getch();
									switch(c4Next){
										case KEY_LEFT:{
												fst++;
												break;
											}
										case KEY_RIGHT:{
												fst--;
												break;
											}
										case KEY_UP:{
												pos--;
												goto cpos;
											}
										case KEY_DOWN:{
												pos++;
												goto cpos;
											}
									}
								}
								else if (key4 == '\r'){
									pos++;
									goto cpos;
									break;
								}
								else if (key4 == 27){
									return;
								}
								if (fst == -1)
									fst = 1;
								if (fst > 1)
									fst = 0;								
								veMuc2Chon(650, 610, khungNoiDung[7], Sex, fst, NEN_KHUNG, WHITE);
								
							}
						}
						break;
					}
				case 6:	{
						bool buttonL = 1;
						veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
						while(1){
							if(kbhit())	{
								char key5 = getch();
								char c5Next;
								if (key5 == 0){
									c5Next = getch();
									switch(c5Next){
										case KEY_UP:{
												pos--;
												veKhungNut(H, W, khungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_DOWN:{
												pos++;
												veKhungNut(H, W, khungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_LEFT:{
												buttonL ^= 1;
												break;
											}
										case KEY_RIGHT:{
												buttonL ^= 1;
												break;
											}
									}
								}
								else if (key5 == '\r'){
//									return;
									if (buttonL == 1){
										if(strlen(tmpDG->docgia.Ho) != 0 && strlen(tmpDG->docgia.Ten) != 0 && strlen(tmptt) != 0){
											tmpDG->docgia.Trangthai = ChangeCharToNum(tmptt);
											if(tmpDG->docgia.Trangthai != 0 && tmpDG->docgia.Trangthai != 1){
												ThongBao(1150, 165, Fail[2], LIGHTRED, MAU_MENU);
											} else {
												tmpDG->docgia.Mathe = ChangeCharToNum(tmpmt);
												strcpy(tmpDG->docgia.Ho, tmpho);
												strcpy(tmpDG->docgia.Ten, tmpten);
												tmpDG->docgia.Phai = fst;
												
												docgia.initdocgia();
												ThongBao(1140, 165, Success[2], GREEN, MAU_MENU);
												return;
											}
											
										}
										else{
											ThongBao(1150, 165, Fail[0], LIGHTRED, MAU_MENU);
										}
									}
									else{
										VeMenu();
										return;
									}
								}
								else if (key5 == 27){
									VeMenu();
									return;
								}
								veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
							}
						}
					}
			}
		}
	}
}

void danhSachchinhthongtinDG(TreeDocgia &docgia){
	int choosePos = 0;
	int page = 1;
	bool select;
	node tmp;
	while(1){
		chonTuDanhSachDocgia(docgia, choosePos, page, select);
		if(select){
			tmp = docgia.timDocGia(docgia.dataArr.arr[choosePos].Mathe);
			chinhThongTinDG(KhungDocgia, ViTriKhungDocGia, tmp, docgia);
		} else {
			break;
		}
	}
	VeMenu();
}

void chinhSuaDocgia(TreeDocgia &docgia){
	bool entered = false;
	docgia.initdocgia();
	do{
		bool chooseList = false;
		char tmpID[20];
		int tmpId;
		VeKhungxoaDocgia(KhungXoa, chooseList, tmpID, entered);
		if (entered){
			if (chooseList){
				return danhSachchinhthongtinDG(docgia);
			}
			else{
					node tmp;
					tmpId = ChangeCharToNum(tmpID);
					tmp = docgia.timDocGia(tmpId);
				if(tmp == NULL){
					//loi ko ton tai
					ThongBao(1180, 310, Fail[1], LIGHTRED, MAU_MENU);
				}
				else{	
					chinhThongTinDG(KhungDocgia, ViTriKhungDocGia, tmp,docgia);
				}
			}
			VeMenu();	
		}
	} while(entered);
	
}

void DanhsachDocgia(TreeDocgia &docgia){
	int choosePos = 0;
	int page = 1;
	bool select;
	docgia.initdocgia();
	chonTuDanhSachDocgia(docgia,choosePos, page, select);
	if (select = true){
		VeMenu();
		return;
	}
}

void inDocgiaquahan(struct docgiaquahan &tmpDg, int posX, int posY){
	char tmpmt[10];
	char tmpgt[10];
	char tmptt[30];
	char tmpsn[10];
	
	if(tmpDg.data.Phai == 1){
		strcpy(tmpgt,"Nam");
	} else {
		strcpy(tmpgt,"Nu");
	}
	if(tmpDg.data.Trangthai == 1){
		strcpy(tmptt,"Hoat dong");
	} else if (tmpDg.data.Trangthai == 0){
		strcpy(tmptt,"Khoa");
	}
	strcpy(tmpmt,toChars(tmpDg.data.Mathe));
	strcpy(tmpsn, toChars(tmpDg.songay));
	// in ma the
	outtextxy(posX + canLeGiua(tmpmt, textwidth(danhSachDausach[1])+sizeDanhSachDocgia[1]*2), posY, tmpmt);
	posX += textwidth(danhSachDocgia[1]) + sizeDanhSachDocgia[1]*2 + 20;
	// in ho
	outtextxy(posX + 10, posY, tmpDg.data.Ho);
	posX += textwidth(danhSachDocgia[2]) + sizeDanhSachDocgia[2]*2 - 5;
	// in ten
	outtextxy(posX + 80, posY, tmpDg.data.Ten);
	posX += textwidth(danhSachDocgia[3]) + sizeDanhSachDocgia[3]*2 - 55;
	// in gioi tinh
	outtextxy(posX + 100, posY, tmpgt);
	posX += textwidth(danhSachDocgia[4]) + sizeDanhSachDocgia[0]*2;
	// in trang thai the
	outtextxy(posX + 195, posY, tmptt);
	posX += textwidth(danhSachDocgia[4]) + sizeDanhSachDocgia[0]*2;
	// in trang so ngay qua han
	outtextxy(posX + 390, posY, tmpsn);
	
}

void inTrangDocgiaquahan(TreeDocgia &docgia ,char khungNoiDung[][30], int sizeKhungNoiDung[], int start){
	int kichThuocSTT = 40;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 7; i++){
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	}
	
	//tinh kich thuoc khung
	int L =	270;
	int U = 100;
	int R =	1650;
	int D =	870;
	
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	
	settextstyle(COMPLEX_FONT, 0, 2);
	int dis = L;
	for (int i = 0; i < 7; i++){
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 22; i++){
		dis += h+10;
		line(L, dis, R, dis);
	}
	
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = docgia.quahan.n;	
	for (int i = start; i < min(start+OBJ_PER_PAGE, Size); i++){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		
		inDocgiaquahan(docgia.quahan.arr[i], disW, dis);
		
		dis += h+5;
	}
	
	setbkcolor(MAU_NEN);
}

void chonTuDanhSachDocgiaquahan(TreeDocgia &docgia,int &stt, int &startPage, bool &selected){	
	//in danh sach
	selected = false;
	
	int limitPage = ceil(docgia.quahan.n*1.0/OBJ_PER_PAGE); // lam tron so 
	if (limitPage == 0){
		noti(Fail[12]);
	}
	else{
		// tinh thong so
		int kichThuocSTT = 40;
		int h = textheight(danhSachDausach[0])+10;
		int H = (h)*OBJ_PER_PAGE + kichThuocSTT;
		
		int W = 1380;
		int U = 100;
		int L =	350;
		
		int x = 270, 
			y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
		int yOld = y;
		
		inTrangDocgiaquahan(docgia, danhSachDocgia, sizeDanhSachDocgia, (startPage-1)*OBJ_PER_PAGE);
		showPage(1520, 880, startPage, limitPage);
		setcolor(GREEN);
		rectangle(x, y, x+W, y+h);
		while(1){
			if(kbhit())	{
				char key = getch();
				if (key == 0){
					char nextK = getch();
					switch(nextK){
						case KEY_PGDN:{
								startPage--;
								if (startPage < 1)
									startPage = limitPage;
								inTrangDocgiaquahan(docgia, danhSachDocgia, sizeDanhSachDocgia, (startPage-1)*OBJ_PER_PAGE);
								showPage(1520, 880, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_PGUP:{
								startPage++;
								if (startPage > limitPage)
									startPage = 1;
								inTrangDocgiaquahan(docgia, danhSachDocgia, sizeDanhSachDocgia, (startPage-1)*OBJ_PER_PAGE);
								showPage(1520, 880,  startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_UP:{
								stt--;
								break;
							}
						case KEY_DOWN:{
								stt++;
								break;
							}
					}
					if (stt < (startPage-1)*OBJ_PER_PAGE)
						stt = min((startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1), docgia.quahan.n- 1);
					else if (stt > (startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1) || stt > docgia.quahan.n - 1)
						stt = (startPage-1)*OBJ_PER_PAGE;
						
					y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
					// to den hinh chu nhat cu
					setcolor(BLACK);
					rectangle(x, yOld, x+W, yOld+h);
					// ve hinh chu nhat moi
					setcolor(GREEN);
					rectangle(x, y, x+W, y+h);
					yOld = y;
				}
				else if (key == 27){ //exit
					VeMenu();
					return;
				}
				else if (key == '\r'){
					selected = true;
					return;
				}
			}
		}
	}
}

void DanhsachQuahan(TreeDocgia &docgia){
	int choosePos = 0;
	int page = 1;
	bool select;
	docgia.initquahan();
	chonTuDanhSachDocgiaquahan(docgia,choosePos, page, select);
	if (select = true){
		VeMenu();
		return;
	}
}	

void SachdangMuon(TreeDocgia &docgia, DSDS &dsds){
	bool select ;
	bool enter;
	int lo = 0;
	char tmpID[5];
	node tmpnode; 
	struct nodeSach *tmpsach;	
	do{
	VeKhungNhapMathe(KhungXoa, select, docgia, dsds, tmpnode, tmpID);
		if(select){
			VeKhungindocgia(KhungDocgia, ViTriKhungDocGia, tmpnode, dsds, enter, 1);
			if(enter){
				VeMenu();
				break;
			}
		}
	} while(select);
	VeMenu();
}

//======== Muon tra ========//

void VeKhungNhapMathe(char khungNoiDung[][30],  bool &selected, TreeDocgia &docgia, DSDS &dsds, node &tmp, char *findID);
void VeKhungindocgia(char khungNoiDung[][30], int ViTriKhung[], node tmpDG,DSDS &dsds, bool &selected, bool trasach);
void VeKhungNhapMasach(char khungNoiDung[][30], DSDS &dsds, nodeSach &tmpS, int &vitri);
void Insachdangmuon(node tmpDg, DSDS dsds);
// khung nut in sach ma muon
void veKhungNut_in(char khungNoiDung[][30], bool Left, bool reset, int n){ 
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	//tinh kich thuoc khung
	int L ;
	int U ;
	int R ;
	int D ;
	if(n==1){ // n = 1; khung in doc gia
		 L = 50;
		 U = 150;
		 R = 950;
		 D = 850;
	} else if(n==0){ // n = 0 khung in sach
		 L = 960;
	 	 U = 150;
	 	 R = 1870;
		 D = 750;
	}
	
	//ve khung duoi
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);

	// Vi trí 2 nut cuoi
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	
	int MAU_NUT_HL = HL_MENU_PHU;
	if (reset)
			MAU_NUT_HL = NEN_KHUNG;
		
	setfillstyle(SOLID_FILL, MAU_NUT_HL);
	if (Left){
		bar (L, D-kichThuocNut, (L+R)/2, D);
		setbkcolor(MAU_NUT_HL);
		setcolor(WHITE);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
		setbkcolor(NEN_KHUNG);
		outtextxy((L+R)/2+midText2, D-midTextH, khungNoiDung[2]);
	} else{
		bar ((L+R)/2, D-kichThuocNut, R, D);
		setcolor(WHITE);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
		setbkcolor(MAU_NUT_HL);
		outtextxy((L+R)/2+midText2, D-midTextH, khungNoiDung[2]);
	}
	
	setcolor(BLACK);
	rectangle(L,D-kichThuocNut,R,D);
	rectangle((L+R)/2,D-kichThuocNut,R,D);						//center line
	
}
// khung nut tim ma the, ma sach
void veKhungNut2(int L, int R, char khungNoiDung[][30], bool Left, bool reset, int n){
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	//tinh kich thuoc khung
//	int L =	1220;
	int U = 300;
//	int R =	1700;
	int D =	515;	
	
	//ve khung duoi
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);

	// Vi trí 2 nut cuoi
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	
	int MAU_NUT_HL = HL_MENU_PHU;
	if (reset)
			MAU_NUT_HL = NEN_KHUNG;
		
	setfillstyle(SOLID_FILL, MAU_NUT_HL);
	if (Left){
		bar (L, D-kichThuocNut, (L+R)/2, D);
		setbkcolor(MAU_NUT_HL);
		setcolor(WHITE);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
		setbkcolor(NEN_KHUNG);
		outtextxy((L+R)/2+midText2, D-midTextH, khungNoiDung[n+1]);
	} else{
		bar ((L+R)/2, D-kichThuocNut, R, D);
		setcolor(WHITE);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
		setbkcolor(MAU_NUT_HL);
		outtextxy((L+R)/2+midText2, D-midTextH, khungNoiDung[n+1]);
	}
	
	setcolor(BLACK);
	rectangle(L,D-kichThuocNut,R,D);
	rectangle((L+R)/2,D-kichThuocNut,R,D);						//center line
	
}

void VeKhungNhapMathe(char khungNoiDung[][30],  bool &selected, TreeDocgia &docgia, DSDS &dsds, node &tmp, char *findID){
	lo:
	selected = false;
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
		
	// Kich thuoc khung
	int L =	270;
	int U = 300;
	int R =	750;
	int D =	515;
	
	int H = 450;
	int W = 600;
	
	//Ve cac khung ban dau===
	selected = false;
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	setcolor(BLACK);
	rectangle(L-1, U-1, R+1, D+1);
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(290, 315, khunginfonhap[0]);
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line((L+R)/2, D-kichThuocNut, (L+R)/2, D);						//center line
	setbkcolor(NEN_KHUNG);
	
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[3]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[4]))/2;
	int midText3 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[2]);
	setcolor(WHITE);
	rectangle(L+14, ViTriKhung[3]-21, R, ViTriKhung[3]+20+textheight(khungNoiDung[0]));
	// ve khung chon id

	setbkcolor(HL_MENU_PHU);
	setfillstyle(SOLID_FILL, HL_MENU_PHU);
	bar (L+15, ViTriKhung[3]-20, R, ViTriKhung[3]+20+textheight(khungNoiDung[1]));
	outtextxy(L+25, ViTriKhung[3], khungNoiDung[1]);
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (L+25+2*textwidth(khungNoiDung[1]), ViTriKhung[3]-10, R-15, ViTriKhung[3]+10+ textheight(khungNoiDung[1]));
	rectangle(L+25+2*textwidth(khungNoiDung[1]), ViTriKhung[3]-10, R-15, ViTriKhung[3]+10+ textheight(khungNoiDung[1])); // khung nhap
	
	// 2 nut check and exit
	setbkcolor(NEN_KHUNG);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
	outtextxy((L+R)/2+midText2, D-midTextH, khungNoiDung[4]);

	
	findID[0] = '\0';	
	int tmpId;
	int pos = 1;	
	while(1){
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
							pos--;
							break;
						}
					case KEY_DOWN:{
							pos++;
							break;
						}
				}
				cpos:
				if (pos == 0)
					pos = 2;
				if (pos > 2)
					pos = 1;
			}
			else if (key == '\r'){
				if (pos <= 2)
					pos++;
			}
			else if (key == 27){
				VeMenu();
				return;
			}
			
			setbkcolor(NEN_KHUNG);	
			setbkcolor(HL_MENU_PHU);
			setfillstyle(SOLID_FILL, HL_MENU_PHU);
			bar (L+15, ViTriKhung[3]-20, R, ViTriKhung[3]+20+textheight(khungNoiDung[1]));
			outtextxy(L+25, ViTriKhung[3], khungNoiDung[1]);
			setfillstyle(SOLID_FILL, TEXTBOX);
			bar (L+25+2*textwidth(khungNoiDung[1]), ViTriKhung[3]-10, R-15, ViTriKhung[3]+10+ textheight(khungNoiDung[1]));
			rectangle(L+25+2*textwidth(khungNoiDung[1]), ViTriKhung[3]-10, R-15, ViTriKhung[3]+10+ textheight(khungNoiDung[1]));
			
			setbkcolor(NEN_TEXT);
			InThongTin(L+35+2*textwidth(khungNoiDung[1]),ViTriKhung[3], findID);
			
			switch(pos){
				case 1:{
						setbkcolor(NEN_KHUNG);	
						setbkcolor(HL_MENU_PHU);
						setfillstyle(SOLID_FILL, HL_MENU_PHU);
						bar (L+15, ViTriKhung[3]-20, R, ViTriKhung[3]+20+textheight(khungNoiDung[1]));
						outtextxy(L+25, ViTriKhung[3], khungNoiDung[1]);
						setfillstyle(SOLID_FILL, TEXTBOX);
						bar (L+25+2*textwidth(khungNoiDung[1]), ViTriKhung[3]-10, R-15, ViTriKhung[3]+10+ textheight(khungNoiDung[1]));
						rectangle(L+25+2*textwidth(khungNoiDung[1]), ViTriKhung[3]-10, R-15, ViTriKhung[3]+10+ textheight(khungNoiDung[1]));
						Nhap(L+35+2*textwidth(khungNoiDung[1]),ViTriKhung[3],0,key,findID,5);
						break;
					}
				case 2:{
						bool buttonL = 1;
						veKhungNut2(L, R, KhungNoiDung, buttonL, 0,1);
						while(1){
							if(kbhit())	{
								char key5 = getch();
								char c5Next;
								if (key5 == 0){
									c5Next = getch();
									switch(c5Next){
										case KEY_UP:{
												pos--;
												veKhungNut2(L, R, KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_DOWN:{
												pos++;
												veKhungNut2(L, R, KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_LEFT:{
												buttonL ^= 1;
												break;
											}
										case KEY_RIGHT:{
												buttonL ^= 1;
												break;
											}
									}
								}
								else if (key5 == '\r'){
									//return;
									if (buttonL == 1){
										if(strlen(findID)!=0){
											tmpId = ChangeCharToNum(findID);
											tmp = docgia.timDocGia(tmpId);
											
											if(!tmp){
												ThongBao(500, 313, Fail[1], LIGHTRED, MAU_MENU);
												goto lo;
											}
											selected = true;
											return;
										}
										else{
											ThongBao(485, 313, Fail[0], LIGHTRED, MAU_MENU);
										}
									}
									else{
										VeMenu();
										return;
									}
								}
								else if (key5 == 27){
									VeMenu();
									goto lo;
									return;
								}
								veKhungNut2(L, R, KhungNoiDung, buttonL, 0,1);
							}
						}
					}
				
				}
		}
	}	
}
// in thong tin doc gia sau khi enter ma sach
void VeKhungindocgia(char khungNoiDung[][30], int ViTriKhung[], node tmpDG, DSDS &dsds,  bool &entered, bool trasach){
	entered = false;
	int soLuongKhung = 5;
	
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	// Kich thuoc khung
	int L =	50;
	int U = 150;
	int R =	950;
	int D =	850;
	
	int H = 450;
	int W = 600;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	//khung
	rectangle(L-1, U, R, D);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(70, 165, khungNoiDung[0]);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	
	Insachdangmuon(tmpDG,dsds);
	//ve khung nhap lieu
	for (int i = 1; i <= soLuongKhung; i++){
		if (i != soLuongKhung){
			veKhung(200, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
		}
		else{
			veMuc2Chon(200, ViTriKhung[i], khungNoiDung[7], Sex, 1, NEN_KHUNG, WHITE);
		}
	}
	
	int fst = tmpDG->docgia.Phai;			//SEX	
	char tmpmt[20];
	char tmptt[20];
	if(tmpDG->docgia.Trangthai == 1)
		strcpy(tmptt, "Hoat dong");
	else 
		strcpy(tmptt, "Khoa");	
	
	strcpy(tmpmt,toChars(tmpDG->docgia.Mathe));
	//in thong tin
	InThongTin(380, 250, tmpmt);
	InThongTin(380, 340, tmpDG->docgia.Ho);
	InThongTin(380, 430, tmpDG->docgia.Ten);
	InThongTin(380, 520, tmptt);
	veMuc2Chon(200, 610, khungNoiDung[7], Sex, fst, NEN_KHUNG, WHITE);
	
	bool buttonL = 1;
	int pos=1;
			
	veKhungNut_in(checkDS, buttonL, 0,1);
	while(1){
		if(kbhit())	{
			char key5 = getch();
			char c5Next;
			if (key5 == 0){
				c5Next = getch();
				switch(c5Next){
					case KEY_UP:{
							pos--;
							veKhungNut_in(checkDS, buttonL, 1,1);
						}
					case KEY_DOWN:{
							pos++;
							veKhungNut_in(checkDS, buttonL, 1,1);
						}
					case KEY_LEFT:{
							buttonL ^= 1;
							break;
						}
					case KEY_RIGHT:{
							buttonL ^= 1;
							break;
						}
				}
			}
			else if (key5 == '\r'){
//				return;
				if (buttonL == 1){
					if(tmpDG->docgia.Trangthai == 0){
						ThongBao(720, 165, Fail[6], LIGHTRED, MAU_MENU);
						VeMenu();
						return;
					} else if(tmpDG->docgia.quaHan() && trasach == false){
						ThongBao(600, 165, Fail[8], LIGHTRED, MAU_MENU);
						VeMenu();
						return;
					} else if(tmpDG->docgia.checkmuon() && trasach == false){
						ThongBao(700, 165, Fail[7], LIGHTRED, MAU_MENU);
						VeMenu();
						return;
					} 
					entered = true;	
					return;				
				}
				else{
					VeMenu();
					return;
				}
			}
			else if (key5 == 27){
				VeMenu();
				return;
			}
			veKhungNut_in(checkDS, buttonL, 0,1);
		}
	}
}
// in thong tin sach & xac nhan muon
void VeKhunginDausach(DSDS &dsds, struct nodeSach *tmpD, int x, node tmpDG, char ID[5]){
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	// Kich thuoc khung
	int L =	960;
	int U = 150;
	int R =	1870;
	int D = 750;  
	
	int H = 450;
	int W = 600;
	// Ve khung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(L,U,R,D);
	//	Ve khung info
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar(L,U,R,U+kichThuocSTT);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(980, 165, Khunginsachmuon[4]);
	
	// Ve vien khung
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L,U+kichThuocSTT,R,U+kichThuocSTT);
	rectangle(L,U,R,D);
	//
	//Ve cac khung ban dau===
	int pos=1;
	int Soluongkhung=4;
	for (int i = 1; i <= Soluongkhung; i++){
		veKhung(1150, ViTriKhungDauSach[i], Khunginsach[i], 0, NEN_KHUNG, WHITE);
	}
	
	//info
	char tmptt[8];
	char tmpms[20];
	if(tmpD->sach.Trangthai == 0){
		strcpy(tmptt,"Cho muon duoc");
	} else if (tmpD->sach.Trangthai == 1){
		strcpy(tmptt,"Da co nguoi muon");
	} else if(tmpD->sach.Trangthai == 2){
		strcpy(tmptt,"Da thanh ly");
	}
	
	strcpy(tmpms,tmpD->sach.Masach);
	
	InThongTin(1330, ViTriKhungDauSach[1], tmpms);
	InThongTin(1330, ViTriKhungDauSach[2], dsds.nodes[x]->Tensach);
	InThongTin(1330, ViTriKhungDauSach[3], tmptt);
	InThongTin(1330, ViTriKhungDauSach[4], tmpD->sach.Vitri);
	
	bool buttonL = 1;
	if(tmpD->sach.Trangthai != 0)
		buttonL = 0;
	node docgia;
	int Id;
	Id = ChangeCharToNum(ID);
	veKhungNut_in(Khungmuon, buttonL, 0,0);	
	while(1){
		if(kbhit())	{
			char key5 = getch();
			char c5Next;
			if (key5 == 0){
				c5Next = getch();
				switch(c5Next){
					case KEY_UP:{
							pos--;
							veKhungNut_in(Khungmuon, buttonL, 1,0);
						}
					case KEY_DOWN:{
							pos++;
							veKhungNut_in(Khungmuon, buttonL, 1,0);
						}
					case KEY_LEFT:{
							buttonL ^= 1;
							break;
						}
					case KEY_RIGHT:{
							buttonL ^= 1;
							break;
						}
				}
			}
			else if (key5 == '\r'){
//			return;
				if (buttonL == 1){
						if(tmpD->sach.Trangthai == 1){
							ThongBao(1600, 165, Fail[3], LIGHTRED, MAU_MENU);
						} else if(tmpD->sach.Trangthai == 2){
							ThongBao(1600, 165, Fail[5], LIGHTRED, MAU_MENU);
						} else if(tmpDG->docgia.checkmuon()){
							ThongBao(1600, 165, Fail[7], LIGHTRED, MAU_MENU);
							setfillstyle(SOLID_FILL, MAU_NEN);
							bar(L-1,U-1,R+1,D+1);
							return;
						} else {
							tmpDG->docgia.MuonSach(dsds, tmpD->sach.Masach);
							ThongBao(1600, 165, Success[4], GREEN, MAU_MENU);
							setfillstyle(SOLID_FILL, MAU_NEN);
							bar(L-1,U-1,R+1,D+1);
							return;
						}
					}
					else{
						setfillstyle(SOLID_FILL, MAU_NEN);
						bar(L-1,U-1,R+1,D+1);
						return;
					}
			}
			else if (key5 == 27){
				setfillstyle(SOLID_FILL, MAU_NEN);
				bar(L-1,U-1,R+1,D+1);
				return;
			}
			veKhungNut_in( Khungmuon, buttonL, 0,0);
		}
	}
}
	
void VeKhungNhapMasach(char khungNoiDung[][30], DSDS &dsds, struct nodeSach* &tmpS, int &vitri, bool &confirm){
	lo:
	confirm = false;
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
		
	// Kich thuoc khung
	int L =	1220;
	int U = 300;
	int R =	1700;
	int D =	515;
	
	int H = 450;
	int W = 600;
	//Ve cac khung ban dau===
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	setcolor(BLACK);
	rectangle(L-1, U-1, R+1, D+1);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(1240, 315, khunginfonhap[1]);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line((L+R)/2, D-kichThuocNut, (L+R)/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[3]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[4]))/2;
	int midText3 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[2]);
	setcolor(WHITE);
	
	rectangle(L+14, ViTriKhung[3]-21, R, ViTriKhung[3]+20+textheight(khungNoiDung[0]));
	// ve khung chon id

	
	setbkcolor(HL_MENU_PHU);
	setfillstyle(SOLID_FILL, HL_MENU_PHU);
	bar (L+15, ViTriKhung[3]-20, R, ViTriKhung[3]+20+textheight(khungNoiDung[1]));
	outtextxy(L+25, ViTriKhung[3], Khunginsach[1]);
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, R-15, ViTriKhung[3]+10+ textheight(khungNoiDung[1]));
	rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, R-15, ViTriKhung[3]+10+ textheight(khungNoiDung[1])); // khung nhap
	
	// 2 nut check and exit
	setbkcolor(NEN_KHUNG);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
	outtextxy((L+R)/2+midText2, D-midTextH, khungNoiDung[4]);
	int pos = 1;
	char findID[10];
	strcpy(findID, "");
	while(1){
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
							pos--;
							break;
						}
					case KEY_DOWN:{
							pos++;
							break;
						}
				}
				cpos:
				if (pos == 0)
					pos = 2;
				if (pos > 2)
					pos = 1;
			}
			else if (key == '\r'){
				if (pos <= 2)
					pos++;
			}
			else if (key == 27){
				VeMenu();
				return;
			}
			
			setbkcolor(NEN_KHUNG);	
			setbkcolor(HL_MENU_PHU);
			setfillstyle(SOLID_FILL, HL_MENU_PHU);
			bar (L+15, ViTriKhung[3]-20, R, ViTriKhung[3]+20+textheight(khungNoiDung[1]));
			outtextxy(L+25, ViTriKhung[3], Khunginsach[1]);
			setfillstyle(SOLID_FILL, TEXTBOX);
			bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, R-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
			rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, R-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
			
			setbkcolor(NEN_TEXT);
			InThongTin(L+35+2*textwidth(khungNoiDung[0]),ViTriKhung[3], findID);
			
			switch(pos){
				case 1:{
						setbkcolor(NEN_KHUNG);	
						setbkcolor(HL_MENU_PHU);
						setfillstyle(SOLID_FILL, HL_MENU_PHU);
						bar (L+15, ViTriKhung[3]-20, R, ViTriKhung[3]+20+textheight(khungNoiDung[1]));
						outtextxy(L+25, ViTriKhung[3], Khunginsach[1]);
						setfillstyle(SOLID_FILL, TEXTBOX);
						bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, R-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
						rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-10, R-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
						Nhap(L+35+2*textwidth(khungNoiDung[0]),ViTriKhung[3],-1,key,findID,10);
						break;
					}
				case 2:{
						bool buttonL = 1;
						veKhungNut2(L, R, KhungNoiDung, buttonL, 0,1);
						while(1){
							if(kbhit())	{
								char key5 = getch();
								char c5Next;
								if (key5 == 0){
									c5Next = getch();
									switch(c5Next){
										case KEY_UP:{
												pos--;
												veKhungNut2(L, R, KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_DOWN:{
												pos++;
												veKhungNut2(L, R, KhungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_LEFT:{
												buttonL ^= 1;
												break;
											}
										case KEY_RIGHT:{
												buttonL ^= 1;
												break;
											}
									}
								}
								else if (key5 == '\r'){
//									return;
									if (buttonL == 1){
										if(strlen(findID)!=0){
											vitri = Get_vitrids(dsds,findID);
											tmpS = dsds.getnodesach(findID);
											if(tmpS == NULL){
												ThongBao(1470, 313, Fail[1], LIGHTRED, MAU_MENU);
												goto lo;
											}
											confirm = true;
											return;
										}
										else{
											ThongBao(1460, 313, Fail[0], LIGHTRED, MAU_MENU);
										}
									}
									else{
										VeMenu();
										return;
									}
								}
								else if (key5 == 27){
									VeMenu();
//									goto lo;
									return;
								}
								veKhungNut2(L, R, KhungNoiDung, buttonL, 0,1);
							}
						}
					}
				
				}
		}
	}	
}

void insachmuon(struct NodeMuontra *mt, int posX, int posY, DSDS dsds){
	char tmpms[20];
	char tmpngay[2];
	char tmpthang[2];
	char tmpnam[5];
	char tmptt[20];
	int i;
	if(mt->muontra.Trangthai == 0){
		strcpy(tmptt, "Dang muon");
	} else if(mt->muontra.Trangthai == 1){
		strcpy(tmptt, "Da tra");
	} else if(mt->muontra.Trangthai == 2){
		strcpy(tmptt, "Lam mat sach");
	}
		
	int ngay = mt->muontra.Ngaymuon.ngay;
	int thang = mt->muontra.Ngaymuon.thang;
	int nam = mt->muontra.Ngaymuon.nam;
	
	strcpy(tmpngay, toChars(ngay));
	strcpy(tmpthang, toChars(thang));
	strcpy(tmpnam, toChars(nam));
	char ngaymuon[20];
	strcat(ngaymuon,tmpngay);
	strcat(ngaymuon,"/");
	strcat(ngaymuon,tmpthang);
	strcat(ngaymuon,"/");
	strcat(ngaymuon,tmpnam);

	strcpy(tmpms,mt->muontra.Masach);
	i = Get_vitrids(dsds,tmpms);

	// in ma sach
	outtextxy(posX, posY, tmpms);
	posX += textwidth(Khunginsachmuon[0]) + sizeSachdangmuon[0];
	
	// in ten sach
	outtextxy(posX + 10, posY, dsds.nodes[i]->Tensach);
	posX += textwidth(Khunginsachmuon[1]) + sizeSachdangmuon[4]*2;
	
	// in ngay muon
	outtextxy(posX + 80, posY,ngaymuon);
	posX += textwidth(Khunginsachmuon[2]) + sizeSachdangmuon[1]*2;
	// in trang thai
	outtextxy(posX, posY, tmptt);

}

void Insachdangmuon(node tmpDg, DSDS dsds){
	int kichThuocSTT = 40;
	int h = textheight(Khunginsachmuon[0]);
	int H = (h+5*2)*3 + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 3; i++){
		W += textwidth(Khunginsachmuon[i]) + sizeSachdangmuon[i]*2;
	}
	//tinh kich thuoc khung
	int L =	100;
	int U = 650;
	int R =	928;
	int D =	900;
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D-90);
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D-111);
	//in phan noi dung + gach doc
	settextstyle(COMPLEX_FONT, 0, 2);
	int dis = L;
	for (int i = 0; i < 4; i++){
		dis += sizeSachdangmuon[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, Khunginsachmuon[i]);
		dis += textwidth(Khunginsachmuon[i]) + sizeSachdangmuon[i];
		setcolor(BLACK);
		line(dis, U, dis, D-110);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 3; i++){
		dis += h+10;
		line(L, dis, R, dis);
	}
	settextstyle(COMPLEX_FONT,0,2);
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	for(struct NodeMuontra *tmpM = tmpDg->docgia.dsmuon; tmpM != NULL; tmpM = tmpM->next){
		if(tmpM->muontra.Trangthai == 0){
			dis += 5;	
			int disW = L;
			disW += textwidth(KhungXoa[0]) ;
			insachmuon(tmpM, disW, dis, dsds);
			dis += h+5;
		}
		
	}
	
		
}

void Muonsach(TreeDocgia docgia, DSDS &dsds){
	bool select ;
	bool enter;
	bool confirm ;
	int lo = 0;
	char tmpID[5];
	node tmpnode; 
	struct nodeSach *tmpsach;	
	do{
		VeKhungNhapMathe(KhungXoa, select, docgia, dsds, tmpnode, tmpID);
			if(select){
				VeKhungindocgia(KhungDocgia, ViTriKhungDocGia, tmpnode, dsds, enter, 0);
				if(enter){
						do{
							VeKhungNhapMasach(KhungXoa, dsds, tmpsach, lo, confirm);
							if(confirm){
								VeKhunginDausach(dsds, tmpsach, lo, tmpnode, tmpID);
								dsds.nodes[lo]->Solanmuon++;
								Insachdangmuon(tmpnode,dsds);
							}
						} while(confirm);
				}
				
			}
		}while(select);
		VeMenu();
			
}
// ve nut 3 chon: lam mat/ tra sach/ thoat
void Venut3chon(char khungNoiDung[][30], int choose, bool reset){
	int kichThuocSTT = 30;
	int kichThuocNut = 50;
	int L =	960;
	int U = 150;
	int R =	1870;
	int D = 750;
	int midText1 = ((R-L)/3 - textwidth(khungNoiDung[0]))/2;
	int midText2 = ((R-L)/3 - textwidth(khungNoiDung[1]))/2;
	int midText3 = ((R-L)/3 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut + 10 - textheight(khungNoiDung[0]))/2 + textheight(khungNoiDung[0]);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D-kichThuocNut/4);

	setcolor(BLACK);
	rectangle(L, D-kichThuocNut, L+(R-L)/3, D-kichThuocNut/4);
	rectangle(L+(R-L)/3, D-kichThuocNut, L+2*(R-L)/3, D-kichThuocNut/4);
	rectangle(L+2*(R-L)/3, D-kichThuocNut, R, D-kichThuocNut/4);
	
	int MAU_NUT_HL = HL_MENU_PHU;
	if (reset)
		MAU_NUT_HL = NEN_KHUNG;
	setfillstyle(SOLID_FILL, NEN_KHUNG);	
	if (choose == 1){
		bar (L+(R-L)/3, D-kichThuocNut, L+2*(R-L)/3, D-kichThuocNut/4);
		bar (L+2*(R-L)/3, D-kichThuocNut, R, D-kichThuocNut/4);
		
		setfillstyle(SOLID_FILL, MAU_NUT_HL);	
		bar (L, D-kichThuocNut, L+(R-L)/3, D-kichThuocNut/4);
		setbkcolor(MAU_NUT_HL);
		
		setcolor(WHITE);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[0]);
		
		setbkcolor(NEN_KHUNG);
		outtextxy(L+(R-L)/3+midText2, D-midTextH, khungNoiDung[1]);
		
		setbkcolor(NEN_KHUNG);
		outtextxy(L+2*(R-L)/3+midText3, D-midTextH, khungNoiDung[2]);
	}
	else if(choose == 2){
		bar (L, D-kichThuocNut, L+(R-L)/3, D-kichThuocNut/4);
		bar (L+2*(R-L)/3, D-kichThuocNut, R, D-kichThuocNut/4);
		
		setfillstyle(SOLID_FILL, MAU_NUT_HL);	
		bar (L+(R-L)/3, D-kichThuocNut, L+2*(R-L)/3, D-kichThuocNut/4);
		setbkcolor(MAU_NUT_HL);
		
		setcolor(WHITE);
		outtextxy(L+(R-L)/3+midText2, D-midTextH, khungNoiDung[1]);
		
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[0]);
		
		setbkcolor(NEN_KHUNG);
		outtextxy(L+2*(R-L)/3+midText3, D-midTextH, khungNoiDung[2]);
	}
	else if(choose == 3){
		bar (L, D-kichThuocNut, L+(R-L)/3, D-kichThuocNut/4);
		bar (L+(R-L)/3, D-kichThuocNut, L+2*(R-L)/3, D-kichThuocNut/4);
		
		setfillstyle(SOLID_FILL, MAU_NUT_HL);	
		bar (L+2*(R-L)/3, D-kichThuocNut, R, D-kichThuocNut/4);
		setbkcolor(MAU_NUT_HL);
		
		setcolor(WHITE);
		outtextxy(L+2*(R-L)/3+midText3, D-midTextH, khungNoiDung[2]);
		
		setbkcolor(NEN_KHUNG);
		outtextxy(L+(R-L)/3+midText2, D-midTextH, khungNoiDung[1]);
		
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[0]);
	}
	setcolor(BLACK);
	setcolor(BLACK);
	rectangle(L, D-kichThuocNut, L+(R-L)/3, D-kichThuocNut/4);
	rectangle(L+(R-L)/3, D-kichThuocNut, L+2*(R-L)/3, D-kichThuocNut/4);
	rectangle(L+2*(R-L)/3, D-kichThuocNut, R, D-kichThuocNut/4);
}
// khung in thong tin sach doc gia can tra || thong bao lam mat sach !
void VeKhunginsachtra(DSDS &dsds, struct nodeSach *tmpD, int x, node &tmpDG, char ID[5], TreeDocgia &docgia, bool &confirm){
	int kichThuocSTT = 50;
	int kichThuocNut = 40;
	// Kich thuoc khung
	int L =	960;
	int U = 150;
	int R =	1870;
	int D = 740;  
	
	int H = 450;
	int W = 600;
	// Ve khung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(L,U,R,D);
	//	Ve khung info
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar(L,U,R,U+kichThuocSTT);
	settextstyle(COMPLEX_FONT, 0, 2);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(980, 165, Khunginsachmuon[4]);
	// Ve vien khung
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L,U+kichThuocSTT,R,U+kichThuocSTT);
	rectangle(L,U,R,D);
	//Ve cac khung ban dau
	int Soluongkhung=4;
	for (int i = 1; i <= Soluongkhung; i++){
		veKhung(1150, ViTriKhungDauSach[i], Khunginsach[i], 0, NEN_KHUNG, WHITE);
	}
	// Ve khung lam mat sach

	//info
	char tmptt[8];
	char tmpms[20];
	if(tmpD->sach.Trangthai == 0){
		strcpy(tmptt,"Cho muon duoc");
	} else if (tmpD->sach.Trangthai == 1){
		strcpy(tmptt,"Da co nguoi muon");
	} else if(tmpD->sach.Trangthai == 2){
		strcpy(tmptt,"Da thanh ly");
	}
	
	strcpy(tmpms,tmpD->sach.Masach);
	
	InThongTin(1330, ViTriKhungDauSach[1], tmpms);
	InThongTin(1330, ViTriKhungDauSach[2], dsds.nodes[x]->Tensach);
	InThongTin(1330, ViTriKhungDauSach[3], tmptt);
	InThongTin(1330, ViTriKhungDauSach[4], tmpD->sach.Vitri);
	
	int pos=0;

	int Id;
	Id = ChangeCharToNum(ID);
	bool enter = false;
	int buttonL = 1;
	Venut3chon(Khungtra, buttonL, 0);	
	while(1){
		if(kbhit())	{
			char key5 = getch();
			char c5Next;
			if (key5 == 0){
				c5Next = getch();
				switch(c5Next){
				case KEY_LEFT:{
						buttonL --;
						break;
					}
				case KEY_RIGHT:{
						buttonL ++;
						break;
					}
				}
			}
			if(buttonL==0){
				buttonL = 3;
			}
			else if(buttonL >3){
				buttonL = 1;
			}	
			else if (key5 == '\r'){
//			return;
				if (buttonL == 1){
						if(docgia.findnodeSachtra(tmpDG->docgia.Mathe, tmpD->sach.Masach) == false){
							ThongBao(1500, 165, Fail[9], LIGHTRED, MAU_MENU);
							setfillstyle(SOLID_FILL, MAU_NEN);
							bar(L-1,U-1,R+1,D+1);
							return;
						} else {
							docgia.traSach(tmpDG->docgia.Mathe, tmpD->sach.Masach, dsds);
							ThongBao(1600, 165, Success[5], GREEN, MAU_MENU);
							setfillstyle(SOLID_FILL, MAU_NEN);
							bar(L-1,U-1,R+1,D+1);
							return;
						}
				} 
				else if (buttonL == 2){
						setfillstyle(SOLID_FILL, MAU_NEN);
						bar(L-1,U-1,R+1,D+1);
						return;
				} 
				else if (buttonL == 3){
						if(docgia.findnodeSachtra(tmpDG->docgia.Mathe, tmpD->sach.Masach) == false){
							ThongBao(1500, 165, Fail[9], LIGHTRED, MAU_MENU);
							setfillstyle(SOLID_FILL, MAU_NEN);
							bar(L-1,U-1,R+1,D+1);
							return;
						} else {
							docgia.matSach(tmpDG->docgia.Mathe, tmpD->sach.Masach, dsds);
							ThongBao(1550, 165, Success[6], GREEN, MAU_MENU);
							ThongBao(1600, 165, Success[7], LIGHTRED, MAU_MENU);
							confirm = false;
							return;
						}
				}
			}
			else if (key5 == 27){
				setfillstyle(SOLID_FILL, MAU_NEN);
				bar(L-1,U-1,R+1,D+1);
				return;
			}
			Venut3chon(Khungtra, buttonL, 0);
		}
	}
}
							
void Trasach(TreeDocgia docgia, DSDS &dsds){
	bool select ;
	bool enter;
	bool confirm ;
	int lo = 0;
	char tmpID[5];
	node tmpnode; 
	struct nodeSach *tmpsach;	
	do{
	VeKhungNhapMathe(KhungXoa, select, docgia, dsds, tmpnode, tmpID);
		if(select){
			VeKhungindocgia(KhungDocgia, ViTriKhungDocGia, tmpnode, dsds, enter, 1);
			if(enter){
					do{
						VeKhungNhapMasach(KhungXoa, dsds, tmpsach, lo, confirm);
						if(confirm){
							VeKhunginsachtra(dsds, tmpsach, lo, tmpnode, tmpID, docgia, confirm);
							Insachdangmuon(tmpnode, dsds);
						}
					} while(confirm);
					VeMenu();
			}
			
		}
	} while(select);
	VeMenu();
}












