from functools import cache


def matrixChainOrder(dims: list[int]) -> int:
    @cache
    def a(i, j):
        return min(
            (a(i, k) + dims[i] * dims[k] * dims[j] + a(k, j) for k in range(i + 1, j)),
            default=0,
        )

    return a(0, len(dims) - 1)


a = matrixChainOrder([30, 35, 15, 5, 10, 20, 25])
print(a)
