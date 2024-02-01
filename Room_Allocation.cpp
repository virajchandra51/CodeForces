#include <bits/stdc++.h>
using namespace std;

static bool compare(pair<long long, pair<long long, long long> > &a, pair<long long, pair<long long, long long> > &b)
{
    return a.second.first < b.second.first;
}

int main()
{
    long long n;
    cin >> n;
    vector<pair<long long, pair<long long, long long> > > v(n);
    // stores index, arrival, departure in order
    for (long long i = 0; i < n; i++)
    {
        long long arrival, departure;
        cin >> arrival >> departure;
        v[i].first = i;
        v[i].second.first = arrival;
        v[i].second.second = departure;
    } // taking input

    sort(v.begin(), v.end(), compare); // sort on basis of arrival then departure
    vector<long long> roomAllocation(n); // answer array
    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > pq;
    // stores lowest departure pair with its roomId
    long long roomId = 1; // denoting which room I'm giving to some person


    for (int i = 0; i < n; i++)
    {
        pair<long long, pair<long long, long long> > room = v[i]; // extracting room
        if (pq.size() == 0) // if nothing in queue means first room
        {
            roomAllocation[room.first] = roomId; // give it the roomId 
            pq.push({room.second.second, roomId}); // push the departure time with roomId
            roomId++; // increase roomId
        }
        else
        {
            if (pq.top().first >= room.second.first) 
            // if the time by which the customer arrives is lower equal than
            // the smallest time on which a room gets free
            // that means I need a new room for this customer as no room is free when he arrived
            {
                roomAllocation[room.first] = roomId;
                pq.push({room.second.second, roomId});
                roomId++;
            }
            else // if the first smallest room gets free
            // I can take that room and just allot it to the new customer
            // and update that room's time when it gets available as departure time of customer
            {
                auto it = pq.top();
                pq.pop();
                roomAllocation[room.first] = it.second; // copy roomId
                it.first = room.second.second; // update time
                pq.push(it);
            }
        }
    }
    // print the max value of the roomIds
    cout << *max_element(roomAllocation.begin(), roomAllocation.end()) << endl;
    // print rooms
    for (auto it : roomAllocation)
        cout << it << " ";
    cout << endl;

    return 0;
}

// TC - O(nlogn)
// SC - O(n)