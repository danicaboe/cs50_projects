def main():
    groceries = {}
    while True:
        try:
            item = input().upper().strip()
            groceries[item] += 1
        except EOFError:
            sort = sorted(groceries.items())
            for each in sort:
                print(each[1], each[0])
            break
        except KeyError:
            groceries[item] = 1

main()