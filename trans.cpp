#include <fstream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ofstream MyFile("filename.txt");
    for(int i=0;i<22287; i++)
    {
        string a,b;
        cin>>a>>b;
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        MyFile<<b<<","<<a<<"\r\n";
    }
    for(int i=22287;i<37205;i++)
    {
        string a,b;
        cin>>a>>b;
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        MyFile<<a<<","<<b<<"\r\n";
    }
    MyFile.close();
    return 0;
}

