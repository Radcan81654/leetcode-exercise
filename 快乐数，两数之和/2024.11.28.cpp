//两数之和
//https://leetcode.cn/problems/two-sum/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            // 遍历当前元素，并在map中寻找是否有匹配的key
            auto iter = umap.find(target - nums[i]);
            if (iter != umap.end()) {
                return { iter->second, i };
            }
            // 如果没找到匹配对，就把访问过的元素和下标加入到map中
            umap.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};





//快乐数
//https://leetcode.cn/problems/happy-number/submissions/583757776/
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> umap;
        while (n != 1)
        {
            if (umap[n] == 1)
                return false;
            umap[n]++;
            vector<int> tmp;
            for (int cp = n; cp > 0; cp /= 10)
                tmp.push_back(cp % 10);
            int nextn = 0;
            for (auto i : tmp)
                nextn += i * i;
            n = nextn;
        }
        return true;

    }
};