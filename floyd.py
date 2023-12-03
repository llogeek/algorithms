
V = 6
inf = float('inf')
def floydWarshall(graph):
    dist = list(map(lambda i: list(map(lambda j: j, i)), graph))
    for k in range(V):
        for i in range(V):
            for j in range(V):
                dist[i][j] = min(dist[i][j],
                                 dist[i][k] + dist[k][j]
                                 )
    printSolution(dist)
def printSolution(dist):
    print("Полученная матрица расстояний")
    for i in range(V):
        for j in range(V):
            if dist[i][j] == inf:
                print("%7s" % ("inf"), end=" ")
            else:
                print("%7d\t" % (dist[i][j]), end=' ')
            if j == V - 1:
                print()
if __name__ == "__main__":
    graph = [[0, 11, 2, 8, 11, 11],
         [11, 0, 5, inf, inf, 1],
         [inf, 5, 0, inf, 2, 1],
         [2, inf, inf, 0, 2, inf],
         [inf, 9, inf, 2, 0, 7],
         [inf, 1, inf, inf, 7, 0]]
    floydWarshall(graph)