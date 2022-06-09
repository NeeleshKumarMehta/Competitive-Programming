class sgTree{
    public:
    vector<int>seg;
    sgTree(int n){
        seg.resize(4*n+4);
    }
    void build(int ind , int low , int high , vector<int>&a){
        if(low == high){
            seg[ind] = a[low];
            return;
        }
        int mid = low + (high - low)/2;
        build(ind*2+1,low,mid,a);
        build(ind*2+2,mid+1,high,a);
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    void update(int ind , int low , int high , int i , int val){
        if(low == high){
            seg[ind]+=val;
            return;
        }
        int mid = low + (high - low)/2;
        if(i <= mid)update(ind*2+1,low,mid,i,val);
        else update(ind*2+2,mid+1,high,i,val);
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    int query(int ind , int low , int high, int l , int r){
        if(r < low || l > high) return 0;
        if(l <= low && r >= high)return seg[ind];
        int mid = low + (high - low)/2;
        return query(ind*2+1,low,mid,l,r)+query(ind*2+2,mid+1,high,l,r);
    }
    
};
