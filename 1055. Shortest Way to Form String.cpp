/*
Time: O(m*log(m)) (m = length of target)
Space: O(n) (n = length of source)


Use binary search on each character's indices list to find the next occurance
If there's no next occurance but we can traverse back to the start, increment subsequence count
*/

class Solution {

public:

    // Function to find the minimum number of subsequences of 'source' required to form 'target'.

    int shortestWay(string s, string t) {
        vector<vector<int>> idx(26, vector<int>());
        int pos = 0;
        for(int i=0;i<s.length();i++){
            idx[s[i]-'a'].push_back(i);
        }
        
        int curr = -1;
        int ans = 1;
        for(int i=0;i<t.length();i++){
            int val = t[i] - 'a';
            if(idx[val].empty()){
                cout<<"-1"<<endl;
                return -1;
            }
            //Use binary search on each character's indices list to find the next occurance
            int pos = upper_bound(idx[val].begin(), idx[val].end(), curr) - idx[val].begin();
            
            //If there's no next occurance but we can traverse back to the start, increment subsequence count
            if(pos == idx[val].size()){
                ans++;
                curr = idx[val][0];
            }
            else{ //otherwise, just move curr to that occurance
                curr = idx[val][pos];
            }
        }
        
        cout<<ans<<endl;
        return ans;
    }

};
