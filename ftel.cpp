#include<bits/stdc++.h>
using namespace std;
char f(char k,char r)
{
	return r+k;
}
string e(string p,char k0)
{
	string c="xx";
	char r[3],k[3],l[3];
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
string d(string c, char k0)
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
string edes(string p,char k[3])
{
	string c="";
	for(int i=0;i<p.size();i+=2)
		{
			string t="";
			t=t+p[i]+p[i+1];
			string ct=e(t,k[0]);
			ct=e(ct,k[1]);
			ct=e(ct,k[2]);
			c=c+ct;
		}
	return c;
}
string ddes(string c,char k[3])
{
	string p="";
	for(int i=0;i<c.size();i+=2)
		{
			string t="";
			t=t+c[i]+c[i+1];
			string pt=d(t,k[2]);
			pt=d(pt,k[1]);
			pt=d(pt,k[0]);
			p=p+pt;
		}
		return p;
}
int main()
{
	string p,c;
	char k[3];
	cout<<"nhap p: "; getline(cin,p);
	p=xuly(p);
	for(int i=0;i<3;i++)
		{
			cout<<"nhap k["<<i<<"] = ";
			cin>>k[i];
		}
	c=edes(p,k);
	cout<<"ma hoa: "<<c<<endl;
	p="";
	cout<<"giai ma: "<<ddes(c,k);
	return 0;
}
