class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int> mpp;
        priority_queue<int> pq;
        for(char c : tasks){
            mpp[c]++;
        }
        for(auto const&[x,y] : mpp){
            pq.push(y);
        }

        int time = 0;
        while(!pq.empty()){
           int cycle = n+1;
           vector<int> store;
           int taskcnt = 0;

           while(cycle -- && !pq.empty()){
              if(pq.top()>1){
                store.push_back(pq.top()-1);
              }
              pq.pop();
              taskcnt++;
           }
           for(int &x : store){
                pq.push(x);
           }
           time+=(pq.empty() ? taskcnt : n+1);
        }
        return time;
    }
};