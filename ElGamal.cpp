#include<bits/stdc++.h>
using namespace std;
int songuyenthuy(int p)
{
	for(int i=1;i<p;i++)
	{
		int x=1;
		int dem=0;
		for(int j=1;j<p;j++)
		{
			x=(x*i)%p;
			if(x==1) dem++;
		}
		if(dem==1) return i;
	}
}
int tinhmu(int a,int xa,int p)
{
	int ya=1;
	for(int i=1;i<=xa;i++)
	{
		ya=(ya*a)%p;
	}
	return ya;
}
int main()
{
	int p,a,xa,xb,ya,yb,ka,kb,P,C;
	cout<<"nhap so nguyen to p: ";
	cin>>p;
	a=songuyenthuy(p);
	cout<<"tu p suy ra phan tu nguyen thuy nho nhat cua p la: "<<a<<endl;
	cout<<"chon ngau nhien lan luot xa,xb deu nho hon p: ";
	cin>>xa>>xb;
	ya=tinhmu(a,xa,p);
	yb=tinhmu(a,xb,p);
	cout<<"khoa cong khai ya,yb lan luot la: "<<ya<<" "<<yb<<endl;
	ka=tinhmu(yb,xa,p);
	kb=tinhmu(ya,xb,p);
	cout<<"ka,kb la luot la: "<<ka<<" "<<kb;	
	cout<<endl<<"nhap plaintext: "; cin>>P;
	C=(ka*P)%p;
	cout<<"ma hoa: "<<C;
	int kdao=tinhmu(ya,p-1-xb,p);
	P=(kdao*C)%p;
	cout<<endl<<"giai ma: "<<P;
	return 0;
}
