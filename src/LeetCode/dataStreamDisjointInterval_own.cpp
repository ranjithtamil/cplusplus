//https://www.youtube.com/watch?v=2v6QM47ygzo

class SummaryRanges {
public:
    vector<vector<int>> intervals;
    /** Initialize your data structure here. */
    SummaryRanges() {
        intervals = vector<vector<int>>();
    }
    /*struct Cmp{
        bool operator () (vector<int> x, vector<int> y) {
            if(x[0] < y[0]) {
                return true;
            }
            return false;
        }
        };
    */
    
    void addNum(int val) {
        int n=intervals.size();
        
        //1. If Intervals is empty, make new interval. Action: insert new interval, return.
        if(intervals.size()==0) {
            intervals.push_back({val,val});
            return;
        }
    
        //auto Cmp = [](vector<int> a, vector<int> b) { return a[0] < b[0]; };
        //Find left Interval (i.e., The largest interval which is smaller(has smaller start) than val)
        
        //auto it = lower_bound(intervals.begin(), intervals.end(), {val,val}, Cmp);
        //Above function finds it->start >= val->start. 
        //it--;
        //int leftInterval = it-intervals.begin();
        
        //alternate to it
        
        /*
        
        int leftInterval = n-1;
        while(leftInterval>=0 && intervals[leftInterval][0]>val) {
            //You can improve this one by binary search
            leftInterval--;
        }
        */
        
        //Find left Interval (i.e., The largest interval which is smaller(has smaller start) than val)
        int leftInterval=0;
        int high=n-1;
        int low= 0;
        int mid=0;
    while ( low <= high )
    {
        mid = (low+high)/2; // NB integer arithmetic
        if ( val < intervals[mid][0] ) {
            if ( mid == 0 ) {
                // value < than first item
                mid=-1;
                break;
            }
            else {
                high = mid-1;
            }
        }
        else {  // value >= list[mid]
            if ( mid == n-1 ) {
                // value is >= last item
                break;
            }
            else if ( val >= intervals[mid+1][0] ) {
                low = mid+1;
            }
            else // list[mid] must be biggest <= value
                break;
        }
    }
        leftInterval=mid;
        
        
        
    //If value is in between an interval. Then, val is smaller than leftInterval's end Or Equal to leftInterval's end. Action: just return
        if(leftInterval >=0 && intervals[leftInterval][1] >= val) {
            return;
        }
        
        
        //val is One away from end of interval.Action: Upate that Interval's end to val value.
        if(leftInterval >=0 && intervals[leftInterval][1] == val-1) {
            intervals[leftInterval][1]=val;
        }//leftInterval+1 is rightInterval. below:One away from beginning of interval 
        else if(leftInterval+1 < n && intervals[leftInterval+1][0] == val+1) {
            intervals[leftInterval+1][0]=val;//Action: Update rightInterval's start to val value.
        }
        else {//More than 1 away from both start/end of intervals
            intervals.insert(intervals.begin() + leftInterval + 1, {val,val});
        }
        
        //See whether val is between two intervals, so you can merge. Left interval's end will be Right interval's start-1.
        if(leftInterval >=0 && leftInterval+1<n && intervals[leftInterval][1]==intervals[leftInterval+1][0]-1) {
            intervals[leftInterval][1]=intervals[leftInterval+1][1];
            intervals.erase(intervals.begin()+leftInterval+1);
        }
        
        
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
