#include <bits/stdc++.h>
#include <random>
using namespace std;

int generateRandomNumber(int l, int r)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(l, r);
    return dis(gen);
}

int main()
{
    double long money = 0;
    double long tries = 1000000;
    double long win = 1000;
    double long lose = 0;
    for (int i = 1; i <= tries; i++)
    {
        int x = generateRandomNumber(0, 1); // equal probability of winning and losing
        if (x == 1)
        {
            money += win;
        }
        else
        {
            money += lose;
        }
    }
    cout << setprecision(10) << fixed;
    cout << "Average: " << money / tries << endl;
    return 0;
}