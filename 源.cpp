#include<iostream>
#include<cstdio>
using namespace std;
int n, m;//������n����ɫ��m
int a = 1, b = 1;//��ʾ�ߵ���������
int total;//��ɫ�˷���������
int graph[20][20] = { 0 };//������ͨͼ
int color[20] = { 0 };//��ɫ����ɫ
bool ok(int v)//�жϸö����Ƿ���Ҫ������ɫ 
{
	for (int k = 1; k <= n; k++) {
		if (graph[v][k] == 1 && color[v] == color[k])
		{
			//������������ڵ���ͨ����ɫ��ͬ
			return false;
		}
		
	}
	return true;
}
void backtrack(int v) {
	//������v��ɫ
	//�������Ѿ������ܶ����������ζ��һ����ɫ�����Ѿ��γɣ������ɫ����������+1
	if (v > n) {
		for (int i = 1; i <= n; i++) {
			cout << color[i]<<" ";
		}
		total++;
		cout << endl;
	}
	//���δ�γ���������ɫ�������ж��Ƿ������ɫ
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
		//���������ͼ
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	backtrack(1);//������1��ɫ
	if (total == 0)
		cout << "No" << endl;
	else
	printf("Total=%d\n", total);
}