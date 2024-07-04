#include <bits/stdc++.h>

using namespace std;
class SanPham{
	string masp, tensp;
	int sl;
	double gia;
	public:
		void nhap();
		void xuat();
		double getPrice();
		void tinhTien();
};
void SanPham::nhap() {
	cout << "Nhap ma sp: ";
	cin.ignore();
	getline(cin, masp);
	cout << "Nhap ten sp:";
	cin.ignore();
	getline(cin, tensp);
	cout << "Nhap so luong: ";
	cin >> sl;
	cout << "Nhap gia:";
	cin >> gia;
}
void SanPham::xuat(){
	cout << "Ma:" << masp << "\tTensp: " << tensp << "\tSo luong" << sl << "\tGia: " << gia << endl;
}
double SanPham::getPrice() {
	return gia;
}
void  SanPham::tinhTien(){
	cout << "Tong tien: " << sl*gia << endl;
}
int main() {
	SanPham *sp = new SanPham();
	sp->nhap();
	sp->xuat();
	sp->tinhTien();
	return 0;
}

