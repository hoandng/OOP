#include <bits/stdc++.h>

using namespace std;

class A{
	int a1;
	int *a2;
	public:
		void xuat(){
			cout << a1 << " " << *a2 << endl;
		}
		A(){
			cout << "Ham tao khong doi\n";
			a1=0;
			a2= new int;
			*a2 = 50;
		}
		A(int x, int y){
			cout<<"Ham toa co doi\n";
			a1 = x;
			a2 = new int;
			*a2 = y;
		}
		~A(){
			if(a2) delete a2;
			cout << "Ham huy\n";
		}
		A(const A& ob){
			cout << "Ham tao sao chep\n";
		}
		void operator = (const A& ob){
			cout << "Toan tu gan\n";
			a1 = ob.a1;
			a2 = new int;
			*a2 = *(ob.a2);
		}
		void biendoi(){
			a1--;
			*(a2)=100;
		}
};
int main() {
	A ob2(3,4);
	A ob1;
	ob1=ob2;
	ob2.biendoi();
	ob1.xuat();
	ob2.xuat();
	return 0;
}

