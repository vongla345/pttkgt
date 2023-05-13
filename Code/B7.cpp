#include <iostream>
using namespace std;
int res=0;
void Try(int k)
{
    if (k==1)
        res=res+1;
    else
    {
        Try(k-1);
        Try(1);
        Try(k-1);
    }
}
int main()
{
    int n;
    cin>>n;
    Try(n);
    cout<<res;
    return 0;
}
