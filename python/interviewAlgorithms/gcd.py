class GCD:
    @staticmethod
    def gcd(a,b):
        if a==b:
            return a
        if (a&1) == 0 and (b&1) == 0:
            return GCD.gcd(a>>1, b>>1)<<1
        if (a&1) == 0 and (b&1) !=0:
            return GCD.gcd(a>>1,b)
        if (a&1) !=0 and (b&1) ==0:
            return GCD.gcd(a,b>>1)

        else:
            big =a if a >b else b
            small = a if  a<b  else b
            return GCD.gcd(big-small , small)

if __name__ =="__main__":
    print(GCD.gcd(25,5))
    print(GCD.gcd(100,80))
    print(GCD.gcd(27,14))