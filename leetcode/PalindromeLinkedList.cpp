// 234. Leetcode  {MEDIUM}  [2-pointers, Stack , LL]

#include <bits/stdc++.h>
using namespace std;

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
class Solution
{

public:
    ListNode *reverselist(ListNode *head)
    {

        ListNode *newhead = NULL;

        while (head != NULL)
        {

            ListNode *next = head->next;
            head->next = newhead;
            newhead = head;
            head = next;
        }

        return newhead;
    }

    bool isPalindrome(ListNode *head)
    {

        // BASE cond

        if (head == NULL || head->next == NULL)
            return true;

        // middle element

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {

            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second half

        slow->next = reverselist(slow->next);
        slow = slow->next;

        // checking point

        while (slow != NULL)
        {

            if (head->val != slow->val)
                return false;

            head = head->next;
            slow = slow->next;
        }

        return true;
    }
};