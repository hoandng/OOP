#include <bits/stdc++.h>

using namespace std;

class Nguoi{
	string cmnd, hoten; 
	int namsinh;
	public:
		void nhap(){
			cin.ignore();
			cout << "Nhap cmnd: ";
			getline(cin, cmnd);
			cout << "Nhap ho ten: ";
			getline(cin, hoten);
			cout << "Nhap nam sinh";
			cin >> namsinh;
		}
		void xuat(){
			cout << "CMND: " << cmnd << "\tHoten: " << hoten << "\tNam sinh: " << namsinh;
		}
		int getAge(){
			return namsinh;
		}
};

class CT:public Nguoi{
	int sbt, sptd;
	public:
		void nhap(){
			Nguoi::nhap();
			cout << "Nhap sbt: ";
			cin >> sbt;
			cout << "Nhap sptd: ";
			cin >> sptd;
		}
		void xuat(){
			Nguoi::xuat();
			cout << "\t SBT: " << sbt << "\tSptd: " << sptd << endl;
		}
		int getScore(){
			return sbt;
		}
		int getMinutes(){
			return sptd;
		}
};
int main() {
	int n;
	cout << "Nhap n: "; cin >> n;
	CT dsct[n];
	for(int i = 0; i < n; i++){
		dsct[i].nhap();
	}
	
	int min_age=dsct[0].getAge();
	for(int i = 0; i < n; i++){
		min_age=min_age>dsct[i].getAge() ? min_age : dsct[i].getAge();
	}
	for(int i = 0; i < n; i++){
		if(dsct[i].getAge() == min_age)
			dsct[i].xuat();
	}
	cout << "Danh sach duov thuong 50 trieu la:\n";
	for(int i = 0; i < n; i++){
		if(dsct[i].getScore()>=3 && dsct[i].getScore() < 5 || dsct[i].getMinutes() >= 500)
			dsct[i].xuat();
	}
	cout << "Danh sach duov thuong 70 trieu la:\n";
	for(int i = 0; i < n; i++){
		if(dsct[i].getScore()>=5)
			dsct[i].xuat();
	}
	return 0;
}

