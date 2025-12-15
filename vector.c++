#include<iostream>
#include<vector>//This header file is required for using vectors
//#include<bits\c++.h> is used in coding platforms
using namespace std;
int main(){
    /*
    vectors are just like arrays but we don't have to restrict the size of vector
    It will be dynamically stored.
    vectors can also be created as 
    vector<int> nameofvector --> inside <> type of elemnts should be written
    vector<int> nameofvector={1,2,3}
    vector<int> nameofvector(3,0)--> here 3 represents no.of elements and
    0 represents the value to be stored at each index
    */
   vector<int> vec={16,17,18,19,20};

    //some vector functions
    cout<<"Size= "<<vec.size()<<endl;
    vec.push_back(17);//adding 17
    vec.push_back(12);//adding 12
    vec.push_back(10);//adding 10
    cout<<"Size after pushback = "<<vec.size()<<endl;
    vec.pop_back();//deleting 10
    cout<<"Size after popback = "<<vec.size()<<endl;
    cout<<"Front most element = "<<vec.front()<<endl;//displays front element in a vector
    cout<<"Element at index 3 = "<<vec.at(3)<<endl;//displays element at a particular index

    for(int i : vec){//for each loop
        cout<<i<<endl;//Here i is not the index but the value at the index
        //i is automatically iterated
    }
    /*
    in arrays, memory is stored staticly i.e., in compile time, in stack
    in vectors, memory is stored dynamically i.e., in run time, in heap
    for example, I create an vector of size 0
    then push back an element,vector size=1 & vector capacity=1
    another pushback--> size=2 & capacity=2
    after every pushback, capacity of array doubles
    another pushback--> size=3 & capacity=4
    another pushback--> size=4 & capacity=4
    another pushback--> size=5 & capacity=8
    */
   vector<int> vec2;
   vec.push_back(0);
   vec.push_back(1);
   vec.push_back(2);
   cout<<"Size of vec2 = "<<vec2.size()<<endl;
   cout<<"Capacity of vec2 = "<<vec2.capacity()<<endl;

   /*
   n^n=0 
   n^0=n
   XOR operations in vectors are very useful
   */

    return 0;
}