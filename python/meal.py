def main():
    time_now = input('What time is it? ').strip()
    num = convert(time_now)
    if 7.0 <= num <= 8.0:
        print('breakfast time')
    elif 12.0 <= num <= 13.0:
        print('lunch time')
    elif 18.0 <= num <= 19.0:
        print('dinner time')
    pass


def convert(time):
    h, m = time.split(":")
    return float(int(h) + (int(m)/60))


if __name__ == "__main__":
    main()