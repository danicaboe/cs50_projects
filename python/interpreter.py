def main():
    equation = input('Expression: ').strip()
    # x, y, z = equation.strip(' ')
    print(float(eval(equation)))

main()