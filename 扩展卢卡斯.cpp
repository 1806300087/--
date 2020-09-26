namespace Exlucss{
  inline ll qpow(ll a,ll b,ll p) { ll ret=1; a%=p;
    for(;b;b>>=1,(a*=a)%=p) if(b&1) (ret*=a)%=p; return ret;
  }
  inline void exgcd(ll a,ll b,ll& x,ll& y) {
    if(!b) {x=1,y=0; return ;}
    exgcd(b,a%b,y,x),y-=a/b*x;
  }
  inline ll Inv(ll n,ll p) {
    ll x,y; exgcd(n,p,x,y); return (x%p+p)%p;
  }
  inline ll fac(ll n,int pi,int pk) {
    if(!n) return 1; ll ans=1;
    for(int i=2;i<pk;++i) if(i%pi) ans=ans*i%pk;//ѭ����
    ans=qpow(ans,n/pk,pk); //�����ݣ���ѭ���ڵĸ���
    for(int i=2;i<=n%pk;++i) if(i%pi) ans=ans*i%pk;//��������ɢ��
    return ans*fac(n/pi,pi,pk)%pk; //�ݹ����
  }
  inline ll L(ll n,ll m,int pi,int pk) {
    int ind=0; for(ll i=n;i;i/=pi) ind+=i/pi;
    for(ll i=m;i;i/=pi) ind-=i/pi;
    for(ll i=n-m;i;i/=pi) ind-=i/pi;
    ll N=fac(n,pi,pk),M=fac(m,pi,pk),N_M=fac(n-m,pi,pk);//�ֱ���ÿ���׳��޳���pi�Ľ��
    return N*Inv(M,pk)%pk*Inv(N_M,pk)%pk*qpow(pi,ind,pk)%pk;
  }
  inline ll solve(ll n,ll m,ll p) { ll tmp=p,ans=0;
    for(ll i=2;i*i<=tmp;++i) if(tmp%i==0) {
        ll pk=1; while(tmp%i==0) pk*=i,tmp/=i;
        ans=(ans+L(n,m,i,pk)*Inv(p/pk,pk)%p*p/pk%p)%p; //��P������������ֽⲢ��CRT�ϲ���
    } if(tmp>1) ans=(ans+L(n,m,tmp,tmp)*Inv(p/tmp,tmp)%p*p/tmp%p)%p;
    return ans;
  }
}
//Exlucss::solve(n,m,p);����C(n,m)%p,p��Ҫ�����������Ӷ���p~plogp֮��
//Exlucss::fac(n,pi,pk);���ص���(n!/(n!������pi����))%pk,(pk=pi^a,pi������)
//Exlucss::L(n,m,pi,pk);���ص���C(n,m)%pk,(pk=pi^a,pi������,a��һ������)

