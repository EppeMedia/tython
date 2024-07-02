#N-body benchmark from the Computer Language Benchmarks Game.
#
#This is intended to support Unladen Swallow's pyperf.py. Accordingly, it has been
#modified from the Shootout version:
#- Accept standard Unladen Swallow benchmark options.
#- Run report_energy()/advance() in a loop.
#- Reimplement itertools.combinations() to work with older Python versions.
#
#Pulled from:
#http://benchmarksgame.alioth.debian.org/u64q/program.php?test=nbody&lang=python3&id=1
#
#Contributed by Kevin Carson.
#Modified by Tupteq, Fredrik Johansson, and Daniel Nanz.

__contact__ = "collinwinter@google.com (Collin Winter)"
DEFAULT_ITERATIONS = 1000 #20000
DEFAULT_REFERENCE = "sun"
DEFAULT_LOOPS = 100

PI = 3.14159265358979323
SOLAR_MASS = 4.0 * PI * PI
DAYS_PER_YEAR = 365.24

BODIES = {
    "sun": ([0.0, 0.0, 0.0], [0.0, 0.0, 0.0], SOLAR_MASS),

    "jupiter": ([4.84143144246472090e+00,
                 -1.16032004402742839e+00,
                 -1.03622044471123109e-01],
                [1.66007664274403694e-03 * DAYS_PER_YEAR,
                 7.69901118419740425e-03 * DAYS_PER_YEAR,
                 -6.90460016972063023e-05 * DAYS_PER_YEAR],
                9.54791938424326609e-04 * SOLAR_MASS),

    "saturn": ([8.34336671824457987e+00,
                4.12479856412430479e+00,
                -4.03523417114321381e-01],
               [-2.76742510726862411e-03 * DAYS_PER_YEAR,
                4.99852801234917238e-03 * DAYS_PER_YEAR,
                2.30417297573763929e-05 * DAYS_PER_YEAR],
               2.85885980666130812e-04 * SOLAR_MASS),

    "uranus": ([1.28943695621391310e+01,
                -1.51111514016986312e+01,
                -2.23307578892655734e-01],
               [2.96460137564761618e-03 * DAYS_PER_YEAR,
                2.37847173959480950e-03 * DAYS_PER_YEAR,
                -2.96589568540237556e-05 * DAYS_PER_YEAR],
               4.36624404335156298e-05 * SOLAR_MASS),

    "neptune": ([1.53796971148509165e+01,
                 -2.59193146099879641e+01,
                 1.79258772950371181e-01],
                [2.68067772490389322e-03 * DAYS_PER_YEAR,
                 1.62824170038242295e-03 * DAYS_PER_YEAR,
                 -9.51592254519715870e-05 * DAYS_PER_YEAR],
                5.15138902046611451e-05 * SOLAR_MASS)
}

def combinations(l):
#    """Pure-Python implementation of itertools.combinations(l, 2)."""
    result = []
    q = len(l) - 1

    for x in range(0, q, 1):
        i = x + 1
        ls = l[i:]

        for y in ls:
            result.append((l[x], y))

    return result

SYSTEM = list(BODIES.values())        # removed list constructor
PAIRS = combinations(SYSTEM)

def advance(dt, n):
    for i in range(0, n, 1):
        for p in PAIRS:

            x1 = p[0][0][0]
            y1 = p[0][0][1]
            z1 = p[0][0][2]
            v1 = p[0][1]
            m1 = p[0][2]

            x2 = p[1][0][0]
            y2 = p[1][0][1]
            z2 = p[1][0][2]
            v2 = p[1][1]
            m2 = p[1][2]

            dx = x1 - x2
            dy = y1 - y2
            dz = z1 - z2
            mag = dt * ((dx * dx + dy * dy + dz * dz) ** (-1.5))
            b1m = m1 * mag
            b2m = m2 * mag
            v1[0] -= dx * b2m
            v1[1] -= dy * b2m
            v1[2] -= dz * b2m
            v2[0] += dx * b1m
            v2[1] += dy * b1m
            v2[2] += dz * b1m

        for b in SYSTEM:

            r = b[0]
            vx = b[1][0]
            vy = b[1][1]
            vz = b[1][2]
            m = b[2]

            r[0] += dt * vx
            r[1] += dt * vy
            r[2] += dt * vz

def report_energy():

    e = 0.0

    for p in PAIRS:

        x1 = p[0][0][0]
        y1 = p[0][0][1]
        z1 = p[0][0][2]
        v1 = p[0][1]
        m1 = p[0][2]

        x2 = p[1][0][0]
        y2 = p[1][0][1]
        z2 = p[1][0][2]
        v2 = p[1][1]
        m2 = p[1][2]

        dx = x1 - x2
        dy = y1 - y2
        dz = z1 - z2
        e -= (m1 * m2) / ((dx * dx + dy * dy + dz * dz) ** 0.5)

    for b in SYSTEM:

        r = b[0]
        vx = b[1][0]
        vy = b[1][1]
        vz = b[1][2]
        m = b[2]

        e += m * (vx * vx + vy * vy + vz * vz) / 2.0

    return e


def offset_momentum(ref):

    px=0.0
    py=0.0
    pz=0.0

    for b in SYSTEM:

        r = b[0]
        vx = b[1][0]
        vy = b[1][1]
        vz = b[1][2]
        m = b[2]

        px -= vx * m
        py -= vy * m
        pz -= vz * m

    v = ref[1]
    m = ref[2]

    v[0] = px / m
    v[1] = py / m
    v[2] = pz / m


def bench_nbody(loops, reference, iterations):
    # Set up global state
    offset_momentum(BODIES[reference])

    range_it = range(0, loops, 1)

    for _ in range_it:
        e = report_energy()
#        print(e)
        advance(0.01, iterations)
        e = report_energy()
#        print(e)

##print("Let's go")
bench_nbody(DEFAULT_LOOPS, DEFAULT_REFERENCE, DEFAULT_ITERATIONS)
##print("Done")