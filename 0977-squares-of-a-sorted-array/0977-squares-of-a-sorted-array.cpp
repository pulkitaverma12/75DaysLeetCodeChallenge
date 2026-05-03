class Solution {
public:
    vector<int> sortedSquares(vector<int>& num) {
        int size = num.size();
        vector<int> pos;
        vector<int> neg;
        for(int i=0;i<size;i++)
        {
            if(num[i]<0)
            neg.push_back(num[i]);
            else 
            pos.push_back(num[i]);
        }
        // agar positive hai toh
        if(neg.size()==0)
        {
            for(int i=0;i<pos.size();i++)
            {
                pos[i]= pos[i] * pos[i];
            }
            return pos;
        }
        // agar negative hai toh 
        if(pos.size()==0)
        {
            for(int i=0;i<neg.size();i++)
            {
                neg[i]= neg[i] * neg[i];
            }
            reverse(neg.begin(),neg.end());
            return neg;
        }
        // 2 pointer jab dono positive negative hai elements
        int i=0;
        int j=0;
        int id=0;
        int n=neg.size();
        int m=pos.size();
        vector<int> res(n+m);
        for(int i=0;i<n;i++)
        neg[i]= neg[i] * neg[i];
        reverse(neg.begin(),neg.end());
        for(int i =0;i<m;i++)
        pos[i] = pos[i] * pos[i];
        while(i < n and j < m)
        {
            if(neg[i]<=pos[j])
            {
                res[id] = neg[i];
                id++;
                i++;
            }
            else
            {
                res[id] = pos[j];
                id ++;
                j++;
            }
        }
        // agar i me koi elements bach gaye
        while(i<n)
        {
            res[id]=neg[i];
            id++;
            i++;
        }
        while(j<m)
        {
            res[id]=pos[j];
            id++;
            j++;
        }
        return res;
    }
};