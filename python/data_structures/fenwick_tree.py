
class FenwickTree:
    """
    Summed array with O(log(N)) edits and O(log(N)) sums.

    Is 1-indexed internally but presents a 0-indexed interface.
    """
    def __init__(self, n):
        self.n = n
        self.arr = [0] * (n + 1)

    def add(self, i, v):
        i += 1
        while i <= self.n:
            self.arr[i] += v
            i += i & -i

    def sum_to(self, i):
        i += 1
        s = 0
        while i > 0:
            s += self.arr[i]
            i -= i & -i
        return s

    def sum_range(self, i, j):
        """
        Sums from (i, ..., j].
        """
        return self.sum_to(j) - self.sum_to(i)

