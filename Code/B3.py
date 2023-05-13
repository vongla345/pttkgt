def strassen_poly(A, B):
    n = len(A)
    if n <= 3:
        return naive_poly_mult(A, B)

    # chia đa thức A và B thành các đa thức con bằng phép chia đôi
    A0, A1 = split_poly(A)
    B0, B1 = split_poly(B)

    # tính các đa thức phụ trợ
    P0 = strassen_poly(A0, B0)
    P1 = strassen_poly(A1, B1)
    P2 = strassen_poly(add_poly(A0, A1), add_poly(B0, B1))
    P3 = strassen_poly(subtract_poly(A0, A1), add_poly(B0, B1))
    P4 = strassen_poly(add_poly(A0, A1), B1)
    P5 = strassen_poly(A0, subtract_poly(B1, B0))
    P6 = strassen_poly(A1, subtract_poly(B0, B1))

    # tính đa thức tích C
    C0 = add_poly(add_poly(P0, P1), subtract_poly(P4, P5))
    C1 = add_poly(P2, P3)
    C2 = add_poly(P4, P6)
    C = [0] * (2 * n - 1)
    for i in range(n):
        C[i] = C0[i]
        C[i + n] = C1[i]
        C[i + 2 * n] = C2[i]
    return C

def add_poly(A, B):
    return [a + b for a, b in zip(A, B)]

def subtract_poly(A, B):
    return [a - b for a, b in zip(A, B)]

def split_poly(P):
    n = len(P) // 2
    return P[:n], P[n:]

def naive_poly_mult(A, B):
    n = len(A)
    C = [0] * (2 * n - 1)
    for i in range(n):
        for j in range(n):
            C[i + j] += A[i] * B[j]
    return C
