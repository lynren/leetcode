def find_judge(N, trust):
    """Return judge number if judge exists
    """

    # res[x][0] = outdegree(x)
    # res[x][1] = indegree(x)
    res = [[0, 0] for _ in range(N)]

    for u, v in trust:
        res[u-1][0] += 1
        res[v-1][1] += 1

    judge = -1
    for count, node in enumerate(res):
        # if indegree(node) = N-1 and outdegree(node) = 0
        # then node is judge
        if node[0] == 0 and node[1] == (N-1):
            return count + 1
    
    return judge

def main():
    print(find_judge(4, [[1, 3], [1, 4], [2, 3], [2, 4], [4, 3]]))

if __name__ == "__main__":
    main()
