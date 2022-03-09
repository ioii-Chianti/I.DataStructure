T = int(input())
Input = []

for i in range(T):
    Input.append(input())

for str in Input:
    str += ']'
    buf = ''        # for split operations
    splited = []    # splitted strings by '[' ']'
    sorted = []     # sort the splited string
    
    # split the string based on brackets
    for ch in str:
        if ch == '[' or ch == ']':
            if buf != '':            # ignore brackets at the beginning
                splited.append(buf)
                splited.append(ch)
                buf = ''             # empty the buffer for new splited parts
        else:
            buf += ch
    
    index = 0
    #traversing the operations along with the strings excluding the added operation
    while index < (len(splited) - 1):
        # [ : insert the string at 0-th 
        if splited[index] == '[':
            sorted.insert(0, splited[index + 1])
            index += 1
        # ] : append the string at end
        elif (splited[index] == ']'):
            sorted.append(splited[index + 1])
            index += 1
        # add the string directly
        else:
            sorted.append(splited[index])
        index += 1


    print(''.join(sorted))