import sys

# определяют бесконечность как максимальное значение целого числа.
inf = sys.maxsize


# Функция для запуска алгоритма Беллмана-Форда из заданного источника.
def bellmanFord(edges, source, n):
    # `cost` хранит информацию о кратчайшем пути.
    cost = [inf] * n

    # Изначально все вершины, кроме исходной, имеют вес бесконечности.
    cost[source] = 0

    # Шаг релаксации (выполнить V-1 раз)
    for _ in range(n - 1):
        # считает, что все ребра от `u` до `v` имеют вес `w`
        for (u, v, w) in edges:
            # , если стоимость до пункта назначения `u` можно сократить, взяв преимущество (u, v)
            if cost[u] != inf and cost[u] + w < cost[v]:
                # Стоимость обновления # до нового более низкого значения
                cost[v] = cost[u] + w

    # Выполните шаг релаксации еще раз в n-й раз, чтобы проверить циклы отрицательного веса.
    for (u, v, w) in edges:
        # , если стоимость до пункта назначения `u` можно сократить, взяв преимущество (u, v)
        if cost[u] != inf and cost[u] + w < cost[v]:
            print(u, v, cost[u], cost[v])
            return True

    return False


def hasNegativeWeightCycle(adjMatrix):
    # Базовый вариант
    if not adjMatrix:
        return False

    # общее количество узлов в Graph
    n = len(adjMatrix)

    # создает список для хранения ребер Graph
    edges = []

    for v in range(n):
        for u in range(n):
            if adjMatrix[v][u] and adjMatrix[v][u] != inf:
                # ребро от источника `v` до места назначения `u`, имеющее указанный вес
                edges.append((v, u, adjMatrix[v][u]))

    # Запуск алгоритма Беллмана-Форда из каждой вершины в качестве источника
    # и проверьте цикл отрицательного веса.
    for i in range(n):
        if bellmanFord(edges, i, n):
            return True

    return False


if __name__ == '__main__':

    # с учетом представления смежности матрицы
    adjMatrix = [[0, 1, inf, 3, inf, inf, inf, inf, inf],
         [-1, 0, 1, inf, 2, inf, inf, inf, inf],
         [inf, 1, 0, inf, -3, 4, inf, inf, inf],
         [3, inf, inf, 0, -3, inf, 5, inf, inf],
         [inf, 2, -3, -3, 0, 2, -2, -1, inf],
         [inf, inf, 4, inf, 2, 0, inf, inf, -3],
         [inf, inf, inf, 5, -2, inf, 0, 3, inf],
         [inf, inf, inf, inf, -1, inf, 3, 0, 4],
         [inf, inf, inf, inf, inf, -3, inf, 4, 0]]

    result = hasNegativeWeightCycle(adjMatrix)
    if result:
        print('Negative-weight cycle found')
    else:
        print('Negative-weight cycle doesn\'t exist')
