class Solution {
public:
    struct element{
        int val;
        int frequence;
        bool operator>(const element& e) const{
            if(this->frequence==e.frequence) return this->val>e.val;
            return this->frequence>e.frequence;
        }
        bool operator==(const element& e) const{
            return this->frequence == e.frequence && this->val == e.val;
        }
        bool operator<(const element& e) const{
            if(this->frequence==e.frequence) return this->val<e.val;
            return this->frequence<e.frequence;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> freq;
        for(int i = 0;i<n;i++){
            if(freq.count(nums[i])==0) freq[nums[i]] = 1;
            else freq[nums[i]]++;
        }
        set<element>s;
        for(int i = 0;i<n;i++){
            element e{nums[i],freq[nums[i]]};
            s.insert(e);
        }
        priority_queue<element,vector<element>,greater<element>> pq;
        auto p = s.begin();
        for(int i = 0;i<k;i++,p++){
            if(p==s.end()) break;
            pq.push(*p);
        }
        while(p!=s.end()){
            pq.push(*p);
            pq.pop();
            p++;
        }
        vector<int>ans(0);
        while(!pq.empty()){
            ans.push_back(pq.top().val);
            pq.pop();
        }
        return ans;
    }
};