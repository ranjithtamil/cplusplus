class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) { // While there may be chars in build(S) or build (T)
            while (i >= 0) { // Find position of next possible char in build(S)
                if (S[i] == '#') {skipS++; i--;}
                else if (skipS > 0) {skipS--; i--;}
                else break;
            }
            while (j >= 0) { // Find position of next possible char in build(T)
                if (T[j] == '#') {skipT++; j--;}
                else if (skipT > 0) {skipT--; j--;}
                else break;
            }
            // If two actual characters are different
            if (i >= 0 && j >= 0 && S[i] != T[j]) {
                return false;
            }
        
            // If expecting to compare char vs nothing
            if((i>=0 && j<0) || (j>=0 && i<0)) {
                return false;
            }
                
            i--; j--;
        }
        return true;
    }
    /*
    bool backspaceCompare(string S, string T) {
        stack<char> sStack;
        stack<char> tStack;
        
        int sSize=S.size();
        int tSize=T.size();
        for(int i=0;i<sSize;i++) {
            if(S[i]=='#') {
                if(!sStack.empty()) {
                    sStack.pop();
                }
            }
            else {
                sStack.push(S[i]);
            }
        }
        
        for(int i=0;i<tSize;i++) {
            if(T[i]=='#') {
                if(!tStack.empty()) {
                    tStack.pop();
                }
            }
            else {
                tStack.push(T[i]);
            }
        }
        
        while(!sStack.empty() && !tStack.empty()) {
            if(sStack.top()!=tStack.top()) {
                return false;
            }
            
            sStack.pop();
            tStack.pop();
        }
        if(!sStack.empty()) {
            return false;
        }
        if(!tStack.empty()) {
            return false;
        }
        
        return true;
    }
    */
};
