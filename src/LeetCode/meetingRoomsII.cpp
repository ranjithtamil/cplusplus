class Solution {
public:
    /*
    Algorithm.
    1. Sort the meeting interval input by ascending order of start times - so that you can service the earlier meetings first.
        (Instead of sorting, you can use a minheap which always extracts the minimum starting time)
    2. While processing the input from the sorted/minheap of starting times, see the incoming ending times and add the ending times to a heap (Min heap of ending times). Why ?  You can check the minimum element in the heap (Which gives the earliest meeting to end amongst meetings in progress. If the start time of the next incoming meeting input is after the ending time of the older meeting(min element of minheap), then that old room can be used to accomodate the incoming meeting request. Otherwise, if the current incoming meeting starting time is less than the older meeting's (min element of minheap) end time, you can add it to the heap )...
    2.5 - The brute force method of using without heap - would be to scan amongst all meetings in progress(all earlier seen intervals), and see which one has the minimum ending time, and then compare the incoming starting time with that found minimum ending time.
    
    3. At the end, the size of the minheap would give the minimum amount of meeting rooms required to accomodate all the meetings.
    */
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //Brute force
        int n=intervals.size();
        if(n==0) {
            return 0;
        }
        if(n==1) {
            return 1;
        }
        priority_queue<pair<int,int>> mh_st;//minheap_startingTimes.buthasboth starting time and ending time info
        priority_queue<int> mh_et;  //minheap_endingTimes
        
        for(int i=0;i<n;i++) {
            mh_st.push(make_pair(-1*(intervals[i][0]),-1*(intervals[i][1])));
        }
        while(!mh_st.empty()) {
            pair<int,int> curr_interval = mh_st.top();
            int cur_st = curr_interval.first;
            int cur_et = curr_interval.second;
            mh_st.pop();   
            if(!mh_et.empty()) {
                int min_old_ets = mh_et.top();
                if((-1*cur_st) >= (-1*min_old_ets)) {
                    mh_et.pop();
                    mh_et.push(cur_et); //pop the older meeting with ending time finished, and push the newer one
                }
                else {
                    mh_et.push(cur_et); //push it to heap
                }
            }
            else {
                mh_et.push(cur_et);
            }   
        }
        return mh_et.size();
    }
};




