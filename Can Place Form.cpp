class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // int f1[0];
        // int f2[0];
        // flowerbed[] = {f1,f2}; 
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        for(int i =1;i<flowerbed.size()-1;i++){
            if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                flowerbed[i]=1;
                n=n-1;
            }
        }
        return n<=0;
    }
};
