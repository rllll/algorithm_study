# algorithm_study

学习数据结构与算法的记录

* 欧几里得算法
  * [递归版本](gcd_recursionVersion.cpp)
  * [非递归版本](gcd_norecursionVersion.cpp)
  
  欧几里得算法解决的是求两个不全为0的非负整数m和n的最大公约数。算法来源于古希腊数学家、亚历山大港的欧几里得所著《几何原本》。欧几里得给出的算法步骤非常简单，但其原理却深刻影响着历代以来的数学家。

  欧几里得算法描述：不断重复gcd(m, n)=gcd(n, m mod n)，直至m mod n = 0，因为gcd(m,0)=m，m最终取值也是m和n初值的最大公约数。

* [埃拉托色尼筛选法](SieveOfEratosthenes.cpp)

    考虑这样一个问题：如何快速地筛选出不大于给定的数n的所有质数？

    埃拉托色尼筛选法给出的方法是：先假设质数序列为2-n，表示2-n中所有数均是质数。依次从序列中取出一个数，然后消除序列中所有它的倍数。当序列中已经没有数字可以消去，仍留在序列中的所有数字就是所要求的不大于n的所有质数。

    思考：从直观上，采取这样的方法确实可以快很多，但仍然进行了很多无效的操作，比如6这个数字，在第一次循环时因为2的倍数被消除，但在进行第二次循环时又被3的倍数消除了一次，尽管这里的消除只是直接将值赋值给0，但从算法原理的角度确实需要更多的操作，有没有更好的方法避免这种情况呢？

    优化：在筛选2的倍数时，我们是依次筛选2×2,2×3,2×4,2×5...进行3时，按照原本的算法，是筛选3×2,3×3,3×4,3×5...可不可以跳过3×2，直接从3×3开始筛呢？答案是肯定的。规律就是从p×p开始筛。因为可以肯定，开始筛p的倍数时，2×p,3×p...(p-1)×p一定在之前的步骤中消去了。例如筛选p=5时，很容易可以发现2×5,3×5已经分别在筛选2的倍数，3的倍数的过程中筛去，剩下的4×5，可以知道在进行2×10的步骤中消去。这个有点隐蔽，其实想想可以发现，4已经是一个合数，也就是可以拆分为更小的两个数2×2相乘，如果只看其中一个数2，就会发现其实还是在筛选2的倍数。

### 排序和查找

* [选择排序](selectSort.cpp)

    **算法思想**：从数组\[0..n-1\]中选择一个最小的数放在第一个位置，再从剩下的\[1..n-1\]个元素的子数组中选择最小的数放在第二个位置，重复进行n-1步后，算法结束。

    时间效率：O(n^2)

* [冒泡排序](BubbleSort.cpp)

    **算法思想**：比较数组中相邻的两个元素，如果逆序，则交换它们的位置，重复多次以后，数组中较大的元素总是向着数组末尾“沉”去，数组中较小的元素向首部“浮”去，因此把这种算法叫做“冒泡排序”。

    时间效率：O(n^2)
* [插入排序](InsertSort.cpp)

    **算法思想**：将数组看成两个子数组，分别是已排序子数组和未排序子数组。初始时，已排序数组中只有第一个元素，未排序数组中是剩下的n-1个元素。依次将未排序数组中的元素插入到已排序数组中合适位置，重复n-1次完成。

    时间效率：O(n^2)

* [合并排序](Mergesort.cpp)

    **算法思想**：将一个数组一分为二，分别对每个子数组递归排序，然后再将两个排好序的子数组合并成一个有序数组。这里采用分而治之的思想，即只要得到所有子问题的解，最终的解可以通过这些子问题的解得到。

    最差输入效率：O(nlogn)
    
    平均时间效率：O(nlogn)
    
    最优输入效率：O(nlogn)

* [快速排序](Quicksort_HoarePatition.cpp)

    **算法思想**：快速排序的核心是对于数组中的某个元素k，经过合适的操作确定其在最终序列中的位置，通常也把k看成一个键，将比k小的元素放在k的左边，比k大的元素放在k的右边，这样k的最终位置就确定了。之所以把k看成键来对数组进行划分，主要是因为通过这样的处理之后，对于k两边的左右子数组来说，可以进行递归操作，降低时间复杂度。

    **划分方法** 快速排序的划分方法有很多种，即对于数组中k的选取。代码采用快速排序发明者的划分方法（霍尔划分），其实也很简单，即选取第一个元素作为键值k，从第二个元素开始比较，如果比k小，继续比较下一位，直到遇到大于等于k的元素。再从最后一个元素往前，如果比k大，也继续往前，直到遇到小于等于k的元素。

    此时会面临三种情况（假设此时两个下标i和j）：i < j，将a[i]和a[j]对调，继续i++,j--；i > j，说明此时划分结束了，将k的位置放在a[j]的位置；i = j，划分结束，k的位置一定在a[i]或a[j]处，综合后两种情况，直接将k与a[j]对换。

    最差输入效率：O(n^2)

    平均时间效率：O(nlogn)

    最优时间效率：O(nlogn)

    值得一提的是，快速排序对于已经排好序的数组来说竟然是最差输入，因为对于每一次划分来说，比键值小的或比键值大的都在一边，也就是说算法的效率从原来的分而治之两边的数组实际上变成了一边，因而效率退化为O(n^2)。尽管如此，快速排序不失为一种效率可观的排序算法。

    [另一个版本的快速排序](Quicksort_anotherVersion.cpp)

* [堆排序](Heapsort.cpp)

    **算法思想**：构建一个最小（大）堆，排序时每次取树根元素，再将树根和最后一片叶子交换后删掉，最后重新将堆调整成最小（大）堆。

    最差输入效率：O(nlogn)

    平均时间效率：O(nlogn)
    
    最优输入效率：O(nlogn)

* [排序算法的比较](CompareSort.cpp)  
     
     程序对插入排序 自顶向和自底向上的归并排序 快速排序 三路划分的快速排序在乱序 基本有序 基本逆序的情况的性能作出比较

### 复杂算法

* [动态连通性](Seepageproblem.cpp)  

    算法思想：<br/>
        **子问题的提出**：问题的输入是一列整数对，其中每个整数对都表示一种某个类型对象。  
        一对整数对p,q可以被理解成"p和q是相连的"。 在得到若干组输入后，判断一 对新对象是<br/>否是相连的。这个问题被称为**动态连通性问题**。  
		**算法思想**：该问题实际上考察连通分量的判断与合并。刚开始的时候，  
		所有的节点处于孤立状态，每得到一组输入时，需判断两个节点是否处于  
		同一个连通分量，如果不是，则将节点的连通分量合并。  
		**核心函数**： find()查找节点的连通分量标识符　connect（）判断两节点连通分量是否一致  
		union（）将两节点的连通分量合并  
		**数据结构的选取**　
		<br/>１：用一维数组存储所有整数对的信息，用下标ｉ表示节点序号<br/>该单元存储的值即为连通分量标识符，在程序初始化时可将所有a[i]=i以达到孤立节点的效果  
		**函数实现**：此时find（） connect（）实现较为简单，但union(p,q)则需要遍历数组将所有  
		连通分量为a[q]的节点改为a[p],时间复杂度为O(n)  
		2：仍然采用一维数组，用下标ｉ表示节点序号，但节点储存的不再是节点的连通分量，  
		而是该节点的父亲节点，采用逻辑上的树结构（每棵树代表一个连通分量）。仅当a[i]=i表示该节点为根节点且  
		a[i]为连通分量。在程序初始化时可将所有a[i]=i使每个节点成为各自的根节点  
		**函数实现**：find（）通过迭代找到该树的根节点。connect（p,q）将q节点的根  
		节点连到p节点的根节点上。  
		**优化**  
		加权的union方法：将节点数少的根节点连至节点数多的根节点上<br/>
		路径压缩：在find（）执行时顺便将其父亲节点置为其父亲节点的父亲节点  
		即a[i] = a[a[i]],降低树的深度。<br/>
		![avatar](https://s2.ax1x.com/2019/10/15/KPYYSf.png)  
		**渗透问题**        
> 		有一个N*N矩阵。每个小格子代表一个site，当site为black时说明当前site为关闭的
>       非黑色为open。如果矩阵最底部有site可以连接到矩阵顶部，我们称这个矩阵为渗透的
   计算出每次模型渗透时，开启区域占总区域个数的百分比。已知这个百分比近似于某一常数<br/>
   并通过多次模拟采样计算该常数  
    **算法思想**:每次随机点亮一个节点，自至矩阵渗透。得到百分比，重复数次,取平均值  
    虽然此时为二维矩阵，但仍然可以展开成一维数组，只是需要同时判断下标是否合法。为  
    了方便判断矩阵是否渗透，故将顶部节点与一个虚节点连接 底部节点与一虚节点连接。  
    **程序流程**：点亮节点-》判断节点是否被点亮-》与其上下左右被点亮的节点合并-》  
    判断是否发生渗透（顶部虚节点与底部虚节点是否相连）    

### 一些杂题

* [Prime Reduction](Prime_Reduction.cpp)
* [another Prime Reduction](primereduction.cpp)
    <details>
        <summary>Prime Reduction</summary>
        
        Problem Description

        You may know about the 3n+1 problem. If not, you may look it up on the Internet. Here's a procedure inspired by this problem:

        Step 1: Accept a natural number.

        Step 2: If the number is prime, reverse the order of the digits to get a new number, else divide it by its least prime factor and then reverse the order of the digits of the resultant to get a new number.

        Step 3: Repeat step 2 until a prime number is obtained that is less than 10 or that when reversed becomes a larger or remains the same prime number.

        Here are some examples for this procedure:

        Example A: Input = 1729

        · 1729 is composite (7*13*19) and its least prime factor is 7.

        · 1729/7 = 247 and hence the new number is 742 (247 reversed).

        · 742 is composite and dividing by the least prime factor 2, we have 742/2 = 371 and hence the new number is 173.

        · 173 is prime and hence the new number is 371 (173 reversed).

        · 371 is composite (7*53) and we have 371/7 = 53 and reversing it, we get the new number 35.

        · 35 is composite with the least prime factor 5; we have 35/5 = 7. Since 7 is prime and is less than 10, the procedure stops at 7 in the 5th step.

        The input transforms to the output in 5 steps: 1729 => 742 => 173 => 371 => 35 => 7 Example B: Input = 13 13 is prime and reversing it gives 31, a larger prime. Hence the number of steps here is 0. Example C: Input = 288 Following the rules, we obtain the following series of numbers: 288 => (/2 = 144) 441 => (/3 = 147) 741 => (/3 = 247) 742 => (/2 = 371) 173 => 371 => (/7 = 53) 35 => (/5 = 7) 7 Hence the number of steps is 7.

        Example D: Input = 144 We have 144 => (/2 = 72) 27 => (/3 = 9) 9 (we assume that single digit reversal results in the same digit) => (/3 = 3) 3 Hence the number of steps is 3. Example E: Input = 111 We have 111 => (/3 = 37) 73 => 37 (prime number that when reversed results in the larger prime 73) Hence the number of steps is 2.

        Example F: Input = 1111 We have 1111 => (/11 = 101) 101 (which is prime that when reversed does not change) Hence the procedure terminates in just 1 step.

        Example G: Input = 1234 We have 1234 => 716 => 853 (prime) => 358 => 971 (prime) => 179 (prime that becomes larger when reversed) Hence the number of steps is 5.

        Let's consider all natural numbers in the closed interval between two given numbers [m,n]. If we perform the above transformation procedure on each of the numbers in this interval, it would take different numbers of steps to complete. The largest number of steps could be taken by one or more numbers. Write a program that accepts two numbers m and n (separated by a space) with m < n, n - m < 10000 and n <= 10^9 and outputs the largest number of steps taken while performing the "prime reduction" procedure on each of the natural numbers in the interval [m,n]. The number of steps may be reported as "Large" if it exceeds 1000 for any number(s) in the interval.

        Constraints
        0 < Numbers <= 10 ^ 9

        Input Format
        Two space separated integers

        Output
        The maximum number of steps taken by "prime reduction" procedure for numbers in the input range

        Test Case

        Explanation
        Example 1

        Input

        1 100

        Output

        9

        Explanation

        The maximum number of steps (9) is taken for numbers 29, 58 and 87 in the interval. Hence the output is 9.

        Example 2

        Input

        100 500

        Output

        13

        Explanation

        The maximum number of steps (13) is taken for number 419 in the interval. Hence the output is 13.

        题目大意：给定一个自然数，如果这个自然数是质数，那么将各位上的数字倒转；如果不是质数，先将其质因数分解，然后将除以质因数中最小的质数后的数各位上的数倒转。一直重复上面的过程，直到最后的质数小于10或倒转后得到比它大或相等的质数。（就是避免死循环！）最终输出到达最后一步的步数。

        思路：刚开始想这很简单，设计一个倒转函数，设计一个取最小质数的函数，然后模拟一遍，同时记录步数就可以得到答案了。倒转函数先用一个容器装好数的每一位，然后再从头开始乘10加存好的值就可以实现。取最小质数我最初想的是先用埃拉托色尼筛法然后从头比，然而时间和空间复杂度都太大，后来直接采用蛮力法，发现求最小质数总是在很小的范围内可以得到。

        但是我也遇到了麻烦，就是一直没想通最后死循环怎么跳出。我一开始的理解是不是要将倒转后的数与最开始的数比较，然而发现1729过了111没过，然后我就想到是死循环那里的问题。如果保留上一次的数呢，1729又过不了，因为中间很明显是不符合要求的，比如173->371那里。最后我突然想到，只有当原数和倒转后的数都是质数并且倒转后的数大于或等于原数才能陷入死循环，因此只要加一个原数和倒转后的数都是质数的条件就可以了。
        
    </details>
		
 	