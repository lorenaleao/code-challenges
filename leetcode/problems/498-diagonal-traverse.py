def printMatrix(mat):
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            print(f"{mat[i][j]} ", end="")
        print()

def findDiagonalOrderUp(mat: list[list[int]], i: int, j: int) -> tuple[list[int], int, int]:
    n = len(mat[0]) # columns
    ans = []

    while i >= 0 and j < n:
        print(f"u: ({i}, {j})")
        ans.append(mat[i][j])
        i-=1
        j+=1
    
    return ans, i, j

def findDiagonalOrderDown(mat: list[list[int]], i: int, j: int) -> list[int]:
    m = len(mat) # lines
    ans = []

    while i < m and j >= 0:
        print(f"d: ({i}, {j})")
        ans.append(mat[i][j])
        i+=1
        j-=1
    
    return ans, i, j

def findDiagonalOrder(mat: list[list[int]]) -> list[int]:
    m = len(mat)    # lines
    n = len(mat[0]) # columns
    ans = []

    i = 0
    j = 0 

    k = 0
    diagonals = n+m-1
    print(diagonals)
    while k < diagonals/2:
        up, i, j = findDiagonalOrderUp(mat, i, j)
        print(f"au: ({i}, {j})")
        ans += up

        if i == m-2 and j == n:
            print(f"break: ({i}, {j})")
            break

        if j >= n: 
            j-=1
            i+=2
        elif i < 0: i+=1
        
        down, i, j = findDiagonalOrderDown(mat, i, j)
        print(f"ad: ({i}, {j})")
        ans += down
        if i >= m: 
            i-=1
            j+=2
        elif j < 0: j+=1

        k+=1
    
    
    return ans
        

mat = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
mat=[[1,2,3],[4,5,6],[7,8,9]]
#mat=[[2,3]]
mat=[[2]]
#printMatrix(mat)
ans = findDiagonalOrder(mat)
print(ans)