#include <bits/stdc++.h>

using namespace std;

class Ungdung;
class KhachHang{
	string mkh, ten, dc, sdt, ng;
	int tgg;
	long long stg;
	public:
		void nhap();
		void xuat();
		friend double tinhlai(KhachHang &kh);
		friend class Ungdung;
		string getSDT() {
        	return sdt;
    	}
    	long long getTG() {
        	return stg;
    	}
    	int getTGG() {
        	return tgg;
    	}
};
void KhachHang::nhap(){
	cout << "Nhap ma khach hang: ";
	getline(cin,mkh);
	cout << "Nhap ten khach hang: ";
	getline(cin,ten);
	cout << "Nhap dia chi:";
	getline(cin,dc);
	cout << "Nhap sdt khach hang: ";
	getline(cin,sdt);
	cout << "Nhap ngay gui: ";
	getline(cin,ng);
	cout << "Nhap so tien gui: ";
	cin >> stg;
	cout << "Nhap thoi gian gui: ";
	cin >> tgg;
	cin.ignore();
}
void KhachHang::xuat(){
	cout <<"---------------------------"<< endl;
	cout << "MaKH: " << mkh 
		 << "\nTen:" << ten
		 << "\nDiaChi: " << dc
		 << "\nSDT: " << sdt
		 << "\nNgayGui: " << ng
		 << "\nSoTienGui: " << stg
		 << "\nThoiGianGui: " << tgg << endl;
	cout <<"---------------------------"<< endl;	 
}
double tinhlai(KhachHang &kh){
	double tl;
	switch(kh.tgg){
		case 1:
			tl=kh.stg + kh.stg*0.03;
			break;
		case 2:
			tl=kh.stg + kh.stg*0.035;
			break;
		case 3:
			tl=kh.stg + kh.stg*0.04;
			break;
		case 4:
			tl=kh.stg + kh.stg*0.05;
			break;
		case 5:
			tl=kh.stg + kh.stg*0.06;
			break;
		case 6:
			tl=kh.stg + kh.stg*0.065;
			break;
		case 7:
			tl=kh.stg + kh.stg*0.07;
			break;
		case 8:
			tl=kh.stg + kh.stg*0.073;
			break;
		case 9:
			tl=kh.stg + kh.stg*0.074;
			break;
		case 10:
			tl=kh.stg + kh.stg*0.075;
			break;
		case 11:
			tl=kh.stg + kh.stg*0.076;
			break;
		case 12:
			tl=kh.stg + kh.stg*0.08;
			break;
		default:
			cout << "Nhap lai thoi gian gui di cha\n";
			break;	
	}
	return tl;
}

class Ungdung{
	int n;
	KhachHang *ds;
	public:
		void nhap();
		void xuat();
		KhachHang getKH();
		int getN();
		friend void timkiem(string sdt, Ungdung dskh);
		friend void KHthanthiet(Ungdung dsk);
};

void Ungdung::nhap(){
	cout << "Nhap so khach hang: ";
	cin >> n;
	ds = new KhachHang[n];
	cin.ignore();
	for (int i = 0; i < n; i++){
		ds[i].nhap();
	}
}
void Ungdung::xuat(){
	for (int i = 0; i < n; i++){
		ds[i].xuat();
	}
}
KhachHang Ungdung::getKH(){
	return *ds;
}
int Ungdung::getN(){
	return n;
}
void timkiem(string sdt, Ungdung dskh){
	cout << "Nhap sdt can tim\n";
	getline(cin,sdt);
	bool check = false;
	for (int i = 0; i < dskh.getN(); i++){
		if(sdt == dskh.ds[i].getSDT()){
			dskh.ds[i].xuat();
			check = true;
		}
	}
	if(check == false){
		cout << "Khong tim thay khach hang\n";
	}
}
void KHthanthiet(Ungdung dskh){
	bool check = false;
	cout << "DS khach hang than thiet la\n";
	for(int i = 0; i < dskh.getN(); i++){
		KhachHang tmp = dskh.ds[i];
		if(tmp.getTGG()>=6 && tmp.getTG() >= 1000000000){
			tmp.xuat();
			check = true;
		}
	}
	if(check == false){
		cout << "Khong co khach hang than thiet\n";
	}
}
int main() {
//	KhachHang a;
//	KhachHang b;
//	a.nhap();
//	b.nhap();
//	a.xuat();
//	cout << tinhlai(a);
//	b.xuat();
	Ungdung ds;
	ds.nhap();
	string sdt;
//	timkiem(sdt, ds);
	KHthanthiet(ds);
	return 0;
}

