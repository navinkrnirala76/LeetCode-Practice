class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_set<int>element;
        unordered_set<int>occur;
        for(int i=0;i<arr.size();i++){
            element.insert(arr[i]);
        }
        int ac=1;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]){
                ac++;
            }
            if(arr[i]!=arr[i+1]){
                occur.insert(ac);
                ac=1;
            }
        }
        occur.insert(ac);
        if(element.size()==occur.size()){
            return true;
        }else{
            return false;
        }
    }
};
