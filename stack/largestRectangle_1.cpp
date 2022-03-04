// effective time complexity : O(R*C)
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int largestHist(int row[], int c)
{
    stack<int> result;
    int top_val;
    int max_area = 0;
    int area = 0;
    int i = 0;
    while (i < c)
    {
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);

        else
        {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;

            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }
    while (!result.empty())
    {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);

        max_area = max(area, max_area);
    }
    return max_area;
}
int maxRectangle(int **a, int r, int c)
{
    int res = largestHist(a[0], c);
    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] == 1)
                a[i][j] += a[i - 1][j];
        }
        res = max(res, largestHist(a[i], c));
    }
    return res;
}
int main()
{
    int r, c;
    cin >> r >> c;
    int **a = new int *[r];
    for (int i = 0; i < r; i++)
        a[i] = new int[c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    cout << maxRectangle(a, r, c);
    return 0;
}