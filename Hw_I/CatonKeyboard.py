T = int(input())

while T:
    T -= 1
    str = input() + ']'
    buf = ''                    # store part of string for split operations
    splited, sorted = [], []    # split strings by '[' ']', and then sort the splited string
    
    # split the string by brackets
    for ch in str:
        if ch == '[' or ch == ']':       
            splited.append(buf)  # append part of string in buffer
            splited.append(ch)   # append the bracket
            buf = ''             # empty the buf
        else:
            buf += ch
    
    # sort the elements in the splited list
    index = 0
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