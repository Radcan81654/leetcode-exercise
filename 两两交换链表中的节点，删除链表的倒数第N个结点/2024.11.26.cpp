//两两交换链表中的节点
//https://leetcode.cn/problems/swap-nodes-in-pairs/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //答案是链表相关题目第一步就要考虑要不要加头节点
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* precur = new ListNode(0);
        precur->next = head;
        ListNode* st = precur;
        ListNode* cur = head;
        ListNode* newhead = head->next;
        while (cur)
        {
            ListNode* aftcur = cur->next;
            if (!aftcur)
                break;
            precur->next = aftcur;
            cur->next = aftcur->next;
            aftcur->next = cur;
            precur = cur;
            cur = precur->next;
        }
        ListNode* ret = st->next;
        delete(st);
        return ret;

    }
};

//删除链表的倒数第N个节点
//https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
/**
*Definition for singly - linked list.
* struct ListNode {
    *int val;
    *ListNode* next;
    *ListNode() : val(0), next(nullptr) {}
    *ListNode(int x) : val(x), next(nullptr) {}
    *ListNode(int x, ListNode* next) : val(x), next(next) {}
    *
};
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* tmp = head;
        while (tmp != nullptr)
        {
            size++;
            tmp = tmp->next;
        }
        //添加哨兵节点，开始遍历寻找位置
        ListNode* st = new ListNode(0);
        st->next = head;
        ListNode* cur = st;
        for (int i = 0; i < size - n; i++)
        {
            cur = cur->next;
        }
        ListNode* tobedelete = cur->next;
        cur->next = tobedelete->next;
        //防止删空的情况，所以返回st->next而不直接返回head
        ListNode* ret = st->next;
        delete(st);
        return ret;

    }
};