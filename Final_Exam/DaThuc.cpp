#include <bits/stdc++.h>

using namespace std;
class DaThuc{
	int n;
	int *a;
	public:
		DaThuc(){
			n=0;
		}
		DaThuc(int n){
			this->n = n;
			a = new int[n];
		}
		void nhap(){
			cout << "Nhap so bac: "; cin >> n;
			a = new int[n];
			for(int i = n; i >= 0; i--){
				cout << "Nhap phan tu thu "<<i<<": ";
				cin >> a[i];
			}
		}
		void xuat(){
			for(int i = n; i >= 0; i--){
				cout << a[i] << "*x^" << i << " ";
			}
		}
		DaThuc cong(DaThuc b){
			if(n>b.n){
				DaThuc res(n);				
				for(int i = 0; i<=b.n; i++){
					res.a[i] = this->a[i]+b.a[i];
				}
				for(int i = b.n+1; i<=n; i++){
					res.a[i] = b.a[i];
				}
				return res;
			}
			if(n<b.n){
				DaThuc res(b.n);				
				for(int i = 0; i<=n; i++){
					res.a[i] = this->a[i]+b.a[i];
				}
				for(int i = n+1; i<=b.n; i++){
					res.a[i] = b.a[i];
				}
				return res;
			}
		}
		DaThuc tru(DaThuc b){
		if(n>b.n){
				DaThuc res(n);				
				for(int i = 0; i<=b.n; i++){
					res.a[i] = this->a[i]-b.a[i];
				}
				for(int i = b.n+1; i<=n; i++){
					res.a[i] = b.a[i];
				}
				return res;
			}
			if(n<b.n){
				DaThuc res(b.n);				
				for(int i = 0; i<=n; i++){
					res.a[i] = this->a[i]-b.a[i];
				}
				for(int i = n+1; i<=b.n; i++){
					res.a[i] = -b.a[i];
				}
				return res;
			}
		}
};
int main() {
	DaThuc a,b;
	a.nhap();
	b.nhap();
	DaThuc tong = a.tru(b);
	tong.xuat();
	return 0;
}

