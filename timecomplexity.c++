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
O(1)-->O(log n)-->O(n)-->O(nlog n)-->O(n^2)-->O(n^3)-->O(2^n)-->O(n!)

Common time Complexities:
1)  O(1)-->Constant Time Complexity
mostly when there are no loops and only formulae are used. Even in loops this may be possible (calculating sum of elements of an array)
Therefore the graph plotted between no.of operations(y) and input size n(x) will be parallel to x axis
2)  O(n)-->Linear Time Complexity

*/
