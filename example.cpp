#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int> > v = {{10, 2}, {30, 5}, {30, 4}};

    sort(v.begin(), v.end());
    for (auto ele : v)
    {
        cout << ele.first << " " << ele.second << endl;
    }
    // vector<int> v;

    // // int a[n];
    // // sort(a + 2, a + n);

    // // sort(v.begin() + 2, v.end());

    // // sort [begin, end)

    // // 10 20 30 40 v.end()
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);
    // v.push_back(40);
    // for (auto ele : v)
    //     cout << ele << " ";
    // cout << endl;

    // // reverse(v.begin(), v.end());
    // // min_element(v.begin(), v.end());
    // // max_element(v.begin(), v.end());
    // // count(v.begin(), v.end(), 10);
    // // find(v.begin(), v.end(), 10); - this is not a boolean func

    // if(find(v.begin(), v.end(), 30) != v.end()){
    //     cout<<"10 is present"<<endl;
    // }
    // else{
    //     cout<<"10 is not present"<<endl;
    // }

    // v.insert(v.end() - 2, 5);
    // v.end();
    // for (auto ele : v)
    //     cout << ele << " ";
    // cout << endl;

    // what is an iterator?

    // 10 20 30 40 50
    //

    // v.begin()
    // cout<<v[0]<<endl;

    return 0;
}
