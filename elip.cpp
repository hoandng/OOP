#include <bits/stdc++.h>

using namespace std;
#define PI 3.14
struct Elip{
	double a, b;
};

void nhap(Elip *e, int n){
	for(int i = 0; i < n; i++){
		cout << "Nhap ban kinh a:";
		cin >> e[i].a;
		cout << "Nhap ban kinh b:";
		cin >> e[i].b;
	}
}

void xuat(Elip *e, int n){
	for(int i = 0; i < n; i++){
		cout << "(" << e[i].a <<";" << e[i].b << ")" << endl;
	}
}

void Smax(Elip *e, int n){
	double S = 0;
	for(int i = 0; i < n; i++) {
		if(e[i].a == e[i].b){
			S = S > PI*e[i].a*e[i].b ? S : PI*e[i].a*e[i].b;
		}
	}
	if(S == 0){
		cout << "Khong ton tai elip hinh tron" << endl;
	}
	else {
		cout << "Dien tich elip hinh tron lon nhat la " << S << endl;  
	}
}
bool ss(Elip &e1, Elip &e2){
	return e1.a < e2.a && e1.b > e2.b;
}

void kiemtraday(Elip *e, int n){
	for (int i = 0; i < n-1; i++){
		if(!ss(e[i], e[i+1])){
			cout << "Khong phai day vua tang dan theo a vua giam dan theo b" << endl;
			return;
		}
	}
	cout << "La day vua tang dan theo a vua giam dan theo b" << endl;
}
int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	Elip *elip = new Elip[n];
	nhap(elip, n);
	xuat(elip, n);
	Smax(elip, n);
	kiemtraday(elip, n);
	return 0;
}

