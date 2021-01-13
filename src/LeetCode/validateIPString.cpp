class Solution {
public:
    string validIPAddress(string IP) {
        if(validateIPv4Address(IP)) {
            return "IPv4";
        }
        if(validateIPv6Address(IP)) {
            return "IPv6";
        }
        return "Neither";
    }
    bool validateIPv4Address(string IP) {
        if (count(IP.begin(), IP.end(), '.') != 3) {
            return false;
        }
        vector<string> parts = split(IP,'.');
        if(parts.size()!=4) {
            return false;
        }
        for(int i=0;i<parts.size();i++) {
            string part=parts[i];
            
            if(part.size()>1 && part[0]=='0') { //leading zeros
                return false;
            }
            if(part.empty()) {  //empty string
                return false;
            }
            if(part.size()>3) { //IP can only be 3 digits long
                return false;
            }
            int num=0;
            for(int j=0;j<part.size();j++) {
                char ch=part[j];
                if(!(ch>='0' && ch<='9')) {
                    return false;
                }
                num=num*10 + (ch-'0');
            }
            if(num>255) {
                return false;
            }
        }
        return true;
    }
    bool validateIPv6Address(string IP) {
        if (count(IP.begin(), IP.end(), ':') != 7) {
            return false;
        }
        vector<string> parts = split(IP, ':');
        if (parts.size() != 8) {
            return false;
        }
        for (string part : parts) {
            if (part.empty() || part.size() > 4) {
                return false;
            }
            for(int j=0;j<part.size();j++) {
                char ch=part[j];
                if(!(ch>='0' && ch<='9')) {
                    //if not digit, then a-f or A-F
                    if(!(ch>='a' && ch<='f')) {
                        if(!(ch>='A' && ch<='F')) {
                            return false;
                        }
                    }
                }
            }
            
        }
        return true;
    }
    vector<string> split(string s,char c) {
        vector<string> parts;
        string part;
        istringstream in(s);
        
        while(getline(in,part,c)) {
            parts.push_back(part);
        }
        return parts;
    }
};
