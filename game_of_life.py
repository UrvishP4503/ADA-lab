def get_next_gen(mat):
    new_mat = [[0 for _ in range(len(mat[0]))] for _ in range(len(mat))]

    for row in range(len(mat)):
        for col in range(len(mat[0])):
            alive_neighbours = get_neighbours_count(mat, row, col)
            if mat[row][col] == 1:
                if alive_neighbours == 2 or alive_neighbours == 3:
                    new_mat[row][col] = 1
            elif mat[row][col] == 0:
                if alive_neighbours == 3:
                    new_mat[row][col] = 1

    return new_mat


def get_neighbours_count(mat, row, col) -> int:
    val = 0
    # up = row - 1
    # down = row + 1
    # left = col - 1
    # right = col + 1

    # if up >= 0:
    #     val += mat[up][col]
    # if down < len(mat):
    #     val += mat[down][col]
    # if left >= 0:
    #     val += mat[row][left]
    #     if up >= 0:
    #         val += mat[up][left]
    #     if down < len(mat):
    #         val += mat[down][left]
    # if right < len(mat[0]):
    #     val += mat[row][right]
    #     if up >= 0:
    #         val += mat[up][right]
    #     if down < len(mat):
    #         val += mat[down][right]

    for i in range(-1, 2):
        for j in range(-1, 2):
            t_row = (row + i + len(mat)) % len(mat)
            t_col = (col + j + len(mat[0])) % len(mat[0])
            val += mat[t_row][t_col]
    val -= mat[row][col]
    return val


matrix = [
    [0, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 0, 0, 0, 0],
    [0, 0, 0, 1, 1, 0, 0],
    [0, 0, 1, 1, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0],
]

print_matrix = lambda mat: print("\n".join([" ".join(map(str, row)) for row in mat]))


print_matrix(matrix)

print("Next Generation")
matrix = get_next_gen(matrix)
print_matrix(matrix)

print("Next Generation")
matrix = get_next_gen(matrix)
print_matrix(matrix)

print("Next Generation")
matrix = get_next_gen(matrix)
print_matrix(matrix)

print("Next Generation")
matrix = get_next_gen(matrix)
print_matrix(matrix)

matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
matrix = get_next_gen(matrix)
print("Next Generation")
matrix = get_next_gen(matrix)
print_matrix(matrix)
