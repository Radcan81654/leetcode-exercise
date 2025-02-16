//https://kamacoder.com/problempage.php?pid=1171
#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
//��������������������������Ϊ�ѷ���
void dfs(vector<vector<int>>& arr, vector<vector<int>>& used, int curx, int cury)
{
    for (int i = 0; i < 4; i++)
    {
        int nextx = curx + dir[i][0];
        int nexty = cury + dir[i][1];
        if (nextx >= arr.size() || nexty >= arr[0].size() || used[nextx][nexty] == 1)
            continue;

        if (used[nextx][nexty] == 0 && arr[nextx][nexty] == 1)//û�����ʹ������ڵ�������
        {
            used[nextx][nexty] = 1;
            dfs(arr, used, nextx, nexty);
        }

    }
}


int main()
{
    int N, M;//���� N �У�ÿ�а��� M ������
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> used(N, vector<int>(M, 0));
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 1 && used[i][j] == 0)
            {
                ret++;
                used[i][j] == 1;////////
                dfs(arr, used, i, j);
            }
        }
    }
    cout << ret << endl;











}