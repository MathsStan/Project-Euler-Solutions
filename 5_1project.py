from functools import reduce

def prime_factors(n):
    if n == 1:
        return []
    for i in range(2, n):
        if n % i == 0:
            break
    else: #If no number >2 but <n divides n
        return [n]
    tmp_list = prime_factors(n//i)
    tmp_list.append(i)
    return tmp_list

def minimal_union(a, b): 
    """
    Union like operation between lists.
    
    Returns list of least elements which contains both input lists as "sublists" (with respect to repetition, but not order.)

    e.g.
    [1,2,2] , [2,2,3] -> [1,2,2,3]
    [1,2,2] , [2,1]   -> [1,2,2]
    """
    b = b.copy()
    c = []
    for item in a:
        if item in b:
            b.remove(item)
        c.append(item)
    return c + b
    
def smallest_multiple(upper_divisor):
    tmp = reduce(minimal_union, [prime_factors(n) for n in range(1, upper_divisor)]) #Acts as a fold from functional programming.
    return reduce(int.__mul__, tmp) #could use lambda here.

if __name__ == "__main__":
    print(smallest_multiple(10))
    print(smallest_multiple(20))
