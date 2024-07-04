#include <bits/stdc++.h>

using namespace std;
class DaThuc{
	int n;
	float *hs;
	public:
		DaThuc(){
			n = 0;
		}
		DaThuc(int n){
			this->n = n;
			hs = new float[n];
		}
		~DaThuc(){}
		DaThuc(const DaThuc &p){
			this->n = p.n;
			hs = new float[n];
			for(int i = 0; i <= n; i++){
				this->hs[i] = p.hs[i];
			} 
		}
		void nhap(){
			for(int i = n; i >= 0; i--){
				cout << "Nhap he so bac " << i << ": ";
				cin >> hs[i];
			}
		}
		void xuat(){
			for(int i = n; i > 0; i--){
				cout << hs[i] << "*x^" << i << " + ";
			}
			cout << hs[0] << endl;
		}
		void operator = (const DaThuc &p){
			this->n = p.n;
			hs = new float[n];
			for(int i = 0; i <= n; i++){
				this->hs[i] = p.hs[i];
			} 
		}
		DaThuc operator +(const DaThuc &p){
			DaThuc tong;
			if (this->n < p.n){
				tong = p;
				for(int i = 0; i <= n; i++){
					tong.hs[i]+=this->hs[i];
				}
			}
			else {
				tong = *this;
				for(int i = 0; i <= p.n; i++){
					tong.hs[i]+=p.hs[i];
				}
			}
			return tong;
		}
		friend float giatritai(float d, DaThuc &p){
			float tong=0;
			for (int i = 0; i <= p.n; i++){
				tong += p.hs[i]*pow(d,i);
			}
			return tong;
		}
};
int main() {
	DaThuc P(4), Q(5);
	P.nhap();
	P.xuat();
	Q.nhap();
	Q.xuat();
	DaThuc tong = P+Q;
	tong.xuat();
	cout << giatritai(2, tong);
	return 0;
}

