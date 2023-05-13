def horner(A, x0):
    result = A[0]
    for i in range(1, len(A)):
        result = result * x0 + A[i]
    return result
    
A = [2, -3, 4, -5]
x0 = 2
result = horner(A, x0)
print(result)  
