// https://leetcode.com/problems/satisfiability-of-equality-equations/

/*

Solution Approach :
Using DSU. Initialize all the variables in all the equations, their parents as themselves, 
their rank as 1. Perform union operation for all the equality eqautions. Once unified, 
check for all inequality equations if in any equation the variables involved have the 
same parent then all equations cannot be simultaneously true.

*/

#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    unordered_map<char, char> parent;
    unordered_map<char, int> rank;

public:
    DSU(vector<string> &equations)
    {
        for (auto eq : equations)
        {
            if (parent.find(eq[0]) == parent.end())
            {
                parent[eq[0]] = eq[0];
                rank[eq[0]] = 1;
            }
            if (parent.find(eq[3]) == parent.end())
            {
                parent[eq[3]] = eq[3];
                rank[eq[3]] = 1;
            }
        }

        for (auto eq : equations)
        {
            if (eq[1] == '=')
            {
                unionByRank(eq[0], eq[3]);
            }
        }
    }

    char find(char var)
    {
        if (parent[var] == var)
            return var;
        return parent[var] = find(parent[var]);
    }

    void unionByRank(char u, char v)
    {
        char pu = find(u);
        char pv = find(v);

        if (pu != pv)
        {
            if (rank[pu] < rank[pv])
            {
                parent[pu] = pv;
            }
            else if (rank[pv] < rank[pu])
            {
                parent[pv] = pu;
            }
            else
            {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }
};

class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        DSU solver(equations);

        for (auto eq : equations)
        {
            if (eq[1] == '!')
            {
                char p1 = solver.find(eq[0]);
                char p2 = solver.find(eq[3]);
                if (p1 == p2)
                {
                    return false;
                }
            }
        }

        return true;
    }
};