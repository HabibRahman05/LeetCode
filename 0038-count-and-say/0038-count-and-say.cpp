
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 1; i < n; i++) {
            string temp = "";
            int count = 1;

            for (int j = 1; j < s.length(); j++) {
                if (s[j] == s[j - 1]) {
                    count++;
                } else {
                    temp += to_string(count) + s[j - 1];
                    count = 1;
                }
            }

            temp += to_string(count) + s.back();
            s = temp;
        }

        return s;
    }
};