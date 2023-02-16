
def main():
#     fraction = input("Fraction: ").strip()
#     print(guage(fraction))

# def guage(fraction):
    while True:
        try:
            fraction = input("Fraction: ").strip()
            x,y = fraction.split('/')
            tank = round((int(x)/int(y)) * 100)
            if 99 <= tank <= 100:
                print('F')
                break
            elif tank <= 1:
                print('E')
                break
            elif 1 < tank < 99:
                print(f'{tank}%')
                break
            else:
                pass
        except ValueError:
            pass
        except ZeroDivisionError:
            pass

main()