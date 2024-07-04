#include <bits/stdc++.h>

using namespace std;

class Xemay{
	string hangxe, tenxe, sokhung;
	int gia, dungtich;
	public:
		Xemay(){
			this->hangxe=" ";
			this->tenxe=" ";
			this->sokhung=" ";
			this->dungtich=0;
			this->gia=0;
		}
		Xemay(string hang, string ten, string sk, int dt, int gia){
			this->hangxe=hang;
			this->tenxe=ten;
			this->sokhung=sk;
			this->dungtich=dt;
			this->gia=gia;
		}
		~Xemay(){}
		Xemay(const Xemay& xe){
			this->hangxe=xe.hangxe;
			this->tenxe=xe.tenxe;
			this->sokhung=xe.sokhung;
			this->dungtich=xe.dungtich;
			this->gia=xe.gia;
		}
		void operator= (const Xemay &xe){
			this->hangxe=xe.hangxe;
			this->tenxe=xe.tenxe;
			this->sokhung=xe.sokhung;
			this->dungtich=xe.dungtich;
			this->gia=xe.gia;
		}
		void nhap(){
			cin.ignore();
			cout<<"Nhap ten hang: "; getline(cin, hangxe);
			cout<<"Nhap ten xe: "; getline(cin, tenxe);
			cout<<"Nhap so khung: "; getline(cin, sokhung);
			cout<<"Nhap dung tich: "; cin>>dungtich;
			cout<<"Nhap gia: "; cin>>gia;
		}
		void xuat(){
			cout << "----------------------\n";
			cout << "Hang: " << hangxe << endl;
			cout << "Ten: " << tenxe << endl;
			cout << "So khung: " << sokhung << endl;
			cout << "Dung tich: " << dungtich << endl;
			cout << "Gia: " << gia << endl;
			cout << "-----------------------\n";
		}
		string getHang(){
			return hangxe;
		}
		int getGia(){
			return gia;
		}
		int getDT(){
			return dungtich;
		}
		friend void timkiem(int n, Xemay *xe){
			string name;
			int price;
			cin.ignore();
			cout << "Nhap ten hang muon tim kiem: "; getline(cin, name);
			cout << "Nhap gia: "; cin >> price;
			int count = 0;
			for(int i = 0; i < n; i++){
				if(name == xe[i].hangxe && price > xe[i].gia){
					xe[i].xuat();
					count++;
				}
			}
			cout << "Co " << count << " xe ma nguoi dung can tim\n";
		}
		friend void binhquan(int n, Xemay *xe){
			int count[4]={0,0,0,0}, sum[4]={0,0,0,0};
			for(int i = 0; i < n; i++){
				if(xe[i].dungtich == 50){
					sum[0]+=xe[i].gia;
					count[0]++;
				}
				if(xe[i].dungtich == 70){
					sum[1]+=xe[i].gia;
					count[1]++;
				}
				if(xe[i].dungtich == 110){
					sum[2]+=xe[i].gia;
					count[2]++;
				}
				if(xe[i].dungtich == 150){
					sum[3]+=xe[i].gia;
					count[3]++;
				}
			}
			if(count[1]==0){
				cout<<"Khong co xe dung tich 50 xilanh\n";
			}else{
				cout<<"Gia trung binh cua xe 50 xilanh là: " << sum[0]/count[0] << endl;
			}
			if(count[2]==0){
				cout<<"Khong co xe dung tich 70 xilanh\n";
			}else{
				cout<<"Gia trung binh cua xe 70 xilanh là: " << sum[1]/count[1] << endl;
			}
			if(count[3]==0){
				cout<<"Khong co xe dung tich 110 xilanh\n";
			}else{
				cout<<"Gia trung binh cua xe 110 xilanh là: " << sum[2]/count[2] << endl;
			}if(count[4]==0){
				cout<<"Khong co xe dung tich 150 xilanh\n";
			}else{
				cout<<"Gia trung binh cua xe 150 xilanh là: " << sum[3]/count[3] << endl;
			}
		}
};
int main() {
	Xemay xe1("Honda", "Dream Thai", "RE451456", 150, 200000000);
	xe1.xuat();
	int n;
	cout << "Nhap so xe: ";
	cin >> n;
	Xemay ds[n];
	for(int i = 0; i < n; i++){
		ds[i].nhap();
	}
	for(int i = 0; i < n; i++){
		ds[i].xuat();
	}
	timkiem(n, ds);
	binhquan(n, ds);
	return 0;
}

