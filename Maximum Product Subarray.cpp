class Solution {
public:
    int helper(vector<int>& nums, int start, int end, int prod){

        if(prod>0)
            return prod;

        else if(prod<0){
            if(start==end)
                return prod;
            //calculate the product after first negative number
            int i=start;
            int fprod=1;
            while(true){
                if(nums[i]<0){
                    fprod*=nums[i];
                    break;
                }

                fprod*=nums[i];
                i++;
            }
            //calculate the product before last negative number
            i=end;
            int bprod=1;
            while(true){
                if(nums[i]<0){
                    bprod*=nums[i];
                    break;
                }

                bprod*=nums[i];
                i--;
            }

            int contd1 = prod/fprod;
            int contd2 = prod/bprod;

            return contd1>contd2 ? contd1:contd2;
        }

        else {
            int i=0;
            int start=0;
            int big = INT_MIN;
            int temprod = 1;
            while(i<nums.size()){
                //for dealing with consecutive zeroes or the original array has nums[0]=0
                if(start==i && nums[i]==0){
                    start++;
                    i++;
                } 
                //Recursion call made for subarray bordered by zeroes
                else if(nums[i]==0 && start!=i){
                    int contd = helper(nums, start, i-1, temprod);
                    start = i+1;
                    temprod = 1;
                    if(contd > big)
                        big = contd;
                    i++;
                }
                //Recursion call made for subarray after the last zero
                else if(i==nums.size()-1){
                    temprod = temprod * nums[i];
                    int contd = helper(nums, start, i, temprod);
                    if(contd > big)
                        big = contd;
                    temprod = 1;
                    i++;
                } else {
                    temprod = temprod * nums[i];
                    i++;
                }
            }

            if(big<0)
                return 0;
            
            return big;
        }
    }

    int maxProduct(vector<int>& nums) {
        int prod=1;
        for(int i=0;i<nums.size();i++){
            prod*=nums[i];
        }
        return helper(nums, 0, nums.size()-1, prod);
    }
};
