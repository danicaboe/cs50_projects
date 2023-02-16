def main():
    tweet = input("Input: ").strip()
    print(f"Output: {rm_vowels(tweet)}")

def rm_vowels(msg):
    # ok I have a few options here - I do create a string/list of vowels and do a nester for loop to compare them
    #with each characted in the string and remove them using .replace() when they are ==. Or I could do conditional stmts
    #and one for loop to check if each vowel is == to the current characted in the string and if so, replace it.
    # The conditional wouldn't be too difficult, but it might miss things.
    # Also it would be more if I had to accomodate upper and lower cases. I can't set the input to lower bc I need it to
    #output the same cases as inputted. but I could do i.lower() in the conditional to help with that need.
    #Which would be better? Lets try both!
    vowels = 'a,e,i,o,u'
    for i in vowels:
        for j in msg:
            if i == j.lower():
                msg = msg.replace(j,'')
    return msg


main()