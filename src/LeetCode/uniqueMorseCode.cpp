
/*
International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cba" can be written as "-.-..--...", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation: 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
Note:

The length of words will be at most 100.
Each words[i] will have length in range [1, 12].
words[i] will only consist of lowercase letters.

*/


using namespace std;
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> set_of_morse;
        
        //create a map of alphabet to morse code
        //get each word from vector 'words'.
        //loop through characters. access map[character] and concat/append to a string. thus create morse-code-string for each word.
        //if unique, add it to set
        
        map<char,string> morse_map;
        morse_map['a']=".-";
        morse_map['b']="-...";
        morse_map['c']="-.-.";
        morse_map['d']="-..";
        morse_map['e']=".";
        morse_map['f']="..-.";
        morse_map['g']="--.";
        morse_map['h']="....";
        morse_map['i']="..";
        morse_map['j']=".---";
        morse_map['k']="-.-";
        morse_map['l']=".-..";
        morse_map['m']="--";
        morse_map['n']="-.";
        morse_map['o']="---";
        morse_map['p']=".--.";
        morse_map['q']="--.-";
        morse_map['r']=".-.";
        morse_map['s']="...";
        morse_map['t']="-";
        morse_map['u']="..-";
        morse_map['v']="...-";
        morse_map['w']=".--";
        morse_map['x']="-..-";
        morse_map['y']="-.--";
        morse_map['z']="--..";
        //Next time, initialize static map like below:
        //map<int, char> m = {{1, 'a'}, {3, 'b'}, {5, 'c'}, {7, 'd'}};
        
        for(vector<string>::iterator it=words.begin();it!=words.end();++it)
        {
            string morse_string="";
            for(string::iterator sit=(*it).begin();sit!=(*it).end();++sit)
            {
                morse_string=morse_string+morse_map[*sit];
            }
            
            if(set_of_morse.find(morse_string)==set_of_morse.end())
            {
                set_of_morse.insert(morse_string);
            }
        
        }
        
        return set_of_morse.size();
        
    }
};