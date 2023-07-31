//POTD GFG LEETCODE CN
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