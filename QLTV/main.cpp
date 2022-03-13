#include "menu.h"
#include "cautrucdulieu.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
	KhoiTaoChuongTrinh();
	DSDS ListDausach;
	TreeDocgia docgia;
	loaddocgia(docgia);
	LoadDs(ListDausach);
	Menu(ListDausach, docgia);
	return 0;
}





