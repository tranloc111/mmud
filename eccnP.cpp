/*P(Xp,Yp) la mot diem thuoc Ep(a,b) Lap trinh nhap toa do diem P roi tinh tich n.P , voi a va P nhap tu ban phim  Xp=3 Yp=10 n=5 a=1 p=23*/
#include<iostream>
using namespace std;
struct Diem
{
	int x;
	int y;
};
struct Diem Tong(int Xp,int Yp, int Xq,int Yq,int a,int p){
	struct Diem R;
	int L,TS,MS,MS1;
	
	if(Xp==Xq && (Yp+Yq)%p==0){			// 2 diem doi nhau
		R.x = -1;
		R.y = -1;
		return R;				//Tong la diem 0 o vo cuc
	}
	else if(Xp==-1 && Yp==-1){			//diem P la diem 0
		R.x = Xq;
		R.y = Yq;
		return R; 				//Tong P+Q la diem Q
	}
	else if(Xq==-1 && Yq==-1){			//diem Q la diem 0
		R.x = Xp;
		R.y = Yp;
		return R;				//Tong P+Q la diem P
	}
	else if(Xp==Xq && Yp==Yq){		//2 diem trung nhau
		TS=(3*Xp*Xp + a)%p;		//Tu so
		MS=(2*Yp)%p;			//Mau so
		int MS1;				//Nghich dao cua mau so
		for(int i=0;i<p;i++){
			if(i*MS%p==1) {MS1=i;break;}
		}
		L=TS*MS1%p;		//Lambda
		//cout<<endl<<"L1= "<<L;
	}
	else
	{
		TS=(Yq-Yp+p)%p;			//Tu so
		MS=(Xq-Xp+p)%p;			//Mau so
		int MS1;	//Nghich dao cua mau so
		for(int i=0;i<p;i++){
			if(i*MS%p==1) {MS1=i;break;}
		}
		L=TS*MS1%p;		//Lambda
		//cout<<endl<<"L2= "<<L;
	}
	R.x = (L*L-Xp-Xq+p+p)%p;
	R.y = (L*(Xp-R.x+p)-Yp+p)%p;
	return R;
};
int main(){
	int Xp,Yp,Xq,Yq;
	int n,a,p;
	cout<<"Nhap Xp= ";cin>>Xp;
	cout<<"Nhap Yp= ";cin>>Yp;
	cout<<"Nhap n= ";cin>>n;
	cout<<"Nhap a= ";cin>>a;
	cout<<"Nhap p= ";cin>>p;
	
	struct Diem R; R.x=Xp; R.y=Yp;		//Neu n=1 thi n.P=P;
	Xq=Xp; Yq=Yp;
	for(int i=2;i<=n;i++){
		R = Tong(Xp,Yp,Xq,Yq,a,p);
		Xq = R.x;
		Yq = R.y;
	}
	cout<<"(Xr,Yr)= ("<<R.x<<", "<<R.y<<")";
}
