#include<bits/stdc++.h>
using namespace std;

int main()
{
	int p,pi=0;
	cout<<"nhap p = "; cin>>p;
	int b[p];
	for (int j = 1; j < p; j++) 
	{
        cout << "\na = " << j << ": ";
		int dem=0;
        int x = 1;

        for (int i = 1; i < p; i++) {
            x = (x * j) % p;
            cout << x << " ";
            if(x==1) dem++;
        }
    	if(dem==1) 
    		{
    			b[pi]=j;
    			pi++;
			}
    }
    cout<<endl<<"cac phan tu nguyen thuy cua "<<p<<" la : ";
    for(int i=0;i<pi;i++)
    	cout<<b[i]<<" ";
	return 0;
}
