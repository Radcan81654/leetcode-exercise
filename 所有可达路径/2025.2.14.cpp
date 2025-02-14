//https://kamacoder.com/problempage.php?pid=1170
#include <iostream>
#include <vector>
using namespace std;
vector<int> path;
vector<vector<int>> result;
//当前遍历的结点start，到达结点cur
void dfs(vector<vector<int>>& arr, int cur, int n)
{
    if (n == cur)
    {
        result.push_back(path);
        return;
    }
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[cur][i] == 1)
        {
            path.push_back(i);
            dfs(arr, i, n);
            path.pop_back();
        }
    }
    return;

}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));
    while (M)
    {
        int s, t;
        cin >> s >> t;//一条路径为 s->t
        arr[s][t] = 1;
        M--;
    }
    path.push_back(1);
    dfs(arr, 1, N);
    if (result.size() == 0)
        cout << -1 << endl;
    for (const vector<int> v : result) {
        for (int i = 0; i < v.size() - 1; i++) {
            cout << v[i] << " ";
        }
        cout << v[v.size() - 1] << endl;
    }
    return 0;




}