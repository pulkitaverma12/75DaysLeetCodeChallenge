class Solution {
public:
vector<string> ans;
void solve(string cur,int n){
    if(cur.size() == n){
        ans.push_back(cur);
        return;
    }
    for(char ch : {'a','b','c'}){
        if(cur.empty() || cur.back() != ch){
            solve(cur + ch,n);
        }
    }
}
    string getHappyString(int n, int k) {
        solve("",n);
        if(k > ans.size()){
            return "";
        }
       return ans[k-1];
    }
};