#include <bits/stdc++.h>

using namespace std;

class Ptb2{
	float a,b,c;
	public:
		Ptb2(float a = 1, float b=2, float c=3){
			this->a=a;
			this->b=b;
			this->c=c;
		}
		friend ostream& operator <<(ostream& os, Ptb2 pt){
			os << pt.a << "*x^2 + " << pt.b << "*x + " << pt.c << endl;
			return os; 
		}
		int tinhpt(){
			float delta = b*b-4*a*c;
			if(delta < 0) {
				cout << "Phuong trinh vo nghiem\n";
				return 0;
			}
			else{
				if(delta == 0){
					cout << "Phuong trinh co nghiem kep x1=x2=" << -b/(2*a) << endl;
					return 1;
				}
				else{
					cout << "Phuong trinh co hai nghiem x1=" << (-b+sqrt(delta))/(2*a) << "\tx2=" << (-b-sqrt(delta))/(2*a)<<endl;
					return 2;
				}
			}
		}
};
int main() {
	Ptb2 p1(1,4,4),p2(2,7), p3;
	cout << p1;
	int x = p1.tinhpt();
	cout << p2;
	int y = p2.tinhpt();
	cout << p3;
	int z = p3.tinhpt();
	cout << "Tong so nghiem cua 3 pt tren la: " << x+y+z;
	return 0;
}

