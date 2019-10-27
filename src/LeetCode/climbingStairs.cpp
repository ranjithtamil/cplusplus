/*
70. Climbing Stairs (https://www.youtube.com/watch?v=5o-kdjv7FD0)

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/

class Solution {
public:
    vector<int> num_ways;
   
    int maxsofar=2;
    int climb_stairs(int n) {
        //cout<<"\nn = "<<n;
        //cout<<"\nnum_ways.size() = "<<num_ways.size();
        //cout<<"\nmaxsofar = "<<maxsofar<<"\n";
        if((num_ways.size()) <= n) {//because num_ways[0] should also be accounted. Should enter loop till size==n.in-end, size=n+1
            for(int i=maxsofar;i<=n;i++) { //till maxsofar==n
                int temp=num_ways[i-1] + num_ways[i-2];    //base case: temp = num_ways[1] + num_ways[0] 
                //cout<<"\ntemp = "<<temp<<"\n";
                num_ways.push_back(temp);
            }
            maxsofar=n+1;//in beginning, num_ways[0]=1,num_ways[1]=1, maxsofar=2.. Suppose we calculated num_ways[2]=2,num_ways[3]=3, then maxsofar=4. maxsofar is the index of next element(for which num_ways[] needs)to be calculated
        }
        return num_ways[maxsofar-1];
    }
    int climbStairs(int n) {
        num_ways.push_back(1); //num_ways[0]=1
        num_ways.push_back(1); //num_ways[1]=1
        return climb_stairs(n);
    }
};


/* Iterative 

class Solution {
public:
    vector<int> num_ways;
   
    int climbStairs(int n) {
        
        vector<int> num_ways;
        num_ways.push_back(1);
        num_ways.push_back(1);
        
        for(int i=2;i<=n;i++) {
            int temp=num_ways[i-1]+num_ways[i-2];
            num_ways.push_back(temp);
        }
        return(num_ways[n]);
    }
};

*/

/*
Recursion with memoization MAPS
class Solution {
public:
    map<int,int> num_ways;
   
    int maxsofar=2;
    int climb_stairs(int n) {
        if(num_ways.find(n)==num_ways.end()) {
            for(int i=maxsofar;i<=n;i++) {
                num_ways[i]=num_ways[i-1]+num_ways[i-2];
            }
            maxsofar=n;
        }
        return num_ways[n];
    }
    int climbStairs(int n) {
        num_ways[0]=1;
        num_ways[1]=1;
        return climb_stairs(n);
    }
};
*/


/*

RECURSION

class Solution {
public:
    int climb_stairs(int n) {
        if(n==1 || n==0) {
            return 1;
        }
        else if(n<0) {
            return 0;
        }
        else {
            return (climb_stairs(n-1) + climb_stairs(n-2));
        }
    }
    int climbStairs(int n) {
        return climb_stairs(n);
    }
};
*/

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
