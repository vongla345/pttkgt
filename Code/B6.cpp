#include <iostream>
using namespace std;
int n, dem=0;	//kich thuoc ban co n*n
const int MAX = 1000;
int dong[MAX];	//MOI DONG CHI CO 1 QUAN HAU
			//VIDU: dong[2]=3;  ..........dat con Hau o dong 2 cot 3
bool cot[MAX];
bool cheoChinh[MAX];	//cheoChinh[i]=false;   => duong cheo chinh i chua bi chiem
bool cheoPhu[MAX];
void Try(int i);
int main()
{
cin>>n;
	Try(0);
	cout<<dem;
return 0;
}
//Try(i): dang xet dong i
void Try(int i)
{
	if(i==n)
	{
		/*
		for(int i=0; i<n; i++)
		{
		for(int j=0; j<n; j++)
		{
			if(dong[i]==j) cout<<"H";
			else cout<<"*";
		}
		cout<<endl;
		}
		cout<<endl<<endl;
		*/
		dem++;
	}
	else
	{
		for(int j=0; j<n; j++)
		{
			if(!cot[j] && !cheoChinh[j-i+n] && !cheoPhu[i+j])
			{
				dong[i] = j;
				cot[j] = true;
				cheoChinh[j-i+n] = true;
				cheoPhu[i+j] = true;
				Try(i+1);
				cot[j] = false;
				cheoChinh[j-i+n] = false;
				cheoPhu[i+j] = false;
				dong[i]=0;
			}
		}
	}
}
