/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int finder(MountainArray &moun) {
        int low = 0;
        int n = moun.length();
        int high = n - 1;
        int peak;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid == 0) 
                mid = mid + 1;
            else if (mid == n - 1) 
                mid = mid - 1;

            int val = moun.get(mid);
            int left = moun.get(mid - 1);
            int right = moun.get(mid + 1);
            if (val > right && val > left) {
                peak = mid;
                break;
            }
            else if (val > left && val < right) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return peak;
    }

    
    int bfback(int l, int h, int target, MountainArray &ma) {
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int val = ma.get(mid);

            if (val == target)
                return mid;
            else if (val < target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }

    int bfsearch(int l, int h, int target, MountainArray &ma) {
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int val = ma.get(mid);

            if (val == target)
                return mid;
            else if (val > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int indx=finder(mountainArr);
        int n=mountainArr.length();
        cout<<indx<<endl;
        if(mountainArr.get(indx)<target)return -1;
        if(mountainArr.get(indx)==target)return indx;
        int s1=bfsearch(0,indx,target,mountainArr);
        int s2=bfback(indx+1,n-1,target,mountainArr);
        if(s1==-1)return s2;
        return s1;
        
        
    }
};