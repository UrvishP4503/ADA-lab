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
