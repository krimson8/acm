#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdio>
#include <stack>
using namespace std;

vector<int> dfn, low, in_stk;
vector<vector<int> > edge, new_edge;
int dfsn, ans;
stack<int> S;

const int DFS_WHITE = -1;
map<int,int> new_mp;

void DFS (int cur) {
	dfn[cur] = low[cur] = dfsn++;
	in_stk[cur] = 1;
	S.push(cur);
 
	for(int j = 0; j < edge[cur].size(); j++) {
		int next = edge[cur][j];
		if (dfn[next]==DFS_WHITE) 
            DFS(edge[cur][j]);
		if (in_stk[next]) 
            low[cur] = min (low[cur], low[next]);
	}
	
	if(low[cur]==dfn[cur]) {
		int top = 0;
        do {
            top = S.top();
            S.pop();
            in_stk[top] = 0;
            new_mp[top] = ans;
        } while(top != cur);
        ++ans;
	}
}

int main() {
	
	int n, m;
    int c;
    int v, w;
	scanf("%d", &c);

	while(c--) {
		scanf("%d %d", &n, &m);
		edge.clear();
		edge.resize(n);
		new_mp.clear();
		
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &v, &w);
			edge[v - 1].push_back(w - 1);
		}
	
		dfn.assign(n, DFS_WHITE);
		low.assign(n, 0);
		in_stk.assign(n, 0);

        // for(int i = 0; i < n; i++) {
        //     dfn[i] = DFS_WHITE;
        //     low[i] = 0;
        //     in_stk[i] = 0;
        // }

		dfsn = 0;
        ans = 0;
        
		for(int i = 0; i < n; i++) {
			if(dfn[i] == DFS_WHITE) DFS(i);
		}
	
		new_edge.clear();
		new_edge.resize(ans);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < edge[i].size(); j++) {
				if (new_mp[i] != new_mp[edge[i][j]])
					new_edge[new_mp[i]].push_back(new_mp[edge[i][j]]);
			}
		}
		
		vector<int> indegree (ans, 0); 
		for (int i = 0; i < ans; i++) {
			for (int j = 0; j < new_edge[i].size(); j++) {
				indegree[new_edge[i][j]] = 1;
			}
		}
		int ret = 0;
		for (int i=0; i < ans; i++) 
            if(indegree[i] == 0) ret++;
		printf ("%d\n", ret);
	}
	
	return 0;
}