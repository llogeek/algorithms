
V = 6
inf = float('inf')
def print_path(T, D):
    way = []
    for i in range(V):
        for j in range(V):
            k = T[i][j]
            while k != j:
                way.append(k+1)
                k = T[k][j]
            way.append(k+1)
            print("Путь из вершины " + str(i + 1) + " в вершину " + str(j + 1)
            + ": " + "->".join([str(i) for i in way]) + " Длина пути: " + str(D[i][j]))

def print_matrix(matrix, T):
    for i in range(len(matrix)):
        stroka = "\t".join([str(matrix[i][j]) for j in range(len((matrix[i])))])
        print(stroka)
    print("Матрица T:")
    for i in range(V):
        print('\t'.join([str(i + 1) for i in T[i]]))

def floyd(G):
    T = [[j for j in range(V)] for _ in range(V)]
    dist = list(map(lambda p: list(map(lambda q: q, p)), G))
    for r in range(V):
        for p in range(V):
            for q in range(V):
                prev = dist[p][q]
                dist[p][q] = min(dist[p][q], dist[p][r] + dist[r][q])
                if dist[p][q] != prev:
                    T[p][q] = T[p][r]
        print("\nD^" +str(r+1) + ": \t", print_matrix(dist, T))
    sol(dist)
    print_path(T, dist)

def sol(dist):
    print("Полученная матрица расстояний:")
    for p in range(V):
        for q in range(V):
            if dist[p][q] == inf:
                print("inf", end='\t')
            else:
                print(dist[p][q], end='\t')
        print(" ")


"""graph = [[0, 11, 2, 8, 11, 11],
         [11, 0, 5, inf, inf, 1],
         [inf, 5, 0, inf, 2, 1],
         [2, inf, inf, 0, 2, inf],
         [inf, 9, inf, 2, 0, 7],
         [inf, 1, inf, inf, 7, 0]]
"""
graph = [[0, 10, inf, inf, 3, 4],
         [10, 0, 5, inf, inf, 5],
         [inf, 5, 0, 3, inf, 3],
         [inf, inf, 3, 0,5,7],
         [3,inf, inf, 5, 0,2],
         [4, 5, 3, 7, 2, 0]]
floyd(graph)
