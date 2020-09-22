namespace MR{
    // 18λ������154590409516822759
  // 19λ������2305843009213693951 (÷ɭ����)
  // 19λ������4384957924686954497
  ll prime[6] = {2, 3, 5,7, 233, 331};
  ll mi;
  ll qmul(ll x, ll y, ll mod) { // �˷���ֹ����� ���p * p����LL�Ļ�����ֱ�ӳˣ� O(1)�˷�����ת���ɶ����Ƽӷ�
      return (x * y - (ll)(x / (long double)mod * y + 1e-3) *mod + mod) % mod;
  }
  ll qpow(ll a, ll b, ll mod) {
      ll ret = 1;
      for(;b;a=qmul(a,a,mod),b>>=1)if(b&1)ret=qmul(ret,a,mod);
      return ret;
  }
  bool M_R(ll p) {//����ֵ������0��Ϊ��������Ϊ1��Ϊ��������Χ�ɲ⵽ll��Χ
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
//ֱ�ӵ��� MR::p_r(cnt,x)�����ɰ�x�����������Ӵ����cnt��
//���� MR::M_R(x) ���ж�x�Ƿ�Ϊ������
