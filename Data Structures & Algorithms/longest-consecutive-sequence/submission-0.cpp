class Solution {
public:
    struct Node{
        int val = 0;
    };
    vector<Node> tree;
    int merge(int x, int y)
    {
        return max(x,y);
    }
    void build(int node, int left, int right)
    {
        if(left==right)
        {
            tree[node].val = 0;
            return;
        }
        int lnode = node*2;
        int rnode = node*2+1;
        int mid = (left+right)/2;
        build(lnode,left,mid);
        build(rnode,mid+1,right);
    }

    void update(int node, int left, int right,int idx,int val)
    {
        if(left==right)
        {
            tree[node].val = max(tree[node].val,val);
            return;
        }
        int mid = (left+right)/2;

        if(idx<=mid)
            update(node*2,left,mid,idx,val);
        else
            update(node*2+1,mid+1,right,idx,val);

        tree[node].val=max(tree[node*2].val,
                       tree[node*2+1].val);
    }
    int query(int node, int left, int right, int l, int r)
    {
        if(left>r or right<l)
            return 0;
        if(l<=left and r>=right)
            return tree[node].val;
        int mid = (left+right)/2;
        int val1 = query(node*2,left,mid,l,r);
        int val2 = query(node*2+1, mid+1, right, l, r);
        return max(val1,val2);

    }
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        long long cur = -1e10;
        long long res = 0, cnt =0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]== cur+1)
            {
                cnt++;
            }
            else if(nums[i]>cur)
            {
                cnt = 1;
            }
            res = max(res,cnt);
            cur = nums[i];
        }
        return res;
        // int cnt = 1;
        // map<int,int>mp;
        // vector<int>v;
        // v = nums;
        // sort(v.begin(),v.end());
        // for(int i = 0;i<v.size();i++)
        // {
        //     if(!mp[v[i]])
        //         mp[v[i]]=cnt++;
        // }

        // for(int i = 0;i<nums.size();i++)
        // {
        //     nums[i] = mp[nums[i]];
        // }

        // tree.resize(cnt*4+10);
        // build(1,1,cnt);
        // int res = 0;
        // for(int i = 0;i<nums.size();i++)
        // {
        //     int p = nums[i];
        //     int cur = query(1,1,cnt,1,p-1)+1;
        //     update(1,1,cnt,p,cur);

        //     res = max(res,cur);
        // }

        // return res;

    }
};
