// LEETCODE 1617.Count Subtrees With Max Distance Between Cities {HARD} {BACKTRACKING} {WEEKLY CONTEST 210}

// There are n cities numbered from 1 to n. You are given an array edges of size n-1, where edges[i] = [ui, vi] represents a bidirectional edge between cities ui and vi. There exists a unique path between each pair of cities. In other words, the cities form a tree.

// A subtree is a subset of cities where every city is reachable from every other city in the subset, where the path between each pair passes through only the cities from the subset. Two subtrees are different if there is a city in one subtree that is not present in the other.

// For each d from 1 to n-1, find the number of subtrees in which the maximum distance between any two cities in the subtree is equal to d.

// Return an array of size n-1 where the dth element (1-indexed) is the number of subtrees in which the maximum distance between any two cities is equal to d.

// Notice that the distance between the two cities is the number of edges in the path between them.

// Example 1:
// Input: n = 4, edges = [[1,2],[2,3],[2,4]]
// Output: [3,4,0]
// Explanation:
// The subtrees with subsets {1,2}, {2,3} and {2,4} have a max distance of 1.
// The subtrees with subsets {1,2,3}, {1,2,4}, {2,3,4} and {1,2,3,4} have a max distance of 2.
// No subtree has two nodes where the max distance between them is 3.

// Example 2:
// Input: n = 2, edges = [[1,2]]
// Output: [1]

// Example 3:
// Input: n = 3, edges = [[1,2],[2,3]]
// Output: [2,1]

### Solution

```
int[][] dist;
public int[] countSubgraphsForEachDiameter(int n, int[][] edges) {
    //precalculate the distance of any two cities
    dist = new int[n][n];
    List<Integer>[] graph = new List[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new ArrayList();
    }
    for (int[] e : edges) {
        graph[e[0] - 1].add(e[1] - 1);
        graph[e[1] - 1].add(e[0] - 1);
    }
    for (int i = 0; i < n; i++) {
        calcDist(graph, i, -1, i, 0);
    }
    int[] res = new int[n - 1];
    for (int i = 1; i < (1 << n); i++) {
        int maxDist = 0;
        int oneDistCount = 0;
        int cities = 0;
        //find the max distance between each pair of cities
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) {
                cities++;
                for (int k = j + 1; k < n; k++) {
                    if ((i & (1 << k)) != 0) {
                        maxDist = Math.max(maxDist, dist[j][k]);
                        if (dist[j][k] == 1) {
                            oneDistCount++;
                        }
                    }
                }
            }
        }
        //x cities form a substree if and only if there are x-1 edges among these cities
        if (oneDistCount == cities - 1 && maxDist > 0) res[maxDist - 1]++;
    }
    return res;
}

public void calcDist(List<Integer>[] graph, int source, int prev, int cur, int d) {
    if (prev == cur) {
        return;
    }
    dist[source][cur] = d;
    dist[cur][source] = d;
    for (int next : graph[cur])
        if (next != prev) {
            calcDist(graph, source, cur, next, d + 1);
        }
}
```
