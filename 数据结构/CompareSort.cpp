#include<vector>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<windows.h> 
using namespace std;

//������
void exch(int& m, int& n) {
	int temp = m;
	m = n;
	n = temp;
}
void InsertionSort(vector<int>& target) {
	int size = target.size();
	for (int i = 1;i < size;i++) {
		for (int j = i;j > 0 && target[j] < target[j - 1];j--)   // &&��·����� & �Ƕ�·�����
			exch(target[j], target[j - 1]);
	}
}
void merge(vector<int>& target, int lo, int mid, int hi) {
	int i = lo;
	int j = mid + 1;
	vector<int> tmp(hi + 1);  //��ʱtmp[hi]����
	for (int k = lo;k <= hi;k++)
		tmp[k] = target[k];
	for (int k = lo;k <= hi;k++)
		if (i > mid) target[k] = tmp[j++];					//��ǰһ�������ѿ�
		else if (j > hi) target[k] = tmp[i++];				//����һ�������ѿ�
		else if (tmp[i] <= tmp[j]) target[k] = tmp[i++];	//��ǰһ���������С�ڵ��ں�һ�����飬��֤�㷨�ȶ���
		else target[k] = tmp[j++];
}
void Mergesort(vector<int>& target, int lo, int hi) {
	if (hi <= lo) return;									//�㷨δ������ʽ�����򣬶���������ϲ�ʱ��ʽ������
	int mid = lo + (hi - lo) / 2;
	Mergesort(target, lo, mid);								//������������ֱ���й鲢����
	Mergesort(target, mid + 1, hi);
	merge(target, lo, mid, hi);								//�ϲ�������

}
void TopdownMergesort(vector<int>& target) {				//����ͨ��С���������������Ż�
	int size = target.size();
	Mergesort(target, 0, size - 1);
}
int mins(int m, int n) {
	return m > n ? n : m;
}
void BottomupMergesort(vector<int>& target) {
	int size = target.size();
	for (int sz = 1;sz < size;sz += sz) {					//sz:������Ĵ�С 
		for (int lo = 0;lo < size - sz;lo += sz + sz) {
			//ÿһ�κϲ�����sz������� lo += sz + sz Ϊ�˱�֤mid< hi <=size-1  lo < size - sz
			merge(target, lo, lo + sz - 1, mins(size - 1, lo + sz + sz - 1));
		}
	}
}
int partition(vector<int>& target, int lo, int hi) {
	int i = lo;
	int j = hi + 1;
	int v = target[lo];
	while (true) {
		while (target[++i] < v) if (i == hi) break;
		while (target[--j] > v) {}  //if(j==lo) break;
		if (i >= j) break;
		exch(target[i], target[j]);
	}
	exch(target[lo], target[j]);
	return j;
}
void sort(vector<int>& target, int lo, int hi) {
	if (hi <= lo) return;
	int j = partition(target, lo, hi);
	sort(target, lo, j - 1);
	sort(target, j + 1, hi);
}
void RandomQuicksort(vector<int>& target) {
	// �Ż�������ȡ��һ���� ���һ���� �м��������λ�����һ�������� Ҳ������С������ʹ�ò�������   Ҳ����������ĩβ�����ڱ�������߽����       
	int size = target.size();
	random_shuffle(target.begin(), target.end());
	sort(target, 0, size - 1);
}
void ThreeWaySort(vector<int>& target, int lo, int hi) {
	//lo - lt-1 С�� v lt - i-1 ����v i - gt δȷ�� gt+1 - hi ���� v
	if (hi <= lo) return;
	int lt = lo;
	int i = lo + 1;
	int gt = hi;
	int v = target[lo];
	while (i <= gt) {
		if (target[i] < v) {
			exch(target[i++], target[lt++]);
		}
		else if (target[i] > v) {
			exch(target[i], target[gt--]);
		}
		else {
			i++;
		}

	}
	ThreeWaySort(target, lo, lt - 1);
	ThreeWaySort(target, gt + 1, hi);
}
void ThreeWayQuicksort(vector<int>& target) {
	int size = target.size();
	random_shuffle(target.begin(), target.end());
	ThreeWaySort(target, 0, size - 1);
}


//��������
void RandomList(vector<int>& a) {        //�����������
	int size = a.size();
	srand((unsigned)time(NULL));		 //srand()��������һ���Ե�ǰʱ�俪ʼ��������� 
	for (int i = 0;i < size;i++) {
		a[i] = rand() % size;
	}
}
void BaseIncreaseList(vector<int>& a) {	 //���ɻ�����������(������
	int size = a.size();
	srand((unsigned)time(NULL));
	for (int i = 0;i < size;i++) {
		a[i] = i;
	}
	int RandomSize = size / 20;
	for (int i = 0;i < RandomSize;i++) {
		int item = rand() % size;
		int value = rand() % size;
		a[item] = value;
	}
}
void BaseDecreaseList(vector<int>& a) {	 //���ɻ����������У��ݼ���
	int size = a.size();
	srand((unsigned)time(NULL));
	for (int i = 0;i < size;i++) {
		a[i] = size - 1 - i;
	}
	int RandomSize = size / 20;
	for (int i = 0;i < RandomSize;i++) {
		int item = rand() % size;
		int value = rand() % size;
		a[item] = value;
	}
}


//�������к���
double BaseRun(void(*CreateList)(vector<int>& a), void(*sort)(vector<int>& a), int size) {
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	vector<int>  test(size);
	CreateList(test);							//��������

	QueryPerformanceCounter(&nBeginTime);		//��ʼ��ʱ  
	sort(test);									//����	
	QueryPerformanceCounter(&nEndTime);			//ֹͣ��ʱ  

	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
	return time * 1000;
}
void RunSort(void(*sort)(vector<int>& a), int size) {
	cout << "RandomList" << endl;
	for (int i = 0;i < 10;i++) {
		double t = BaseRun(RandomList, sort, size);
		cout << t << " ";
	}
	cout << "ms" << endl;

	cout << "BaseIncreaseList" << endl;
	for (int i = 0;i < 10;i++) {
		double t = BaseRun(BaseIncreaseList, sort, size);
		cout << t << " ";
	}
	cout << "ms" << endl;

	cout << "BaseDecreaseList" << endl;
	for (int i = 0;i < 10;i++) {
		double t = BaseRun(BaseDecreaseList, sort, size);
		cout << t << " ";
	}
	cout << "ms" << endl;
}
void Run(int size) {
	cout << "InsertionSort" << endl;
	RunSort(InsertionSort, size);

	cout << "TopdownMergesort" << endl;
	RunSort(TopdownMergesort, size);

	cout << "BottomupMergesort" << endl;
	RunSort(BottomupMergesort, size);

	cout << "RandomQuicksort" << endl;
	RunSort(RandomQuicksort, size);

	cout << "ThreeWayQuicksort" << endl;
	RunSort(ThreeWayQuicksort, size);
}
void FinalRun() {
	cout << "size==1000" << endl;
	Run(1000);

	cout << "size==10000" << endl;
	Run(10000);
	cout << "size==100000" << endl;
	Run(100000);

	cout << "size==1000000" << endl;
	Run(1000000);

	cout << "size==1000000" << endl;
	Run(1000000);

	cout << "size==1000000" << endl;
	Run(1000000);
}






//���Ժ�����
void print_vector(vector<int> test) {
	for (int i = 0;i < test.size();i++) {
		cout << test[i] << " ";

	}
	cout << endl;
}
void testSort() {
	int test[] = { 45,1,3,448,54,12516,11,3,11,44 };
	vector<int> target(test, test + 10);
	print_vector(target);
	ThreeWayQuicksort(target);
	print_vector(target);
}

int main() {
	FinalRun();
}