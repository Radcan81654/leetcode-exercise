//·´×ª×Ö·û´® II
//https://leetcode.cn/problems/reverse-string-ii/
class Solution {
public:
    string reverseStr(string s, int k) {
        int prei = 0, i = 0, flag = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            if (i - prei == k)
            {
                if (flag == 0)
                {
                    reverse(s.begin() + prei, s.begin() + i);
                    prei = i;
                    flag = 1;
                }
                else
                {
                    prei = i;
                    flag = 0;

                }

            }
        }
        if (flag == 0 && i - prei <= k)
            reverse(s.begin() + prei, s.end());
        return s;

    }
};


// ·´×ª×Ö·û´®ÖÐµÄµ¥´Ê
//https://leetcode.cn/problems/reverse-words-in-a-string/
class Solution {
public:
    string reverseWords(string s) {
        string ret;
        vector<string> tmp;
        int left = 0;
        while (left < s.size())
        {
            while (left < s.size() && s[left] == ' ')
                left++;
            if (left == s.size())//·ÀÖ¹push½ø¿Õ×Ö·û´®
                break;
            int right = left;
            while (right < s.size() && s[right] != ' ')
                right++;
            string w = string(s.begin() + left, s.begin() + right);
            tmp.push_back(w);
            left = right;
        }
        for (int i = tmp.size() - 1; i >= 0; i--)
        {
            ret += tmp[i];
            if (i != 0)
                ret += ' ';

        }
        return ret;


    }
};