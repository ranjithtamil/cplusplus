class Solution {
public:
    //Transitive Property does not satisfy for this problem
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int m = sentence1.size();
        int n = sentence2.size();
        
        if(m!=n) {
            return false;
        }
     unordered_set<string> mySet;
        
        for(int i=0;i<similarPairs.size();i++) {
            mySet.insert(similarPairs[i][0]+"#"+similarPairs[i][1]);
        }
        
        
        
        
        for(int i=0; i<m ; i++) {
            string sent1Word = sentence1[i];
            string sent2Word = sentence2[i];
            if(sent1Word!=sent2Word && !mySet.count(sent1Word+"#"+sent2Word) && !mySet.count(sent2Word+"#"+sent1Word)) {
                return false;
            }
        }
        return true;
    }
    /*
    //Transitive Property does not satisfy for this problem
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int m = sentence1.size();
        int n = sentence2.size();
        
        if(m!=n) {
            return false;
        }
        unordered_map<string,unordered_set<string>> neighbor;
        
        for(int i=0;i<similarPairs.size();i++) {
            neighbor[similarPairs[i][0]].insert(similarPairs[i][1]);
            neighbor[similarPairs[i][1]].insert(similarPairs[i][0]);
        }
        
        
        
        
        for(int i=0; i<m ; i++) {
            string curWord = sentence1[i];
            
            if(sentence1[i]!=sentence2[i] && !neighbor[curWord].count(sentence2[i])) {
                return false;
            }
        }
        return true;
    }
    */
};
