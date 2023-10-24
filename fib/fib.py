from functools import cache


@cache
def fib(n):
    print(f"fib({n})")
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)


a = fib(10)
a = fib(5)
