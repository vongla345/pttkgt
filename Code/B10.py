def LCS(X, Y):
    m = len(X)
    n = len(Y)
    # Tạo bảng đường chéo để lưu LCS của các cặp chuỗi con
    c = [[0] * (n + 1) for i in range(m + 1)]
    # Duyệt các phần tử của X và Y
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            # Nếu ký tự tại vị trí i của X và ký tự tại vị trí j của Y giống nhau
            if X[i - 1] == Y[j - 1]:
                c[i][j] = c[i - 1][j - 1] + 1
            # Nếu khác nhau, lấy giá trị lớn hơn của LCS(X[:i], Y[:j-1]) và LCS(X[:i-1], Y[:j])
            else:
                c[i][j] = max(c[i - 1][j], c[i][j - 1])
    # Truy vết LCS từ bảng đường chéo
    lcs = ""
    i = m
    j = n
    while i > 0 and j > 0:
        # Nếu ký tự tại vị trí i của X và ký tự tại vị trí j của Y giống nhau
        if X[i - 1] == Y[j - 1]:
            lcs = X[i - 1] + lcs
            i -= 1
            j -= 1
        # Nếu khác nhau, đi theo hướng có giá trị lớn hơn
        elif c[i - 1][j] > c[i][j - 1]:
            i -= 1
        else:
            j -= 1
    return lcs

# Kiểm tra kết quả
X = "ABCDEF"
Y = "ACDFG"
print("Chuỗi chung dài nhất của", X, "và", Y, "là:", LCS(X, Y)) # Kết quả: ACDF
