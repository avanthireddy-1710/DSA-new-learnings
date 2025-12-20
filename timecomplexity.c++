/*
Time Complexity:
Time complexity is NOT the actual time taken for a program to run but amount of time taken as function of input size(n).
It should be calculated to create better systems,better algorithms. 
Everytime worst case scenario should be considered to optimize the working.
  example: you have an array with entries 1,2,5,4,3
  in linear search,
  if your target is 1 : no.of iterations/operations required=1
  if your target is 3 : no.of iterations/operations required=5
  here, best case is when target=1 and worst case is when target=3
  if a program runs optimally in worst case,it'll definitely be optimal in all other cases possible
big O is a function in terms of n which represents time complexity of a given code/algorithm.


time complexity of a for loop is O(n) because,
a for loop graph is like y=x(y=no.of iterations & x=no.of terms input=n)
so, y=n => time complexity = O(n)


time complexity of a polynomial should be calculated as follows:
1)Set all the coefficients to 1 
2)Find the largest term
3)Time complexity = O(largest term)

example: 4n^2+3n-5
       1)n^2+n-1
       2)if n=10^5, largest term is definitely given by n^2
       3)Time Complexity = O(n^2)

in worst case scenario T.C = O -> Upper bound
in average case scenario T.C = 0 (theta)
in best case scenario T.C = omega -> Lower bound


Time Complexity in ascending order:
O(1)-->O(log n)-->O(√n)-->O(n)-->O(nlog n)-->O(n^2)-->O(n^3)-->O(2^n)-->O(n!)


Common time Complexities:
1)  O(1)-->Constant Time Complexity
mostly when there are no loops and only formulae are used. Even in loops this may be possible (calculating sum of elements of an array)
Therefore the graph plotted between no.of operations(y) and input size n(x) will be parallel to x axis

2)  O(n)-->Linear Time Complexity
i)  N factorial
int fact = 1;
for(int i = 1; i <= n; i++) {
    fact *= i;
}
ii)Kadane's algorithm
int currSum = 0, ans = INT_MIN;

for(int i = 0; i < n; i++) {
    currSum += arr[i];
    ans = max(currSum, ans);
    currSum = currSum < 0 ? 0 : currSum;
}
iii)Nth Fibonacci
for(int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
}
here all constant functions k are performed for n times inside the loop. T.C = O(n*k) but as we neglect constants --> T.C = O(n)

3)  O(n^2)
for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - i - 1; j++) {
        if(arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
        }
    }
}
here outer and inner loops run for n times each . So, T.C = O(n^2)

4)  O(n^3)
where 3 oops are involved . for example: 3D Array

5)  O(log n)
binary search:
int s = 0, e = n-1;
while(s<=e){
    int mid = s + (e - s) / 2;
    if(arr[mid] < target) s = mid + 1;
    else if(arr[mid] > target) e = mid - 1;
    else return mid;//ans
}
Here, the search space becomes half after each iteration until the required element is found out.
no.of elements=n/2^0 -->n/2^1 -->n/2^2 -->..... -->n/2^k and the element is found.The final search space =1 in the worst case
n/2^k = 1 --> n = 2^k --> k=log n (base=2) 
since the loop runs for k times, T.C = O(log n)
This T.C is same for binary trees.
This is the best T.C after O(1)

6)  O(nlog n)
for greedy algorithm,optimized sorting techniques like merge sort,quick sort(average) e.t.c
This T.C lies between O(n^2) and O(n)

7)  O(2^n) or O(3^n) or O(4^n).....---->(exponential time complexity)
mostly seen in recursions.Easily found when bruteforce approach is used in any problem.
This T.C is considered to be one of the worst T.Cs. It is worse than O(n^3)

8)  O(n!)-->not so common
for bruteforce approach of problems like n queeens , knights tour, no.of possible permutations of a string e.t.c
all of the above mentioned problems use recursions
This T.C is way more worse than the exponential T.C


Solving T.Cs of few snippets:
1)  Prime number:
for(int i=2;i*i<=n;i++){
if(n%i==0) return -1;
}
Here the loop has constant k work inside it and it runs for sqrt(√n) times. T.C = O(√n)

2)  Selection Sort:
for(int i=0;i<n-1;i++){
int min=arr[i];
for(int j=i+1;j<n;j++){
if(arr[j]<min) min=arr[j]; arr[j]=arr[i];
}
}
Here inner loop runs for n-i times per i, while the outer loop runs for n times in total
so, n+n-1+n-2+n-3+.......+1 times = (n*(n+1))/2 times. All these times, it performs a constant operation inside the loop.
So, T.C = O(n^2)
We can do this easily by considering the worst case. In the worst case(already sorted), both outer and inner loops run for approximately n times.
n*n*k---> T.C = O(n^2)

3)Recursion:
i)Factorial:
int factorial(int n){
if(n==1 ||n==0) return 1;
else return n*factorial(n-1);
}
Generally in recursion problems, we have 2 ways to find time complexity:  i)Calculating from recurrence relation  ii)no.of recursive calls*work done in each call
Finding relation and solving it is very mathematical and is not always easy for all teh problems. So, we opt for the other method
by recurrence relation:
relation: f(n)   =  k+f(n-1)
          f(n-1) =  k+f(n-2)
          f(n-2) =  k+f(n-3)
                 :
                 :
                 :
          f(2)   =  k+k2      //k2=f(1)=1
on adding all these relations, we get f(n) = k*n + k2
So,T.C = O(n)
by alternative method:
No.of calls by each recursive function = n and only constan work k is performed in the loop
So, T.C = O(n)

ii)Fibonacci:
int fib(int n){
if(n==0 || n==1) return n;
else return fib(n-1)+fib(n-2);
}
here function calling tree looks like

                                 --fib(n-3)----------------
                     --fib(n-2)--
                                 --fib(n-4)----------------
         --fib(n-1)--
                                 --fib(n-4)----------------
                     --fib(n-3)--
                                 --fib(n-5)----------------
fib(n)--
                                --fib(n-4)-----------------
                    --fib(n-3)--
                                --fib(n-5)-----------------
        --fib(n-2)--
                                --fib(n-5)-----------------
                    --fib(n-4)--
                                --fib(n-6)-----------------

We can make the last layers equal by writing fib(0)
here no.of calls in 1st layer=2^0,2nd layer=2^1,3rd layer=2^2,..........last layer=2^n-1
total no.of calls=(2^n)-1 and constant work k is done in each call
So, T.C = O(2^n)
If we don't balance the tree's last layer, T.C = O(1.618^n)
This is for bruteforce approach.If we use dynamic programming, T.C can be reduced to O(n)
From recurrence relation:
T(n) = T(n-1) + T(n-2) +O(1)

iii)Merge Sort:
void merge(int arr[], int si, int mid, int ei){
    vector<int> temp;
    int i = si, j = mid + 1;

    while (i <= mid && j <= ei){
        if (arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid){
        temp.push_back(arr[i++]);
    }

    while (j <= ei){
        temp.push_back(arr[j++]);
    }

    // copy back to original array
    for (int idx = si, x = 0; idx <= ei; idx++){
        arr[idx] = temp[x++];
    }
}

void mergeSort(int arr[], int si, int ei){
    if (si >= ei){
        return;
    }

    int mid = si + (ei - si) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);

    merge(arr, si, mid, ei);
}
inside merge function,all while loops combinedly run for n times and the for loop runs for n times.So,T.C = O(n)
for mergesort function,as it solely depends on the T.C of merge function,
f(n) calls f(n/2) and f(n/2). They both call 2 f(n/4)s each and this goes on until f(1)s are reached
no.of layers = log n
and in each call O(size) work happens i.e., in f(n)-->O(n),in second layer f(n/2) + f(n/2)-->O(n/2)+O(n/2)=O(n)
In this way, O(n) work happens in each layer. So, T.C = O(nlog n) for the function mergesort


Practical Usage:
Generally, in all coding platforms, there are size constraints for almost all problems. The system of a coding platform can perform 10^8 operations in 1 sec
and if the code written by us is not performed in that time, it means our code is too bad (not optimized).That is why sometimes codes will pass testcases but will 
not be submitted.
example: n<=10^5 constraint is given and if we use 2 loops, T.C = O(n^2) => 10^10 operations will be required which is > 10^8.This code will not be submitted

Whenever we are given the following constraints, the T.Cs which will be accepted are: (TAOs mean The above ones)
n>10^8  --> O(log n),O(1)
n<=10^8 --> TAOs + O(n)
n<=10^6 --> TAOs + O(nlog n) -->Sorting
n<=10^4 --> TAOs + O(n^2)
n<=500  --> TAOs + O(n^3)
n<=25   --> TAOs + O(2^n) -->Recursion Bruteforce
n<=12   --> TAOs + O(n!) -->Recursion Bruteforce

*/


