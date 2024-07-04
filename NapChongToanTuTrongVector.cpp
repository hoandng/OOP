#include <bits/stdc++.h>

using namespace std;
class Vector{
	float *ele;
	int dim;
	public:
		friend istream& operator >>(istream &, Vector&);
		friend ostream& operator <<(ostream &, const Vector&);
		Vector operator +(const Vector&);
		float operator *(const Vector&);
		Vector operator *(const int&);
};
istream& operator >>(istream &is, Vector &v){
	cout << "Nhap so chieu: "; is >> v.dim;
	v.ele=new float[v.dim];
	for(int i = 0; i < v.dim; i++){
		cout << "Nhap thanh phan thu " << i+1 << " ";
		is >> v.ele[i];
	}
	return is;
}
ostream& operator <<(ostream &os, const Vector&v){
	os<<"(";
	for(int i=0; i<v.dim-1;i++){
		os<<v.ele[i]<<",";
	}
	os<<v.ele[v.dim-1]<<")";
	return os;
}
Vector Vector::operator +(const Vector&v){
	Vector tong;
	int min = (dim<v.dim)?dim:v.dim;
	int max = (dim>v.dim)?dim:v.dim;
	tong.dim=max;
	tong.ele=new float[max];
	for(int i=0; i<min; i++) 
		tong.ele[i]=ele[i]+v.ele[i];
	for(int i =min; i<max; i++){
		if(max == dim)
			tong.ele[i]=ele[i];
		else tong.ele[i]=v.ele[i];
	}
	return tong;
}
float Vector::operator *(const Vector&v){
	float s = 0;
	int min = (dim<v.dim)?dim:v.dim;
	for(int i=0; i<min; i++){
		s+=ele[i]*v.ele[i];
	}
	return s;
}
Vector Vector::operator *(const int&k){
	Vector s;
	s.dim=dim;
	s.ele=new float[dim];
	for(int i=0; i<dim; i++)
		s.ele[i]=k*ele[i];
	return s;
}
int main() {
	Vector u, v, t;
	int k;
	cin >> u >> v >> t;
	cout << u << endl << v << endl << t << endl;
	cout << "u+v = " << u+v << endl;
	cout << "u*v = " << u*t << endl;
	cout << "ku+t = " << u*2+t;
	return 0;
}

