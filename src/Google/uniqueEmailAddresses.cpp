#if 0
929. Unique Email Addresses
Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails? 

Example 1:

Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
 
Note:
1 <= emails[i].length <= 100
1 <= emails.length <= 100
Each emails[i] contains exactly one '@' character.
All local and domain names are non-empty.
Local names do not start with a '+' character.
#endif

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>seen;
        for(int i=0;i<emails.size();i++) {
            string curr=emails[i];
            int posAt=curr.find('@');
            string local=curr.substr(0,posAt);
            int posPlus=local.find('+');
            if(posPlus) {
                local=local.substr(0,posPlus);
            }
            local.erase(remove(local.begin(),local.end(),'.'),local.end());
            local=local+'@'+curr.substr(posAt+1,curr.size());
            seen.insert(local);
        }
        return seen.size();
    }
};

//no library functions
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>seen;
        for(int i=0;i<emails.size();i++) {
            string curr=emails[i];
            //
            //cout<<"\ncurr="<<curr;
            //
            //int p=0;
            int q=0;
            string local="";
            string rest="";
            while(q<curr.size()) {
                if(curr[q]=='@') {
                    break;
                }
                if(curr[q]=='+') {
                    break;
                }
                if(curr[q]=='.') {
                    q++;
                }
                else {
                    //local[p]=curr[q];
                    //p++;
                    local=local+curr[q];
                    q++;
                }
            }
            if(q<curr.size() && curr[q]=='+') {
                while(q<curr.size() && curr[q]!='@') {
                    q++;
                }
            }
            if(q<curr.size() && curr[q]=='@') {
                q++;
                while(q<curr.size()) {
                    rest=rest+curr[q];
                    q++;
                } 
            }
            //
            //cout<<"\nlocal = "<<local<<"rest="<<rest;
            //
            seen.insert(local+"@"+rest);
        }
        return seen.size();
    }
};