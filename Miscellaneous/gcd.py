a = int(input('first no.: '))
b = int(input('second no.: '))
while b > 1:
    R = a % b
    a = b
    b = R
if b == 0:
    print(a)
else:
    print(b)
