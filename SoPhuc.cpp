#include <bits/stdc++.h>

using namespace std;

class Complex{
	double a, b;
	public:
		Complex(){
			a = 0;
			b = 0;
		}
		Complex(double a, double b){
			this->a = a;
			this->b = b;
		}
		friend istream &operator >> (istream&, Complex&);
		friend ostream &operator << (ostream&,const Complex&);
		Complex operator +(Complex&);
		Complex operator -(Complex&);
		Complex operator *(Complex&);
		Complex operator /(Complex&);
};

istream &operator >> (istream &is, Complex &c){
	cout << "Nhap phan thuc:";
	is >> c.a;
	cout << "Nhap phan ao:";
	is >> c.b;
	return is;
}
ostream &operator << (ostream &os, const Complex &c){
	os<<"So phuc la: " << c.a << "+" << c.b << "i" << endl;
	return os;
}
Complex Complex::operator +(Complex &p){
	Complex res;
	res.a = this->a + p.a;
	res.b = this->b + p.b;
	return res;
}
Complex Complex::operator -(Complex &p){
	Complex res;
	res.a = this->a - p.a;
	res.b = this->b - p.b;
	return res;
}
Complex Complex::operator *(Complex &p){
	Complex res;
	res.a = this->a * p.a - this->b * p.b;
	res.b = this->a * p.b + this->b * p.a;
	return res;
}
Complex Complex::operator /(Complex &p){
	Complex res;
	res.a = this->a + p.a;
	res.b = this->b + p.b;
	return res;
}

int main() {
	Complex a(1,2);
	Complex b(3,5);
	cout << a;
	cout << a+b;
	cout << a-b;
	cout << a*b;
	return 0;
}

