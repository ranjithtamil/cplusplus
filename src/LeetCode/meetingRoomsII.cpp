class Solution {
public:
    /*
    Algorithm.
    1. Sort the meeting interval input by ascending order of start times - so that you can service the earlier meetings first.
        (Instead of sorting, you can use a minheap which always extracts the minimum starting time)
        
    2.brute - process each input of minheap_st. (so, you pick the element with first start time(curr_el)). Now, look at all the meetings in the list. have a list endingtimes=[]. for first element, ending times[] will be empty, so add curr_el.endingtime to endingTimes=[].
    Now, when you keep processing elements from minheap_st, keep checking in endingTimes list if any of those meetings are over (i.e., find the smallest ending time in the list (minEndingTime in the endingTimes list), and check if the current element's starting Time is after that(current st >= minEndingTime). If so, remove the minEndingTime from the endingTimes list, and add the current element's endingTime to the endingTime's list). Otherwise (if you find current element starting time <= minEndingTime, it means overlap and that the same room cannot be reused), so add the current element's ending Time to the endingTime's list. In the end, the size of the endingTimes list will give you the amount of meeting rooms required.
    2.nonbrute - {***You can use a minheap for the endingTimes list to find the minEndingTime repeatedly ***} While processing the input from the sorted/minheap of starting times, see the incoming ending times and add the ending times to a heap (Min heap of ending times). Why ?  You can check the minimum element in the heap (Which gives the earliest meeting to end amongst meetings in progress. If the start time of the next incoming meeting input is after the ending time of the older meeting(min element of minheap), then that old room can be used to accomodate the incoming meeting request. Otherwise, if the current incoming meeting starting time is less than the older meeting's (min element of minheap) end time, you can add it to the heap )...
    2.5 - The brute force method of using without heap - would be to scan amongst all meetings in progress(all earlier seen intervals), and see which one has the minimum ending time, and then compare the incoming starting time with that found minimum ending time.
    
    3. At the end, the size of the minheap would give the minimum amount of meeting rooms required to accomodate all the meetings.
    */
    
    struct comparatorr {
      bool operator()(pair<int,int> x, pair<int,int> y) {
          if(x.first > y.first) {
              return true;      //for minHeap
          }
          return false;
      }  
    };
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0) {
            return 0;
        }
        if(n==1) {
            return 1;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparatorr> min_st;
        priority_queue<int,vector<int>,greater<int>> min_et;
        
        for(int i=0;i<n;i++) {
            min_st.push(make_pair(intervals[i][0],intervals[i][1]));
        }
        
        while(!min_st.empty()) {
            int cur_st = min_st.top().first;
            int cur_end = min_st.top().second;
            
            min_st.pop();
            if(min_et.empty()) {
                min_et.push(cur_end);
            }
            else {
                int minEndingTime = min_et.top();
                if(cur_st >= minEndingTime) {
                    min_et.pop(); //pops minEndingTime from min_et.same room can be reused (can be removed), so pop and update endingTime with that of cur
                    min_et.push(cur_end);
                }
                else {
                    min_et.push(cur_end);   //overlap. so cannot reuse same room.
                }
            }
            
        }
        return min_et.size();
    }
    /*
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
    }*/
};
