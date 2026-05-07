class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();

        vector<int>res(m+n+5,0);

        string result;

        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        int pos =0;
        
        for(int i = 0;i<n;i++)
        {
            int k = pos;
            int rem =0;
            for(int j =0 ;j<m;j++)
            {
                int v1 = num1[j]-'0';
                int v2 = num2[i]-'0';

                int fact = v1*v2;
                fact += res[k];
                fact+=rem;
                res[k] = fact%10;
                rem = fact/10;
                k++;
            }
            pos++;
            res[k] = rem;
        }
        for(int i = 0;i<m+n;i++)
            result.push_back(res[i]+'0');
        int p = result.size();
        int cnt =0;
        for(int i = 0;i<p;i++)
        if(result[i]=='0')
            cnt++;
        if(cnt==p)
            return "0";
        if(result[result.size()-1]=='0')
            result.pop_back();
        reverse(result.begin(),result.end());
        
        return result;
    }
};
