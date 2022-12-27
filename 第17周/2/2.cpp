#include <iostream>
using namespace std;
#define maxv 100

int maxvalue(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int indegree[maxv];
int timea[maxv][maxv];
int alltime[maxv] = {0};
int result = 0;
int cnt = 0;

void topology(int n){
    while(true){
        int flag = 0;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                for(int j = 0; j < n; j++){
                    if(timea[i][j] != -1){
                        alltime[j] = maxvalue(alltime[j], alltime[i] + timea[i][j]);
                        result = maxvalue(alltime[j], result);
                        indegree[j]--; 
                    }
                }
                indegree[i] = -1;
                flag = 1; 
                cnt++;
            }
        }
        if(flag == 0){
            break;
        }
    }
    if(cnt < n){
        cout << "Impossible";
    }
    else{
        cout << result;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            timea[i][j] = -1;
        }
    }
    for(int i = 0; i < m; i++){
        int p1, p2, t;
        cin >> p1 >> p2 >> t;
        timea[p1][p2] = t; 
        indegree[p2]++; 
    }

    topology(n);
    return 0;
}

