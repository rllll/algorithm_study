#include<iostream>
#include <stdlib.h> 
#include <time.h> 

using namespace std;
class UF {
private:
	bool* open;     //��ʾ�ڵ��״̬ trueΪ�õ��ѵ���
	int* tmp;		//��n*n�Ķ�ά����չ����һά���� ����tmp[0] Ϊ�϶˵�����ڵ� tmp[n*n+1]Ϊ�¶˵�����ڵ�
	int n;			//����Ĺ�ģ
	int* weight;	//��ͨ�����ĸ���
public:
	UF(int n) {						//��ʼ��
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
	void Print() {				//���Ժ���
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
	bool is_legal(int row, int col) {   //�ж��Ƿ��±�Ϸ�
		if (row < 0 || row >= n)
			return false;
		if (col < 0 || col >= n)
			return false;
		return true;
	}
	bool is_open(int row, int col) {			//�жϽڵ��Ƿ񱻵���
		return open[row * n + col];				//n*n�����չ����ʽ
	}
	int change(int row, int col) {				//����ά�����±�չ��Ϊn*n+2��һά����
		return row * n + col + 1;
	}
	int find(int p) {							//Ѱ�ҽڵ�ĸ��ڵ� ˳��·���Ż�
		while (tmp[p] != p) {
			tmp[p] = tmp[tmp[p]];
			p = tmp[p];
		}
		return p;
	}
	bool connect(int p, int q) {
		return (find(p) == find(q));
	}
	void unions(int p, int q) {	//��Ȩ��union�㷨
		/*if (!connect(p, q)) {   //find(p)�ظ�ִ��
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
		srand((unsigned)time(NULL));   //srand()��������һ���Ե�ǰʱ�俪ʼ��������� 
		int i, j;
		while (true) {
			i = rand() % n;
			j = rand() % n;
			if (!is_open(i, j)) {				//���δ������
				open[i * n + j] = true;
				break;
			}
		}
		//cout << " i j :" << i << " " << j << endl;			//�������
		if (i == 0) {						//λ�ڶ���
			unions(0, change(i, j));
		}
		else if (i == n - 1) {				//λ�ڵײ�	
			unions(n * n + 1, change(i, j));
		}
		if (is_legal(i + 1, j) && is_open(i + 1, j))		//�¶˵�
			unions(change(i + 1, j), change(i, j));

		if (is_legal(i, j + 1) && is_open(i, j + 1))		//�Ҷ˵�
			unions(change(i, j + 1), change(i, j));

		if (is_legal(i - 1, j) && is_open(i - 1, j))   //�϶˵�
			unions(change(i - 1, j), change(i, j));

		if (is_legal(i, j - 1) && is_open(i, j - 1))		//��˵�
			unions(change(i, j - 1), change(i, j));

	}
	bool seepager() {				//����Ƿ�����͸
		return connect(0, n * n + 1);
	}
};
int main() {
	double prob;	//Ƶ��
	int num;		//���ֵĵĴ���
	int n;			//n*n����
	double sum = 0;  //test_num��Ƶ�ʵ��ܺ�
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
				prob = num;				//��������
				prob = prob / (n * n);
				sum = sum + prob;
				break;
			}
		}
	}
	cout << sum / test_num << endl;
	return 0;
}