class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>s;
        string x;
        for(int i=0;i<emails.size();i++)
        {
            x="";
            for(int j=0;j<emails[i].length();)
            {
                if(emails[i][j]=='+')
                {
                    while(emails[i][j]!='@')
                    {
                       j++;
                    }
                    while(j<emails[i].length())
                    {
                        x+=emails[i][j];
                        j++;
                    }
                }
                else if(emails[i][j]=='@')
                {
                    while(j<emails[i].length())
                    {
                        x+=emails[i][j];
                        j++;
                    }
                }
                else
                {
                    if(emails[i][j]=='.')
                    {
                        j++;
                        continue;
                    }
                    x+=emails[i][j];
                    
                }
                j++;

            }
            
            s.insert(x);
        }
        return s.size();
    }
};
