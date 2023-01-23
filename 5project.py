def remove_divisors(divisor_list):
    for index, divisor in enumerate(divisor_list):
        if any([x % divisor == 0 for x in divisor_list[index+1:]]):
            divisor_list.remove(divisor)
            break
    else:
        return divisor_list
    return remove_divisors(divisor_list)

def smallest_multiple(upper_divisor):
    divisor_list = list(range(1, upper_divisor+1))
    remove_divisors(divisor_list)
    n = upper_divisor
    while True:
        for divisor in divisor_list:
            if n % divisor != 0:
                break
        else:
            return n
        n += 1

if __name__ == "__main__":
    print(smallest_multiple(10))
    print(smallest_multiple(20))

