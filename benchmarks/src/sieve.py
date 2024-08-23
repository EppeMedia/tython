# Adapted from https://www.geeksforgeeks.org/python-program-for-sieve-of-eratosthenes/

def SieveOfEratosthenes(num):

    prime = []
    for i in range(0, num+1):
        prime.append(True)

    p = 2
    while (p * p <= num):

        if (prime[p] == True):
            for i in range(p * p, num+1, p):
                prime[i] = False
        p += 1

    count = 0
    for p in range(2, num+1):
        if prime[p]:
            count += 1

    print("count: " + str(count))

SieveOfEratosthenes(30000000)
