#include<vector>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<windows.h> 
using namespace std;

//排序函数
void exch(int& m, int& n) {
	int temp = m;
	m = n;
	n = temp;
}
void InsertionSort(vector<int>& target) {
	int size = target.size();
	for (int i = 1;i < size;i++) {
		for (int j = i;j > 0 && target[j] < target[j - 1];j--)   // &&短路运算符 & 非短路运算符
			exch(target[j], target[j - 1]);
	}
}
void merge(vector<int>& target, int lo, int mid, int hi) {
	int i = lo;
	int j = mid + 1;
	vector<int> tmp(hi + 1);  //此时tmp[hi]存在
	for (int k = lo;k <= hi;k++)
		tmp[k] = target[k];
	for (int k = lo;k <= hi;k++)
		if (i > mid) target[k] = tmp[j++];					//若前一个数组已空
		else if (j > hi) target[k] = tmp[i++];				//若后一个数组已空
		else if (tmp[i] <= tmp[j]) target[k] = tmp[i++];	//若前一个数组的数小于等于后一个数组，保证算法稳定性
		else target[k] = tmp[j++];
}
void Mergesort(vector<int>& target, int lo, int hi) {
	if (hi <= lo) return;									//算法未进行显式的排序，而是在数组合并时隐式的排序
	int mid = lo + (hi - lo) / 2;
	Mergesort(target, lo, mid);								//对两个子数组分别进行归并排序
	Mergesort(target, mid + 1, hi);
	merge(target, lo, mid, hi);								//合并子数组

}
void TopdownMergesort(vector<int>& target) {				//可以通过小数组插入排序进行优化
	int size = target.size();
	Mergesort(target, 0, size - 1);
}
int mins(int m, int n) {
	return m > n ? n : m;
}
void BottomupMergesort(vector<int>& target) {
	int size = target.size();
	for (int sz = 1;sz < size;sz += sz) {					//sz:子数组的大小 
		for (int lo = 0;lo < size - sz;lo += sz + sz) {
			//每一次合并两个sz大的数组 lo += sz + sz 为了保证mid< hi <=size-1  lo < size - sz
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
	// 优化：可以取第一个数 最后一个数 中间的数的中位数与第一个数交换 也可以在小数组中使用插入排序   也可以在数组末尾放置哨兵来避免边界测试       
	int size = target.size();
	random_shuffle(target.begin(), target.end());
	sort(target, 0, size - 1);
}
void ThreeWaySort(vector<int>& target, int lo, int hi) {
	//lo - lt-1 小于 v lt - i-1 等于v i - gt 未确定 gt+1 - hi 大于 v
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


//测试数组
void RandomList(vector<int>& a) {        //生成随机序列
	int size = a.size();
	srand((unsigned)time(NULL));		 //srand()函数产生一个以当前时间开始的随机种子 
	for (int i = 0;i < size;i++) {
		a[i] = rand() % size;
	}
}
void BaseIncreaseList(vector<int>& a) {	 //生成基本有序序列(递增）
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
void BaseDecreaseList(vector<int>& a) {	 //生成基本有序序列（递减）
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


//基本运行函数
double BaseRun(void(*CreateList)(vector<int>& a), void(*sort)(vector<int>& a), int size) {
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	vector<int>  test(size);
	CreateList(test);							//生成数组

	QueryPerformanceCounter(&nBeginTime);		//开始计时  
	sort(test);									//排序	
	QueryPerformanceCounter(&nEndTime);			//停止计时  

	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
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






//测试函数集
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