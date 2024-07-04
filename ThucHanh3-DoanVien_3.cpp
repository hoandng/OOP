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
		friend istream& operator >>(istream& is, DoanVien &dv){
			dv.quequan = new char(20);
			cout << "Nhap ho ten: "; getline(is, dv.hoten);
			cout << "Nhap que quan: "; is.getline(dv.quequan, 20);
			cout << "Nhap nam vao doan: "; is >> dv.namvaodoan;
			cin.ignore();
			return is;
		}
		friend ostream& operator << (ostream &os, const DoanVien &dv){
			os << "Ho ten: " << dv.hoten << "\tQue quan: " << dv.quequan << "\tNam vao doan:" << dv.namvaodoan << endl;
			return os;
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
		bool operator < (const DoanVien &dv){
			if(this->namvaodoan<dv.namvaodoan)
				return true;
			return false;
		}
		bool operator > (const DoanVien &dv){
			if(this->namvaodoan>dv.namvaodoan)
				return true;
			return false;
		}
};
int main() {
	int n;
	cout << "Nhap sl doan vien: "; cin >> n;
	cin.ignore();
	DoanVien listDV[n+5]={};
	for(int i = 0; i < n; i++){
		cin>>listDV[i];
	}
	for(int i = 0; i < n; i++){
		cout<<listDV[i];
	}
	cout << "Danh sach doan vien sau khi sap xep\n";
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(listDV[i]>listDV[j]){
				DoanVien temp;
				temp = listDV[i];
				listDV[i]=listDV[j];
				listDV[j] = temp;
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << listDV[i];
	}
	return 0;
}
