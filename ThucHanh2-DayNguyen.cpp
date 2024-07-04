#include <bits/stdc++.h>

using namespace std;

class DayNguyen{
	int n;
	double *a;
	public:
		friend void nhap(DayNguyen &dn){
			cout << "Nhap so pt: ";
			cin >> dn.n;
			dn.a = new double[dn.n];
			for(int i = 0; i < dn.n; i++){
				cin >> dn.a[i];
			}
		}
		friend ostream& operator <<(ostream &os, DayNguyen dn){
			for(int i = 0; i < dn.n; i++){
				os << dn.a[i] << " ";
			}
			os << "\n";
			return os;
		}
		void capsocong(){
			bool check = false;
			for(int i = 0; i < n-2; i++){
				double d = a[i+1]-a[i];
				if(a[i+1]+d == a[i+2]){
					cout << "(" << a[i] << "," << a[i+1] << "," << a[i+2] << "), ";
					check = true;
				}
			}
			cout << "\n";
			if(!check){
				cout << "Day khong co cap so cong\n";
			}
		}
};
int main() {
	DayNguyen d1;
	nhap(d1);
	cout << d1;
	d1.capsocong();
	return 0;
}

