class Solution {
    /*
    C++ O(N * M) time and O(N * M) space complexity solution. The time complexity is O(N * M) because each element will be seen at most twice. It is seen first time when it is pushed into the queue and the second time when it is popped. The factor of M comes in time complexity based on the fact that we are traversing every character of string.
The space complexity is O(N * M) because each element will be stored in the queue at most once. We remove it from the set of words list therefore it cannot be added again in the queue.
    */
public:
    bool isDifferenceOne(string str1, string str2) {
        if(str1.size()!=str2.size()) {
            return false;
        }
        int difference=0;
        for(int i=0;i<str1.size();i++) {
            if(str1[i]!=str2[i]) {
                difference++;
            }
        }
        if(difference==1) {
            return true;
        }
        return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>Q;
        //unordered_set<string>seen;
        
        unordered_set<string> wset(wordList.begin(),wordList.end());
        if(beginWord=="") {     //do you need this
            return 0;
        }
        int step = 0;
        Q.push(beginWord);
        while(!Q.empty()) {
            int qsize=Q.size();
            step++;
            for(int i=0;i<qsize;i++) {
                string curr = Q.front();
                Q.pop();
                if(curr==endWord) {
                    return step;
                }
                for(int i=0;i<curr.size();i++) {
                    char origChar = curr[i];
                    for(char c = 'a';c<='z';c++) {
                        curr[i]=c;
                        if(wset.find(curr)!=wset.end()) {       //by changing 1 char in curr, we reached element in wordList
                            Q.push(curr);       //push this to Q for next level
                            wset.erase(wset.find(curr));    //delete from wordList set. no need of seeing all paths to this wset element
                        }
                    }
                    curr[i]=origChar;
                }
                /*
                for(int j=0;j<wordList.size();j++) {
                    if(seen.count(wordList[j])==0 && wordList[j]!=curr && isDifferenceOne(curr,wordList[j])) {
                        Q.push(wordList[j]);
                        seen.insert(wordList[j]);
                    }
                }*/
            }
        }
        return 0;
    }
};
