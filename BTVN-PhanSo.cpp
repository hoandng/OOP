#include <bits/stdc++.h>

using namespace std;

class PhanSo{
	int x;
	int y;
	public:
		PhanSo(){
			x=0;
			y=1;
		}
		PhanSo(int x, int y){
			this->x = x;
			this->y = y;
		}
		friend ostream& operator << (ostream &os, PhanSo& ps){
			if(ps.x==0){
				os << 0 << endl;
			}
			else{
				if(ps.y==1) os << ps.x << endl;
				else{
					if(ps.x*ps.y<0){
						os << "-" << abs(ps.x) << "/" << abs(ps.y) << endl;
					}
					else cout << abs(ps.x) << "/" << abs(ps.y) << endl;
				}
			}
			return os;
		}
		friend PhanSo cong(PhanSo a, PhanSo b){
			PhanSo kq;
			kq.x = a.x*b.y + a.y*b.x;
			kq.y = a.y * b.y;
			return kq;
		}
};
int main() {
	PhanSo a(-2, 3), b(1,5);
	cout << a << b;
	PhanSo c = cong(a,b);
	cout << c;
	return 0;
}

