/*
Time: O(n)
Space: O(1)

if we can't do it with neither of the first domino's top and bottom
we can't do it at all
so check only for these two values

For each of these 2 values,
    count how many dominos have the value only on top, only on botto, and both top+bottom
    these 3 counts must equal to n
    if they do, we need to flip the minimum of only_top/only_bottom counts   
*/
class Solution {
public:
    const int inf = 1e9;

    int can(vector<int>& tops, vector<int>& bottoms, int val){
        int n = tops.size();
        int only_top = 0, only_bottom = 0, both = 0;

        for(int i=0;i<tops.size();i++){
            if(tops[i] == bottoms[i] && tops[i] == val){
                both++; //both sides have value = val
            }
            else if(tops[i] == val){
                only_top++;
            }
            else if(bottoms[i] == val){
                only_bottom++;
            }
        }

        // < n means we can't flip and make all dominos have same side
        if(only_top + only_bottom + both != n)  return inf;

        // = n means we can
        // we need to flip either only_top sides or only_bottom sides -> we choose the minimum
        return min(only_top, only_bottom);
    }


    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        //if we can't do it with neither of the first domino's top and bottom
        //we can't do it at all
        //so check only for these two values 
        int op1 = can(tops,bottoms,tops[0]);
        int op2 = can(tops,bottoms,bottoms[0]);

        int ans = min(op1,op2);
        if(ans == inf)  return -1;
        return ans;
    }
};
