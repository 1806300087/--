namespace MR{
    // 18位素数：154590409516822759
  // 19位素数：2305843009213693951 (梅森素数)
  // 19位素数：4384957924686954497
  ll prime[6] = {2, 3, 5,7, 233, 331};
  ll mi;
  ll qmul(ll x, ll y, ll mod) { // 乘法防止溢出， 如果p * p不爆LL的话可以直接乘； O(1)乘法或者转化成二进制加法
      return (x * y - (ll)(x / (long double)mod * y + 1e-3) *mod + mod) % mod;
  }
  ll qpow(ll a, ll b, ll mod) {
      ll ret = 1;
      for(;b;a=qmul(a,a,mod),b>>=1)if(b&1)ret=qmul(ret,a,mod);
      return ret;
  }
  bool M_R(ll p) {//传入值，返回0即为合数，犯为1即为质数，范围可测到ll范围
      if(p==2) return 1;
      if(p<2|| !(p & 1) ) return 0;
      ll s = p - 1;
      while(! (s & 1)) s >>= 1;
      for(int i = 0; i < 6; ++i) {
          if(p == prime[i]) return 1;
          ll t = s, m = qpow(prime[i], s, p);
          while(t!= p - 1 && m != 1 && m != p - 1) {
              m = qmul(m, m, p);
              t <<= 1;
          }
          if(m != p - 1 && !(t & 1)) return 0;
      }
      return 1;
  }
  ll f(ll x,ll mod,int a)
  {
      return (qmul(x,x,mod)+a)%mod;
  }
  ll find_factorplus(ll N,int seed) {
      ll a = rand();
      ll b = a,p;
      do {
          a = f(a,N,seed);
          b = f(f(b,N,seed),N,seed);
          p = __gcd( abs( b - a ) , N);
          if( p > 1&&p<N) return p;
      } while( b != a );
      return 0;
  }
  void p_r(vector<ll> &cnt,ll x)
  {

      if((x&1)==0)
      {
        cnt.emplace_back(2);
        while((x&1)==0)x >>= 1;
      }

      if(x==1)return ;
      if(M_R(x))
      {
          cnt.push_back(x);return ;
          return ;
      }
      ll p=0;
      while(p==0){
      int seed=rand();
      p=find_factorplus(x,seed);
      }
      p_r(cnt,p);
      p_r(cnt,x/p);
  }
}
//直接调用 MR::p_r(cnt,x)，即可把x的所有质因子存放在cnt中
//调用 MR::M_R(x) 可判断x是否为质因子
