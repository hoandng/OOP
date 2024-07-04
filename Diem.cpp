//bai tap ve nha lop diem
#include"bits/stdc++.h"
using namespace std;
class Diem{
	private:
		char* ten;
		float hd;
		float td;
	public: 
		Diem(char name , float hd,float td){
			this->ten = new char[10];
			*ten = name;
			this->hd=hd;
			this->td = td;
		}
		void xuat(){
			cout<<*ten<<" ( "<<hd<<" , "<<td<<" )\n";
		}	
};
int main(){
	Diem A('A',1,2);
	Diem B('B',0,0);
	A.xuat();
	B.xuat();
}
