#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode* cur, * next, * newhead;
    cur = head; next = head->next;  newhead = NULL;
    while (cur)
    {
        cur->next = newhead;

        newhead = cur;
        cur = next;
        if (next)
            next = next->next;
    }
    return newhead;
}

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast, * slow;
    fast = slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}


struct ListNode* chkPalindrome(struct ListNode* head) {
    struct ListNode* newhead, * mid;// 创建中间节点mid和新头newhead
        mid = middleNode(head); //  使用 找中间节点 的函数
        newhead = reverseList(mid); //  使用 逆置 mid 的函数
        while (head && newhead)
        {
            if (head->val != newhead->val)
            {
                return "false";
            }
            else
            {
                head = head->next;
                newhead = newhead->next;
            }
        }
        return "true";
    }





