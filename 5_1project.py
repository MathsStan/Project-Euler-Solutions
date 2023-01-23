from functools import reduce

def prime_factors(n):
    if n == 1:
        return []
    for i in range(2, n):
        if n % i == 0:
            break
    else:
        return [n]
    tmp_list = prime_factors(n//i)
    tmp_list.append(i)
    return tmp_list

def minimal_union(a, b):
    b = b.copy()
    c = []
    for item in a:
        if item in b:
            b.remove(item)
        c.append(item)
    return c + b
    
def smallest_multiple(upper_divisor):
    tmp = reduce(minimal_union, [prime_factors(n) for n in range(1, upper_divisor)])
    return reduce(int.__mul__, tmp)

if __name__ == "__main__":
    print(smallest_multiple(10))
    print(smallest_multiple(20))
