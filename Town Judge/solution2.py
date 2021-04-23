def find_judge(N, trust):
    """Return judge number if judge exists
    """

    judge = -1

    # judge has indegree N-1 and outdegree 0
    possible_judges = set(range(1, N+1))
    indeg = [0] * N

    for u, v in trust:
        if u in possible_judges:
            possible_judges.remove(u)
        indeg[v-1] += 1

    # for vertices with outdegree 0
    for x in possible_judges:
        if indeg[x-1] == (N-1):
            return x

    return judge

def main():
    print(find_judge(4, [[1, 3], [1, 4], [2, 3], [2, 4], [4, 3]]))

if __name__ == "__main__":
    main()
