## Built-in Functions

- **builtin_popcount(x)/**builtin_popcountll(x) = count of set bits
- \_\_builtin_clz(x) = count of leading zeroes {x is unsigned int}
- \_\_builtin_ctz(x) = count of trailing zeroes
- bitset<32>(x).to_string() = binary representation

## Tricky manipulations

- rightmost set bit = log2(n&-n)
- leftmost set bit = log2(n)
- rightmost unset bit = log2(n^(n|(n+1)))
- set $i_{th}$ bit $\rightarrow$ a|=(1<<i)
- unset $i_{th}$ bit $\rightarrow$ a&=(~(1<<i))
- flip $i_{th}$ bit $\rightarrow$ a^=(1<<i)
- unset rightmost set bit $\rightarrow$ n&=(n-1);
- whether $i_{th}$ bit is set $\rightarrow$ n&(1<<i)
- n!=0 && n&(n-1)==0 $\rightarrow$ n=$2^k$
- add 1 $\rightarrow$ flip all the bits from the rightmost unset-bit
- subtract 1 $\rightarrow$ flip all the bits from the rightmost set-bit

a + b = a^b + 2(a&b) = a|b + a&b

2-s complement of a = ~a+1 = -a
~a = -(a+1) is a$\rightarrow$'signed int'

Efficient modulo: n%(2^i) = n&(2^i-1)

a%2 is equivalent to a&1
a\*=2 is eqivalent to a<<=1;
a/=2 is eqivalent to a>>=1
N with all k-bits set = (1<<k)-1
Lower to upper case $\rightarrow$ ch&='_'
Upper to lower case $\rightarrow$ ch|=' '
clear all bits till $i_{th}$ bit $\rightarrow$ x&=((1<<i)-1)
clear all bits from $i_{th}$ bit $\rightarrow$ x&=~((1<<(i+1))-1)

XOR([1...n]) = 
- n if n=4k
- 1 if n=4k+1
- n+1 if n=4k+2
- 0 if n=4k+3

pre-compute $log_2$
```
log2[1] = 0
for i=2 to n
    log2[i] = log2[i/2]+1
```

to make n nearest power of 2
- `while(__builtin_popcount(n)!=1) n++;`
- `while((n&(n-1))!=0) n++;`

```
int count_setbits(x){
    cnt=0;
    while(x)
        x&=(x-1), cnt++;
    return cnt;
}
```

```
void swap(int &a, int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}
```

## Multiplication using bitwise Operations (Russian peasant algorithm)

- $a*b = a*(2*(b/2)+b\&1) = (2*a)*(b/2)+a*(b\&1)$

```

res = 0
while b > 0
if b&1 then res += a
a <<= 1
b >>= 1

```

## Division using bitwise operations

- shift B towards the left and check if it is less than or equal to A
- If it is, we subtract it from A and add the value of 2^i to Q

```

for i = 31 upto 0
if(B<<i <= A){
A-=(B<<i)
Q|=(1<<i)
}

```

## BITSET

- like array of bool but optimizes space: each bool takes 1 bit space only
- size has to be known at the compile time (i.e. `constexpr`)
- Constructor: bitset<8> bs; bitset<32> bs(n); bitset<12> bs(bin_str);
- Access Operator[]: $bs[i] \rightarrow i_{th}$ bit from right
- Operations: ==, !=, &, |, ^, ~, >>, <<, &=, |=, ^=, ~=, >>=, <<=
- Conversion: bs.to_string(), bs.to_ulong(), bs.to_ullong()
- Functions:
- bs.size() => #bits
- bs.count() => #set_bits
- bs.set() => sets_all_bits
- bs.reset() => resets_all_bits
- bs.flip() => flips_all_bits
- bs.any(), bs.none(), bs.all()

## Tricky Questions

- Given an array in which all numbers except two are repeated once. Find them.
- Given an array where every element occurs three times, except one element which occurs only once. Find it.
- Detect if two integers have opposite signs.
- Given a number x and two positions (from the right side), write a function that swaps n bits at the given two positions.

```

```
