#include <bits/stdc++.h>

using namespace std;

class NS{
	string hoten;
	int tuoi;
	public:
		void nhap(){
			cout << "Nhap ho ten: "; getline(cin, hoten);
			cout << "Nhap tuoi: "; cin >> tuoi;
			cin.ignore();
		}
		void xuat(){
			cout << "Ho ten: " << hoten << "\tTuoi: " << tuoi << "\t";
		}
		int getAge(){
			return tuoi;
		}
};

class QL:public NS{
	char chucvu[4];
	int ngaycong;
	public:
		void nhap(){
			NS::nhap();
			cout << "Nhap chuc vu: "; cin>>chucvu;
			cout << "Nhap ngay cong: "; cin>>ngaycong;
			cin.ignore();
		}
		void xuat(){
			NS::xuat();
			cout << "Chuc vu: " << chucvu << "\tNgay cong: " << ngaycong << endl;
		}
		float tienCong(){
			if(strcmp(chucvu, "GD")==0){
				return 50000;
			}
			else{
				if(strcmp(chucvu, "TP")==0){
					return 40000;
				}
				else return 30000;
			}
		}
		float tienLuong(){
			return ngaycong*QL::tienCong();
		}
};

void Highest(int n, QL *ql){
	QL maxluong;
	for (int i = 0; i<n-1; i++){
		maxluong = ql[i].tienLuong()>ql[i+1].tienLuong()?ql[i]:ql[i+1];
	}
	cout << "Nguoi co luong cao nhat la:\n";
	maxluong.xuat();
}
void Youngest(int n, QL *ql){
	QL trenhat;
	for (int i = 0; i<n-1; i++){
		trenhat = ql[i].getAge()<ql[i+1].getAge()?ql[i]:ql[i+1];
	}
	cout << "Nguoi tre tuoi nhat la:\n";
	trenhat.xuat();
}


int main() {
	int n;
	cout <<"Nhap so quan ly: ";
	cin >> n;
	cin.ignore();
	QL ql[n];
	for (int i = 0; i<n; i++){
		ql[i].nhap();
	}
	for (int i = 0; i<n; i++){
		ql[i].xuat();
	}
	Youngest(n,ql);
	Highest(n,ql);
	return 0;
}

