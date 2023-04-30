#include <iostream>
#include <unordered_map>

int lengthOfLongestSubstringSlow(const std::string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        int curr = 1;
        std::unordered_map<char, int> seen;
        seen[s[i]] = 1;
        for (int j = i + 1; j < s.size(); ++j) {
            if (seen[s[j]]) break;
            seen[s[j]] = 1;
            ++curr;
        }
        ans = std::max(curr, ans);
    }

    return ans;
}

int lengthOfLongestSubstring(const std::string s) {
    int n = static_cast<int>(s.length());
    std::unordered_map<char, int> mp;

    int ans = 0;

    for (int i = 0, j = 0; j < n; j++) {
        if (mp[s[j]] > 0) {
            i = std::max(i, mp[s[j]]);
        }
        ans = std::max(ans, j - i + 1);
        mp[s[j]] = j + 1;
    }

    return ans;
}


void test() {
    auto t1_input = "abcabcbb";
    auto t1_ans = 3;

    auto t2_input = "bbbbb";
    auto t2_ans = 1;

    auto t3_input = "pwwkew";
    auto t3_ans = 3;

    auto t4_input = "dvdf";
    auto t4_ans = 3;

    assert(lengthOfLongestSubstring(t1_input) == t1_ans);
    assert(lengthOfLongestSubstring(t2_input) == t2_ans);
    assert(lengthOfLongestSubstring(t3_input) == t3_ans);
    assert(lengthOfLongestSubstring(t4_input) == t4_ans);

    assert(lengthOfLongestSubstringSlow(t1_input) == t1_ans);
    assert(lengthOfLongestSubstringSlow(t2_input) == t2_ans);
    assert(lengthOfLongestSubstringSlow(t3_input) == t3_ans);
    assert(lengthOfLongestSubstringSlow(t4_input) == t4_ans);
}

int main() {
    test();
    return 0;
}
