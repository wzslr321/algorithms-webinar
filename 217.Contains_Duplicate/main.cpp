#include <iostream>
#include <vector>
#include <unordered_map>

bool containsDuplicate(const std::vector<int> &nums) {
    std::unordered_map<int, int> seen;
    for (const auto num: nums) {
        if(seen[num]) return true;
        seen[num] = 1;
    }

    return false;
}

void test() {
    auto t1_input = {1, 2, 3, 1};
    auto t1_ans = true;

    auto t2_input = {1, 2, 3, 4};
    auto t2_ans = false;

    auto t3_input = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    auto t3_ans = true;

    assert(containsDuplicate(t1_input) == t1_ans);
    assert(containsDuplicate(t2_input) == t2_ans);
    assert(containsDuplicate(t3_input) == t3_ans);
}

int main() {
    test();

    return 0;
}
