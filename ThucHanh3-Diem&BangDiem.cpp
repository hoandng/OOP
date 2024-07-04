#include <bits/stdc++.h>

using namespace std;

class Diem{
	string hoten;
	char *sbd;
	float diem;
	public:
		Diem(string hoten="Nguyen Xuan Dat", char sbd[]="1", float diem=10){
			this->sbd=new char(10);
			this->hoten=hoten;
			this->sbd=sbd;
			this->diem=diem;
		}
		~Diem(){
			delete[] sbd;
		}
		Diem(const Diem &d){
			this->sbd=new char(10);
			this->hoten=d.hoten;
			strcpy(this->sbd, d.sbd);
			this->diem=d.diem;
		}
		float getMark() const{
			return diem;
		}
		void operator = (const Diem &d){
			this->sbd=new char(10);
			this->hoten=d.hoten;
			strcpy(this->sbd, d.sbd);
			this->diem=d.diem;
		}
		friend istream& operator >>(istream& is, Diem &d){
			d.sbd= new char(10);
			cout << "Nhap ho ten: "; getline(is, d.hoten);
			cout << "Nhap sbd: "; is.getline(d.sbd, 10);
			cout << "Nhap diem: "; is>>d.diem;
			cin.ignore();
			return is;
		}
		friend ostream& operator << (ostream &os, const Diem &d){
			os << "Ho ten: " << d.hoten << "\tSBD: " << d.sbd << "\tDiem:" << d.diem << endl;
			return os;
		}
		bool operator < (const Diem &d){
			if(this->diem  <d.diem)
				return true;
			return false;
		}
		bool operator > (const Diem &d){
			if(this->diem > d.diem)
				return true;
			return false;
		}
};

class BangDiem{
	int n;
	vector<Diem> dshs;
	public:
		BangDiem(int n=0){
			this->n=n;
		}
		friend istream& operator >>(istream& is, BangDiem &bd){
			cout << "Nhap so hoc sinh: "; cin >> bd.n;
			bd.dshs.resize(bd.n);
			cin.ignore();
			for(int i = 0; i < bd.n; i++){
				is >> bd.dshs[i];
			}
			return is;
		}
		friend ostream& operator << (ostream &os, const BangDiem &bd){
			os<<"Danh sach hoc sinh la\n";
			for (int i = 0; i<bd.n; i++){
				os << bd.dshs[i];
			}
			return os;
		}
		void GiamDan(){
			cout << "Danh sach hoc sinh theo diem giam dan la\n";
			for (int i = 0; i<n-1; i++){
				for(int j = i+1; j < n; j++){
					if(dshs[i]<dshs[j]){
						swap(dshs[i], dshs[j]);
					}
				}
			}
			cout<<*this;
		}
		void datDiem(float mark=8){
			cout << "Danh sach hoc sinh dat diem A la\n"; 
			for (int i = 0; i < n; i++){
				if(dshs[i].getMark() >= mark){
					cout << dshs[i];
				}
			}
		}
};
int main() {
	BangDiem toan;
	cin >> toan;
	cout << toan;
	toan.GiamDan();
	toan.datDiem();
	return 0;
}

