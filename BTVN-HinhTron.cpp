#include <bits/stdc++.h>

using namespace std;

class Htron{
	int hd, td, r;
	public:
		friend istream& operator >> (istream& is, Htron &ht){
			cout << "Nhap hd: "; is>>ht.hd;
			cout << "Nhap td: "; is>>ht.td;
			cout << "Nhap bk: "; is>>ht.r;
			return is;
		}
		void xuat(){
			cout << "Hinh tron tam (" << hd << ", " << td << ")" << " ban kinh " << r << endl;
		}
		int getR(){
			return r;
		}
};
int main() {
	Htron ds[5];
	for(Htron &x: ds) cin >> x;
	for(Htron x: ds) x.xuat();
	int sum = 0;
	for(Htron x: ds) sum+=x.getR()*x.getR()*3.141592;
	cout << "Trung binh dien tich cac hinh la: " << (double) sum/5;
	return 0;
}

