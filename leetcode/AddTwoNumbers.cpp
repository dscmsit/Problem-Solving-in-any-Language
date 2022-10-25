// Leetcode Problem No-2 : Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result_ans = new ListNode(0);
        ListNode *head = result_ans;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry > 0)
        {
            int result = carry + (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0);
            ListNode *new_result = new ListNode(result % 10);
            carry = result / 10;
            l1 = (l1 == NULL ? l1 : l1->next);
            l2 = (l2 == NULL ? l2 : l2->next);
            result_ans->next = new_result;
            result_ans = result_ans->next;
        }
        return head->next;
    }
};