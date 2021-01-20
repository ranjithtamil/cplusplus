class Solution {
public:
    int isWordsEqual(string word1, string word2,unordered_map<char,int>& myMap) {
        for(int i=0; i<min(word1.size(),word2.size());i++) {
            if(word1[i]!=word2[i]) {
                if(myMap[word1[i]]>myMap[word2[i]]) {
                    return -1;      //not equal and not sorted
                }
                return 1;       //not equal but it is sorted
            }
        }
        return 2;   //all the way equal
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> myMap;
        for(int i = 0; i < order.size(); i++) {
            myMap[order[i]]=i+1;
        }
        
        int siz = words.size();
        
        for(int i = 0; i < siz-1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];
            
            int eq = isWordsEqual(word1,word2,myMap);
            if(eq==2) {             //if all the way equal
                if(word1.size()>word2.size()) {//apple, app. this case eq=2 and word1.size()>word2.size()
                    return false;
                }
            }
            else if(eq==-1) {       //not in sorted order
                return false;
            }
            else {      //eq = 1    //in sorted order. go to next pair of words
                //continue;
            }
        }
        return true;
    }
    
    /*
    //Below solution doesnt work for below testcase. 
    //apple app
    //supposed to return false, but my solution will return true
    //abcdefghijklmnopqrstuvwxyz
    
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> ord;
        for(int i=0;i<order.size();i++) {
            ord[order[i]]=i+1;
        }
        
        int ws = words.size();
        
        if(ws==0) {
            return true;
        }
        if(ws==1) {
            return true;
        }
        
        int i=0;
        int j=0;
        
        int maxLen=0;
        for(int k=0;k<ws;k++) {
            if(words[k].size()>maxLen) {
                maxLen=words[k].size();
            }
        }
        
        int minLetter=order[0];
       // cout<<"\nMaxLen = "<<maxLen;
        while(i<maxLen) {
            int siz=words[j].size();
            
            if(i<siz) {
                if(ord[words[j][i]]>=ord[minLetter]) {
                    minLetter=words[j][i];
                    j++;
                }
                else {
                    return false;
                }
            }
            else {
                j++;
            }
            if(j==ws-1) {
                j=0;
                i++;
                minLetter=order[0];
            }
        }
        
        return true;
    }
    */
};
