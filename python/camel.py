def main():
    variable = input('camelCase: ').strip()
    print(to_snake(variable))

def to_snake(camel):
    for i in camel:
        if i.isupper():
            camel = camel.replace(i, f'_{i.lower()}')
    return camel
main()