class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        if (words.empty() || s.empty()) {
            return result;
        }

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen) {
            return result;
        }

        unordered_map<string, int> wordFreq;

        for (const string& word : words) {
            wordFreq[word]++;
        }

        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;

            unordered_map<string, int> seen;

            for (int right = i; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);

                if (wordFreq.find(word) != wordFreq.end()) {
                    seen[word]++;
                    count++;

                    while (seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount) {
                        result.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
};