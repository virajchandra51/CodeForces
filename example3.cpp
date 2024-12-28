#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main()
{
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    for(int i=0; i<1000; i++)
    {
        cout << "" << '\n';
    }

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}