# algorithm_study
学习数据结构与算法的经历

* 欧几里得算法
  * [递归版本](gcd_recursionVersion.cpp)
  * [非递归版本](gcd_norecursionVersion.cpp)
  
  欧几里得算法解决的是求两个不全为0的非负整数m和n的最大公约数。算法来源于古希腊数学家、亚历山大港的欧几里得所著《几何原本》。欧几里得给出的算法步骤非常简单，但其原理却深刻影响着历代以来的数学家。

  欧几里得算法描述：不断重复gcd(m, n)=gcd(n, m mod n)，直至m mod n = 0，因为gcd(m,0)=m，m最终取值也是m和n初值的最大公约数。

* [埃拉托色尼筛选法](SieveOfEratosthenes.cpp)

* [快速排序](quicksort.cpp)
