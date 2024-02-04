#include <bits/stdc++.h>

using namespace std;

void deleteHeap(vector<int> &v)
{
    v[0] = v[v.size() - 1];
    v.pop_back();
    int currentIndex = 0;
    int totalChildren = v.size();
    while (true)
    {
        int leftIndex = (currentIndex * 2) + 1;
        int rightIndex = (currentIndex * 2) + 2;

        // left and right both present
        if (leftIndex < totalChildren && rightIndex < totalChildren)
        {
            if (v[leftIndex] > v[rightIndex])
            {
                if (v[leftIndex] < v[currentIndex])
                {
                    break;
                }
                swap(v[currentIndex], v[leftIndex]);
                currentIndex = leftIndex;
            }
            else
            {
                if (v[rightIndex] < v[currentIndex])
                {
                    break;
                }
                swap(v[currentIndex], v[rightIndex]);
                currentIndex = rightIndex;
            }
        }

        // left present
        else if (leftIndex < totalChildren)
        {
            if (v[leftIndex] < v[currentIndex])
            {
                break;
            }
            swap(v[currentIndex], v[leftIndex]);
            currentIndex = leftIndex;
        }

        // right present
        else if (rightIndex < totalChildren)
        {
            if (v[rightIndex] < v[currentIndex])
            {
                break;
            }
            swap(v[currentIndex], v[rightIndex]);
            currentIndex = rightIndex;
        }
        else
            break;
    }
}

int main()
{
    vector<int> v;

    // Insert in Heap
    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        int currentIndex = v.size() - 1;

        while (currentIndex != 0)
        {
            int parentIndex = (currentIndex - 1) / 2;
            if (v[parentIndex] < v[currentIndex])
            {
                swap(v[parentIndex], v[currentIndex]);
            }
            else
                break;

            currentIndex = parentIndex;
        }
    }

    deleteHeap(v);

    // print heap ( print vector)
    for (int val : v)
    {
        cout << val << " ";
    }
    return 0;
}