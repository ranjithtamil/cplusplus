/*
34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { 
        vector<int> res;
        if(nums.empty()) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
        int j=0;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++) {
            
            if( *it==target) {
                res.push_back(j);
                break;
            }
            j++;
        }
       int k=nums.size()-1;
        for(vector<int>::iterator it=nums.begin()+k;;it--) {
            if( *it==target && k!=(res[0])) {
                res.push_back(k);
                break;
            }
            k--;
            if(it==nums.begin()) {
                break;
            }
        }
        
        if(res.size()==2){
            
            return res;
        }
        else if(res.size()==1){
            res.push_back(res[0]);
            return res;
        }
        
        
        res.push_back(-1);
        res.push_back(-1);
        return res;
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

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().searchRange(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
