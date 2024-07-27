def printMatrix(mat):
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            print(f"{mat[i][j]} ", end="")
        print()

def findDiagonalOrder(mat: list[list[int]]) -> list[int]:
    m = len(mat)    # lines
    n = len(mat[0]) # columns
    ans = []

    for lineStart in range(0, m, 1):
        i = lineStart
        j = 0
        while i >= 0 and j < n:
            print(f"({i}, {j})")
            ans.append(mat[i][j])
            i-=1
            j+=1
    
    for colStart in range(1, n, 1):
        i = m - 1
        j = colStart
        while i >= 0 and j < n:
            print(f"({i}, {j})")
            ans.append(mat[i][j])
            i-=1
            j+=1
    return ans
        

mat = [[1,2,3,4],[5,6,7,8],[8,9,10,11],[12,13,14,15]]
printMatrix(mat)
ans = findDiagonalOrder(mat)
print(ans)