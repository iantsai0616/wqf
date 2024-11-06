struct DSU{
    vector<int>to,num;
    int cnt;
    DSU(int n = 0): to(n), num(n) {
      cnt = n;
      for(int i=0;i<n;i++){
        to[i]=i;
        num[i]=1;
      }
    }
    int find(int x){
      return x==to[x]?x:to[x]=find(to[x]);
    }
    bool un(int x, int y){
      x=find(x),y=find(y);
      if(x==y)return 0;
      cnt--;
      if(num[x]>num[y])swap(x,y);
      to[x]=y;
      num[y]+=num[x];
      return 1;
    }
};