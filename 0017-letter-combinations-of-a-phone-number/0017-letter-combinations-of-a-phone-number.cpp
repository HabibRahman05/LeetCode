class Solution {
public:
    vector<string> result;

    string phone[10] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string digits, int index, string current) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        string letters = phone[digits[index] - '0'];

        for (char letter : letters) {
            current.push_back(letter);

            backtrack(digits, index + 1, current);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        result.clear();

        if (digits.empty()) {
            return result;
        }

        backtrack(digits, 0, "");

        return result;
    }
};