#include <vector>

int maxAreaSlow(const std::vector<int> &height) {
    int ans = INT_MIN;
    for (int i = 0; i < height.size(); ++i) {
        for (int j = i + 1; j < height.size(); ++j) {
            ans = std::max(ans, (j - i) * std::min(height[i], height[j]));
        }
    }

    return ans;
}

int maxArea(const std::vector<int> &height) {
    int n = static_cast<int>(height.size());
    int i = 0, j = n - 1;
    int ans = INT_MIN;
    while (i < j) {
        if (height[i] < height[j]) {
            ans = std::max(ans, (j - i) * height[i]);
            ++i;
            continue;
        }
        ans = std::max(ans, (j - i) * height[j]);
        --j;
    }

    return ans;
}

void test() {
    auto t1_input = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    auto t1_ans = 49;

    auto t2_input = {1, 1};
    auto t2_ans = 1;

    assert(maxArea(t1_input) == t1_ans);
    assert(maxArea(t2_input) == t2_ans);

    assert(maxAreaSlow(t1_input) == t1_ans);
    assert(maxAreaSlow(t2_input) == t2_ans);
}

int main() {
    test();

    return 0;
}
