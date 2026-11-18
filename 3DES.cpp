#include<bits/stdc++.h>
using namespace std;
char F(char R, char ki){
	return R+ki;
}

string E(char k, string P){
	char R[3],L[3],K[3];
	string C="xx";
	L[0]= P[0];
	R[0]= P[1];
	K[0]= k;
	int n=2;
	for(int i=1; i<=n; i++){
		K[i]=K[0]<<i;
		K[i]=L[i-1]^F(R[i-1],K[i]);
		L[i]= R[i-1];
	}	
	C[0]=L[n];
	C[1]=R[n];
	return C;
}

string D(char k, string C){
	char R[3],L[3],K[3];
	string P="xx";
	L[2]= C[0];
	R[2]= C[1];
	K[0]= k;
	int n=2;
	for(int i=n; i>=1; i--){
		K[i]=K[0]<<i;
		R[i-1]=L[i];
		L[i-1]=R[i]^F(L[i],K[i]);
	}
	P[1]=L[0];
	P[0]=R[0];
	return P;
}

//string EEE(string P, char k1, char k2, char k3){
//	if(P.size()%2!=0) P+="*";
//	string Cipher = "";
//	for(int i=0; i<P.size(); i+=2){
//		string t;
//		t=t+P[i]+P[i+1];
//		string c=E(k1,t);
//		c=E(k2,c);
//		c=E(k3,c);
//		Cipher = c;
//	}
//	return Cipher;
//}
int main(){
	string P,C="xx";
	char K1, K2, K3;
	cout<<"Nhap khoi Plaintext: ";getline(cin,P);
	cout<<"Nhap khoa K1: "; cin>>K1;
	cout<<"Nhap khoa K2: "; cin>>K2;
	cout<<"Nhap khoa K3: "; cin>>K3;
	C=E(K1,P);
	C=E(K2,C);
	C=E(K3,C);
	
	cout<<"Ma hoa: "<<C; 
	return 0;	
}
