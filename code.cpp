//Striver's ATOZ

//1. learn the basics
//1.0 allowed tc as per constraint
>10^8 logN (base 2) or O(1)
<=10^8 n 
<=10^6 nlogn
<=10^4 n^2
<=500 n^3
<=25 2^n 
<=12 n!
//1.1 things to know

//1 For cin function if we don't type anything then it will be garbage value if we give value with multiple enter or spaces it will considered it

// int long long long float double

//2 
string str;
cin>>str;//only till space
getline(cin,str);//entire line

//3
array fixed size cant change during execution 
strings dynamic

//4
pass by val,ref and const
int arr[5] will always be passed as ref

//5 time & space complexity
1sec approx= 10^8 operations

//1.2 patterns

//1 to toggle between 0 & 1
val=1-val
val^=1

//2
('A'+j-1) = 65 (for j=1)
char('A'+j-1) = 'A'

for char '' compulsory
	"" error

//1.3 STL

//1 pair
pair<int,int> p={1,3};
to access use p.first & p.second

//2 vector
vector<int> v;//size 0
// vector<int> v(5);
v.push_back(1); //emplace_back()

//3 iterator
    vector<int> v = {2, 35, 4};// [] error
    // int arr[5] = {3,5,2,4,5};//[] err

    vector<int>::iterator it = v.begin();
    // cout<< it<<endl;//error
    cout << static_cast<void*>( &(*it) )  << endl;      // This will print the memory address of the iterator
    cout << *it << endl;     // This will print the value the iterator points to
    cout << *(it) << endl;   // This is equivalent to the above line, but parentheses are not necessary

//v.begin() first element. v.end() just after last element

//4 for each
for(int num:v){	// int or auto
	cout<<num;
}

//5 tc
.push_back(creates copy) or .emplace_back(directly create)
best O(1) , average O(1) , worst O(n) when capactity full and need to copy all elements to new vector of double size . 

//6 erase O(n) after deleting need to shift left
//delete range
    v.erase(v.begin()+2,v.begin()+4); // [start,end) end not included
//delete 1
    v.erase(v.begin()+2); 

//7 insert O(N) shifting after insert 
v.insert(v.begin(),3);//insert 3 at start
v.insert(v.begin()+1,2,10);//insert 2 10s at 1st idx
v.insert(v.begin(),v2.begin(),v2.end());//insert other vec

//8 vector functions
cout<<v.size();
cout<<v.empty();

//do not return anything
v.swap(v2);
v.clear();
v.pop_back();

//9 list - doubly linked list
list<int> myList;

// Insert elements into the list
myList.push_back(10);
myList.push_front(10);

//10 deque - double ended queue
//11 stack all operation push,pop,top in O(1)
//12 queue O(1)
//13 priority queue
priority_queue<int> pq;//largest at top
priority_queue<int, vector<int>, greater<int> >pq2;//smallest at top
push , pop in O(logN)

//14 set
sorted unique
set<int> s;
s.insert(5);
auto it=s.find(5); //will return iterator
s.count(5);//will return 1 if present else 0

//15 unordered set O(1) in average
//16 map - key,value pair
unique key in sorted order

//17 algo
sort(a,a+n);
sort(v.begin(),v.end());

//descending
sort(a,a+n,greater<int>);

//18 custom comp
//sort ascending on 2nd val if same 2nd descending 1st
bool comp(pair<int,int> p1,pair<int,int> p2){
	if(p1.second < p2.second) return 1;
	else if(p1.second > p2.second) return 0;
	else{
		return p1.first >= p2.second;
	}
}

//19 next_permutation()
The function modifies the input sequence to the next lexicographically greater permutation and returns true, or it leaves the sequence unmodified and returns false if no greater permutation is possible.

//20 *max_element()

//1.4 Basic Maths
//1 count digits
%10 /10
tc= log10(N) whenever iterations count gets divided we use log

//2 count digits of num which divides the num evenly(i.e num%dig ==0)
int countDigits(int n){
	// Write your code here.
	int c=0;
	int temp=n;
	while(temp){
		int dig=temp%10;
		if(dig && n%dig == 0) c++;//missed to check if dig is 0
		temp/=10;
	}
	return c;	
}

//3 reverse bits
long reverseBits(long n) {
    // Write your code here.
    long ans=0;
    for(int i=0;n && i<32;i++){
        if(n%2){    //or n&1
            long mask=(1ll<<(31-i));    //missed 1ll
            ans^=mask;  //or ans|=mask or ans+=mask
        }
        n/=2;   //or n>>=1
    }
    return ans;
}
//tc O(1) fixed 32 times max

//4 reverse number
	int ans=0;
	while(n){
		int dig=n%10;
		ans=ans*10 + dig;

		n/=10;
	}


//5 sumofalldivisors

//O(N)
int sumOfAllDivisors(int n){
	// Write your code here.	
	int ans=0;
	for(int i=1;i<=n;i++){
		// cout<<i<<" "<<n/i<<endl;
		ans+=n/i*i;
	}
	return ans;
}

//pending
/*
    Time Complexity: O(sqrt(n))

    Space Complexity: O(1)

    Where 'n' is the given integer.
*/

int sumOfAllDivisors(int n)
{
    int ans = 0;
    int l = 1;

    // Iterating over all values of 'l' such that 'n/l' is distinct.
    // There at most 2*sqrt(n) such values.
    while (l <= n)
    {
        int val = n / l;

        // 'r' = maximum value of 'i' such that 'n/i' is val.
        int r = n / val;

        ans += ((r * (r + 1)) / 2 - (l * (l - 1)) / 2) * val;

        // moving on to next range.
        l = r + 1;
    }

    return ans;
}

//1.5 Basic Recursion
function calls itself till a specified condition

recursion tree

//1 return a vector with 1 to n nums
vector<int> printNos(int x) {
    // Write Your Code Here
    if(x<1) return {};
    vector<int> v=printNos(x-1);
    v.push_back(x);
    return v;
}

//a2
pass x and &vector as arg

//2
long long sumFirstN(long long n) {
    // Write your code here.

    // if(n==1) return 1;
    // return n + sumFirstN(n-1);	//using recursion

    return n*(n+1)/2;
}

//3 isPalindrome using recursion
bool f(int i,int n,string &s){
    if(i==n/2) return 1;

    if(s[i] != s[n-1-i]) return false;

    return f(i+1,n,s);
}

bool isPalindrome(string& str) {
    // Write your code here.
    int n=str.size();
    return f(0,n,str);
}

//4
1 to n
n to 1
sum of first n
factorial
reverse an array
fibonacci

//1.6 Basic Hashing
//pre calculate and fetch

//1 countFrequency of elements from 1 to n(size of vec)
vector<int> countFrequency(int n, int x, vector<int> &nums){
    // Write your code here.
    vector<int> v(n,0);
    for(int val:nums){
        if(val<=n){
            v[val-1]++;
        }
    }
    return v;
}

//a2 O(1) space pending
vector<int> countFrequency(int n, int x, vector<int> &nums)
{
    // Iterate through the array and modify the elements to track the frequency.
    int i = 0;
    while (i < n)
    {
        // Skip the element if it is not within our range.
        if (nums[i] > n || nums[i] < 1)
        {
            i++;
            continue;
        }

        // Calculate the index of the element.
        int j = nums[i] - 1;

        // Update the frequencies.
        if (nums[j] < 0)
        {
            nums[i] = 0;
            nums[j]--;
            i++;
            continue;
        }
        else
        {
            swap(nums[j], nums[i]);
            nums[j] = -1;
        }
    }

    // Adjust the negative values to positive frequencies.
    for (int &x : nums)
    {
        if (x < 0)
            x *= -1;
        else
            x = 0;
    }

    // Return the array with frequencies.
    return nums;
}

//2 get highest & lowest frequency elements
	//if tie select lower element
	//atleast 2 distinct ele present
vector<int> getFrequencies(vector<int>& v) {
    // Write Your Code Here
    unordered_map<int,int> um;
    for(int val:v){
        um[val]++;
    }

    int lnum=-1,lfre=v.size(),hnum=-1,hfre=0;

    for(auto p:um){
        if(p.second < lfre){
            lfre=p.second;
            lnum=p.first;
        }else if(p.second == lfre){ //if we had taken map no need to check this as keys will be sorted 
                // to update freq<lfre
            lnum=min(lnum,p.first);
        }

        if(p.second > hfre){
            hfre=p.second;
            hnum=p.first;
        }else if(p.second == hfre){ //if map no need of this
            hnum=min(hnum,p.first);
        }
    }

    return {hnum,lnum};
}

//3 max size array
int (inside main) 10^6 , bool 10^7
int (global) 10^7 , bool 10^8

//4
int freq[26]={0};

freq['z'-'a']++;//freq[122-97]=freq[25]

//2. Sorting

//2.1 sorting-1
//1 selection sort
select min and swap it with current position
max 1 swap in 1 iteration
tc O(N^2) sc O(1)

void selectionSort(vector<int>&arr) {
    // Write your code here.
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int minidx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minidx]) minidx=j;
        }
        swap(arr[i],arr[minidx]);
    }
}

//2 bubble sort
after 1st iteration max element will be at last by alternate swaps
tc O(n^2) average & worst, O(N) best case when no swaps performed 
sc O(1)

void bubbleSort(vector<int>& arr, int n) 
{
    //write your code here
    for(int i=0;i<n-1;i++){

        bool sorted = true;
        
        for(int j=0;j<n-1-i;j++){

            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                sorted = false;
            }
        }

        if(sorted) break;
    }
}

//3 insertion sort (insert unsorted element into sorted like arranging cards)
tc O(n^2) except best O(N)
sc O(1)

for(int i=1;i<n;i++){
    for(int j=i-1;j>=0;j--){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            
        }else break;
    }
}

//a2
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//2.2 sorting-2

//1 merge sort
#include <bits/stdc++.h>
using namespace std;


void merge(int arr[],int l,int m,int r){
    int n1=m-l+1, n2=r-m;

    vector<int> L(n1), R(n2);

    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=arr[m+1+i];
    }

    int i=0,j=0,k=l;

    while(i<n1 && j<n2){
        if(L[i]>R[j]){
            arr[k++]=R[j++];
        }else{
            arr[k++]=L[i++];
        }
    }
    while(i<n1 ){
        
        arr[k++]=L[i++];
        
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
}

void mergeSort(int arr[], int l, int r) {
    // Write Your Code Here
    if(l>=r) return;

    int m=(l+r)/2;	//or l+(r-l)/2

    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    merge(arr,l,m,r);
}

//tc O(nlogn) , sc O(n)

//2 quick sort
int partitionArray(int input[], int start, int end) {
	// Write your code here
	int pele = input[end];

	for(int j=start;j<end;j++){
		if(input[j]<pele){
			swap(input[start++],input[j]);
		}
	}

	swap(input[start],input[end]);

	return start;
}

void quickSort(int input[], int start, int end) {
	
	if(start>=end) return;

	int pidx = partitionArray(input, start, end);

	quickSort(input, start, pidx-1);
	quickSort(input, pidx+1, end);
}

//tc O(nlogn) average , O(n^2) worst
//sc O(logn) avg , O(n) worst

//3. Arrays

//3.1 easy

//1 second largest and second smallest
sorting will take nlogn
to do in O(N)
//first itr find lar and sma
//second itr seclar & secsmal
if(x>seclar && x!=lar) seclar=x;

//2 remove dups
i=0,j=1
move j from 1 to end if new ele 
arr[++i] = arr[j]

//3 left rotate by 1

//new array O(n)

//store 1st element and rotate O(1)

//4 left rotate by k
//a1 tc O(n*k) sc O(1)
rotate 1 for k times

//a2 tc O(n) sc O(n)
vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.
    int n=arr.size();
    // k%=n;
    // if(k<0) k+=n;
    // if(k==0) return arr;

    vector<int> ans(n);

    for(int i=k;i<n;i++){
        ans[i-k] = arr[i];
    }

    for(int i=0;i<k;i++){
        ans[n-k+i] = arr[i];
    }

    return ans;
}
// OR
    for(int i=0;i<n;i++){
        ans[(i-k+n)%n] = arr[i];
    }

//5 move zeros to end
//a1 without considering order
vector<int> moveZeros(int n, vector<int> a) {
    // Write your code here.
    int i=0,j=n-1;
    while(i<j){
        if(a[i]>0) i++;
        else if(a[j]==0) j--;
        else {
            swap(a[i++],a[j--]);
        }
    }
    return a;
}


//a2 keeping original order
vector<int> moveZeros(int n, vector<int> a) {
    // Write your code here.
    int i=0;
    for(int j=0;j<n;j++){
        if(a[j]){
            a[i++]=a[j];
        }
    }

    // for(int k=i;k<n;k++){
    //     a[k]=0;
    // }

    while(i<n){
        a[i++]=0;
    }

    return a;

}

//6 merge two sorted arrays. result must be sorted and unique
//a1 set tc O((n+m)*log(n+m)) sc O(n+m)

//a2 using two ptr
	//tc O(n+m) sc O(n+m)
vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    int n1=a.size(),n2=b.size();

    int i=0,j=0;

    vector<int> ans;

    while(i<n1 && j<n2){
        if(a[i]>b[j]){
            if(ans.empty() || b[j] != ans.back()){
                ans.push_back(b[j]);
            }
            j++;
        }else{
            if(ans.empty() || a[i] != ans.back()){
                ans.push_back(a[i]);
            }
            if(a[i] == b[j]) j++;
            i++;
        }
    }

    while(i<n1 ){
        
        if(ans.empty() || a[i] != ans.back()){
            ans.push_back(a[i]);
        }
        i++;
        
    }

    while(j<n2){
        
        if(ans.empty() || b[j] != ans.back()){
            ans.push_back(b[j]);
        }
        j++;
        
    }

    return ans;
}

//7 find missing in array
//a1 xor
//a2 sum
//a3 binary search (use if sorted)

//8 max consecutive 1s with m flips
int traffic(int n, int m, vector<int> vehicle) {
	// Write your code here.
	int ans=0;

	int i=0;

	for(int j=0;j<n;j++){
		if(vehicle[j] == 0){
			m--;
		}

		while(m<0 ){
			if(vehicle[i] == 0) m++;
			i++;
		}

		ans=max(ans,j-i+1);
	}

	return ans;
}

//9 Find one number that appears once in a sorted where the rest are present twice
//a1 tc O(n)
if(arr[i] != next or prev) return it.
special check for 1st & last

//OR
    for(int i=0;i<n-1;i=i+2){   //missed i+2
        if(arr[i] != arr[i+1]) return arr[i];
    }

    return arr[n-1];

//a2 O(logn)
#include<vector>

int getSingleElement(vector<int> &arr){
    // Write your code here.
    int n=arr.size();

    if(n==1) return arr[0];

    int i=0,j=n-1;
    while(i<j){
        int mid=(i+j)/2;

        if(mid%2){
            if(arr[mid] == arr[mid-1]){
                i=mid+1;
            }else{
                j=mid;
            }
        }else{
            // cout<<mid<<" is mid\n";

            if(arr[mid] == arr[mid+1]){
                i=mid+2;
            }else{
                j=mid;
            }
        }

    }   
    return arr[i];
}

//OR
    int i=0,j=n-1;

    while(i<j){
        int mid=(i+j)/2;

        if(mid%2) mid--;

        if(arr[mid] != arr[mid+1]){
            j=mid;
        }else i=mid+2;
    }

    return arr[i];

//a3 xor

//10 Longest Subarray With Sum K (non negative)
two pointer

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();

    long long s=0;

    int i=0,j=0,ansmax=0;

    for(;j<n;j++){
        s+=a[j];

        while(s>k){
            s-=a[i++];
        }

        if(s==k){
            ansmax=max(ansmax,j-i+1);
        }
    }

    return ansmax;
}

//11 Longest Subarray With Sum K (including negative)

int getLongestSubarray(vector<int>& a, int k){
    // Write your code here
    int n=a.size();

    unordered_map<int,int> um; // sum vs sum till idx

    int ansmax=0;

    int i=0,j=0,cursum=0;

    um[0]=-1;

    for(;j<n;j++){
        cursum += a[j];

        // if(cursum == k){
        //     ansmax=max(ansmax,j+1);
        // }   //to skip this um[0]=-1;

        int req = cursum - k;   //incorrect k-cursum

        if(um.find(req) != um.end()){
            ansmax=max(ansmax,j-um[req]);
        }

        if(um.find(cursum) == um.end()){
            um[cursum] = j;
        }
    }

    return ansmax;
}

//3.2 medium
//1 two sum
    //Sum of any two number should be equal to the target sum In unsorted array

//a1 sort O(nlogn) then 2 ptr one at start and other at end
//a2 unordered_set to store elements occured before O(n) to traverse O(1) to store and retrieve in unordered_set

//2 sort 0 1 2
    int i=0,j=0,k=n-1;
    //before i all 1, after k all 2

    while(j<=k){
        if(arr[j] == 0)         swap(arr[i++],arr[j++]);
        else if(arr[j] == 1)    j++;
        else                    swap(arr[j],arr[k--]);
    }

//3 majority element
    //a1 sc O(n) using map
    //a2 sc O(1) MOORE'S VOTING ALGORITHM
int majorityElement(vector<int> v) {
    // Write your code here
    int n=v.size(), ans, count=0;
    for(auto x:v){
        if(count){
            if(x == ans) count++;
            else count--;
        }else{
            ans=x;
            count++;
        }
    }
    //check candidate ans has freq>n/2
    //no need to check if given that array has a majority element
    return ans;
}

//4 maxSubarraySum
long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long ansmax=0, pre=0;  //ansmax=0 since empty subarray allowed

    for(int i=0;i<n;i++){
        pre+=arr[i];
        if(pre>ansmax) ansmax=pre;
        if(pre<0) pre=0;
    }

    return ansmax;
}

//5 print max sum subarray
long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long ansmax=0, pre=0;  //ansmax=0 since empty subarray allowed

    int si=0,ei=-1,finalStartIdx=0;

    for(int i=0;i<n;i++){
        pre+=arr[i];
        if(pre>ansmax){
            ansmax=pre;
            ei=i;
            finalStartIdx=si;
        }
        if (pre < 0) {
            pre = 0;
            si=i+1;
        }
    }

    // cout<<si<<endl;
    // cout<<finalStartIdx<<endl;
    // cout<<ei<<endl;

    // if(ei == -1){
    //     //all negative element so
    //     // max sum subarray will be max element
    // }


    return ansmax;
}

//6 Best time to buy and sell stock
keep track of lowestTillNow and find profit for each day then store maxProfit

//7 Alternate Numbers + - + -
pos=0, neg=1;
if(a[i]>0) ans[pos]=a[i];
pos+=2;

//8 next permutation
//steps
find increaseIdx
find swap idx
reverse from increaseIdx+1

29851
2 has element greater than it on right. 
the element just greater than 2 is 5 to the right. 
swap with 5 and then reverse after 2s idx

//code
void rev(vector<int> &v,int st,int en){
    while(st<en){
        swap(v[st++],v[en--]);
    }
}

vector<int> nextGreaterPermutation(vector<int> &A) {
    // Write your code here.
    int n=A.size();
    //find increaseIdx
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            //find swap idx
            int j;
            for( j=i+1;j<n;){
              if (A[j] > A[i]) {
                  j++;
                  
              }else{
                  break;    //missed
              }
              
            }
            swap(A[j-1],A[i]);

            //reverse from increaseIdx+1
            rev(A,i+1,n-1);//or reverse(A.begin()+i+1,A.end())

            return A;

        }
    }

    //if increaseIdx = -1 means highest num cant get next per so reverse to get lowest
    rev(A,0,n-1);

    return A;
    
    
}

//9 longest Successive Elements
int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    unordered_set<int> us;
    for(auto x:a) us.insert(x);

    int ans=0, curans=0;
    for(int x:us){
        //can it be the start
        if(us.find(x-1) == us.end()){
            curans=1;
            while(us.find(x+1) != us.end()){
                curans++;
                x++;
            }
            ans=max(ans,curans);
        }
    }
    return ans;
}
//tc O(n) since everyone wont be startele

//a2 sorting tc O(nlogn)
int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    sort(a.begin(),a.end());
    int ans=0,curans=1;

    int  n=a.size();

    for(int i=1;i<n;i++){
        if(a[i] != a[i-1]){
            if(a[i] == a[i-1]+1){
                curans++;
            }else{

                ans=max(ans,curans);
                curans=1;
            }
        }
    }
    ans=max(ans,curans);

    return ans;
}
//10 set matrix 0
//a1 use 2 vector to note which rows&cols to make 0
//a2 use 1st row 1st col and col variable to keep track what to make 0

//11 rotate the matrix 90deg clockwise
    //think about each element , then each row

    //transpose
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){   //only till less than i, else you swap twice and it remains as og
            swap(mat[i][j],mat[j][i]);
        }
    }

    //reverse each row
    for(int j=0;j<n;j++){
        for(int i=0;i<n/2;i++){
            swap(mat[j][i],mat[j][n-1-i]);
        }
    }

//12 spiralMatrix
    //a1 using direction matrix
vector<int> spiralMatrix(vector<vector<int>>&MATRIX) {
    // Write your code here.
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    // int dir[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int n=MATRIX.size(), m=MATRIX[0].size();

    vector<int> steps = {m,n-1};//You are standing at 0 -1 how many steps you can go right and how many steps you can go down
    vector<int> ans;

    int stepIdx=0, dirIdx=0, x=0, y=-1;//We can control step index based on direction index by using direction modulus 2

    while(true){
        int curSteps = steps[stepIdx];
        if(curSteps<1) break;

        int dx=dir[dirIdx][0];
        int dy=dir[dirIdx][1];

        while(curSteps--){
            x+=dx;
            y+=dy;
            ans.push_back(MATRIX[x][y]);
        }

        steps[stepIdx]--;
        stepIdx=(stepIdx+1)%2;
        dirIdx=(dirIdx+1)%4;
    }

    return ans;
}

    //a2 using boundaries right,down,left,up

//13 find count of All Subarrays With given Sum
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    // Write Your Code Here
    unordered_map<int,int> um;
    um[0]=1;

    int cur=0, n=arr.size(), ans=0;
    for(int i=0;i<n;i++){
        cur+=arr[i];

        int rem=cur-k;//if we need 6: if cur is 10 we look for (10-6=4) prev count
        ans+=um[rem];

        um[cur]++;
    }
    return ans;
}

//3.3 Hard
//1 pascalTriangle
vector<vector<int>> pascalTriangle(int N) {
    // Write your code here.
    vector<vector<int>> ans;
    for(int i=1;i<=N;i++){
        vector<int> v;

        int cur=1;
        v.push_back(cur);
        for(int j=1;j<i;j++){
            cur=cur*(i-j)/(j);
            v.push_back(cur);
        }

        ans.push_back(v);


    }
    return ans;
}
//a2
vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> triangle(N);

    for (int i = 0; i < N; i++) {
        triangle[i].resize(i + 1);

        // Mark the edges as 1.
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle;
}

//2 majority2 >n/3
if(e==x1) c1++;
else if(e==x2) c2++;
else if(c1==0) x1=e,c1=1;
else if(c2==0) x2=e,c2=1;
else c1--;c2--;

//3 3sum
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.  [-1, -1, 2, 0, 1] 
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;

    for(int i=0;i<n-2;i++){
        if(arr[i]>0) break;//start cant be +ve and end cant be -ve
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j=i+1,k=n-1;
        int tar=-arr[i];

        while(j<k){
            int cur=arr[j]+arr[k];

            if(cur == tar){
                ans.push_back({arr[i],arr[j],arr[k]});
                while(j<k && arr[j]==arr[j+1]) j++;
                while(j<k && arr[k]==arr[k-1]) k--;
                j++;
                k--;
            }else if(cur>tar){
                while(j<k && arr[k]==arr[k-1]) k--;
                k--;
            }else{
                while(j<k && arr[j]==arr[j+1]) j++;
                j++;
            }
        }
    }

    return ans;
}

//4 4sum
fix i(0 to <n-3 ) ,then j(i+1 to <n-2) then extremes k(j+1) & l(n-1)

//5 Longest Subarray With Zero Sum
// keep track of prefix sum and check if same sum occured in past
// Prefix till index 2 is 10 and prefix index 5 is also 10 that means sum of subarray from index 3 to 5 is zero
// As we want the longest separation Store the lowest index at which the sum has occurred do not modify if the same sum occurred for example prefix sum of at index 2 is 5 and at index 4 is also 5 then keep storing index 2
    
    unordered_map<int,int> um;//prevsum vs at which idx

//6 count  Subarrays with XOR ‘K’
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int ansCount=0, n=a.size() , pre=0;
    unordered_map<int,int> um;//prevXor vs count
    um[0]=1;
    for(int i=0;i<n;i++){
        pre^=a[i];

        int toFind=pre^b;
        ansCount+=um[toFind];

        um[pre]++;
    }
    return ansCount;
}

//7 mergeOverlappingIntervals
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
    // Write your code here.
    sort(arr.begin(),arr.end());

    vector<vector<int>> ans;

    ans.push_back(arr[0]);

    int n=arr.size();

    for(int i=1;i<n;i++){
        int lastEnd=ans.back()[1];
        if( lastEnd >= arr[i][0]){
            ans.back()[1]= max(lastEnd,arr[i][1]);
        }else{
            ans.push_back(arr[i]);
        }
    }

    return ans;
    
}

/*
bool compareSecondElement(const std::vector<int>& a, const std::vector<int>& b) {
    return a[1] < b[1]; // Sort based on the second element
}
*/

//8 merge Two Sorted Arrays Without ExtraSpace
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
    // Write your code here.
    int n1=a.size(), n2=b.size();

    int i=n1-1, j=0;

    while(i>=0 && j<n2){    //check if highest of a is less than b then task done
        if(a[i]>b[j]){
            swap(a[i--],b[j++]);
        }else break;
    }

    if(i == n1-1) return;//no swaps

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    return;
    
}

//9 findMissingRepeatingNumbers

    s=s-1ll*(n)*(n+1)/2; // sumOfArr - sumOf1toN = r-m
    s2=s2-1ll*(n)*(n+1)*(2*n+1)/6;//r^2-m^2;

    s2/=s;//r+m

    r=(s+s2)/2;
    m=r-s;

//10 Count inversions PTC
its easy to count while merging 2 sorted arrays 
//11 Count reverse pairs PTC
its easy to count while merging 2 sorted arrays 

//12 Find maximum product subarray
//a1
int subarrayWithMaxProduct(vector<int> &arr){
    // Write your code here.
    int maxi=arr[0], mini=arr[0], ans=arr[0];

    int n=arr.size();

    for(int i=1;i<n;i++){
        if(arr[i] < 0) swap(maxi,mini);

        maxi=max(arr[i],arr[i]*maxi);
        mini=min(arr[i],arr[i]*mini);

        ans=max(ans,maxi);
    }

    return ans;
}
//a2 keep track of max prefix and suffix 
// 2 -1 3 -6 -5 0 4 -8 -3 -1
    //0s will divide into subproblems
int subarrayWithMaxProduct(vector<int> &arr){
    // Write your code here.
    int ans=0;

    int pre=1, suf=1, n=arr.size();

    for(int i=0;i<n;i++){
        pre*=arr[i];
        suf*=arr[n-1-i];

        int maxi=max(pre,suf);
        ans=max(ans,maxi);

        pre= pre==0?1:pre;
        suf= suf==0?1:suf;
    }

    return ans;
}

//4 Binary Search
//4.1 bs on 1d array

//1 lower bound 
smallest idx where arr[idx] not less than element 
first idx where arr[idx] >= element

//2 upper bound
idx of first element of array which is greater than x

//3 search in rotated sorted array 
// One of the half will be sorted if the element doesn't lies in that half discard that half,  else if element lies in that half discard the other half

//4 Search in rotated sorted array with duplicate 
// Check if the mid element is equal to lower and higher 
// If this mid is not equal to required element then skip the lower and higher element

//4.2 bs on answers
//1 floor sqrt
int floorSqrt(int n)
{
    // Write your code here.
    int i=0, j=n,ans=0;
    while(i<=j){
        int mid=i+(j-i)/2;

        if(1ll*mid*mid < n) {   //or        if(mid < n/mid) {
            //missed if n==0
            ans=mid;
            i=mid+1;
        }
        else if(1ll*mid*mid > n) j=mid-1;
        else return mid;
    }

    return ans;
}
    //to find exact square root hi-low>=1e5

//2 minimumRateToEatBananas
    /*
    Monotonic functions ffffttt or tttfffff
Is able to eat at the speed of 3 bananas then also possible to eat at any higher speed 
If not able to eat at speed of 3 then won't be able to eat at any lower speed like at speed of 2 or 1
*/
bool isPossible(vector<int> &v,int h,int mid){
    int currentHours=0;
    for(int x:v){
        currentHours+=(x+mid-1)/mid;

        if(currentHours>h) return 0;
    }
    return 1;
}
//tc O(N*logM) where M is searchspace maxi-1
int minimumRateToEatBananas(vector<int> v, int h) {
    // Write Your Code Here
    int maxi=v[0];
    for(auto x:v) maxi=max(maxi,x);
    // int maxi2=*max_element(v.begin(),v.end());
    int low=1, high= maxi, mid, ans=-1;//or high=1e9
    while(low<=high){   //log(searchSpace)
        mid=(low)+(high-low)/2;

        if(isPossible(v,h,mid)){    //O(N)
            ans=mid;
            high=mid-1;
        }else low=mid+1;
    }

    return ans;
  
}

//3
//isPossible to make m bouquets of k consecutive flowers in mid days

//a1
bool isPossible(vector<int> &arr, int k, int m, int mid){
    int count=0, n=arr.size();
    for(int i=0;i<=n-k;i++){
        int flag=1;
        for(int j=i;j<i+k;j++){
            if(arr[j]>mid){
                flag=0;
                break;
            }
        }
        if(flag){
            count++;
            if(count==m) return 1;
            i+=k-1;
            
        }
    }
    return 0;
}

//a2 
bool isPossible(vector<int> &arr, int k, int m, int mid){
    int count=0, n=arr.size(), adjacent=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=mid) adjacent++;
        else adjacent=0;

        if(adjacent==k){
            count++;
            if(count==m) return 1;
            adjacent=0;
        }
    }
    return 0;
}

int roseGarden(vector<int> arr, int k, int m)
{
    // Write your code here
    int n=arr.size();
    if(k*m>n) return -1;

    int low=1, high=*max_element(arr.begin(),arr.end()), mid, ans=high;

    while(low<=high){
        mid=(low)+(high-low)/2;

        // cout<<mid<<" ";

        if(isPossible(arr,k,m,mid)){
            ans=mid;
            high=mid-1;
        }else low=mid+1;

        // cout<<ans<<endl;
    }
    return ans;
}

//4
bool isPossible(vector<int> &weights, int d, int capacity){
    int currentDays=1, currentLoad=0;
    for(int weight:weights){
        if(weight>capacity) return 0;

        currentLoad+=weight;

        if(currentLoad>capacity){
            currentDays++;
            if(currentDays>d) return 0;
            currentLoad=weight;
        }
    }

    return 1;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    // Write your code here.
    int sum=0;
    for(auto x:weights) sum+=x;

    if(d==1) return sum;

    int low=1, high=sum, mid, ans=-1;//or low=min & high=sum
    while(low<=high){
        mid=low+(high-low)/2;

        if(isPossible(weights,d,mid)){
            ans=mid;
            high=mid-1;
        }else low=mid+1;
    }

    return ans;
}

//5 Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized.
    int low=0, high=sum, mid, ans=-1;//or low=sum/k & high=sum

//6
int numberOfGasStationsRequired( double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    // cout<<cnt<<endl;
    return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
     double low = 0;
     double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, ( double)(arr[i + 1] - arr[i]));
    }
    //or high=1e9
    
    //Apply Binary search:
     double diff = 1e-6 ;
    while (high - low > diff) {
         double mid = (low + high) / (2.0);
        // cout<<mid<<" ";
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    // cout<<high<<endl;
    return (double)high;
}

//7 median of 2 sorted array
double median(vector<int>& a, vector<int>& b) {
    // Write your code here.
    int n1=a.size(), n2=b.size();
    if(n1>n2) return median(b, a);

    int total=n1+n2;
    int left=(total+1)/2 , right=total-left;

    int low=0, high=n1, mid;
    while(low<=high){
        mid=low+(high-low)/2;

        int cut1=mid, cut2=left-cut1;

        int l1=cut1==0? INT_MIN : a[cut1-1];
        int l2=cut2==0? INT_MIN : b[cut2-1];

        int r1=cut1==n1? INT_MAX : a[cut1];
        int r2=cut2==n2? INT_MAX : b[cut2];
        
        if(l1>r2) high=mid-1;
        else if(l2>r1) low=mid+1;
        else {
            if(total%2) return max(l1,l2);
            return (max(l1,l2)+min(r1,r2))/2.0;
        }
    }

    return 0.0;
}

//8 kthElement after merging 2 sorted array
#include <bits/stdc++.h>
using namespace std;
int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k){
    
    if(n1>n2) return kthElement(b, a, n2, n1, k);

    int total=n1+n2;
    int left=k , right=total-k;

    int low=max(0,k-n2), high=min(k,n1), mid;
    while(low<=high){
        mid=low+(high-low)/2;

        int cut1=mid, cut2=left-cut1;

        int l1=cut1==0? INT_MIN : a[cut1-1];
        int l2=cut2==0? INT_MIN : b[cut2-1];

        int r1=cut1==n1? INT_MAX : a[cut1];
        int r2=cut2==n2? INT_MAX : b[cut2];

        if(l1>r2) high=mid-1;
        else if(l2>r1) low=mid+1;
        else {
            return max(l1,l2);
        }
    }

    return 0.0;
}

//4.3 bs on 2d
//1
vector<int> findPeakGrid(vector<vector<int>> &g){
    // Write your code here.   
    int rows=g.size(), cols=g[0].size();
    // vector<int> ans;
    int i=0,j=0;
    while(true){
        if(j>0 && g[i][j-1]>g[i][j]) j--;
        else if(i>0 && g[i-1][j]>g[i][j]) i--;
        else if(i<rows-1 && g[i+1][j]>g[i][j]) i++;
        else if(j<cols-1 && g[i][j+1]>g[i][j]) j++;
        else return {i,j};
    }
    return {}; 
}

//2 median in row wise sorted array
bool isPossible(vector<vector<int>> &matrix, int m, int n, int mid){
    int count=0;
    for(int i=0;i<m;i++){
        int low=0, high=n-1, middle,ans=-1;
        while(low<=high){
            middle=low+(high-low)/2;
            if(matrix[i][middle]>mid){
                high=middle-1;
            }else{
                ans=middle;
                low=middle+1;
            }
        }
        count+=ans+1;
    }
    return count>(m*n)/2;//condition for element to be median
}

int median(vector<vector<int>> &matrix, int m, int n) {
    // Write your code here.
    int low=1, high=1e9, mid, ans=-1;
    while(low<=high){
        mid=low+(high-low)/2;

        if(isPossible(matrix,m,n,mid)){
            ans=mid;
            high=mid-1;//check for smaller as we want lowest element with count>=m*n/2
        }else low=mid+1;
    }
    return ans;
}

//5 Strings
//5.1 easy
//1 largestOddNumber substring
class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        for(int i=n-1;i>=0;i--){
            int val=num[i]-'0';//or num[i]
                //'0' is 48
            if(val%2){
                return num.substr(0,i+1);
            }
        }

        return "";
    }
};

//2 
    //  kam  al  vino  
    //vino al kam
//(no leading or trailing on inbetween extra spaces)
string reverseString(string &str){
    // Write your code here.
    if(str=="" || str==" ") return str;
    string ans;
    int n=str.size();

    for(int i=0;i<n;i++){
        if(str[i] != ' '){
            int j;
            for(j=i+1;j<n;j++){
                if(str[j] == ' ') break;
            }
            string word=str.substr(i,j-i+1);
            // reverse(word.begin(),word.end());
            // ans+=word+" ";

            if(ans == "") ans=word;
            else ans=word+" "+ans;
            
            i=j;
        }
    }   

    // if(ans == "") return ans;

    // reverse(ans.begin(),ans.end());

    // return ans.substr(1);

    return ans;
}
//3 largest odd number
for largest odd number the string should end at an odd number 
To get the biggest substring we can start from index zero and end at the right most odd place 
So check from right to left and if we find an odd character then returns substring from start to that odd character

//4 longest prefix
First find the length of shortest string in the array 
The answer can be zero to the length of this shortest string 
Start checking the ith character of every string matches with the ith character of first string 
// If it doesn't match return substring from 0 to that index

//a2
Sort the given strings 
Search for common prefix in first and last string as on sorting these are the two strings that have least matching 
So if they match then all the rest in between also match

//5
bool areIsomorphic(string &str1, string &str2)
{
    // Write your code here
    int n1=str1.size(), n2=str2.size();
    if(n1!=n2) return 0;

    unordered_map<char,char> um;//char from s2 mapped to char from s1
    unordered_set<char> us;//store all s1 mapped
    for(int i=0;i<n2;i++){
        char c=str2[i];
        if(um.find(c) == um.end()){
            um[c]=str1[i];
            if(us.find(str1[i]) != us.end()) return 0;
            us.insert(str1[i]);
        }else{
            if(um[c] != str1[i]) return 0;
        }
    } 
    return 1;
}
//xxy aab
//xxx aab
//xxy aaa

//6 isCyclicRotation
//a1 tle
bool same(string &p, string &q,int i,int n){
    for(int j=0;j<n;j++){
        if(q[j] != p[(i+j)%n]) return 0;
    }
    return 1;
} 
    //Check if string P from ith index can match with string q from zero index
int isCyclicRotation(string &p, string &q) 
{
    // Write your code here
    int n=p.size();
    for(int i=0;i<n;i++){
        if(p[i] != q[0]) continue;
        if(same(p,q,i,n)){
            return 1;
        }
    }
    return 0;
}

//a2 tle
int isCyclicRotation(string &p, string &q) 
{
    // Write your code here
    int n=p.size();
    for(int i=0;i<n;i++){
        if(p[i] != q[0]) continue;
        string match=p.substr(i)+p.substr(0,i);
        if(match == q) return 1;
    }
    return 0;
}
//a3 tle
store all rotations of p in set and check if q present in any form 

//a4 49/50 
    //to get 50 use kmp algo while searching q in p+p
int isCyclicRotation(string &p, string &q) 
{
    // Write your code here
    p+=p;
    if(p.find(q) != string::npos) return 1;
    return 0;
}

//7
bool isAnagram(string str1, string str2)
{
    //Write your code here
    if(str1.size() != str2.size()) return 0;
    vector<int> f(256);
    for(auto x:str1) f[x]++;

    for(auto x:str2){
        if(f[x]==0) return 0;
        f[x]--;
    }
    return 1;
}

//a2
    if(str1.size() != str2.size()) return 0;
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    return (str1==str2);

//5.2 medium

str.append(times,character);
//1 
int romanToInt(string s) {
    // Write your code here
    unordered_map<char,int> um = {
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
    };//char vs val

    int ans=0 ,prev=0,n=s.size();

    for(int i=n-1;i>=0;i--){
        char c=s[i];
        int val=um[c];
        if(val>=prev){
            ans+=val;
            
        }else{
            ans-=val;   // IX 10-1 OR IV 5-1
        }
        prev=val;
    }
    return ans;
}

//2
//a1
int createAtoi(string s) {
    // Write your code here.
    int n=s.size(),i;
    for(i=0;i<n;i++){
        if(s[i] != ' ') break;
    }
    if(i==n) return 0;

    s=s.substr(i);

    long long ans=0, flag=1,finalAns;
    i=0;
    n=s.size();
    if(s[0]=='-'){
        flag=-1;
        i++;
    }else if(s[0]=='+') i++;
    while(i<n){
        if(s[i]>='0' && s[i]<='9') {
            if(ans>INT_MAX/10 ){
                return flag==1? INT_MAX:INT_MIN;
            }
            ans=ans*10+(s[i]-'0');
            i++;
        }
        
        else break;
    }
    finalAns=ans*flag;
    // if(finalAns>INT_MAX) return INT_MAX;
    // if(finalAns<INT_MIN) return INT_MIN;
    return finalAns;
}

//a2
int createAtoi(string s) {
    int n = s.size();
    int i = 0;

    // Skip leading whitespace
        // s.erase(0, s.find_first_not_of(' '));

    while (i < n && s[i] == ' ') {
        i++;
    }

    // Check for empty string or all whitespace
    if (i == n) {
        return 0;
    }

    // Handle sign
    long long ans = 0;
    int flag = 1;
    if (s[i] == '-') {
        flag = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    // Process digits
    while (i < n && isdigit(s[i])) {
        ans = ans * 10 + (s[i] - '0');
        // Check for overflow
        if (ans > INT_MAX && flag == 1) {
            return INT_MAX;
        } else if (-ans < INT_MIN && flag == -1) {
            return INT_MIN;
        }
        i++;
    }

    return flag * ans;
}

//3
int count(string &str, int k){
    int n=str.size();
    unordered_map<char,int> freq;//char vs freq

    int i=0,j=0,c=0;
    while(j<n){
        freq[str[j]]++;
        while(freq.size()>k){
            if(freq[str[i]] == 1) freq.erase(str[i]);
            else freq[str[i]]--;
            i++;
        }
        c+=j-i+1;//all substr ending at j
        j++;
    }
    return c;
} 

int countSubStrings(string str, int k) 
{
    // Write your code here.
    //atmost 3(3,2,1,0)-atmost2(2,1,0)=exact(3)
    return count(str,k)-count(str,k-1);

}

//4
int beauty(vector<int> &f){
    int maxi=1,mini=INT_MAX;
    for(auto x:f){
        maxi=max(maxi,x);
        if(x>0) mini=min(mini,x);
    }
    return maxi-mini;
}

int sumOfBeauty(string s) {
    // Write your code here.
    int n=s.size(),ans=0;
    for(int i=0;i<n-2;i++){
        vector<int> f(26,0);
        for(int j=i;j<n;j++){
            f[s[j]-'a']++;
            if(j>i+1)   //optional
                ans+=beauty(f);
        }
    }
    return ans;
}

//5
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int maxLength=1, n=s.size();
        ans+=s[0];

        //odd
        for(int i=1;i<n-1;i++){
            int x=1;
            while(i-x>=0 && i+x<n){
                if(s[i-x] != s[i+x]) break;
                x++;
            }
            int currentLength=2*x+1-2; 
            if(currentLength>maxLength){
                maxLength=currentLength;
                ans=s.substr(i-x+1,currentLength);
            }
        }
        //even
        for(int i=0;i<n-1;i++){
            int x=1;
            while(i-x+1>=0 && i+x<n){
                if(s[i-x+1] != s[i+x]) break;
                x++;
            }
            int currentLength=2*x-2; 
            if(currentLength>maxLength){
                maxLength=currentLength;
                ans=s.substr(i-x+2,currentLength);
            }
        }
        return ans;
    }
};

//a1 better
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int maxLength=1, n=s.size();
        ans+=s[0];

        //odd
        for(int i=1;i<n-1;i++){
            int left=i-1,right=i+1;
            while(left>=0 && right<n){
                if(s[left] != s[right]) break;
                left--;
                right++;
            }
            int currentLength=right-left-1;
            if(currentLength>maxLength){
                maxLength=currentLength;
                ans=s.substr(left+1,currentLength);
            }
        }
        //even
        for(int i=0;i<n-1;i++){
            int left=i,right=i+1;
            while(left>=0 && right<n){
                if(s[left] != s[right]) break;
                left--;
                right++;
            }
            int currentLength=right-left-1;
            if(currentLength>maxLength){
                maxLength=currentLength;
                ans=s.substr(left+1,currentLength);
            }
        }
        return ans;
    }
};

//a1 more better way
class Solution {
public:
    string expand(int left,int right,string &s,int n){
        while(left>=0 && right<n){
            if(s[left] != s[right]) break;
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }

    string longestPalindrome(string s) {
        string ans;
        int maxLength=1, n=s.size();
        ans+=s[0];

        for(int i=0;i<n-1;i++){
            string odd=expand(i-1,i+1,s,n);
            string even=expand(i,i+1,s,n);

            if(odd.size() > maxLength){
                maxLength=odd.size();
                ans=odd;
            }
            if(even.size() > maxLength){
                maxLength=even.size();
                ans=even;
            }
        }
        return ans;
    }
};

//6
//a1
    //static 
    // only > no >=
class Solution {
public:
    

    static bool comp(pair<char,int> p1, pair<char,int> p2){
        return p1.second>p2.second;
    }

    string frequencySort(string s) 
    {
        // Write Your Code here
        int n=s.size();
        string ans;
        unordered_map<char,int> um;

        for(auto x:s) um[x]++;

        vector< pair<char,int> > v;
        for(auto x:um) v.push_back({x.first,x.second});

        sort(v.begin(),v.end(),comp);

        for(auto x:v){
            ans.append(x.second,x.first);
        }

        return ans;
    }
};
//a2
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        string ans = "";

        // count character frequency
        for(auto ch: s){
            mp[ch]++;
        }

        // push to heap to sort characters in highest frequency first
        for(auto i: mp){
            pq.push({i.second, i.first});
        }

        // add to final answer string from the heap till it's empty
        while(!pq.empty()){
            pair<int, char> cur = pq.top();
            pq.pop();
            while(cur.first--) ans += cur.second;
        }
        
        return ans;
    }
};
//6. Linked List
//6.1 1d ll

//1 constructLL from arr values and return head
/**
 * Definition of linked list
 * class Node {
 *
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 */

Node* constructLL(vector<int>& arr) {
    // Write your code here
    Node* head=new Node();
    Node* temp=head;

    for(auto x:arr){
        Node* currentNode=new Node(x);
        temp->next=currentNode;
        temp=currentNode;// temp=temp->next;
        
    }

    return head->next;
}
//a2
    Node* head=NULL,*temp=head;

    for(auto x:arr){
        Node* currentNode=new Node(x);
        if(head == NULL){
            head=currentNode;
            temp=head;
        }else{
            temp->next=currentNode;
            temp=temp->next;
        }
        
    }
//2 insert at head
    Node* newNode=new Node(newValue);
    newNode->next=list;
    list=newNode;//or return newNode

    return list;

//3 deleteLast 
        //move till 2ndLast
Node *deleteLast(Node *list){
    // Write your code here
    Node* temp=list;
    // while(temp-> next && temp->next->next){
    while( temp->next->next){

        temp=temp->next;
    }
    Node* toDel=temp->next;
    temp->next=temp->next->next;
    delete toDel;
    return list;
}

//4 length
    int ans=0;
    while(head){
        ans++;
        head=head->next;
    }
    return ans;

//5
Node<int> * head can point only to ll with nodes having int data. Node *head is general, can point any data
//search in ll
    while(head){
        if(head->data == k) return 1;
        head=head->next;
    }
    return 0;

//6.3 medium ll
//1 findMiddle
Node *findMiddle(Node *head) {
    // Write your code here
    Node *slow=head, *fast=head;
    while(fast && fast->next){  //to find second middle
    // while(fast->next && fast->next->next){   //to find first middle
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

//2 reverseLinkedList iterative
Node* reverseLinkedList(Node *head)
{
    // Write your code here
    Node *pre=NULL, *cur=head, *nex;
    while(cur){
        nex=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nex;
    }
    return pre;
}

//3 reverseLinkedList recursive
Node* reverseLinkedList(Node *head)
{
    // Write your code here
    if(head==NULL || head->next==NULL) return head;

    Node *newHead=reverseLinkedList(head->next);
    head->next->next=head;
    head->next=NULL;

    return newHead;
}
//4 detectCycle
    //Floyd’s Cycle detection algorithm
bool detectCycle(Node *head)
{
    Node *fast=head,*slow=head;

    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow) return 1;//cant check before as in start they are equal only pointing to head
    }
    // }while((fast && fast->next) || fast!=slow);  //tle
    // }while((fast && fast->next) && fast!=slow);  //correct

    return 0;
}
//5 node where the cycle begins
Node *firstNode(Node *head)
{
    //    Write your code here.
    Node *fast=head, *slow=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            slow=head;
            while(slow!=fast){
                //start of cycle is equidistanct from head & meeting point
                fast=fast->next;
                slow=slow->next;
            }
            return slow;
        }
    }
    return NULL;
}

//6 length of loop
        if(fast==slow){
            int count=0;
            do{
                slow=slow->next;
                count++;
            }while(slow!=fast);
            return count;
        }
//7 isPalindrome
Node * reverse(Node* head){
    if(head==NULL || head->next==NULL) return head;

    Node* reversedHead=reverse(head->next);

    head->next->next=head;
    head->next=NULL;

    return reversedHead;
}

bool isPalindrome(Node *head)
{
    if(head==NULL || head->next==NULL) return 1;
    // write your code here
    // find second mid
    Node *temp=head, *mid=head;
    while(temp && temp->next){
        temp=temp->next->next;
        mid=mid->next;
    }
    // reverse from there
    Node *end=reverse(mid);
    // start & end check. start->next end->next
    Node *start=head;
    while(end){
        if(start->data != end->data) return 0;
        start=start->next;
        end=end->next;
    }
    // if end reach null return true
    return 1;
}
//a2 stack
    stack<Node*> visitedNodes;

    Node* temp=head;
    while(temp){
        visitedNodes.push(temp);
        temp=temp->next;
    }

    temp=head;
    while(temp){
        Node* end=visitedNodes.top();
        if(temp->data != end->data) return 0;

        visitedNodes.pop();
        temp=temp->next;
    }

    return 1;
//a3 recursion

//8
Node* segregateEvenOdd(Node* head)
{
    // Write your code here
    Node *oddStart=new Node(-3), *evenStart=new Node(-2);
    Node *oddEnd=oddStart, *evenEnd=evenStart;

    Node *temp=head;
    while(temp){
      if(temp->data %2){
        oddEnd->next=temp;
        oddEnd=oddEnd->next;
      }else{
        evenEnd->next=temp;
        evenEnd=evenEnd->next;
      }
      temp=temp->next;
    }
    oddEnd->next=NULL;//missed
    evenEnd->next=oddStart->next;

    return evenStart->next;
}
//a2
Node* segregateEvenOdd(Node* head)
{
    // Write your code here
    Node *oddStart=NULL, *evenStart=NULL;
    Node *oddEnd=oddStart, *evenEnd=evenStart;

    Node *temp=head;
    while(temp){
      if(temp->data %2){
        if(oddStart){
          oddEnd->next=temp;
          oddEnd=temp;
        }else{
          oddStart=oddEnd=temp;
        }
      }else{
        if(evenStart){
          evenEnd->next=temp;
          evenEnd=temp;
        }else{
          evenStart=evenEnd=temp;
        }
      }
      temp=temp->next;
    }
    
    if(!evenStart){
      return oddStart;
    }
    evenEnd->next=oddStart;
    if(oddEnd) oddEnd->next=NULL;

    return evenStart;
}

//9 removeKthNode from end
Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    //a1 calculate size then n-k
    //a2 2ptr
    Node *fast=head, *slow=head;
    while(K--) fast=fast->next;
//When fast reaches end slow will reach the node to delete 
// So when fast reaches just before end, slow will reach just before the node to delete

    if(!fast){
        //remove first
        Node *toDelete=head;
        head=head->next;
        delete toDelete;
        return head;
    }

    while(fast->next){
        fast=fast->next;
        slow=slow->next;
    }

    Node *toDelete=slow->next;
    slow->next=slow->next->next;
    delete toDelete;

    return head;
}
//10
// Step 1 to find 2nd middle 
// At the end slow will point to second middle just keep track of node previous to slow
Node* deleteMiddle(Node* head){
    // Write your code here.
    if(head->next == NULL) {
        delete head;
        return NULL;
    }

    Node *fast=head, *slow=head, *prev=NULL;
    while(fast && fast->next){
        fast=fast->next->next;
        prev=slow;
        slow=slow->next;
    }
    prev->next=slow->next;
    delete slow;
    return head;
}
//a2 count nodes
n/2 is the node previous to middle 
5/2 =2 is previous to middle 3
6/2 =3 is previous to middle 4

//11
// 9
// 11 30 12 22 17 16 18 16 18
Node* sortList(Node* head){
    // Write your code here.
    if(head->next==NULL || head->next->next==NULL) return head;

    Node *h1=head,*h2=head->next;
    Node *p1=h1,*p2=h2,*t1=h1;

    while(p1 && p2){
        
        p1->next=p1->next->next;
        if(p2->next) p2->next=p2->next->next;

        p1=p1->next;
        // if(p1) t1=p1;
        p2=p2->next;
    }

    h2=reverse(h2);

    Node* merged=new Node(-1), *h=merged;

    while(h1 && h2){
        if(h1->data <=h2->data){
            h->next=h1;
            h=h1;
            h1=h1->next;
        }else{
            h->next=h2;
            h=h2;
            h2=h2->next;
        }
    }
    while(h1){
            h->next=h1;
            h=h1;
            h1=h1->next;
    }
    while(h2){
            h->next=h2;
            h=h2;
            h2=h2->next;
    }
    // t1->next=h2;
    return merged->next;
}
//12
Node* sortList(Node *head){
    // Write your code here.
    Node *zh=new Node(-1),*zt=zh;
    Node *oh=new Node(-1),*ot=oh;
    Node *th=new Node(-1),*tt=th;

    while(head){
        if(head->data==0){
            zt->next=head;
            zt=head;
        }else if(head->data==1){
            ot->next=head;
            ot=head;
        }else{
            tt->next=head;
            tt=head;
        }
        head=head->next;
    }
    //either
    // if(oh!=ot){
    //     zt->next=oh->next;
    // }else zt->next=tt->next;

    // ot->next=th->next;

    // tt->next=NULL;

    // return zh->next;

    //or
    zt->next=NULL;
    ot->next=NULL;
    tt->next=NULL;

    if(ot!=oh) {
        zt->next=oh->next;
        if(tt!=th) ot->next=th->next;
    }
    else if(tt!=th) zt->next=th->next;

    if(zh->next) return zh->next;
    else if(oh->next) return oh->next;
    return th->next;
}

//13 findIntersection
    //From intersection length will be same
int length(Node *head){
    int count=0;
    while(head){
        head=head->next;
        count++;
    }
    return count;
}

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    int length1 = length(firstHead);
    int length2 = length(secondHead);

    if(length1>length2){
        int difference = length1-length2;
        while(difference--) firstHead=firstHead->next;
    }else{
        int difference = length2-length1;
        while(difference--) secondHead=secondHead->next;
    }

    while(firstHead){
        if(firstHead==secondHead) return firstHead;
        firstHead=firstHead->next;
        secondHead=secondHead->next;
    }

    return NULL;

}
//a2 tle
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    set<Node*> nodes;
    while(firstHead){
        nodes.insert(firstHead);
        firstHead=firstHead->next;
    }

    while(secondHead){
        if(nodes.find(secondHead) != nodes.end()) return secondHead;
        secondHead=secondHead->next;
    }

    return NULL;

}
//a3 without counting nodes
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node *p1=firstHead, *p2=secondHead;

    if(p1==NULL || p2==NULL) return NULL;

    while(p1 && p2 && p1!=p2){
        p1=p1->next;
        p2=p2->next;

        if(p1==p2) return p1;

        if(p1== NULL) p1=secondHead;
        if(p2==NULL) p2=firstHead;
    }
    return p1;
}
//14
Node *addOne(Node *head)
{
    // Write Your Code Here.
        Node *curr=head, *lastNotNine=NULL;
        while(curr){
            if(curr->data != 9) {
                lastNotNine=curr;
            }
            curr=curr->next;
        }
    
        if(lastNotNine){
            lastNotNine->data=lastNotNine->data+1;
                //missed to make rest 0
            curr=lastNotNine->next;
            while(curr){
                curr->data=0;
                curr=curr->next;
            }
            return head;
        }
    
        Node *extra=new Node(1);
        extra->next=head;
        curr=head;
        while(curr){
            curr->data=0;
            curr=curr->next;
        }
    
        return extra;
}

//a2
Node *addOne(Node *head)
{
    // Write Your Code Here.
    Node *reverseHead=reverse(head);

    Node *temp=reverseHead;
    int carry=1;
    //either
    // while(temp){
    //     int val=temp->data;
    //     temp->data=(temp->data+1)%10;
    //     if(val<9){
    //         carry=0;
    //         break;
    //     }
    //     temp=temp->next;
    // }
    //or
    while(temp && carry){
        carry=(temp->data+1)/10;
        temp->data=(temp->data+1)%10;
        
        temp=temp->next;
    }
    head=reverse(reverseHead);
    if(carry){
        Node *newNode=new Node(1);
        newNode->next=head;
        head=newNode;
    }
    return head;
}
//a3 recursive
int addOneHelper(Node *head){
    if(head==NULL) return 1;

    int val=head->data + addOneHelper(head->next);
    head->data=val%10;

    return val/10;
}

Node *addOne(Node *head)
{
    // Write Your Code Here.
    int carry=addOneHelper(head);

    if(carry){
        Node *extra=new Node(1);
        extra->next=head;
        head=extra;
    }

    return head;
}

//15
    //question already gave as reverse else we had to do it
Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node *head=NULL, *tail=NULL;
    int carry=0;
    while(num1 || num2 || carry){
        if(num1){
            carry+=num1->data;
            num1=num1->next;
        }
        if(num2){
            carry+=num2->data;
            num2=num2->next;
        }
        int val=carry%10;
        carry/=10;

        Node *curr=new Node(val);
        //if needed reverse
        // curr->next=head;
        // head=curr;

        //no reverse
        if(head){
            tail->next=curr;
            tail=curr;
        }else{
            head=curr;
            tail=curr;
        }

    }
    return head;
}

//6.5 hard ll
//1
//a1
void reverse(Node *head){
    if(head==NULL || head->next==NULL) return ;

    reverse(head->next);

    head->next->next=head;
    head->next=nullptr;

    return ;
}

 Node *getk(Node* head,int k){
     while(--k && head){
        //to reverse remaining also
    // while(--k && head->next){

         head=head->next;
     }
     return head;
 }

Node* kReverse(Node* head, int k) {
    // Write your code here.
    Node *temp=head, *prev=NULL;
    while(temp){
        Node *kthNode=getk(temp,k);
        if(kthNode) {
            Node *nextNode=kthNode->next;
            kthNode->next=NULL;
            reverse(temp);

            if(temp==head){
                head=kthNode;
            }else{
                if(prev) prev->next=kthNode;
            }

            prev=temp;
            temp=nextNode;

        }else{
            if(prev) prev->next=temp;
            break;
        }
    }

    return head;
    
}
//a2
Node *reverse(Node *head){
    if(head==NULL || head->next==NULL) return head;

    Node *newH=reverse(head->next);

    head->next->next=head;
    head->next=nullptr;

    return newH;
}

 Node *getk(Node* head,int k){
     while(--k && head){
         head=head->next;
     }
     return head;
 }

Node* kReverse(Node* head, int k) {
    // Write your code here.
    Node *temp=head, *prev=NULL;
    while(temp){
        Node *kthNode=getk(temp,k);
        if(kthNode) {
            Node *nextNode=kthNode->next;
            kthNode->next=NULL;
            Node *newH=reverse(temp);

            if(temp==head){
                head=kthNode;
            }else{
                if(prev) prev->next=kthNode;
            }

            prev=temp;
            temp=nextNode;

        }else{
            if(prev) prev->next=temp;
            break;
        }
    }

    return head;
    
}
//a3
bool check(Node *head, int k) {
    int c=0;
    while(head){
        c++;
        if(c==k) return 1;
        head=head->next;
    }

    return 0;
}

Node* kReverse(Node* head, int k) {
    // Write your code here.
    bool canReverse=check(head,k);
    if(!canReverse) return head;

    Node *prev=nullptr, *temp=head;
    int c=0;
    while(c++<k){
        Node *nextNode=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nextNode;
    }

    if(temp){
        Node *nextHead=kReverse(temp, k);
        head->next=nextHead;
    }

    return prev;
}
//a4
void reverse(Node *head,Node *tail){
    if(head==tail) return ;

    reverse(head->next,tail);

    head->next->next=head;
    head->next=nullptr;

    return ;
}

 Node *getk(Node* head,int k){
     while(--k && head){
         head=head->next;
     }
     return head;
 }

Node* kReverse(Node* head, int k) {
    // Write your code here.
    Node *temp=head, *prev=NULL;
    while(temp){
        Node *kthNode=getk(temp,k);
        if(kthNode) {
            Node *nextNode=kthNode->next;
            // kthNode->next=NULL;
            reverse(temp,kthNode);

            if(temp==head){
                head=kthNode;
            }else{
                if(prev) prev->next=kthNode;
            }

            prev=temp;
            temp=nextNode;

        }else{
            if(prev) prev->next=temp;
            break;
        }
    }

    return head;
    
}
//2
Node *rotate(Node *head, int k) {
     // Write your code here.
     // if(k==0 || head->next==nullptr) return head;    
     int n=0;
     Node *temp=head, *tail=head;
     while(temp){
          
          n++;
          temp=temp->next;
     }
     k%=n;
     if(k==0) return head;

     Node *fast=head,*newTail=head;
     while(k--) fast=fast->next;

     while(fast->next){
          fast=fast->next;
          newTail=newTail->next;
     }
     tail=fast;

     Node* newHead=newTail->next;
     tail->next=head;
     newTail->next=nullptr;

     return newHead;
}
//3

Node *mergeR(Node *a,Node *b){
    if(a==nullptr) return b;
    if(b==nullptr) return a;

    Node *temp;
    if(a->data < b->data){
        temp=a;
        temp->child=mergeR(a->child, b);
    }else{
        temp=b;
        temp->child=mergeR(a,b->child);
    }
    return temp;
}

Node *mergeI(Node *a,Node *b){
    Node *head=new Node(1), *temp=head;

    while(a && b){
        if(a->data < b->data){
            temp->child=a;
            temp=a;
            a=a->child;
        }else{
            temp->child=b;
            temp=b;
            b=b->child;
        }
    }

    if(a) temp->child=a;
    if(b) temp->child=b;

    return head->child;
}


Node* flattenLinkedList(Node* head) 
{
    // Write your code here
    if(head->next == nullptr) return head;

    Node *nextNode=flattenLinkedList(head->next);

    // head=mergeR(head,nextNode);//recursive
    head=mergeI(head,nextNode); //iterative

    head->next=NULL;

    return head;
}

//4
Node *cloneLL(Node *head){
    // Write your code here

    //step1 make copy and attach in between
    Node* it=head,*fr=head;//iterator & front

    while(it){
        fr=it->next;
        Node *cp=new Node(it->data);
        it->next=cp;
        cp->next=fr;
        it=fr;
    }

    //step 2 assign random of copy
    it=head;
    while(it){
        if(it->random) it->next->random=it->random->next;//checking because if it->random is null then its next will give error
        it=it->next->next;
    }

    //step 3 seperate both lists
    
    //s2
    Node *dummy=new Node(-1);
    it=head,fr=head;
    Node *cpit=dummy;

    while(it){
        fr=it->next->next;

        cpit->next=it->next;
        it->next=fr;

        cpit=cpit->next;
        it=it->next;
    }
    return dummy->next;
}
//6.2 doubly ll easy
//1
Node* constructDLL(vector<int>& arr) {
    // Write your code here
    Node *head=nullptr,*tail=nullptr;

    for(auto x:arr){
        Node *curr=new Node(x);

        if(head){
            tail->next=curr;
            curr->prev=tail;
            tail=curr;
        }else{
            head=curr;
            tail=curr;
        }
    }
    return head;
}
//2
Node * insertAtTail(Node *head, int k) {
    // Write your code here
    Node *curr=new Node(k);
    
    if(head == nullptr) return curr;

    Node *temp=head;
    while(temp->next){
        temp=temp->next;
    }

    temp->next=curr;
    curr->prev=temp;

    return head;
}
//3
Node * deleteLastNode(Node *head) {
    // Write your code here
    if(head->next==nullptr) {
        delete head;
        return nullptr;
    }

    Node *curr=head;
    while(curr->next) curr=curr->next;

    curr->prev->next=nullptr;

    delete curr;

    return head;
}
//4
Node* reverseDLL(Node* head)
{   
    // Write your code here   
    Node *cur=head, *tail=head;
    while(cur){
        tail=cur;
        
        Node *nex=cur->next;
        cur->next=cur->prev;
        cur->prev=nex;

        cur=nex;//or cur=cur->prev
    }

    return tail;
}

//6.4 doubly ll medium
//1
Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    Node *curr=head;
    while(curr){
        if(curr->data == k){
            if(curr==head) head=head->next;

            Node *nextNode=curr->next;

            if(curr->next) curr->next->prev=curr->prev;
            if(curr->prev) curr->prev->next=curr->next;

            delete curr;

            curr=nextNode;
        }else{
            curr=curr->next;
        }
    }
    return head;
}

//2
vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    Node *tail=head;
    while(tail->next) tail=tail->next;

    vector<pair<int,int>> ans;

    while(head!=tail){
        int val=head->data + tail->data;
        if( val== k){
          ans.push_back({head->data, tail->data});
          head=head->next;
          if(head==tail) break;// or in while add 1 more (head!=tail && head->prev!=tail)
            //or   while (start->data < end->data)
          tail=tail->prev;
        }else if(val>k) tail=tail->prev;
        else head=head->next;
    }

    return ans;
}
//a2
    vector<pair<int,int>> ans;
    unordered_set<int> visited;

    Node *curr=head;
    while(curr){
        int val=curr->data;
        int rem=k-val;
        if(visited.find(rem) != visited.end()){
            ans.push_back({val,rem});
        }
        visited.insert(val);

        curr=curr->next;
    }

    return ans;
//3
Node * removeDuplicates(Node *head)
{
    // Write your code here
    Node *curr=head->next;
    while(curr){
        if(curr->data == curr->prev->data){
            curr->prev->next=curr->next;//no need to check if prev is not null
            if(curr->next) curr->next->prev=curr->prev;

            Node *del=curr;
            curr=curr->next;
            delete del;
            
        }else curr=curr->next;
    }
    return head;
}

//7. Recursion
//7.1 easy

// range of int
-2^31 to 2^31-1
approx -10^9 to 10^9

//1
5.2 4

//2
double positive(double x, int n) {
    if(n==0) return 1;
    double half=positive(x,n/2);
    half*=half;
    if(n&1) half*=x;

    return half;
}

double myPow(double x, int n) {
    // Write Your Code Here
    double ans=positive(x,n);

    if(n<0) return 1.0/ans;

    return ans;
}
//a2
double myPow(double x, int n) {
    // Write Your Code Here
    if(n==0) return 1;

    if(n>0) return x*myPow(x, n-1);

    return myPow(x, n+1)/x;
}
//3
bool check(int num,int digit,int sum){
    if(num==0) return 1;//incorrect num<10 return 1

    int curr=num%10;
    if(curr==digit || curr<=sum) return 0;//incorrect cur<sum

    if(sum==-1) return check(num/10, digit, sum+1+curr);

    return check(num/10, digit, sum+curr);
}

vector<int> goodNumbers(int a, int b, int digit) {
    // Write your code here.
    vector<int> ans;
    for(int num=a;num<=b;num++){
        if(check(num,digit,-1)){
            ans.push_back(num);
        }
    }
    return ans;
}
//4
#include <bits/stdc++.h> 
stack<int> sortStack(stack<int> &s)
{
    // Write code here.
    if(s.size() == 1) return s;

    int top=s.top();
    s.pop();

    sortStack(s);

    stack<int> helper;
    while(s.size()>0 && s.top()>top){
        helper.push(s.top());
        s.pop();
    }
    s.push(top);
    while(helper.size()>0){
        s.push(helper.top());
        helper.pop();
    }

    return s;
}
//a2
void sortedInsert(stack<int> &s,int num) {
    if(s.empty() || num>=s.top()){
        s.push(num);
        return;
    }

    int top=s.top();
    s.pop();

    sortedInsert(s,num);

    s.push(top);
}

stack<int> sortStack(stack<int> &s)
{
    // Write code here.
    if(s.size() == 1) return s;

    int top=s.top();
    s.pop();

    sortStack(s);

    sortedInsert(s,top);

    return s;
}
//5
void insertAtBottom(stack<int> &stack, int num) {
    if(stack.empty()){
        stack.push(num);
        return;
    }

    int top=stack.top();
    stack.pop();

    insertAtBottom(stack, num);

    stack.push(top);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.size()==1) return;

    int num=stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack,num);

}
//careful as name of stack is stack. avoid this

//7.2 medium
//1

void generate(int N,string curr,vector<string> &ans){
    // void generate(int N,string &curr,vector<string> &ans){
        //&curr error if passing curr+"0"

    if(curr.size() == N) {
        ans.push_back(curr);
        return;
    }

    generate(N, curr+"0",ans);

    if(curr.size()==0 || curr.back()!='1')
        generate(N, curr+"1", ans);
}

vector<string> generateString(int N) {
    // Write your code here.
    vector<string> ans;
    string curr;
    generate(N,curr,ans);
    return ans;
}

//a2 fastest as no string copy using ref
void generate(int N,string &curr,vector<string> &ans){
    // void generate(int N,string &curr,vector<string> &ans){
        //&curr error

    if(curr.size() == N) {
        ans.push_back(curr);
        return;
    }
    curr+='0';
    generate(N, curr,ans);
    curr.pop_back();

    if(curr.size()==0 || curr.back()!='1'){
        curr+="1";
        generate(N, curr, ans);
        curr.pop_back();
    }
        
}

vector<string> generateString(int N) {
    // Write your code here.
    vector<string> ans;
    string curr;
    generate(N,curr,ans);
    return ans;
}
//2
void f(int n,int open,int close,string &curr,vector<string> &ans){
    if(close==n){
        ans.push_back(curr);
        return;
    }
    if(open<n){
        curr+='(';
        f(n,open+1,close,curr,ans);//or "("
        curr.pop_back();
        //to avoid push & pop use f(n,open+1,close,curr+'(',ans);
        //but its less efficient
    }
    if(close<open){
        curr+=')';
        f(n,open,close+1,curr,ans);
        curr.pop_back();
    }
}

vector<string> validParenthesis(int n){
    // Write your code here.
    vector<string> ans;
    string curr;
    f(n,0,0,curr,ans);//n open close curr ans
    return ans;
}
// 3
void f(int idx,string curr,string &s,vector<string> &ans){
    if(idx==s.size()){
        ans.push_back(curr);
        return;
    }

    f(idx+1,curr,s,ans);
    f(idx+1,curr+s[idx],s,ans);
}

vector<string> generateSubsequences(string s)
{
    // Write your code here.
    vector<string> ans;
    f(0,"",s,ans);//index currString s ans
    return ans;
}
//a2
vector<string> generateSubsequences(string s)
{
    // Write your code here.
    vector<string> ans;
    int n=s.size();
    // pow(2,n) = 1<<n
    for(int i=0;i<(1<<n);i++){
        string curr;
        for(int j=0;j<n;j++){
            if(i & (1<<j)) curr+=s[j];  //i=4 100 right to left if (1<<j) j=0 to n-1
            // if(i & (1<<(n-1-j) ) ) curr+=s[j];   //left to right
        }
        // cout<<curr<<endl;
        ans.push_back(curr);
    }
    return ans;
}
// 4 PTC
// 5
vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    // Write your code here
    vector<vector<int>> ans;

    int n=a.size(), j=0;
    long long cur=0;
    for(int i=0;i<n;i++){
        cur+=a[i];
        while(cur>k){
            cur-=a[j];
            j++;
        }

        if(cur==k){
            ans.push_back(vector<int> (a.begin()+j,a.begin()+i+1));
                // [j,i+1) so j to i both included [j,i]
            /*
            vector<int> temp;
            for(int it=i;it<=j;it++){
                temp.push_back(a[it]);
            }
            ans.push_back(temp);
            */
        }
    }

    return ans;
}
// 6
//a1 tle 
bool check(int n, int k, vector<int> &a,int idx,int sum){
    if(sum==k) return 1;
    if(idx==n || sum>k) return 0;

    return check(n, k, a, idx+1, sum) || check(n, k, a, idx+1, sum+a[idx]);
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    return check(n,k,a,0,0); //idx sum
}
//a2 dp ptc

// 7
void f(vector<int> &ARR, int B,int idx,int sum,vector<int> &temp,vector<vector<int>>&ans){
    if(sum==B){
        ans.push_back(temp);
        return;
    }
    if(sum>B || idx==ARR.size()) return;

    //take
    temp.push_back(ARR[idx]);
    f(ARR,B,idx,sum+ARR[idx],temp,ans);// we can take again so idx
    temp.pop_back();
    //skip
    f(ARR, B, idx+1, sum, temp, ans);
}

vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    // Write your code here.
    sort(ARR.begin(),ARR.end());
    vector<vector<int>>ans;
    vector<int> temp;
    f(ARR,B,0,0,temp,ans);      //idx sum 
    return ans;
}
// 8
//a1
void f(int idx,int sum,vector<int> &temp,vector<vector<int>> &ans,vector<int> &arr, int n, int target){

    if(sum==target){
        ans.push_back(temp);
        return;
    }
    if(idx==n || sum>target) return;

    //select
    temp.push_back(arr[idx]);
    f(idx+1,sum+arr[idx],temp,ans,arr,n,target);
    temp.pop_back();

    //reject all occurence of this num
    while(idx+1<n && (arr[idx+1]==arr[idx]) ){
        idx++;
    }
    f(idx+1,sum,temp,ans,arr,n,target);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
    // Write your code here.
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> temp;

    f(0,0,temp,ans,arr,n,target);   //idx sum
    return ans;
}
//a2
    //select
    if(arr[idx] != lastRejected){
        temp.push_back(arr[idx]);
        f(idx+1,sum+arr[idx],temp,ans,arr,n,target,lastRejected);
        temp.pop_back();
    }

    f(idx+1,sum,temp,ans,arr,n,target,arr[idx]);
//main    // f(0,0,temp,ans,arr,n,target,-1);    //idx sum

//a3
    //BASE CASE
    if(target == 0){
        res.push_back(ds);                          
        return;                     
    }

        for (int i = index; i < arr.size(); i++) {
        // CONDITION TO AVOID DUPLICATE ENTRIES AND COMBINATIONS
          if (i > index and arr[i] == arr[i - 1]) {
            continue; 
          }
        // OPTIMISING BY BREAKING LOOP AND INITIALISING A NEW ELEMENT  AS A STARTING POINT
          if (arr[i] > target) {
            break;
          }
          ds.push_back(arr[i]);

          findCombs(i + 1, target-arr[i], arr, ds, res);
          /* THE ELEMENT IS REMOVED SO THAT A NEW COMBINATION CAN BE GENERATED
           WHEN RECURSION CALL IS BACK-TRACKED */
          ds.pop_back(); 
        }
//9 all subset sum
        select & reject
//10 unique subsets
        similar to combinationSum2
    //a2 dont select repeated 
void findSubsets(int index, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans) {
    // Pushing the array 'temp' into 'ans'
    ans.push_back(temp);
    
    for(int i = index; i < (int)arr.size(); ++i) {
        // Checking if the previous element is same as current element
        if(i != index && arr[i] == arr[i - 1]) continue;
        
        // Inserting the current element in array 'temp'
        temp.push_back(arr[i]);
        
        findSubsets(i + 1, arr, temp, ans);
        
        // Removing last element from 'temp'
        temp.pop_back();
    }
}
//11
//a1
void f(int count,int sum,int num,int k,int n,vector<int> &temp, vector<vector<int>> &ans){
    if(sum==n && count==k){
        ans.push_back(temp);
        return;
    }

    if(count>k || sum>n || num>9) return;
    //select
        //count sum num
    temp.push_back(num);
    f(count+1,sum+num,num+1,k,n,temp,ans);
    temp.pop_back();
    //reject
    f(count,sum,num+1,k,n,temp,ans);
}

vector<vector<int>> combinationSum(int k, int n) {
    // Write Your Code Here
    vector<vector<int>> ans;
    vector<int> temp;
    f(0,0,1,k,n,temp,ans);
    return ans;
}
//a2

void f(int k,int n,vector<int> &t,vector<vector<int>> &ans,int start){

    if(k==0){
        if(n==0){
            ans.push_back(t);
        }
        return;
    }

    for(int i=start;i<=9;i++){
        if(i>n) break;

        t.push_back(i);
        f(k-1,n-i,t,ans,i+1);
        t.pop_back();
    }
}

vector<vector<int>> combinationSum(int k, int n) {
    // Write Your Code Here
    vector<vector<int>> ans;
    vector<int> t;
    f(k,n,t,ans,1);//last selected 1, so we can select anything higher than it
    return ans;
}
//12 letterCombinations
void f(int idx,string &temp,string &digits,vector<string> &ans,vector<string> &v){
    if(idx==digits.size()){
        ans.push_back(temp);
        return;
    }
    //idx
        //try all letters of this idx and move ahead
    string curr=v[digits[idx]-'0'];
    for(char letter:curr){
        temp+=letter;
        f(idx+1,temp,digits,ans,v);
        temp.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    // Write your code here.
    vector<string> v={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        //imp 0 & 1 
        //read constraint 
    vector<string> ans;
    string temp;
    f(0,temp,digits,ans,v);
    return ans;
}

//7.3 recursion hard
//1
bool check(string &s,int start,int end){
    while(start<end){
        if(s[start++] != s[end--]) return 0;
    }
    return 1;
}

void f(int idx,vector<string> &temp,string &s,vector<vector<string>> &ans){
    if(idx==s.size()){
        ans.push_back(temp);
        return ;
    }
    //idx to endIdx
    //if palindrome temp+substr(idx,end+1)
    for(int i=idx;i<s.size();i++){
        if(check(s,idx,i)){
            string curr=s.substr(idx,i-idx+1);
                //substr(start,length)
            temp.push_back(curr);
            f(i+1,temp,s,ans);//incorrect idx+1
            temp.pop_back();
        }
    }

}

vector<vector<string>> partition(string s) {
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> temp;
    f(0,temp,s,ans);
    return ans;

}

//2
bool found(vector<vector<char>> &board, string &word, int n, int m,int row,int col,int wordIdx,vector<vector<int>> &v) {

    if(wordIdx==word.size()) return 1;
    if(row<0 || row==n || col<0 || col>m || board[row][col] != word[wordIdx]) return 0;

    // if(board[row][col] == word[wordIdx]){
        board[row][col]='-';
        bool ans=false;
        for(int i=0;i<4;i++){
            ans|=found(board,word,n,m,row+v[i][0],col+v[i][1],wordIdx+1,v);
        }
        board[row][col]=word[wordIdx];
    // }
    return ans;
}

bool present(vector<vector<char>> &board, string &word, int n, int m) 
{
    // Write your code here.
    vector<vector<int>> v={{-1,0},{1,0},{0,1},{0,-1}};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //first match
            if(board[i][j] == word[0]){
                //if entire word found
                if(found(board,word,n,m,i,j,0,v)){  //0 is wordIdx
                    return 1;
                }
            }
        }
    }
    return 0;
}
//3
bool safe(int row,int col,vector<int> &cb,int n){
    for(int i=0;i<row;i++){
        if(cb[i*n + col]) return 0;
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(cb[i*n + j]) return 0;
    }
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(cb[i*n + j]) return 0;
    }
    return 1;
}

void f(int row,vector<int> &cb,vector<vector<int>> &ans,int n){
    if(row==n){
        ans.push_back(cb);
        return;
    }
    // try to place in cols
    for(int col=0;col<n;col++){
        //safe 
        if(safe(row,col,cb,n)){
            // place 
            cb[row*n + col]=1;
            //explore
            f(row+1,cb,ans,n);
             //unplace
            cb[row*n + col]=0;
        }
  
    }
}

vector<vector<int>> nQueens(int n)
{
    // Write your code here.
    vector<int> cb (n*n,0);
    vector<vector<int>> ans;
    f(0,cb,ans,n);
    return ans;
}
//a2
two diagonals & col track to find safe fast 
// 4
void f(int row,int col,int lastRow,int lastCol,string &temp,vector<string> &ans,vector<vector<int>> &mat,string &move,vector<vector<int>> &dir){
    if(row<0 || col<0 || row>lastRow || col>lastCol || mat[row][col]==0) return;

    if(row==lastRow && col==lastCol){
        ans.push_back(temp);
        return;
    }

    for(int k=0;k<4;k++){
        mat[row][col]=0;
        temp.push_back(move[k]);
        f(row+dir[k][0],col+dir[k][1],lastRow,lastCol,temp,ans,mat,move,dir);
        temp.pop_back();
        mat[row][col]=1;
    }
}

vector<string> ratMaze(vector<vector<int>> &mat) {
    // Write your code here.
    
    int lastRow=mat.size()-1,lastCol=mat[0].size()-1;
    if(mat[0][0]==0 || mat[lastRow][lastCol]==0) return {};
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    string move="UDLR";
    string temp;
    vector<string> ans;
    f(0,0,lastRow,lastCol,temp,ans,mat,move,dir);
    return ans;
}
// 5
void f(int currIdx,string &s,unordered_set<string> &words,string temp,vector<string> &ans){

    if(currIdx==s.size()){
        temp.pop_back();
        ans.push_back(temp);
        return;
    }

    for(int lastIdx=currIdx;lastIdx<s.size();lastIdx++){
            //optimize Difference between last index and current index should not be greater than maximum size of the word
        string curr=s.substr(currIdx,lastIdx-currIdx+1);
        if(words.find(curr) != words.end()){
            f(lastIdx+1,s,words,temp+curr+" ",ans);
        }
    }
}

vector<string> getAllValidSentences(string &s, vector<string> &dict)
{
    //  write your code here.
    unordered_set<string> words;
    for(auto word:dict) words.insert(word);

    vector<string> ans;
    string temp;
    f(0,s,words,temp,ans);
    return ans;
}
//a2 dp PTC
//a3 trie

// 6
bool canColor(int color,vector<vector<int>> &mat,vector<int> &v,int idx){
    for(int j=0;j<mat.size();j++){
        //if connected and same coloured return 0 cant color
        if(mat[idx][j] && v[j]==color ) return 0;
    }
    return 1;
}

bool f(vector<vector<int>> &mat, int m,vector<int> &v,int idx,int n){
    if(idx==n) return 1;

    for(int color=1;color<=m;color++){
        if(canColor(color,mat,v,idx)){
            v[idx]=color;
            bool flag=f(mat,m,v,idx+1,n);
            if(flag) return 1;
            v[color]=0;
        }
    }

    return 0;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n=mat.size();
    vector<int> v(n,0);
    v[0]=1;//to skip this line idx=0
    
    return f(mat,m,v,1,n)==1?"YES":"NO";
}
//a2 graph PTC

// 7
bool valid(int i,int board[][9],int row, int col){
    for(int j=0;j<9;j++){
        if(board[row][j] == i) return 0;
        if(board[j][col] == i) return 0;
        if(board[(row/3*3)+j/3][(col/3*3)+j%3]==i) return 0;
    }
    return 1;
}

bool f(int board[][9],int row, int col){
    if(row==9) return 1;
    if(col==9) return f(board,row+1,0);

    //few test case failed when already entered entries where not checked
    if(board[row][col]) 
    {
        int temp=board[row][col];
        board[row][col]=0;
        if(valid(temp,board,row,col)){
            board[row][col]=temp;
            return f(board,row,col+1);
        }else return 0;
        
    }
    else{
        for(int i=1;i<=9;i++){
            if(valid(i,board,row,col)){
                board[row][col]=i;
                bool flag=f(board,row,col+1);
                if(flag) return 1;
                board[row][col]=0;
            }

        }
    }    

    
    return 0;
}

bool sudokuSolver(int board[][9]) {
    
    return f(board,0,0);
}
// 8 expression add operator leetcode 282 PTC

//8.0 BIT MANIPULATION
//tle eliminators tricks
//1 odd or even
(x&1)
//2 power of 2 
if(x && (x&(x-1))==0)
    //x-1 turns rightmost bit as 0 and all 0s to right of it
//3 play with kth bit
101100
543210 kth least significant bit / kth bit from right
    //check kth bit set or not
if(x & (1<<k)) set 
    //toggle kth bit
(x ^ (1<<k))
    //set kth bit
(x | (1<<k))
    //unset kth bit
(x & ~(1<<k))   // ~not turns 1 to 0 and 0 to 1

//4
    //divide by 2^k
x>>k 
    //multiply by 2^k
x<<k 

//5 remainder when divided by 2^k
(x & (1<<k)-1 ) //last k-1 bits 

//6 swap x&y
x=x^y;
y=x^y;
x=x^y;

//7 set bits in a^b will be even if sum of set bits in a ans b is even
//  set bits in a^b will be odd  if sum of set bits in a ans b is odd
since in a^b if kth bit in both set then we lose 2 bits else we retain all set bits  

//8 toggle between 2 values
if(x==10) x=5;
else if(x==5) x=10;

x=x^5^10;

//9
a+b = a^b + 2*(a&b)
    = a|b + a&b 
//10 no of set bits
__builtin_popcount()

//8.1 
//1 get set and clear ith bit
1 based indexing
//2 check if kth bit set
    return (n & (1<<k-1));
    //or
    // return (n>>(k-1) & 1);
//operator precedence
a++ a--
++a --a
! ~
* / %
+ -
<< >>
> < >= <=
== !=
&
^ 
|
&&
||
?:
=
,

//3 odd/even
//4 isPowerOfTwo
//5 count of set bits from 1 to N
int nearestPowerOfTwo(int n){
    int x=0;
    while( (1<<x+1)<=n ) x++;
    return x;
}

int countSetBits(int N)
{
    //Write your code here
    if(N<2) return N;
    int bits=nearestPowerOfTwo(N);

    return bits*(1<<bits-1) + (N-(1<<bits)+1) + countSetBits(N-(1<<bits) );
    //eg 11
    // 3*4 + (11-8+1) + f(11-8);
        //in 8 numbers each bit will be 0&1 half times so 4 times set
}
//a2 ptc
int countSetBits(int N)
{
    // We have 'd' which is the size of repeating window.
    // We are using 'x' to run the loop Log(N) times which is equal to the number of bits in its binary representation.
    int d=2,ans=0,x=N;
    while(x)
    {

        // Using the Mathematical formula explained in the Approach.
        ans+=((N+1)/d)*(d/2) + max((N+1)%d-d/2,0);

        // Window size double every time we shift to the next left bit.
        d*=2;
        x/=2;
    }
    return ans;
}
//6 Set The Rightmost Unset Bit
int setBits(int N){
    // Write your code here.
    if( (N&N+1) == 0) return N;
    return N|N+1;
        //n-1 unset rightmost set
        //n+1 sets rightmost unset
}
//7 swap
//8 divide without /
int divideTwoInteger(int dividend, int divisor) {
    // Write your code here.
    bool isNegative=(dividend>=0) ^ (divisor>0);
    dividend=abs(dividend);
    divisor=abs(divisor);
    long long q=0,a=dividend,b=divisor;

    //a2
    for(int i=31;i>=0;i--){
        if((b<<i)<=a){
            a-=(b<<i);
            q|=(1<<i);
        }
    }
    //a1
    // while(a>=b){
    //     a-=b;
    //     q++;
    // }

    return isNegative? -q:q;
} 

//8.2
//1
// int countSetBits(int n){
//     int ans=0;
//     while(n){
//         n=n&n-1;
//         ans++;
//     }
//     return ans;
// }

int flipBits(int A, int B){
    // Write your code here.
    return __builtin_popcount(A^B); //a1
    //a2
    // return countSetBits(A^B);
}

//2 find 1 num odd times rest even times
int missingNumber(int n, vector<int> &arr){
    // Write your code here.
    int xorAll=0;
    for(int num:arr) xorAll^=num;
    return xorAll;
}

//3 non empty subsequence
vector<string> subsequences(string str){

    vector<string> ans;
    int n=str.size();
    for(int i=1;i<(1<<n);i++){  //for non-empty starting from 1 else 0
        string temp;
        for(int j=0;j<n;j++){
            if(i & (1<<j) ) temp+=str[j];
        }
        ans.push_back(temp);
    }
    return ans;
    
}

//4 xor of all from L to R
int f(int n){
    if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else if(n%4==3) return 0;
    else return n;
}

int findXOR(int L, int R){
    // Write your code here.
    return f(L-1)^f(R);
}

//5 twoOddNum
vector<int> twoOddNum(vector<int> arr){
    // Write your code here.
    int xorAll=0;
    for(auto num:arr) xorAll^=num;

    int differentBit= xorAll & ~(xorAll-1);//retain rightmost set bit
        //or x&(-x); -x is 2's complement(1's complement +1)

    int n1=0,n2=0;

    for(auto num:arr){
        if(num & differentBit) n1^=num;
        else n2^=num;
    }

    if(n1>n2) return {n1,n2};
    return {n2,n1};
}
//8.3
//1
int* printDivisors(int n, int &size){
// Write your code here
    int *v=new int[n];
    size=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            v[size++]=i;
            if(n/i!=i){
                v[size++]=n/i;
            }
        }
    }
    sort(v,v+size);
    return v;
}
//2 unique primes
vector<int> countPrimes(int n)
{
    // Write your code here.
    vector<int> ans;
    for(int i=2;i*i<=n && n>1;i++){
        if(n%i==0){
            ans.push_back(i);
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1) ans.push_back(n);
    return ans;
}
//a2 sieve ptc

//3 n^r
#define mod 1000000007
int power(int N, int R){
    // Write your code here.
    if(R==0) return 1;
    //either
    long long half=power(N, R/2);
    long long  full=(half*half)%mod;
    if(R&1) full=(full*N)%mod;

    //or
    // int half=power(N, R/2);
    // int full=(half*1ll*half)%mod;
    // if(R&1) full=(full*1ll*N)%mod;

    return full;
}
//9 stacks & queues
//9.1
//1 stack using array
// Stack class.
class Stack {
    //use this to differentiate between local variable and member variable
public:
    vector<int> s;
    int topIndex;
    int size;
    Stack(int capacity) {
        // Write your code here.
            //This is not mandatory, using this gives clarity that we are accessing member variables and not local variables
        this->s.resize(capacity);
        this->topIndex=-1;
        this->size=capacity;
    }

    void push(int num) {
        // Write your code here.
        if(topIndex<size-1){
            s[++topIndex]=num;
        }
    }

    int pop() {
        // Write your code here.
        if(topIndex>=0){
            return s[topIndex--];

        }else{
            return -1;
        }
    }
    
    int top() {
        // Write your code here.
        if(topIndex>=0){
            return s[topIndex];

        }else{
            return -1;
        }
    }
    
    int isEmpty() {
        // Write your code here.
        return topIndex==-1;
    }
    
    int isFull() {
        // Write your code here.
        return topIndex==size-1;
    }
    
};

//2 queue using array
//for queue we need 2 pointers as insertion and deletion occurs at two different places(front and back) while in stack insertion and deletion occurs at one place at the top
class Queue {
    int front, rear;
    vector<int> arr;
    

public:
//private members can be accessed and modified within member functions of the same class.
    Queue()
    {
        front = 0;
        rear = 0;
        arr.resize(100001);
    }

    // Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e)
    {
        // Write your code here.
        // if(rear<arr.size())  //bydefault it will be less as per constraint
            arr[rear++]=e;
    }

    // Dequeue (retrieve) the element from the front of the queue.
    int dequeue()
    {
        // Write your code here.
        if(front==rear) return -1;
        return arr[front++];
    }
};
//3 stack using queue
    void push(int element) {
        // Implement the push() function.
        //a1
        q2.push(element);
        while(!q1.empty()){
            q2.push(q1.front());    //top incorrect
            q1.pop();
        }
        swap(q1,q2);
        //a2
        // int curr=q1.size();
        // q1.push(element);

        // while(curr--){
        //     int first=q1.front();
        //     q1.pop();
        //     q1.push(first);
        // }

        //a3
        //push efficient & pop efficient(a1&a2)
    }

//a4 ptc
class Stack {
    // Define the data members.

   public:
    Stack() {
        // Implement the Constructor.
    }
    queue<int>q1;
    queue<int>q2;

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
       return q1.size()+q2.size();
    }

    bool isEmpty() {
       if(q1.empty() && q2.empty()) return true;
       else
       return false;
    }

    void push(int element) {

       if(q1.empty() && q2.empty()) q1.push(element);
       else if(q2.empty()) q1.push(element);
       else q2.push(element);

    }

    int pop() {
       if(q1.empty() && q2.empty()) return -1;
       else if(q1.empty()){
           int temp;
           while(!q2.empty()){
               temp = q2.front();
               q2.pop();
               if(!q2.empty())
               q1.push(temp);
           }
           return temp;
       }
       else{
           int temp;
           while(!q1.empty()){
               temp = q1.front();
               q1.pop();
                if(!q1.empty())
               q2.push(temp);
           }
           return temp;
       }
    }

    int top() {
       if(q1.empty() && q2.empty()) return -1;
       else if(q1.empty()) return q2.back();
       else return q1.back();
    }
};

//4 queue using stack
class Queue {
    // Define the data members(if any) here.
    stack<int> s1,s2;
    
    public:
    Queue() {
        // Initialize your data structure here.

    }

    void insertAtbottom(stack<int> &s1,int val){
        if(s1.empty()){
            s1.push(val);
            return;
        }
        int front=s1.top();
        s1.pop();
        insertAtbottom(s1,val);
        s1.push(front);
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        //a1
        // while(!s1.empty()){
        //     s2.push(s1.top());
        //     s1.pop();
        // }
        // s1.push(val);
        // while(!s2.empty()){
        //     s1.push(s2.top());
        //     s2.pop();
        // }
        //a2 insert at bottom of stack
        insertAtbottom(s1,val);
    }
//5
//a1 stack using linked list
class Stack
{
    //Write your code here
    Node* head;
    int size;
    // list<int> ll;

public:
    Stack()
    {
        //Write your code here
        // ll={};// or list<int> ll;
        head=NULL;
        size=0;
    }

    int getSize()
    {
        //Write your code here
        return size;
    }

    bool isEmpty()
    {
        //Write your code here
        return size==0;
    }

    void push(int data)
    {
        //Write your code here
        Node* curr=new Node(data);
        curr->next=head;
        head=curr;
        size++;
    }

    void pop()
    {
        //Write your code here
        if(head){
            head=head->next;
            size--;
        }
    }

    int getTop()
    {
        //Write your code here
        if(head) return head->data;
        return -1;
    }
};
//a2 without size
#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    int getSize() {
        int size = 0;
        Node* current = topNode;
        while (current != nullptr) {
            size++;
            current = current->next;
        }
        return size;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    void push(int element) {
        Node* newNode = new Node(element);
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        int topElement = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return topElement;
    }

    int top() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return topNode->data;
    }

    ~Stack() {
        Node* current = topNode;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.top() << std::endl;
    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Stack size: " << stack.getSize() << std::endl;
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
//6 queue using linked list
/**
 * Definition of linked list
 * class Node {
 * 
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 * 
 * Definition of Queue
 * struct Queue {
 *   Node* front;
 *   Node* rear;
 *   void push(int);
 *   int pop();
 *   
 *   Queue() {
 *       front = rear = NULL;
 *   }
 * };
 */

void Queue::push(int x) {
    // Write Your Code Here
    Node* curr=new Node(x);
    if(front){
        rear->next=curr;
        rear=curr;
    } else{
        front=rear=curr;
    }
    
}

int Queue::pop() {
    // Write Your Code Here
    if(!front) return -1;
    int first=front->data;
    front=front->next;
    // if(front==NULL) rear=NULL;
    return first;
}

//7
bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> lastOpeningBracket;

    for(char ch:s){
        if(ch=='(' || ch=='[' || ch=='{') {
            lastOpeningBracket.push(ch);
        }else if(ch==')'){
            if(lastOpeningBracket.empty() || lastOpeningBracket.top()!='(') return 0;
            lastOpeningBracket.pop();
        } else if (ch == ']') {
            if (lastOpeningBracket.empty() || lastOpeningBracket.top() != '[')
              return 0;
            lastOpeningBracket.pop();
        } else if (ch == '}') {
            if(lastOpeningBracket.empty() || lastOpeningBracket.top()!='{') return 0;
            lastOpeningBracket.pop();
        }
    }

    return lastOpeningBracket.empty();
}
//a2
bool matching(char a,char b){
  return (a == '(' && b == ')') || (a == '[' && b == ']') ||
         (a == '{' && b == '}');
}

bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> openings;
    for(char ch:s){
        if(ch=='(' || ch=='[' || ch=='{') openings.push(ch);
        else if(openings.empty()) return 0;
        else if(!matching(openings.top(),ch)) return 0;
        else openings.pop();
    }

    return openings.empty();
}
//8
//a1 maintain 2 stacks 1 normal & other mini
    //push in mini if ele<=mini.top(), pop from mini if normal.top()==mini.top()
//a2 using 1 stack only
min stack (store the net change in minimum value due to addition of an element)
//code
#define ll long long
class MinStack {
public:
    stack<ll> st;
    ll mini;
    MinStack() {
        this->mini=INT_MAX;
    }
    
    void push(int val) {
        if(this->st.empty()) {
            this->st.push(val);
            mini=val;
        }
        else{
            this->st.push(val-mini);
            if(val<mini) mini=val;
        }
        
    }
    
    void pop() {
        if(!this->st.empty()){
            if(this->st.top()<0) {
                this->mini=this->mini - this->st.top();
               
            }
            this->st.pop();
        }
    }
    
    int top() {
        if(this->st.size()==1) return this->st.top();
        else if(this->st.top()<0) return mini;
        else return mini+this->st.top();
    }
    
    int getMin() {
        return mini;
    }
};

//9.2 Prefix, Infix, PostFix Conversion Problems
//1 infixToPostfix
#include <stack>
int precedence(char ch){
    if(ch=='^') return 4;
    if(ch=='*' || ch=='/') return 3;
    if(ch=='+' || ch=='-') return 2;
    return 1;//for (
}

string infixToPostfix(string exp){
    // Write your code here
    string ans;
    stack<char> st;
    for(auto ch:exp){
        if((ch>='a' && ch<='z')||(ch>='0' && ch<='9')) ans+=ch;
        else if(ch=='(') st.push(ch);
        else if(ch==')'){
            while(st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && precedence(st.top())>=precedence(ch)){
                    //>= Greater than equal to because we want higher precedence operator to evaluate first and also if precedence same that operator should be evaluated first based on evaluating from left to right
                ans+=st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty() ){
        ans+=st.top();
        st.pop();
    }   
    return ans;
}
//2&3 prefix to infix &postfix
reverse and evaluate
//4&5 postfix to infix/prefix
Three stacks value of integers, infix of Strings, and prefix of Strings. For operands pushing all three stacks. For operator push v1 operator V2 in value stack, push ( v1 operator v2 ) in infix stack, and push in operator V1 V2 in prefix stack.
//6 infix to prefix
stack<string> prefix
stack<char> operator

If operand push into pre and post stack. Opening bracket push into operator stack. Closing bracket pop till opening bracket. Operator of lower precedence then push into operator stack else evaluate till operator stack becomes empty or we get a lower precedence operator. 
While evaluating for pre operator val1 val2, for post val1 val2 operator.

//9.3 
//1 nextGreaterElement
//a1
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
    // Write your code here
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]>=st.top()) {
            st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(arr[i]);
    }
    return ans;
}
//a2
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
    // Write your code here
    vector<int> ans(n);
    stack<int> st;//remaining idx ans
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
                //check current element can be ans to which previous idx
            ans[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        ans[st.top()]=-1;
        st.pop();
    }
    return ans;
}
//2 nextGreaterElementII in cyclic array
#include <stack>
vector<int> nextGreaterElementII(vector<int>& arr) {
    // Write your code here.
    int n=arr.size();
    vector<int> ans(n);
    stack<int> st;
    //finding maximum wont work 5 6 7 1 2 3
    for(int i=2*n-1;i>=0;i--){
            //like traversing twice but storing ans only once
        while(!st.empty() && arr[i%n]>=st.top()) {
            st.pop();
        }
        if(i<n) ans[i]=st.empty()?-1:st.top();
        st.push(arr[i%n]);
    }
    return ans;
}
//3 next smaller
//4 Count Of Greater Elements To The Right
brute O(n*q)
//5 
long long getTrappedWater(long long* arr, int n) {
    // Write your code here.
    vector<long long> rightMax(n);
    long long rightMaxi=0;
    for(int i=n-1;i>=0;i--){
        rightMaxi=max(rightMaxi,arr[i]);
        rightMax[i]=rightMaxi;
    }

    long long ans=0, leftMaxi=0;
    for(int i=0;i<n;i++){
        leftMaxi=max(leftMaxi,arr[i]);

        ans+=min(leftMaxi,rightMax[i])-arr[i];
    }
    return ans;
}
//a2 ptc Peak Elevation Approach

//a3 2 ptr
long long getTrappedWater(long long* arr, int n) {
    // Write your code here.
    long long ans=0,lmax=0,rmax=0;
    int l=0,r=n-1;
    while(l<=r){
        if(arr[l]<=arr[r]){
        // if(lmax<=rmax){
                //min(lmax,rmax)=lmax
            lmax=max(lmax,arr[l]);
            ans+=lmax-arr[l];
            l++;
        }else{
                //min(lmax,rmax)=rmax
            rmax=max(rmax,arr[r]);
            ans+=rmax-arr[r];
            r--;
        }
    }
    return ans;
}

//6 sumSubarrayMins
#include <bits/stdc++.h>
using namespace std;
int sumSubarrayMins(vector<int>&arr) {
    // Write your code here.
    //a1 find next smaller & previous smaller in 2 iteration
    //a2 in 1 iteration
    int n=arr.size(),ans=0,mod=1e9+7;
    stack<int> st;
    
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]<=arr[st.top()]){    //<= for duplicates
            int nsei=i;//next smaller element idx
            int elementIdx=st.top();
            st.pop();
            int psei=st.empty() ? -1:st.top();//previous  smaller element idx
            //contribution of each element=element*left*right
                //2 3 1 4 5 6 so for 1 left (2 3 1 ) & right (1 4 5 6)
                //so we can start from 2 3 1 and end at 1 4 5 6 total 3*4 =12 subarrays
            // ans+=( 1ll*(arr[elementIdx])*(elementIdx-psei)*(nsei-elementIdx) )%mod;
            //1ll not working
            ans+=( (arr[elementIdx])*(elementIdx-psei)*(nsei-elementIdx) )%mod;
                //error if using [()]
            ans%=mod;
        }
        st.push(i);//missed
    }
//we can skip the next while loop by
    //        while(!st.empty() && (i==n || nums[i]>=nums[st.top()])){

    while(!st.empty()){
        int nsei=n;//next smaller element idx
        int elementIdx=st.top();
        st.pop();
        int psei=st.empty() ? -1:st.top();//previous  smaller element idx
        ans+=((arr[elementIdx])*(elementIdx-psei)*(nsei-elementIdx) )%mod;
        ans%=mod;        
    }

    return ans;

}
//modulus arithmetic
a+b=(a+b)%m 
a*b=(a%m * b%m)%m 
a-b=(a-b+m)%m 

//7
vector<int> collidingAsteroids(vector<int> &asteroids)
{
    //    Write your code here.
    stack<int> st;
    for(auto x:asteroids){
        if(x<=0){
            while(!st.empty() && st.top()>0 && st.top()<-x) st.pop();

            if(st.empty() || st.top()<=0) st.push(x);
            else if(st.top()==-x) st.pop();
        }else st.push(x);
            
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
//8
int rangeSum(vector<int>&nums){
    // Write your code here.
    stack<int> st;
    int ans=0,n=nums.size();
    //ans+=maximums
    for(int i=0;i<=n;i++){
        while(!st.empty() && (i==n || nums[i]>=nums[st.top()])){
            int curr=st.top();
            st.pop();
            int psei=st.empty()?-1:st.top();
            ans+=(nums[curr] * (i-curr) *(curr-psei));
        }
        st.push(i);
    }
    st.pop();
    //ans-=minimums
    for(int i=0;i<=n;i++){
        while(!st.empty() && (i==n || nums[i]<=nums[st.top()])){
            int curr=st.top();
            st.pop();
            int psei=st.empty()?-1:st.top();
            ans-=(nums[curr] * (i-curr) *(curr-psei));
        }
        st.push(i);
    }
    st.pop();
    //we can club both these loops into 1 using
            // while( !st.empty() && ( (z==2 && arr[i]>=arr[st.top()] ) || (z==1 && arr[i]<=arr[st.top()] )   ) ){
//        while(!st.empty() && (i==n || ( (z==1 && nums[i]>=nums[st.top()]) || (z==2 && nums[i]<=nums[st.top()]) )    ) ){

    return ans;
}
//9 removeKDigits to get lowest num
    //always think of most significant digit
string removeKDigits(string num, int k) 
{
    // Write your code here.
    int n=num.size();
    // if(k==n) return "0";
    string ans;//use string as stack
    for(int i=0;i<n;i++){
        while(k && ans.size() && num[i]<ans.back()){
            ans.pop_back();
            k--;
        }
        ans+=num[i];
    }

     //if required deletion were not made. eg 2 3 4 k=2
    while(k--){
        ans.pop_back();
    }

    //if leading 0
    int i=0;
    while(i<ans.size() && ans[i]=='0') i++;
    ans=ans.substr(i);

    //if empty
    return ans.empty() ? "0" : ans;
}

//10 largestRectangle
 #include <stack>
 int largestRectangle(vector < int > & heights) {
   // Write your code here.

    // Height * (next smaller - previous smaller - 1) 
    // Strictly smaller as with equal height we can expand. 
    // We will stop our expansion as we encounter a strictly smaller

    int maxans=0, n=heights.size();
    stack<int> st;
    for(int i=0;i<=n;i++){
      while(!st.empty() && (i==n || heights[i]<heights[st.top()] ) ){
        int curr=heights[st.top()];
        st.pop();
        int pre=st.empty() ? -1:st.top();
        int ans=curr*(i-pre-1);
        maxans=max(maxans,ans);
      }
      st.push(i);
    }
    return maxans;
 }
//a2 segment tree ptc

//11 Maximum Size Rectangle Sub-matrix With All 1's

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
    // Write your code here.
    int maxans=0;
    vector<int> v(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // if(mat[i][j]) v[j]+=mat[i][j];
      if(mat[i][j]) v[j]++;
            else v[j]=0;
        }
        int ans=largestRectangle(v);
        maxans=max(ans,maxans);
    }
    return maxans;
}
//a2 dp ptc

//9.4
//1
vector<int> maxSlidingWindow(vector<int> &arr, int n, int k){
    // Write your code here.
    vector<int> ans;
    deque<int> deq;//since removal at both ends
        //in queue removal only at start
    for(int i=0;i<n;i++){
        if(!deq.empty() && deq.front()==i-k) deq.pop_front();//out of window

        while(!deq.empty() && arr[deq.back()]<=arr[i]) deq.pop_back();
        deq.push_back(i);

        if(i>=k-1) ans.push_back(arr[deq.front()]);
    }
    return ans;
}
//2 find previous >= curr
vector<int> findStockSpans(vector<int>& prices) {
    // Write your code here.
    int n=prices.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i=n-1;i>=-1;i--){
        while(!st.empty() && (i==-1 || prices[i]>=prices[st.top()] )  ){
            int curr=st.top();
            st.pop();
            ans[curr]=curr-i;
        }
        st.push(i);
    }
    return ans;
}
//3
int findCelebrity(int n) {
    // Write your code here.
    stack<int> st;
    for(int i=0;i<n;i++) st.push(i);

    while(st.size()>1){
        int one=st.top();
        st.pop();
        int two=st.top();
        st.pop();
    //if one knows two, one cant be celebrity else two cant be celebrity.
        if(knows(one,two)) st.push(two);
        else st.push(one);
    }

    int candidate=st.top();
    for(int i=0;i<n;i++){
        if(i==candidate) continue;

        if( (knows(candidate,i)) || !(knows(i,candidate)) ) return -1;
    }
    return candidate;

}
//a2 2 ptr
    int i=0,j=n-1;
    while(i<j){
        if(knows(i,j)) i++;
        else j--; 
    }
    int candidate=i;
//4 LRU
//5 LFU

//10 Sliding Window & 2ptr
//10.1 medium
//1
#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int ans=1, n=input.size(), i=0;
    unordered_set<char> used;
    for(int j=0;j<n;j++){
        char ch=input[j];
        //window will end at j, make adjustment of i to make window valid
        if(used.find(ch) != used.end()){
            while(input[i] != ch){
                used.erase(input[i]);
                i++;
            }
            used.erase(input[i]);
            i++;
        }
        used.insert(ch);
        ans=max(ans,j-i+1);
    }
    return ans;
}
//a2
    vector<int> f(256,-1);// f stores last found at
    int l=0,ans=0,n=input.size();
    for(int r=0;r<n;r++){
        if(f[input[r]]>=l) l=f[input[r]]+1;//if last found within current window then 
        // start window post last found
        ans=max(ans,r-l+1);
        f[input[r]]=r;
    }
    return ans;
//2 Maximum Consecutive Ones with k replacing 
int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int ans=0,l=0;
    for(int r=0;r<n;r++){
        if(arr[r]==0) k--;

        while(k<0){
            if(arr[l]==0) k++;
            l++;
        }

        ans=max(ans,r-l+1);
    }
    return ans;
}
//3 findMaxFruits with 2 baskets
    //max subarray size with atmost 2 distinct elements
int findMaxFruits(vector<int> &arr, int n) {
    // Write your code here.
    unordered_map<int,int> visited; //tree count
    int ans=0, left=0;
    for(int right=0;right<n;right++){
        visited[arr[right]]++;

        while(visited.size()>2){
            if(visited[arr[left]]-- ==1 ) visited.erase(arr[left]);
            left++;
        }

        ans=max(ans,right-left+1);
    }
    return ans;
}
//4
//ABCCAA k=2
//ans=4
//a1 brute tle
int longestRepeatingSubstring(string &str, int k) {
    // Write your code here.
    int maxans=0,n=str.size();
    for(int i=0;i<n;i++){
        vector<int> f(26,0);
        int maxi=0;
        for(int j=i;j<n;j++){
            f[str[j]-'A']++;
            maxi=max(maxi,f[str[j]-'A']);

            int currentLength=j-i+1;
            if(currentLength-maxi<=k){
                maxans=max(maxans,currentLength);
            }
        }
    }
    return maxans;
}
//a2
int longestRepeatingSubstring(string &str, int k) {
    // Write your code here.
    int n=str.size(), i=0,j=0,maxi=0;
    // map<char,int> um;    //map & unordered_map 1 test case failed so using vector
    vector<int> f(26,0);
    while(j<n){
        // um[str[j]]++;
        f[str[j]-'A']++;
        maxi=max(maxi,f[str[j]-'A'] );

        if(j-i+1-maxi>k){
            f[str[i]-'A']--;
            i++;
        }
        j++;
    }
    return j-i;
}
//5
//a1 brute
int subarrayWithSum(vector<int> &arr, int k) {
    // Write your code here.
    int ans=0, n=arr.size();
    for(int i=0;i<n;i++){
        int c=0;
        for(int j=i;j<n;j++){
            c+=arr[j];
            if(c==k) ans++;
            if(c>k) break;
        }
    }
    return ans;
}
//a2 atmost(3)-atmost(2)=exactly(3)
int count(vector<int> &arr, int k) {
    if(k<0) return 0;
    
    int ans=0, i=0, j=0, n=arr.size();
    while(j<n){
        if(arr[j]) k--;
        while(k<0){
            if(arr[i]) k++;
            i++;
        }
        ans+=j-i+1;//all ending at idx j
        j++;//missed
    }
    return ans;
}

int subarrayWithSum(vector<int> &arr, int k) {
    // Write your code here.
    // atmost(3)-atmost(2)=exactly(3)
    return  count(arr,k)-count(arr,k-1);
}
//a3 prefix
int subarrayWithSum(vector<int> &arr, int k) {
    // Write your code here.
    int n=arr.size() ;
    vector<int> f(n+1,0);
    f[0]=1;//empty

    int count1=0, ans=0;
    for(int i=0;i<n;i++){
        if(arr[i]) count1++;
        int remove=count1-k;    //if we have 4 1's and we need k=3 1's remove all prefix which have 1 1's
        if(count1>=k) ans+=f[remove];
        f[count1]++;
    }
    return ans;
}
//a4
int subarrayWithSum(vector<int> &arr, int k) {
    // Write your code here.
    int c=0,f=0,ans=0;
    int i=0,j=0, n=arr.size();
    while(j<n){
        c+=arr[j];
        if(c==k) f++;
        if(c>k){
            while(c>k){
                c-=arr[i];
                i++;
                ans+=f;
            }
            f=1;
        }
        j++;
    }
    while(c==k){
        c-=arr[i];
        i++;
        ans+=f;
    }
    return ans;
}

//6 count subarrays with k odd nums
// same as 5th

//7 countSubstring with a,b,c
int countSubstring(string s){
    // Write your code here.
    int ans=0, n=s.size(), a=-1, b=-1, c=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='a') a=i;
        else if(s[i]=='b') b=i;
        else c=i;

        ans+=min(a,min(b,c))+1;
        //to end at current idx we need to start at min of last occurence of a,b,c.
    }
    return ans;
}
//a2 atmost(3)-atmost(2)=exactly(3)
//tle with map, might pass with array
int count(string &s,int k){
    int ans=0;
    int i=0,j=0,n=s.size();
    if(k==3) return n*(n+1)/2;  //all substrings with atmost 3 only as there are only 3 chars a,b,c.
    map<char,int> um;
    for(;j<n;j++){
        um[s[j]]++;
        while(um.size()>k){
            if(um[s[i]]--==1) um.erase(s[i]);
            i++;
        }
        ans+=j-i+1;
    }
    return ans;
}

int countSubstring(string s){
    // Write your code here.
    return count(s,3)-count(s,2);
}
//a2.2
//passed with vector
int count(string &s,int k){
    int ans=0;
    int i=0,j=0,n=s.size();
    if(k==3) return n*(n+1)/2;  //all substrings with atmost 3 only as there are only 3 chars a,b,c.
    // map<char,int> um;
    vector<int> v(3,0);
    int size=0;
    for(;j<n;j++){
        // um[s[j]]++;
        v[s[j]-'a']++;
        if(v[s[j]-'a']==1) size++;
        while(size>k){
            if(v[s[i]-'a']--==1) size--;
            i++;
        }
        ans+=j-i+1;
    }
    return ans;
}

int countSubstring(string s){
    // Write your code here.
    return count(s,3)-count(s,2);
}

//8
    // 1 100 2 3 k=2 cant just select whichever end we get higher. we might get higher even after selecting lower end 
//a1 if we take maximums from end then we will left with minimum subarray in middle
    //to get max we need to subtract min from total
int maxPoints(vector<int>&arr , int K){
    // Write your code here.
    int n=arr.size(), sum=0,total=0;
    for(int i=0;i<n-K;i++){
        sum+=arr[i];
        total+=arr[i];
    }
    int minans=sum;
    for(int i=n-K;i<n;i++){
        sum+=(arr[i]-arr[i-(n-K)]);
        minans=min(minans,sum);
        total+=arr[i];
    }
    return total-minans;//missed total-
}
//a2 trying all options
    //from left k, right 0. k-1 1. k-2 2
    //take sum of first k, then add 1 from right and remove 1 from left
int maxPoints(vector<int>&arr , int k){
    // Write your code here.
    int sum=0, n=arr.size();
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    int maxans=sum;
    for(int i=1;i<=k;i++){
        sum+=arr[n-i]-arr[k-i];
        maxans=max(maxans,sum);
    }
    return maxans;
}
//10.2
//1 Longest Substring with At Most K Distinct Characters
//2  Subarrays With ‘K’ Distinct Values
//3 Minimum Window Substring ptc
//4 Minimum Window Subsequence ptc

//11 Heaps

//11.0 intro
//1 
// heap: Heap is a complete binary tree which satisfies heap's property
// binary tree: atmost 2 child
// complete binary tree: All levels are fully filled and last level is filled from left side
// heap's property: For Max heap, value of parent is greater than value of child. Root has the maximum value.
//Since complete binary tree height is logn and we can denote the binary using vector

//0 index 
left=2*i+1, right=2*i+2, parent=(i-1)/2
//1 index
left=2*i, right=2*i+1, parent=i/2
//pg1

//11.1
//1 implement heap. push & pop
void push(vector<int> &heap, int x){
    heap.push_back(x);
    int pos=heap.size()-1;
    //pos=0 means root
    while(pos>0){
        int parent=(pos-1)/2;
        if(heap[parent]<heap[pos]){
            swap(heap[parent],heap[pos]);
            pos=parent;
        }else break;
    }
}

int pop(vector<int> &heap)
{
    // Write you code here.
    if(heap.empty()) return -1;

    int ans=heap[0];
    int n=heap.size();
    heap[0]=heap[n-1];
    heap.pop_back();
    n--;

    int idx=0;
    while(idx<n){
        int left=2*idx+1,right=2*idx+2;
        //a2
        int largest=idx;
        if(left<n && heap[left]>heap[largest]) largest=left;
        if(right<n && heap[right]>heap[largest]) largest=right;

        if(largest!=idx){
            swap(heap[largest],heap[idx]);
            idx=largest;
        }else break;
        //a1
        // if(left>=n && right>=n) break;//missed
        // int lval=left<n?heap[left]:-1;
        // int rval=right<n?heap[right]:-1;

        // int largest=lval>rval?left:right;

        // if(heap[idx]<heap[largest]){
        //     swap(heap[idx],heap[largest]);
        //     idx=largest;
        // }else break;

    }

    return ans;
}
//2 implement min heap
similar to 1

//3 
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for(int i=1;i<n;i++){
            if(arr[i]>arr[(i-1)/2]) return 0;
        }
        return 1;
        
        //a2
    //     for(int i =0;i<=n/2;i++){
    //       if((arr[i] < arr[(2*i)+1]) || (arr[i] < arr[(2*i)+2])){
    //             return false;
    //       }
    //   }
    }

//4 MinToMaxHeap
void heapify(int n, vector<int>&arr, int idx){
    while(idx<n){
        int largest=idx;
        int left=2*idx+1,right=2*idx+2;
        if(left<n && arr[left]>arr[largest]) largest=left;
        if(right<n && arr[right]>arr[largest]) largest=right;

        if(largest!=idx){
            swap(arr[largest],arr[idx]);
            idx=largest;
        }else break;
    }
}

vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
    // Write your code here.
    vector<int> ans(arr);
    for(int i=n/2-1;i>=0;i--){
        heapify(n, ans, i);
    }
    return ans;
}

//11.2
//1 kLargest
#include <bits/stdc++.h>
vector<int> kLargest(int arr[], int n, int k) {
    // Write your code here
    priority_queue<int,vector<int>,greater<int> >minHeap;

    for(int i=0;i<n;i++){
        if(i<k) minHeap.push(arr[i]);
        // if(minHeap.size()<k) minHeap.push(arr[i]);
        else if(arr[i]>minHeap.top()){
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    vector<int> ans;
    while(!minHeap.empty()){
        ans.push_back(minHeap.top());
        minHeap.pop();
    }

    return ans;
    //a2 using max heap
    //push all into heap than pop for k times that will give k largest
        //space O(n) worse than O(k)
}
//2 k smallest
//3 mergeKSortedArrays
//comparator when comp returns true means correct order
https://www.youtube.com/watch?v=-xyju56LLMI
The element at last of container has higher priority 
For min heap, minimum element should be at last so we want greater at start so if a>b return true its correct order
//a1 insert all into heap and pop   //tle since we store all elements. Not using advantage of sorted array
//a2 merge 2 
#include <bits/stdc++.h>
//function to merge two sorted arrays
void merge (vector<int>& ans, vector<int> arr) {

    int i = 0, j = 0;
    vector<int> tempMerged;

    while (i < ans.size() && j < arr.size()) {

        if (ans[i] < arr[j]) tempMerged.push_back(ans[i++]);

        else tempMerged.push_back(arr[j++]);
    }

    while (i < ans.size()) tempMerged.push_back(ans[i++]);

    while (j < arr.size()) tempMerged.push_back(arr[j++]);

    ans.clear();

    for (int i = 0; i < tempMerged.size(); i++) {
        ans.push_back(tempMerged[i]);
    }

    return;
}


vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){

    vector<int> ans = kArrays[0];

    for (int i = 1; i < k; i++) {

        merge(ans, kArrays[i]);

    }

    return ans;
}

//a3
#include <bits/stdc++.h> 
class triplet{
    public: //missed
    int val,row,col;
    triplet(int v,int r,int c){
        val=v;
        row=r;
        col=c;
    }
};
class compare{
    //overloading 
    public: //if struct bydefault public
    bool operator()(triplet &a,triplet &b){
        return a.val>b.val;
    }
};
// class compare{
//     //overloading 
//     public:
//    // const means no modification
//     bool operator()(const triplet& a, const triplet& b) const {
//         return a.val > b.val;
//     }
// };

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int> ans;
    priority_queue< triplet, vector<triplet>, compare> mini;
    for(int i=0;i<k;i++){
        triplet curr(kArrays[i][0],i,0);
        mini.push(curr);
//or
        // triplet *curr=new triplet(kArrays[i][0],i,0);
        // mini.push(*curr);
    }
    while(!mini.empty()){
        triplet temp=mini.top();
        mini.pop();
        ans.push_back(temp.val);

        int arrNum=temp.row, pos=temp.col;
        if(pos+1<kArrays[arrNum].size()){
            // triplet next(kArrays[arrNum][pos+1],arrNum,pos+1);
            // mini.push(next);
//or
            mini.push(triplet (kArrays[arrNum][pos+1],arrNum,pos+1));
        }
    }
    return ans;
}
//4 mergeKLists
//a1 add all into vector. sort. make new list
//a2
Node<int>* merge(Node<int> *first, Node<int> *second) {

    if(!first)
        return second;
    if(!second)
        return first;
    if(first->data<second->data)
    {
        first->next=merge(first->next,second);
        return first;
    } else {
      second->next = merge(first, second->next);
      return second;
    }
}

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    // Write your code here.
    if(listArray.size()==0)
        return NULL;
    auto ans=listArray[0];
    for(int i=1;i<listArray.size();i++)
        ans=merge(ans, listArray[i]);
    return ans;
}
//a3
class comp{
    public:
    bool operator()(Node *a,Node *b){
        return a->data>b->data;
    }
};
Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    Node *dummy=new Node(-1),*tail=dummy;
    priority_queue<Node*,vector<Node*>,comp> mini;

    for(int i=0;i<listArray.size();i++){
        mini.push(listArray[i]);
    }
    while(!mini.empty()){
        Node* curr=mini.top();
        mini.pop();

        if(curr->next){
            mini.push(curr->next);
        }

        tail->next=curr;
        tail=curr;
    }
    // tail->next=NULL;
    return dummy->next;
}
//a3.2
head=null,tail=null. 
if(!head){
    head=curr;
    tail=curr;
}else{
    tail->next=curr;
    tail=curr;
}
//5 replaceWithRank
typedef pair<int, int> myPair;
class comp{
    public: //missed
    bool operator()(myPair &a,myPair &b){
        return a.first>b.first;
    }
};
vector<int> replaceWithRank(vector<int> &arr, int n) {
    // Write your code here.
    vector<int> ans(n);
    priority_queue<myPair, vector<myPair>, comp> mini;
    for(int i=0;i<n;i++){
        //any 1 of 3
        mini.push(myPair{arr[i],i});
        // mini.push(myPair(arr[i],i));
        // mini.push(make_pair(arr[i],i));
    }
    int rank=1;
    while(!mini.empty()){
        myPair curr=mini.top();
        mini.pop();
        ans[curr.second]=rank;

        while(!mini.empty() && curr.first==mini.top().first){
            myPair next=mini.top();
            mini.pop();
            ans[next.second]=rank;            
        }

        rank++;
    }
    return ans;

}
//a2 ptc
vector<int> replaceWithRank(vector<int> &arr, int n) {

    multimap<int, int> rankMap;

    for(int i = 0; i < arr.size(); i++) {

        rankMap.insert({arr[i], i});

    }

    

    int rank = 1;

    int prevValue = rankMap.begin()->first;

    for(auto x: rankMap) {

        if(prevValue != x.first) {

            rank++;

            prevValue = x.first;

        }

        arr[x.second] = rank;

    }

 

    return arr;

}
//6 task scheduler //mik ptc
//7 hands of straight //gfg ptc

//11.3
// 1
// 2 connect n ropes with min cost
    //take 2 smallest ropes connect and push sum
    priority_queue<int, vector<int> ,greater<int> >minHeap;
    for(int i=0;i<n;i++) minHeap.push(arr[i]);
    int ans=0;
    while(minHeap.size()>1){
        int s1=minHeap.top();
        minHeap.pop();
        int s2=minHeap.top();
        minHeap.pop();
        ans+=s1+s2;
        minHeap.push(s1+s2);
    }
    return ans;
// 3 Kthlargest in stream
class Kthlargest {
    priority_queue<int, vector<int> , greater<int> >mini;   //store k largest element

public:
//or
    // priority_queue<int, vector<int> , greater<int> >mini;   //store k largest element

    Kthlargest(int k, vector<int> &arr) {
        //writing here will give error
        // priority_queue<int, vector<int> , greater<int> >mini;   //store k largest element
        for(auto x:arr) mini.push(x);
    }

    int add(int num) {
        if(num>mini.top()){
            mini.pop();
            mini.push(num);
        }

        return mini.top();
    }

};
//ex kth largest in array using quick selct partition
// 4
typedef pair<int, pair<int,int>> SI;  // sumIdx
typedef pair<int, int> P;

class comp {
public:
    bool operator()(SI &a, SI &b) {
        return a.first < b.first;
    }
};

    vector<int> maxCombinations(int N, int C, vector<int> &A, vector<int> &B) {
    
        vector<int> ans;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
    
        int n1 = A.size() - 1, n2 = B.size() - 1;
        priority_queue<SI, vector<SI>, comp> maxi;
        maxi.push({A[n1] + B[n2], {n1, n2}});
    
        set<P> used;
    
        while (C) {
            SI curr = maxi.top();
            maxi.pop();
            ans.push_back(curr.first);
            int cn1=curr.second.first, cn2=curr.second.second;
            C--;
            if (C == 0) break;
            if (used.find({cn1 - 1, cn2}) == used.end() && cn1 > 0) {
                maxi.push({A[cn1 - 1] + B[cn2], {cn1 - 1, cn2}});
                used.insert({cn1 - 1, cn2});
            }
            if (used.find({cn1, cn2 - 1}) == used.end() && cn2 > 0) {
                maxi.push({A[cn1] + B[cn2 - 1], {cn1, cn2 - 1}});
                used.insert({cn1, cn2 - 1});
            }
        }
        return ans;
    }
// 5 findMedian of stream
#include <bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
    
    // Write your code here 
    priority_queue<int> pqMax;
    priority_queue<int,vector<int>,greater<int> > pqMin;

    vector<int> ans;

    for(int i=0;i<n;i++){
        if(pqMax.empty() || arr[i]<=pqMax.top()){
            pqMax.push(arr[i]);
        }else{
            pqMin.push(arr[i]);
        }
//need to maintain maxhalf-minhalf=0 or 1
/*
___________  ___________
            max  min
*/

//make this shifts only when we need median, else keep pushing 

//if we finding median after inserting every new element we can replace both while with if
        while(pqMin.size()>pqMax.size()){
            pqMax.push(pqMin.top());
            pqMin.pop();
        }

        while(pqMin.size()+2<=pqMax.size()){
            pqMin.push(pqMax.top());
            pqMax.pop();
        }

        int maxiOfFirstHalf=pqMax.top();
        int miniOfSecondHalf= pqMin.empty() ? 0 : pqMin.top();

        if(i&1){
            ans.push_back((maxiOfFirstHalf+miniOfSecondHalf)/2);
        }else{
            ans.push_back(maxiOfFirstHalf);
        }

    }
    return ans;
}

// 6
//a1 ptc quick select on frequency array to partition k lowest freq on one side
        //pivot idx =n-k so on right we have k max freq elements
//a2 heap
typedef pair<int,int> P;
class comp{
    public:
    bool operator ()(P &a,P &b){
        return a.first<b.first;
    }
};
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;
    unordered_map<int,int> um;

    for(auto x:arr) um[x]++;
    priority_queue<P, vector<P>,comp > pqMax;
    for(auto x:um){
        pqMax.push({x.second,x.first}); //incorrect {um[x],x}
    }
    while(k--){
        P curr=pqMax.top();
        pqMax.pop();
        ans.push_back(curr.second);
    }
    return ans;
}
//a2.2
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    if (k == n)
    {
        return arr;
    }

    unordered_map<int, int> mp;

    // Build map where the key is element
    // and value is how often this element appears in 'ARR'.
    for (int ele : arr)
    {
        mp[ele]++;
    }

    // Elements in heap will be sorted in descending order
    // according to the frequency of the element.
    priority_queue<pair<int, int>> heap;

    // Build heap of maximum size 'K'.
    for (auto x : mp)
    {
        heap.push({x.second, x.first});
    }

    vector<int> ans(k);

    // Build output array.
    for (int i = 0; i < k; i++)
    {
        ans[i] = heap.top().second;
        heap.pop();
    }

    return ans;
}
//a3  buckets n arrays as freq of any element will be 0 to n
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> buckets(n+1);
    unordered_map<int,int> um;
    for(auto x:arr) um[x]++;
    for(auto x:um){
        buckets[x.second].push_back(x.first);
    }
    vector<int> ans;
    for(int i=n;i>=0 && k>0;i--){
        if(buckets[i].empty()) continue;
        for(auto x:buckets[i]){
            ans.push_back(x);
            k--;
        }
    }
    return ans;
}

//12 GREEDY
//12.1 easy
//1 assignCookie
int assignCookie(vector<int> &greed, vector<int> &size) {
    // Write your code here.
    sort(greed.begin(),greed.end());
    sort(size.begin(),size.end());

    int ans=0;
    int i=0,j=0, n1=greed.size(), n2=size.size();
    while(i<n2 && j<n1){
        if(size[i]>=greed[j]){
            ans++;
            i++;
            j++;
        }else{
            i++;
        }
    }
    return ans;
}
//or
        if (size[i] >= greed[j]) {
            ans++;
            j++;
        }
        i++;
// 2 fractional knapsack ptc
// 3
vector<int> MinimumCoins(int n)
{
    // Write your code here
    vector<int> v={1000,500,100,50,20,10,5,2,1};
    vector<int> ans;
    for(auto x:v){
        if(n>=x){
            int q=n/x;
            n=n%x;
            while(q--) ans.push_back(x);
        }
        if(n==0) break;
    }
    return ans;
}
// 4 lemonadeChange 5 10 20
bool lemonadeChange(vector<int> &bill) {
    // Write your code here.
    int c5=0,c10=0;
    for(auto x:bill){
        if(x==5){
            c5++;
        }else if(x==10){
            if(c5==0) return 0;
            c5--;
            c10++;
        }else if(x==20){
            if(c5>0 && c10>0){
                c5--;
                c10--;
            //used 10 before using 2 5 as if next 10 comes we need 5 and 5 is more flexible.
            }else if(c5>=3){    //missed
                c5-=3;
            }else return 0;
        }else return 0;
    }
    return 1;
}

// 5 Balanced Parentheses
bool matching(char a,char b){
    if( (a=='(' && b==')')
      || (a == '[' && b == ']') || (a == '{' && b == '}') ) return 1;
      return 0;
}

bool isBalanced(string S){
    // Write your code here.
    stack <char> open;
    for(auto ch:S){
        if(ch=='(' || ch=='[' || ch=='{') open.push(ch);
        else{
            if(open.empty()) return 0;
            if(matching(open.top(),ch)){
                open.pop();
            }else return 0;
        }
    }
    return open.empty();//missed
}
//a2
bool isBalanced(string S) {
  // Write your code here.
  stack<char> open;
  map<char, char> partner;
  partner[')'] = '(';//incorrect ['(']=')'
  partner[']'] = '[';
  partner['}'] = '{';

  for (auto ch : S) {
    if (ch == '(' || ch == '[' || ch == '{')
      open.push(ch);
    else {
      if (open.empty())
        return 0;
      if (partner[ch] == open.top()) {
        open.pop();
      } else
        return 0;
    }
  }
  return open.empty();
}

//12.2
// 1 maximumMeetings
//a1
int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int n=start.size();
    vector< pair<int,int> > v;
    for(int i=0;i<n;i++){
        v.push_back({start[i],end[i]});
    }
    sort(v.begin(),v.end());

    int ans=1, preEnd=v[0].second;
    for(int i=1;i<n;i++){
        //if overlapping take the one with lower end time
        if(v[i].first>preEnd){
            ans++;
            preEnd=v[i].second;
        }else{
            preEnd=min(preEnd,v[i].second);
        }
    }
    return ans;
}
//a2
bool comp(pair<int,int> &a,pair<int,int> &b){
    return a.second<b.second;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int n=start.size();
    vector< pair<int,int> > v;
    for(int i=0;i<n;i++){
        v.push_back({start[i],end[i]});
    }
    sort(v.begin(),v.end(),comp);

    int ans=1, lastMeet=0;
    for(int i=1;i<n;i++){
        if(v[i].first>v[lastMeet].second){
            ans++;
            lastMeet=i;
        }
    }
    return ans;
}
// 2
//a1
bool help(vector<int> &jump, int n,int idx){
    if(idx==n-1) return 1;
    if(idx>=n || jump[idx]==0) return 0;

    bool flag=false;
    for(int i=idx+1;i<=idx+jump[idx];i++){
        flag=help(jump,n,i);
        if(flag) break;
    }
    return flag;
}

bool jump_search(vector<int> &jump, int n){
    // Write your code here.
    return help(jump,n,0);
}
//a2  greedy
bool jump_search(vector<int> &jump, int n){
    // Write your code here.
    int reachable=0;
    for(int i=0;i<n && i<=reachable  && reachable<n ;i++){
        reachable=max(reachable,i+jump[i]);
    }
    return reachable>=n-1;
}
//a3 dp ptc

// 3
//a1 tle
void help(vector<int> &jump, int n,int idx,int cur,int &minans){
    if(idx==n-1){
        minans=min(cur,minans);
        return;
    }
    if(idx>=n || jump[idx]==0) return ;

    for(int i=idx+1;i<=idx+jump[idx];i++){
        help(jump, n, i, cur+1, minans);
    }
}

int minJumps(vector<int> &arr,int n) {
    // Write your code here.
    int minans=n;
    help(arr,n,0,0,minans);
    return minans==n? -1 : minans;
}
//a2 dp ptc
//a3 greedy
int minJumps(vector<int> &arr,int n) 
{
    // Write your code here.
    //bfs
    int steps=0, left=0, right=0;
    while(right<n-1 && left<=right){
        int nextRight=0;
        for(int i=left;i<=right;i++){
            nextRight=max(nextRight,i+arr[i]);
        }
        left=right+1;
        right=nextRight;
        steps++;
    }
    if(right>=n-1) return steps;
    return -1;
}
// 4 calculateMinPatforms
//a1
minHeap based
heap to store departure time of previous trains 
if minDeparture time of any previous train < arrival then pop else platform++
push current departure
//code
typedef pair<int,int> P;    //missed ;
bool comp(P &a,P &b){
    return a.first<b.first;
}
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    priority_queue<int,vector<int>,greater<int> > pqMin;

    vector<P> v;
    for(int i=0;i<n;i++) v.push_back({at[i],dt[i]});

    sort(v.begin(),v.end(),comp);

    int ans=1;
    pqMin.push(v[0].second);
    for(int i=1;i<n;i++){
        if(v[i].first>pqMin.top()){
            pqMin.pop();
        }else ans++;

        pqMin.push(v[i].second);
    }
    return ans;
}
//a2
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int ans=1;
    int i=1,j=0;
    while(i<n){
        if(at[i]>dt[j]){    //check if any previous train can depart  
            j++;//departing
        }else ans++;    //or adding new platform so no depart so no j++
        i++;
    }
    return ans;
}
//a3
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);

    int curr=0, maxans=0;
    int i=0,j=0;
    while(i<n){
        if(at[i]<=dt[j]){
            curr++;
            maxans=max(maxans,curr);
            i++;
        }else{
            curr--;
            j++;
        }
    }
    return maxans;
}
// 5 jobScheduling
//approach
Any job with deadline 2 can be completed at time to or anytime before 2 
For time 2 we will push all the jobs with time 2 into queue 
Then take out the maximum profit job. Rest will be present in the queue. 
Jobs in queue represent options, select best option.
for time 1...
//a1.1
#include <bits/stdc++.h>
typedef pair<int,int> P;
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    vector<P> v;
    int n=jobs.size();
    for(int i=0;i<n;i++) v.push_back({jobs[i][1],jobs[i][2]});

    sort(v.begin(),v.end());
    int ans=0,count=0;
    priority_queue<int> pqMax;
    int time=v[n-1].first;
    int idx=n-1;

    while(time>0){
        while(idx>=0 && v[idx].first==time){
            pqMax.push(v[idx].second);
            idx--;
        }
        if(!pqMax.empty()){
            ans+=pqMax.top();
            count++;
            pqMax.pop();
        }
        time--;
    }
    return {count,ans};
}
//a1.2
#include <bits/stdc++.h>
bool comp(vector<int> &a,vector<int> &b){
    return a[1]<b[1];
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int n=jobs.size();
   
    sort(jobs.begin(),jobs.end(),comp);

    int ans=0,count=0;
    priority_queue<int> pqMax;
    int time=jobs[n-1][1];
    int idx=n-1;

    while(time>0){
        while(idx>=0 && jobs[idx][1]==time){
            pqMax.push(jobs[idx][2]);
            idx--;
        }
        if(!pqMax.empty()){
            ans+=pqMax.top();
            count++;
            pqMax.pop();
        }
        time--;
    }
    return {count,ans};
}
//a2 
//https://www.youtube.com/watch?v=R6Skj4bT1HE
Sort all the jobs based on Profit 
Try to place max profit job in available slot if any 
Try to place as later as possible(check from deadline to 0) 
If able to place, mart that slot as filled and add profit of that job
//code
#include <bits/stdc++.h>
bool comp(vector<int> &a,vector<int> &b ){
    return a[2]>b[2];
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    //sort based on profit
    sort(jobs.begin(),jobs.end(),comp);

    int n=jobs.size();
    int maxDeadline;
    for(int i=0;i<n;i++){
        maxDeadline=max(maxDeadline,jobs[i][1]);
    }

    vector<int> slots(maxDeadline+1,-1);//-1 empty

    int count=0,profit=0;
    for(int i=0;i<n;i++){
        int currDeadline=jobs[i][1];
        for(int j=currDeadline;j>0;j--){
            if(slots[j]==-1){
                slots[j]=i;
                count++;
                profit+=jobs[i][2];
                break;//missed
            }
        }
    }
    return {count,profit};
}

//a3 ptc
#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    priority_queue<int> pq;
    int prof=0,time=0;
    sort(jobs.begin(),jobs.end(),[](vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    });
    for(int i=0;i<jobs.size();i++){
        if(jobs[i][0]>time){
            prof+=jobs[i][1];
            pq.push(-jobs[i][1]);
            time++;
        }else if(!pq.empty()&&-pq.top()<jobs[i][1]){
            prof+=pq.top();pq.pop();
            prof+=jobs[i][1];
            pq.push(-jobs[i][1]);
            time;
        }
    }
    return prof;
}


// 6 Candy
int requiredCandies(vector < int > &students) {
    // Write your code here.
    int n=students.size();
    vector<int> v(n,1);

// 1. If two students having the same grade are standing next to each other, they may receive the same number of candies.
//may not should
    for(int i=1;i<n;i++){
        if(students[i]>students[i-1]) v[i]=v[i-1]+1;
        // else if(students[i]==students[i-1]) v[i]=v[i-1];
    }
    for(int i=n-2;i>=0;i--){
        if(students[i]>students[i+1]){
            v[i]=max(v[i],v[i+1]+1);
        }
        // else if(students[i]==students[i+1]){
        //     v[i]=max(v[i],v[i+1]);
        // }
    }
    int ans=0;
    for(auto x:v) ans+=x;
    return ans;
}

//a2 O(1)
int requiredCandies(vector < int > &students) {
    // Write your code here.
    int n=students.size();
    int ans=n;
    int i=1;
    while(i<n){
        if(students[i]==students[i-1]){
            i++;
            continue;
        }
        int peak=0,dip=0;
        while(students[i]>students[i-1]){
            peak++;
            ans+=peak;
            i++;
            if(i==n) return ans;
        }
        while(i<n && students[i]<students[i-1]){
            dip++;
            ans+=dip;
            i++;
        }
        ans-=min(peak,dip);

    }
    return ans;
}

// 7 shortest job first scheduling algorithm.
typedef pair<int,int> P;
class comp{
    public:
    bool operator()(P &a,P &b ){
        return a.second>b.second;
    }
};
float sjf(int n, vector<int> &arrivalTime, vector<int> &burstTime) 
{
    // Write your code here.
    vector<P> v;
    for(int i=0;i<n;i++){
        v.push_back({arrivalTime[i],burstTime[i]});
    }
    sort(v.begin(),v.end());
    int time=v[0].first, wait=0, idx=0;
    priority_queue<P,vector<P>,comp> pqMin;

    while(idx<n){
        while(idx<n && v[idx].first<=time){
            pqMin.push(v[idx]);
            idx++;
        }
        // cout<<time<<" t "<<endl;
        if(!pqMin.empty()){
            wait+=time-pqMin.top().first;
            time+=pqMin.top().second;
            pqMin.pop();
        }
        // else time++;
        else time=v[idx].first; //since empty increase time till next job arrives

    }
    while(!pqMin.empty()){
        wait+=time-pqMin.top().first;
        time+=pqMin.top().second;
        pqMin.pop();
    }

    return 1.0*wait/n;

}
// 8 ptc Program for Least Recently Used (LRU) Page Replacement Algorithm

// 9 ptc addInterval
vector<vector<int>> addInterval(vector<vector<int>> &intervals, int n, vector<int> &newInterval)

{

    int new_int1 = newInterval[0];

    int new_int2 = newInterval[1];

    vector<vector<int>> ans;

    int i = 0;

 

    while (i < n && intervals[i][1] < new_int1) {

        ans.push_back(intervals[i]);

        i++;

    }

 

    while (i < n && intervals[i][0] <= new_int2) {

        new_int1 = min(new_int1, intervals[i][0]);

        new_int2 = max(new_int2, intervals[i][1]);

        i++;

    }

 

    ans.push_back({new_int1, new_int2});

 

    while (i < n) {

        ans.push_back(intervals[i]);

        i++;

    }

 

    return ans;

}
// 10 mergeIntervals
//a1 sort based on end time
#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
bool comp(vector<int> &a,vector<int> &b){
    // if(a[1]==b[1]) return a[0]<b[0];
    return a[1]<b[1];
}
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
        //sort based on endtime. if equal sort on starttime
    // 1 5 4
    // 4 6 6
    sort(intervals.begin(),intervals.end(),comp);

    vector<vector<int>> ans;
    int n=intervals.size();
    // ans.push_back(intervals[0]);
    for(int i=0;i<n;i++){
        // if(ans.back()[1]>=intervals[i][0]){
        //     ans.back()[1]=intervals[i][1];
        //     ans.back()[0]=min(ans.back()[0],intervals[i][0]);
        // }else{
        //     ans.push_back(intervals[i]);
        // }
        while(!ans.empty() && intervals[i][0]<=ans.back()[1]){
            intervals[i][0]=min(intervals[i][0],ans.back()[0]);
            ans.pop_back();
        }
        ans.push_back(intervals[i]);
    }
    return ans;

}
//a2 sort start time better
bool comp(vector<int> &a,vector<int> &b){
    return a[0]<b[0];
}
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    
    sort(intervals.begin(),intervals.end(),comp);//no need of comp as sorting ascending on first val

    vector<vector<int>> ans;
    int n=intervals.size();
    ans.push_back(intervals[0]);
    for(int i=1;i<n;i++){
        if(ans.back()[1]>=intervals[i][0]){
            //start time already lower. just update to max end
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;

}


// 11 minimumReschedules to make non overlapping
bool comp(vector<int> &a,vector<int> &b){
    return a[1]<b[1];
}

int minimumReschedules(int n, vector<vector<int>> &intervals) {
    // Write your code here.
    sort(intervals.begin(),intervals.end(),comp);
    //1-2 2-3 is not overlapping according to question
    int lastEnd=0, ans=0;
    for(int i=1;i<n;i++){
        if(intervals[i][0]<intervals[lastEnd][1]) ans++;
        else lastEnd=i;
    }
    return ans;
}
//13 Binary Trees
//13.0 intro
binary atmax 2 children
terms: root,subtree,leaf
types: 
full(every node has 0 or 2 children)
complete(All levels are completely filled except the last level 
Last level should be filled from as left as possible)
Perfect( All all leaves are at same level)
Balanced(height can be maximum of Logn) where n is the number of nodes
Degenerate(all nodes have at Max one child) 
If all have left child then its known as left skewed tree

//13.1
//2 create tree
//a1

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/
Node *help(vector<int> &arr,int idx){
    if(idx>=arr.size()) return NULL;
    Node *curr=new Node(arr[idx]);
    curr->left=help(arr, idx*2+1);
    curr->right=help(arr, idx*2+2);
    return curr;
}

Node* createTree(vector<int>&arr){
    // Write your code here.
    Node* root=help(arr,0);
    return root;
}
//a2 bfs 
Node* createTree(vector<int>&arr){
    // Write your code here.
    queue<Node*> q;
    Node* root=new Node(arr[0]);
    q.push(root);
    int level=0;

    while(!q.empty() && level<2){
        int n=q.size();
        int start=pow(2,level)-1;
        while(n--){
            Node *curr=q.front();   //q.first() q.top() incorrect
            q.pop();
            Node *left=new Node(arr[start*2+1]);
            Node *right=new Node(arr[start*2+2]);
            q.push(left);
            q.push(right);

            curr->left=left;
            curr->right=right;

            start++;

        }
        level++;
    }
    return root;
}
//a3 count iterations
Node* createTree(vector<int>&arr){
    // Write your code here.
    queue<Node*> q;
    Node* root=new Node(arr[0]);
    q.push(root);
    int count=0;

    while(!q.empty() && count<=2){
        
        Node *curr=q.front();   //q.first() q.top() incorrect
        q.pop();
        Node *left=new Node(arr[count*2+1]);
        Node *right=new Node(arr[count*2+2]);
        q.push(left);
        q.push(right);

        curr->left=left;
        curr->right=right;

        count++;
    }
    return root;
}
//4 5 6 7
void inorder(TreeNode* root,vector<int> &ans){
    if(root==NULL) return;
    //inorder left task right
    //pre task left right
    //post left right task
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    inorder(root,ans);
    return ans;
}
//pg1

//8a levelOrder
//a1 maintaining level
vector<int> levelOrder(TreeNode<int> * root){
    // Write your code here.
    vector<int> ans;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        while(n--){
            TreeNode<int> *curr=q.front();//        auto curr=q.front();
            q.pop();
            ans.push_back(curr->data);

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return ans;
}
//a2 bydefault level will be maintained as next level will be pushed after current level
vector<int> levelOrder(TreeNode<int> * root){
    // Write your code here.
    vector<int> ans;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        
        auto curr=q.front();
        q.pop();
        ans.push_back(curr->data);

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
        
    }
    return ans;
}
//a3 very slow
#include <bits/stdc++.h>
void traversal(TreeNode<int> *root,vector< pair<int,pair<int,int> > > &ans,int level,int &idx) {
    if(!root) return;

    ans.push_back({idx, {level, root->data}});
    idx++;

    traversal(root->left,ans,level+1,idx);
    traversal(root->right,ans,level+1,idx);

}

bool comp(pair<int,pair<int,int> > &a, pair<int,pair<int,int> > &b){
    if(a.second.first != b.second.first) 
        return a.second.first < b.second.first;
    return a.first<b.first;
}   

vector<int> levelOrder(TreeNode<int> * root){
    // Write your code here.
    vector< pair<int,pair<int,int> > > ans;//missed >>
    int idx=0;
    traversal(root,ans,0,idx);//missed to pass idx as varaible. (0,0) error. (0,idx) correct.

    sort(ans.begin(),ans.end(),comp);

    vector<int> final;
    for(auto x:ans) final.push_back(x.second.second);
    return final;
}

//8b ziz zag
//ptc

//9 Iterative Preorder Traversal of Binary Tree
#include <stack>
vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.
    stack<TreeNode<int>* > s;
    s.push(root);
    vector<int> ans;

    while(!s.empty()){
        auto curr=s.top();
        s.pop();
        ans.push_back(curr->data);

        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
    }
    return ans;
}
//10 Iterative Inorder Traversal of Binary Tree
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    stack<TreeNode*> s;
    // s.push(root);    //mistake
    TreeNode* curr=root;
    vector<int> ans;

    while(curr || !s.empty()  ){
        while(curr){
            s.push(curr);
            curr=curr->left;
        }

        curr=s.top();
        s.pop();
        ans.push_back(curr->data);

        curr=curr->right;
    }
    return ans;
}
//a2
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    stack<TreeNode*> s;
    TreeNode* curr=root;
    vector<int> ans;

    while(curr || !s.empty()  ){
        if(curr){
            s.push(curr);
            curr=curr->left;
        }else{
            curr=s.top();
            s.pop();
            ans.push_back(curr->data);

            curr=curr->right;
        }
 
    }
    return ans;
}
//11
vector<int> postorderTraversal(TreeNode *root)
{
    // Write your code here.
    stack<TreeNode*> s;
    s.push(root);
    vector<int> ans;
// In post order node will come last right will come second last left will come third last
    while(!s.empty()){
        TreeNode* curr=s.top();
        s.pop();
        ans.push_back(curr->data);
        if(curr->left) s.push(curr->left);
        if(curr->right) s.push(curr->right);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
//12 1 stack without reverse ptc
//13 all in 1
void travel(TreeNode *root,vector<vector<int>> &ans){
    if(root==NULL) return;

    int d=root->data;

    ans[1].push_back(d);

    travel(root->left, ans);

    ans[0].push_back(d);

    travel(root->right, ans);

    ans[2].push_back(d);

}


vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>> ans(3);
    travel(root,ans);
    return ans;
}
//a2 
1 (pre)call left, 2 (in)call right, 3 (post)
1 2 3 
//code
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>> ans(3);
    stack< pair<TreeNode* ,int> > s;
    s.push({root, 1});
    while(!s.empty()){
        auto curr=s.top();
        s.pop();
        if(curr.second==1){
            ans[1].push_back(curr.first->data);
            s.push({curr.first,2});
            if(curr.first->left) s.push({curr.first->left,1});
        }else if(curr.second==2){
            ans[0].push_back(curr.first->data);
            s.push({curr.first,3});
            if(curr.first->right) s.push({curr.first->right,1});
        }else{
            ans[2].push_back(curr.first->data);

        }
    }
    return ans;
}

//13.2
//1
int heightOfBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return 0;

    return max(heightOfBinaryTree(root->left),heightOfBinaryTree(root->right)) + 1;
}
//a2 bfs 
return levels 

//2 isBalancedBT. difference in left height & right height must not be > 1
int heightOfBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return 0;
    int leftH=heightOfBinaryTree(root->left);
    if(leftH<0) return -1;
    int rightH=heightOfBinaryTree(root->right);
    if(rightH<0) return -1;

    if(abs(leftH-rightH)>1) return -1;

    return max(leftH,rightH) + 1;
}

bool isBalancedBT(TreeNode<int>* root){
    // Write your code here.
    int h=heightOfBinaryTree(root);
    return h>=0;
}
//3 diameterOfBinaryTree
int heightOfBinaryTree(TreeNode<int> *root,int &ans)
{
    // Write your code here.
    if(!root) return 0;

    int leftH=heightOfBinaryTree(root->left,ans);
    int rightH=heightOfBinaryTree(root->right,ans);

    ans=max(ans,leftH+rightH);

    return max(leftH,rightH)+1;

}
int diameterOfBinaryTree(TreeNode<int> *root){
    // Write Your Code Here.
    int ans=0;
    int h=heightOfBinaryTree(root,ans);
    return ans;
}
//4 maxPathSum
class Solution {
public:
    int help(TreeNode *root, int &ans) {
        if (root == NULL) return 0;

        int left = max(0, help(root->left, ans)); // Max of 0 and left subtree path sum
        int right = max(0, help(root->right, ans)); // Max of 0 and right subtree path sum

        // Calculate the maximum path sum including the current node
        int curr = root->val + left + right;
        ans = max(curr, ans);

        // Return the maximum path sum starting from the current node upwards
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        help(root, ans);
        return ans;
    }
};
//while using ternary ?: be careful with ()
        // int curr=root->val + (left>0?left:0) + (right>0?right:0);

//5 identicalTrees
//a1 dfs
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here.     
    if(root1==NULL && root2==NULL) return 1;
    if(root1==NULL || root2==NULL) return 0;

    if(root1->data != root2->data) return 0;

    return identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right);
}
//a2 bfs with null as -1
vector<int> level(BinaryTreeNode<int>* root){
    vector<int> ans;
    if(root==NULL) return {-1};

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    ans.push_back(root->data);

    while(!q.empty()){
        auto curr=q.front();

        if(curr->left){
            ans.push_back(curr->left->data);
            q.push(curr->left);
        }else{
            ans.push_back(-1);
        }

        if(curr->right){
            ans.push_back(curr->right->data);
            q.push(curr->right);
        }else{
            ans.push_back(-1);
        }

        q.pop();
    }
    return ans;
}

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here.    
    vector<int> v1=level(root1);
    vector<int> v2=level(root2);

    if(v1.size() != v2.size()) return 0;

    for(int i=0;i<v1.size();i++){
        if(v1[i] != v2[i]) return 0;
    }
    return 1;
    
}
//6 zigzagLevelOrder
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int flip=0;
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            while(n--){
                auto curr=q.front();
                q.pop();
                temp.push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

            }
            if(flip) reverse(temp.begin(),temp.end());
            flip^=1;
            ans.push_back(temp);
        }
        return ans;
    }
//7 boundary
bool isLeaf(TreeNode<int> *root){
    return (root->left==NULL) && (root->right==NULL);
}
void addLeft(vector<int> &ans,TreeNode<int> *root){
    while(root){
        if(!isLeaf(root)){
            ans.push_back(root->data);
        }
        if(root->left) root=root->left;
        else root=root->right;
    }
}

void addRight(vector<int> &ans,TreeNode<int> *root){
    vector<int> temp;
    while(root){
        if(!isLeaf(root)){
            temp.push_back(root->data);
        }
        if(root->right) root=root->right;
        else root=root->left;
    }
    //in reverse
    int n=temp.size();
    for(int i=n-1;i>=0;i--) ans.push_back(temp[i]);
}

void addLeaves(vector<int> &ans, TreeNode<int> *root) {
    if(!root) return;
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    addLeaves(ans, root->left);
    addLeaves(ans, root->right);
}
//anticlockwise
vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    ans.push_back(root->data);
    if(isLeaf(root)) return ans;
    
    addLeft(ans,root->left);
    addLeaves(ans,root);
    addRight(ans,root->right);
    return ans;
}

// 8 vertical
    //incorrect
//2 7 5 2 6 -1 9 -1 -1 5 11 4 -1 -1 -1 -1 -1 -1 -1
//failing for same place insertion based on value
#include <bits/stdc++.h>

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return {};
    vector<int> ans;
    map<int,vector<int> > mp;//line val

    queue< pair<TreeNode<int>*,int> >q;//node* line
    q.push({root,0});//missed
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        auto currNode=curr.first;
        int currLine=curr.second;

        // if(mp.find(currLine) == mp.end()){
            mp[currLine].push_back(currNode->data);
        // }

        if(currNode->left) q.push({currNode->left,currLine-1});
        if(currNode->right) q.push({currNode->right,currLine+1});
    }

    // for(auto x:mp) ans.push_back(x.second);
    for(auto x:mp){
        for(auto lineElement:x.second) ans.push_back(lineElement);
    }
    return ans;
}
//a1 ptc
#include<bits/stdc++.h>

 

vector<int> verticalOrderTraversal(TreeNode<int> *root)

{

    vector<int> ans;

    if (root == NULL) return ans;

 

    queue<pair<TreeNode<int>*, pair<int, int>>> q;

    map<pair<int, int>, multiset<int>> mp;

 

    q.push({root, {0, 0}});

    while (!q.empty()) {

        auto it = q.front();

        q.pop();

        auto node = it.first;

        int x = it.second.first;

        int y = it.second.second;

        mp[{x, y}].insert(node->data);

        if (node->left != NULL) q.push({node->left, {x-1, y+1}});

        if (node->right != NULL) q.push({node->right, {x+1, y+1}});

    } 

 

    for (auto it : mp) {

        ans.insert(ans.end(), it.second.begin(), it.second.end());

    }

 

    return ans;

}
//a2 dfs
sort based on line level val
#include<bits/stdc++.h>
void dfs(int line,int level,TreeNode<int> *root,vector< pair< pair<int,int> , int> > &v){
    if(!root) return;

    v.push_back({{line,level},root->data});

    dfs(line-1,level+1,root->left,v);
    dfs(line+1,level+1,root->right,v);
}

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    // Write your code here.
    vector< pair< pair<int,int> , int> > v;//line level val
    dfs(0,0,root,v);
    
    sort(v.begin(),v.end());//sort ascending bydefault based on parameters. if first same sort on second,if that also same sort on third and so on...
    vector<int> ans;
    for(auto x:v) ans.push_back(x.second);
    return ans;
}
// 9 top
    //incorrect
//1 2 3 -1 4 -1 -1 -1 5 -1 -1
// In this tree 5 will be reached first in pre-order but from top 3 should appear in top view
#include <bits/stdc++.h>
void traverse(TreeNode<int> *root,map<int,int> &mp,int line){
    if(!root) return;
    if(mp.find(line) == mp.end()) mp[line]=root->data;

    traverse(root->left, mp, line-1);
    traverse(root->right, mp, line+1);
}

vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return {};
    map<int,int> mp;
    traverse(root,mp,0);

    vector<int> ans;
    for(auto x:mp) ans.push_back(x.second);
    return ans;
}
//a1
#include <bits/stdc++.h>
void traverse(TreeNode<int> *root,map <int, pair<int,int> > &mp,int line,int level){
    if(!root) return;
    if(mp.find(line) == mp.end() || level<mp[line].second)
      mp[line] = {root->data, level};

    traverse(root->left, mp, line-1,level+1);
    traverse(root->right, mp, line+1,level+1);
}

vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return {};
    map <int, pair<int,int> > mp;
    traverse(root,mp,0,0);

    vector<int> ans;
    for(auto x:mp) ans.push_back(x.second.first);
    return ans;
}
//a2
#include <bits/stdc++.h>

vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return {};
    vector<int> ans;
    map<int,int> mp;//line val

    queue< pair<TreeNode<int>*,int> >q;//node* line
    q.push({root,0});//missed
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        auto currNode=curr.first;
        int currLine=curr.second;

        if(mp.find(currLine) == mp.end()){
            mp[currLine]=currNode->data;
        }

        if(currNode->left) q.push({currNode->left,currLine-1});
        if(currNode->right) q.push({currNode->right,currLine+1});
    }

    for(auto x:mp) ans.push_back(x.second);
    return ans;
}

// 10 bottom
//only change
// For top update for every new line 
// For bottom update at every instance as this is the last node
        // if(mp.find(currLine) == mp.end()){
            mp[currLine]=currNode->data;
        // }

// 11 printLeftView
//a1 
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(!root) return {};

    queue<BinaryTreeNode<int> *>q;
    q.push(root);

    vector<int> ans;
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            auto curr=q.front();
            q.pop();
            if(i==0) ans.push_back(curr->data);

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return ans;
}
//a2 ptc
void dfsTraversal(BinaryTreeNode<int>* root, vector<int> &ans, int level){
    // Base Case
    if(root == NULL) return;
    // Update Statement
    if(ans.size() == level){
        // This is the first occurance
        ans.push_back(root->data);
    }
    if(root->left != NULL)
        dfsTraversal(root->left, ans, level + 1);
    if(root->right != NULL)
        dfsTraversal(root->right, ans, level + 1);
}

void printLeftView(BinaryTreeNode<int> *root)
{
    // Approach: Recursive DFS Traversal
    // and consider only the first node's value and
    // discard the remaining nodes in a particular level.
    // Time Complexity: O(N)
    // Space Complexity: O(height)
    vector<int> ans;
    // DFS Traversal
    dfsTraversal(root, ans, 0);
    // print the values
    for(int it : ans){
        cout << it << " ";
    }
    cout << endl;
    return;
}
//a3
#include <bits/stdc++.h>
void traversal(BinaryTreeNode<int> *root,vector< pair<int,pair<int,int> > > &ans,int level,int &idx) {
    if(!root) return;

    ans.push_back({idx, {level, root->data}});
    idx++;

    traversal(root->left,ans,level+1,idx);
    traversal(root->right,ans,level+1,idx);

}

bool comp(pair<int,pair<int,int> > &a, pair<int,pair<int,int> > &b){
    if(a.second.first != b.second.first) 
        return a.second.first < b.second.first;
    return a.first<b.first;
}   

vector<int> levelOrder(BinaryTreeNode<int> * root){
    // Write your code here.
    vector< pair<int,pair<int,int> > > ans;
    int idx=0;
    traversal(root,ans,0,idx);

    sort(ans.begin(),ans.end(),comp);

    vector<int> final;
    int n=ans.size();
    for(int i=0;i<n;i++){
        final.push_back(ans[i].second.second);
        int currLevel=ans[i].second.first;
        while(i+1<n && ans[i+1].second.first==currLevel) i++;
    }
    // for(auto x:ans) final.push_back(x.second.second);
    return final;
}
//12
bool help(TreeNode<int> *root1,TreeNode<int> *root2){
    if(root1==NULL && root2==NULL) return 1;
    if(root1==NULL || root2==NULL) return 0;

    if(root1->data != root2->data) return 0;

    return help(root1->left, root2->right) && help(root1->right, root2->left);

}
//mirror image should be same
    //i.e left=right
bool isSymmetric(TreeNode<int> *root)
{
    // Write your code here
    return help(root,root);//no need to check root as it will be same
    //  return isMirrorReflection(root->left, root->right);
}
//a2
// If at any point, the consecutive nodes’ values in the queue are not equal, then we return false,  as the tree is not symmetric.
bool isSymmetric(TreeNode<int> *root)
{

    //If root is NULL, then simply return true.
    if (root == NULL)
    {
        return true;
    }

    //Create a queue which will contain the nodes of the binary tree.
    queue<TreeNode<int>*> q;

    //Push the root two times to the queue initially.
    q.push(root);
    q.push(root);

    while (!q.empty())
    {

        //Pop two elements from the queue
        TreeNode<int>* node1 = q.front();
        q.pop();

        TreeNode<int>* node2 = q.front();
        q.pop();

        //If both the nodes are NULL, then go back to the previous step.
        if (node1 == NULL && node2 == NULL)
        {
            continue;
        }

        //If only one of them is NULL, then simply return false.
        if (node1 == NULL || node2 == NULL)
        {
            return false;
        }

        //If the values of two nodes don't match, then simply return false.
        if (node1->data != node2->data)
        {
            return false;
        }

        //Add the left child of node1, right child of node2, right child of node1 and left child of node2 to the queue in exact order.
        q.push(node1->left);
        q.push(node2->right);
        q.push(node1->right);
        q.push(node2->left);
    }

    return true;
}

//13.3 hard
// 1 root to leaf paths
    void f(Node* root,vector<int> &temp,vector<vector<int>> &ans){
        temp.push_back(root->data);

        if(root->left==NULL && root->right==NULL){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }

        if(root->left) f(root->left,temp,ans);
        if(root->right) f(root->right,temp,ans);

        temp.pop_back();
        
    }

    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        f(root,temp,ans);
        return ans;
    }
// 2
void markParent(TreeNode<int> * root,TreeNode<int> * parent,unordered_map<int,int> &ump){
    if(!root) return;

    if(parent) ump[root->data]=parent->data;
    else ump[root->data]=-1;

    markParent(root->left,root,ump);
    markParent(root->right,root,ump);

}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    //    Write your code here
    //mark parents in map
    unordered_map<int,int> ump;
    markParent(root,NULL,ump);

    //mark path for first root
    unordered_set<int> visited;//as distinct val
//     unordered_map<TreeNode<int> *,TreeNode<int> *> ump; 
    //not going through this approach as we would have to find nodes for val x & y

    int curr=x;
    while(curr!=-1){
        visited.insert(curr);
        curr=ump[curr];//move to parent
    }

    //mark path for second from node to root and check first visited(first matching)
    while(true){
        if(visited.find(y) != visited.end()) return y;
        y=ump[y];
    }
    
}
//a1.2
    ump[root->data]=parent->data;
    markParent(root->left,root,ump);
    markParent(root->right,root,ump);

}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    //    Write your code here
    //mark parents in map
    unordered_map<int,int> ump;
    ump[root->data]=-1;
    markParent(root->left,root,ump);
    markParent(root->right,root,ump);
//a2
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    //    Write your code here
    if(!root) return -1;
    if(root->data==x || root->data==y) return root->data;
    // int lcaLeft=-1,lcaRight=-1;
    int lcaLeft=lowestCommonAncestor(root->left, x, y);
    int lcaRight=lowestCommonAncestor(root->right, x, y);

    if(lcaLeft!=-1 && lcaRight!=-1) return root->data;//if both on either sides of root then root is lca
    if(lcaLeft!=-1) return lcaLeft;//both on left
    return lcaRight;//both on right

}
//pg2

// 3a getMaxWidth
//a1 dfs + map
void f(TreeNode<int> *root,int level,unordered_map<int,int> &ump){
    if(!root) return;
    ump[level]++;
    f(root->left,level+1,ump);
    f(root->right,level+1,ump);

}
int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    unordered_map<int,int> ump;
    f(root,0,ump);
    int ans=0;
    for(auto x:ump) ans=max(ans,x.second);
    return ans;
}
//a2 bfs
#include <bits/stdc++.h>

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return 0;

    queue<TreeNode<int>*> q;
    q.push(root);
    int maxAns=0;
    while(!q.empty()){
        int n=q.size();
        maxAns=max(maxAns,n);

        while(n--){
            auto curr=q.front();
            q.pop();

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);

        }
    }
    return maxAns;
}
//3b
// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
#include <bits/stdc++.h>

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q; // Change the data type of index to unsigned long long
        q.push({root, 1});
        while (!q.empty()) {
            int size = q.size();
            unsigned long long leftmost = q.front().second, rightmost = leftmost;
            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();
                rightmost = index;
                if (node->left) q.push({node->left, 2ULL * index}); // Use ULL suffix for unsigned long long literal
                if (node->right) q.push({node->right, 2ULL * index + 1});
            }
            maxWidth = max(maxWidth, static_cast<int>(rightmost - leftmost + 1));
        }
        return maxWidth;
    }
};
//a1.2
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long maxAns=0;
        queue< pair<TreeNode* , int > > q;
        q.push({root,1});//1 based idx

        while(!q.empty()){
            int n=q.size();
            long  firstIdx=q.front().second, lastIdx;
            for(int i=0;i<n;i++){

                auto curr=q.front();
                q.pop();

                // if(i==0) firstIdx=curr.second;
                if(i==n-1) lastIdx=curr.second;

                if(curr.first->left) q.push({curr.first->left,1ll*curr.second*2 - firstIdx});
                if(curr.first->right) q.push({curr.first->right,1ll*curr.second*2+1 - firstIdx});

            }
            maxAns=max(maxAns,lastIdx - firstIdx + 1);
        }
        return maxAns;
    }
};
// 4 is Parent Sum of child
bool isParentSum(Node *root){
    // Write your code here.
    if(!root) return 1;
    if(root->left==NULL && root->right==NULL) return 1;

    int sum=0;
    if(root->left) sum+=root->left->data;
    if(root->right) sum+=root->right->data;
    if(root->data != sum) return 0;

    return isParentSum(root->left) && isParentSum(root->right);

}
//4b ptc Convert an arbitrary Binary Tree to a tree that holds Children Sum Property
// 5 printNodesAtDistanceK
#include <bits/stdc++.h>
void f(BinaryTreeNode<int>* child,BinaryTreeNode<int>* parent,unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &ump){
    if(!child) return;
    ump[child]=parent;
    f(child->left,child,ump);
    f(child->right,child,ump);

}
vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K) {
    // Write your code here.
    //mark parents
    unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> ump;
    f(root,NULL,ump);

    queue<BinaryTreeNode<int>*>q;
    q.push(target);
    unordered_set<BinaryTreeNode<int>*> visited;
    // visited.insert(target);

    while(!q.empty() && K>0){
        int n=q.size();
        while(n--){
            auto curr=q.front();
            q.pop();
            visited.insert(curr);

            if(curr->left && (visited.find(curr->left)==visited.end() ) ){
                q.push(curr->left);
            }
            if(curr->right && (visited.find(curr->right)==visited.end() ) ){
                q.push(curr->right);
            }
            if(ump[curr] && (visited.find(ump[curr])==visited.end() ) ){
                q.push(ump[curr]);
            }
        }
        K--;
    }
    vector<BinaryTreeNode<int>*> ans;
    while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
    }

    return ans;
}
//a1.2
    vector<BinaryTreeNode<int>*> ans;

    while(!q.empty() && K>=0){
        int n=q.size();
        while(n--){
            auto curr=q.front();
            q.pop();
            if(K==0) ans.push_back(curr);
            else{
                visited.insert(curr);
                // /if (!vis.count(curr->left) && curr->left) {
                if(curr->left && (visited.find(curr->left)==visited.end() ) ){
                    q.push(curr->left);
                }
                if(curr->right && (visited.find(curr->right)==visited.end() ) ){
                    q.push(curr->right);
                }
                if(ump[curr] && (visited.find(ump[curr])==visited.end() ) ){
                    q.push(ump[curr]);
                }
            }
            
        }
        K--;
    }

    return ans;
}
//a2 ptc
/*
    Time Complexity : O(N)
    Space Complexity : O(N)

    Where N is the number of non-NULL nodes in the tree.
*/

// Add all nodes 'maxmDist - dist' from the node subtree to solution.
void subtreeAdd(BinaryTreeNode<int>* node, int dist, int maxmDist, vector<BinaryTreeNode<int>*> &sol) {
    if (node == NULL) {
        return;
    }

    if (dist == maxmDist) {
        sol.push_back(node);
    }

    else {
        subtreeAdd(node->left, dist + 1, maxmDist, sol);
        subtreeAdd(node->right, dist + 1, maxmDist, sol);
    }

}

int dfs(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K, vector<BinaryTreeNode<int>*> &sol) {
    if (!root) {
        return -1;
    }

    else if (root == target) {
        subtreeAdd(root, 0, K, sol);
        return 1;
    }

    else{
        int L = dfs(root->left, target, K, sol), R = dfs(root->right, target, K, sol);

        if (L != -1) {

            if (L == K) {
                sol.push_back(root);
            }

            subtreeAdd(root->right, L + 1, K, sol);
            return L + 1;
        }

        else if (R != -1){

            if (R == K) {
                sol.push_back(root);
            }

            subtreeAdd(root->left, R + 1, K, sol);
            return R + 1;
        }

        else {
            return -1;
        }

    }

}

void dfsHelper(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K, vector<BinaryTreeNode<int>*> &sol) {
    int temp = dfs(root, target, K, sol);
}

vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K) {
    vector<BinaryTreeNode<int>*> sol;
    sol.clear();

    // Function dfs returns the number of vertices between root and target if path exists, else returns -1.
    dfsHelper(root, target, K, sol);
    return sol;
}

// 6 timeToBurnTree
//a1

#include <bits/stdc++.h>
void f(BinaryTreeNode<int>* child,BinaryTreeNode<int>* parent,unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &ump){
    if(!child) return;
    ump[child]=parent;
    f(child->left,child,ump);
    f(child->right,child,ump);

}
int  printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target) {
    // Write your code here.
    //mark parents
    unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> ump;
    f(root,NULL,ump);

    queue<BinaryTreeNode<int>*>q;
    q.push(target);
    unordered_set<BinaryTreeNode<int>*> visited;
    vector<BinaryTreeNode<int>*> ans;
    int time=0;
    while(!q.empty() ){
        int n=q.size();
        while(n--){
            auto curr=q.front();
            q.pop();
            // else{
            visited.insert(curr);

            if(curr->left && (visited.find(curr->left)==visited.end() ) ){
                q.push(curr->left);
            }
            if(curr->right && (visited.find(curr->right)==visited.end() ) ){
                q.push(curr->right);
            }
            if(ump[curr] && (visited.find(ump[curr])==visited.end() ) ){
                q.push(ump[curr]);
            }
            // }
            
        }
        time++;
    }

    return time-1;
}

BinaryTreeNode<int>* find(BinaryTreeNode<int>* root, int start){
    if(!root) return NULL;
    if(root->data == start) return root;
    return find(root->left,start)!=NULL ? find(root->left,start) : find(root->right,start);
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
    BinaryTreeNode<int>* target = find(root,start);

    return printNodesAtDistanceK(root,target);
}
//a2 ptc
/*
    Time Complexity : O(N)
    Space Complexity : O(N)
    
    where 'N' is the number of nodes in the tree.
    
*/

#include <unordered_map>

void inorder(BinaryTreeNode<int> *root, unordered_map<int, vector<int>> &m)
{
    if (root)
    {
        inorder(root->left, m);
        if (root->left)
        {
            m[root->data].push_back(root->left->data);
            m[root->left->data].push_back(root->data);
        }
        if (root->right)
        {
            m[root->data].push_back(root->right->data);
            m[root->right->data].push_back(root->data);
        }
        inorder(root->right, m);
    }
}

int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
    // Initialize map to store edges and vertices.
    unordered_map<int, vector<int>> m;
    
    // Store edges by doing inorder traversal.
    inorder(root, m);
    
    // Initialize queue for bfs traversal.
    queue<int> q;
    
    q.push(start);
    
    // Variable to keep count of number of levels from start node.
    int count = 0;
    unordered_map<int, bool> visited;
    visited[start] = true;
    
    // Iterate while queue is not empty.
    while (!q.empty())
    {
        count++;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            int node = q.front();
            q.pop();
            
            for(auto i:m[node])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    
    return count - 1;
}
//a3 ptc
/*
    Time complexity : O(N)
    Space complexity : O(H)

    where 'N' is the number of nodes in the tree 
    and 'H' is the height of the tree.

*/

class Triplet
{
public:
    int max, above, below;

    Triplet(int max, int above, int below)
    {
        this->max = max;
        this->above = above;
        this->below = below;
    }
};

Triplet timeToBurnTreeHelper(BinaryTreeNode<int> *root, int start)
{
    if (root == NULL)
    {
        return Triplet(-1, -1, 0);
    }

    Triplet left = timeToBurnTreeHelper(root->left, start);
    Triplet right = timeToBurnTreeHelper(root->right, start);

    Triplet ans = Triplet(-1, -1, 0);

    // Node is the starting node
    if (root->data == start)
    {
        int below = max(left.below, right.below);
        ans.max = below;
        ans.above = 0;
        ans.below = below;
    }
    
    // Starting Node is in left subtree
    else if (left.above != -1)
    {
        ans.max = max(left.max, max(left.below, left.above + right.below + 1));
        ans.above = left.above + 1;
        ans.below = left.below;
    }
    
    // Starting Node is in right subtree
    else if (right.above != -1)
    {
        ans.max = max(right.max, max(right.below, right.above + left.below + 1));
        ans.above = right.above + 1;
        ans.below = right.below;
    }
    
    // Starting Node doesn't exist in the subtree
    else
    {
        ans.max = -1;
        ans.above = -1;
        ans.below = max(left.below, right.below) + 1;
    }

    return ans;
}

int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
    Triplet ans = timeToBurnTreeHelper(root, start);
    return ans.max;
}


// 7 Count total Nodes in a COMPLETE Binary Tree
int countNodes(BinaryTreeNode<int> *root) {
  // Write your code here.
    if(!root) return 0;
    int lh=1,rh=1;
    BinaryTreeNode<int> *curr=root;
    while(curr->left){
        lh++;
        curr=curr->left;
    }
    curr=root;
    while(curr->right){
        rh++;
        curr=curr->right;
    }
    if(lh==rh) return pow(2,lh)-1;//if all levels filled
    return 1+countNodes(root->left)+countNodes(root->right);
        //atleast one of left or right will be completely filled
}
// 8 Requirements needed to construct a Unique Binary Tree | Theory
//we need inorder along with pre/post to create unique binary tree
int uniqueBinaryTree(int a, int b){
    // Write your code here.
    // return (a*b==2 || a*b==6);
    return (a!=b) && (a==2 || b==2);
}
// 9 Construct Binary Tree from inorder and preorder
TreeNode<int> *create(vector<int> &inorder,int li,int ri, vector<int> &preorder,int lp,int rp,unordered_map<int,int> &ump){
    if(li>ri) return NULL;

    TreeNode<int> *root=new TreeNode<int>( preorder[lp]);
    if(li==ri) return root;
    int idx=ump[preorder[lp]];
    int elements=idx-li;
    root->left=create(inorder, li, idx-1, preorder, lp+1, lp+elements, ump);
    root->right=create(inorder, idx+1, ri, preorder, lp + elements + 1, rp, ump);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    //    Write your code here
    int n=inorder.size();
    unordered_map<int,int> ump;
    for(int i=0;i<n;i++){
        ump[inorder[i]]=i;
    }
    return create(inorder,0,n-1,preorder,0,n-1,ump);
}
// 10 Construct the Binary Tree from Postorder and Inorder Traversal
#include <bits/stdc++.h>
TreeNode<int>* create(vector<int>& postOrder,int postL,int postR, vector<int>& inOrder,int inL,int inR,unordered_map<int,int> &ump){
     if(inL>inR) return NULL;
     int rootVal=postOrder[postR];
     TreeNode<int> *root=new TreeNode<int>(rootVal);
     if(inL==inR) return root;
     int idx=ump[rootVal];
     int elementsOnLeft=idx-inL;
     root->left=create(postOrder, postL, postL-1+elementsOnLeft, inOrder, inL, idx-1, ump);
     root->right=create(postOrder, postL+elementsOnLeft, postR-1, inOrder, idx+1, inR, ump);

     return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder){
    // Write your code here.
     unordered_map<int,int> ump;
     int n=inOrder.size();
     for(int i=0;i<n;i++){
          ump[inOrder[i]]=i;
     }

     return create(postOrder,0,n-1,inOrder,0,n-1,ump);
}

// 11 Serialize and deserialize Binary Tree
string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    if(!root) return "-1";
    string ans;
    queue<TreeNode<int> *>q;
    q.push(root);
    ans+=to_string(root->data);
    while(!q.empty()){
        // cout<<ans<<endl;
        auto curr=q.front();
        q.pop();

        if(curr->left){
            ans+=" "+to_string(curr->left->data);
            q.push(curr->left);
        }else ans+=" "+to_string(-1);

        if(curr->right){
            ans+=" "+to_string(curr->right->data);
            q.push(curr->right);
        }else ans+=" "+to_string(-1);

        // cout<<ans<<endl;
    }
    return ans;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    if(serialized.empty()) return NULL;
    istringstream iss(serialized);
    int num;
    vector<int> v;
    while(iss>>num){
        v.push_back(num);
    }

    TreeNode<int> *root=new TreeNode<int>(v[0]);
    queue< TreeNode<int>* > q;
    q.push(root);
    int idx=1, n=v.size();

    while(idx<n){
        auto curr=q.front();
        q.pop();

        if(v[idx] != -1){
            TreeNode<int> *L=new TreeNode<int>(v[idx]);
            curr->left=L;
            q.push(L);
        }
        idx++;
        if(v[idx] != -1){
            TreeNode<int> *R=new TreeNode<int>(v[idx]);
            curr->right=R;
            q.push(R);
        }
        idx++;
    }

    return root;
}
//a2 ptc
string serializeTree(TreeNode<int> *root) {
    if (!root) return "-1"; // Use "#" to represent null nodes
    return to_string(root->data) + " " + serializeTree(root->left) + " " + serializeTree(root->right);
}

TreeNode<int>* deserializeTreeHelper(istringstream &iss) {
    string val;
    iss >> val;
    if (val == "-1") return nullptr; // Return null for "#" nodes
    TreeNode<int>* root = new TreeNode<int>(stoi(val));
    root->left = deserializeTreeHelper(iss);
    root->right = deserializeTreeHelper(iss);
    return root;
}

TreeNode<int>* deserializeTree(string &serialized) {
    istringstream iss(serialized);
    return deserializeTreeHelper(iss);
}
// 12 Morris Preorder Traversal of a Binary Tree
    //ptc
// 13 Morris Inorder Traversal of a Binary Tree
    //ptc
// 14 Flatten Binary Tree to LinkedList
void pre(TreeNode<int>* root,vector<TreeNode<int>* > &v){
    if(!root) return;
    v.push_back(root);
    pre(root->left, v);
    pre(root->right, v);
}

void flattenBinaryTree(TreeNode<int>* root)
{
    // Write your code here.
    vector<TreeNode<int>* > v;
    pre(root,v);
    int n=v.size();
    for(int i=0;i<n-1;i++){
        v[i]->right=v[i+1];
        v[i]->left=NULL;
    }
}
//a2 ptc

//14 bst
A binary search tree (BST) is a binary tree data structure that has the following properties:

1. The left subtree of a node contains only nodes with data less than the node’s data.

2. The right subtree of a node contains only nodes with data greater than the node’s data.

3. The left and right subtrees must also be binary search trees.
Note:
It is guaranteed that all nodes have distinct data.
//14.1
//1 for valid bst inorder must be sorted
bool isValidBST(vector<int> &order){
    // Write your code here.
    int n=order.size();
    for(int i=1;i<n;i++){
        if(order[i-1]>=order[i]) return 0;
    }
    return 1;
}
//2
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    BinaryTreeNode<int> *curr=root;
    while(curr){
        if(curr->data == x) return 1;
        else if(curr->data>x) curr=curr->left;
        else curr=curr->right;
    }
    return 0;
}
//3
int minVal(Node* root){
    // Write your code here.    
    if(!root) return -1;
    while(root->left) root=root->left;
    return root->data;
}
//14.2
// 1 Ceil in a Binary Search Tree
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans=-1;
    while(node){
        if(node->data == x) return x;
        else if(node->data > x){
            //possible ans
            ans=node->data;
            //check for smaller
            node=node->left;
        }else node=node->right;
    }
    return ans;
}
// 2 Floor in a Binary Search Tree
    //similar to 1
// 3 Insert a given Node in Binary Search Tree
//a1
TreeNode<int>* insertionInBST(TreeNode<int>* root, int val)
{
    // Write your code here.
    TreeNode<int> *add=new TreeNode<int>(val), *curr=root;
    if(!root) return add;

    while(curr){
        if(curr->val > val){
            if(curr->left) curr=curr->left;
            else{
                curr->left=add;
                break;
            }
        }else{
            if(curr->right) curr=curr->right;
            else{
                curr->right=add;
                break;
            }
        }
    }

    return root;
}
//a2 
TreeNode<int>* insertionInBST(TreeNode<int>* root, int val)
{
    // Write your code here.
    if(!root){
        TreeNode<int> *add=new TreeNode<int>(val);
        return add;
    }
    
    if(val>root->val){
        root->right=insertionInBST(root->right, val);
    }else{
        root->left=insertionInBST(root->left, val);
    }
    return root;
}
// 4 Delete a Node in Binary Search Tree
//a1
BinaryTreeNode<int>* helper(BinaryTreeNode<int>* root){
    if(!root->left) return root->right;
    if(!root->right) return root->left;

    //find highest(rightmost) in left and link to rightChild
    BinaryTreeNode<int>* rightChild=root->right;
    BinaryTreeNode<int>* highestInLeft=root->left;
    while(highestInLeft->right) highestInLeft=highestInLeft->right;
    highestInLeft->right=rightChild;
    return root->left;
    //OR
    //find lowest(leftmost) in right and link to leftChild
}

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    // Write your code here.
    if(root->data == key){
        return helper(root);
    }
    BinaryTreeNode<int>* og=root;
    while(root){    //if while(true) runTimeError?
        if(root->data > key){
            if(root->left && root->left->data==key){
                root->left=helper(root->left);
                break;
            }else root=root->left;
        }else{
            if(root->right && root->right->data==key){
                root->right=helper(root->right);
                break;
            }else root=root->right;
        }
    }
    return og;
}

//a2 
BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    // Write your code here.
    if(!root) return NULL;//if this commented runtimeerror?
    if(root->data > key) root->left=deleteNode(root->left, key);
    else if(root->data < key) root->right=deleteNode(root->right, key);
    else{
        if(!root->right) return root->left;
        if(!root->left) return root->right;

        BinaryTreeNode<int>* curr=root->left;
        while(curr->right) curr=curr->right;
        root->data=curr->data;

        root->left=deleteNode(root->left, curr->data);
    }
}
// 5 Find K-th smallest/largest element in BST
void inorder(TreeNode<int> *root, int &k,int &ans,int &count){
    if(!root) return ;

    inorder(root->left, k, ans,count);
    //a1
    // count++;
    // if(count==k){
    //     ans=root->data;
    // }

    //a2
    if(k==0) return;
    if(k==1){
        ans=root->data;
        k--;
        return;
    }
    k--;
    inorder(root->right, k, ans,count);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    //  Write the code here.
    int ans=-1, count=0;
    inorder(root,k,ans,count);
    return ans;
}
// 6 Check if a tree is a BST or BT
#include <climits> // Include for INT_MIN and INT_MAX
bool f(BinaryTreeNode<int> *root,int low,int high){
    if(!root) return 1;
    int val=root->data;
    if(val<low || val>=high) return 0;//duplicate in right
    //left subtree can have value [low,val) and right subtree can have val from [val,high)
    return f(root->left, low, val) && f(root->right, val, high);
}

bool isBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return f(root,INT_MIN,INT_MAX);
}
// 7 LCA in Binary Search Tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mini=min(p->val,q->val);
        int maxi=max(p->val,q->val);

        while(root){
            int val=root->val;
            if(val>=mini && val<=maxi) return root;
            if(val<mini) root=root->right;
            else root=root->left;
        }
        return NULL;
    }
//a2
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if both on right move right
        if(p->val>root->val && q->val>root->val ){
            return lowestCommonAncestor(root->right,p,q);
        }
        //if both on left move left
        if(p->val<root->val && q->val<root->val ){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }
// 8 Construct a BST from a preorder traversal
TreeNode *create(vector<int> &preOrder,int start,int end){
    if(start>end) return NULL;
    TreeNode *curr=new TreeNode(preOrder[start]);
    if(start==end) return curr;
    int rightStart=start+1;
    //can use binary search instead of linear
    while(rightStart<=end && preOrder[rightStart]<preOrder[start])
        rightStart++;
    curr->left=create(preOrder, start+1, rightStart-1);
    curr->right=create(preOrder, rightStart, end);
    return curr;
}

TreeNode *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    int n=preOrder.size();
    return create(preOrder,0,n-1);
}
//a2
int search(vector<int> &preOrder,int start,int end,int val){
    int ans=end+1;
    while(start<=end){
        int mid=(start+end)/2;
        if(preOrder[mid]>val){
            ans=mid;
            end=mid-1;
        }else start=mid+1;
    }
    return ans;
}
TreeNode *create(vector<int> &preOrder,int start,int end){
    if(start>end) return NULL;
    TreeNode *curr=new TreeNode(preOrder[start]);
    if(start==end) return curr;
    int rightStart=search(preOrder,start+1,end,preOrder[start]);
    
    curr->left=create(preOrder, start+1, rightStart-1);
    curr->right=create(preOrder, rightStart, end);
    return curr;
}

TreeNode *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    int n=preOrder.size();
    return create(preOrder,0,n-1);
}
//a2.2
int search(vector<int> &preOrder,int start,int end,int val){
    //everything from end is greater
    //everything before start is lower
    while(start<end){
        int mid=(start+end)/2;
        if(preOrder[mid]>val) end=mid;
        else start=mid+1;
    }
    return end;
}
    int rightStart=search(preOrder,start+1,end+1,preOrder[start]);

//a3 ptc
TreeNode<int>* build(vector<int> &preOrder,int &i,int bound){
    if(i==preOrder.size() || preOrder[i]>bound) return NULL;

    TreeNode<int>* root=new TreeNode<int>(preOrder[i++]);
    root->left=build(preOrder,i,root->data);
    root->right=build(preOrder,i,bound);

    return root;

}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i=0;
    return build(preOrder,i,INT_MAX);
}
// 9 Inorder Successor/Predecessor in BST
void inorder(TreeNode *root, int key,int &a1,int &a2,int &f1,int &f2){
    if(!root) return;
    if(f1+f2==0) return;
    inorder(root->left, key, a1, a2, f1, f2);
    if(f2){
        a2=root->data;
        f2=0;
        return;
    }
    if(root->data==key){
        f1=0;
        f2=1;
    }
    if(f1){
        a1=root->data;
    }
    inorder(root->right, key, a1, a2, f1, f2);

}
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    int a1=-1,a2=-1, f1=1,f2=0;
    inorder(root,key,a1,a2,f1,f2);

    return {a1,a2};
}
//a2 will pass even if key not present in tree
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    int pre=-1,suc=-1;
    TreeNode *curr=root;
    while(root){
        if(root->data<key){
            pre=root->data;
            root=root->right;
        }else root=root->left;
    }
    root=curr;
    while(root){
        if(root->data>key){
            suc=root->data;
            root=root->left;
        }else root=root->right;
    }
    return {pre,suc};
}
// 10 Merge 2 BST's
//a1
get both sorted vector using inOrder
then merge 2 sorted arrays and return
//10b ptc next hasnext using stack 
// 11 Two Sum In BST | Check if there exists a pair with Sum K
inorder get sorted then normal 2 sum in array
//a2 
    bool findTarget(TreeNode* root, int k) {
        if(!root) return 0;

        stack<TreeNode *> s1,s2;
        TreeNode *t1=root,*t2=root;

        while(1){
            while(t1){
                s1.push(t1);
                t1=t1->left;
            }
            while(t2){
                s2.push(t2);
                t2=t2->right;
            }

            if(s1.empty() || s2.empty()) return 0;
            t1=s1.top(),t2=s2.top();

            if(t1->val + t2->val ==k){
                if(t1==t2) return 0;
                return 1;
            }else if(t1->val + t2->val <k){
                s1.pop();
                t1=t1->right;
                t2=NULL;
            }else {
                s2.pop();
                t1=NULL;
                t2=t2->left;
            }
        }   
        return 0;
    }
// 12 Recover BST | Correct BST with two nodes swapped
//logic
If adjacent swiped in sorted array there will be 2 invalid data 
    1 2 3 4 => 1 3 2 4 . 1 pair of incorrect
If non adjacent swap there will be more than two probably 3 to 4 invalid
    4 2 3 1. 2 pairs of incorrect
swap first with fourth if 2 pairs else with second if 1 pair
//code
TreeNode *first=NULL,*second=NULL,*fourth=NULL,*pre=NULL;

void inorder(TreeNode * root){
    if(!root) return;
    inorder(root->left);
    if(!pre) {}
    else if(root->data<pre->data){
        if(!first){
            first=pre;
            second=root;
        }else{
            fourth=root;//third=pre
        }
    }
    pre=root;
    inorder(root->right);
}

TreeNode * FixBST(TreeNode * root){
    // Write your code here.
    inorder(root);
    if(fourth && first){
        swap(first->data,fourth->data);
        // cout<<4<<endl;
    } 
    else if(second && first){
        swap(first->data,second->data);
        // cout<<2<<endl;
    } 

    return root;
}
//a1.2
TreeNode *first=NULL,*second=NULL,*pre=NULL;

void inorder(TreeNode * root){
    if(!root) return;
    inorder(root->left);
    if(pre && root->data<pre->data){
        if(!first) first=pre;
        second=root;
    }
    pre=root;
    inorder(root->right);
}

TreeNode * FixBST(TreeNode * root){
    inorder(root);
    swap(first->data,second->data);
    return root;
}
// 13 Largest BST in Binary Tree
//a1 brute
pass root and check if valid bst 
if not pass left & right and check 
//a2
class NodeVal{
    public:
        int size,mini,maxi;
        NodeVal(int size,int mini,int maxi){
            this->size=size;
            this->mini=mini;
            this->maxi=maxi;
        }
};  //missed ;

NodeVal help(TreeNode * root){
    if(!root){
        return NodeVal(0,INT_MAX,INT_MIN);
    }
    //postorder
    auto left=help(root->left);
    auto right=help(root->right);

    //if bst
    int val=root->data;
    if(val>left.maxi && val<right.mini){
        return NodeVal(left.size+right.size+1,min(left.mini,val),max(val,right.maxi));
    }else{
        return NodeVal(max(left.size,right.size),INT_MIN,INT_MAX);
    }
}

int largestBST(TreeNode * root){
    // Write your code here.
    return help(root).size;
}
//15 Graphs
//15.1 Learning
//1
int countingGraphs(int N)
{
    // Write your code here.
    // 2^noOfEdges
// For 3 vertex 2 edges from first point. One from next. Total 3 
// For 4 vertex 3 + 2 + 1
    int edges=N*(N-1)/2;//int till N=8
    // return pow(2,edges);
    return 1<<edges;
}
//2 Adjacency list stores who are my neighbours or whom I am connected
//other way Adjacency matrix , it takes more space
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<vector<int> >adj(n);
    for(int i=0;i<n;i++){
        adj[i].push_back(i);
    }
    for(auto edge:edges){   //edge is a vector u=edge[0],v=edge[1]
        int u=edge[0], v=edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    return adj;
}
//4 findNumOfProvinces
//count components
void dfs(int city,vector<int> &vis,vector<vector<int>>& roads,int n){
    vis[city]=1;
    for(int i=0;i<n;i++){
        if(roads[city][i] && !vis[i]){  //also i!=city i.e [0][0] taken care as city visited
            dfs(i, vis, roads, n);
        }
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    // Write your code here.
    vector<int> vis(n,0);
    int count=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,roads,n);
            count++;
        }
    }
    return count;
}
//5 bfs
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vector<bool> vis(n,false);//or 1/0
    queue<int> q;

    vis[0]=true;
    q.push(0);

    vector<int> bfs;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        bfs.push_back(curr);

        for(auto connected:adj[curr]){
            if(!vis[connected]){
                vis[connected]=true;
                q.push(connected);
            }
        }
    }
    return bfs;
}
//6 dfs
void dfs(int vertex,vector<int> &vis,vector<vector<int>> &adj,vector<int> &temp){
    vis[vertex]=1;
    temp.push_back(vertex);
    for(auto neighbour:adj[vertex]){
        if(!vis[neighbour]){
            dfs(neighbour, vis,adj, temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> adj(V);
    for(auto edge:edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> vis(V,0);
    vector<vector<int>> ans;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int> temp;
            dfs(i,vis,adj,temp);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
    }
    return ans;
}

//15.2 bfs/dfs
//1 same as 15.1 4
//no of islands 
to call for 8 directions
dx -1 to 1
    dy -1 to 1
// 2 Connected Components Problem in Matrix same as 15.1 4

// 3 Rotten Oranges
#include <bits/stdc++.h>
bool canAffect(int x,int y,vector<vector<int>>& grid){
    if(x<0 || y<0 || x==grid.size() || y==grid[0].size() || grid[x][y]!=1) return 0;
    return 1;
}

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    int ones=0;
    queue<pair<int,int> >q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1) ones++;
            else if(grid[i][j]==2) q.push({i,j});
        }
    }
    if(ones==0) return 0;
    
    int time=0;
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};

    while(!q.empty()){
        int qsize=q.size();
        while(qsize--){
            auto curr=q.front();
            q.pop();
            int x=curr.first, y=curr.second;

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(canAffect(nx,ny,grid)){
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                    ones--;
                }
            }
        }
        time++;
        if(ones==0) return time;
        
    }
    return -1;
}
// 4 Flood fill
void dfs(int x, int y, int p,int val,vector<vector<int>> &image,int dx[],int dy[]){
    image[x][y]=p;
    for(int k=0;k<4;k++){
        int newx=x+dx[k];
        int newy=y+dy[k];

        if(newx>=0 && newy>=0 && newx<image.size() && newy<image[0].size() && image[newx][newy]==val){
            dfs(newx, newy, p, val, image, dx, dy);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int n, int m, int x, int y, int p) {
    // Write your code here.
    if(image[x][y]==p) return image;
    int val=image[x][y];//new=p
    int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
    dfs(x,y,p,val,image,dx,dy);
    return image;
}
// 5 Cycle Detection in unirected Graph (bfs)
class Graph {

public:
    bool detectCycleHelp(int V, vector<int> adj[],int start,vector<int> &vis) {
        
        // Write your code here.
        queue<pair<int,int> > q;

        vis[start]=1;
        q.push({start,-1});

        while(!q.empty()){
            auto curr=q.front();
            q.pop();

            int node=curr.first, parent=curr.second;
            for(auto nei:adj[node]){
                if(!vis[nei]){
                    vis[nei]=1;
                    q.push({nei,node});//incorrect {nei,parent}
                }else{
                    if(nei!=parent) return 1;
                }
            }
        }

        return 0;
    }
    bool detectCycle(int V, vector<int> adj[]) {
        // unordered_set<int> vis;//better to use vector<bool> vis
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectCycleHelp(V, adj,i,vis)) return 1;
            }
        }
        return 0;
    }
};
// 6 Cycle Detection in undirected Graph (dfs)
class Graph {

public:
    bool dfs(int src,int par,vector<int> &vis,vector<int> adj[]){
        vis[src]=1;
        for(auto nei:adj[src]){
            if(!vis[nei]){
                if(dfs(nei,src,vis,adj)) return 1;
            }else{
                if(nei!=par) return 1;
            }
        }
        return 0;
    }
    bool detectCycle(int V, vector<int> adj[]) {
        // Write your code here.
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj)) return 1;
            }
        }
        return 0;
    }
};
// 7 0/1 Matrix (Bfs Problem)
vector < vector < int > > nearest(vector < vector < int >> & mat, int n, int m) {
    // Write your code here.
    vector<vector<int>> ans(n,vector<int> (m,-1));
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1){
                ans[i][j]=0;
                q.push({i,j});
            }
        }
    }
    int dist=1;
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            auto cur=q.front();
            q.pop();
            int x=cur.first, y=cur.second;
            for(int k=0;k<4;k++){
                int nx=x+dx[k], ny=y+dy[k];

                if(nx>=0 && ny>=0 && nx<n && ny<m && ans[nx][ny]==-1){
                    ans[nx][ny]=dist;
                    q.push({nx,ny});
                }
            }

        }
        dist++;
    }
    return ans;
}
// 8 Surrounded Regions (dfs)
#include <vector>
using namespace std;
void dfs(int i,int j,vector<vector<int>> &vis,char** arr, int n, int  m){
    vis[i][j]=1;
    int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
    for(int k=0;k<4;k++){
        int ni=i+dx[k], nj=j+dy[k];
        if(ni>=0 && nj>=0 && ni<n && nj<m && arr[ni][nj]=='O' && !vis[ni][nj]){
            dfs(ni, nj, vis, arr, n, m);
        }
    }
}

void replaceOWithX(char** arr, int n, int  m)
{
    //Write your code here   
    vector<vector<int>> vis(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0 || i==n-1 || j==m-1){
                if(arr[i][j]=='O'){
                    dfs(i,j,vis,arr,n,m);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++) {
            if(!vis[i][j]) arr[i][j]='X';
        }
    }
    return;
}
// 9 Number of Enclaves [flood fill implementation - multisource]
void dfs(int x,int y,vector<vector<int>> &Matrix){
    int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
    for(int k=0;k<4;k++){
        int nx=x+dx[k], ny=y+dy[k];
        if(nx>=0 && ny>=0 && nx<Matrix.size() && ny<Matrix[0].size() && Matrix[nx][ny]==0){
            Matrix[nx][ny]=1;
            dfs(nx, ny, Matrix);
        }
    }
}

int matrixTraps(int N,int M,vector<vector<int>> &Matrix)
{
    // Write your code here.
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Matrix[i][j]==0){               
                if(i==0 || j==0 || i==N-1 || j==M-1){           
                    Matrix[i][j]=1;//or use visited        
                    dfs(i,j,Matrix);
                }
            }
        }
    }
    int zeros=0;
    for(int i=1;i<N-1;i++){ // [0,N) would also work but [1,N-1) better
        for (int j = 1; j < M-1; j++) {
            if(Matrix[i][j]==0) zeros++;
        }
    }
    return zeros;
}
// 10 Word ladder - 1

// 11 Word ladder - 2

// 12 Number of Distinct Islands [dfs multisource]
#include <bits/stdc++.h>
void dfs(int** arr, int n, int m,int ci,int cj,int i,int j,vector<pair<int,int>> &v) { 
    v.push_back({ci - i, cj - j}) ;
    int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
    for(int k=0;k<4;k++){
        int ni=ci+dx[k], nj=cj+dy[k];
        if(ni>=0 && nj>=0 && ni<n && nj<m && arr[ni][nj]){
            arr[ni][nj]=0;
            dfs(arr, n, m, ni, nj, i, j, v);
        }
    }
}

int distinctIslands(int** arr, int n, int m)
{
    //Write your code here
    set<vector<pair<int,int>>> s;//store distinct shapes
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]){
                vector<pair<int,int>> v;
                arr[i][j]=0;
                dfs(arr,n,m,i,j,i,j,v);
                s.insert(v);
            }
        }
    }
    return s.size();
}
//a2
    ‘S’ - starting vertex

     ‘D’ - down

     ‘U’ - up

     ‘L’ - left

     ‘R’ - right

     ‘B’ - backtrack
// 13 Bipartite Graph (DFS)
Bipartite 
If all notes can be divided into two independent set such that every node marks from one-node of set A to a node of set B. 
Non bipartite if cycle of odd length
//a1 bfs
#include <bits/stdc++.h>
bool bfs(vector<vector<int>> &edges,vector<int> &color,int st) {
    int nodes=edges.size();
    color[st]=1;
    queue<int> q;
    q.push(st);
    int nextCol=2;
    while(!q.empty()){
        int n=q.size();
        while(n--){
            int cur=q.front();
            q.pop();

            for(int nei=0;nei<nodes;nei++){
                if(edges[cur][nei]){
                    if(!color[nei]){
                        color[nei]=nextCol;
                        q.push(nei);
                    }else{
                        if(color[nei] != nextCol) return 1;//detected a cycle of odd length
                    }
                }
                
            }
        }
        nextCol=nextCol^1^2;
    }
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    // Write your code here.
    int v=edges.size();
    vector<int> color(v,0);//0 uncoloured 1 first colour 2 second
    for(int i=0;i<v;i++){
        if(!color[i]){
            if(bfs(edges,color,i)) return 0;
        }
    }
    return 1;
}
//a2 dfs 
#include <bits/stdc++.h>
bool dfs(vector<vector<int>> &edges,vector<int> &color,int st,int curCol) {
    color[st]=curCol;
    int n=edges.size();
    for(int i=0;i<n;i++){
        if(edges[st][i]){   //if nei
// If neighbour not coloured colour with opposite colour, else check if neighbour coloured with same colour then non bipartite
            if(!color[i]){
                if( dfs(edges,color,i,curCol^1^2) ) return 1;
            }else if(color[i] == curCol) return 1;
        }
    }
    return 0;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    // Write your code here.
    int v=edges.size();
    vector<int> color(v,0);//0 uncoloured 1 first colour 2 second
    for(int i=0;i<v;i++){
        if(!color[i]){
            if(dfs(edges,color,i,1)) return 0;
        }
    }
    return 1;
}

// 14 Cycle Detection in Directed Graph (DFS)
//pg1 eg
bool dfs(int cur,vector<int> &vis,vector<vector<int>> &adj){
    vis[cur]=2;
    for(auto nei:adj[cur]){
        if(!vis[nei]){
            if(dfs(nei, vis, adj)) return 1;
        }else if(vis[nei]==2) return 1;
    }
    vis[cur]=1;
    return 0;
}

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
    // Write your code here
    vector<vector<int>> adj(v);
    for(auto edge:edges){
        int v1=edge[0], v2=edge[1];
        adj[v1].push_back(v2);
        // adj[v2].push_back(v1);   //missed

    }

    vector<int> vis(v,0);//0 not vis, 1 vis,2 path visited
    //if any node path vis on same path means cycle
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfs(i,vis,adj)) return 1;
        }
    }
    return 0;
}

//15.3 topo
//1 Topo Sort
//dependant 
// 1->2 1 can be done post 2
#include <bits/stdc++.h>
void dfs(int node,vector<vector<int>> &adj,stack<int> &st,vector<int> &vis){
    vis[node]=1;
    for(auto nei:adj[node]){
        if(!vis[nei]){
            dfs(nei,adj,st,vis);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
    vector<vector<int>> adj(nodes);
    for(auto ed:graph){
        adj[ed[0]].push_back(ed[1]);
    }
    vector<int> vis(nodes,0), ans;
    stack<int> st;
    
    for(int i=0;i<nodes;i++){
        if(!vis[i]){
            dfs(i,adj,st,vis);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
//2 Kahn's Algorithm
//node whose indegree is 0 will come first
#include <bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
    vector<vector<int>> adj(nodes);
    for(auto ed:graph){
        adj[ed[0]].push_back(ed[1]);
    }
    vector<int> in(nodes,0);
    for(auto neis:adj){
        for(int nei:neis) in[nei]++;
    }

    queue<int> q;
    vector<int> ans;
    for(int i=0;i<nodes;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        ans.push_back(cur);
        for(int nei:adj[cur]){
            if(in[nei]--==1) q.push(nei);
        }
    }
    return ans;
}

//3 Cycle Detection in Directed Graph (BFS)
    //cycle will not let indegree become 0
#include <bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<vector<int>> adj(n+1);
  for(auto ed:edges){
    adj[ed.first].push_back(ed.second);
  }

  vector<int> in(n+1,0);
  for(auto neis:adj){
    for(auto nei:neis) in[nei]++;
  }

  queue<int> q;
  for(int i=1;i<=n;i++){
    if(in[i]==0) q.push(i);
  }
  int c=0;
  while(!q.empty()){
    int cur=q.front();
    q.pop();
    c++;
    for(auto nei:adj[cur]){
      if(in[nei]--==1) q.push(nei);
    }

  }
  return c!=n;


}
//4 & 5 Course Schedule - 1&2
//1 check if no cycle
//2 return ans if no cycle else {}
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto ed:prerequisites){
            adj[ed[1]].push_back(ed[0]);
        }
        vector<int> in(numCourses,0);
        for(auto neis:adj){
            for(auto nei:neis) in[nei]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in[i]==0) q.push(i);
        }
        // int c=0;
        vector<int> ans;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            // c++;
            ans.push_back(cur);

            for(auto nei:adj[cur]){
                if(in[nei]--==1) q.push(nei);
            }
        }
        // return c==numCourses;
        if(ans.size()==numCourses) return ans;
        return {};
    }
};
//6 safe nodes
//a1 fails
    //outdegree doesnt tell which nodes outdegree to reduce
#include <bits/stdc++.h> 
vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    // Write your code here.
    vector<vector<int>> adj(n);
    for(auto ed:edges){
        adj[ed[0]].push_back(ed[1]);
    }
    vector<int> out(n,0);
    for(int i=0;i<n;i++){
        out[i]=adj[i].size();
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(out[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        ans.push_back(cur);

        
    }
}
//a2 indegree
#include <bits/stdc++.h> 
vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    // Write your code here.
    vector<vector<int>> adj(n);
    for(auto ed:edges){
        adj[ed[1]].push_back(ed[0]);
    }
    vector<int> in(n,0);
    for(auto neis:adj){
        for(auto nei:neis) in[nei]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(in[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        ans.push_back(cur);

        for(auto nei:adj[cur]){
            if(in[nei]--==1) q.push(nei);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
//a3 dfs vis & pathVis
    //ptc
//7 Alien Dictionary
//a1 tle
    //comparing word with all its successor
    string findOrder(string dict[], int N, int K) {
        //code here
        vector< set<int> > adj(K);
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                int p1=0,p2=0;
                int n1=dict[i].size(), n2=dict[j].size();
                while(p1<n1 && p2<n2){
                    if(dict[i][p1] != dict[j][p2]){
                        adj[ dict[i][p1]-'a' ].insert(dict[j][p2]-'a');
                        break;
                    }else {
                        p1++;
                        p2++;
                    }
                }
            }
        }
        vector<int> in(K,0);
        for(auto neis:adj){
            for(auto nei:neis) in[nei]++;
        }

        queue<int> q;
        for(int i=0;i<K;i++){
            if(in[i]==0) q.push(i);
        }
        // vector<int> ans;
        string s;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            // ans.push_back(cur);
            s+=('a'+cur);

            for(auto nei:adj[cur]){
                if(in[nei]--==1) q.push(nei);
            }
        }
        // for(auto x:ans) cout<<x<<" ";
        // cout<<endl;
        return s;
    }
//a2 no tle
    //only compare neighbouring 2 words
        for(int i=0;i<N-1;i++){
            int j=i+1;
            int p1=0,p2=0;
            int n1=dict[i].size(), n2=dict[j].size();
            while(p1<n1 && p2<n2){
                if(dict[i][p1] != dict[j][p2]){
                    adj[ dict[i][p1]-'a' ].insert(dict[j][p2]-'a');
                    break;
                }else {
                    p1++;
                    p2++;
                }
            }
            
        }
//a3
// The insert method of an unordered_set in C++ returns a pair of values. The first value is an iterator pointing to the inserted element (or to the element that prevented the insertion), and the second value is a boolean indicating whether the insertion took place.

// If the insertion took place (i.e., the element was not already in the set), the second value of the pair is true. If the element was already present in the set and hence not inserted, the second value is false.
string findOrder(string dict[], int N, int K) {
    vector<vector<int>> adj(K);
    vector<int> in(K, 0);

    unordered_set<string> uniqueEdges;

    for (int i = 0; i < N - 1; ++i) {
        string word1 = dict[i], word2 = dict[i + 1];
        int len = min(word1.length(), word2.length());
        int j = 0;

        while (j < len && word1[j] == word2[j]) ++j;

        if (j < len && uniqueEdges.insert(word1.substr(j, 1) + word2.substr(j, 1)).second) {
            adj[word1[j] - 'a'].push_back(word2[j] - 'a');
            ++in[word2[j] - 'a'];
        }
    }

    queue<int> q;
    for (int i = 0; i < K; ++i) {
        if (in[i] == 0) q.push(i);
    }

    string result;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        result += (cur + 'a');

        for (int nei : adj[cur]) {
            if (--in[nei] == 0) q.push(nei);
        }
    }

    return result.size() == K ? result : "";
}
//a4
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        vector<int> in(K, 0);
    
        for (int i = 0; i < N - 1; ++i) {
            string word1 = dict[i], word2 = dict[i + 1];
            int len = min(word1.length(), word2.length());
            int j = 0;
    
            while (j < len && word1[j] == word2[j]) ++j;
    
            if (j < len) {
                adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                ++in[word2[j] - 'a'];
            }
        }
    
        queue<int> q;
        for (int i = 0; i < K; ++i) {
            if (in[i] == 0) q.push(i);
        }
    
        string result;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            result += (cur + 'a');
    
            for (int nei : adj[cur]) {
                if (--in[nei] == 0) q.push(nei);
            }
        }
    
        return result.size() == K ? result : "";
    }
//15.4 

// 1  
// 2  
// 3  
// 4  
// 5  
// 6  
// 7  
// 8  
// 9  
// 10  
// 11  
// 12  
// 13  

//15.5

// 1  
// 2  
// 3  
// 4  
// 5  
// 6  minimum number of operations that will be required to make the graph connected.
    //a1
    void dfs(int start,vector<int> &vis,vector<vector<int>> &adj){
        vis[start]=1;
        for(auto nei:adj[start]){
            if(!vis[nei]) dfs(nei,vis,adj);
        }
    }
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        int m=edge.size();
        if(n>m+1) return -1;//insufficient edge to get connected
        //no of operation=no of components-1

        vector<vector<int>> adj;
        for(auto ed:edge){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);

        }

        vector<int> vis(n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                c++;

            }
        }
        return c-1;

    }
// 7  
// 8  
// 9  
// 10  
// 11  

//15.6
// 1
// 2
// 3

//16 DP
//16.1 intro
//1 fibo
//a1 recursion
    //tc O(2^n) sc O(n) stack space
#include<bits/stdc++.h>
using namespace std;
int fib(int n){
        if(n<=1) return n;
        return fib(n-1)+fib(n-2);
}
int main()
{

        int n;
        cin>>n;

        cout<<fib(n)<<endl;
}
//a2 memoization top-down
    //tc O(n) sc O(n)+O(n) array+stack
int fib(int n,vector<int> &dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fib(n-1,dp)+fib(n-2,dp);//missed second parameter dp
}

int main()
{
 
        int n;
        cin>>n;
        vector<int> dp(n+1,-1);
        cout<<fib(n,dp)<<endl;
}
//a3 tabulation bottom-up
    //tc O(n) sc O(n) array
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
        // cout<<fib(dp[n])<<endl;//missed to remove fib
        cout<<dp[n]<<endl;//missed to remove fib
//a4 space optimised
        int p2=0,p1=1;
        for(int i=2;i<=n;i++) {
              int cur=p1+p2;
              p2=p1;
              p1=cur;  
        }
        cout<<p1<<endl;

//16.2
// 1 countDistinctWays to climb stairs
//a1 recursion tle
#include <bits/stdc++.h> 
int countDistinctWays(int n) {  //n=nStairs
    //  Write your code here.
    if(n<=1) return 1;
        //to reach 0th stair 1 way : no climb
                    // 1st stair 1 way: climb 1 step
    return countDistinctWays(n-1)+countDistinctWays(n-2);
        //we can reach step5 from all ways we reached step4+climb1 and step 3 +climb2
}
//a2
#include <bits/stdc++.h> 
int mod=1e9+7;
//int can store till 2147483647
//so sum( countDistinctWaysH(n-1,dp)+countDistinctWaysH(n-2,dp)  ) will always be within range as 1e9+1e9 will be within range
//so sum can exceed 1e9 but will never exceed int max 2147483647 
    // 3 1e9 would exceed, 2 wont
int  countDistinctWaysH(int n,vector<int> &dp) {  //n=nStairs
    //  Write your code here.
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];
        //to reach 0th stair 1 way : no climb
                    // 1st stair 1 way: climb 1 step
    return dp[n]=( countDistinctWaysH(n-1,dp)+countDistinctWaysH(n-2,dp) )%mod;
        //we can reach step5 from all ways we reached step4+climb1 and step 3 +climb2
}

int  countDistinctWays(int n) { // n=nStairs
    vector<int> dp(n+1,-1);
    return countDistinctWaysH(n,dp);
}
//a3
int  countDistinctWays(int n) { // n=nStairs
    vector<int> dp(n+1);
    
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
        // dp[n]=(dp[n-1]+dp[n-2])%mod;//incorrect wrote n inplace of i

    }
   
    return dp[n];
}
//a4 matrix exponentiation ptc

// 2
//a1 tle to reach nth element
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    if(n==1) return 0;
    if(n==2) return abs(heights[1]-heights[0]);

    int option1=frogJump(n-1, heights)+abs(heights[n-1]-heights[n-2]);
    int option2=frogJump(n-2, heights)+abs(heights[n-1]-heights[n-3]);
    return min(option1,option2);
}
//a2 tle to reach nth index
int frogJump2(int n, vector<int> &heights)
{
    // Write your code here.
    if(n==0) return 0;
    if(n==1) return abs(heights[1]-heights[0]);

    int option1=frogJump2(n-1, heights)+abs(heights[n]-heights[n-1]);
    int option2=frogJump2(n-2, heights)+abs(heights[n]-heights[n-2]);
    return min(option1,option2);
}

int frogJump(int n, vector<int> &heights){
    return frogJump2(n-1, heights);
}
//a3 memo
int frogJump2(int n, vector<int> &heights,vector<int> &dp)
{
    // Write your code here.
    if(n==0) return 0;
    if(n==1) return abs(heights[1]-heights[0]);
    if(dp[n]!=-1) return dp[n];
    int option1=frogJump2(n-1, heights,dp)+abs(heights[n]-heights[n-1]);
    int option2=frogJump2(n-2, heights,dp)+abs(heights[n]-heights[n-2]);
    return dp[n]=min(option1,option2);
}

int frogJump(int n, vector<int> &heights){
    vector<int> dp(n,-1);
    return frogJump2(n-1, heights,dp);
}
//a4 tabu
int frogJump(int n, vector<int> &heights){
    if(n==1) return 0;
    vector<int> dp(n);
    dp[1]=abs(heights[1]-heights[0]);
    for(int idx=2;idx<n;idx++){
        dp[idx]=min( dp[idx-1]+abs(heights[idx]-heights[idx-1]) ,
        dp[idx-2]+abs(heights[idx]-heights[idx-2]) );
    }
    return dp[n-1];
}
// 3 frogJump with k steps
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int> dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mini=INT_MAX;
        for(int j=1;j<=k && i-j>=0;j++){
            mini=min(mini,dp[i-j]+abs(height[i]-height[i-j]) );//missed i-j
        }
        dp[i]=mini;
    }
    return dp[n-1];
}
//a2
int f(int idx,int k,vector<int> &height,vector<int> &dp){
    if(idx==0) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int mini=INT_MAX;
    for(int i=1;i<=k && idx-i>=0;i++){
        mini=min(mini,f(idx-i, k, height, dp)+abs(height[idx]-height[idx-i]) );
    }
    return dp[idx]=mini;
}
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int> dp(n,-1);
    return f(n-1,k,height,dp);
}
// 4
#include <bits/stdc++.h> 
int f(int idx,vector<int> &nums,vector<int> &dp){
    if(idx>=nums.size()) return 0;
    if(dp[idx]!=-1) return dp[idx];

    int take=nums[idx]+f(idx+2,nums,dp);
    int skip=f(idx+1,nums,dp);

    return dp[idx]=max(take,skip);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n,-1);
    return f(0,nums,dp);

}
//a2
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n,0);
    dp[0]=nums[0];
    // dp[1]=max(nums[0],nums[1]);
    for(int i=1;i<n;i++){
        int maxi=INT_MIN;
        maxi=dp[i-1];
        if(i>1){
            maxi=max(maxi,dp[i-2]+nums[i]);
        }else{  //missed else
            maxi=max(maxi,nums[i]);
        }
        dp[i]=maxi;
    }
    return dp[n-1];

}
//a2.2
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    if(n==1) return nums[0];
    vector<int> dp(n,0);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[n-1];

}
//a2.3
    int n=nums.size();
    // if(n==1) return nums[0];
    vector<int> dp(n,0);
    dp[0]=nums[0];
    // dp[1]=max(nums[0],nums[1]);
    for(int i=1;i<n;i++){
        dp[i]=max(dp[i-1],(i>1?dp[i-2]:0)+nums[i]);
    }
    return dp[n-1];
// 5
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();
    if(n==1) return valueInHouse[0];
    //if n<2 one vector will be empty so check
    
    // vector<int> v1(valueInHouse.begin(),valueInHouse.begin()+n-1);
    vector<int> v1(valueInHouse.begin(),valueInHouse.end()-1);
    vector<int> v2(valueInHouse.begin()+1,valueInHouse.end());

    return max(maximumNonAdjacentSum(v1),maximumNonAdjacentSum(v2));
}
//16.2 2d 3d dp
//1 max points by doing any 1 activity out of 3 for n days without doing same activity on two days together
//a1 tle
#include <bits/stdc++.h>
int f(int idx,int pre,int n,vector<vector<int>> &points){
    if(idx==n) return 0;

    int maxi=INT_MIN;
    for(int i=0;i<3;i++){
        if(i==pre) continue;    //cannot use same as previous
        maxi=max(maxi,points[idx][i]+f(idx+1,i,n,points));
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return f(0,-1,n,points);    //or (0,n)
}
//a2 n*4 array
#include <bits/stdc++.h>
int f(int idx,int pre,int n,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(idx==n) return 0;
    if(dp[idx][pre]!=-1) return dp[idx][pre];
    int maxi=INT_MIN;
    for(int i=0;i<3;i++){
        if(i==pre) continue;    //cannot use same as previous
        maxi=max(maxi,points[idx][i]+f(idx+1,i,n,points,dp));
    }
    return dp[idx][pre]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int> (4,-1));
        //4 states 0,1,2 and 3(as -1 as on 0th day nothing selected prev)
    return f(0,3,n,points,dp);    //or (0,n)
}
//a3 n*3 array
#include <bits/stdc++.h>
int f(int idx,int pre,int n,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(idx==n) return 0;
    if(pre!=-1 && dp[idx][pre]!=-1) return dp[idx][pre];
    int maxi=INT_MIN;
    for(int i=0;i<3;i++){
        if(i==pre) continue;    //cannot use same as previous
        maxi=max(maxi,points[idx][i]+f(idx+1,i,n,points,dp));
    }
    if(pre==-1) return maxi;
    return dp[idx][pre]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int> (3,-1));
        //4 states 0,1,2 and 3(as -1 as on 0th day nothing selected prev)
    return f(0,-1,n,points,dp);    //or (0,n)
}
//a4
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    // int n=points.size();
    vector<vector<int>> dp(n,vector<int> (3,0));
    dp[0][0]=points[0][0];
    dp[0][1]=points[0][1];
    dp[0][2]=points[0][2];

    for(int day=1;day<n;day++){
        //find max we can get by doing all activity on given day
        //dp[i][j] will store max points we can get by doing jth activity on ith day
        for(int act=0;act<3;act++){
            
            int maxi=INT_MIN;
            for(int pre=0;pre<3;pre++){
                if(pre==act) continue;
                maxi=max(maxi,dp[day-1][pre]);//get max we can get from doing any other activity on prev day
            }
            dp[day][act]=points[day][act] + maxi;
        }
    }
    int ansMax=INT_MIN;
    for(int i=0;i<3;i++){
        ansMax=max(ansMax,dp[n-1][i]);
    }
    return ansMax;
}
//a5 ptc
//Space optimisation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    int a,b,c, d,e,f  ;
    a = points[0][0] ;
    b = points[0][1] ;
    c = points[0][2] ;
    for( int i = 1 ; i < n ; i++ )
    {
        d = points[i][0] + max(b,c) ;
        e = points[i][1] + max(a,c) ;
        f = points[i][2] + max(b,a) ;
        a = d ;
        b = e ; 
        c = f ;
    }
    return max(a, max(b,c)) ;
}

//2 Grid Unique Paths : DP on Grids (DP8)
//a1
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
    // Write your code here.
    vector<vector<int>> dp(m,vector<int> (n,0));
    dp[m-1][n-1]=1;
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i+1<m) dp[i][j]+=dp[i+1][j];
            if(j+1<n) dp[i][j]+=dp[i][j+1];
            //error out of bound missed to check these 2 condition
        }
    }
    return dp[0][0];
}
//a2 
(m-1+n-1)!/( (m-1)! * (n-1)! )
//a3
if(m<n)
(m+n-2)C(m-1) 
else
(m+n-2)C(n-1)  
//a4 ptc
int uniquePaths(int m,int n)
{
    // Reference array to store subproblems.
    int dp[n] = {1};                   

    // Bottom up approach.
    dp[0] = 1;

    for (int i = 0; i < m; i++) 
    {      
        for (int j = 1; j < n; j++) 
        { 
            dp[j] += dp[j - 1];  
        }
    } 
    
    //Returning answer. 
    return dp[n - 1];                  
}
/*
for 3*4 observe the numbers
1 1 1 1
1 2 3 4
1 3 6 10
*/

//3 Grid Unique Paths 2 (DP 9)
    //cannot go through -1 cell
int mazeObstacles(int m, int n, vector< vector< int> > &mat) {
    // Write your code here
    if(mat[0][0]==-1 || mat[m-1][n-1]==-1) return 0;
    int mod=1e9+7;

    vector<vector<int>> dp(m,vector<int> (n,0));
    dp[m-1][n-1]=1;
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(mat[i][j]==-1) continue;//major change
            if(i+1<m) dp[i][j]=(dp[i][j]+dp[i+1][j])%mod;
            if(j+1<n) dp[i][j]=(dp[i][j]+dp[i][j+1])%mod;
            //error out of bound missed to check these 2 condition
        }
    }
    return dp[0][0];
}

//4 Minimum path sum in Grid (DP 10)
#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size(), m=grid[0].size();
    vector<vector<int>> dp(n,vector<int> (m,0));
    dp[n-1][m-1]=grid[n-1][m-1];//incorrect dp[n-1][m-1]=0
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int mini=INT_MAX;
            if(i+1<n) mini=min(mini,dp[i+1][j]);
            if(j+1<m) mini=min(mini,dp[i][j+1]);
            if(mini!=INT_MAX)   //missed
                dp[i][j]=grid[i][j]+mini;
        }
    }
    return dp[0][0];
}
//a1.2
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size(), m=grid[0].size();
    vector<vector<int>> dp(n,vector<int> (m,0));
    dp[n-1][m-1]=grid[n-1][m-1];//incorrect dp[n-1][m-1]=0
    for(int i=n-2;i>=0;i--)
        dp[i][m-1]=grid[i][m-1]+dp[i+1][m-1];
    for(int j=m-2;j>=0;j--)
        dp[n-1][j]=grid[n-1][j]+dp[n-1][j+1];
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
        }
    }
    return dp[0][0];
}
//5 Minimum path sum in Triangular Grid (DP 11)
//a1
#include <bits/stdc++.h> 
int minimumPathSum(vector<vector<int>>& triangle, int n){
    // Write your code here.
    for(int i=1;i<n;i++){
        int col=triangle[i].size();
        for(int j=0;j<col;j++){
            //missed first & last element condition in each row
            if(j==0) triangle[i][j]+=triangle[i-1][j];
            else if(j==col-1) triangle[i][j]+=triangle[i-1][j-1];
            else triangle[i][j]+=min(triangle[i-1][j],triangle[i-1][j-1]);
        }
    }
    // for(auto x:triangle[n-1]) cout<<x<<" ";
    // cout<<endl;
    int ansMin=INT_MAX;
    int colsInLastRow=triangle[n-1].size();
    for(int j=0;j<colsInLastRow;j++){
        ansMin=min(ansMin,triangle[n-1][j]);
    }
    return ansMin;
}
//a2
    for (int i=n-2;i>=0;i--) {
        for(int j=0;j<=i;j++){
            triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
        }
        
    }
    return triangle[0][0];
//6 Minimum/Maximum Falling Path Sum (DP-12)
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n=matrix.size(), m=matrix[0].size();
    if(n==1){
        //return max in row
        int ansMax=INT_MIN;
        for(int j=0;j<m;j++){
            ansMax=max(ansMax,matrix[0][j]);
        }
        return ansMax;
    }
    if(m==1){
        //return sum of all
        int ansMax=0;
        for(int i=0;i<n;i++){
            ansMax+=matrix[i][0];
        }
        return ansMax;
    }
    vector<vector<int>> dp(n,vector<int> (m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0){
                dp[i][j]=matrix[i][j];
            }else if(j==0){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j+1]) + matrix[i][j];
            }else if(j==m-1){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]) + matrix[i][j];

            }else{
                dp[i][j]=max(  max(dp[i-1][j],dp[i-1][j-1]), dp[i-1][j+1] ) + matrix[i][j];
            }
        }
    }
    int ansMax=INT_MIN;
    for(int j=0;j<m;j++){
        ansMax=max(ansMax,dp[n-1][j]);
    }
    return ansMax;
}
//a2
matrix[row][col] = matrix[row][col] + max(matrix[row - 1][col], max(matrix[row - 1][max(0, col - 1)], matrix[row - 1][min(m - 1, col + 1)]));

//7 3-d DP : Ninja and his friends (DP-13)
//a1
#include <bits/stdc++.h> 
int f(int cur,int a,int b,int r, int c, vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){ //cur:current row
    // cout<<a<<" "<<b<<endl;
    if(dp[cur][a][b] != -1) return dp[cur][a][b] ;
    int sum=grid[cur][a]+grid[cur][b];
    if(a==b) sum/=2;
    if(cur==r-1){     
        return sum;
    }

    int amin=max(0,a-1);
    int amax=min(c-1,a+1);
    int bmin=max(0,b-1);
    int bmax=min(c-1,b+1);

    // cout<<amin<<" "<<amax<<" "<<bmin<<" "<<bmax<<endl;

    int maxi=INT_MIN;
    for(int i=amin;i<=amax;i++){
        for(int j=bmin;j<=bmax;j++){
            maxi=max(maxi,f(cur+1, i, j, r, c, grid,dp));
        }
    }

    return dp[cur][a][b] = maxi+sum;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    
    return f(0, 0, c-1, r, c, grid,dp);
}
//a2 ptc
#include <bits/stdc++.h> 
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    int dp[r][c][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            for(int k=0;k<c;k++){
                dp[i][j][k]=0;
            }
        }
    }
        dp[0][0][c-1] = grid[0][0] + grid[0][c-1];
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                if(j>i){break;}
                int k= c>=r?c-1-i:0;
                for(;k<c;k++){
                    if(k<c-1-i){continue;}
                    int maxi=0;
                    for(int per=j-1;per<=j+1;per++){
                        if(per<0 || per>=c){continue;}
                        if(k>0)maxi = max(dp[i-1][per][k-1],maxi);
                        maxi=max(dp[i-1][per][k],maxi);
                        if(k<c-1)maxi=max(dp[i-1][per][k+1],maxi);
                    }
                    dp[i][j][k] = maxi+ (j!=k?grid[i][j]+grid[i][k]:grid[i][k]);
                }
            }
        }
        int res=0;
        for(int i=0;i<c;i++){
            for(int j=0;j<c;j++){
                res=max(dp[r-1][i][j],res);
            }
        }
        return res;
}

//16.4
// 1 Subset sum equal to target (DP- 14)
#include <bits/stdc++.h> 
bool f(int idx,int sum,int n, int k, vector<int> &arr,vector<vector<int>> &dp){
    if(idx==n){
        return sum==k;
    }
    // if(dp[idx][sum] != -1) return dp[idx][sum] ;
    //cant write here as sum might be greater than k and we are storing till k

    if(sum==k)  return dp[idx][sum] =1;
    if(sum>k) return 0;

    if(dp[idx][sum] != -1) return dp[idx][sum] ;

    return dp[idx][sum] = f(idx+1,sum+arr[idx],n,k,arr,dp) || f(idx+1,sum,n,k,arr,dp);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
    return f(0,0,n,k,arr,dp);
}
//a2 remaining sum
#include <bits/stdc++.h> 
bool f(int idx,int sum,int n, int k, vector<int> &arr,vector<vector<int>> &dp){
    if(idx==n){
        return sum==0;
    }
    // if(dp[idx][sum] != -1) return dp[idx][sum] ;
    //cant write here as sum might be greater than k and we are storing till k

    if(sum==0)  return dp[idx][sum] =1;
    if(sum<0) return 0;

    if(dp[idx][sum] != -1) return dp[idx][sum] ;

    return dp[idx][sum] = f(idx+1,sum-arr[idx],n,k,arr,dp) || f(idx+1,sum,n,k,arr,dp);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
    return f(0,k,n,k,arr,dp);
}
//a2
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<int> dp(k+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        if(arr[i]==0) continue;
        // for(int j=arr[i];j<=k;j++){  //incorrect 
            //eg n=5 k=4 100000.
            //arr[i]=2       101010 but correct was 101000
        for(int j=k;j>=arr[i];j--){

            if(dp[j-arr[i] ]) dp[j]=1;
        }
        // for(auto x:dp) cout<<x<<" ";
        // cout<<endl;
        if(dp[k]) return 1;
    }

    return 0;
}
//a3
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int> (k+1,0));
    dp[0][0]=1;
    if(arr[0]<=k)   //missed if arr[0]>k
        dp[0][arr[0]]=1;

    for(int i=1;i<n;i++){
        //missed to update values less than arr[i]
        // for(int j=k;j>=arr[i];j--){
        //     if(dp[i-1][j] || dp[i-1][j-arr[i]]) dp[i][j]=1;
        // }
        for(int j=0;j<=k;j++){
            if(j>=arr[i]){
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i]];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
        if(dp[i][k]) return 1;
    }
    return 0;
}
// 2 Partition Equal Subset Sum (DP- 15)
bool f(vector<int> &arr, int n,int idx,int target,vector<vector<int>> &dp){
    if(target==0) return 1;
    if(idx==0) return arr[0]==target;

    if(dp[idx][target] != -1) return dp[idx][target];

    bool skip=f(arr,n,idx-1,target,dp);
    bool take=false;
    if(arr[idx]<=target)
    take=f(arr,n,idx-1,target-arr[idx],dp);

    return dp[idx][target] = skip||take;
}

bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.
    int sum=0;
    for(auto x:arr) sum+=x;
    if(sum&1) return 0;
    vector<vector<int>> dp(n,vector<int> (sum/2+1,-1));
    return f(arr,n,n-1,sum/2,dp);
}

// 3 Partition Set Into 2 Subsets With Min Absolute Sum Diff (DP- 16)
//a1 tle
void f(int idx,int cur,int sum,vector<int>& arr, int n,int &mini){
    if(idx==n){
        int rem=sum-cur;
        mini=min(mini,abs(cur-rem));
        return;
    }
    f(idx+1,cur+arr[idx],sum,arr,n,mini);
    f(idx+1,cur,sum,arr,n,mini);
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
    // Write your code here.
    int sum=0;
    for(auto x:arr) sum+=x;
    int mini=sum;
    f(0,0,sum,arr,n,mini);

    return mini;
}

//a2
int minSubsetSumDifference(vector<int>& arr, int n)
{
    // Write your code here.
    int sum=0;
    for(auto x:arr) sum+=x;
    int target=(sum+1)/2;

    vector<int> dp(target+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=target;j>=arr[i];j--){
            if(dp[j-arr[i]]) dp[j]=1;
        }
        if(dp[target]) return target-(sum-target);
    }

    for(int i=target;i>=0;i--){
        if(dp[i]) return abs(i-(sum-i));
    }
}
//a3 tle
int f(int cur,int idx,int sum,vector<int>& arr){
    if(idx==0){
        return abs(sum-2*cur);
    }
    return min(f(cur+arr[idx], idx-1,sum,arr),f(cur, idx-1, sum, arr));
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
    // Write your code here.
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return f(0,n-1,sum,arr);
}

// 4 Count Subsets with Sum K (DP - 17)
#include <bits/stdc++.h>
int mod=1e9+7;
int findWays(vector<int>& arr, int k)
{
    // Write your code here.
    int sum=0;
    for(auto x:arr) sum+=x;

    if(k>sum) return 0;
    // if(k==sum) return 1;//if no element is 0

    k=min(k,sum-k);// if sum is 11 and k=9 then we can solve for k=11-9=2

    vector<int> dp(k+1,0);
    dp[0]=1;

    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=k;j>=arr[i];j--){
            dp[j]=(dp[j]+dp[j-arr[i]])%mod;
        }
    }
    return dp[k];
}

// 5 Count Partitions with Given Difference (DP - 18)
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum=0;
    for(auto x:arr) sum+=x;
    if(d>sum) return 0;//missed

    if((sum&1)^(d&1)) return 0; //if d odd sum must be odd
            //if d even sum must be even
    // x+(x+d)=s=> x=(s-d)/2
    int k=(sum-d)/2;

    return findWays(arr, k);
}

// 6 0/1 Knapsack (DP - 19)
#include <bits/stdc++.h> 
int f(int idx,int maxWeight,vector<int> &weight, vector<int> &value, int n,vector<vector<int>> &dp){
    if(idx==n) return 0;

    if(dp[idx][maxWeight] != -1) return dp[idx][maxWeight];

    int skip=f(idx+1,maxWeight,weight,value,n,dp);
    int take=0;
    if(weight[idx]<=maxWeight) take=value[idx]+f(idx+1,maxWeight-weight[idx],weight,value,n,dp);

    return dp[idx][maxWeight] = max(skip,take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    // Write your code here
    vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));
    return f(0,maxWeight,weight,value,n,dp);
}
//a2
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    // Write your code here
    vector<int> dp(maxWeight+1,0);
    for(int i=0;i<n;i++){
        for(int wi=maxWeight;wi>=weight[i];wi--){
            dp[wi]=max(dp[wi],value[i]+dp[wi-weight[i]] );
        }
    }
    return dp[maxWeight];
}
// 7 Minimum Coins (DP - 20)
//a1 tle
#include <bits/stdc++.h> 

int f(int x,int idx,vector<int> &num){
    if(x==0) return 0;
    if(idx==num.size()) return 1e5;

    int skip=f(x,idx+1,num);
    int take=1e5;
    if(num[idx]<=x) take=1+f(x-num[idx],idx,num);

    return min(skip,take);
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int ans = f(x,0,num);
    if(ans!= 1e5) return ans;
    return -1;
}
//a2
#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<int> dp(x+1,1e5);
    dp[0]=0;//missed
    for(int i=0;i<num.size();i++){
        for(int j=num[i];j<=x;j++){
            dp[j]=min(dp[j],1+dp[j-num[i] ] );
        }
    }
    return dp[x]==1e5? -1:dp[x];
}
//a3
#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<int> dp(x+1,-1);
    dp[0]=0;//missed
    for(int i=0;i<num.size();i++){
        for(int j=num[i];j<=x;j++){
            if(dp[j-num[i]] != -1){
                if(dp[j] == -1) dp[j]=1+dp[j-num[i] ];
                else
                dp[j]=min(dp[j],1+dp[j-num[i] ] );
            }
            
        }
    }
    return dp[x];
}
// 8 Target Sum (DP - 21)
//a1 tle
#include <bits/stdc++.h> 
int f(int n, int target, vector<int>& arr,int idx){
    if(idx==n){
        return target==0;
    }

    return f(n,target+arr[idx],arr,idx+1) + f(n,target-arr[idx],arr,idx+1);
    //missed target+arr[idx] and wrote target which is wrong as no option to skip
    //either + or -
}
int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    return f(n,target,arr,0);
}
//a2
int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    int sum=0;
    for(auto x:arr) sum+=x;
    if(target>sum || target<-sum) return 0;

    //split into 2 parts
        //x+y=sum x-y=target
    //find subset which gives sum x
    //x=(sum+target)/2;
    if((sum-target)&1) return 0;// 1 odd other even
    int k=(sum+target)/2;
    //count subsets with sum k
    return findWays(arr, k);
}
// 9 Coin Change 2 (DP - 22)
long countWaysToMakeChange(int *denominations, int n, int value)
{
 
    //Write your code here
    vector<long> dp(value+1,0);
    dp[0]=1;

    for(int i=0;i<n;i++){
        int coin=denominations[i];
        for(int j=coin;j<=value;j++){
            dp[j]+=dp[j-coin];
        }
    }
    return dp[value];
}
// 10 Unbounded Knapsack (DP - 23)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<int> dp(w+1,0);
    for(int i=0;i<n;i++){
        int cur=weight[i];
        for(int j=cur;j<=w;j++){
            dp[j]=max(dp[j],profit[i]+dp[j-cur ] );
        }
    }
    return dp[w];
// 11 Rod Cutting Problem | (DP - 24)
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            dp[j]=max(dp[j],price[i-1]+dp[j-i]);
        }
    }
    return dp[n];
}
