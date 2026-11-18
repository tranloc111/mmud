
#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int p,a,b;
	cout<<"p=";cin>>p;
	cout<<"a=";cin>>a;
	cout<<"b=";cin>>b;
	cout<<"may tinh so mu = "<< (((-1/2) % p)+p)%p;
	
	cout<<"\nMa hoa = "<< ((16*10 % p)+p)%p ;
	cout<<"\nTinh K^-1 = "<<(9 ^ (p-1-10)) % p;
	
}

