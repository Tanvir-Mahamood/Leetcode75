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
    void deleteNode(ListNode* head, int deleteNode) {
        int idx = 1;
        ListNode* p1 = head;
        ListNode* p2 = p1->next;

        while(idx != deleteNode) {
            p1 = p2;
            p2 = p2->next;
            idx++;
        }
        p1->next = p2->next;
    }

public:
    ListNode* deleteMiddle(ListNode* head) {
        int len = 1;
        ListNode* Head = head;
        while(head->next != NULL) {
            head = head->next;
            len++;
        }
        int middNode = len / 2;
        if(middNode == 0) {
            return NULL;
        }
        deleteNode(Head, middNode);
        return Head;
    }
};