/*
Space Complexity:
the amount of space taken by an algorithm as function of input size(n)
generally space in a system is occupied in two ways : 1)input (arrays,int,float,string e.t.c)  2)auxiliary space (extra space reserved)
only auxiliary space is considered while calculating space complexity
example 1:if we are given an array as input and are asked to create a array containing the squares of the elements of the input array,
input space = n and auxiliary space = n. So, space complexity = O(n)
example 2:if we are given an array as input and are asked to find the sum of the elements,
input space = n and auxiliary space = constant = k. So, space complexity = O(k) which is written as O(1)

Space complexity of a recursive function:
let's consider a factorial function
in the function we not only calculate the auxiliary space but also the additional recursive stack space which is taken by the function
i.e., S.C =O(Height of callstack * memory in each call)=O(n*k)
S.C = O(n)
This is the difference between the calculation of S.C for all other codes and recursive functions
*/
