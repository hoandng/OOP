#include <bits/stdc++.h>

using namespace std;

class thisinh{
	string sbd, ht;
	int diem, kv;
	public:
		thisinh(string sbd="1", string ht="Nguyen Van A", int diem=10, int kv=1){
			this->sbd=sbd;
			this->ht=ht;
			this->diem=diem;
			this->kv=kv;
		}
		void nhap(){
			cin.ignore();
			cout << "Nhap sbd: "; getline(cin, sbd);
			cout << "Nhap ho ten: "; getline(cin, ht);
			cout << "Nhap diem: "; cin >> diem;
			cout << "Nhap khu vuc: "; cin >> kv; 
		}
		void xuat(){
			cout << "SDB: " << sbd << "\tHo ten: " << ht << "\tDiem: " << diem << "\tKhu vuc: " << kv << endl;
		}
		int getDiem(){
			return diem;
		}
		int getKV(){
			return kv;
		}
};
int main() {
	cout << "Nhap so thi sinh: ";
	int n; cin >> n;
	thisinh ds[n];
	for(int i = 0; i < n; i++){
		ds[i].nhap();
	}
	for(int i = 0; i < n; i++){
		ds[i].xuat();
	}
	double sum[3]={}, count[3]={};
	for(int i = 0; i < n; i++){
		int num = ds[i].getKV() - 1;
		sum[num]+=ds[i].getDiem();
		count[num]++;
	}
	for(int i = 0; i < 3; i++){
		if(count[i]==0) cout << "Khu vuc " << i+1 << " khong co thi sinh\n";
		else cout << "TBC diem cua khu vuc " << i+1 << " la: " << sum[i]/count[i] << endl;
	}
	return 0;
}

