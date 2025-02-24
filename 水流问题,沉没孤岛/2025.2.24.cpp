//https://kamacoder.com/problempage.php?pid=1174
#include <iostream>
#include <vector>
using namespace std;


int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };

//把周边的岛屿置为2
void dfs(vector<vector<int>>& grid, int curx, int cury)
{
    grid[curx][cury] = 2;
    for (int i = 0; i < 4; i++)
    {
        int nextx = curx + dir[i][0];
        int nexty = cury + dir[i][1];
        if (nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size())
            continue;
        if (grid[nextx][nexty] == 1)
            dfs(grid, nextx, nexty);
    }

}



int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (grid[i][0] == 1)
            dfs(grid, i, 0);
        if (grid[i][M - 1] == 1)
            dfs(grid, i, M - 1);
    }
    for (int j = 0; j < M; j++)
    {
        if (grid[0][j] == 1)
            dfs(grid, 0, j);
        if (grid[N - 1][j] == 1)
            dfs(grid, N - 1, j);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == 0)
                continue;
            else
                grid[i][j]--;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M - 1; j++)
        {
            cout << grid[i][j] << ' ';
        }
        cout << grid[i][M - 1] << endl;
    }

    return 0;
}


https://kamacoder.com/problempage.php?pid=1175
#include <iostream>
#include <vector>
using namespace std;
//按照j--,i++的顺序往下面流
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int curx, int cury)
{
    if (visited[curx][cury])//没了这个判断的话会有多次重复调用，内存超限了
        return;

    visited[curx][cury] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nextx = curx + dir[i][0];
        int nexty = cury + dir[i][1];
        if (nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size())
            continue;
        if (grid[curx][cury] <= grid[nextx][nexty])
            dfs(grid, visited, nextx, nexty);
    }

}


int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> firstbdr(N, vector<int>(M, 0));
    vector<vector<int>> secondbdr(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
        dfs(grid, firstbdr, i, 0);

    for (int i = 0; i < M; i++)
        dfs(grid, firstbdr, 0, i);


    for (int i = 0; i < N; i++)
        dfs(grid, secondbdr, i, M - 1);

    for (int i = 0; i < M; i++)
        dfs(grid, secondbdr, N - 1, i);



    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (firstbdr[i][j] && secondbdr[i][j])
                cout << i << ' ' << j << endl;
        }
    }


    return 0;
}


