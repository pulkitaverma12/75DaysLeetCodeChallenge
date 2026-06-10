class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int mins = INT_MAX;
        int maxs = INT_MIN;

        // Step 1: Find the absolute bounds of our timeline
        for(int i=0; i<intervals.size(); i++){
            mins=min(mins, intervals[i][0]);
            maxs=max(maxs, intervals[i][1]);
        }

        // Step 2: Initialize frequency arrays sized exactly to our range
        vector<int> vec1(maxs-mins+1, 0); // Tracks starts
        vector<int> vec2(maxs-mins+1, 0); // Tracks ends
        vector<vector<int>> res;

        int start, end;

        for(int i=0; i<intervals.size(); i++){
            start = intervals[i][0];
            end = intervals[i][1];

            vec1[start-mins]++;
            vec2[end-mins]++;
        }

        int i=0;
        int sum=0;

        // Step 3: Sweep the timeline to merge overlapping active zones
        while(i<vec1.size()){
            while(i<vec1.size() && sum==0){
                sum+=vec1[i];
                i++;
            }
            i--; // Rewind 1 step to process the current valid coordinate
            sum-=vec2[i];

            // Edge case: Handle isolated point intervals [x, x]
            if(sum==0){
                res.push_back({i+mins,i+mins});
                i++;
                continue;
            }
            start = i+mins;
            i++;

            // Fast-forward through the active merged interval
            while(i<vec2.size() && sum!=0){
                sum-=vec2[i]; // Subtract ends
                sum+=vec1[i]; // Add starts (bounces sum back up if touching)
                i++;
            }

            // The active interval has fully closed
            end = i+mins-1;
            res.push_back({start,end});
        }
        
        return res;
    }
};