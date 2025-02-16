//https://kamacoder.com/problempage.php?pid=1171
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
void bfs(vector<vector<int>>& arr, vector<vector<int>>& used, int x, int y)
{

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));//q.push({x,y})
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int curx = cur.first;
        int cury = cur.second;
        used[curx][cury] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1];
            if (nextx < 0 || nexty < 0 || nextx >= arr.size() || nexty >= arr[0].size())
                continue;
            if (used[nextx][nexty] == 0 && arr[nextx][nexty] == 1)
            {
                q.push(make_pair(nextx, nexty));
                used[nextx][nexty] = 1;
            }



        }
    }
}


int main()
{
    int N, M;
    cin >> N >> M;
    int ret;
    vector<vector<int>> arr(N, vector<int>(M, 0));
    vector<vector<int>> used(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 1 && used[i][j] == 0)
            {
                ret++;
                bfs(arr, used, i, j);
            }

        }
    }
    cout << ret;



}