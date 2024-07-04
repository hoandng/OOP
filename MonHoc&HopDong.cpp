#include <bits/stdc++.h>

using namespace std;

class MonHoc{
	string mamon, tenmon;
	int stc;
	public:
		void nhap(){
			cout << "Nhap ma mon: "; getline(cin,mamon);
			cout << "Nhap ten mon: "; getline(cin,tenmon);
			cout << "Nhap stc: "; cin >> stc;
			cin.ignore();
		}
		void xuat(){
			cout << "Ma mon: " << mamon << "\tTen mon:" << tenmon << endl;
		}
		
		string getSubId(){
			return mamon;
		}
		string getSubName(){
			return tenmon;
		}
};

bool checkSub(string id, vector<MonHoc> &ds){
	for(int i = 0; i < ds.size(); i++){
				if(ds[i].getSubId() == id){
					return true;
				}
			}
	return false;
}
class HopDong{
	string cccd, hoten, td, mamon, tenlop, nbd, nkt;
	public:
		void nhap(vector<MonHoc> &ds){
			cout << "Nhap cccd: "; getline(cin, cccd);
			cout << "Nhap ho ten: "; getline(cin, hoten);
			cout << "Nhap trinh do: "; getline(cin, td);
			string subid;
			do{
				cout << "Nhap ma mon: "; 
				getline(cin, subid);
				if(!checkSub(subid, ds)){
					cout << "Mon hoc khong ton tai\n";
				}
			}while(!checkSub(subid, ds));
			mamon = subid;
			cout << "Nhap ten lop: "; getline(cin, tenlop);
			cout << "Nhap ngay bat dau: "; getline(cin, nbd);
			cout << "Nhap ngay ket thuc: "; getline(cin, nkt);
		}
		void xuat(vector<MonHoc> &ds){
			cout << "CCCD: " << cccd << "\tHo ten: " << hoten << "\tTrinh do: " << td;
			HopDong::xuatTenMon(ds); 
			cout << "\tTen lop: " << tenlop << "\tNgay bd: " << nbd << "\tNgay kt: " << nkt << endl;
		}
		string getId(){
			return cccd;
		}
		string getName(){
			return hoten;
		}
		void xuatTenMon(vector<MonHoc> &ds){
			for(int i = 0; i < ds.size(); i++){
				if(mamon == ds[i].getSubId()){
					cout << "Ten mon: " << ds[i].getSubName();
				}
			}
		}
};
void search(vector<HopDong> &dsgv, vector<MonHoc> &dsmh){
	cout << "Nhap ten giao vien muon tim: ";
	string ten;
	getline(cin, ten);
	bool check = false;
	for(int i = 0; i < dsgv.size(); i++){
		if(dsgv[i].getName() == ten){
				dsgv[i].xuatTenMon(dsmh);
				check = true;
			}
	}
	if(!check) cout << "Khong ton tai giao vien\n";
}
int main() {
	vector<MonHoc> dsmh;
	cout << "Nhap so mon hoc: ";
	int n;
	cin >> n;
	cin.ignore();
	for(int i=0; i < n; i++){
		MonHoc mh;
		mh.nhap();
		dsmh.push_back(mh);
	}
	vector<HopDong> dsgv;
	int m;
	cout << "Nhap so giao vien: "; cin >> m;
	cin.ignore();
	for(int i=0; i < m; i++){
		HopDong hd;
		hd.nhap(dsmh);
		dsgv.push_back(hd);
	}
	for(int i=0; i < m; i++){
		dsgv[i].xuat(dsmh);
	}
	search(dsgv, dsmh);
	return 0;
}

