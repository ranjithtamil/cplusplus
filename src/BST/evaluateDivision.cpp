class Solution {
public:
    pair<string, double> findSet(unordered_map<string, pair<string,double>>&G, string nodeGid) {
        if(G.find(nodeGid)==G.end()) {
            G[nodeGid]=make_pair(nodeGid, 1.0);
        }
        
        pair<string, double> gentry = G[nodeGid];
        
        
        if(gentry.first != nodeGid) {
            pair<string, double> newEntry = findSet(G, gentry.first);
            G[nodeGid] = make_pair(newEntry.first, gentry.second * newEntry.second);
        }
        
        return G[nodeGid];
    }
    void Union(unordered_map<string,pair<string,double>> &G, string dividend, string divisor, double quotient) {
        pair<string, double> dividendEntry = findSet(G, dividend);
        pair<string, double> divisorEntry = findSet(G, divisor);
        
        string dividendGid = dividendEntry.first;
        string divisorGid = divisorEntry.first;
        
        double dividendWeight = dividendEntry.second;
        double divisorWeight = divisorEntry.second;
        
        if(dividendGid != divisorGid) {
            G[dividendGid] = make_pair(divisorGid,(divisorWeight * quotient)/dividendWeight);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, pair<string, double>> G;
        
        int eq_size = equations.size();
        for(int i=0;i<eq_size;i++) {
            string dividend = (equations[i])[0];
            string divisor = (equations[i])[1];
            double quotient = values[i];
            Union(G,dividend,divisor,quotient);
        }
        
        int query_size = queries.size();
        vector<double> results(query_size);
        
        
        for(int i=0; i<query_size; i++) {
            string query_dividend = (queries[i])[0];
            string query_divisor = (queries[i])[1];
            
            if(G.find(query_dividend)==G.end() || G.find(query_divisor)==G.end()) {
                results[i]=-1.0;
            }
            else if(query_dividend == query_divisor) {
                    results[i] = 1.0;
            }
            else {
                pair<string, double> dividendEntry = findSet(G, query_dividend);
                pair<string, double> divisorEntry = findSet(G, query_divisor);
                
                
                
                string dividendGid = dividendEntry.first;
                string divisorGid = divisorEntry.first;
                
                double dividendWeight = dividendEntry.second;
                double divisorWeight = divisorEntry.second;
                
                if(dividendGid != divisorGid) {
                    results[i] = -1.0;      // no path between divisor and dividend
                }
                else {
                    results[i] = dividendWeight/divisorWeight;
                }
            }
        }
        return results;
    }
    /*
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> G;
        
        int eq_size = equations.size();
        for(int i = 0; i < eq_size; i++) {
            //vector<string> eq = equations[i];
            //string dividend = eq[0];
            //string divisor = eq[1];
            
            string dividend = (equations[i])[0];
            string divisor = (equations[i])[1];
            double quotient = values[i];
            
            
            G[dividend][divisor]=quotient;
            G[divisor][dividend]=1/quotient;
        }
        
        int queries_size = queries.size();
        vector<double> results(queries_size,-1.0);
        
        for(int i=0;i<queries_size;i++) {
            //vector<string> query = queries[i];
            //string query_dividend = query[0];
            //string query_divisor = query[1];
            
            string query_dividend = (queries[i])[0];
            string query_divisor = (queries[i])[1];
            
            if(G.find(query_dividend)==G.end() || G.find(query_divisor)==G.end()) {
                results[i]=-1.0;
            }
            else if(query_dividend==query_divisor ) {
                results[i]=1.0;
            }
            else {
                unordered_set<string> visited;
                results[i]=backTrackEvaluate(G,query_dividend,query_divisor,1,visited);
            }
        }
        return results;
    }
    
    double backTrackEvaluate(unordered_map<string, unordered_map<string,double>> G, string curNode, string targetNode, double accProduct, unordered_set<string> visited) {
        
        visited.insert(curNode);
        double ret = -1.0;
        
        unordered_map<string, double> neighbors = G[curNode];        
        if(neighbors.find(targetNode)!=neighbors.end()) {
            ret = accProduct * neighbors[targetNode];
        }
        else {
            for(unordered_map<string, double>::iterator it = neighbors.begin(); it!=neighbors.end(); it++) {
                string nextNode = it->first;
                if(!visited.count(nextNode)) {
                    ret = backTrackEvaluate(G, nextNode, targetNode, accProduct* (it->second), visited);
                    if((ret!=-1.0)) {
                        break;
                    }
                }
            }
        }
        //visited.erase(curNode);
        return ret;
    }
    */
};
