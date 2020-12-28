//https://leetcode.com/problems/k-closest-points-to-origin/discuss/217966/C%2B%2B-3-lines-nth_element-O(n)
/* based on sorting. but better solution better than 90% and 72% time and space respectively
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        vector<int> dist;
        vector<vector<int>> result;
        for(int i=0;i<n;i++) {
            int pointX=points[i][0];
            int pointY=points[i][1];
            
            dist.push_back(pointX*pointX + pointY*pointY);
        }
        
        sort(dist.begin(),dist.end());
        
        for(int i=0;i<n;i++) {
            int pointX=points[i][0];
            int pointY=points[i][1];
            if(result.size()==K)
            {
                break;
            } 
            if(pointX*pointX + pointY*pointY <= dist[K-1]) {
                result.push_back({pointX,pointY});
            }
        }
        return result;
    }
    */
    /*
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        sort(points.begin(),points.end(),[](vector<int> pointA, vector<int> pointB) {
           if(pointA[0]*pointA[0] + pointA[1]*pointA[1]  <= pointB[0]*pointB[0] + pointB[1]*pointB[1]) {
               return true;
           } 
           return false;
        });
        
        vector<vector<int>> result;
        for(int i=0; i<K; i++) {
            result.push_back(points[i]);
        }
        return result;
    }
    */
    /* //Heap-Method
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        //create a min heap of Euclidean distance (euclidean distance = sqroot(x^2 + y^2) for distance from origin. => but you dont need to do sqroot.)
        priority_queue<int, vector<int>, greater<int>> hp;
        unordered_map<int,vector<vector<int>>> umap;
        //store a map so that you can map distance to the vector of points with same distance. So for a specific euclidean distance, you have a vector of <x,y> points that give the distance.
        
        for(int i=0;i<points.size();i++) {
            vector<int> point = points[i];
            int dist = (point[0]*point[0] + point[1]*point[1]);         //while storing distance on the heap, populate the map as well
            umap[dist].push_back(point);
            hp.push(dist);
        }

        vector<vector<int>> result;
        
        
        for(int i=0;i<K;i++) {
            if(hp.empty()==false) {         
                
                
                int minDist = hp.top();
                vector<vector<int>> pointsWithMinDist = umap[minDist];                  //get the minDistance from heap and extract the vector of points with this distance
                if(pointsWithMinDist.size() == 1) {                                     //if vector has only one element, pop element from heap
                    result.push_back(pointsWithMinDist[0]);                                //update answer with point
                    //umap[minDist].pop_back();
                    pointsWithMinDist.pop_back();                                       //pop the point from vector, and update the map without this point
                    //umap[minDist]=vector<vector<int>>();
                    umap[minDist]=pointsWithMinDist;            
                    hp.pop();                                                           //pop heap
                }
                else {
                    result.push_back(pointsWithMinDist.back());                            //update answer with point
                    //umap[minDist].pop_back();
                    pointsWithMinDist.pop_back();                                           //pop the point from vector, and update the map without this point
                    umap[minDist]=pointsWithMinDist;
                }
            }
        }
        return result;
    }
    */

/*
C++ STL, quickselect, priority_queue and multiset
The simplest solution is to use partial_sort or nth_element to order the K closest points at the beginning of points. Here we need a custom comparator to compare the closeness of points. This solution is of O(nlogK) time. If we ignore the space of the output since that is inevitable, this solution is of O(1) space.

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        partial_sort(points.begin(), points.begin() + K, points.end(), [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin() + K - 1, points.end(), [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
You may also implement the underlying quickselect algorithm yourself.

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int l = 0, r = points.size() - 1;
        while (true) {
            int p = partition(points, l, r);
            if (p == K - 1) {
                break;
            }
            if (p < K - 1) {
                l = p + 1;
            } else {
                r = p - 1;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
private:
    bool farther(vector<int>& p, vector<int>& q) {
        return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
    }
    
    bool closer(vector<int>& p, vector<int>& q) {
        return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
    }
    
    int partition(vector<vector<int>>& points, int left, int right) {
        int pivot = left, l = left + 1, r = right;
        while (l <= r) {
            if (farther(points[l], points[pivot]) && closer(points[r], points[pivot])) {
                swap(points[l++], points[r--]);
            }
            if (!farther(points[l], points[pivot])) {
                l++;
            }
            if (!closer(points[r], points[pivot])) {
                r--;
            }
        }
        swap(points[pivot], points[r]);
        return r;
    }
};
If you would not like to modify points, you may maintain the K closest points so far in a separate data structure. We can use a max heap to maintain the K closest points. A max heap has its largest element in the root. Each time we add a point to the heap, if its size exceeds K, we pop the root, which means we get rid of the farthest point and keep the closest ones. This solution is also of O(nlogK) time.

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for (vector<int>& point : points) {
            pq.push(point);
            if (pq.size() > K) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
private:
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
};
We can also use a min heap. A min heap has the smallest element in the root. We add all the points to the heap, and then pop the first K ones, we are just the closest ones. This makes the code shorter. Now this one is of O(n + Klogn) time. The n part is on adding all points to the heap (building a min heap for all the points) and the Klogn part is on fetching the top K points from the heap.

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq(points.begin(), points.end());
        vector<vector<int>> ans;
        for (int i = 0; i < K; i++) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
private:
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
        }
    };
};
Note that for priority_queue, if you would like to use it as a max heap, the comparator should be < and if as a min heap, the comparator is >.

Max/min heaps can also be implemented using multiset. For multiset, max heap has > and min heap has < in the comparator. The following two solutions are respectively max/min heap using multiset.

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multiset<vector<int>, compare> mset;
        for (vector<int>& point : points) {
            mset.insert(point);
            if (mset.size() > K) {
                mset.erase(mset.begin());
            }
        }
        vector<vector<int>> ans;
        copy_n(mset.begin(), K, back_inserter(ans));
        return ans;
    }
private:
    struct compare {
        bool operator()(const vector<int>& p, const vector<int>& q) const {
            return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
        }
    };
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multiset<vector<int>, compare> mset(points.begin(), points.end());
        vector<vector<int>> ans;
        copy_n(mset.begin(), K, back_inserter(ans));
        return ans;
    }
private:
    struct compare {
        bool operator()(const vector<int>& p, const vector<int>& q) const {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
};
*/
