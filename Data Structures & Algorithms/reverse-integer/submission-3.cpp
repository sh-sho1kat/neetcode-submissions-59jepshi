class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        bool flag = false;
        if(s[0]=='-')
            flag = true;

        std::reverse(s.begin(),s.end());
        if(flag)
            s.pop_back();
        cout<<s<<endl;
        long long p = stoll(s);
        if(p >= (1LL<<31))
            p = 0;
        if(flag)
            p*=-1;
        cout<<p<<endl;
        return p;
    }
};
