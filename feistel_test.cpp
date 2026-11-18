#include<bits/stdc++.h>
using namespace std;
char f(char r,char k)
{
	return r+k;
}
string e(char k0,string p)
{
	string c="xx";
	char l[3],r[3],k[3];
	k[0]=k0;
	r[0]=p[0];
	l[0]=p[1];
	for(int i=1;i<=2;i++)
	{
		k[i]=k[0]<<i;
		r[i]=l[i-1]^f(r[i-1],k[i]);
		l[i]=r[i-1];
	}
	c[0]=l[2];
	c[1]=r[2];
	return c;
}
string d(char k0, string c)
{
	string p="xx";
	char r[3],l[3],k[3];
	k[0]=k0;
	r[2]=c[1];
	l[2]=c[0];
	for(int i=2;i>=1;i--)
	{
		k[i]=k[0]<<i;
		l[i-1]=r[i]^f(l[i],k[i]);
		r[i-1]=l[i];
	}
	p[0]=r[0];
	p[1]=l[0];
	return p;
}
string xuly(string p)
{
	if(p.size()%2!=0) p+='*';
	return p;
}

int main()
{
	char k[3];
	string p,c="";
	cout<<"nhap p: ";
	getline(cin,p);
	p=xuly(p);
	for(int i=0;i<=2;i++)
	{
		cout<<"nhap k["<<i<<"] : ";
		cin>>k[i];
	}
	for(int i=0;i<p.size();i+=2)
	{
		string t="";
		t=t+ p[i]+p[i+1];
		string ct=e(k[0],t);
		ct=e(k[1],ct);
		ct=e(k[2],ct);
		c=c+ct;
	}
	cout<<"ma hoa: "<<c<<endl;;
	p="";
	for(int i=0;i<c.size();i+=2)
	{
		string t="";
		t=t+ c[i]+c[i+1];
		string ct=d(k[2],t);
		ct=d(k[1],ct);
		ct=d(k[0],ct);
		p=p+ct;
	}
	cout<<"giai ma: "<<p;
	return 0;
}
