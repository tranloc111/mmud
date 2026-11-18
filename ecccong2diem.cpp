#include <bits/stdc++.h>
using namespace std;
// Ham tim nghich dao modulo
int nghichDao(int mau, int p) {
    for (int i = 1; i < p; i++) {
        if ((mau * i) % p == 1) {
            return i;
        }
    }
    return -1;
}
// Ham cong hai diem ECC
void congHaiDiem(int p, int a, int x1, int y1, int x2, int y2,int &x3, int &y3) {
    int tu, mau;
    // Truong hop P va Q trung nhau
    if (x1 == x2 && y1 == y2) {
        tu = (3 * x1 * x1 + a) % p;
        mau = (2 * y1) % p;
    }
    // Truong hop P va Q khac nhau
    else {
        tu = (y2 - y1 + p) % p;
        mau = (x2 - x1 + p) % p;
    }
    // Tim nghich dao modulo cua mau
    int nd = nghichDao(mau, p);
    // Tinh lambda
    int lambda = (tu * nd) % p;
    // Tinh toa do diem R
    x3 = ((lambda * lambda - x1 - x2) % p + p) % p;
    y3 = ((lambda * (x1 - x3) - y1) % p + p) % p;
}
int main() {
    int p, a,n,chon;
    int x[100],y[100];
    cout << "Nhap p = ";
    cin >> p;
    cout << "Nhap a = ";
    cin >> a;
    cout<<"Nhap so diem : ";
    cin>>n;
    cout<<"1: cong - 2: tru";
    cin>>chon;
    for(int i=0;i<n;i++)
    {
    	cout<<"x["<<i<<"] y["<<i<<"]";
    	cin>>x[i]>>y[i];
	}
    // Goi ham cong hai diem ECC
    int xkq=x[0],dem=1;
    int ykq=y[0];
   	for(int i=1;i<n;i++)
   	{
   		if (chon == 2) 
		{
            y[i] = (p - y[i]) % p;
        }
   		int xmoi,ymoi;
   		congHaiDiem(p,a,xkq,ykq,x[i],y[i],xmoi,ymoi);
   		xkq=xmoi;
   		ykq=ymoi;
   		cout<<"cong lan "<<dem<<" ("<<xkq<<","<<ykq<<")"<<endl;
   		dem++;
	}
    return 0;
}

