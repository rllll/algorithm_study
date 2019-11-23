# �㷨

## <span id="content">Ŀ¼</span>

* [�㷨](#algorithm)

    * [ŷ������㷨](#gcd)

    * [������ɫ��ɸѡ��](#SieveOfEratosthens)

* [һЩ����](#jobs)

    * [Prime_Reduction](#Prime_Reduction)

### <span id="algorithm">�㷨</span>

* <span id="gcd">ŷ������㷨</span> \[ [Ŀ¼](#content) \]
  * [�ݹ�汾](gcd_recursionVersion.cpp)
  * [�ǵݹ�汾](gcd_norecursionVersion.cpp)
  
  ŷ������㷨���������������ȫΪ0�ķǸ�����m��n�����Լ�����㷨��Դ�ڹ�ϣ����ѧ�ҡ�����ɽ��۵�ŷ���������������ԭ������ŷ����ø������㷨����ǳ��򵥣�����ԭ��ȴ���Ӱ����������������ѧ�ҡ�

  ŷ������㷨�����������ظ�gcd(m, n)=gcd(n, m mod n)��ֱ��m mod n = 0����Ϊgcd(m,0)=m��m����ȡֵҲ��m��n��ֵ�����Լ����

* [<span id="SieveOfEratosthens">������ɫ��ɸѡ��</span>](SieveOfEratosthenes.cpp) \[ [Ŀ¼](#content) \]

    ��������һ�����⣺��ο��ٵ�ɸѡ�������ڸ�������n������������

    ������ɫ��ɸѡ�������ķ����ǣ��ȼ�����������Ϊ2-n����ʾ2-n���������������������δ�������ȡ��һ������Ȼ�������������������ı��������������Ѿ�û�����ֿ�����ȥ�������������е��������־�����Ҫ��Ĳ�����n������������

    ˼������ֱ���ϣ���ȡ�����ķ���ȷʵ���Կ�ܶ࣬����Ȼ�����˺ܶ���Ч�Ĳ���������6������֣��ڵ�һ��ѭ��ʱ��Ϊ2�ı��������������ڽ��еڶ���ѭ��ʱ�ֱ�3�ı���������һ�Σ��������������ֻ��ֱ�ӽ�ֵ��ֵ��0�������㷨ԭ��ĽǶ�ȷʵ��Ҫ����Ĳ�������û�и��õķ���������������أ�

    �Ż�����ɸѡ2�ı���ʱ������������ɸѡ2��2,2��3,2��4,2��5...����3ʱ������ԭ�����㷨����ɸѡ3��2,3��3,3��4,3��5...�ɲ���������3��2��ֱ�Ӵ�3��3��ʼɸ�أ����ǿ϶��ġ����ɾ��Ǵ�p��p��ʼɸ����Ϊ���Կ϶�����ʼɸp�ı���ʱ��2��p,3��p...(p-1)��pһ����֮ǰ�Ĳ�������ȥ�ˡ�����ɸѡp=5ʱ�������׿��Է���2��5,3��5�Ѿ��ֱ���ɸѡ2�ı�����3�ı����Ĺ�����ɸȥ��ʣ�µ�4��5������֪���ڽ���2��10�Ĳ�������ȥ������е����Σ���ʵ������Է��֣�4�Ѿ���һ��������Ҳ���ǿ��Բ��Ϊ��С��������2��2��ˣ����ֻ������һ����2���ͻᷢ����ʵ������ɸѡ2�ı�����


* [<span id="Seepageproblem">��̬��ͨ��</span>](Seepageproblem.cpp) \[ [Ŀ¼](#content) \]

    �㷨˼�룺<br/>
        **����������**�������������һ�������ԣ�����ÿ�������Զ���ʾһ��ĳ�����Ͷ���  
        һ��������p,q���Ա�����"p��q��������"�� �ڵõ�������������ж�һ ���¶�����<br/>���������ġ�������ⱻ��Ϊ**��̬��ͨ������**��  
		**�㷨˼��**��������ʵ���Ͽ�����ͨ�������ж���ϲ����տ�ʼ��ʱ�����еĽڵ㴦�ڹ���״̬��ÿ�õ�һ������ʱ�����ж������ڵ��Ƿ���ͬһ����ͨ������������ǣ��򽫽ڵ����ͨ�����ϲ���  
		**���ĺ���**�� find()���ҽڵ����ͨ������ʶ����connect�����ж����ڵ���ͨ�����Ƿ�һ��union���������ڵ����ͨ�����ϲ�  
		**���ݽṹ��ѡȡ**��
		<br/>������һά����洢���������Ե���Ϣ�����±���ʾ�ڵ����<br/>�õ�Ԫ�洢��ֵ��Ϊ��ͨ������ʶ�����ڳ����ʼ��ʱ�ɽ�����a[i]=i�Դﵽ�����ڵ��Ч��  
		**����ʵ��**����ʱfind���� connect����ʵ�ֽ�Ϊ�򵥣���union(p,q)����Ҫ�������齫����  
		��ͨ����Ϊa[q]�Ľڵ��Ϊa[p],ʱ�临�Ӷ�ΪO(n)  
		2����Ȼ����һά���飬���±���ʾ�ڵ���ţ����ڵ㴢��Ĳ����ǽڵ����ͨ������  
		���Ǹýڵ�ĸ��׽ڵ㣬�����߼��ϵ����ṹ��ÿ��������һ����ͨ������������a[i]=i��ʾ�ýڵ�Ϊ���ڵ���  
		a[i]Ϊ��ͨ�������ڳ����ʼ��ʱ�ɽ�����a[i]=iʹÿ���ڵ��Ϊ���Եĸ��ڵ�  
		**����ʵ��**��find����ͨ�������ҵ������ĸ��ڵ㡣connect��p,q����q�ڵ�ĸ�  
		�ڵ�����p�ڵ�ĸ��ڵ��ϡ�  
		**�Ż�**  
		��Ȩ��union���������ڵ����ٵĸ��ڵ������ڵ�����ĸ��ڵ���<br/>
		·��ѹ������find����ִ��ʱ˳�㽫�丸�׽ڵ���Ϊ�丸�׽ڵ�ĸ��׽ڵ�  
		��a[i] = a[a[i]],����������ȡ�<br/>
		![avatar](https://s2.ax1x.com/2019/10/15/KPYYSf.png)  
		**��͸����**?       
> 		��һ��N*N����ÿ��С���Ӵ���һ��site����siteΪblackʱ˵����ǰsiteΪ�رյ�
>       �Ǻ�ɫΪopen�����������ײ���site�������ӵ����󶥲������ǳ��������Ϊ��͸��
   �����ÿ��ģ����͸ʱ����������ռ����������İٷֱȡ���֪����ٷֱȽ�����ĳһ����<br/>
   ��ͨ�����ģ���������ó���  
    **�㷨˼��**:ÿ���������һ���ڵ㣬����������͸���õ��ٷֱȣ��ظ�����,ȡƽ��ֵ  
    ��Ȼ��ʱΪ��ά���󣬵���Ȼ����չ����һά���飬ֻ����Ҫͬʱ�ж��±��Ƿ�Ϸ���Ϊ  
    �˷����жϾ����Ƿ���͸���ʽ������ڵ���һ����ڵ����� �ײ��ڵ���һ��ڵ����ӡ�  
    **��������**�������ڵ�-���жϽڵ��Ƿ񱻵���-�������������ұ������Ľڵ�ϲ�-��  
    �ж��Ƿ�����͸��������ڵ���ײ���ڵ��Ƿ�������    

### <span id="jobs">һЩ����</span> \[ [Ŀ¼](#content) \]

* [<span id ="Prime_Reduction">Prime Reduction</span>](Prime_Reduction.cpp) \[ [Ŀ¼](#content) \]
* [another Prime Reduction](primereduction.cpp) \[ [Ŀ¼](#content) \]
    <details>
        <summary>Prime Reduction</summary>
        
        Problem Description

        You may know about the 3n+1 problem. If not, you may look it up on the Internet. Here's a procedure inspired by this problem:

        Step 1: Accept a natural number.

        Step 2: If the number is prime, reverse the order of the digits to get a new number, else divide it by its least prime factor and then reverse the order of the digits of the resultant to get a new number.

        Step 3: Repeat step 2 until a prime number is obtained that is less than 10 or that when reversed becomes a larger or remains the same prime number.

        Here are some examples for this procedure:

        Example A: Input = 1729

        �� 1729 is composite (7*13*19) and its least prime factor is 7.

        �� 1729/7 = 247 and hence the new number is 742 (247 reversed).

        �� 742 is composite and dividing by the least prime factor 2, we have 742/2 = 371 and hence the new number is 173.

        �� 173 is prime and hence the new number is 371 (173 reversed).

        �� 371 is composite (7*53) and we have 371/7 = 53 and reversing it, we get the new number 35.

        �� 35 is composite with the least prime factor 5; we have 35/5 = 7. Since 7 is prime and is less than 10, the procedure stops at 7 in the 5th step.

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

        ��Ŀ���⣺����һ����Ȼ������������Ȼ������������ô����λ�ϵ����ֵ�ת����������������Ƚ����������ֽ⣬Ȼ�󽫳�������������С�������������λ�ϵ�����ת��һֱ�ظ�����Ĺ��̣�ֱ����������С��10��ת��õ����������ȵ������������Ǳ�����ѭ��������������������һ���Ĳ�����

        ˼·���տ�ʼ����ܼ򵥣����һ����ת���������һ��ȡ��С�����ĺ�����Ȼ��ģ��һ�飬ͬʱ��¼�����Ϳ��Եõ����ˡ���ת��������һ������װ������ÿһλ��Ȼ���ٴ�ͷ��ʼ��10�Ӵ�õ�ֵ�Ϳ���ʵ�֡�ȡ��С�����������������ð�����ɫ��ɸ��Ȼ���ͷ�ȣ�Ȼ��ʱ��Ϳռ临�Ӷȶ�̫�󣬺���ֱ�Ӳ�������������������С���������ں�С�ķ�Χ�ڿ��Եõ���

        ������Ҳ�������鷳������һֱû��ͨ�����ѭ����ô��������һ��ʼ������ǲ���Ҫ����ת��������ʼ�����Ƚϣ�Ȼ������1729����111û����Ȼ���Ҿ��뵽����ѭ����������⡣���������һ�ε����أ�1729�ֹ����ˣ���Ϊ�м�������ǲ�����Ҫ��ģ�����173->371��������ͻȻ�뵽��ֻ�е�ԭ���͵�ת����������������ҵ�ת��������ڻ����ԭ������������ѭ�������ֻҪ��һ��ԭ���͵�ת��������������������Ϳ����ˡ�
        
    </details>
		