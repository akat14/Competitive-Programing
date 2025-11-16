struct MOD
{
  const static long long mod = 998244353;
  long long value;
  MOD(long long v) { value = v; }
  MOD() { value = 0; }
  MOD operator+(const MOD &x)
  {
    long long curr = value + x.value;
    if(curr >= mod) curr -= mod;
    return MOD(curr);
  }
  MOD operator+=(const MOD &x)
  {
    value += x.value;
    if(value >= mod) value -= mod;
    return *this;
  }
  MOD operator-(const MOD &x)
  {
    long long curr = value - x.value;
    if(curr < 0) curr += mod;
    return curr;
  }
  MOD operator*(const MOD &x) { return MOD((value * x.value) % mod); }
};
