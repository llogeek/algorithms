def bellman_ford(matrix, source):
    '''
    matrix: square distance matrix; the (i,j) elements is the distance between
    the source node i and the destination node j.
    source: the source node index

    It returns None if shortest path from source to all other nodes can be
    arbitrarily low (ideally tends to -inf) because of negative cycles.
    Otherwise the array of shortest distances from source to all other nodes
    is returned.
    '''

    n, inf = len(matrix), float("inf")
    v = range(n)
    l = [[matrix[0][j] for j in range(n)]]
    dist = [matrix[0][j] for j in v]
    dist[source] = 0
    for _ in range(n - 1):
        for i in v:
            vect = []
            for j in v:
                w = matrix[i][j]
                if dist[i] != inf and dist[i] + w < dist[j]:
                    dist[j] = dist[i] + w
                print(i, j, dist[i])
    for i in v:
        for j in v:
            w = matrix[i][j]
            if dist[i] != inf and dist[i] + w < dist[j]:
                return None

    return dist

source = 0
inf = float('inf')
matrix = [[0, 1, inf, 3, inf, inf, inf, inf, inf],
          [1, 0, 1,  inf, 2, inf, inf, inf, inf],
          [inf, 1, 0, inf, 3, 4, inf, inf, inf],
          [3, inf, inf, 0, 3, inf, 5, inf, inf],
          [inf, 2, 3, 3, 0, 2, 2, 1, inf],
          [inf, inf, 4, inf, 2, 0, inf, inf, -3],
          [inf, inf, inf, 5, 2, inf, 0, 3, inf],
          [inf, inf, inf, inf, 1, inf, 3, 0, 4],
          [inf, inf, inf, inf, inf, 3, inf, 4, 0]]
print(bellman_ford(matrix, source))