class Solution {
public:
    bool reportSpam(vector<string>& ms, vector<string>& b) {
        int count=0;
        map<string,int> m;
        for(auto s: b) m[s]++;
        for(auto s: ms){
            if(m[s]>0){
                count++;
            }
            if(count>=2)
            {
                return true;
            }
        }
        return false;
    }
};