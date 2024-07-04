#include <bits/stdc++.h>

using namespace std;
class Nguoi{
	string ms, ht, gt;
	int ns;
	public:
		Nguoi(string ms = "01", string ht = "Nguyen Van A", string gt = "None", int ns = 2004){
			this->ms=ms;
			this->ht=ht;
			this->gt=gt;
			this->ns=ns;
		}
		void nhap(){
			cout << "Nhap ma so: "; getline(cin, ms);
			cout << "Nhap ho ten: "; getline(cin, ht);
			cout << "Nhap gioi tinh: "; getline(cin, gt);
			cout << "Nhap nam sinh: "; cin >> ns;
			cin.ignore();
		}
		void xuat(){
			cout << "MS: " << ms << "\tHt: " << ht << "\tGT: " << gt << "\tNS: " << ns;
		}
		int getYear(){
			return ns;
		}
		string getGender(){
			return gt;
		}
};

class HocVien:public Nguoi{
	int tg, tt;
	public:
		HocVien(string ms = "01", string ht = "Nguyen Van A", string gt = "None", int ns = 2004, int tg = 0, int tt = 0)
		:Nguoi(ms,ht,gt,ns){
			this->tg=tg;
			this->tt=tt;
		}
		void nhap(){
			Nguoi::nhap();
			cout << "Nhap tg tham gia: "; cin >> tg;
			cout << "Nhap so lan tt: "; cin >> tt;
		}
		void xuat(){
			Nguoi::xuat();
			cout << "\tTgtg: " << tg << "\tTT: " << tt << endl;
		}
		int getTime(){
			return tg;
		}
		int getInteract(){
			return tt;
		}
};
int main() {
	int n;
	cout << "Nhap so hoc vien: ";
	cin >> n;
	HocVien dshv[n];
	for(int i = 0; i < n; i++){
		cin.ignore();
		dshv[i].nhap();
	}
	for(int i = 0; i < n; i++){
		dshv[i].xuat();
	}
	//
	int max = dshv[0].getYear();
	for(int i = 0; i < n; i++){
		max = max > dshv[i].getYear() ? max : dshv[i].getYear();
	}
	cout << "Danh sach nhung hoc vien tre tuoi nhat la:\n";
	for(int i = 0; i < n; i++){
		if(dshv[i].getYear() == max){
			dshv[i].xuat();
		}
	}
	//
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(dshv[i].getTime() > dshv[j].getTime()){
				swap(dshv[i],dshv[j]);
			}
		}
	}
	cout << "Danh sach hoc vien sau khi sap xep\n";
	for(int i = 0; i < n; i++){
		dshv[i].xuat();
	}
	//
	int maxTT = 0;
	for(int i = 0; i < n; i++){
		if(dshv[i].getGender()=="nu")
			maxTT = maxTT > dshv[i].getInteract() ? maxTT : dshv[i].getInteract();
	}
	cout << "Danh sach hoc vien nu co tuong tac cao nhat la\n";
	for(int i = 0; i < n; i++){
		if(dshv[i].getGender()=="nu" && dshv[i].getInteract()==maxTT)
			dshv[i].xuat();
	}
	return 0;
}

