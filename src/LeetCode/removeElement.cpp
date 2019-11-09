/*
Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,1,2,2,3,0,4,2], val = 2,

Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.

Note that the order of those five elements can be arbitrary.

It doesn't matter what values are set beyond the returned length.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        
        if(nums.size()==0) {
            return 0;
        }
        for(int i=0;i<n;) {
            if(nums[i]==val) {  
                n--;                    
                for(int j=i;j<n;j++) {      //if you find the value to be removed, shift all elements from right of it one place to left, and decrement the size of array
                    nums[j]=nums[j+1];      //dont increment i until nums[i]!=val
                }
            }
            else {
                i++;                        //when nums[i]!=val, increment i
            }
        }
        return n;
    } 
};

// suboptimal solution
/*
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int n=nums.size();
        for(int j=0;j<n;j++) {
            if(nums[j]!=val) {
                nums[i]=nums[j];
                i++;
            }
        }
        return i; //(actually i jumps out of the array but since length is asked, it is i )
    } 
};    
*/
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
        int val = stringToInteger(line);
        
        int ret = Solution().removeElement(nums, val);

        string out = integerVectorToString(nums, ret);
        cout << out << endl;
    }
    return 0;
}
