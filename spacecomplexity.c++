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
i)Factorial:
in the function we not only calculate the auxiliary space but also the additional recursive stack space which is taken by the function
i.e., S.C =O(Height of callstack * memory in each call)=O(n*k)
S.C = O(n)
This is the difference between the calculation of S.C for all other codes and recursive functions

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
So,no.of layers  = n and work done in each layer = k.So, S.C = O(n)

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
Here, we create a vector of size n to temporarily store the elements.So, S.C of merge function is O(n)
depth of callstack for mergesort is log n. In every level, each layer occupies n space for vector and leaves it before going to another layer.
Only,n space is occupied at a given time. So, S.C = O(log n + n). Here log n is due to Recursion and n is due to merge function.
As we ignore smaller terms and log n is very small as compared to n, Final S.C = O(n)
*/
