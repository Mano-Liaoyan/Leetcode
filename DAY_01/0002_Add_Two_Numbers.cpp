#include <algorithm>
#include <cstring>
#include <iostream>
#include <ctime>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) {}
    ListNode(int x) : value(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : value(x), next(next) {}
};

class Solution {
   public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1), cur = dummy;
        int t = 0;
        while (l1 || l2 || t) {
            if (l1) t += l1->value, l1 = l1->next;
            if (l2) t += l2->value, l2 = l2->next;
            cur = cur->next = new ListNode(t % 10);
            t /= 10;
        };
        return dummy->next;
    }
};

int main() {
    int count = 10;
    srand(time(0));
    auto l1 = new ListNode(2), l2 = new ListNode(5);
    auto l1_c = l1, l2_c = l2;
    for (int i = 0; i < count - 1; i++) {
        l1_c = l1_c->next = new ListNode(rand() % 10);
        l2_c = l2_c->next = new ListNode(rand() % 10);
    }
    cout << "l1: ";
    l1_c = l1;
    for (int i = 0; i < count; i++) {
        cout << l1_c->value << " ";
        l1_c = l1_c->next;
    }
    cout << endl;
    cout << "l2: ";
    l2_c = l2;
    for (int i = 0; i < count; i++) {
        cout << l2_c->value << " ";
        l2_c = l2_c->next;
    }
    cout << endl;
    auto res = Solution::addTwoNumbers(l1, l2);
    while (res) {
        cout << res->value << " ";
        res = res->next;
    }

    return 0;
}