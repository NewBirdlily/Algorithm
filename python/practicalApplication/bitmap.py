class MyBitMap:
    def __init__(self, size):
        self.size = size
        self.words = [0] * (self.getWordIndex(size-1) + 1)

    # 判断Bitmap某一位的状态
    def getBit(self, bitIndex):
        if bitIndex < 0 or bitIndex > self.size-1:
            print("超过Bitmap的有效范围")
        wordIndex = self.getWordIndex(bitIndex)
        return (self.words[wordIndex] & (1 << bitIndex)) != 0

    # 把Bitmap某一位设置为true
    def setBit(self, bitIndex):
        if bitIndex < 0 or bitIndex > self.size-1:
            print("超出Bitmap的有效范围")
        wordIndex = self.getWordIndex(bitIndex)
        self.words[wordIndex] |= (1 << bitIndex)

    # 定位Bitmap某一位所对应的word
    def getWordIndex(self, bitIndex):
        # 右移6位，相当于除以64
        return bitIndex >> 6


if __name__ == "__main__":
    bitmap = MyBitMap(128)
    bitmap.setBit(126)
    bitmap.setBit(75)
    #bitmap.setBit(130)
    print(bitmap.getBit(126))
    print(bitmap.getBit(78))
    #print(bitmap.getBit(130))

