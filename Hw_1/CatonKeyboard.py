T = int(input())
Input = []

while T:
    string = input()
    string += ']'
    strNew, strBuf = [], []
    exHead = False

    for ch in string:
        if 'a' <= ch <= 'z':
            strBuf.append(ch)
        else:
            if exHead:
                strBuf.extend(strNew)
                strNew = strBuf
                strBuf = []
            elif not exHead:
                strNew.extend(strBuf)
                strBuf = []
            exHead = True if ch == '[' else False

    if exHead:
                strBuf.extend(strNew)
                strNew = strBuf
                strBuf = []
    elif not exHead:
        strNew.extend(strBuf)
        strBuf = []

    print("".join(strNew))
    T -= 1