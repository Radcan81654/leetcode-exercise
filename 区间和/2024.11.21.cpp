//Çø¼äºÍ
//https://kamacoder.com/problempage.php?pid=1070
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    cin >> v[0];
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    int left = 0, right = 0;
    while (cin >> left >> right)
    {
        int count = 0;
        count = v[right] - v[left - 1];//
        cout << count << endl;
    }
    return 0;
}