#include <iostream>
using namespace std;
int main()
{
    int N,W,L[107][107]={0},a[1007],check[1007]={0};
    cin >>N>>W;
    for (int i=1;i<=N;i++)
    {
        cin >>a[i];
    }
    
    /* Tạo bảng 2 chiều, từng cột sẽ là số tiền lớn nhất ở từng mức từ 1 - N, 
    dòng sẽ là số lượng đồ vật ở từng mức tiền.
    */
    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=W;j++)
        {
            if (j<a[i]) L[i][j]=L[i-1][j];
            else L[i][j]=max(L[i-1][j-a[i]]+a[i],L[i-1][j]);
        }
    }
    // Hàm truy vấn ngược lại
    cout <<L[N][W]<<endl;
    int x=N,y=W;
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
        if (check[i]==1) cout <<i-1<<" ";
    }
}
