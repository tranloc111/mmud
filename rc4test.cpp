#include<bits/stdc++.h>
using namespace std;
int kt_so(char x)
{	
	return (x+256)%256;
}
char so_kt(int x)
{
	return char(x);
}
string rc4(string p,string k0)
{
	int s[256],t[256];
	string c="";
	for(int i=0;i<256;i++)
		{
			s[i]=i;
			t[i]=kt_so(k0[i%k0.size()]);
		}
	int j=0;
	for(int i=0;i<256;i++)
		{
			j=(j+s[i]+t[i])%256;
			swap(s[i],s[j]);
		}
	int i=0;
	j=0;
	for(int x=0;i<p.size();x++)
		{
			i=(i+1)%256;
			j=(j+s[i])%256;
			swap(s[i],s[j]);
			int t=(s[i]+s[j])%256;
			int k=s[t];
			c=c+so_kt(kt_so(p[x]^k));
		}
		return c;
}
int main()
{
	string p,c,k;
	cout<<"p= "; getline(cin,p);
	cout<<"k= "; getline(cin,k);
	c=rc4(p,k);
	cout<<"ma hoa: "<<c<<endl;
	cout<<"giai ma: "<<rc4(c,k);
	return 0;
}
