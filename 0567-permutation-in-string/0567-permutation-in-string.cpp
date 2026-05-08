class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      int n1=s1.size(),n2=s2.size();
      if(n1>n2) return false;
      vector<int>freq1(26,0),freq2(26,0);
      for(char c:s1){
        freq1[c-'a']++;
      }
      int left=0;
      for(int right=0;right<n2;right++){
        freq2[s2[right]-'a']++;
        if(right-left+1>n1){
            freq2[s2[left]-'a']--;
            left++;
        }
        if(freq1==freq2) return true;
      }
      return false;
    }
};