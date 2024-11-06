struct segmenttree {
  vector<int> seg, tag;
  int l,r;
  segmenttree(int n = 0) : seg(4 * n), tag(4 * n){}
  void push(int id){
    seg[id*2]+=tag[id];
    seg[id*2+1]+=tag[id];
    tag[id*2]+=tag[id];
    tag[id*2+1]+=tag[id];
    tag[id]=0;
  }
  void pull(int id){
    seg[id]=max(seg[id*2],seg[id*2+1]);
  }
  void build(int l, int r, int id) {
    if(l == r)return;
    int mm=l+r>>1;
    build(l,mm,id*2);
    build(mm+1,r,id*2+1);
    pull(id);
  }
  void s_modify(
    int l,int r,int id,int ql,int qr,int x) {
    if (qr<l || r<ql) return;
    if (ql <= l && r <= qr)
      return seg[id]+=x,tag[id]+=x,void();
    push(id);
    int mm=l+r>>1;
    s_modify(l,mm,id*2,ql,qr,x);
    s_modify(mm+1,r,id*2+1,ql,qr,x);
    pull(id);
  }
  int s_query(
    int l,int r,int id,int ql,int qr) {
    push(id);
    if(ql<=l and r<=qr)return seg[id];
    int mm=l+r>>1;
    if(qr<=mm)return s_query(l,mm,id*2,ql,qr);
    if(ql>mm)return s_query(mm+1,r,id*2+1,ql,qr);
    return max(s_query(l,mm,id*2,ql,mm),
    s_query(mm+1,r,id*2+1,mm+1,qr));
  }
  void init(int L, int R) {
    l=L,r=R;
    build(l,r,1);
  }
  void modify(int ql, int qr, int x) {
    s_modify(l,r,1,ql,qr,x);
  }
  int query(int ql, int qr) {
    return s_query(l,r,1,ql,qr);
  }
};