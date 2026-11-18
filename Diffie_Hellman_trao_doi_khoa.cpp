#include<bits/stdc++.h>
using namespace std;
int songuyenthuy(int p)
{
	int a;
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
int khoacongkhai(int a,int xa,int p)
{
	int ya=1;
	for(int i=1;i<=xa;i++)
	{
		ya=(ya*a) % p;
	}
	return ya;
}
int main()
{
	int p,xa,xb,ya,yb,a,ka,kb;
	cout<<"nhap p la so nguyen to: "; 
	cin>>p;
	a=songuyenthuy(p);
	cout<<endl<<"a la so nguyen thuy be nhat cua p: "<<a<<endl;
	cout<<"nhap lan luot xa,xb deu nho hon p: ";
	cin>>xa>>xb;
	ya=khoacongkhai(a,xa,p);
	yb=khoacongkhai(a,xb,p);
	cout<<"khoa cong khai ya,yb lan luot la: "<<ya<<" "<<yb<<endl;
	ka=khoacongkhai(yb,xa,p);
	kb=khoacongkhai(ya,xb,p);
	cout<<"ka cua xa: "<<ka<<endl;
	cout<<"kb cua xb: "<<kb<<endl;
	return 0;
}
