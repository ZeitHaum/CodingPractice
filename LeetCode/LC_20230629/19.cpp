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

    void deleteNode(ListNode* prev, ListNode* todel){
        prev->next = todel->next;
        todel->next = nullptr;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int all_cnt = 1;
        ListNode* curr = head;
        while(curr->next!=nullptr){
            curr = curr->next;
            all_cnt++;
        }
        int tocom = all_cnt - (n-1);
        int tmp_cnt = 1;
        curr = head;
        ListNode* prev = nullptr;
        while(tmp_cnt<tocom){
            prev = curr;
            curr  =curr -> next;
            tmp_cnt++;
        }
        if(curr==head){
            ListNode* new_head = curr->next;
            curr->next = nullptr;
            return new_head;
        }
        else{
            deleteNode(prev,curr);
            return head;
        }
    }
};