//�����������ֵ
//https://leetcode.cn/problems/sliding-window-maximum/
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        typedef pair<int, int> pii;
        multiset<pii> window;//ֱ��д��multiset<int,int> window;�Ļ����ò���window.find

        for (int i = 0; i < nums.size(); ++i) {
            window.emplace(nums[i], i);

            if (i >= k) {
                auto it = window.find({ nums[i - k], i - k });
                if (it != window.end()) {
                    window.erase(it);
                }
            }

            if (i >= k - 1) {
                result.push_back(window.rbegin()->first);
            }
        }

        return result;
    }
};

////ǰk����ƵԪ��
//https://leetcode.cn/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        vector<int> ret;
        for (int num : nums)
            umap[num]++;
        multimap<int, int> mmap;
        for (auto it : umap) {
            mmap.insert(pair<int, int>(it.second, it.first));
            //mmap.insert({it.second, it.first}); //��һ�ֿ��е�д��
        }

        auto rb = mmap.rbegin();
        for (int i = 0; i < k && rb != mmap.rend(); i++, rb++) {
            ret.push_back(rb->second);
        }

        return ret;
    }
};