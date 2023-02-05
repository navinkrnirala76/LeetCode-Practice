class Solution { 
public: 
    void sortColors(vector<int>& nums) { 
        int n=nums.size(); 
        int a=0,b=0,c=0; //count number of zeroes, ones and twos 
        for(int i=0;i<n;i++) 
        { 
            if(nums[i]==0) 
            a++; 
            else if(nums[i]==1) 
            b++; 
            else 
            c++; 
        } 
        int count = 0; 
        while(a>0)//push all zeroes first 
        { 
            nums[count]=0; 
            count++; 
            a--; 
        } 
        while(b>0)//push all ones 
        { 
            nums[count]=1; 
            count++; 
            b--; 
        } 
        while(c>0)// push all 2's 
        { 
            nums[count]=2; 
            count++; 
            c--; 
        } 
    } 
};
