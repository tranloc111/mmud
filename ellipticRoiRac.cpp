#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a,b,p;
	cout<<"Nhap a = ";cin>>a;
	cout<<"Nhap b = ";cin>>b;
	cout<<"Nhap p = ";cin>>p;
	for(int x=0; x<=p-1; x++){
		for(int y=0; y<=p-1; y++){
			int vt = ((y*y % p)+p)%p;
			//mod p sau moi lan mux
			int vp = ((((x*x*x)%p + (a*x)%p + b%p)%p)+p)%p;
			if(vt==vp) cout<<"("<<x<<";"<<y<<")"<<"\n";
		}
	}
	
	return 0;
}
