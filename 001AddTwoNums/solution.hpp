#include <cstddef>
#include <cstdlib>
#include <cmath>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *Out;
        Out = new ListNode(0);
        ListNode *tail = Out;
        int remain = 0;
        int val = 0;
        div_t tem{0,0};
        while(l1 || l2){
            val = tail->val;
            if(l1){
                val += l1->val;
                l1 = l1->next;
            }
            if(l2){
                val += l2->val;
                l2 = l2->next;
            }
            tem = div(val, 10);
            tail->val = tem.rem;
            if (l1 || l2 || tem.quot){
                tail->next = new ListNode(tem.quot);
                tail = tail->next;
            }
        }
        return Out;
    }
};