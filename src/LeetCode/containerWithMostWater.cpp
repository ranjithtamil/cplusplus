/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

//BRUTE FORCE METHOD
/*
class Solution {
public:
    int minimum(int a,int b) {
        if(a<=b) {
            return a;
        }
        else {
            return b;
        }
    }
    int maxArea(vector<int>& height) {
        int n=height.size();
        if( n<=1 ) {
            return 0;
        }
        
        int maxarea=0;
        for(int i=0;i<n-1;i++) {
            int area=0;
            for(int j=i+1;j<n; j++) {
                area=(j-i) * minimum(height[i],height[j]);
                if(area > maxarea) {
                    maxarea=area;
                }
            }
        }
        return maxarea;
    }
};
*/

//Two Pointer approach
class Solution {
public:
    int minimum(int a,int b) {
        if(a<=b) {
            return a;
        }
        else {
            return b;
        }
    }
    int maxArea(vector<int>& height) {
        int n=height.size();
        if( n<=1 ) {
            return 0;
        }
        int maxarea=0;
        for(int i=0,j=n-1;i<j;) {
            int area = (j-i) * minimum(height[i],height[j]);
            if(height[i]<height[j]) {   //move pointer of shorter line. if ith line is shorter than jth line, move i to right. if instead longer line was moved, then area would definitely decrease.
                i++;
            }
            else {  // if jth line is shorter than ith line, move j to left
                j--;
            }
            
            if(area > maxarea) {
                maxarea=area;
            }
        }
        
        return maxarea;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntegerVector(line);
        
        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
