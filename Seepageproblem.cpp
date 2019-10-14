#include<iostream>
#include <stdlib.h> 
#include <time.h> 

using namespace std;
class UF {
private:
	bool* open;     //表示节点的状态 true为该点已点亮
	int* tmp;		//将n*n的二维数组展开的一维数组 其中tmp[0] 为上端点虚拟节点 tmp[n*n+1]为下端点虚拟节点
	int n;			//数组的规模
	int* weight;	//连通分量的个数
public:
	UF(int n) {						//初始化
		this->n = n;
		open = new bool[n * n];
		weight = new int[n * n + 2];
		tmp = new int[n * n + 2];
		for (int i = 0;i < n * n;i++) {
			open[i] = false;
		}
		for (int i = 0;i < n * n + 2;i++) {
			tmp[i] = i;
			weight[i] = 1;
		}
	}
	void Print() {				//测试函数
		cout << "open ";
		for (int i = 0;i < n * n;i++) {
			cout << open[i] << " ";
		}
		cout << endl;
		cout << "tmp ";
		for (int i = 0;i < n * n + 2;i++) {
			cout << tmp[i] << " ";
		}
		cout << endl;
		cout << "weight ";
		for (int i = 0;i < n * n + 2;i++) {
			cout << weight[i] << " ";
		}
		cout << endl;
	}
	bool is_legal(int row, int col) {   //判断是否下标合法
		if (row < 0 || row >= n)
			return false;
		if (col < 0 || col >= n)
			return false;
		return true;
	}
	bool is_open(int row, int col) {			//判断节点是否被点亮
		return open[row * n + col];				//n*n数组的展开方式
	}
	int change(int row, int col) {				//将二维数组下标展开为n*n+2的一维数组
		return row * n + col + 1;
	}
	int find(int p) {							//寻找节点的根节点 顺便路径优化
		while (tmp[p] != p) {
			tmp[p] = tmp[tmp[p]];
			p = tmp[p];
		}
		return p;
	}
	bool connect(int p, int q) {
		return (find(p) == find(q));
	}
	void unions(int p, int q) {	//加权的union算法
		/*if (!connect(p, q)) {   //find(p)重复执行
			int i, j;
			i = find(p);
			j = find(q);
			if (weight[i] >= weight[j]) {
				tmp[j] = i;
				weight[i] += weight[j];
			}
			else {
				tmp[i] = j;
				weight[j] += weight[i];
			}
		}*/
		int i, j;
		i = find(p);
		j = find(q);
		if (i != j) {
			if (weight[i] >= weight[j]) {
				tmp[j] = i;
				weight[i] += weight[j];
			}
			else {
				tmp[i] = j;
				weight[j] += weight[i];
			}
		}
	}
	void light() {
		srand((unsigned)time(NULL));   //srand()函数产生一个以当前时间开始的随机种子 
		int i, j;
		while (true) {
			i = rand() % n;
			j = rand() % n;
			if (!is_open(i, j)) {				//如果未被点亮
				open[i * n + j] = true;
				break;
			}
		}
		//cout << " i j :" << i << " " << j << endl;			//测试语句
		if (i == 0) {						//位于顶部
			unions(0, change(i, j));
		}
		else if (i == n - 1) {				//位于底部	
			unions(n * n + 1, change(i, j));
		}
		if (is_legal(i + 1, j) && is_open(i + 1, j))		//下端点
			unions(change(i + 1, j), change(i, j));

		if (is_legal(i, j + 1) && is_open(i, j + 1))		//右端点
			unions(change(i, j + 1), change(i, j));

		if (is_legal(i - 1, j) && is_open(i - 1, j))   //上端点
			unions(change(i - 1, j), change(i, j));

		if (is_legal(i, j - 1) && is_open(i, j - 1))		//左端点
			unions(change(i, j - 1), change(i, j));

	}
	bool seepager() {				//检查是否发生渗透
		return connect(0, n * n + 1);
	}
};
int main() {
	double prob;	//频率
	int num;		//出现的的次数
	int n;			//n*n矩阵
	double sum = 0;  //test_num次频率的总和
	int test_num = 100;
	cin >> n;
	for (int i = 0;i < test_num;i++) {
		UF  uf(n);
		//uf.Print();
		num = 0;
		prob = 0;
		while (true) {
			uf.light();
			//uf.Print();
			num++;
			if (uf.seepager()) {
				prob = num;				//避免整除
				prob = prob / (n * n);
				sum = sum + prob;
				break;
			}
		}
	}
	cout << sum / test_num << endl;
	return 0;
}