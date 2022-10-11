class Solution {
public:
    map<ListNode*,int> a;
    bool hasCycle(ListNode *head) {
        while(head!=NULL){
            a[head]++;
            if(a[head]==2)
                return true;
            head=head->next;
        }
        return 0;
    }
};
