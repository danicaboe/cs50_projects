def main():
    mass = int(input('m: '))
    s = calculate_e(mass)
    print(f'E: {s}')


def calculate_e(mass):
    c = 300000000
    e = mass * (c**2)
    return e







main()