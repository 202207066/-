// 0701.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include<map>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    /*
    vector<int> v;

    v.push_back(10);
    v.push_back(12);
    v.push_back(13);
    v.push_back(155);
    v.push_back(176);

    vector<int> v1;

    v.push_back(10);
    v.push_back(12);
    v.push_back(1100);
    */
    /*
    vector<int> v1 (3);
    vector<int> v2 (3, 10);
    vector<int> v3 = { 10,20,30 };

    v.push_back(10);
    v.push_back(12);
    v.push_back(13);
    v[0] = 100;


    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    cout << endl;
   /// cout << v.front() << endl;
    ///cout << v.back() << endl;

    v2.assign(3, 100);
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v[i] << endl;
    }
    cout << v.max_size() << endl;
    */
    /*
    vector<int> ::iterator iter;
    vector<int> ::reverse_iterator riter;

    for (iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    for (riter = v.rbegin(); riter != v.rend(); riter++)
    {
        cout << *riter << " ";
    }
    cout << endl;

    iter = v.begin() + 1;
    ///v.insert(iter, 2, 1000);
    for (iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << " ";
    }

    ///v.insert(iter, v.begin(), v.end());
    cout << endl;
    for (iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << " ";
    }
    v.erase(v.begin()+1,v.begin()+4);

    cout << endl;
    for (iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << " ";
    }
    */
    /*
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    v.push_back(60);
    cout << v.size()<<endl;
    cout << v.capacity() << endl;
    v.push_back(60);
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    v.clear();
    cout << v.size() << endl;
    cout << v.capacity() << endl;

    if (v.empty())
    {
        vector<int>().swap(v);
        cout << v.size() << endl;
        cout << v.capacity() << endl;
    }*/
    /*
    if (v == v1) {
        cout << "같음" << endl;
    }
    if (v != v1) {
        cout << "다름" << endl;
    }
    if (v < v1) {
        cout << "v < v1" << endl;
    }
    if (v > v1) {
        cout << "v > v1" << endl;
    }*/
    /*
    map<string, int>scores;
    scores["Alice"] = 90;
    scores["Bob"] = 40;
    scores["charlie"] = 60;
    for (auto it = scores.begin(); it != scores.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }

    scores["Bob"] = 100;

    scores.insert({ "David",10 });
    auto result = scores.insert({ "Alice",10 });
    if (!result.second)
    {
        cout << "실패" << endl;
    }
    for (auto it = scores.begin(); it != scores.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }


    cout << scores["David"] << endl;
    cout << scores["Jon"] << endl;
    for (auto it = scores.begin(); it != scores.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }
    scores.erase("Jon");


    auto it = scores.find("David");
    if (it != scores.end())
    {
        cout;
    }*/
/*
    stack<int>s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    queue<int>q;

    q.push(10);
    q.push(20);
    q.push(30);
    while (!q.empty())
    {
        cout << q.top() << endl;
        q.pop();
    }*/
}

