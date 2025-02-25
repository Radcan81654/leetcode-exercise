//https://kamacoder.com/problempage.php?pid=1176


#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int dir[4][2] = { 1,0,-1,0,0,1,0,-1 };
int island_size;

void dfs(vector<vector<int>>& grid, int curx, int cury, int mark)
{
    grid[curx][cury] = mark;
    island_size++;
    for (int i = 0; i < 4; i++)
    {
        int nextx = curx + dir[i][0];
        int nexty = cury + dir[i][1];
        if (nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size())
            continue;
        if (grid[nextx][nexty] == 1)
            dfs(grid, nextx, nexty, mark);
    }

}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M, 0));
    map<int, int> mark_sz;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }
    int mark = 2;
    int max_island_size = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == 1)
            {
                island_size = 0;
                dfs(grid, i, j, mark);
                max_island_size = max(max_island_size, island_size);
                mark_sz.insert({ mark,island_size });
                mark++;
            }

        }
    }

    /////////////
    int ret = max_island_size;//默认ret=0的话，矩阵内全部元素都为1时报错
    ////////////


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == 0)
            {
                int cur_size = 1;
                set<int> island_mark;
                for (int k = 0; k < 4; k++)
                {
                    int nexti = i + dir[k][0];
                    int nextj = j + dir[k][1];
                    if (nexti < 0 || nextj < 0 || nexti >= N || nextj >= M)
                        continue;
                    if (grid[nexti][nextj] >= 2)
                        island_mark.insert(grid[nexti][nextj]);
                }
                for (auto m : island_mark)
                {
                    cur_size += mark_sz[m];
                }
                ret = max(ret, cur_size);

            }
        }
    }
    cout << ret << endl;



}





