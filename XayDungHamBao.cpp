#include <bits/stdc++.h>

using namespace std;

class A{
	string s;
	int i;
	char c;
	public:
		A(string s = "string", int i = 0, char c = 'A'){
			this->s = s;
			this->i = i;
			this->c = c;
		}
		void xuat(){
			cout << s << ", " << i << ", " << c << endl;
		}
};

class B{
	int b1, b2;
	A x, y;
	public:
		B(int b1 = 0, int b2 = 1, string s1 = "string 1", int i1 = 1, char c1 = 'Z', 
		string s2 = "string 2", int i2 = 2, char c2 = 'E'):x(s1,i1,c1),y(s2,i2,c2){
			this->b1 = b1;
			this->b2 = b2;
		}
		void xuat(){
			cout << b1 << " " << b2 << endl;
			cout << "x= "; x.xuat();
			cout << "y= "; y.xuat();
		}
};
int main() {
	B b1, b2(12, -34), b3(43,11,"qwerty"), b4(454,34,"bfbw", 43);
	b1.xuat();
	b2.xuat();
	b3.xuat();
	b4.xuat();
	return 0;
}

