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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    int lengthList(ListNode* head) {
        int len = 0;
        while(head) {
            head = head->next;
            len++;
        }
        return len;
    }

public:
    int pairSum(ListNode* head) {
        ListNode* p = head;
        int len = lengthList(p);
        int midd = len / 2;
        p = head;
        int maxLength = 0;

        for(int i=0; i<midd-1; i++) {
            p = p->next;
        }
        ListNode* head2 = p->next;
        p->next = NULL;

        ListNode* head3 = reverseList(head2);
        
        for(int i=0; i<midd; i++) {
            maxLength = max(maxLength, head->val+head3->val);
            head = head->next;
            head3 = head3->next;
        }

        return maxLength;
    }
};