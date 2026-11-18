#include<bits/stdc++.h>
using namespace std;
long long ucln(long long a,long long b)
{
	while(b!=0)
		{
			long long t=a%b;
			a=b;
			b=t;
		}
	return a;
}
long long B(long long phi,long long a)
{
	long long b0=1;
	while((a*b0)%phi!=1)
		b0++;
	return b0;
}
long long mu(long long p,long long a, long long n)
{
	long long c=1;
	for(long long i=1;i<=a;i++)
		{
			c=(c*p)%n;
		}
	return c;
}
int main()
{
	long long p,q,n,phi,a=2,b,P,C;
	cout<<"nhap p,q la so nguyen to va p khac q: ";
	cin>>p>>q;
	n=p*q;
	cout<<"n = "<<n<<endl;;
	cout<<"Nhap P sao cho 0<=P<="<<n<<" :"; cin>>P;
	phi=(p-1)*(q-1);
	cout<<"phi = "<<phi<<endl;
	while(ucln(a,phi)!=1)
		a++;
	cout<<"chon a = "<<a<<endl;
	b=B(phi,a);
	cout<<"b = "<<b<<endl;
	C=mu(P,a,n);
	cout<<"ma hoa: "<<C<<endl;
	P=mu(C,b,n);
	cout<<"giai ma: "<<P<<endl;
	return 0;
}
