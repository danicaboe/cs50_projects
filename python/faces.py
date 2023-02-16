def main():
    w_emoticon = input()
    print(convert(w_emoticon))



def convert(string):
    if ':)' in string and ':(' in string:
        x = string.replace(':)', '🙂')
        return x.replace(':(', '🙁')
    elif ':)' in string:
        return string.replace(':)', '🙂')
    elif ':(' in string:
        return string.replace(':(', '🙁')



main()