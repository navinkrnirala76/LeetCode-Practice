class Solution {
public:
    bool wordBreak(string str,vector<string>wordDict) 
    {
        unordered_map<string,bool>existsinDict;
        for(string j:wordDict)
        {
            existsinDict[j]=true;
        }
        queue<int>tocheck;
        vector<bool>alreadypushedinqueue(str.size(),false);
        bool partitionreachedend=false;
        tocheck.push(-1);
        while(!tocheck.empty())
        {
            int indexofstr=tocheck.front();
            tocheck.pop();
            if(indexofstr==(str.size()-1))
            {
                partitionreachedend=true;
                break;
            }
            string checkinDict;
            for(int i=indexofstr+1;i<str.size();i++)
            {
                checkinDict.push_back(str[i]);
                if(existsinDict[checkinDict] && !alreadypushedinqueue[i])
                {
                    tocheck.push(i);
                    alreadypushedinqueue[i]=true;
                }
            }
        }
        return partitionreachedend;
    }
};
