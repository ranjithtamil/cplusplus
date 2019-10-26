/* 
819. Most Common Word

Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

 

Example:

Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
 

Note:

1 <= paragraph.length <= 1000.
0 <= banned.length <= 100.
1 <= banned[i].length <= 10.
The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
There are no hyphens or hyphenated words.
Words only consist of letters, never apostrophes or other punctuation symbols.

Cases : 
1. paragraph = [], banned=[] or banned=["some words", "other words"]
2. paragraph = ["Bob"], banned=[] or banned=["bob"]
3. All other cases where paragraph will have punctuation breakers to separate words.
*/
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        if(paragraph.size()==0) {
            return "";
        }
        
        
        unordered_map<string,int> mymap;
        unordered_set<string> myset;
        int maxFreq=0;
        string freqWord="";
        int j=0;
        int n=paragraph.size();
        string str="";
        int b=banned.size();
        
        
        
        for(int i=0;i<b;i++) {
            myset.insert(banned[i]);
        }
        
        while(j<n) {
            if(paragraph[j]>=97 && paragraph[j]<=122) {
                str=str+(paragraph[j]);
                j++;
            }
            else if(((paragraph[j]>=65 && paragraph[j]<=90))) {
                paragraph[j]=tolower(paragraph[j]);
                str=str+(paragraph[j]);
                j++;
            }
            else {
                int len=str.size();
                if(len>0) {
                    if(myset.find(str)==myset.end()) {
                        mymap[str]++;
                        
                        int wordFreq=mymap[str];
                        if(wordFreq > maxFreq) {
                            maxFreq=wordFreq;
                            freqWord=str;
                        }
                        
                    }
                }
                str="";
                j++;
            }
            
            if(j==n) { //It is j==n because it would have been incremented by 1st if or 2nd ifelse. Paragraph has only one word with no punctuation breakers.. will never hit else
                
                int len=str.size();
                if(len>0) {
                    if(myset.find(str)==myset.end()) {
                        mymap[str]++;
                        
                        int wordFreq=mymap[str];
                        if(wordFreq > maxFreq) {
                            maxFreq=wordFreq;
                            freqWord=str;
                        }
           
                    }
                }
                str="";
                j++;
            }
           
            
        }
        
        
        return freqWord;    
    }
};
