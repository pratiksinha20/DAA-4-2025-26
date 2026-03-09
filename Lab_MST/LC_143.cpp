
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
    void reorderList(ListNode* head) {
        if (!head) return;

       
        vector<ListNode*> nodes;
        ListNode* curr = head;
        while (curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int i = 0, j = nodes.size() - 1;
        while (i < j) {
            nodes[i]->next = nodes[j];
            i++;
            if (i == j) break;
            nodes[j]->next = nodes[i];
            j--;
        }

        nodes[i]->next = nullptr;
    }
};

// first we store all the nodes in a vector, then we use two pointers to reorder the list. 
// The first pointer starts from the beginning of the vector and the second pointer starts from the end of the vector.
//  We alternate between the two pointers to set the next pointers of the nodes accordingly. Finally, we set the next pointer of the last node to nullptr to terminate the list.