//https://leetcode.com/problems/shortest-way-to-form-string/discuss/330938/Accept-is-not-enough-to-get-a-hire.-Interviewee-4-follow-up
//https://medium.com/swlh/google-interview-question-leetcode-1055-7670fbaf5bd3
//https://medium.com/swlh/google-interview-question-leetcode-1055-7670fbaf5bd3 - TODO: READ O(n) solution
class Solution {
public:
    //O(mlogn) solution -O(m) for target array traversal, O(logn) for source traversal by Binary search. O(26) for character map
    int shortestWay(string source, string target) {
        unordered_map<char,vector<int>> posMap;
        int m = target.size();
        int n = source.size();
        for(int i=0;i<n;i++) {
            posMap[source[i]].push_back(i);     //push all indices of the particular character in source array
        }
        int ans=1;
        int idx=0;
        for(int i=0;i<m;i++) {
            char ch = target[i];
            
            if(posMap[ch].size()==0) {
                return -1;                  //target has element not present in source array. so no way we can form it with source. return -1.
            }
            else {
                vector<int> posArray = posMap[ch];  //we know this vector is non-null. we can access last element
                
                int highest_index_in_posArray = posArray[posArray.size() - 1];
                
                if(idx > highest_index_in_posArray) {
                    idx=0;
                    ans++;
                }
                int k = binarySearchUpper(idx, posArray);   //posArray[k] denotes the index in which the character is present in source array.
                idx = posArray[k] +1;                               // we need to update idx to point to posArray[k] + 1
                
            }
            
        }
        return ans;
    }
//Returns index of element if found,else returns next index.fr eg:[0,3,5] and target =4. Then return result=2 (i.e. for 5, coz 4 not found && 5 > 4) 
    int binarySearchUpper(int target, vector<int> & arr) {
        int l = 0;
        int h = arr.size() - 1;
        int ans;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(target == arr[mid]) {
                return mid;
            }
            if(target < arr[mid]) {
                h = mid-1;
                ans = mid;
            }
            else {
                l = mid+1;
            }
        }
        return ans;
    }
    
    //o(mn) solutions all below
    /*
    int shortestWay(string source, string target) {
        int ans=0;
        int n1=source.size();
        int n2=target.size();
        
        for(int j=0;j<n2;) {    //NOTICE NO J++
            int originalJ=j;
            for(int i=0;i<n1;i++) {
                if(j<n2 && source[i]==target[j]) {
                    j++;
                }
                
            }
            if(j==originalJ) {
                return -1;      //j never changed its position, means no match in source array (target element didnt match with any element in source array)
            }
            ans++;  //one whole pass through source array means ans++
        }
        return ans;
    }
    */
    /*
     int shortestWay(string source, string target) {
        int i=0;
        int j=0;
        int ans=1;
        int n1=source.size();
        int n2=target.size();
        
        bool sourcemap[26]={false};
        for(int k=0;k<source.size();k++) {
            sourcemap[source[k] - 'a']=true;
        }
        
        while(j<n2) {
            if(sourcemap[target[j]-'a']==false) {
                return -1;
            }
            if(source[i]==target[j]) {
                i++;
                j++;
            }
            else {
                while(i<n1) {
                    if(source[i]!=target[j]) {
                        i++;
                    }
                    else if(source[i]==target[j]) {
                        j++;
                        i++;
                    }
                }
            }
            if(i==n1 && j<n2) {
                i=0;
                ans++;
            }
        }
        return ans;
    }
    
    */
    /*
    int shortestWay(string source, string target) {
        int i=0;
        int j=0;
        int ans=1;
        int n1=source.size();
        int n2=target.size();
        
        set<int> sourceset;
        for(int k=0;k<source.size();k++) {
            sourceset.insert(source[k]);
        }
        
        while(j<n2) {
            if(!sourceset.count(target[j])) {
                return -1;
            }
            if(source[i]==target[j]) {
                i++;
                j++;
            }
            else {
                while(i<n1) {
                    if(source[i]!=target[j]) {
                        i++;
                    }
                    else if(source[i]==target[j]) {
                        j++;
                        i++;
                    }
                }
            }
            if(i==n1 && j<n2) {
                i=0;
                ans++;
            }
        }
        return ans;
    } */
    
// Similar solution:
/*first opinion is that we can use two pointer , one iterate src, another iterate tar.
for each tar char, we move j until src[j] == tar[i], if j == src.length, res++, j = 0;
in this solution, we greedy match as many chars from src to tar as possible which can lead mininum use of src.
and we can build a set to save all the char in src, if there exists a char from tar which not exists in set, return -1.*/
    /*
    public int shortestWay(String source, String target) {
	char[] cs = source.toCharArray(), ts = target.toCharArray();
	boolean[] map = new boolean[26];
	for (int i = 0; i < cs.length; i++) 
		map[cs[i] - 'a'] = true;
	int j = 0, res = 1;
	for (int i = 0; i < ts.length; i++,j++) {
		if (!map[ts[i] - 'a']) return -1;
		while (j < cs.length && cs[j] != ts[i]) {
			j++;
		}
		if (j == cs.length) {
			j = -1;
			res++;
			i--;
		}
	}
	return res;
}
*/
};
