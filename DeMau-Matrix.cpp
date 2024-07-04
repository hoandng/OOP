#include <bits/stdc++.h>

using namespace std;

class Matrix{
	int n;
	int **a;
	public:
		Matrix(){}
		Matrix(int n){
			this -> n = n;
			a = new int*[n];
			for(int i = 0; i < n; i++){
				a[i] = new int[n];
				for(int j = 0; j < n; j++)
				cin >> a[i][j];
			}
		}
		friend istream& operator >> (istream &is, Matrix &mt){
			cout << "Nhap kich thuoc ma tran: "; is >> mt.n;
			mt.a = new int*[mt.n];
			for(int i = 0; i < mt.n; i++)
			{
				mt.a[i] = new int[mt.n];
				for(int j = 0; j < mt.n; j++)
					is >> mt.a[i][j];
			}
			return is;
		}
		friend ostream& operator << (ostream &os,const Matrix &mt){
			for(int i = 0; i < mt.n; i++)
			{
				for(int j = 0; j < mt.n; j++)
					os << mt.a[i][j] << " ";
				os << "\n";	
			}
			return os;
		}
		~Matrix(){
			for (int i = 0; i < n; i++) {
  				delete[] a[i];
			}
			delete[] a;
		}
		friend int maxValue(Matrix &mt){
			int max = mt.a[0][0];
			for(int i = 0; i < mt.n; i++)
			{
				for(int j = 0; j < mt.n; j++)
					max = max > mt.a[i][j] ? max : mt.a[i][j];
			}
			return max;
		}
		double averageInMainCross(){
			int sum = 0;
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++){
					if(i==j){
						sum+=a[i][j];
					}
				}
			}
			return (double) sum/n;
		}
};
int main() {
	Matrix A(3), B;
	cin >> B;
	cout << "Matrix A:\n" << A << "Matrix B:\n" << B;
	cout << "23122021/(MaxA + MaxB) = " << (double) 23122021/(maxValue(A)+maxValue(B));
	cout << "\nSqrt(TbA - TbB) = " << sqrt(abs(A.averageInMainCross() - B.averageInMainCross()));
	return 0;
}

