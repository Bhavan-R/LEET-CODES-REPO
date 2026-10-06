class Solution(object):

  def fib(self, n):
    if n <= 1:
      return n

    prev_a = 0
    prev_b = 1

    for step in range(2, n + 1):
      current_val = prev_a + prev_b
      prev_a = prev_b
      prev_b = current_val

    return prev_b
