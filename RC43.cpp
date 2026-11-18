#include<bits/stdc++.h>
using namespace std;

int kt_so(char x){	
	return (x+256)%256;
}

char so_kt(int x){
	return char(x);
}

string RC4(string p,string k){
	int s[256],t[256];
	string c = "";
	for(int i=0;i<256;i++){
		s[i]=i;
		t[i]=kt_so(k[i%k.size()]);
	}
	int j=0;
	for(int i=0;i<256;i++){
		j=(j+s[i]+t[i])%256;
		swap(s[i],s[j]);
	}
	int i=0;
	j=0;
	for(int m=0;m<p.size();m++){
		i=(i+1)%256;
		j=(j+s[i])%256;
		swap(s[i],s[j]);
		int t = (s[i]+s[j])%256;
		int K = s[t];
		c=c+so_kt(kt_so(p[m])^K);
	}
	return c;
}

int main(){
	string p,k;
	cout<<"p: ";getline(cin,p);
	cout<<"k: ";getline(cin,k);
	string c = RC4(p,k);
	cout<<"ma hoa: "<<c<<endl;
	string m = RC4(c,k);
	cout<<"giai ma: "<<m<<endl;
}
