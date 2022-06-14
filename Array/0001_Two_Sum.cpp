#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    unordered_map<int, int> heap;
    int n, target, temp;
    cin >> n;
    vector<int> nums;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }

    cin >> target;

    for (int i = 0; i < n; i++) {
        int r = target - nums[i];
        if (heap.count(r)) {
            cout << "[" << heap[r] << ", " << i << "]";
            break;
        }
        heap[nums[i]] = i;
    }

    return 0;
}