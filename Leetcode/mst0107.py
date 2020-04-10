class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        matrix2 = []
        for i in range(n):
            matrix2.append([])
        for i in range(n-1, -1, -1):
            for j in range(n):
                matrix2[j].append(matrix[i][j])

        matrix[:] = matrix2[:]
