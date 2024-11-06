struct BIT {
  int bit[mxn+1], n;
  int lb(int x) { return x & -x; }
  void init(int _n) {
    n=_n;
    for (int i=0;i<=n;i++) {
      bit[i]=0;
    }
  }
  void modify(int x,int v) {
    for(;x;x+=lb(x))bit[x]+=v;
  }
  int query(int x) {
    int r=0;
    for(;x;x-=lb(x))
      r+=bit[x];
    return r;
  }
};