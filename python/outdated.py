def main():
    months = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"]

    while True:
        try:
            date = input("Date: ").strip()
            if not date[0].isnumeric():
                each = date.split(' ')
                month = str(months.index(each[0])+1)
                return print(f"{each[2]}-{month.zfill(2)}-{each[1].strip(',').zfill(2)}")
            else:
                separate = date.split("/")
                return print(f"{separate[2]}-{separate[0].zfill(2)}-{separate[1].zfill(2)}")
        except ValueError:
            pass
        except IndexError:
            pass

main()