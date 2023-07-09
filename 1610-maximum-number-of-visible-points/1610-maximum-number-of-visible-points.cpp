class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> pa;
        int common=0;
        for(auto point:points)
        {
            if(point[0]==location[0] && point[1]==location[1])
                common++;
            else
            {
                double ang = atan2(point[1]-location[1], point[0]-location[0]) * 180.0 /M_PI;
                if(ang<0)
                    ang+=360;
                pa.push_back(ang);
            }
        }
        // in the abive snippet we calculate the angles between each of the points and the location and 
        // in the below code we are going to sort the angles and check what maximum window size we can get 
        // approach achi hai bete kya baat hai HARD krega hein
        sort(pa.begin(), pa.end());
        int n=pa.size();   
        int l = 0, ret=0;
        for(int i=0; i<n; i++)
            pa.push_back(pa[i] + 360);// this step is to ensure all values>0
        for(int r=0; r<pa.size(); r++)
        {
            while((pa[r]-pa[l])>angle)
                l++;
            ret = max(ret, r-l+1);
        }
        // the start value is basically the poitns same asthe location
        return ret + common;
    }
};