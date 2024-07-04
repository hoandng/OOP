#include <bits/stdc++.h>

using namespace std;

class Ns{
	string hoten;
	int tuoi;
	public:
		void nhap(){
			cin.ignore();
			cout << "Nhap ho ten: ";
			getline(cin, hoten);
			cout << "Nhap tuoi: ";
			cin >> tuoi;
		}
		void xuat(){
			cout << "ho ten: " << hoten << "\tTuoi: " << tuoi;
		}
		int getAge(){
			return tuoi;
		}
};

class Ql:public Ns{
	char chucvu[4];
	int ngaycong;
	public:
		void nhap(){
			Ns::nhap();
			cout << "Nhap chuc vu: ";
			cin >> chucvu;
			cout << "Nhap ngay cong: ";
			cin >> ngaycong;
		}
		void xuat(){
			Ns::xuat();
			cout << "\tChuc vu: " << chucvu << "\tNgay cong: " << ngaycong << endl;
		}
		float tienLuong(){
			if(strcmp(chucvu, "GD"))return 50000*ngaycong;
			if(strcmp(chucvu, "TP"))return 40000*ngaycong;
			if(strcmp(chucvu, "NV"))return 30000*ngaycong;
		}
};
int main() {
	int n;
	cout << "Nhap n:";
	cin >> n;
	Ql ds[n+5];
	for(int i = 0; i < n; i++)ds[i].nhap();
	int min_age = ds[0].getAge();
	for(int i = 0; i < n; i++){
		min_age=min_age<ds[i].getAge() ? min_age : ds[i].getAge();
	}
	for(int i = 0; i < n; i++){
		if(ds[i].getAge()==min_age)ds[i].xuat();
	}
	int max_salary = ds[0].tienLuong();
	for(int i = 0; i < n; i++){
		max_salary=min_age>ds[i].tienLuong() ? max_salary : ds[i].tienLuong();
	}
	for(int i = 0; i < n; i++){
		if(ds[i].tienLuong()==max_salary)ds[i].xuat();
	}
	return 0;
}

