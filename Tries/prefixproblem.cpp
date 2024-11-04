#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfword;
    int freq;

    Node() {
        endOfword = false;
    }
};

class Tries {
    Node* root;

public:
    Tries() {
        root = new Node();
        root->freq=-1;
    }
    void insert(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();
                temp->children[key[i]]->freq=1;
            }else{
                temp->children[key[i]]->freq++;
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

    string getPrefix(string key){
        Node* temp=root;
        string prefix="";

        for(int i=0;i<key.size();i++){
            prefix+=key[i];
            if(temp->children[key[i]]->freq==1){
                break;
            }else{
                temp=temp->children[key[i]];
            }
        }
        return prefix;
    }
};

void prefixproblem(vector<string>dict){
    Tries trie;
    for(int i=0;i<dict.size();i++){
        trie.insert(dict[i]);
    }
    for(int i=0;i<dict.size();i++){
        cout<<trie.getPrefix(dict[i])<<" ";
    }
}

int main() {
    // Input string to check if it can be segmented
    string s="ilikesamsung";

    vector<string> wordDict={"i","like","sam","samsung","sung"};
    vector<string> wordDict1={"zebra","loop","love","Dog","Dolphin"};

    // Solution sol;
    // bool result = sol.wordBreak(s, wordDict);

    // if (result) {
    //     cout << "The string can be segmented into words from the dictionary." << endl;
    // } else {
    //     cout << "The string cannot be segmented into words from the dictionary." << endl;
    // }

    prefixproblem(wordDict1);

    return 0;
}
