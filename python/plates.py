def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    l = len(s)
    p = l
    final = 0
    if 2 <= l <= 6 and s[:2].isalpha():
        for i,char in enumerate(s):
            if char.isdigit():
                if char == '0' and p > i:
                    return False
                    break
                p = i
                final += 1
            elif char.isalpha():
                if i > p:
                    return False
                    break
                final += 1
            else:
                return False
                break
    else:
        return False
    if final >= 2:
        return True


main()
