#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> pairsum(vector<int> arr,int target){
vector<int> ans;
   int n=arr.size();
   int i=0,j=n-1;
   while(i<j){
    int pairsum=arr[i]+arr[j];
    if(pairsum>target){
        j--;
    }
    else if(pairsum<target){
        i++;
    }
    else{
       ans.push_back(i);
       ans.push_back(j);
       return ans;
    }
   }
   return ans;
}

int main(){
    /*
    Subarray is a continuous subpart of an array
    no.of subarrays=n*(n+1)/2
    */

    int n=5;
    int arr[5]={1,2,3,4,5};

    //to print all subarrays
    for(int st=0;st<n;st++){
        for(int end=st;end<n;end++){
            for(int i=st;i<=end;i++){
              cout<<arr[i];
            }
        cout<<" ";
        }
    cout<<endl;
    }

    /*
    to find maximum sum subarray using brute force method-->time complexity=O(n2)
    i.e., finding all subarrays and finding the maximum sum among them
    */

   int maxsum=INT_MIN;
    for(int st=0;st<n;st++){
        int currentsum=0;
        for(int end=st;end<n;end++){
            currentsum+=arr[end];
            maxsum=max(maxsum,currentsum);  
        }
    }

    cout<<"Max subarray sum = "<<maxsum<<endl;

    /*
    to find maximum sum subarray using Kadane's algorithm-->time complexity=O(n)
    */

   int maxisum=INT_MIN;
   int cursum=0;
   for(int i=0;i<n;i++){
    cursum+=arr[i];
    maxisum=max(maxisum,cursum);
    if(cursum<0){
        cursum=0;
    }
   }

   int target=6;
   vector<int> v(arr, arr + n);
   vector<int> ans = pairsum(v, target);
   cout<<ans[0]<<","<<ans[1];

   /*
   kadane's algorithm -->53
   majority element -->169
   */

    return 0;
}