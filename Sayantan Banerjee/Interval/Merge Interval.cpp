// AUTHOR :- SAYANTAN BANERJEE (IIIT GWALIOR)

// https://leetcode.com/problems/merge-intervals/

bool compareInterval(vector<int> i1, vector<int> i2) 
{ 
    if(i1[0] == i2[0])
        return i1[1] < i2[1];
    
    return i1[0] < i2[0];
} 

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin() , intervals.end() , compareInterval);
        
        if(intervals.size() == 0){
            vector<vector<int>> empty;
            return empty;
        }
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        vector<vector<int>> output;
        
        for(int i = 1 ; i < intervals.size() ; i++){
            if(intervals[i][0] <= end){
                end = max(end, intervals[i][1]);
            }else{
                vector<int> current;
                current.push_back(start);
                current.push_back(end);
                output.push_back(current);
                
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        vector<int> current;
        current.push_back(start);
        current.push_back(end);
        output.push_back(current);
        
        return output;
    }
};
