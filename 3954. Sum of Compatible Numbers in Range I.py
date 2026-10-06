class Solution(object):

  def sumOfGoodIntegers(self, n, k):
    a = max(1, n - k)
    b = n + k
    c = 0

    for d in range(a, b + 1):
      if (n & d) == 0:
        c += d

    return c
