#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*
    map =>

    map<string, int> mp;
    mp["Sakib al hasn"] = 79; // O(logN)
    mp.insert({"akib", 100});
    mp.insert({"akib", 150});
    mp["tamim"] = 79;

    // for (auto it = mp.begin(); it != mp.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl; // O(logN)
    // }

    cout << mp.count("akib") << endl;
    */

    string sentence;
    getline(cin, sentence);
    string word;
    stringstream ss(sentence);
    map<string, int> mp;
    while (ss >> word)
    {
        mp[word]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    cout << mp["She"] << endl;
    return 0;
}