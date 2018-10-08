def two_sum(targetNum, ary):
    foundNum = set()
    for num in ary:
        targetValue = targetNum - num
        if targetValue in foundNum:
            print(targetValue + " + " + num + " = " targetNum)
            return
        foundNum.add(num)
    return

