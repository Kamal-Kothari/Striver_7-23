//POTD GFG LEETCODE CN
//L 1/7
class Solution {
public:
    
    int result = INT_MAX;
    int n;
    
    void f(int idx, vector<int>& cookies, vector<int>& children, int k) {
        if(idx == cookies.size()) {
            
            int ans = *max_element(begin(children), end(children));
            result = min(result, ans);
            return;
        }
        
        int candy = cookies[idx];
        for(int i = 0; i<k; i++) {
            children[i] += candy;
            
            f(idx+1, cookies, children, k);
            
            children[i] -= candy;
        }
        
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> children(k);
        f(0, cookies, children, k);
        
        return result;
    }
};
//L 2/7 swap position , max request that can be fulfilled
    //2 choice fulfill or not fulfill
class Solution {
public:
    int m;
    int result = INT_MIN;
    
    void f(int idx, int count, int n, vector<int>& resultant, vector<vector<int>>& requests) {
        if(idx == m) {
            
            int allZero = true;
            for(int &x : resultant) {
                if(x != 0) {
                    allZero = false;
                    break;
                }
            }
            
            if(allZero) {
                result = max(result, count);
            }
            return;
        }
        
        
        int from = requests[idx][0];
        int to   = requests[idx][1];
        
        resultant[from]--;
        resultant[to]++;
        f(idx+1, count+1, n, resultant, requests);
        
        resultant[from]++;
        resultant[to]--;
        f(idx+1, count, n, resultant, requests);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        m = requests.size();
        
        vector<int> resultant(n, 0);
        
        f(0, 0, n, resultant, requests);
        
        return result;
    }
};
//G 3/7 max i<j and arr[i]<=arr[j]
    int maxIndexDiff(int arr[], int n) {
        // code here
        int a=0;
        int* l=new int[n];
        int r[n]={0};
        l[0]=arr[0],r[n-1]=arr[n-1];
        for(int i=1;i<n;i++) l[i]=min(arr[i],l[i-1]);
        for(int i=n-2;i>=0;i--) r[i]=max(arr[i],r[i+1]);
        int i=0,j=0;
        while(i<n && j<n){
            if(l[i]<=r[j]){
                a=max(a,j-i);
                j++;
            }
            else i++;
        }
        return a;
    }
//L if strings match after swapping two char in s
    bool buddyStrings(string s, string goal) {
        int s1=s.size(),s2=goal.size();
        if(s1!=s2) return false;
        if(s == goal){
            unordered_set<char> u;
            for(auto x:s){
                if(u.count(x)) return true;
                u.insert(x);
            }
            /*
	//or
            unordered_set<char> u(s.begin(),s.end());
            
            return u.size()!=s1;
            */
            return false;
        }
        
        int fm=-1,sm=-1;//first unmatch
        for(int i=0;i<s1;i++){
            if(s[i]!=goal[i]){
                if(fm<0) fm=i;
                else if(sm<0) sm=i;
                else return false;
            }
        }
        if(sm<0) return false;
        return (s[fm]==goal[sm] && s[sm]==goal[fm]);

    }
    	OR 
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        if(s == goal){
            set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size(); // Swapping same characters
        }

        int i = 0;
        int j = n - 1;

        while(i < j && s[i] == goal[i]){
            i++;
        }

        while(j >= 0 && s[j] == goal[j]){
            j--;
        }

        if(i < j){
            swap(s[i], s[j]);
        }

        return s == goal;
    }
};
//L 4/7 all thrice except one
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> u;
        for(auto x:nums) u[x]++;
        for(auto x:u){
            if(x.second==1) return x.first;
        }
        return -1;
    }
};
//a2 check if bit set count not multiple of 3 then set that bit in ans
    int singleNumber(vector<int>& nums) {
        int s=0,a=0,cb=1;
        for(int i=0;i<32;i++){
            int cb=1<<i;//check bit
            for(auto x:nums){

                s+=(cb&x)?1:0;
            }
            s%=3;
            a|=(s<<i);//set ith bit in ans if not multiple of 3
            s=0;
        }
        return a;
    }
//a3 sort and check for i=1,4,7,... if(a[i]!=a[i-1]) return a[i-1]. edge case start and end
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        sort(nums.begin(),nums.end());
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        for(int i=1;i<n;i+=3){
            if(nums[i]!=nums[i-1]) return nums[i-1];
        }
        return -1;
    }
};
    OR 
    //no base case
for(int i=1;i<n;i+=3){
    if(nums[i]!=nums[i-1]) return nums[i-1];
}
return nums[n-1];
//a4 set bits coming once & twice
    int singleNumber(vector<int>& nums) {
        int ones=0,twos=0;//bits coming once & twice
        for(auto x:nums){
            ones^=(x&~twos);
            twos^=(x&~ones);
        }
        return ones;
    }
//G countSubArrayProductLessThanK
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans=0;
        long long p=1;
        int i=0,j=0;
        while(j<n){
           p*=a[j];
           while(i<=j && p>=k){//or(p>=k)
               p/=a[i];
               i++;
           }
           if(p<k) ans+=j-i+1;//adding subarrays ending at j
           j++;
        }
        return ans;   
    }
//G 5/7 stockBuyAndSell BUY & SELL one after other
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        int p=0;
        int mini=prices[0];
        for(int i=1;i<n;i++){
            mini=min(mini,prices[i]);
            if(prices[i]>mini){
                p+=prices[i]-mini;
                mini=prices[i];
            }
            
        }
        return p;
    }
    //a2
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        int p=0;
        int bd=0,sd=0;
        for(int i=1;i<n;i++){
            if(prices[i]>=prices[sd]) sd=i;
            else{
                p+=prices[sd]-prices[bd];
                sd=bd=i;
            }
        }
        p+=prices[sd]-prices[bd];
        return p;
    }
//L longestSubarray of 1s after deleting 1 element
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int i=0,j=0,n=nums.size(),cz=0;
        while(j<n){
            if(nums[j]==0) cz++;
            while(cz>1) {
                if(nums[i]==0) cz--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans-1;
    }
//G 6/7
quick sort 
//L return the minimal length of a subarray whose sum is greater than or equal to target
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,n=nums.size(),sum=0,ans=INT_MAX;
        while(j<n){
            while(j<n && sum<target){
                sum+=nums[j++];
            }
            while(sum>=target){
                sum-=nums[i++];
            }
            ans=min(ans,j-i+1);
        }
        return ans>n ? 0: ans;
    }
    //a2
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;
        while (r < n) {
            sum += nums[r++];
            while (sum >= s) {
                len = min(len, r - l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
    //a3 binary search
    //PTU PENDING TO UNDERSTAND
    class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), len = INT_MAX;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = n; i >= 0 && sums[i] >= s; i--) {
            int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
            len = min(len, i - j + 1);
        }
        return len == INT_MAX ? 0 : len;
    }
};

//G 7/7 
//merge two sorted array to get smaller in first and bigger in second in sorted form
eg [2,5,6,7] [0,1,8] => [0,1,2,5] [6,7,8]
line 1518 in striver_0623.txt

//L maxConsecutiveAnswers TTT=3
    //a1
class Solution {
public:
    int solve(string answerKey, int k, char ch){
        int c=0,amax=1,i=0,j=0,n=answerKey.size();
        while(j<n){
            while(j<n){
                if(answerKey[j]==ch){
                    if(c<k) c++;
                    else break;
                } 
                
                j++;
            }
            amax=max(amax,j-i);
            if(j==n) break;
            while(c==k){
                if(answerKey[i]==ch){
                    c--;
                }
                i++;
            }
        }
        return amax;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        if(k==n || k==n-1) return n;
        return max(solve(answerKey,k,'T'),solve(answerKey,k,'F'));
        
    }
};
    //a2
class Solution {
public:
    int solve(string answerKey, int k, char ch){
        int c=0,amax=1,i=0,j=0,n=answerKey.size();
        while(j<n){
            if(answerKey[j]==ch) c++;
            while(c>k){
                if(answerKey[i]==ch){
                    c--;
                }
                i++;
            }
            amax=max(amax,j-i+1);
            j++;
        }
        return amax;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        if(k==n || k==n-1) return n;
        return max(solve(answerKey,k,'T'),solve(answerKey,k,'F'));
        
    }
};
//G 8/7
//findTriplets with sum 0
bool findTriplets(int nums[], int n)
    {
        sort(nums,nums+n);
        // int n=nums.size();
        if(n<3) return 0;
        if(nums[0]>0) return 0;//all +ve wont add 3 nums to 0
        // vector<vector<int>> a;
        for(int i=0;i<n-2;i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1,h=n-1,s=-nums[i],cs;
            while(l<h){
                cs=nums[l]+nums[h];
                if(cs==s){
                    return 1;
                }
                else if(cs>s){
                    h--;
                }
                else l++;
            }
        }
        return 0;
    }
//L putMarbles
    //1st and last will be added bcoz 1 st partition starts at 1st & last ends at last
    // a b c d e f and k=2
    // aa bf , ab cf ,ac df , ad ef, ae ff so a. .f
    long long putMarbles(vector<int>& weights, int k) {
        
        long long a=0;
        int n=weights.size();
        if(n==k) return 0;
        vector<int> v;//store consecutive
        for(int i=0;i<n-1;i++){
            v.push_back(weights[i]+weights[i+1]);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<k-1;i++){
            a+=v[n-2-i]-v[i];
        }
        return a;
    }

//L 9/7 largestVariance
class Solution {
public:
    int largestVariance(string s) {
        //char pair 26*26
        int ans = 0;
        unordered_map<char, int> freq;
        for(auto& c:s){
            freq[c]++;
        }
        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                    if(ch1==ch2 || freq[ch1]==0 || freq[ch2]==0)
                        continue;
                    for(int rev=1;rev<=2;rev++){
                    int cnt1 = 0,cnt2 = 0;
                    for(auto& c:s){
                    cnt1 += c==ch1;
                    cnt2 += c==ch2;
                    if(cnt1<cnt2)
                    cnt1 = cnt2 = 0;
                    if(cnt1>0 and cnt2>0)
                        ans = max(ans,cnt1-cnt2);
                    }
                reverse(s.begin(),s.end());
            }
        }
        }
        return ans;
    }
};
//G lowest +ve missingNumber
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        unordered_set <int> us;
        for(int i=0;i<n;i++){
            int x=arr[i];
            us.insert(x);
        }
        for(int i=1;i<=n;i++){
            if(us.count(i)==0) return i;
        }
        return n+1;
    } 
//L 10/7 mindepth of binary tree is count of nodes encountered on shortest path to leaf from root
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        if(root->left==NULL) return 1+minDepth(root->right);
        if(root->right==NULL) return 1+minDepth(root->left);
        return 1+ min(minDepth(root->left),minDepth(root->right));
    }
//G 
    void transpose(vector<vector<int> >& matrix, int n)
    { 
        // code here 
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
//G 11/7 kth element in spiral traversal
//L distanceK nodes from a target
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> um;
    unordered_set<TreeNode*> us;

    void connectParent(TreeNode* root, TreeNode* parent){
        if(root==NULL) return;
        um[root]=parent;
        connectParent(root->left,root);
        connectParent(root->right,root);

    }

    void dfs(TreeNode* target, int k, vector<int>&res){

        if(target==NULL) return;
        if(us.count(target)) return;

        us.insert(target);
        
        if(k==0){
            res.push_back(target->val);
            return;
        }
        dfs(target->left,k-1,res);
        dfs(target->right,k-1,res);
        dfs(um[target],k-1,res);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL) return {};
        vector<int> res;
        connectParent(root,NULL);
        dfs(target,k,res);
        return res;
    }
};
//G 12/7 N raise to its reverse. 12^21
    # define mod 1000000007
    long long power(int N,int R)
    {
       //Your code here
       if(R==0) return 1;
       long long half=power(N,R/2);
       half=(half*half)%mod;
       if(R&1) half=(half * N )%mod;
       return half;
        
    }
//L safe nodes in graph
//G 13/7 UNIQUE FREQ
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int,int> um;//num vs freq
        for(int i=0;i<n;i++) um[arr[i]]++;
        unordered_set<int> us;
        for(auto x:um){
            if(us.count(x.second)) return 0;
            us.insert(x.second);
        }
        return 1;
    }
//L canFinish all tasks with dependency. topo sort
class Solution {
public:
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int> > gr(numCourses);//topo
    vector<int> indegrees(numCourses, 0);
    for (const auto& prerequisite : prerequisites) {
        int course = prerequisite[0];
        int pre_course = prerequisite[1];
        gr[pre_course].push_back(course);
        indegrees[course]++;
    }   
    queue<int> q;
    for (int course = 0; course < numCourses; course++) {
        if (indegrees[course] == 0) {
        q.push(course);
        }
    }
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        for (int next_course : gr[course]) {
            indegrees[next_course]--;
            if (indegrees[next_course] == 0) {
            q.push(next_course);
            }
        }
    }
    for (int indegree : indegrees) {
        if (indegree != 0) {
        return false;
        }
    }
    return true;
    }
};
//G 14/7 implement 2 stacks using an array
//L subsequence without changing order, delete some or no elements
    int longestSubsequence(vector<int>& arr, int difference) {
        int ml=1;
        unordered_map<int,int> um;
        for(auto x: arr){
            ml=max(ml,um[x]=um[x- difference]+1);
        }
        return ml;
    }
//G 15/7
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        //delete n/2 elements
        stack<int> s2;
        int n=sizeOfStack/2;
        for(int i=0;i<n;i++){
            // int rem=s.top();
            
            s2.push(s.top());
            s.pop();
        }
        //pop
        s.pop();
        //push back
        for(int i=0;i<n;i++){
            // int rem=s2.top();
            
            s.push(s2.top());
            s2.pop();
        }
    }
    //a2
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
       if(s.size()==(sizeOfStack+1)/2)
       {  
           s.pop();
           return;
       }
       int ele=s.top();
       s.pop();
       deleteMid(s,sizeOfStack);
       s.push(ele);
    }
//L best events
// G 16/7 reverse queue
class Solution
{
    public:
    
    void f(queue<int> &q){
        if(q.empty()) return;
        int ele=q.front();
        q.pop();
        f(q);
        q.push(ele);
    }
    
    queue<int> rev(queue<int> q)
    {
        
        f(q);
        return q;
    }
};
//L make team with all skills and least ppl
//G 17/7 FirstNonRepeating till now aabc -> a#bb
        string FirstNonRepeating(string A){
            // Code here
            unordered_map<char,int> um;//char vs freq
            queue<char> q;//possible ans;
            
            string ans="";
            for(auto x:A){
                um[x]++;
                if(um[x]==1) q.push(x);
                
              //  char ansfornow='#';
              //  while(q.size()){
              //      char fr=q.front();
              //      if(um[fr]==1){
              //          ansfornow=fr;
              //          break;
              //      }
              //      else q.pop();
              //  }
              //  ans+=ansfornow;
              
              while(q.size() && um[q.front()]>1) q.pop();
              ans+= (q.empty() ? '#' : q.front());
            }
            return ans;
        }
//L add two numbers given as ll 12 + 999 = 1011
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        while(l1) s1.push(l1->val),l1=l1->next;
        while(l2) s2.push(l2->val),l2=l2->next;

        int c=0;
        ListNode* res=NULL;
        int sum;
        while(c || (!s1.empty()) || (!s2.empty()) ){
            sum=c;
            if(!s1.empty()) sum+=s1.top(),s1.pop();
            if(!s2.empty()) sum+=s2.top(),s2.pop();

            int dig=sum%10;
            c=sum/10;

            ListNode* newD= new ListNode(dig);

            newD->next=res;
            res=newD;
        }
        return res;
    }
};

//G 18/7 longest repeating subsequence
//L LRU cache

//G 19/7 longestPalinSubseq
    int longestPalinSubseq(string A) 
    {
        int n=A.size();
        string B = A;
        reverse(B.begin(),B.end());
        vector<vector<int> >soldp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(A[i-1]==B[j-1]) soldp[i][j]=1+soldp[i-1][j-1];
                else soldp[i][j]=max(soldp[i-1][j],soldp[i][j-1]);
            }
        }
        return soldp[n][n];
    }
//L eraseOverlapIntervals
    //minimum erase to make non overlapping
class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int ans=-1;
        sort(intervals.begin(),intervals.end(),comp);
        vector<int> pre=intervals[0];
        for(auto x:intervals){  //x is vector interval
            if(x[0]<pre[1]){
                ans++;
            }
            else pre=x;
        }
        return ans;
    }
};

//L 20/7 asteroidCollision
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<bool> vis(n,true);//TRUE means survived
        stack<int> st;//stack of positive index

        for(int i=0;i<n;i++){
            if(asteroids[i]>0) st.push(i);
            else{
                while(!st.empty()){
                    if(-1*asteroids[i]> asteroids[ st.top()] ){
                        vis[st.top()]=false;
                        st.pop();
                    }
                    else if(-1*asteroids[i] < asteroids[ st.top()]){
                        vis[i]=false;
                        break;
                    }
                    else{
                        vis[st.top()]=false;
                        st.pop();
                        vis[i]=false;
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]) ans.push_back(asteroids[i]);
        }
        return ans;
    }
};
//a2
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            if(ast[i] > 0 || s.empty()) {
                s.push(ast[i]);
            }
            else {
                while(!s.empty() and s.top() > 0 and s.top() < abs(ast[i])) {
                    s.pop();
                }
                if(!s.empty() and s.top() == abs(ast[i])) {
                    s.pop();
                }
                else {
                    if(s.empty() || s.top() < 0) {
                        s.push(ast[i]);
                    }
                }
            }
        }
        // finally we are returning the elements which remains in the stack.
        // we have to return them in reverse order.
        vector<int> res(s.size());
        for(int i = (int)s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};

//G first nonrepeatingCharacter
    char nonrepeatingCharacter(string S)
    {
        //Your code here
        unordered_map<char,int> um;
        for(auto x:S) um[x]++;
        for(auto x:S){
            if(um[x]==1) return x;
        }
        return '$';
    }

//G 21/7 reverse k nodes
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head == NULL || head->next==NULL) return head;

        int c=0;
        struct node *temp=head,*prev=NULL,*front=NULL;
        while(temp && c++<k){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        if(temp){
            struct node* newH=reverse(temp,k);
            head->next=newH;
        }
        return prev;
    }
//L findNumberOfLIS
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),cnt(n,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                }
                else if(nums[i]>nums[j] && dp[j]+1==dp[i]){
                    cnt[i]+=cnt[j];
                }
            }
        }
        int maxi=*max_element(dp.begin(), dp.end());
        int c=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) c+=cnt[i];
        }
        return c;
    }
//22/7 g removeDuplicates in unsorted linked list
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
        if(head->next == NULL ) return head;
        unordered_set<int> us;
        Node* temp=head;
        Node* prev=NULL;
        while(temp){
            if(us.count(temp->data)){
                Node* front=temp->next;
                free(temp);
                temp=front;
                if(prev){
                    prev->next=temp;
                    
                }
                else{
                    
                    head=front;
                }
            }else{
                us.insert(temp->data);
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
//a2
Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_map <int,int> m;
     Node* temp = head;
     m[temp->data]++;
     while(temp->next)
    {
       if(m[temp->next->data]++) 
       temp->next = temp->next->next;  //used for forgetting the middle value;
       else 
       temp = temp->next;
    }
     return head;
    }

//L
class Solution {
public:
    unordered_map<string,double> mp;
    int dir[8][8] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    double knightProbability(int n, int k, int row, int column) {
        return find(n,k,row,column);
    }
    double find(int n, int moves, int r, int c) {
        if(r<0 || r>=n || c<0 || c>=n)
        return 0;
        if(moves == 0)
        return 1;
        string key = to_string(r) + "k" + to_string(c) + "v" + to_string(moves);
        if(mp.find(key) != mp.end())
        return mp[key];
        double probability = 0;
        for(int i=0; i<8; i++)
        probability += find(n,moves-1, r+dir[i][0], c+dir[i][1])/8.0 ;
        mp[key] = probability;
        return mp[key];
    }
};

//G 23/7 sort linked list with 0,1,2
    Node* segregate(Node *head) {
        
        // Add code here
        Node* zh=new Node(-1),*oh=new Node(-1),*th=new Node(-1);
        Node *zt=zh,*ot=oh,*tt=th;

        Node* curr=head;
        while(curr){
            if(curr->data==0){
                zt->next=curr;
                zt=curr;
            }else if(curr->data==1){
                ot->next=curr;
                ot=curr;
            }
            else{
                tt->next=curr;
                tt=curr;
            }
            curr=curr->next;
        }
        zt->next= (oh->next) ? (oh->next) : (th->next);
        ot->next= th->next;
        tt->next=NULL;
        return zh->next;
    }
//L 
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
class Solution {
public:
    // global map
    unordered_map<int, vector<TreeNode *>> dpmemo;
    
    // recursion is very lengthy: dp memorization can help a little bit
    vector<TreeNode *> allPossibleFBT(int n) {
        // vector that stores ans
        vector<TreeNode *> ans;
        // base case
        if (n < 1 || n % 2 == 0) {
            // if n is less than 1 or a multiple of 2: cannot have a FULL binary tree
            return ans;
        }
        if (dpmemo.find(n) != dpmemo.end()) {
            // dpmemo map has something
            return dpmemo[n];
        }
        if (n == 1) {
            // if n is eql to 1 simply return
            ans.push_back(new TreeNode(0));
            dpmemo[1] = ans;
            return ans;
        }


        // main part: including the recursive part
        // get all the possible number of node combinations possible on the left and right sub tree
        for (int i = 1; i < n; i += 2) {
            // incremented i by 2 because if we increment it by 1 : it'll automatically get rejected by the base condition
            // make 2 vectors that store the number of nodes in left and right sub tree specifically
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right = allPossibleFBT(n - 1 - i);

            // make trees from all possible combinations of left and right subtrees
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode *root = new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        dpmemo[n] = ans;  // dp memorize the ans for this integer
        return ans;
    }
};
//L 24/7
    double myPow(double x, int n) {
        double r = 1;
        while (n) {
            if (n % 2) r = n > 0 ? r * x : r / x;
            x = x * x;
            n /= 2;
        }
        return r;
    }
//G
    vector<int> rightView(Node *root)
    {
       // Your Code here
        vector<int> a;
        if(!root) return a;
        queue<Node*> q;
        q.push(root);

        while(q.size()){
            // vector<int> helper;
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* ele=q.front();
                q.pop();
                if(ele->left) q.push(ele->left);
                if(ele->right) q.push(ele->right);
                if(i==n-1) a.push_back(ele->data);//last child is rightmost in any level
            }
        }

        return a;
    }
//G 25/7 right to left on odd level & L->R on even
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> a;
    if(!root) return a;
    queue<Node*> q;
    q.push(root);
    vector<int> temp;
    int level=1;

    while(q.size()){

        int n=q.size();
        for(int i=0;i<n;i++){
            Node* first=q.front();
            q.pop();
            temp.push_back(first->data);

            if(first->left) q.push(first->left);
            if(first->right) q.push(first->right);
        }

        if(level){
            for(int i=n-1;i>=0;i--){
                a.push_back(temp[i]);
            }
        }
        else{
            for(int i=0;i<n;i++){
                a.push_back(temp[i]);
            }
        }
        level=1-level;
        temp.clear();

    }

    return a;
}
//L only 1 peak
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=0, j=arr.size()-1;
        while(i<j)
        {
            int mid=(i+j)/2;
            if(arr[mid]<arr[mid+1]) i=mid+1;
            else                    j=mid;
        }
        return j;
    }
//G 26/7 kthAncestor
void f(Node* child,Node* parent,unordered_map<Node*,Node*> &um,Node* &ptr,int val){
    if(child->data == val) ptr=child;
    um[child]=parent;
    if(child->left) f(child->left,child,um,ptr,val);
    if(child->right) f(child->right,child,um,ptr,val);
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    unordered_map<Node*,Node*> um;
    Node* ptr=NULL;
    f(root,NULL,um,ptr,node);
    // for(auto x:um){
    //     cout<<x.first->data<<" "<<x.second? x.second->data:"NULL"<<endl;
    // }
    
    // cout<<ptr->data<<endl;
    
    while(um[ptr] &&  k ){
        k--;
        ptr=um[ptr];
    }
    // cout<<k<<endl;
    if(k==0) return ptr->data;

    return -1;

}
//a2
/*
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
bool findAncestors(Node* root, int target, vector<int>& ancestors) {
    if (root == nullptr)
        return false;

    if (root->data == target)
        return true;

    if (findAncestors(root->left, target, ancestors) || findAncestors(root->right, target, ancestors)) {
        ancestors.push_back(root->data);
        return true;
    }

    return false;
}
int kthAncestor(Node *root, int k, int node)
{
    vector<int> ancestors;

    // Find the ancestors of the target node
    if (!findAncestors(root, node, ancestors))
        return -1; // Target node not found

    // Check if k is within the range of ancestors
    int n = ancestors.size();
    if (k > n)
        return -1; // kth ancestor does not exist

    // Return the kth ancestor
    return ancestors[k - 1];
}
//a3
int ans=-1;
int fun(Node *root, int k ,int node)
{
    if(root==NULL)
    return -1;
    
    if(root->data==node)
    return 0;
    
    int l=fun(root->left,k,node);
    int r=fun(root->right,k,node);
    
    if(l==-1 && r==-1)
    return -1;
    else if(l!=-1)
    {
        if(l+1==k)
        {
            ans=root->data;
            return k;
        }
        else
        return l+1;
    }
    else if(r!=-1)
    {
        if(r+1==k)
        {
            ans=root->data;
            return k;
        }
        else
        return r+1;
    }
}
int kthAncestor(Node *root, int k, int node)
{
     fun(root,k,node);
     int temp=ans;
     ans=-1 ;
     return temp;
}
//L minSpeedOnTime
class Solution {
public:

    bool f(vector<int>& dist, double hour,int s){
        double time=0.0;
        int n=dist.size();
        for(int i=0;i<n-1;i++){
            time+=(dist[i]+s-1)/s;
        }
        time+=(1.0 * dist[n-1])/s;
        return time<=hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        if(hour<= (1.0 * (n-1) ) ) return -1;

        int l=1,r=1e7+1,mid=-1;
        while(l<r){
            mid=l+(r-l)/2;
            if( f(dist,hour,mid) ){
                r=mid;
            }
            else l=mid+1;
        }
        return r;
    }
};
//L 27/7 maxRunTime simultaneously
class Solution {
public:
    bool possible(int n, vector<int>& batteries,long long m){
        long long time=0;
        for(auto x:batteries){
            if(x>m) time+=m;
            else time+=x;
        }
        return time/n>=m;//or time>=m*n;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long l=0,r=1e14,m,ans;
            //or r = sum /n
        while(l<=r){
            m=l+(r-l)/2;
            if(possible(n,batteries,m)){
                ans=m;
                l=m+1;
            }
            else r=m-1;
        }
        return ans;
    }
};
//G heapSort
    //left child of idx i = 2*i+1,right=2*i+2
    //parent of idx i= (i-1)/2
class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int cur = arr[i];
        int par = arr[(i - 1) / 2];
        
        while(i > 0 and par < cur){
            swap(arr[(i - 1) / 2], arr[i]);
            i = (i - 1) / 2;
            
            cur = arr[i];
            if(i > 0)
                par = arr[(i - 1) / 2];
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i = 1; i < n; i++){
            heapify(arr, n, i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        
        int last = n;
        
        while(last > 0){
            swap(arr[0], arr[--last]);
            
            int ind = 0;
            int cur = arr[ind];
            int c1, c2;
            c1 = c2 = -1;
            
            if(ind * 2 + 1 < last)    
                c1 = arr[ind * 2 + 1];
            if(ind * 2 + 2 < last)
                c2 = arr[ind * 2 + 2];
                
            while(c1 > cur or c2 > cur){
                if(c1 > cur and c1 > c2){
                    swap(arr[ind * 2 + 1], arr[ind]);
                    ind = ind * 2 + 1;
                }
                else if(c2 > cur){
                    swap(arr[ind * 2 + 2], arr[ind]);
                    ind = ind * 2 + 2;
                }
                
                c1 = c2 = -1;
                
                if(ind * 2 + 1 < last)    
                    c1 = arr[ind * 2 + 1];
                if(ind * 2 + 2 < last)
                    c2 = arr[ind * 2 + 2];
            }
        }
    }
};

//L 28/7 PredictTheWinner

//Recursion + Memo - I
//Approach-1 (Using same as Optimal Code Strategy)
class Solution {
public:
    int n;
    int t[23][23];
    int solve(vector<int>& nums, int l, int r) {
        
        if(l > r)
            return 0;
        
        if(l == r)
            return nums[l];
        
        if(t[l][r] != -1)
            return t[l][r];
        
        int take_left  = nums[l] + min(solve(nums, l+2, r), solve(nums, l+1, r-1));
        
        int take_right = nums[r] + min(solve(nums, l, r-2), solve(nums, l+1, r-1));
        
        
        return t[l][r] = max(take_left, take_right);
        
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        memset(t, -1, sizeof(t));
        
        n = nums.size();
        
        
        int total = accumulate(begin(nums), end(nums), 0);
        
        int player1 = solve(nums, 0, n-1);
        int player2 = total - player1;
        
        return player1 >= player2;
    }
};


//Recursion + Memo - II
//Approach-2 (Using diff of score between players)
class Solution {
public:
    int n;
    int t[23][23];
    
    //Player1 - Player2
    int maxDiff(vector<int>& nums, int l, int r) {
        
        if(l == r)
            return nums[l];
        
        if(t[l][r] != -1)
            return t[l][r];
        
        int take_left  = nums[l] - maxDiff(nums, l+1, r);
        int take_right = nums[r] - maxDiff(nums, l, r-1);
        
        return t[l][r] = max(take_left, take_right);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return maxDiff(nums, 0, n-1) >= 0;
            
    }
};

//G lowest comman ancestor
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            if(!root) return NULL;
            if(root->data==n1 || root->data==n2) return root;

            Node* leftlca=LCA(root->left,n1,n2);
            Node* rightlca=LCA(root->right,n1,n2);

            if(!leftlca) return rightlca;
            if(!rightlca) return leftlca;

            return root;
        }

};
//G 29/7 findMedian in BST
void f(Node *root, vector<int> &v){ //inorder in BST gives sorted values
    if(!root) return;
    
    f(root->left,v);
    v.push_back(root->data);
    f(root->right,v);
}

float findMedian(struct Node *root)
{
      //Code here
    vector<int> v;
    f(root,v);
    int n=v.size();
    if(n&1){
        return v[n/2];
    }
    return (v[n/2]+v[n/2-1])/2.0;
}
//L soupServings
    //4 4a,0b 3a,1b 2a,2b 1a,3b
class Solution {
public:

unordered_map<int, unordered_map<int, double>> dp;
    double prob(int i, int j){
        if (i <= 0 && j <= 0) return 0.5;
        if (i <= 0) return 1;
        if (j <= 0) return 0;
        if (dp[i].count(j)) return dp[i][j];
        return dp[i][j] = (prob(i - 4, j) + prob(i - 3, j - 1) +
        prob(i - 2, j - 2) + prob(i - 1, j - 3)) /
        4;

    }
    double soupServings(int n) {
        int m = ceil(n / 25.0);
        for (int k = 1; k <= m; k++) {
            if (prob(k, k) > 1 - 1e-5) {
            return 1;
        }
    }
    return prob(m, m);
    }
};
//G 30/7 inOrderSuccessor
//a1
void f(Node *root, Node *x,Node * &ans,int &fe,int &fa){
        if(!root) return;
        if(fa) return;
        f(root->left,x,ans,fe,fa);
        if(fe){
            ans=root;
            fa=1;
            fe=0;
        }
        if(root==x) fe=1;
        f(root->right,x,ans,fe,fa);
    }
    
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node *ans=NULL;
        int fe=0,fa=0;
        f(root,x,ans,fe,fa);  //foundelement foundans
        return ans;
    }
//a2
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* succ;
        while(root)
        {
            if(x->data >= root->data)   //smaller or equal cannot be successor, so go right and increase the val
                root = root->right;
            else{   //if we get val>x then it is successor , so store and look in left for earlier
                succ = root;
                root = root->left;
            }
        }
        return succ;
    }
//L
class Solution {
    public:
    int solve(int i, int j, const string& s, vector<vector<int>>& pd) {
        if (i == j) return 1;
        if (pd[i][j] != -1) return pd[i][j];
        int minTurns = INT_MAX;
        for (int k = i; k < j; k++) {
        minTurns = min(minTurns, solve(i, k, s, pd) + solve(k + 1, j, s, pd));
        }
        return pd[i][j] = (s[i] == s[j]) ? minTurns - 1 : minTurns;
    }
    int strangePrinter(std::string s) {
        int n = s.length();
        vector<vector<int>> pd(n, vector<int>(n, -1));
        return solve(0, n - 1, s, pd);

    }
};
//31/7 G bfsOfGraph -> radially equal distance, dfs depth first
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> canvis(V,1);
        vector<int> ans;
        queue<int> q;

        q.push_back(0);
        canvis[0]=0;

        while(q.size()){    //or (!q.empty())
            int x=q.front();
            ans.push_back(x);
            q.pop();

            //for(int i=0;i<adj[x].size();i++){
            for(auto it:adj[x]){
                if(canvis[it]){
                    q.push(it);
                    canvis[it]=0;
                }
            }
        }
        return ans;
    }
//L delete char and make strings equal is least possible deletions 
        //also lower to delete if you have a choice 
        //delete a better than b
class Solution {
public:
    int n1,n2;
    int dp[1001][1001];
    int f(string &s1, string &s2,int i1,int i2){
        if(i1==n1 && i2==n2) return 0;

        if(dp[i1][i2]!=-1) return dp[i1][i2];

        if(i1==n1){
            return dp[i1][i2] = s2[i2]+f(s1,s2,i1,i2+1);
        }
        if(i2==n2){
            return dp[i1][i2] = s1[i1]+f(s1,s2,i1+1,i2);
        }
        if(s1[i1]==s2[i2]){
            return dp[i1][i2] = f(s1,s2,i1+1,i2+1);
        }

        return dp[i1][i2] = min(s1[i1]+f(s1,s2,i1+1,i2),s2[i2]+f(s1,s2,i1,i2+1));
    }

    int minimumDeleteSum(string s1, string s2) {
        n1=s1.size(),n2=s2.size();
        memset(dp,-1,sizeof(dp));
        return f(s1,s2,0,0);
    }
};
//L 1/8 combination 
    //n=4,k=2 => 12 13 14 23 24 34
class Solution {
public:

    void f(int n,int k,int i,vector<int> &temp,vector<vector<int>> &ans,int c){ //&temp to save time else every time new copy will be created
        // if(c>k){
        //  return;
        // }
        if(c==k){   //c or temp.size()
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<=n;j++){
            temp.push_back(j);//mistake i
            f(n,k,j+1,temp,ans,c+1);//mistake i
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        f(n,k,1,temp,ans,0);
        return ans;
    }
};
//G dfsOfGraph
    void f(int V, vector<int> adj[],vector<int> &canvis,vector<int> &ans,int cv){  //cv current vertex
    // no &adj 
        // if(ans.size()==V) return;

        ans.push_back(cv);
        canvis[cv]=0;

        for(auto x:adj[cv]){
            if(canvis[x]){
                f(V,adj,canvis,ans,x);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> canvis (V,1);
        f(V,adj,canvis,ans,0);
        return ans;
    }
//L 2/8 permute
    //a1 swapping
class Solution {
public:

    void f(vector<vector<int>> &ans,vector<int>& nums,int i,int n){
        if(i==n){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<n;j++){
            swap(nums[j],nums[i]);
            f(ans,nums,i+1,n);
            swap(nums[j],nums[i]);
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        f(ans,nums,0,n);
        return ans;
    }
};
    //a2 selecting
class Solution {
public:
    vector<vector<int>> ans;

    void f (vector<int>& nums,int n,vector<int> &temp,vector<int> &cantake,int i){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<n;j++){
            if(cantake[j]){
                temp.push_back(nums[j]);
                cantake[j]=0;
                f(nums,n,temp,cantake,i+1);
                cantake[j]=1;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> cantake(n,1);
        vector<int> temp;
        f(nums,n,temp,cantake,0);
        return ans;
    }
};
//related permutation2 with repeating elements
class Solution {

public:
    vector<vector<int>> ans;
    unordered_map<int,int> um;
    int n;

    void f(vector<int> &nums,int idx,vector<int> &temp){  
        if(idx==n){
            ans.push_back(temp);
            return;
        }

        for(auto x:um){
            if(x.second>0){
                temp.push_back(x.first);
                um[x.first]--;
                f(nums,idx+1,temp);
                um[x.first]++;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(auto x:nums) um[x]++;
        n=nums.size();
        vector<int> temp;
        f(nums,0,temp);
        return ans;
    }
};
//a2
class Solution {
public:

    void f(vector<vector<int>> &ans,vector<int>& nums,int i,int n){
        if(i==n){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> us;//ex
        for(int j=i;j<n;j++){
            if(us.count(nums[j])) continue;//ex
            us.insert(nums[j]);//ex
            swap(nums[j],nums[i]);
            f(ans,nums,i+1,n);
            swap(nums[j],nums[i]);
            
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        f(ans,nums,0,n);
        return ans;
    }
};
//G shortestDistance from 00 to XY 
//a1 dfs TLE
//a2 bfs 
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0 || A[X][Y]==0) return -1;

        int steps=0;
        queue<pair<int,int> > q;
        q.push({0,0});
        A[0][0]=0;

        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};

        while(q.size()){
            int n=q.size();
            while(n--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();

                if(i==X && j==Y) return steps;

                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];

                    if(ni<0 || ni>=N || nj<0 || nj>=M || A[ni][nj]==0) continue;

                    q.push({ni,nj});
                    A[ni][nj]=0;
                }
            }
            steps++;
        }

        return -1;
    }
//L 3/8 letterCombinations of phone number
class Solution {
public:
    vector<string> ans;
    vector<string> str={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void f(string digits,int idx,string temp,int n){
        if(idx==n){
            ans.push_back(temp);
            return;
        }

        string cur= str[digits[idx]-'2'];
        for(int i=0;i<cur.size();i++){
            f(digits,idx+1,temp+cur[i],n);
        }
    }

    vector<string> letterCombinations(string digits) {
        string temp;
        int n=digits.size();
        if(n==0) return ans;
        f(digits,0,temp,n);
        return ans;
    }
};
//G shortestPath in directed acyclic graph
class Solution {
  private:
    void dfs(int node, vector < pair < int, int >> adj[],int vis[], stack < int > & st) {
      vis[node] = 1;
      for (auto it: adj[node]) {
        int v = it.first;
        if (!vis[v]) {
          dfs(v, adj, vis, st);
        }
      }
      st.push(node);
    }
  public:
    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {

      vector < pair < int, int >> adj[N];
      for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt}); 
      }
    // toposort
      int vis[N] = {0};
      stack < int > st;
      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
      }
     // distance calculation
      vector < int > dist(N);
      for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
      }

      dist[0] = 0;
      while (!st.empty()) {
        int node = st.top();
        st.pop();

        for (auto it: adj[node]) {
          int v = it.first;
          int wt = it.second;

          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
      }

      for (int i = 0; i < N; i++)     if (dist[i] == 1e9) dist[i] = -1;
        
      
      return dist;
    }
};
//G 4/8 Reverse stack using recursion
    void insertAtBottom(stack<int> &St,int val){
        if(St.empty()){
            St.push(val);
            return;
        }
        int topele=St.top();
        St.pop();
        insertAtBottom(St,val);
        St.push(topele);
    }
    void Reverse(stack<int> &St){
        if(St.empty()) return;// or St.size()==1 return

        int topval=St.top();
        St.pop();
        Reverse(St);

        insertAtBottom(St,topval);

    }
//a2 use 2 extra stacks
//a3 use 1 extra queue

//L wordBreak 
    //a1 recursion tle
    //a2 recursion + memorisation(dp)
class Solution {
public:
    unordered_set<string> st;
    int t[301];
    int n;
    
    bool solve(string &s, int idx) {
        
        if(idx == n) {
            return true;
        }
        
        if(t[idx] != -1)
            return t[idx];
        
        for(int l = 1; idx+ l<=n; l++) {
            
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solve(s, idx+l))
                return t[idx] = true;
            
        }
        
        return t[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        
        memset(t, -1, sizeof(t));
        
        for(string &word : wordDict) {
            st.insert(word);
        }
        
        return solve(s, 0);
    }
};
//G 5/8 findMinDiff where each of M student can take 1 packet from n packets
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        long long ans= LLONG_MAX;

        sort(a.begin(), a.end());
        for(int i=m-1;i<n;i++){
            long long cur=a[i]-a[i-m-1];
            ans=min(ans,cur);
        }

        return ans;
    }  
//L
        //no of binary search tree with n nodes = 2nCn / (n+1);
        //eg for 3 nodes 6C3/4= 5
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
class Solution {
public:
    vector<TreeNode*> helper(int l, int r) {
        if(l > r || l < 1) {
            vector<TreeNode*> v;
            v.push_back(NULL);
            return v;
        }
        if(l==r) {
            
            vector<TreeNode*> v;
            TreeNode* temp = new TreeNode;
            temp->val = l;
            temp->left = NULL;
            temp->right = NULL;
            v.push_back(temp);
            return v;
        }
        vector<TreeNode*>ans;
        for(int i = l; i <= r; i++) {
            
            vector<TreeNode*> lt = helper(l,i-1);
            vector<TreeNode*> rt = helper(i+1,r);
            for(int k = 0; k < lt.size(); k++) {
                for(int j = 0; j < rt.size(); j++) {
                    TreeNode* temp = new TreeNode;
                    temp->val = i;
                    temp->left = lt[k];
                    temp->right = rt[j];
                    ans.push_back(temp);
                }
            }
            
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};

//G 6/8 permutation
    void f(string &S,int idx,vector<string> &v){
        if(idx==S.size()){
            v.push_back(S);
            return;
        }

        for(int i=idx;i<S.size();i++){
            swap(S[i],S[idx]);
            f(S,idx+1,v);
            swap(S[i],S[idx]);
        }
    }

    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> v;
        f(S,0,v);
        sort(v.begin(),v.end());
        return v;
    }
//L numMusicPlaylists pending
class Solution {
public:
    int N;
    int GOAL;
    int K;
    long t[101][101];
    const int MOD = 1e9+7;
    
    long helper(int count_song, int count_unique) {
        if(count_song == GOAL) {
            if(count_unique == N)
                return 1;
            
            return 0;
        }
        
        if(t[count_song][count_unique] != -1)
            return t[count_song][count_unique];
        
        long result = 0;
        
        //Option-1 (Play a unique song)
        if(count_unique < N)
            result += (N-count_unique) * helper(count_song+1, count_unique+1);
        
        //Option-2 (Replay a song)
        if(count_unique > K)
            result += (count_unique - K) * helper(count_song+1, count_unique);
        
        
        return t[count_song][count_unique] = result % MOD;

    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        N    = n;
        GOAL = goal;
        K    = k;
        memset(t, -1, sizeof(t));
        return helper(0, 0); 
    }
};
//L 7/8 
//a1 start from top right
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(),c=matrix[0].size();
        int sr=0,sc=c-1;//top right
        while(sr<r && sc>=0){
            if(matrix[sr][sc]==target) return 1;
            else if(matrix[sr][sc]>target) sc--;
            else sr++;
        }
        return 0;
    }
//a2 binary search faster
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(),c=matrix[0].size();
        int s=0,e=r*c-1;
        while(s<=e)       
        {
            int mid=(s+e)/2;
            //int row=mid/c,col=mid%c;
            int element=matrix[mid/c][mid%c];
            if(target==element) return 1;
            else if(target>element) s=mid+1;
            else e=mid-1;
        }
        return 0;
    }
};
//G SolveSudoku
    bool safe(int num,int (grid)[N][N],int r,int c){    //no need of &grid if int grid[][]
        //  int &grid[][] => error
        //  int grid[][] => correct
        for(int i=0;i<9;i++){
            if(grid[i][c]==num) return 0;
            if(grid[r][i]==num) return 0;

            if(grid[ (r/3*3 + i/3)  ][ (c/3*3 + i%3)  ] == num) return 0;
        }
        return 1;
    }

    bool solve(int (grid)[N][N],int r,int c){
        if(r==9) return 1;
        if(c==9) return solve(grid,r+1,0);

        if(grid[r][c]!=0) return solve(grid,r,c+1);

        for(int num=1;num<=9;num++){
            if(safe(num,grid,r,c)){
                grid[r][c]=num;
                if( solve(grid,r,c+1) ) return 1;
                grid[r][c]=0;
            }
        }
        return 0;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return solve(grid,0,0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
//L 9/8 search in rotated sorted array
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,m;

        while(l<=r){
            m=l+(r-l)/2;
            if(nums[m]==target) return m;
            else if(nums[m]>=nums[l]){
                //left sorted
                if(target>=nums[l] && target<nums[m]) r=m-1;
                else l=m+1;
            }else {
                //right sorted
                if(target>nums[m] && target<=nums[r]) l=m+1;
                else r=m-1;
            }
        }
        return -1;
    }
//a2
int search(vector<int>& nums, int target) {
    int lo = 0, hi = int(nums.size()) - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo == hi && nums[lo] == target ? lo : -1;
}
//G countFractions which sum 1
    int countFractions(int n, int numerator[], int denominator[])
    {
        map< pair<int,int>,int > mp;
        int ans=0;
        for(int i=0;i<n;i++){
            int hcf=__gcd(numerator[i],denominator[i]);

            int x=numerator[i]/hcf,y=denominator[i]/hcf;

            ans+=mp[{y-x,y}];// x/y + (y-x)/y = 1
            mp[{x,y}]++;
        }
        return ans;

    }
//G 9/8 largestPrimeFactor
    long long int largestPrimeFactor(int N){
        // code here
        int ans=N;
        int og=N;
        
        for(int i=2;N>1 && i*i<=og;i++){
            while(N%i==0){
                N/=i;
                ans=i;
                // cout<<i<< " "<<ans<<endl;
            }
        }
        
        return N>1? N:ans;
    }
//a2
    long long int largestPrimeFactor(int N){
        // code here
        int ans=N;
        int og=N;
        
        for(int i=2;N>1 && i*i<=N;i++){
            if(N%i){
                
            }
            else{
                while(N%i==0){
                    N/=i;
                    ans=i;
                    // cout<<i<< " "<<ans<<endl;
                }
                i=1;
            }
            
        }
        
        return N>1? N:ans;
    }
//a3
        int ans=0;
        for(int i=2;N>1 && i*i<=N;i++){
            if(N%i==0){
                ans=i;
                while(N%i==0) N/=i;
            }
            
        }
        
        return N>1? N:ans;
//L minimize Max diff between p pairs selected from an array
class Solution {
public:

    bool pairs(vector<int>& nums, int p, int m){
        int c=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]- nums[i-1]<=m){
                c++;
                i++;
            }
        }
        return c>=p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        if(p==0) return 0;
        int n=nums.size();
        sort(nums.begin(), nums.end());

        int l=0,r=nums[n-1]-nums[0],m;
        int a=r;

        while(l<=r){
            m=l+(r-l)/2;
            //p pairs with diff<=m 
            if(pairs(nums,p,m)){
                cout<<m<<endl;
                a=m;
                r=m-1;
            }else l=m+1;
        }
        return a;
    }
    
};

//G 10/8
class Solution
{
    public:
    
    vector<vector<int>> v;
    //error using member initialization in the class definition. 
    
    Solution() {
        v.resize(1001, vector<int>(1001, -1));//or write this in lcs 
        //v.assign(1001, vector<int>(1001, -1));//will also work

        //Instead, you should initialize the member variables in the constructor of the class.
    }
    
    int f(int i1,int i2,int n, int m, string &s1, string &s2){
        if(i1==n || i2==m) return 0;
        
        if(v[i1][i2]!=-1) return v[i1][i2];
        
        if(s1[i1] == s2[i2]) {
            return v[i1][i2] = f(i1+1,i2+1,n,m,s1,s2) + 1;
        }
        
        return v[i1][i2] = max(f(i1,i2+1,n,m,s1,s2),f(i1+1,i2,n,m,s1,s2)) ;
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        // vector<vector<int>> v(n,vector<int> (m,0));
        return f(0,0,n,m,s1,s2);
    }
};
//a2
class Solution
{
    public:
    
    int v[1001][1001];
    
    int lcs(int n, int m, string s1, string s2)
    {
        
        memset(v,-1,sizeof(v));
        return f(0,0,n,m,s1,s2);
    }
};
//a3
int lcs(int n, int m, string s1, string s2)
    {
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
        for(int i=0;i<=m;i++)
            dp[0][i] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        /*int i=n,j=m;  //To get the LCS string
        string res="";
        while(i!=0 || j!=0)
        {
            if(s1[i-1]==s2[j-1])
            {
                res+=s1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1])
                {
                    i--;
                }
                else
                    j--;
            }
        }
        reverse(res.begin(),res.end());
        cout<< res <<endl;*/
        
        return dp[n][m];
    }
//L search in rotated2 with repeated values
//[1,0,1,1,1]
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,m;

        while(l<=r){
            m=l+(r-l)/2;
            if(nums[m]==target) return 1;
            if(nums[m]==nums[l] && nums[m]==nums[r]) l++,r--;//only change
            else if(nums[m]>=nums[l]){
                //left sorted
                if(target>=nums[l] && target<nums[m]) r=m-1;
                else l=m+1;
            }else {
                //right sorted
                if(target>nums[m] && target<=nums[r]) l=m+1;
                else r=m-1;
            }
        }
        return 0;
    }
//a2
class Solution {
public:
    int pivot(vector<int>& nums, int l, int r) {
        while(l < r) {
            
            while(l < r && nums[l] == nums[l+1])
                l++;
            
            while(r < l && nums[r] == nums[r-1])
                r--;
            
            /*
                You need to do what I did above because you'll fail in case like
                [1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1]
                2
                Here, the nums[mid] <= nums[r] and
                and we will cut down the right half but our pivot lies there
                So, make it a RULE, whenever there are duplicate elements and you need to to something
                like Binary Search, you need to ignore duplicates like done above
                Similar Qn : "Smallest element in a rotated sorted array with duplicates"
            */
            int mid = l + (r-l)/2;
            
            if(nums[mid] <= nums[r]) { //sorted part
                r = mid; //possibly my pivot
            } else {
                l = mid+1;
            }
        }
        
        return r;
    }
    
    bool binarySearch(vector<int>& nums, int l, int r, int& target) {
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] == target)
                return true;
            
            if(nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        
        int p = pivot(nums, 0 , n-1);
        cout <<"p = " << p << endl;
        if(binarySearch(nums, 0, p-1, target)) {
            return true;
        }
        
        return binarySearch(nums, p, n-1, target);
            
    }
};
//g 11/8 coin change combination
//error we couldnt avoid permutation if we give all choices at each moment
//we should only be able to choose current or higher idx not before
{
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<long long int> dp(sum+1,0);
        dp[0]=1;

        for(int i=0;i<N;i++){
            for(int j=coins[i];j<=sum;j++){ //mistake j<N , j<sum
                dp[j]+=dp[j-coins[i]];
                // cout<<dp[j]<<" ";
            }
            // cout<<endl;
        }

        return dp[sum];
    }
};

//a2
//     long long int dfs(int coins[], int N, int sum){
//     if(sum <  0 || N <= 0)
//         return 0;
//     if(sum == 0)
//         return 1;
//         return dfs(coins, N-1, sum) + dfs(coins, N, sum-coins[N-1]);
//     }
//   public:
//     long long int count(int coins[], int N, int sum) {
//         // code here.
//         return dfs(coins,N,sum);
//     }

//a3
// class Solution {
//   public:
//     long long int dp[1001][1001]; 
//     int n;
//     long long int helper(int indx, int target, int* coins){
//         if (target == 0)
//         return 1;
        
//         if (indx == n)
//         return 0;
        
//         if (dp[indx][target] != -1)
//         return dp[indx][target];
        
//         long long int take = 0, skip = 0;
//         if (target >= coins[indx])
//         take = helper(indx,target - coins[indx],coins);
//         skip = helper(indx+1, target, coins);

//         return dp[indx][target] = take + skip;
//     }

// long long int count(int coins[], int N, int sum) {
//     memset(dp,-1,sizeof(dp));
//         n = N;
//         return helper(0,sum,coins);
// }
// };

//l coin change
class Solution {
public:
    int t[301][5001];
    int f(int amount, vector<int>& coins,int i){
        if(amount==0) return 1;
        if(i==coins.size()) return 0;

        if(t[i][amount]!=-1) return t[i][amount];
        //skip
        int skip=f(amount,coins,i+1);
        //take
        int take=coins[i]<=amount? f(amount-coins[i],coins,i) : 0;

        return t[i][amount] = skip+take;
    }
    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
        return f(amount , coins , 0);
    }
};
//l 12/8 uniquePathsWithObstacles
class Solution {
public:
    int n,m;
    int t[101][101];

    int f(int i,int j,vector<vector<int>>& obstacleGrid){
//no need to check i<0 && j<0
//no need to mark visited because we cant visit any cell again as only right & down options , no up & left.
        if( i==n || j==m || obstacleGrid[i][j]) return 0;

        if(i==n-1 && j==m-1) return 1;

        if(t[i][j]!=-1) return t[i][j];

        int right=f(i,j+1,obstacleGrid);
        int down =f(i+1,j,obstacleGrid);

        return t[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n=obstacleGrid.size(),m=obstacleGrid[0].size();
        memset(t,-1,sizeof(t));

        if(obstacleGrid[0][0] + obstacleGrid[n-1][m-1] > 0 ) return 0;

        return f(0,0,obstacleGrid);
    }
};
//a2
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    } 
};
//g longest increasing Subsequence length
//a1 runtime error
    public:
    //idx [0,n-1]
    //previous [-1,n-1]
    int t[10001][10002];
    //Function to find length of longest increasing subsequence.
    int f(int n, int a[],int pt,int idx){
        if(idx==n) return 0;
        
        if(t[idx][pt+1]!=-1) return t[idx][pt+1];
        
        int take=0,skip=0;
        //take
        if(pt==-1 || a[idx]>a[pt]) {
            take = f(n,a,idx,idx+1)+1;
        }
        //skip
        skip = f(n,a,pt,idx+1);
        
        return t[idx][pt+1] = max(take,skip);
        
    }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
       // n a prevtaken idx
       memset(t,-1,sizeof(t));
       
       return f(n,a,-1,0);
    }
//a2 
    int longestSubsequence(int n, int a[])
    {
        // your code here
        vector<int> v;
        //every position of v will store smallest element needed to make lis of that position length
        // 5 8 3 7 9 1
        // [5]
        // [5,8]
        // [3,8] //1 length we need 3 & 2 length we need 8 ending till now, so for 2 length we will search anything above 3
        // [3,7]
        // [3,7,9]
        // [1,7,9]
        
        v.push_back(a[0]);
        for(int i=1;i<n;i++){
           if(a[i]>v.back()) v.push_back(a[i]);
           else{
               int lb= lower_bound(v.begin(),v.end(),a[i]) - v.begin();
               v[lb]=a[i];
           }
        }
        return v.size();
    }
//g 13/8 nthFibonacci
    int nthFibonacci(int n){
        // code here
        long a=0,b=1,c=0,m=1e9+7;
        
        for(int i=0;i<n;i++){
            c=(a+b)%m;
            
            a=b;
            b=c;
        }
        return a;
    }
//a2
    int mod=1e9+7;
    int t[100001];
    int f(int i){
        if(i<=1) return t[i]=i;
        
        if(t[i]!=-1) return t[i];
        
        return t[i] = (f(i-1) + f(i-2))%mod;
    }
  
    int nthFibonacci(int n){
        // code here
        memset(t,-1,sizeof(t));
        return f(n);
    }
//l validPartition
class Solution {
public:
    int n;
    vector<int> memo;  // Memoization array
    // int memo[1000001];

    bool f(int i, vector<int>& nums) {
        if (i == n) return true;
        if (i == n - 1) return false;

        if (memo[i] != -1) return memo[i];

        bool f1 = false, f2 = false;
        if (nums[i] == nums[i + 1]) {
            f1 = f(i + 2, nums);
        }
        if(f1) return memo[i] = 1;

        if (i + 2 < n) {
            if ((nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) ||
                (nums[i] + 1 == nums[i + 1] && nums[i] + 2 == nums[i + 2])) {
                f2 = f(i + 3, nums);
            }
        }

        return memo[i] = f2;
    }

    bool validPartition(vector<int>& nums) {
        n = nums.size();
        memo.assign(n, -1);  // Initialize memoization array with -1
        // memset(memo,-1,sizeof(memo));
        return f(0, nums);
    }
};
//a2
class Solution {
public:
    bool validPartition(std::vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return false;

        std::vector<bool> dp = {true, false, n > 1 && nums[0] == nums[1]};

        for (int i = 2; i < n; i++) {
            bool current_dp = false;

            if (nums[i] == nums[i-1] && dp[1]) {
                current_dp = true;
            }
            else if (nums[i] == nums[i-1] && nums[i] == nums[i-2] && dp[0]) {
                current_dp = true;
            }
            else if (nums[i] - nums[i-1] == 1 && nums[i-1] - nums[i-2] == 1 && dp[0]) {
                current_dp = true;
            }

            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = current_dp;
        }

        return dp[2];
    }
};
/*
 11234
TFTFFT

 44456
TFTTFT

 1112
TFTTF
*/
//use \ to split long lines of code into multiple lines
//g 14/8 2 odd occurence singleNumber
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int x=0;//xor of 2 ans
        for(auto num:nums) x^=num;
        
        // int diff= x^(x&(x-1));// x&(-x)
        int diff= x&(-x);
        // x&(-x) and x^(x&(x-1)) will give rightmost 1 in binary form
        int x1=0,x2=0;
        for(auto num:nums){
            if(num&diff) x1^=num;
            else x2^=num;
        }
        if(x1<x2) return {x1,x2};
        return {x2,x1};
    }
//l findKthLargest
//a1 store all in max heap , pop k-1 times , return top
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int> pq;
        // for(auto num:nums) pq.push(num);
        priority_queue<int> pq(nums.begin(),nums.end());

        while(--k) pq.pop();
        return pq.top();
    }
//a2 min heap of size k, return top
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int> > pq;//min heap
        for(auto num:nums){
            pq.push(num);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
//g 15/8 max ones after flipping subarray
        int c0=0,l=-1,r=-1,max0=0,j=0,i=0,c1=0;
        
        for(;j<n;j++){
            if(a[j]) {
                c1++;
                c0--;
            }
            else c0++;
            
            for(;c0<0;i++){
                if(a[i]) c0++;
                else c0--;
            }
            
            if(c0>max0){
                l=i;
                r=j;
                max0=c0;
            }
        }
        cout<<l<<" "<<r<<endl;
        return c1 + max0;
    }
//a2
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int c0=0,l=-1,r=-1,max0=0,j=0,i=0,c1=0;
        
        for(;j<n;j++){
            if(a[j]) {
                c1++;
                c0--;
            }
            else c0++;
            
            if(c0<0) c0=0;
            
            max0=max(max0,c0);
            
        }
        return c1 + max0;
    }
//l partition LL based on < val & >=val
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* less= new ListNode(-1);
        ListNode* big = new ListNode(-1);

        ListNode* t1=less,*t2=big;

        while(head){
            if(head->val < x){
                t1->next = head;
                t1 = head;
            }else{
                t2->next = head;
                t2 = head;
            }
            head=head->next;
        }

        t1->next=big->next;
        t2->next = nullptr; // Terminate the big list


        // return less->next;
        ListNode* newH=less->next;

        delete less;
        delete big;

        return newH;
    }
};
