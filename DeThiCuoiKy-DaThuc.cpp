#include <bits/stdc++.h>

using namespace std;
class DaThuc{
	int n;
	float *hs;
	public:
		DaThuc(){
			n = 0;
			hs = new float[n];
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
			if(n==0){
				cout << "Nhap bac: ";
				cin >> this->n;
				this->hs = new float[this->n];
			}
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
		friend DaThuc tru(DaThuc &a, DaThuc &b){
			DaThuc hieu(max(a.n, b.n));
			int i=0;
			for(i = 0; i <= a.n; i++){
				hieu.hs[i] = a.hs[i]-b.hs[i];
			}
			while(i<=b.n){
				hieu.hs[i] =0-b.hs[i];
				i++;
			}
			return hieu;
		}
		float giatritai(float d){
			float res=0;
			for (int i = 0; i <= this->n; i++){
				res += this->hs[i]*pow(d,i);
			}
			return res;
		}
};
int main() {
	DaThuc P, Q(5);
	P.nhap();
	P.xuat();
	Q.nhap();
	Q.xuat();
	DaThuc C = tru(P,Q);
	cout << "P-Q = "; C.xuat();
	DaThuc tong = P+Q;
	cout << "P+Q = "; tong.xuat();
	float d1, d2;
	cout << "Nhap d1, d2: "; cin >> d1 >> d2;
	cout << "1/(P(d1)-Q(d2)) = " << 1/(P.giatritai(d1)-Q.giatritai(d2));
	return 0;
}

