class IsPowerOf2:
    def isPowerOf2(self, num):
        return (num & (num - 1)) == 0

if __name__ == "__main__":
    obj = IsPowerOf2()
    print(obj.isPowerOf2(32))
    print(obj.isPowerOf2(18))