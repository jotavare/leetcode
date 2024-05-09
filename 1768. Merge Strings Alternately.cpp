#include <string>

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedString;
        int i = 0, j = 0;

        while (i < word1.length() && j < word2.length()) {
            mergedString += word1[i++];
            mergedString += word2[j++];
        }

        while (i < word1.length()) {
            mergedString += word1[i++];
        }
        while (j < word2.length()) {
            mergedString += word2[j++];
        }

        return mergedString;
    }
};
