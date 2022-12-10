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
    struct ListNode* newhead, * mid;// �����м�ڵ�mid����ͷnewhead
        mid = middleNode(head); //  ʹ�� ���м�ڵ� �ĺ���
        newhead = reverseList(mid); //  ʹ�� ���� mid �ĺ���
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





