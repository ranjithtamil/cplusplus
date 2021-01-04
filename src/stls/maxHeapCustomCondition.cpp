class Solution {
public:
    struct comparePair {
        bool operator()(pair<int,char> const& p1, pair<int,char> const& p2) {
            // return "true" if "p1" is greater than "p2" 
            return p1.first < p2.first;       //But This will make Max Heap. NOTE VERY IMPORTANT that it has to be ascending here but heap will be maxheap  
                                            // for minHeap, condition will be p1.first > p2.first
        }
    };
    string reorganizeString(string S) {
        vector<int> charMap(26,0);
        bool oddN = false;
        bool evenN = false;
        int n = S.size();
        if(n%2 == 0) {
            evenN = true;
        }
        else {
            oddN = true;
        }
        
        for(int i=0;i<n;i++) {
            char ch = S[i];
            charMap[ch-'a']++;
            
            if(oddN) {  //oddN
                if(charMap[ch - 'a'] > (n+1)/2) {
                    return "";
                }
            }
            else {  //evenN
                if(charMap[ch - 'a'] > (n/2)) {
                    return "";
                }
            }
        }
        //frequency of every character is found.
        priority_queue <pair<int,char>, vector<pair<int,char>>, comparePair> pq;
    
        for(int i=0;i<26;i++) {
            char ch=i+'a';
            if(charMap[i]>0) {
                pair<int,char> freqToCharPair = make_pair(charMap[i],ch);
                pq.push(freqToCharPair);
            }
        }
        //Priority queue is a Max Heap of Frequency of characters. The pair will have the character as well
        int s_idx=0;
        while(!pq.empty()) {
            pair<int,char> curPair = pq.top();
            S[s_idx] = curPair.second;
            s_idx++;
            pq.pop();
            if(!pq.empty()) {
                pair<int,char> nextPair = pq.top();
                S[s_idx] = nextPair.second;
                s_idx++;
                pq.pop();
                if(curPair.first > 1) {
                    pq.push(make_pair(curPair.first - 1, curPair.second));      //we decrement the frequency and push it to heap again
                }
                if(nextPair.first > 1) {
                    pq.push(make_pair(nextPair.first - 1, nextPair.second));    
                }
            }
        }
        return S;
    }
};
