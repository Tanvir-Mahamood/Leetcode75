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
    int pairSum(ListNode* head) {
        ListNode* p1 = head;
        int len = 0, maxLength = 0;
        while(p1) {
            len++;
            p1 = p1->next;
        }
        vector<int> v(len/2, 0);
        int idx = 0;
        p1 = head;
        while(idx < len/2) {
            v[idx] += p1->val;
            p1 = p1->next;
            idx++;
        }
        idx--;
        while(idx >= 0) {
            v[idx] += p1->val;
            p1 = p1->next;
            idx--;
        }
        for(int i=0; i<len/2; i++) {
            maxLength = max(maxLength, v[i]);
        }

        return maxLength;
    }
};