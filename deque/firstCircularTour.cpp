#include <deque>
#include <vector>
#include <iostream>
using namespace std;

int getLoc_startPos(int petrol[], int dist[], int n)
{
    /* // NAIVE SOLUTION
    for (int st = 0; st < n; st++)
    {
        int curr_petrol = 0;
        int en = st;
        while (true)
        {
            curr_petrol += petrol[en] - dist[en];
            if (curr_petrol < 0)
                break;
            en = (en + 1) % n;
            if (en == st)
                return st+1;
        }
    }
    return -1;
    */
    // BETTER SOLUTION int tour(petrolPump p[],int n)
    deque<int> dq;
    int st = 0, curr = 0, vis_cnt = 0;
    while (1)
    {
        curr += (petrol[st] - dist[st]);
        if (dq.empty())
        {
            vis_cnt++;
        }
        dq.push_back(st);
        while (!dq.empty() && curr < 0)
        {
            curr -= (petrol[dq.front()] - dist[dq.front()]);
            dq.pop_front();
        }
        if (dq.size() == n)
        {
            return dq.front() + 1;
        }
        if (vis_cnt >= n)
            break;
        st = (st + 1) % n;
    }
    return -1;
    // return dq.front() + 1;

    /* // EFFICIENT SOLUTION
    int st = 0, curr_petrol = 0, prev_petrol = 0;
    for (int i = 0; i < n; i++)
    {
        curr_petrol += petrol[i] - dist[i];
        if (curr_petrol < 0)
        {
            st = i + 1;
            prev_petrol += curr_petrol;
            curr_petrol = 0;
        }
    }
    return (curr_petrol + prev_petrol >= 0 ? st + 1 : -1);
    */
}
int main()
{
    int n;
    cin >> n;
    int petrol[n], dist[n];
    for (int i = 0; i < n; i++)
    {
        cin >> petrol[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> dist[i];
    }
    cout << getLoc_startPos(petrol, dist, n);
    return 0;
}