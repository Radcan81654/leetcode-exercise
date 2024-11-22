//开发商购买土地
//https://kamacoder.com/problempage.php?pid=1044
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
int main()
{
    int n, m, sum = 0;//没有初始化sum为0会导致输出错误
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));//n个拥有m个元素的数组,n行m列
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            sum += v[i][j];
        }
    }
    //cout<<"sum"<<sum<<endl;
    vector<int> RowSum(n, 0);
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        for (int j = 0; j < m; j++)
        {
            tmp += v[i][j];
        }
        RowSum[i] = tmp;
        //cout<<tmp<<endl;
    }
    vector<int> ColumSum(m, 0);
    for (int i = 0; i < m; i++)
    {
        int tmp = 0;
        for (int j = 0; j < n; j++)
        {
            tmp += v[j][i];
        }
        ColumSum[i] = tmp;
        //cout<<tmp<<endl;
    }
    ////////////////////////
    int ret = INT_MAX;
    int presum = 0;
    for (int i = 0; i < RowSum.size() - 1; i++)
    {
        presum += RowSum[i];
        //cout<<"RowSum presum:"<<presum<<endl;
        //cout<<"abs(sum-presum-presum)"<<abs(sum-presum-presum)<<endl;
        ret = min(ret, abs(sum - presum - presum));
        //cout<<"ret:"<<ret<<endl;
    }
    presum = 0;
    for (int i = 0; i < ColumSum.size() - 1; i++)
    {
        presum += ColumSum[i];
        //cout<<"ColumSum presum:"<<presum<<endl;
        //cout<<"abs(sum-presum-presum)"<<abs(sum-presum-presum)<<endl;
        ret = min(ret, abs(sum - presum - presum));
        //cout<<"ret:"<<ret<<endl;
    }
    cout << ret << endl;

    return 0;
}

















