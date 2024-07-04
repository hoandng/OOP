#include <bits/stdc++.h>

using namespace std;

class DayNguyen{
	int n;
	double *p;
	public:
		DayNguyen(int n=0){
			this->n = n;
			p = new double[n];
		}
		~DayNguyen(){
			delete[] p;
		}
//		void nhap(){
//			for(int i = 0; i < n; i++){
//				cin >> *(p+i);
//			}
//		}
		friend istream& operator >>(istream &is, DayNguyen &dn){
			for(int i = 0; i < dn.n; i++){
				cout << "Nhap phan tu thu " << i+1 << " : ";
				cin >> dn.p[i];
			}
			return is;
		}
//		friend void xuat(DayNguyen &dn){
//			for(int i = 0; i < dn.n; i++){
//				cout << dn.p[i] << " ";
//			}
//			cout << endl;
//		}
		friend ostream& operator <<(ostream &os, DayNguyen &dn){
			cout << "Danh sach phan tu cua mang la: ";
			for(int i = 0; i < dn.n; i++){
				cout << dn.p[i] << " ";
			}
			cout << endl;
			return os;
		}
		bool isPrime(int n){
			if(n <= 1) return false;
			for (int i = 2; i*i <= n; i++){
				if(n%i==0){
					return false;
				}
			}
			return true;
		}
		void operator!(){
			int count = 0;
			double a[this->n];
			for(int i = 0; i < n; i++){
//				int num = static_cast<int>(*(p+i));
				if(isPrime(*(p+i))){
					a[count] = *(p+i);
					count++;
				}
			}
			cout << "Mang tren co " << count << " so nguyen to\n";
			for(int i = 0; i < count; i++){
				cout << a[i] << " ";
			}
			cout << endl;
		}
		DayNguyen operator + (DayNguyen& dn){
			int spt = this->n + dn.n;
			DayNguyen tong(spt);
			for(int i = 0; i < this->n; i++){
				tong.p[i] = this->p[i];
			}
			int index = 0;
			for(int i = 0; i < dn.n; i++){
				tong.p[i+this->n] = dn.p[i];
			}
			return tong;
		} 
};
int main() {
	DayNguyen a(5), b(4);
	cin>>a;
	cout << a;
	cin >> b;
	cout << b;
	!a;
	DayNguyen c = a+b;
	cout << c;
	return 0;
}

