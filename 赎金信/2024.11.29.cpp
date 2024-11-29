//�����
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
// //���⣺
// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         int record[26] = {0};
//         //add
//         if (ransomNote.size() > magazine.size()) {
//             return false;
//         }
//         for (int i = 0; i < magazine.length(); i++) {
//             // ͨ��record���ݼ�¼ magazine������ַ����ִ���
//             record[magazine[i]-'a'] ++;
//         }
//         for (int j = 0; j < ransomNote.length(); j++) {
//             // ����ransomNote����record���Ӧ���ַ�������--����
//             record[ransomNote[j]-'a']--;
//             // ���С����˵��ransomNote����ֵ��ַ���magazineû��
//             if(record[ransomNote[j]-'a'] < 0) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };