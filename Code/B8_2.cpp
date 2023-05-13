#include <iostream>
using namespace std;
int main()
{
    int N,W,L[107][107]={0},a[1007],c[1007],check[1007]={0};
    cin >>N>>W;
    for (int i=1;i<=N;i++)
    {
        cin >>a[i]>>c[i];
    }
    /*
    Đã có a[i-1,W]: Giá trị lớn nhất mang đi được với i-1 đồ vật khi trọng lượng túi là W.
    Xét đồ vật thứ i khi trọng lượng túi vẫn là W: Chỉ mang thêm đồ vật thứ i khi giá trị của túi lúc mang i-1 đồ vật ở trọng lượng túi là j-a[i],  cộng với giá trị của đồ vật thứ i, c[i] lớn hơn khi không mang đồ vật thứ i 
    */
    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=W;j++)
        {
            if (j<a[i]) L[i][j]=L[i-1][j];
            else L[i][j]=max(L[i-1][j-a[i]]+c[i],L[i-1][j]);
        }
    }
    cout <<L[N][W]<<endl;
    int x=N,y=W;
    // Ham truy van
    while (x!=-1 && y!=-1)
    {
        if (L[x][y]!= L[x-1][y])
        {
            check[x]=1;
            y-=a[x];
            x--;
        }
        else x--;
    }
    for (int i=1;i<=N;i++)
    {
        cout <<check[i]<<" ";
    }
}
