// 0702.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include<functional>
#include <algorithm>
using namespace std;
class print {
public:
    void operator()(int n) {
        cout << n << " ";

    }
};
class desending {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};
int add(int a, int b) {
    return a + b;
}
class puls {
public:
    int operator() (int a ,int b){
        return a + b;

    }
};
int main()
{
    /*vector <int> v = {5,2,6,10,3};
    sort(v. begin(),v.end());
    for_each(v.begin(), v.end(),print());
    cout << endl;
    sort(v.begin(), v.end(), desending());
    for_each(v.begin(), v.end(), print());
    */
    vector <int> v = { 5,2,6,10,3 };

    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), print());

    vector<bool> flags = {true, false, true, false};
    transform(flags.begin(), flags.end(), flags.begin(), logical_and<bool>());
    for_each(flags.begin(), flags.end(), print());

    plus<int> add;
    cout << add(3, 4) << endl;
}

