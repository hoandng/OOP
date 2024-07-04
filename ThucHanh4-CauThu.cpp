#include <bits/stdc++.h>

using namespace std;

class Nguoi{
	string id, hoten;
	int namsinh;
	public:
		Nguoi(string id="040204010123", string hoten="Ngyuyen Van Duc", int namsinh = 1990){
			this->id=id;
			this->hoten=hoten;
			this->namsinh=namsinh;
		}
		void nhap(){
			cout << "Nhap id: "; getline(cin, id);
			cout << "Nhap ho ten: "; getline(cin, hoten);
			cout << "Nhap nam sinh: "; cin >> namsinh;
			cin.ignore();
		}
		void xuat(){
			cout <<"ID: " << id << "\tHo ten: " << hoten << "\tNam sinh: " << namsinh;
		}
		int getYear(){
			return namsinh;
		}
};

class CauThu:public Nguoi{
	int sbt, sptd;
	public:
		CauThu(string id="040204010123", string hoten="Ngyuyen Van Duc", int namsinh = 1990, int sbt=0, int sptd=0):Nguoi(id,hoten,namsinh){
			this->sbt=sbt;
			this->sptd=sptd;
		}
		void nhap(){
			Nguoi::nhap();
			cout << "Nhap so ban thang: "; cin >> sbt;
			cout << "Nhap so phut thi dau: "; cin >> sptd;
			cin.ignore();
		}
		void xuat(){
			Nguoi::xuat();
			cout << "\tSbt: " << sbt << "\tSptd: "<<sptd<<endl;
		}
		int getGoal(){
			return sbt;
		}
		int getMinute(){
			return sptd;
		}
};

void cauThuTreNhat(int n, vector<CauThu> dsct){
	CauThu trenhat;
	for(int i=0; i<n-1; i++){
		trenhat=dsct[i].getYear()>dsct[i+1].getYear()?dsct[i]:dsct[i+1];
	}
	cout << "Cau thu tre tuoi nhat la:\n";
	trenhat.xuat();
}
void thuongTien(int n, vector<CauThu> dsct){
	vector<CauThu> ds50;
	vector<CauThu> ds70;
	for(int i=0; i<n; i++){
		if(dsct[i].getGoal()>=5){
			ds70.push_back(dsct[i]);
			continue;	
		}
		if((dsct[i].getGoal()>=3 && dsct[i].getGoal()<5) || dsct[i].getMinute()>=500){
			ds50.push_back(dsct[i]);
		}
	}
	cout << "Danh sach cau thu duoc thuong 50 trieu la:\n";
	for(int i=0; i<ds50.size(); i++){
		ds50[i].xuat();
	}
	cout << "Danh sach cau thu duoc thuong 70 trieu la:\n";
	for(int i=0; i<ds70.size(); i++){
		ds70[i].xuat();
	}
}
int main() {
	int n;
	cout << "Nhap so cau thu: "; cin >> n;
	cin.ignore();
	vector<CauThu> vct;
	for(int i=0; i<n; i++){
		CauThu ct;
		ct.nhap();
		vct.push_back(ct);
	}
	for(int i=0; i<n; i++){
		vct[i].xuat();
	}
	cauThuTreNhat(n,vct);
	thuongTien(n, vct);
	return 0;
}

