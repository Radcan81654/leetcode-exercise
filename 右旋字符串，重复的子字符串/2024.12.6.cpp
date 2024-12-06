//ÓÒÐý×Ö·û´®
//https://kamacoder.com/problempage.php?pid=1065
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string rs(string& s, int k)
{
    int sz = s.size();
    k = min(k, sz);
    reverse(s.begin(), s.begin() + sz - k);
    reverse(s.begin() + sz - k, s.end());
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    string input;
    int k;
    cin >> k >> input;
    string ret = rs(input, k);
    cout << ret << endl;
}


//ÖØ¸´µÄ×Ó×Ö·û´®
//https://leetcode.cn/problems/repeated-substring-pattern/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string m = s + s;
        m.erase(m.begin());
        m.erase(m.end() - 1);
        if (m.find(s) != std::string::npos)
            return true;
        return false;
    }
};