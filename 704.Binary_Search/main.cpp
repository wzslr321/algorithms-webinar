#include <vector>

int searchSlow(std::vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) return i;
    }
    return -1;
}

int search(std::vector<int> &nums, int target) {
    int left = 0, right = static_cast<int>(nums.size()) - 1;
    while (left <= right) {
        auto middle = left + (right - left) / 2;

        if (target == nums[middle]) return middle;

        if (target < nums[middle]) right = middle - 1;
        else left = middle + 1;
    }

    return -1;
}

void test() {
    std::vector<int> t1_input_1 = {-1, 0, 3, 5, 9, 12};
    auto t1_input_2 = 9;
    auto t1_ans = 4;

    std::vector<int> t2_input_1 = {-1, 0, 3, 5, 9, 12};
    auto t2_input_2 = 2;
    auto t2_ans = -1;

    assert(search(t1_input_1, t1_input_2) == t1_ans);
    assert(search(t2_input_1, t2_input_2) == t2_ans);
}

int main() {
    test();
    return 0;
}