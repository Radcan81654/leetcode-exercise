
#include <iostream>
#include <vector>
using namespace std;
int count;
int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 }; // �ĸ�����
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;  // Խ���ˣ�ֱ������
        if (!visited[nextx][nexty] && grid[nextx][nexty] == 1) { // û�з��ʹ��� ͬʱ ��½�ص�
            visited[nextx][nexty] = true;
            count++;
            dfs(grid, visited, nextx, nexty);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                count = 1;  // ��Ϊdfs������һ���ڵ㣬������������½���˾��ȼ�����dfs���������������½��
                visited[i][j] = true;
                dfs(grid, visited, i, j); // ���������ӵ�½�ض������ true
                result = max(result, count);
            }
        }
    }
    cout << result << endl;

}