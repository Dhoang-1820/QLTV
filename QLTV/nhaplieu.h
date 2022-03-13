#pragma once
#include <math.h>

//==
bool  CheckLetter(char s);
bool  CheckNum(char s);
bool  KhoaNhapLieu(char s[], int n);
char* toChars(unsigned long long num);
int   KiemtraNhapLieu(char c, char s[]);
int   canLeGiua(char *S, int dis);
void  AddChuoi(char c, char s[]);
void  Nhap(int x, int y, int check, char c, char s[], int n);
unsigned long long  ChangeCharToNum (char s[]);
//

bool CheckLetter(char s){ // kiem tra la chu
	if((s>= 65 && s<= 90) || (s>= 97 && s<= 122 ) || (s==32) || (s==44) || (s==45) || (s==38)){
		return 1;
	}
	return 0;	 
}

bool CheckNum(char s){ // kiem tra la so
		if(s >= 48 && s <= 57){
			return 1;
		}
	return 0;	 
}

unsigned long long ChangeCharToNum (char s[]){ // chuyen ky tu sang so
	unsigned long long n = 0;
	for(int i = 0; i<strlen(s);i++){
		n *= 10;
		n += (s[i]-48);
	}
	return n;
}

char* toChars(unsigned long long num){
	char* a = new char[100];
	if (num == 0){
		a[1] = '\0';
		a[0] = '0';
	}
	else{
		int l = floor(log10(num)+1);
		a[l--] = '\0';
		while(num>0){
			a[l--] = num%10+48; //to char
			num /= 10;
		}
	}
	return a;
}
void AddChuoi(char c, char s[]){
	strncat(s, &c, 1);
}

int KiemtraNhapLieu(char c, char s[]){
	if(strlen(s) == 0 && c == ' ') // khoa khoang trong
		return 0;
	else	
		if(strlen(s) != 0 && s[strlen(s)-1] == ' ' && c == ' ') // khoa 2 khoang trong 
			return 0;	
	else	
		if((strlen(s) != 0 && s[strlen(s)-1] == ' ' && c != ' ') || (strlen(s) == 0 && c != ' ')) // viet hoa ki tu sau dau cach
			return -1;
	return 1;	 
}

bool KhoaNhapLieu(char s[], int n){
	if(strlen(s)<n)
		return 1;
	return 0;	
}

void Nhap(int x, int y,int check, char c, char s[], int n){
	if(c == 8 && strlen(s) != 0){ //8: Backspace
		s[strlen(s)-1] = '\0';
	}  
	c = tolower(c);
	if(check == 0){ // So
		if(CheckNum(c) && KhoaNhapLieu(s,n)){
			if(KiemtraNhapLieu(c,s) == 1 || KiemtraNhapLieu(c,s) == -1){
				AddChuoi(c,s);
			}
		}
	} else if(check == 1){
		if(CheckNum(c) && KhoaNhapLieu(s,n) && c != 48){
			if(KiemtraNhapLieu(c,s) == 1 || KiemtraNhapLieu(c,s) == -1){
				AddChuoi(c,s);
			}
		}
	}
	else if(check == -1){ // Chu in hoa
		if((CheckNum(c) || CheckLetter(c)) && KhoaNhapLieu(s,n) && c != ' '){
			if(KiemtraNhapLieu(c,s) == 1|| KiemtraNhapLieu(c,s) == -1){
				c = toupper(c);
				AddChuoi(c,s);
			} 
		}
	}
	else if(check == 2){ // form Aaa Bbb Ccc
		if((CheckNum(c) || CheckLetter(c)) && KhoaNhapLieu(s,n)){
			if(KiemtraNhapLieu(c,s) == 1){
				AddChuoi(c,s);
			}
			else
				if(KiemtraNhapLieu(c,s) == -1){
					c = toupper(c);
					AddChuoi(c,s);
				}
		}
	} 
	setcolor(WHITE);
	setbkcolor(NEN_TEXT);
	outtextxy(x,y,s);
}

int canLeGiua(char *S, int dis){
	return (dis-textwidth(S))/2;
}


