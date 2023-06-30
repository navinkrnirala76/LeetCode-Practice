class Solution {
public:
    string smallestString(string s) {
        vector<int> pos;
        int n=s.size();
        
        char c='a';
        vector<char> m(26,'#');
        for(int i=0;i<26;i++)
        {
            m[i]=c;
            c++;
        }
        if(n==1)
        {
            if(s[0]=='a')
                return "z";
            char c1=m[(s[0]-'a'-1)%26];
            string s1="";
            s1.push_back(c1);
            return s1;
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
                pos.push_back(i);
        }
        if(pos.size()==0)
        {
           for(int i=0;i<n;i++)
        {
            s[i]=m[(s[i]-'a'-1)%26];
        } 
            return s;
        }
        if(pos.size()==n)
        {
            s[n-1]='z';
            return s;
        }
        for(int i=0;i<pos[0];i++)
        {
            s[i]=m[(s[i]-'a'-1)%26];
        }
        if(pos[0]>0)
            return s;
        int sz=pos.size();
        for(int i=0;i<pos.size()-1;i++)
        {
            bool flag=false;
            for(int j=pos[i]+1;j<pos[i+1];j++)
           {
               s[j]=m[(s[j]-'a'-1)%26];
                flag=true;
           }
            if(flag)
            return s;
        }
        for(int k=pos[sz-1]+1;k<n;k++)
        {
            s[k]=m[(s[k]-'a'-1)%26];
        }
        return s;
    }
};
