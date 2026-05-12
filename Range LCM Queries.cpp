#define ll long long
class Solution {
  public:
  vector<ll>st;
  
  ll lc(ll x, ll y){
      ll gc= gcd(x,y);
      return 1ll*x*(y/gc);
  }
  
  void build(int idx , int lef, int rig, vector<int>&arr){
      if(lef==rig){
          st[idx]=arr[lef];
          return;
      }
      int mid= (lef+rig)>>1;
      build(2*idx+1,lef,mid,arr);
      build(2*idx+2,mid+1,rig,arr);
      st[idx]= lc(st[2*idx+1],st[2*idx+2]);
      return;
  }
  
  void update(int idx, int lef, int rig, int i, int val){
      if(lef==rig){
          st[idx]=val;
          return;
      }
      int mid= (lef+rig)>>1;
      if(i<=mid) update(2*idx+1,lef,mid,i,val);
      else update(2*idx+2,mid+1,rig,i,val);
      st[idx]= lc(st[2*idx+1],st[2*idx+2]);
      return; 
  }
  
  ll query(int idx, int lef, int rig, int l, int r){
    //   if(lef>rig) return 1;
    //   if(lef==rig) return st[idx];
      if(lef==l and rig==r) return st[idx];
      int mid= (lef+rig)>>1;
      
      if(r<=mid) return query(2*idx+1,lef,mid,l,r);
      if((mid+1)<=l) return query(2*idx+2,mid+1,rig,l,r);
      
      ll left= query(2*idx+1,lef,mid,l,mid);
      ll rigt= query(2*idx+2,mid+1,rig,mid+1,r);
      return lc(left,rigt);
  }
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &q) {
        // code here
        
        int n= arr.size();
        st.resize(4*n);
        vector<ll>ans;
        build(0,0,n-1,arr);
        for(auto &it:q){
            if(it[0]==1){
                update(0,0,n-1,it[1],it[2]);
            }
            else{
                ll x= query(0,0,n-1,it[1],it[2]);
                ans.push_back(x);
            }
        }
        return ans;
    
    }
};
