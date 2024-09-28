#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfword;

    Node() {
        endOfword = false;
    }
};

class Tries {
    Node* root;
public:
    Tries() {
        root = new Node();
    }
    void insert(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfword = true;
    }

    bool search(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i])) {
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }
        return temp->endOfword;
    }
};

// Solution class containing helper function
class Solution {
public:
    static bool helper(Tries& trie, string key) {
        if (key.size() == 0) {
            return true;
        }
        for (int i = 0; i < key.size(); i++) {
            string first = key.substr(0, i + 1);
            string second = key.substr(i + 1);
            if (trie.search(first) && helper(trie, second)) {
                return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        Tries trie;
        for (int i = 0; i < wordDict.size(); i++) {
            trie.insert(wordDict[i]);
        }
        return helper(trie, s);
    }
};

int main() {
    // Input string to check if it can be segmented
    string s="ilikesamsung";

    vector<string> wordDict={"i","like","sam","samsung","sung"};

    Solution sol;
    bool result = sol.wordBreak(s, wordDict);

    if (result) {
        cout << "The string can be segmented into words from the dictionary." << endl;
    } else {
        cout << "The string cannot be segmented into words from the dictionary." << endl;
    }

    return 0;
}
