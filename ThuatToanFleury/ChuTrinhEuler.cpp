#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>
#include <cstdio>
#include <stack>

//Ap dung cho do thi vo huong
//Code nay de tim chu trinh euler

using namespace std;

int n,m;
set<int> a[10001];
int bac[10001];

void nhap(){
    cin>>n>>m;
    for(int i = 0; i<m;i++){
        int x,y;
        cin>>x>>y;
        a[x].insert(y);
        a[y].insert(x);
        bac[x]++;
        bac[y]++;
    }
}

bool isConnected() {
    vector<bool> visited(n + 1, false);
    stack<int> st;
    
    st.push(1);  
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        visited[x] = true;

        for (int neighbor : a[x]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            return false;  
        }
    }

    return true;
}

bool KiemTraChuTrinhEuler() {
    if (!isConnected()) {
        return false;  
    }

    for (int i = 1; i <= n; ++i) {
        if (bac[i] % 2 != 0) {
            return false;  
        }
    }

    return true;
}


void euler(int x){
    stack<int> st;
    vector<int> EU;
    st.push(x);
    while(!st.empty()){
        int x = st.top();
        if(a[x].size() != 0){
            int y = *a[x].begin();
            st.push(y);
            a[x].erase(y);
            a[y].erase(x);
        }
        else{
            st.pop();
            EU.push_back(x);
        }
    }
    begin(EU), end(EU);
    for (int x : EU){ 
        cout<<x<<" ";
        }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
    if (KiemTraChuTrinhEuler()) {
        cout << "---------- Do thi co chu trinh Euler ----------" << endl;
        euler(1);
    } else {
        cout << "----------- Do thi khong co chu trinh Euler ----------" << endl;
    }
    return 0;
}