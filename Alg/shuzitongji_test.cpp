#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Node {
    int num;
    int cnt;
    Node(int n, int c) : num(n), cnt(c) {}
    bool operator<(const Node & other) const {
        if(cnt > other.cnt) return true;
        else if(cnt == other.cnt && num < other.num) return true;
        return false;
    }
};

int main() {
    int N;
    cin >> N;
    map<int,int> counter;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        counter[num]++;
    }
    vector<Node> vec;
    for(map<int,int>::iterator it=counter.begin(); it!=counter.end(); it++) {
        vec.push_back(Node(it->first, it->second));
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<vec.size(); i++) {
        cout << vec[i].num << " " << vec[i].cnt << endl;
    }
}