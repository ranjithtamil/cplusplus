/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> mySet;
    
    vector<string> vec{
        "Coursera",
        "Google",
        "Facebook",
        "Amazon",
        "Microsoft",
        "Airbnb",
        "Adobe",
        "Uber",
        "Twilio",
        "Stripe",
        "Twitter", 
        "Paypal",
        "Cisco",
        "Yelp",
        "Meraki",
        "Addepar",
        "GoDaddy",
        "LiveRamp",
        "FiveStars",
        "Asana",
        "Square",
        "Blizzard",
        "Indeed",
        "eBay",
        "Fitbit",
        "PureStorage",
        "Qualtrics",
        "Quantcast",
        "Whitepages",
        "Bloomberg",
        "Affirm",
        "TubularLabs",
        "Delphix",
        "Doordash",
        "Quora",
        "Ciena",
        "commscope",
        "TubeMogul",
        "CapitalOne",
        "Wish",
        "Slack",
        "Tinder",
        "Medallia",
        "BlueApron",
        "JPMorgan",
        "GrandRounds",
        "Visa",
        "LatticeEngines",
        "Segment",
        "BlendLabs",
        "Moodys",
        "ATnT",
        "EA",
        "IBM",
        "Demandware",
        "Curalate",
        "Pixar",
        "Xero",
        "Viasat",
        "Qualcomm",
        "Samsung",
        "Amazon",
        "Microsoft",
        "Goldmansachs",
        "apple",
        "google",
        "facebook",
        "salesforce",
        "visa",
        "cisco",
        "slack",
        "paypal",
        "oracle",
        "adobe",
        "dropbox",
        "twitter",
        "linkedIn",
        "nvidia",
        "snap",
        "spotify",
        "intel",
        "netflix",
        "tesla",
        "amd",
        "atlassian",
        "purestorage",
        "square",
        "nutanix",
        "twilio",
        "confluent",
        "snowflake",
        "netapp",
        "walmartlabs",
        "thoughtspot",
        "splunk",
        "rubrik",
        "twitter",
        "cloudflare",
        "akamai",
        "datadog",
        "docker",
        "mongodB",
        "quora",
        "robinhood",
        "squarespace",
        "ebay",
        "intuit",
        "godaddy",
        "citi",
        "morganstreet",
        "redhat",
        "thoughtworks",
        "samsaraiot",
        "memsql",
        "arista",
        "reddit"};
        int n=vec.size();
        for(int i=0;i<n;i++) {
            transform(vec[i].begin(),vec[i].end(),vec[i].begin(),::tolower);
            mySet.insert(vec[i]);
        }
        for(set<string>::iterator it=mySet.begin();it!=mySet.end();it++) {
            cout<<"\n"<<*it;
        }
        
    
    return 0;
}
