import sys
import copy

def enter_adjacency_matrix(x):
    print("-" * (vertex + 13))
    for i in range(vertex):
        if i == 0 and vertex != 1:
            k = "Point    " + str(i + 1)
        else:
            if i == 0 and vertex == 1:
                k = "Point   " + str(i + 1) + "\n"
            else:
                if i + 1 == vertex:
                    k = " " + str(i + 1) + "\n"
                else:
                    k = " " + str(i + 1)
        sys.stdout.write(k)
    for i in range(vertex):
        while True:
            try:
                print("X(", i + 1, ") | ", end='')
                x[i] = [int(j) for j in input().strip().split(" ")]
                if len(x[i]) > vertex or sum(x[i]) > vertex + 1 or x[i].count(2) > 1 or (
                        x[i].count(2) == 1 and x[i].index(2) != i) or x[i].count(-1) == 1:
                    print("You have something errors, check it and enter this line again")
                else:
                    break
            except:
                print("You have something errors, check it and enter this line again")
    print("-" * (vertex + 13))
    if vertex == 2:
        if (x[0] != x[1]):
            print("You have something errors, check it and enter matrix again")
            enter_adjacency_matrix(x)
        else:
            if sum(x[0]) == 2 and sum(x[0]) == sum(x[1]):
                print("You have something errors, check it and enter matrix again")
                enter_adjacency_matrix(x)
    else:
        for i in range(vertex):
            if sum(x[i]) == 2 and x[i].count(2) == 1 and x[i][i] != 2:
                print("You have something errors, check it and enter matrix again")
                enter_adjacency_matrix(x)
def enter_weight(x):
    for i in range(vertex):
        for l in range(vertex):
            if ( amarray[i][l] == 1):
                print("Enter the weight with",i+1," --> ",l+1,": ", end='')
                x[i][l] = input()
                while True:
                    if not x[i][l].isdigit():
                        print("Pls enter the number without fractional part and positive! Try again: ")
                        x[i][l] = input()
                    else:
                        break
                x[i][l] = int(x[i][l])
def find_short_way(x):
    visited = []
    checked = [1]
    while True:
        for i in range(vertex):
            if amarray[checked[0] - 1][i] == 1:
                if (i + 1 not in visited and i + 1 not in checked):
                    checked.append(i + 1)
                if (short_way[i] - short_way[checked[0]-1] > weight[checked[0]-1][i]):
                    short_way[i] = short_way[checked[0]-1] + weight[checked[0]-1][i]
            if i == vertex - 1:
                visited.append(checked[0])
                del checked[0]
        if len(visited) == vertex:
            break
def find_minimal_way():
    count = 0
    way = [1]
    checked = [1]
    while True:
        for i in range(vertex):
            count = i
            if amarray[checked[-1] - 1][i] == 1:
                if (short_way[i] - short_way[checked[-1] - 1] == weight[checked[-1] - 1][i]):
                    amarray[checked[-1] - 1][i] = 0
                    checked.append(i + 1)
                    way.append(i + 1)
                    amarray[i] = list(static[i])
                    break
                else:
                    if (short_way[i] - short_way[checked[-1] - 1] != weight[checked[-1] - 1][i]):
                        amarray[checked[-1] - 1][i] = 0
        if checked[-1] == vertex:
            for i in range(len(way)):
                if i == len(way)-1:
                    print(way[i])
                else:
                    print(way[i], end=' --> ')
        if count == vertex - 1:
            del checked[-1]
            del way[-1]
        if len(checked) == 1 and sum(amarray[0]) == 0:
            break

amarray = []
weight = []
plot = 0
vertex = 0
while True:
  if plot == 0:
    vertex = input("Enter the number of vertex: ")
    while True:
        if not vertex.isdigit():
            print("Pls enter the number without fractional part and positive! Try again: ")
            vertex = input()
        else:
            if int(vertex) == 0:
                print("Vertex zero? Seriosly? Man enter something more 0")
                vertex = input()
            else:
                plot = 1
                vertex = int(vertex)
                break
  else:
    break
amarray = [[0]* vertex for i in range(vertex)]
weight = [[0]* vertex for i in range(vertex)]
print("Enter the matrix by this example: \n"
              "----------\n"
              "1 0 0 0 2 \n"
              "0 0 1 0 1 \n"
              "0 1 0 0 0 \n"
              "0 0 0 1 0 \n"
              "---------- ")
enter_adjacency_matrix(amarray)
enter_weight(weight)
short_way = [(max(max(weight))*vertex)] * vertex
short_way[0] = 0
find_short_way(short_way)
print("\nThe short way is: ",short_way[-1])
static = copy.deepcopy(amarray)
print("\nThe shortest paths: ")
find_minimal_way()