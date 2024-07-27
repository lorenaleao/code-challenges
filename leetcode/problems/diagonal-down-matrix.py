def printMatrix(mat):
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            print(f"{mat[i][j]} ", end="")
        print()

def findDiagonalOrder(mat: list[list[int]]) -> list[int]:
    m = len(mat)
    n = len(mat[0])
    ans = []

    for colStart in range(0, n, 1):
        i = 0
        j = colStart
        while i < m and j >= 0:
            print(f"({i}, {j})")
            ans.append(mat[i][j])
            i+=1
            j-=1
    
    for lineStart in range(1, n, 1):
        i = lineStart
        j = n - 1
        while i < m and j >= 0:
            print(f"({i}, {j})")
            ans.append(mat[i][j])
            i+=1
            j-=1
    return ans
        

mat = [[1,2,3,4],[5,6,7,8],[8,9,10,11],[12,13,14,15]]
printMatrix(mat)
ans = findDiagonalOrder(mat)
print(ans)