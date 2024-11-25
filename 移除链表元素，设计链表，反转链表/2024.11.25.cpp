//移除链表元素
//https://leetcode.cn/problems/remove-linked-list-elements/description/
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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        while (head && head->val == val)
        {
            head = head->next;
        }
        ListNode* cur = head, * pre = nullptr;
        while (cur)
        {
            if (cur->val == val)
            {
                ListNode* next = cur->next;
                pre->next = next;
                cur = next;

            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};


//设计链表
//https://leetcode.cn/problems/design-linked-list/description/
class MyLinkedList {
public:
    ListNode* st;
    int size;
    MyLinkedList() {
        this->st = new ListNode(0);
        size = 0;
    }

    int get(int index) {
        if (index >= size || index < 0)
            return -1;
        ListNode* cur = st;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        return cur->next->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);

    }

    void addAtTail(int val) {
        addAtIndex(size, val);

    }

    void addAtIndex(int index, int val) {
        if (index > size)
            return;
        index = max(0, index);
        ListNode* cur = st;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        ListNode* newmsg = new ListNode(val);
        newmsg->next = cur->next;
        cur->next = newmsg;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index >= size || index < 0)
            return;
        ListNode* cur = st;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


//反转链表
//https://leetcode.cn/problems/reverse-linked-list/
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* precur = nullptr;
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = precur;
            precur = cur;
            cur = next;
        }
        return precur;
    }
};