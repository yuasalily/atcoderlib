//mod付きa^n
long long int modpow(long long int a,long long int n,long long int mod);
//mod付きnCk
long long int modcomb(long long n, long long k, long long int mod);

long long int modpow(long long int a,long long int n,long long int mod){
    long long int x = 1,a = 2;

    while (n){
        if (n & 1){
            x = (x % mod) * (a % mod);
        }
        n >>= 1;
        a = (a % mod) * (a % mod);
    }
    return x;
}

long long int modcomb(long long n, long long k, long long int mod){
    long long ans = 1;
    for (long long int i = 0;i < k;i++){
        ans = (ans * (n-i) % mod ) * modpow(i+1,mod-2,mod) % mod;
    }
    return ans;
}