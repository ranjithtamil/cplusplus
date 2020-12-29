class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        if(n==1) {
            return 1;
        }
        int len_char=1;
        int cur_pos = 0;
        for(int i=0;i<n;) {
            len_char=1;
            char cur_char = chars[i];
            if(i+1==n) {
                chars[cur_pos]=chars[i];
                cur_pos++;
                i++;
                continue;
            }
            if(i+1<n && chars[i+1]!=cur_char) {
                chars[cur_pos]=chars[i];
                cur_pos++;
                i++;
                continue;
            }
            while(i+1<n && chars[i+1]==cur_char) {
                i++;
                len_char++;
            }
            chars[cur_pos]=chars[i];
            i++;
            fillCnt(chars,len_char,cur_pos);  
        }
        return min(cur_pos,n);
    }
    void fillCnt(vector<char>& chars, int len, int& cur_pos) {
        int num_digits = 0;
        int num=len;
        while(num>0) {
            num=num/10;
            num_digits++;
        }
        int no_digits=num_digits;
        
        cur_pos++;
        int start=cur_pos;
        while(cur_pos <= (start-1 + num_digits)) {
            chars[start-1+no_digits] = (len%10) + '0';
            no_digits=no_digits-1;
            len=len/10;
            cur_pos++;
        }
        
    }
};
