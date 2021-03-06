/*
https://www.youtube.com/watch?v=HmBbcDiJapY
*/
class Solution {
public:
    int trap(vector<int>& height) {
        //https://www.youtube.com/watch?v=HmBbcDiJapY
        /*
        int n = height.size();
        if( n==0 ) {
            return 0;
        }
        if( n==1 ) {
            return 0;
        }
        
        int result=0;
        for( int i = 0; i<n; i++) {
            int lmax=0;
            int rmax=0;
            for(int x=i; x>=0; x--) {
                lmax=max(lmax, height[x]);
            }
            for(int x=i;x<n; x++) {
                rmax=max(rmax, height[x]);
            }
            
            int minOfBoth = min(lmax,rmax);
            int current_trapped = minOfBoth - height[i];
            result=result+current_trapped;
        }
        return result;
        */
        
        /*
        int n = height.size();
        if( n==0 ) {
            return 0;
        }
        if( n==1 ) {
            return 0;
        }
        
        vector<int> lmaxArr(n,0);
        vector<int> rmaxArr(n,0);
        int result=0;
        
        for(int i=0; i<n; i++) {
            int lmax=height[i];
            lmaxArr[i]=lmax;
            if(i>0) {
                lmaxArr[i]=max(lmaxArr[i],lmaxArr[i-1]);
            }
        }
        for(int i=n-1; i>=0; i--) {
            int rmax=height[i];
            rmaxArr[i]=rmax;
            if(i<n-1) {
                rmaxArr[i]=max(rmaxArr[i],rmaxArr[i+1]);
            }
        }
        
        
        for(int j=0;j<n;j++) {
            int lmax=lmaxArr[j];
            int rmax=rmaxArr[j];
            
           result = result + (min(lmax,rmax)  - height[j]);
        }
        return result;
        */
        
        
        
        //https://www.youtube.com/watch?v=XqTBrQYYUcc
        //Finding lower Envelope of 2 monotonic functions
        int n = height.size();
        if( n==0 ) {
            return 0;
        }
        if( n==1 ) {
            return 0;
        }
        
        int result=0;
        
        int i=0;
        int j=n-1;
        int lmax=height[0];
        int rmax=height[n-1];
        while(i<j) {
            
            if(i>0) {
                lmax=max(lmax,height[i]);
            }
            if(j<n-1) {
                rmax=max(rmax,height[j]);
            }
            
            if(lmax > rmax) {
                result=result+(rmax-height[j]);
                j--;
            }
            else {
                result=result+(lmax-height[i]);
                i++;
            }
        }
        return result;
    }
};
