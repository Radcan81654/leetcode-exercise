//赎金信
//https://leetcode.cn/problems/ransom-note/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mgz;
        for (auto i : magazine)
            mgz[i]++;
        unordered_map<char, int> nt;
        for (auto i : ransomNote)
            nt[i]++;
        for (auto it : nt)
        {
            if (it.second > mgz[it.first])
                return false;

        }
        return true;


    }
};
// //正解：
// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         int record[26] = {0};
//         //add
//         if (ransomNote.size() > magazine.size()) {
//             return false;
//         }
//         for (int i = 0; i < magazine.length(); i++) {
//             // 通过record数据记录 magazine里各个字符出现次数
//             record[magazine[i]-'a'] ++;
//         }
//         for (int j = 0; j < ransomNote.length(); j++) {
//             // 遍历ransomNote，在record里对应的字符个数做--操作
//             record[ransomNote[j]-'a']--;
//             // 如果小于零说明ransomNote里出现的字符，magazine没有
//             if(record[ransomNote[j]-'a'] < 0) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };