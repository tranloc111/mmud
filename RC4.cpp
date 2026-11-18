#include<bits/stdc++.h>
using namespace std;
void KhoiTao(unsigned char T[], unsigned char s[], string K){
    for(int i=0;i<256;i++){
        T[i]=(unsigned char)K[i%K.size()];
        s[i]=i;
    }
}
// Ham KSA - Tao mang S ngau nhien
void KSA(unsigned char T[], unsigned char s[]){
    int j=0;
    for(int i=0;i<256;i++){
        j=(j+s[i]+T[i])%256;
        swap(s[i],s[j]);
    }
}
// Ham RC4 - Ma hoa hoac giai ma
string RC4(string p, unsigned char s[]){
    string c="";
    int i=0,j=0,k,t;
    for(int x=0;x<p.size();x++){
        i=(i+1)%256;
        j=(j+s[i])%256;
        swap(s[i],s[j]);
        t=(s[i]+s[j])%256;
        k=s[t];
        c+=p[x]^k;
    }
    return c;
}
int main(){
    string p,c;
    string K;
    cout<<"Nhap p: ";
    getline(cin,p);
    cout<<"Nhap K = ";
    getline(cin,K);
    if(K.empty()){
        cout<<"Khoa khong duoc rong!";
        return 0;
    }
    unsigned char T[256],s[256];
    // MA HOA
    KhoiTao(T,s,K);
    KSA(T,s);
    c=RC4(p,s);
    cout<<"c = "<<c<<endl;
    // GIAI MA
    KhoiTao(T,s,K);
    KSA(T,s);
    p=RC4(c,s);
    cout<<"p = "<<p;                                         
    return 0;
}

