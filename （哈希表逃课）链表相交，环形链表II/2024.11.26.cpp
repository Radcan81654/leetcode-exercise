//链表相交
//https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        unordered_map<ListNode*, int> umap;
        while (curA)
        {
            umap[curA]++;
            curA = curA->next;
        }
        while (curB)
        {
            if (umap[curB] == 1)
                return curB;
            curB = curB->next;
        }
        return NULL;


    }
};


//环形链表II
//https://leetcode.cn/problems/linked-list-cycle-ii/submissions/583212648/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* cur = head;
        unordered_map<ListNode*, int> umap;
        while (cur)
        {
            umap[cur]++;
            if (umap[cur] == 2)
                return cur;

            cur = cur->next;
        }
        return nullptr;



    }
};