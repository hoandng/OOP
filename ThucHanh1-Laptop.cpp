#include <bits/stdc++.h>

using namespace std;

class Laptop{
	string model,hang;
	int gia,bh;
	public:
		Laptop(string model = "Nitro 5", string hang = "Acer", int gia = 25000000, int bh = 12){
			this->model = model;
			this->hang = hang;
			this->gia = gia;
			this->bh = bh;
		}
		~Laptop(){}
		Laptop(const Laptop &a){
			this->model = a.model;
			this->hang = a.hang;
			this->gia = a.gia;
			this->bh = a.bh;
		}
		void nhap(){
			cin.ignore();
			cout << "Nhap hang sx: "; getline(cin, hang);
			cout << "Nhap ten model: "; getline(cin, model);
			cout << "Nhap gia: "; cin >> gia;
			cout << "Nhap tg bao hanh: "; cin >> bh;
		}
		void xuat(){
			cout << "-----------------\n";
			cout << "Hang: " << hang << endl;
			cout << "Model: " << model << endl;
			cout << "Gia: " << gia << endl;
			cout << "Bh: " << bh << endl;
			cout << "-----------------\n";
		}
		friend void xuatTangDan(int n, Laptop *t){
			Laptop newLaptop[n];
			for(int i = 0; i < n; i++){
				newLaptop[i] = t[i];
			}
			for(int i= 0; i < n-1; i++){
				for(int j = i+1; j <n ; j++){
					if(newLaptop[i].gia > newLaptop[j].gia)
						swap(newLaptop[i], newLaptop[j]);
				}
			}
			for(int i = 0; i < n; i++){
				newLaptop[i].xuat();
			}
		}
		friend timkiem(int n, Laptop *lt){
			cout << "Nhap gia muon tim kiem: ";
			bool Find = false;
			int price; cin >> price;
			for(int i = 0; i < n; i++){
				if(lt[i].gia < price)
					lt[i].xuat();
					Find = true;
			}
			if(!Find){
				cout << "Khong tim thay laptop can tim\n";
			}
		}
};
int main() {
	int n;
	cout << "Nhap so laptop: "; cin >> n;
	Laptop lt[n];
	for(Laptop &x : lt) x.nhap();
//	for(Laptop x : lt) x.xuat();
	xuatTangDan(n, lt);
	timkiem(n, lt);
	return 0;
}

