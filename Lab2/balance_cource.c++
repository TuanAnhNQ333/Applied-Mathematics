#include<iostream>
using namespace std;

int m, n, k;
vector<vector<int>>favor;
bool conflict[31][31];
vector<int>load;
vector<vector<int>>assigned;
int ans = INT_MAX;

bool is_valid(int teacher, int course)
{
    if(find(favor[teacher].begin(), favor[teacher].end(), course + 1) == favor[teacher].end())
        return false;
for(int i = 0; i< assigned[teacher].size(); i++)
    {
        if(conflict[course][assigned[teacher][i]]) return false;
    }
    return true;
}

void Try(int index)
{
if(index == n)
    {
        int max_load_curr = *max_element(load.begin(), load.end());
ans = min(ans, max_load_curr);
return;
    }
for(int teacher = 0; teacher < m; teacher++)
    {
if(is_valid(teacher, index) && load[teacher] + 1 <= ans)
        {
            load[teacher]++;
            assigned[teacher].push_back(index);
Try(index + 1); 
            load[teacher]--;
            assigned[teacher].pop_back();
        }
    }
}

int main()
{
cin>> m >>n;
favor.resize(m);
load.resize(m, 0);
assigned.resize(m);

for(int i = 0; i< m; i++)
    {
        int k;
cin>>k;
        favor[i].resize(k);
for(int j = 0; j < k; j++)
        {
cin>> favor[i][j];
        }
    }

cin>>k;
memset(conflict, false, sizeof(conflict));
for(int i = 0; i< k; i++)
    {
        int temp1, temp2;
cin>> temp1 >>temp2;
conflict[temp1 - 1][temp2 - 1] = true; 
conflict[temp2 - 1][temp1 - 1] = true;
    }

Try(0);

    if (ans == INT_MAX) {
        cout<< -1 <<endl;
    } else {
        cout<<ans<<endl;
    }

    return 0;
}

