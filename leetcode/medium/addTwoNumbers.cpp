#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = (ListNode *) malloc(sizeof(ListNode));
        head->next = NULL;
        int sum = 0;

        while ((l1 != NULL) || (l2 != NULL)) {
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            ListNode *temp = (ListNode *) malloc(sizeof(ListNode));
            temp->next = NULL;

            int op = sum / 10;
            temp->val = sum - (op * 10);
            sum = op;


            ListNode *tempHead = head;
            while (tempHead->next != NULL) tempHead = tempHead->next;
            tempHead->next = temp;
        }

        return head->next;
    }
};

int main() {
    ListNode *l1 = (ListNode *) malloc(sizeof(ListNode));
    l1->val = 2;
    ListNode *l11 = (ListNode *) malloc(sizeof(ListNode));
    l11->val = 4;
    ListNode *l12 = (ListNode *) malloc(sizeof(ListNode));
    l12->val = 3;
    l12->next = NULL;

    l1->next = l11;
    l11->next = l12;

    ListNode *l2 = (ListNode *) malloc(sizeof(ListNode));
    l2->val = 5;
    ListNode *l21 = (ListNode *) malloc(sizeof(ListNode));
    l21->val = 6;
    ListNode *l22 = (ListNode *) malloc(sizeof(ListNode));
    l22->val = 4;
    l22->next = NULL;

    l2->next = l21;
    l21->next = l22;

    Solution solution;
    ListNode *res = solution.addTwoNumbers(l1, l2);

    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
}