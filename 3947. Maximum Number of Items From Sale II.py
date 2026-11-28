from functools import cmp_to_key


class Solution(object):
    def maximumSaleItems(self, a, b):
        c = max(x for x, _ in a)
        d = [0] * (c + 1)
        for x, _ in a:
            d[x] += 1

        e = [0] * (c + 1)
        for f in range(1, c + 1):
            if d[f]:
                g = 0
                for h in range(f, c + 1, f):
                    g += d[h]
                e[f] = g - 1

        i = []
        for x, y in a:
            if y > b:
                continue
            j = e[x]
            if j > 0:
                i.append((y, 2, y, 2, j))
            i.append((y, 1, y, 1, b // y))

        i.sort(
            key=cmp_to_key(
                lambda u, v: (
                    -1
                    if u[0] * v[1] < v[0] * u[1]
                    else (1 if u[0] * v[1] > v[0] * u[1] else 0)
                )
            )
        )

        k = 0
        l = b
        for _, _, m, n, o in i:
            if l < m:
                continue
            p = min(o, l // m)
            k += p * n
            l -= p * m

        return k
