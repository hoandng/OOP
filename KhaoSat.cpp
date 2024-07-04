#include <bits/stdc++.h>

using namespace std;

class KhaoSat
{
protected:
    string Ten;
    int STV;
    double Dientich;

public:
    KhaoSat(string ten, int stv, double dt) : Ten(ten), STV(stv), Dientich(dt) {}
    KhaoSat();
    void display()
    {
        cout << "Chu ho: " << Ten << endl;
        cout << "So thanh vien: " << STV << endl;
        cout << "Dien tich: " << Dientich << endl;
    }

    string getTen()
    {
        return Ten;
    }

    int getSTV()
    {
        return STV;
    }

    double getDientich()
    {
        return Dientich;
    }
};

class KSTinh : public KhaoSat
{
private:
    string Tinh;
public:
    KSTinh(string ten, int stv, double dientich, string tinh) : KhaoSat(ten, stv, dientich), Tinh(tinh) {}
    KSTinh();
    void display()
    {
        KhaoSat::display();
        cout << "Tinh: " << Tinh << endl;
    }

    string getTinh()
    {
        return Tinh;
    }
};

int demChan(vector<KSTinh> a)
{
    int count = 0;
    for (int i = 0; i < a.size() ; i++)
    {
        if (a[i].getSTV() % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

int demLe(vector<KSTinh> a)
{
    int count = 0;
    for (int i = 0; i < a.size() ; i++)
    {
        if (a[i].getSTV() % 2 != 0)
        {
            count++;
        }
    }
    return count;
}

void MDLN(vector<KSTinh> a){
    double max = 0;
    KSTinh m = a[1];
    for (int i = 0; i < a.size() ; i++)
    {
        if (max < (a[i].getDientich() / a[i].getSTV()))
        {
        max =(a[i].getDientich() / a[i].getSTV());
        m = a[i];
        }
    }
    cout << "Ho co mat do dt lon nhat la:\n";
    m.display();
}
int main()
{
    int n;
    cout << "Nhap so ho gia dinh: ";
    cin >> n;
    vector<KSTinh> ks;
    for (int i = 0; i < n; i++)
    {
        string ten, tinh;
    	int stv;
    	double dt;
    	cout << "Nhap ten: ";
    	cin.ignore();
        getline(cin, ten);
        cout << "Nhap so thanh vien: ";
        cin >> stv;
        cout << "Nhap dien tich ";
        cin >> dt;
        cout << "Nhap tinh: ";
        cin.ignore();
        getline(cin, tinh);
        ks.push_back(KSTinh(ten, stv, dt, tinh));
    }
    // So sanh so gia dinh le thanh vien va gia dinh chan thanh vien
    int chan = demChan(ks);
    int le = demLe(ks);
    if (chan > 0 && le > 0){
        if (chan > le){
            cout << "so gia dinh le thanh vien it hon so ho gia dinh chan thanh vien\n";
        }
        else {
            if(chan < le){
                cout << "so gia dinh le thanh vien nhieu hon so ho gia dinh chan thanh vien\n";
            }
            else{
                cout << "so gia dinh le thanh vien bang so ho gia dinh chan thanh vien\n";
            }
        }
    }
    else{
        cout << "Khong du du lieu de so sanh\n";
    }
    //y 2
    MDLN(ks);
    //y 3
    cout << "Ho o HN co mat do < 4 la:\n";
    for (int i = 0; i < ks.size() ; i++)
    {
        if (ks[i].getTinh() == "HN" && (ks[i].getDientich() / ks[i].getSTV()) < 4)
        {
            ks[i].display();
        }
    }
    return 0;
}
