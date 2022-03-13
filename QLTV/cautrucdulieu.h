#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include<ctime>
#include "nhaplieu.h"

#define Maxdausach 10000
#define maxN 99999
#define minN 10000
using namespace std;

int random(int min, int max){
    return minN + rand() % (maxN + 1 - minN);
}

int getyearsystem(){
	time_t now = time(0);
	tm* ltm = localtime(&now);
	return (1900 + ltm->tm_year); 
}

// Cau truc danh muc sach: Danh sach lien ket don.
struct Sach {
	char Masach[20];
	int Trangthai; // 0: cho muon dc; 1: da co nguoi muon; 2: sach da thanh ly
	char Vitri[50];
	Sach() {
		Masach[0] = '\0';
		Vitri[0] = '\0';
	}
};
struct nodeSach {
	Sach sach;
	nodeSach* next;
};
typedef struct nodeSach* pDMS;

// Cau truc dau sach: Danh sach tuyen tinh.
struct Dausach {
	char ISBN[15];
	char Tensach[32];
	unsigned int Sotrang;
	char Tacgia[25];
	unsigned int Namxb;
	char Theloai[30];
	int Solanmuon;
	int soluong; // so luong sach moi dau sach
	nodeSach *dms = NULL;
	Dausach() {
		ISBN[0] = '\0';
		Tensach[0] = '\0';
		Tacgia[0] = '\0';
		Theloai[0] = '\0';
		soluong = 0;
		Solanmuon = 0;
	}
	// them sach
	void Insert_last(Sach news) {
		pDMS p = new nodeSach;
		if (dms == NULL) {
			p->sach = news;
			p->next = NULL;
			dms= p;
		}
		else {
			for (pDMS last = dms; ; last = last->next) {
				if (last->next == NULL) {
					p->sach = news;
					p->next = NULL;
					last->next = p;
					break;
				}
			}
		}
	}
};
// danh cho tim kiem
struct arrdausach{
	Dausach* arr;
	int n;	
	void Add(Dausach* data) {
		n++;
		arr = (Dausach*)realloc(arr, n * sizeof(Dausach));
		strcpy(arr[n-1].ISBN, data->ISBN);
		strcpy(arr[n-1].Tacgia, data->Tacgia);
		strcpy(arr[n-1].Tensach, data->Tensach);
		strcpy(arr[n-1].Theloai, data->Theloai);
		arr[n-1].Namxb = data->Namxb;
		arr[n-1].Sotrang = data->Sotrang;
	}
	void init(){
		arr = NULL;
		n = 0;
	}
	~arrdausach(){
		free(arr);
	}
};

struct DS_Dausach {
	int n;
	Dausach* nodes[Maxdausach];
	arrdausach Arrds;
	
	DS_Dausach() {
		n = 0;
	}
	struct Dausach* Search_ISBN(char tmpISBN[15]) {
		for (int i = 0; i < n; i++) {
			if (strcmp(nodes[i]->ISBN, tmpISBN) == 0) {
				return nodes[i];
			}
		}
		return NULL;
	}

	void addsach(int pos, Sach& newsach) {
		struct Dausach* p = nodes[pos];
		p->Insert_last(newsach);
		nodes[pos]->soluong++;
	}
// 5 --> 3
//  2 3 4 3
	char* randomDms(int pos) {
		char tmp[20];
		char newms[20];
		strcpy(tmp, nodes[pos]->ISBN);
		strcat(tmp, "-");
		strcat(tmp, toChars(nodes[pos]->soluong));
		strcpy(newms, tmp);
		return newms;
	}

	void setStatus(char* maSach, int tt) {
		for (int i = 0; i < n; i++) {
			nodeSach* walker = this->nodes[i]->dms;
			while (walker) {
				if (!strcmp(maSach, walker->sach.Masach)) {
					walker->sach.Trangthai = tt;
				}
				walker = walker->next;
			}
		}
	}

	nodeSach* getnodesach(char* masach) {
		for (int i = 0; i < n; i++) {
			if (strstr(masach, nodes[i]->ISBN) != NULL) {
				nodeSach* walker = nodes[i]->dms;
				while (walker) {
					if (!strcmp(masach, walker->sach.Masach))
						return walker;
					walker = walker->next;
				}
			}
		}
		return NULL;
	}

	bool comparedausach(Dausach* a, Dausach* b) {
		if (strcmp(a->Theloai, b->Theloai) < 0) {
			return false;
		}
		else if (strcmp(a->Theloai, b->Theloai) > 0) {
			return true;
		}
		else {
			if (strcmp(a->Tensach, b->Tensach) < 0) {
				return false;
			}
		}
		return true;
	}

	bool comparesolanmuon(int a, int b) {
		return (a <= b);
	}

	void swap(int a, int b) {
		Dausach* tmp = nodes[a];
		nodes[a] = nodes[b];
		nodes[b] = tmp;
	}

	int partition(int low, int high, bool mode) {
		int pilot = high;
		int i = low - 1;
		for (int j = low; j < high; j++) {
			if (mode ? comparedausach(nodes[pilot], nodes[j]) : comparesolanmuon(nodes[pilot]->Solanmuon, nodes[j]->Solanmuon)) {
				i++;
				swap(i, j);
			}
		}
		swap(i + 1, high);
		return i + 1;
	}

	void quickSort(int low, int high, bool mode) {
		if (low < high) {
			int p = partition(low, high, mode);
			quickSort(low, p - 1, mode);
			quickSort(p + 1, high, mode);
		}
	}

	void sort(bool mode) {
		quickSort(0, n - 1, mode);
	}
	// danh cho tim kiem
	void search(char *tensach){
		for(int i=0; i<n; i++){
			if(strstr(nodes[i]->Tensach, tensach)){
				Arrds.Add(nodes[i]);
			}
		}
	}
	int searchIsbn(char *ISBN){ 
		for (int i = 0; i < n; i++) {
			if (strcmp(nodes[i]->ISBN, ISBN) == 0) {
				return i;
			}
		}
		return -1;
	}
	
}; typedef struct DS_Dausach DSDS;



//===== Them dau sach ====== //
// insert last
void Insert(DSDS& dsds, struct Dausach* newnodes) {
	dsds.nodes[dsds.n] = newnodes;
	dsds.n++;
	/*int j;
  for(j = dsds.n-1; j >= l; j--)
	  dsds.nodes[j+1] = dsds.nodes[j];
  dsds.nodes[l] = newnodes;
  dsds.n ++;*/
}

int Get_vitrids(DSDS& dsds, char* masach) {
	for (int i = 0; i < dsds.n; i++) {
		if (strstr(masach, dsds.nodes[i]->ISBN) != NULL)
			return i;
	}
	return NULL;
}

int isFull(DSDS& dsds) {
	for (int i = 0; i < dsds.n; i++) {
		return dsds.n == Maxdausach;
	}
}
// xoa theo vi tri
void DeleteDs(DSDS& dsds, int pos) {
	int j;
	for (j = pos + 1; j < dsds.n; j++)
		dsds.nodes[j - 1] = dsds.nodes[j];
	dsds.n--;

}
// xoa theo  Isbn
void DeleteISBN(DSDS& dsds, char tmpISBN[15]) {
	for (int i = 0; i < dsds.n; i++) {
		if (strcmp(dsds.nodes[i]->ISBN, tmpISBN) == 0) {
			DeleteDs(dsds, i);
			break;
		}
	}
}

// Cau truc muon tra: Danh sach lien ket don.
struct DMY {
	int ngay;
	int thang;
	int nam;
	int sec;
};

struct Muontra {
	char Masach[20];
	DMY Ngaymuon;
	DMY Ngaytra;
	int Trangthai; // 0: dang muon; 1: da tra; 2: lam mat sach(da thanh ly)	
};

struct NodeMuontra {
	Muontra muontra;
	NodeMuontra* next;
};

// Cau truc doc gia: Cay nhi phan tim kiem.
struct Docgia {
	int Mathe;
	char Ho[30];
	char Ten[20];
	bool Phai = true; // 1. Nam, 0. Nu.
	int Trangthai; // 0: Khoa, 1: Hoat dong

	NodeMuontra* dsmuon = NULL;  // First
	NodeMuontra* tail = NULL;	// Tail
	int soSach;

	void add(Muontra data) { // insert_last
		NodeMuontra* tmp = new NodeMuontra;
		tmp->next = NULL;
		tmp->muontra = data;
		if (dsmuon == NULL) {
			dsmuon = tail = tmp;
		}
		else {
			tail->next = tmp;
			tail = tmp;
		}
		soSach++;
	}

	bool quaHan() {
		time_t now = time(0);
		if (dsmuon == NULL) return false;
		else {
			NodeMuontra* walker = dsmuon;
			while (walker) {
				if (walker->muontra.Trangthai == 0) {
					if (now - walker->muontra.Ngaymuon.sec >= 604800) { 
						return true;
					}
				}
				walker = walker->next;
			}
		}
		return false;
	}
	
	bool checkmuon() {
		if (dsmuon == NULL) return false;
		else {
			int count = 0;
			NodeMuontra* walker = dsmuon;
			while (walker) {
				if (walker->muontra.Trangthai == 0) count++;
				walker = walker->next;
			}
			if (count == 3) return true;
		}
		return false;
	}
	// check doc gia dang muon sach -> k the xoa
	bool checkdangmuon(){
		if(dsmuon == NULL) return false;
		else{
			NodeMuontra* walker = dsmuon;
			while(walker){
				if(walker->muontra.Trangthai == 0) return true;
				walker = walker->next;
			}
		}
		return false;
	}
	
	void MuonSach(DSDS& listsach, char masach[20]) {
		time_t now = time(0);
		tm* ltm = localtime(&now);
		Muontra data;
		strcpy(data.Masach, masach);
		data.Ngaymuon.nam = 1900 + ltm->tm_year;
		data.Ngaymuon.thang = 1 + ltm->tm_mon;
		data.Ngaymuon.ngay = ltm->tm_mday;
		data.Ngaymuon.sec = now;
		data.Trangthai = 0;
		this->add(data);
		listsach.setStatus(masach, 1);
//		return;
	}

	void traSach(DSDS& listsach, NodeMuontra* sachtra) {
		time_t now = time(0);
		tm* ltm = localtime(&now);
		sachtra->muontra.Ngaytra.nam = 1900 + ltm->tm_year;
		sachtra->muontra.Ngaytra.thang = 1 + ltm->tm_mon;  // so thang trong nam tu 0-11
		sachtra->muontra.Ngaytra.ngay = ltm->tm_mday;
		sachtra->muontra.Ngaytra.sec = now;
		sachtra->muontra.Trangthai = 1;
		listsach.setStatus(sachtra->muontra.Masach, 0);
	}

	void matSach(DSDS& listsach, NodeMuontra* sachtra) {
		sachtra->muontra.Trangthai = 2;
		listsach.setStatus(sachtra->muontra.Masach, 2);
	}
	
	// doc file muon tra
	void read(Muontra data) {
		NodeMuontra* tmp = new NodeMuontra;
		tmp->next = NULL;
		tmp->muontra = data;
		if (this->dsmuon == NULL) {
			this->dsmuon = this->tail = tmp;
		}
		else {
			this->tail->next = tmp;
			this->tail = tmp;
		}
	}
};

struct NodeDocgia {
	Docgia docgia;
	NodeDocgia* left = NULL;
	NodeDocgia* right = NULL;
};
typedef NodeDocgia* node;

struct arrdocgia {
	Docgia* arr;
	int n;
private:
	bool compareTen(Docgia a, Docgia b) {
		int result = strcmp(a.Ten, b.Ten);
		if (result > 0) return true;
		else if (result < 0) return false;
		else {
			result = strcmp(a.Ho, b.Ho);
			if (result > 0) return true;
			else if (result < 0) return false;
		}
		return true;
	}

	bool compareThe(int a, int b) {
		return (a > b);
	}

	void swap(int a, int b) {
		Docgia tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}

	int partition(int low, int high, bool mode) {
		int pilot = high;
		int i = low - 1;
		for (int j = low; j < high; j++) {
			if (mode ? compareTen(arr[pilot], arr[j]) : compareThe(arr[pilot].Mathe, arr[j].Mathe)) {
				i++;
				swap(i, j);
			}
		}
		swap(i + 1, pilot);
		return i + 1;
	}

	void quickSort(int low, int high, bool mode) {
		if (low < high) {
			int p = partition(low, high, mode);
			quickSort(low, p - 1, mode);
			quickSort(p + 1, high, mode);
		}
	}
public:
	arrdocgia() {
		arr = NULL;
		n = 0;
	}
	~arrdocgia() {
		free(arr);
	}
	void sort(bool mode) {
		quickSort(0, n - 1, mode);
	}

	void add(Docgia data) {
		n++;
		arr = (Docgia*)realloc(arr, n * sizeof(Docgia));
		arr[n - 1] = data;
	}

	void del(int mathe) {
		for (int i = 0; i < n; i++) {
			if (arr[i].Mathe == mathe) {
				for (int j = i; j < n; j++) {
					arr[j] = arr[j + 1];
				}
				break;
			}
		}
		n--;
	}
	void init() {
		arr = NULL;
		n = 0;
	}
};

struct docgiaquahan{
	Docgia data;
	int songay = 0;
};

struct arrquahan {
	docgiaquahan* arr;
	int n;
	
	void initialization(){
		arr = NULL;
		n = 0;
	}
	
	void add(Docgia data) {
		time_t now = time(0);
		NodeMuontra* walker = data.dsmuon;
		while (walker) {
			if (walker->muontra.Trangthai == 0) {
				if (now - walker->muontra.Ngaymuon.sec >= 604800) {
					n++;
					arr = (docgiaquahan*)realloc(arr, n * sizeof(docgiaquahan));
					arr[n - 1].data = data;
					arr[n - 1].songay = ceil((now - walker->muontra.Ngaymuon.sec - 604800)*1.0 / 86400);
				}
			}
			walker = walker->next;
		}
	}
	
	bool compareThe(int a, int b) {
		return (a < b);
	}
	void swap(int a, int b) {
		docgiaquahan tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}
	int partition(int low, int high) {
		int pilot = high;
		int i = low - 1;
		for (int j = low; j < high; j++) {
			if (compareThe(arr[pilot].songay, arr[j].songay)) {
				i++;
				swap(i, j);
			}
		}
		swap(i + 1, high);
		return i + 1;
	}
	void quickSort(int low, int high) {
		if (low < high) {
			int p = partition(low, high);
			quickSort(low, p - 1);
			quickSort(p + 1, high);
		}
	}
	void sort() {
		quickSort(0, n - 1);
	}
	~arrquahan(){
		free(arr);
	}
};

struct TreeDocgia {
	int n = 0;
	node root = NULL;

	arrdocgia dataArr;
	arrquahan quahan;

	node addNode(node tmp, Docgia data) {
		if (tmp == NULL) {
			tmp = new NodeDocgia;
			tmp->docgia = data;
			tmp->left = tmp->right = NULL;
		}
		else if (data.Mathe > tmp->docgia.Mathe) {
			tmp->right = addNode(tmp->right, data);
		}
		else {
			tmp->left = addNode(tmp->left, data);
		}
		return tmp;
	}

	node min(node tmp) {
		if (tmp->left == NULL) return tmp;
		else return min(tmp->left);
	}

	node delNode(node tmp, int mathe) {
		node temp;
		if (tmp == NULL) return tmp;
		else if (mathe > tmp->docgia.Mathe) {
			tmp->right = delNode(tmp->right, mathe);
		}
		else if (mathe < tmp->docgia.Mathe) {
			tmp->left = delNode(tmp->left, mathe);
		}
		else {
			if (tmp->left && tmp->right) {
				temp = min(tmp->right);
				tmp->docgia = temp->docgia;
				tmp->right = delNode(tmp->right, tmp->docgia.Mathe);
			}
			else {
				temp = tmp;
				if (tmp->left == NULL) {
					tmp = tmp->right;
				}
				else {
					tmp = tmp->left;
				}
				delete temp;
			}
		}
		return tmp;
	}

	node findNode(node tmp, int mathe) {
		if (tmp == NULL) return tmp;
		else if (tmp->docgia.Mathe > mathe) {
			return findNode(tmp->left, mathe);
		}
		else if (tmp->docgia.Mathe < mathe) {
			return findNode(tmp->right, mathe);
		}
		else {
			return tmp;
		}
	}
	
	node timDocGia(int mathe) {
		node walker = root;
		return findNode(walker, mathe);
	}
	
	int sinhMathe(){
		int r;
		node n;
		srand(time(NULL));
		r = random(minN,maxN);
		n = timDocGia(r);
		while(n != NULL){
			r = random(minN,maxN);
			n = timDocGia(r);
		};
		return r;
	}

	void themDocgia(Docgia data) {
		data.soSach = 0;
		root = addNode(root, data);
		dataArr.add(data);
	}

	void xoaDocgia(int mathe) {
		root = delNode(root, mathe);
		dataArr.del(mathe);
		this->n--;
	}

	// kiem tra doc gia co dang muon sach nay?
	bool findnodeSachtra(int mathe, char* masach){
		node docgia = findNode(root, mathe);
		NodeMuontra* walker = docgia->docgia.dsmuon;
		for (walker; walker != NULL; walker = walker->next){
			if(strcmp(walker->muontra.Masach, masach) == 0 && (walker->muontra.Trangthai == 0))
				return true;
		}
		return false;
	}
	
	void traSach(int mathe, char* masach, DSDS& ds) {
		node docgia = findNode(root, mathe);
		NodeMuontra* walker = docgia->docgia.dsmuon;
		for (walker; walker != NULL; walker = walker->next) {
			if ((strcmp(walker->muontra.Masach, masach) == 0) && (walker->muontra.Trangthai == 0)) {
				docgia->docgia.traSach(ds, walker);
			} 
		}
		
	}
	
	void matSach(int mathe, char* masach, DSDS& ds){
		node docgia = findNode(root, mathe);
		NodeMuontra* walker = docgia->docgia.dsmuon;
		for (walker; walker != NULL; walker = walker->next) {
			if ((strcmp(walker->muontra.Masach, masach) == 0) && (walker->muontra.Trangthai == 0)) {
				docgia->docgia.matSach(ds, walker);
			} 
		}
		docgia->docgia.Trangthai = 0;
	}
	

	void theotenmode() {
		dataArr.sort(true);

	}
	void theoidmode() {
		dataArr.sort(false);
	}
	void checkquahan(Docgia data) {
		if (data.quaHan()) {
			quahan.add(data);
		}
	}
	void Rcheckquahan(node t) {
		if (t == NULL) return;
		checkquahan(t->docgia);
		Rcheckquahan(t->left);
		Rcheckquahan(t->right);
	}
	void initquahan() {
		node walker = root;
		quahan.initialization();
		Rcheckquahan(walker);
		quahan.sort();
	}
	void adddg(node t){
		if(t == NULL) return;
		adddg(t->left);
		dataArr.add(t->docgia);
		adddg(t->right);
	}
	void initdocgia(){
		node walker = root;
		dataArr.init();
		adddg(walker);
	}

};

// DOC & GHI FILE //

void WriteDs(ofstream& file, struct Dausach* p) {
	file << p->ISBN << endl;
	file << p->Tensach << endl;
	file << p->Sotrang << endl;
	file << p->Tacgia << endl;
	file << p->Namxb << endl;
	file << p->Theloai << endl;
}

void SaveDs(DSDS& dsds) {
	ofstream fileDs;
	ofstream logs;
	ofstream fileDms;
	fileDs.open("list_dausach.txt", ios::out);
	fileDms.open("list_dms.txt", ios::out);
	logs.open("Logs.txt", ios::out);
	logs << dsds.n << endl;
	for (int i = 0; i < dsds.n; i++) {
		WriteDs(fileDs, dsds.nodes[i]);
		fileDms << dsds.nodes[i]->Solanmuon << endl;
		fileDms << dsds.nodes[i]->soluong << endl;
		nodeSach* walker = dsds.nodes[i]->dms;
		while(walker) {
			fileDms << walker->sach.Masach << endl;
			fileDms << walker->sach.Trangthai << endl;
			fileDms << walker->sach.Vitri << endl;
			walker = walker->next;
		}
	}
	fileDs.close();
	fileDms.close();
	logs.close();
}

void ReadDs(ifstream& file, struct Dausach* p) {
	file.getline(p->ISBN, sizeof(p->ISBN));
	//	file>>p->ISBN;
	file.getline(p->Tensach, sizeof(p->Tensach));
	file >> p->Sotrang;
	file.ignore();
	file.getline(p->Tacgia, sizeof(p->Tacgia));
	file >> p->Namxb;
	file.ignore();
	file.getline(p->Theloai, sizeof(p->Theloai));
}

void LoadDs(DSDS& dsds) {
	ifstream fileDs;
	ifstream fileDms;
	ifstream logs;
	fileDs.open("list_dausach.txt", ios::in);
	fileDms.open("list_dms.txt", ios::in);
	logs.open("Logs.txt", ios::in);
	logs >> dsds.n;
	for (int i = 0; i < dsds.n; i++) {
		dsds.nodes[i] = new Dausach;
		ReadDs(fileDs, dsds.nodes[i]);
		//Dms	
		fileDms >> dsds.nodes[i]->Solanmuon;
		fileDms >> dsds.nodes[i]->soluong;
		for (int j = 0; j < dsds.nodes[i]->soluong; j++) {
			struct Sach p;
			fileDms >> p.Masach;
			fileDms >> p.Trangthai;
			fileDms.ignore();
			fileDms.getline(p.Vitri, sizeof(p.Vitri));
			dsds.nodes[i]->Insert_last(p);
		}
	}

	fileDs.close();
	fileDms.close();
}

void infodocgia(ifstream& file,Docgia& data) {
	file >> data.Mathe;
	file.ignore();
	file.getline(data.Ho, sizeof(data.Ho));
	file.getline(data.Ten, sizeof(data.Ten));
	file >> data.Trangthai;
	file.ignore();
	file >> data.Phai;
	file.ignore();
}

void infomt(ifstream& file, node& t) {
	Muontra data;
	file >> t->docgia.soSach;
	for (int i = 0; i < t->docgia.soSach; i++) {
		file >> data.Masach;
		file >> data.Ngaymuon.sec;
		file >> data.Ngaymuon.ngay;
		file >> data.Ngaymuon.thang;
		file >> data.Ngaymuon.nam;
		file >> data.Trangthai;
		if (data.Trangthai) {
			file >> data.Ngaytra.sec;
			file >> data.Ngaytra.ngay;
			file >> data.Ngaytra.thang;
			file >> data.Ngaytra.nam;
		}
		t->docgia.read(data);
	}
}

void loadinfomt(ifstream& file, node& t) {
	if (t == NULL) return;
	loadinfomt(file, t->left);
	infomt(file, t);
	loadinfomt(file, t->right);
}

void loaddocgia(TreeDocgia& docgia) {
	ifstream filedg;
	ifstream filemt;
	filedg.open("data_docgia.txt",ios::in);
	filemt.open("data_muontra.txt", ios::in);
	filedg >> docgia.n;
	for (int i = 0; i < docgia.n; i++) {
		Docgia data;
		infodocgia(filedg,data);
		docgia.themDocgia(data);
	}
	node walker = docgia.root;
	loadinfomt(filemt, walker);
	filedg.close();
	filemt.close();
}

void saveinfo(ofstream& file, Docgia docgia) {
	file << docgia.Mathe << endl;
	file << docgia.Ho << endl;;
	file << docgia.Ten << endl;;
	file << docgia.Trangthai << endl;;
	file << docgia.Phai << endl;;
}

void rSaveTree(ofstream& file, node& t) {
	if (t == NULL) return;
	rSaveTree(file,t->left);
	saveinfo(file,t->docgia);
	rSaveTree(file,t->right);
}


void saveinfomt(ofstream& file, Docgia docgia){
	file << docgia.soSach << endl;
		NodeMuontra* walker = docgia.dsmuon;
		while (walker) {
			file << walker->muontra.Masach << endl;
			file << walker->muontra.Ngaymuon.sec << endl;
			file << walker->muontra.Ngaymuon.ngay << endl;
			file << walker->muontra.Ngaymuon.thang << endl;
			file << walker->muontra.Ngaymuon.nam << endl;
			file << walker->muontra.Trangthai << endl;
			if (walker->muontra.Trangthai) {
				file << walker->muontra.Ngaytra.sec << endl;
				file << walker->muontra.Ngaytra.ngay << endl;
				file << walker->muontra.Ngaytra.thang << endl;
				file << walker->muontra.Ngaytra.nam << endl;
			} 	
			walker = walker->next;
		}
}
void savemt(ofstream& file, node& t) {
	if (t == NULL) return;
	savemt(file, t->left);
	saveinfomt(file, t->docgia);
	savemt(file, t->right);
}
void savedocgia(TreeDocgia docgia) {
	ofstream filedg;
	ofstream filemt;
	filedg.open("data_docgia.txt", ios::out);
	filemt.open("data_muontra.txt", ios::out);
	filedg << docgia.n << endl;
	rSaveTree(filedg, docgia.root);
	savemt(filemt, docgia.root);
	filedg.close();
	filemt.close();
}

