#include<iostream>
#include<cstdio>
using namespace std;
int n, m;//顶点数n，着色数m
int a = 1, b = 1;//表示边的两个顶点
int total;//着色人方法的总数
int graph[20][20] = { 0 };//无向连通图
int color[20] = { 0 };//着色的颜色
bool ok(int v)//判断该顶点是否需要继续着色 
{
	for (int k = 1; k <= n; k++) {
		if (graph[v][k] == 1 && color[v] == color[k])
		{
			//如果顶点是相邻点连通且颜色相同
			return false;
		}
		
	}
	return true;
}
void backtrack(int v) {
	//给顶点v着色
	//顶点编号已经超过总顶点个数，意味着一个着色方案已经形成，输出着色方案，总数+1
	if (v > n) {
		for (int i = 1; i <= n; i++) {
			cout << color[i]<<" ";
		}
		total++;
		cout << endl;
	}
	//如果未形成完整的着色方案，判断是否继续着色
	else {
		for (int i = 1; i <= m; i++) {
			color[v] = i;
			if (ok(v)) {
				backtrack(v + 1);
			}
			color[v] = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	while (cin >> a >> b && a != 0 && b != 0) {
		//构造给定的图
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	backtrack(1);//给顶点1着色
	if (total == 0)
		cout << "No" << endl;
	else
	printf("Total=%d\n", total);
}