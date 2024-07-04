#include <bits/stdc++.h>

using namespace std;

class NhanVien{
	string ma, hoten;
	public:
		void nhap(){
			cout<<"Nhap ma: ";
			getline(cin, ma);
			cout<<"Nhap ho ten: ";
			getline(cin, hoten);
		}
		void xuat(){
			cout << "Ma: " << ma << "\tHoten: " << hoten;
		}
};
class BienChe: public NhanVien{
	double snct, hsl;
	public:
		void nhap(){
			NhanVien::nhap();
			cout << "Nhap so nam cong tac: "; cin >> snct;
			cout << "Nhap he so luong: "; cin >> hsl;
			cin.ignore();
		}
		void xuat(){
			NhanVien::xuat();
			cout << "\tSNCT: " << snct << "\tHSL: " << hsl << endl;
		}
};
class HopDong:public NhanVien{
	int ngaycong, tiencong;
	public:
		void nhap(){
			NhanVien::nhap();
			cout << "Nhap ngay cong: ";
			cin >> ngaycong;
			cout << "Nhap tien cong: ";
			cin >> tiencong;
			cin.ignore();
		}
		void xuat(){
			NhanVien::xuat();
			cout << "\tNgay cong: " << ngaycong << "\tTiencong: " << tiencong << endl;
		}
};
int main() {
	HopDong hd;
	hd.nhap();
	hd.xuat();
	BienChe bc;
	bc.nhap();
	bc.xuat();
	return 0;
}

