#include <bits/stdc++.h>

using namespace std;

struct NhanVien{
	string ten, ngayhd;
	char phong;
	double mnv, hsl, luong, bhtn, bhyt, bhxh, tl;
};

void themnv(NhanVien *nv, int n){
	for (int i = 0; i<n; i++){
		cout << "Nhap ma nv: "; cin >> nv[i].mnv;
		cout << "Nhap ho ten: "; cin.ignore(); getline(cin, nv[i].ten);
		cout << "Nhap phong: "; cin >> nv[i].phong;
		cout << "Nhap ngay hd: "; fflush(stdin); getline(cin, nv[i].ngayhd);
		cout << "Nhap hsl: "; cin >> nv[i].hsl;
	}
	
}

void timkiem(NhanVien *nv, int n){
	cout << "Nhap ten can tim kiem:";
	string ht;
	cin.ignore();
	getline(cin, ht);
	bool check = 0;
	for(int i = 0; i<n; i++){
		if(ht == nv[i].ten){
			check = 1;
			cout << "<-------------------->\n";
			cout << "Nhan vien can tim la:\n";
			cout << "Ma: " << nv[i].mnv
			 << "\tHo ten: " << nv[i].ten
			 << "\tPhong: " << nv[i].phong 
			 << setprecision(15) << "\tLuong: " << nv[i].tl << endl;
			 return;
		}
	}
	if(!check){
		cout << "Khong tim thay nhan vien\n";
	}
}

void tinhLuong(NhanVien *nv, int n){
	for (int i = 0; i<n; i++){
		nv[i].luong = nv[i].hsl * 10000000;
		nv[i].bhtn = nv[i].luong * 0.01;
		nv[i].bhyt = nv[i].luong * 0.05;
		nv[i].bhxh = nv[i].luong * 0.1;
		nv[i].tl = nv[i].luong - nv[i].bhtn - nv[i].bhyt - nv[i].bhxh;
	}
	cout << "<-------------------->\n";
	cout << "Danh sach luong cua nhan vien la:\n";
	for(int i = 0; i < n; i++) {
		cout << "Ma: " << nv[i].mnv
			 << "\tHo ten: " << nv[i].ten
			 << "\tPhong: " << nv[i].phong 
			 << setprecision(15) << "\tLuong: " << nv[i].tl << endl;
	}
}

void tinhLuongTB(NhanVien *nv, int n){
	double a[4] = {0};
	int count[4] = {0};
	for (int i = 0; i<n; i++){
		int index = nv[i].phong- 'A';
		a[index] += nv[i].tl;
		count[index] += 1;
	}
	cout << "<-------------------->\n";
	for (int i = 0; i < 4; i++){
        if (count[i] != 0) {
            cout << "Luong TB cua phong " << char(i + 'A') << " la: " << a[i] / count[i] << endl;
        } else {
            cout << "Khong co nhan vien nao o phong " << char(i + 'A') << endl;
        }
    }
}

void MinNV(NhanVien *nv, int n) {
	NhanVien min;
	min = nv[0];
	for(int i = 1; i < n; i++){
		min = min.tl > nv[i].tl ? nv[i] : min;
	}
	cout << "<-------------------->\n";
	cout << "Nhan vien co luong thap nhat la:\n";
	cout << "Ma: " << min.mnv
		 << "\tHo ten: " << min.ten
		 << "\tPhong: " << min.phong 
		 << setprecision(15) << "\tLuong: " << min.tl << endl;
}

void sapxep(NhanVien *nv, int n){
	NhanVien temp;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n ; j++){
			if (nv[i].tl> nv[j].tl){
				temp = nv[i];
				nv[i] = nv[j];
				nv[j] = temp;
			}
		}
	}
}

void inds(NhanVien *nv, int n){
	sapxep(nv, n);
	cout << "<-------------------->\n";
	cout << "Danh sach nhan vien la:\n";
	for (int i = 0; i < n; i++){
		cout << "Ma: " << nv[i].mnv
			 << "\tHo ten: " << nv[i].ten
			 << "\tPhong: " << nv[i].phong 
			 << setprecision(15) << "\tLuong: " << nv[i].tl << endl;
	}
}
int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	NhanVien nv[100];
	themnv(nv, n);
	tinhLuong(nv, n);
	timkiem(nv, n);
	tinhLuongTB(nv, n);
	MinNV(nv, n);
	inds(nv, n);
	return 0;
}

