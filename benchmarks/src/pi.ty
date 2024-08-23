# Adapted from https://crypto.stanford.edu/pbc/notes/pi/code.html

LIMIT = 2800

def bench(limit):

    for k in range(0, 100):

        r = []; # len(r) will be limit + 1
        i = 0
        b = 0
        c = 0

        for _ in range(0, limit):
            r.append(2000)

        r.append(0)

        result = []

        for k in range(limit, 0, -14):

            d = 0
            i = k

            while True:

                d += r[i] * 10000
                b = 2 * i - 1

                r[i] = d % b
                d = d / b
                i -= 1

                if (i == 0):
                    break

                d = d * i

            result.append(c + d / 10000)
            c = d % 10000

bench(LIMIT)
