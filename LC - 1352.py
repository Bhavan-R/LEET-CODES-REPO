class ProductOfNumbers(object):

    def __init__(self):
        self.p = [1]

    def add(self, num):
        if num == 0:
            self.p = [1]
        else:
            self.p.append(self.p[-1] * num)

    def getProduct(self, k):
        if k >= len(self.p):
            return 0
        return self.p[-1] // self.p[-1 - k]
