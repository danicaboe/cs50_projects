def main():
    q = input('What is the Answer to the Great Question of Life, the Universe, and Everything? ')
    print(answer(q))


def answer(i):
    s = i.lower().strip()
    match s:
        case '42' | 'forty two' | 'forty-two':
            return 'Yes'
        case _:
            return 'No'



main()