// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        unsigned int s=1;
        unsigned int e=n;
        unsigned int mid=(s+e)/2;
        while(s<=e)
        {
            mid=(s+e)/2;
            if(isBadVersion(mid)==true && isBadVersion(mid-1)==false)
                return mid;
            if(isBadVersion(mid)==true)
                e=mid-1;
            else
                s=mid+1;
        }
        return mid;
        
    }
};
