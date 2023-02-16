def main():
    amount_due = 50
    change_owed = 0
    while amount_due > 0:
        print(f"Amount Due: {amount_due}")
        coin = int(input("Insert Coin: "))
        match coin:
            case 5 | 10 | 25:
                amount_due -= coin
            case _:
                continue
        if amount_due <= 0:
            change_owed = abs(amount_due)
    print(f"Change Owed: {change_owed}")


main()