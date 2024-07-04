#include <bits/stdc++.h>

using namespace std;

class DaThuc
{
    int bac;
    double *a;

public:
    DaThuc()
    {
        a = nullptr;
    }
    DaThuc(int x)
    {
        bac = x;
        a = new double[x + 1];
    }
    ~DaThuc()
    {
        delete[] a;
    }
    void nhap()
    {
        cout << "Nhap bac cua da thuc: ";
        cin >> bac;
        a = new double[bac + 1];
        for (int i = 0; i <= bac; i++)
        {
            cout << "Nhap he so a" << i << ": ";
            cin >> a[i];
        }
    }
    void in()
    {
        for (int i = 0; i <= bac; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    int getBac()
    {
        return bac;
    }
    DaThuc operator+(DaThuc another)
    {
        DaThuc tong(max(this->bac, another.bac));
        int i = 0, j = 0, k = 0;
        while (i <= this->bac && j <= another.bac)
        {
            tong.a[k] = this->a[i] + another.a[j];
            ++i;
            ++j;
            ++k;
        }
        while (i <= this->bac)
        {
            tong.a[k] = this->a[i];
            ++i;
            ++k;
        }
        while (j <= another.bac)
        {
            tong.a[k] = another.a[j];
            ++j;
            ++k;
        }
        return tong;
    }

    double tinhGiaTri(double d)
    {
        double res = 0;
        for (int i = 0; i <= bac; i++){
            res += a[i]*pow(d, i);
        }
        return res;
    }
    double daoHam(double x){
    	double res = 0;
    	for(int i = 0; i <= bac; i++){
    		res += i * this->a[i] * pow(x, i-1);
		}
    	return res;
	}
};

int main()
{
    DaThuc a;
    a.nhap();
    a.in();
    double d; 
    cout << "Nhap gia tri d: ";
    cin >> d;
    // DaThuc b;
    // b.nhap();
    // b.in();
    // DaThuc c = a + b;
    // cout << "He so cua tong hai da thuc la: " << endl;
    // c.in();
    cout << a.tinhGiaTri(d);
    cout << a.daoHam(d);
    return 0;
}
