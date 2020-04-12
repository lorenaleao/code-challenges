/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode* it = head;
        while(it != NULL){
            size++;
            it = it->next;
        }
        it = head;
        for(int i = 0; i < size/2; i++){
            it = it->next;
        }
        
        return it;

        /*
        // errichto's solution

        ListNode* A = head;
        ListNode* B = head;

        while(B != NULL){
            B = B->next;
            if(B == NULL)
                return A;
            A = A->next;
            B = B->next;
        }
        return A;
        */
    }
};