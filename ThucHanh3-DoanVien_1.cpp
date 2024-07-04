#include <bits/stdc++.h>

using namespace std;

class DoanVien{
	string hoten;
	char *quequan;
	int namvaodoan;
	public:
		DoanVien(string hoten="A", char quequan[]="Ha noi", int namvaodoan=2000){
			this->quequan = new char(20);
			this->hoten=hoten;
			this->quequan=quequan;
			this->namvaodoan=namvaodoan;
		}
		void nhap(){
			quequan = new char(20);
			cout << "Nhap ho ten: "; getline(cin, hoten);
			cout << "Nhap que quan: "; cin.getline(quequan, 20);
			cout << "Nhap nam vao doan: "; cin >> namvaodoan;
		}
		void xuat(){
			cout << "Ho ten: " << hoten << "\tQue quan: " << quequan << "\tNam vao doan:" << namvaodoan << endl;
		}
		~DoanVien(){
			delete[] quequan;
		}
		DoanVien(const DoanVien &dv){
			this->quequan = new char(20);
			this->hoten=dv.hoten;
			this->quequan=dv.quequan;
			this->namvaodoan=dv.namvaodoan;
		}
		void operator = (const DoanVien &dv){
			this->quequan = new char(20);
			this->hoten=dv.hoten;
			this->quequan=dv.quequan;
			this->namvaodoan=dv.namvaodoan;
		}
};
int main() {
	DoanVien A("Nguyen Van Nam", "Ha Noi", 2020), B;
	B.nhap();
	DoanVien C, D=A;
	C = B;
	A.xuat();
	B.xuat();
	C.xuat();
	D.xuat();
	return 0;
}

