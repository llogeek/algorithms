
class Graph:

    def __init__(self, vertices):
        self.V = vertices  # No. of vertices
        self.graph = []

    # function to add an edge to graph
    def addEdge(self, u, v, w):
        self.graph.append([u, v, w])

    # utility function used to print the solution
    def printArr(self, dist):
        print("Расстояния до вершин из источника:")
        for i in range(self.V):
            print("{0}\t\t{1}".format(i, dist[i]))

    def printShortestPath(self, dist, x, indexEND, source):
        way = [indexEND + 1]
        idx = indexEND
        while x[idx] != -1:
            way.append(x[idx] + 1)
            idx = x[idx]
        print("Путь в вершину " + str(indexEND + 1) + " из вершины " + str(source + 1) + ": " +
              "->".join([str(way[l]) for l in range(len(way) - 1, -1, -1)])
              + ".Расстояние : " + str(dist[indexEND]))

    def BellmanFord(self, src):
        dist = [float("Inf")] * self.V
        dist[src] = 0
        x = [-1 for i in range(self.V)]

        for i in range(self.V - 1):
            for u, v, w in self.graph:
                if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    x[v] = u

        for u, v, w in self.graph:
            if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                print("Граф содержит контур отрицательной длины")
                return
        print("Найденные пути минимальной длины до вершин из источника: ", dist)
        print("Метки для нахождения пути:", [i+1 for i in x])
        for i in range(len(dist)):
            self.printShortestPath(dist, x, i, src)


g = Graph(10)
g.addEdge(0, 3, 2)
g.addEdge(1, 0, 6)
g.addEdge(1, 2, 2)
g.addEdge(1, 5, 8)
g.addEdge(1, 7, 7)
g.addEdge(2, 7, 2)
g.addEdge(2, 9, 2)
g.addEdge(3, 1, 3)
g.addEdge(3, 4, 3)
g.addEdge(3, 6, 2)
g.addEdge(4, 5, 6)
g.addEdge(5, 6, 2)
g.addEdge(6, 8, 1)
g.addEdge(7, 6, 1)
g.addEdge(7, 9, 2)
g.addEdge(8, 9, 5)
g.BellmanFord(1)