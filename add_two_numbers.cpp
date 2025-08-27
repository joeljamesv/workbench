/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* result = new ListNode;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* restemp = result;

        int carry = 0;
        int sum;

        while (temp1 != nullptr && temp2 != nullptr) {
            ListNode* curres = new ListNode;
            sum = temp1->val + temp2->val+carry;

            if (sum >= 10) {
                curres->val = sum - 10;
            } else {
                curres->val = sum;
            }
            curres->next = nullptr;

            if (sum >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }

            if (restemp == NULL) {
                restemp = curres;
            } else {
                restemp->next = curres;
                restemp = restemp->next;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while (temp1 != nullptr) {
            ListNode* curres = new ListNode;
            sum = temp1->val + carry;

            if (sum >= 10) {
                curres->val = sum - 10;
            } else {
                curres->val = sum;
            }

            curres->next = nullptr;

            if (sum >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }

            if (restemp == NULL) {
                restemp = curres;
            } else {
                restemp->next = curres;
                restemp = restemp->next;
            }
            temp1 = temp1->next;
        }

        while (temp2 != nullptr) {
            ListNode* curres = new ListNode;
            sum = temp2->val + carry;

            if (sum >= 10) {
                curres->val = sum - 10;
            } else {
                curres->val = sum;
            }

            curres->next = nullptr;

            if (sum >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }

            if (restemp == NULL) {
                restemp = curres;
            } else {
                restemp->next = curres;
                restemp = restemp->next;
            }
            temp2 = temp2->next;
        }

        if (carry == 1) {
            ListNode* curres = new ListNode;
            curres->val = 1;
            curres->next = nullptr;
            if (restemp == NULL) {
                restemp = curres;
            } else {
                restemp->next = curres;
                restemp = restemp->next;
            }
        }

        result = result->next;
        return result;
    }
};