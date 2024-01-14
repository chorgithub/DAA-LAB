#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAX = 1000000;
int n;
vector<vector<int>> dist;
vector<vector<int>> memo;
int fun(int i, int mask)
{

    if (mask == ((1 << i) | 1))
        return dist[0][i]; 

    if (memo[i][mask] != 0)
        return memo[i][mask];

    int res = MAX; 

    for (int j = 1; j < n; j++)
        if ((mask & (1 << j)) && j != i)
            res = min(res, fun(j, mask & (~(1 << i))) + dist[j][i]);

    return memo[i][mask] = res;
}

int main()
{
    ifstream in("q3_in.txt");
    ofstream out("q3_out.txt");

    in >> n;

    dist.resize(n, vector<int>(n, 0));
    memo.resize(n, vector<int>(1 << n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            in >> dist[i][j];
    int answer = MAX;
    for (int i = 1; i < n; i++)
        answer = min(answer, fun(i, (1 << n) - 1) + dist[i][0]); 

    out << "The shortest possible route cost is: " << answer << endl;

    in.close();
    out.close();

    return 0;
}
