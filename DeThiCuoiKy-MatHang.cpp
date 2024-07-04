#include <bits/stdc++.h>

using namespace std;

class MatHang{
	string ten;
	int sl, dongia;
	public:
		MatHang(string ten = "", int sl = 0; int dongia = 0){
			this->ten = ten;
			this->sl = sl;
			this->dongia = dongia;
		}
		
};

class Thue:public MatHang{
	int tlt;
	public:
		Thue(string ten = "", int sl = 0; int dongia = 0, int tlt = 0):MatHang(ten,sl,dongia){
			this->tlt = tlt;
		}
};
int main() {

	return 0;
}

