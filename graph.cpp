#include <bits/stdc++.h>

using namespace std;

/* Input */
/*
6 6   <= node and edge
0 1
1 5
0 4
0 3
3 4
2 4

*/

int main()
{
    int n, e;
    cin >> n >> e;
    /* Adjacency Matrix */
    /*
    int mat[n][n];
    memset(mat, 0, sizeof(mat));
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // for checking connection, use Adjacency Matrix
    if (mat[2][4] == 1)
        cout << "connected";
    else
        cout << "not connected";
    */

    /* Adjacency List */
    /*
    vector<int> mat[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    // for checking all connection, use Adjacency List

    //  print system : 1
    // for (int i : mat[0])
    // {
    //     cout << i << " ";
    // }

    // print system : 2
    for (int i = 0; i < mat[0].size(); i++)

    {
        cout << mat[0][i] << " ";
    }
    */

    /* Edge List */

    /*
    vector<pair<int, int>> v;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    // //  print system : 1
    // for (pair<int, int> p : v)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }

    //  print system : 2
    for (auto p : v)
    {
        cout << p.first << " " << p.second << endl;
    }

    // // print system : 3
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    */
    return 0;
}