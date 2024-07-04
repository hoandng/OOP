#include <bits/stdc++.h>

using namespace std;

class hcn{
	double a,b;
	public:
		hcn(double a,double b){
			this->a = a;
			this->b = b;
		}
		double dientich(){
			return a*b;
		}
		friend double S(hcn h){
			return h.a*h.b;
		}
};
int main() {
	hcn h1(2,3);
	hcn h2(4,3.2);
	cout << h1.dientich()<<endl;
	cout << S(h2);
	return 0;
}

