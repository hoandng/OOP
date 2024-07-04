#include <bits/stdc++.h>

using namespace std;

class DaThuc{
	int bac;
	double *heso;
	public:
		DaThuc(){
			heso = nullptr;
		}
		DaThuc(int x){
			bac = x;
			heso = new double[bac+1];
		}
		~DaThuc(){
			delete[] heso;
		}
		void nhap(){
			cout << "Nhap bac cua da thuc: ";
			cin >> bac;
			heso = new double[bac+1];
			for (int i = 0; i <= bac; i++){
				cout << "Nhap he so a" << i <<": ";
				
				cin >> heso[i];
			}
		}
		void xuat(){
			for(auto i = bac; i >= 0; i--){
				if (i == 0 || heso[i-1] < 0)
					cout << heso[i] << "x^" << i;
				else
					cout << heso[i] <<"x^" << i << "+";
			}
			cout << endl;
		}
		DaThuc tongHaiDaThuc(DaThuc b){
			DaThuc tong(max(this->bac, b.bac));
	        int i = 0, j = 0, k = 0;
	        while (i <= this->bac && j <= b.bac)
	        {
	            tong.heso[k] = this->heso[i] + b.heso[j];
	            ++i;
	            ++j;
	            ++k;
	        }
	        while (i <= this->bac)
	        {
	            tong.heso[k] = this->heso[i];
	            ++i;
	            ++k;
	        }
	        while (j <= b.bac)
	        {
	            tong.heso[k] = b.heso[j];
	            ++j;
	            ++k;
	        }
	        return tong;	
		}
		double giaTriDaThuc(double x){
			double res = 0;
			for (int i = 0; i <= bac; i++){
				res += heso[i] * pow(x, i);
			}
			return res;
		}
		friend void hieuHaiDaThuc(DaThuc a, DaThuc b){
			DaThuc hieu(max(a.bac, b.bac));
			for (int i = 0; i <= hieu.bac; i++){
				hieu.heso[i] += (i <= a.bac ? a.heso[i]:0) - (i <= b.bac ? b.heso[i] : 0);
			}
			for(auto i = hieu.bac; i >= 0; i--){
				if (i == 0 || hieu.heso[i-1] < 0)
					cout << hieu.heso[i] << "x^" << i;
				else
					cout << hieu.heso[i] <<"x^" << i << "+";
			}
			cout << endl;
		}
};
int main() {
	DaThuc p;
	p.nhap();
	p.xuat();
	DaThuc q;
	q.nhap();
	q.xuat();
//	DaThuc r = p.tongHaiDaThuc(q);
//	r.xuat();
//	cout << p.giaTriDaThuc(5);
//	hieuHaiDaThuc(p, q);
	return 0;
}

