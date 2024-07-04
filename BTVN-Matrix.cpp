#include <bits/stdc++.h>

using namespace std;

class Fmatrix{
	int m,n;
	double **a;
	public:
		friend istream& operator >>(istream& is, Fmatrix &mt){
			cout << "Nhap kich thuoc ma tran: ";
			is >> mt.m >> mt.n;
			mt.a = new double*[mt.m];
			for(int i = 0; i < mt.m; i++){
				mt.a[i]=new double[mt.n];
				for(int j = 0; j < mt.n; j++){
					is >> mt.a[i][j];
				}
			}
			return is;
		}
		void xuat(){
			cout << "Mat tran:\n";
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
		}
		friend double TBC(Fmatrix mt, double a=10, double b=200){
			double sum = 0;
			int count=0;
			for(int i = 0; i < mt.m; i++){
				for(int j = 0; j < mt.n; j++){
					if(mt.a[i][j]<a || mt.a[i][j]>200){
						sum+=mt.a[i][j];
						count++;
					}
				}
			}
			cout << "TBC cac ptu trong doan ["<<a<<","<<b<<"] la: " << sum/count;
			return sum/count;
		}
		~Fmatrix(){
			delete[] a;
		}	
};
int main() {
	Fmatrix mt;
	cin >> mt;
	mt.xuat();
	TBC(mt);
	return 0;
}

