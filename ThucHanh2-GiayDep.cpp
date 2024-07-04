#include "bits/stdc++.h"

using namespace std;

class GiayDep {
private:
    string ten;
    string hangSanXuat;
    string mau;
    int size;
    int gia;

public:
    GiayDep(string ten = "NoName", string hangSanXuat = "NoName", string mau = "NoName", int size = 0, int gia = 0) {
        this->ten = ten;
        this->hangSanXuat = hangSanXuat;
        this->mau = mau;
        this->size = size;
        this->gia = gia;
    }

    string getTen() const {
        return ten;
    }

    string getHangSanXuat() const {
        return hangSanXuat;
    }

    string getMau() const {
        return mau;
    }

    int getSize() const {
        return size;
    }

    int getGia() const {
        return gia;
    }

    friend istream& operator>>(istream& is, GiayDep& X) {
        cout << "Nhap ten: ";
        is >> X.ten;
        cout << "Nhap hang san xuat: ";
        is >> X.hangSanXuat;
        cout << "Nhap mau: ";
        is >> X.mau;
        cout << "Nhap Size: ";
        is >> X.size;
        cout << "Nhap gia : ";
        is >> X.gia;
        return is;
    }

    friend ostream& operator<<(ostream& os, const GiayDep& X) {
        os << "Ten: " << X.ten << endl;
        os << "Hang san xuat: " << X.hangSanXuat << endl;
        os << "Mau : " << X.mau << endl;
        os << "Size: " << X.size << endl;
        os << "Gia: " << X.gia << endl;
        return os;
    }

};

class DSGD
{
    private:
    vector<GiayDep> list;
    public:
        void input()
    {
        int n;
        cout << "Nhap so luong giay dep: ";
        cin >> n;
        for(int i=0;i<n;i++)
        {
            GiayDep temp;
            cin >> temp;
            list.push_back(temp);
        }
    }

    void Search(string ten, string hangSanXuat, string mau, int size, int gia)
    {
        bool check = false;
        for (int i = 0; i < list.size(); i++)
        {
            if(list[i].getTen()==ten && list[i].getHangSanXuat() == hangSanXuat
                && list[i].getMau() == mau && list[i].getSize() == size && list[i].getGia() <= gia)
                {
                    cout << list[i];
                    check = true;
                }

        }
        if(!check) cout << "Khong tim thay giay dep phu hop";
        
    }
};

signed main()
{
        DSGD X;
        X.input();
        string ten, hangSanXuat,mau;
        int size, gia;
        cin.ignore();
        cout << "Nhap ten: ";
        getline(cin,  ten);
        cout << "Nhap hang san xuat:";
        getline(cin,hangSanXuat);
        cout << "Nhap mau: ";
        getline(cin, mau);
        cout << "Nhap size: ";
        cin >> size;
        cout << "Nhap gia: ";
        cin >> gia;
        X.Search(ten, hangSanXuat, mau, size, gia);
}

