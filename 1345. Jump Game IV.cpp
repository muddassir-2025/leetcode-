class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n=arr.size();
        if(n==0) return 0;
        int jumps=0;

        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

        vector<bool>vis(n,false);
        queue<int>q;

        q.push(0);
        vis[0]=true;
       

        while(!q.empty()){
            int sz=q.size();
            //store all possible paths - if reach end return
            while(sz--){
                int i=q.front();
                q.pop();

                if(i==n-1) return jumps;

                if(i+1<n && !vis[i+1]){
                    vis[i+1]=true;
                    q.push(i+1);
                }

                if(i-1>=0 && !vis[i-1]){
                    vis[i-1]=true;
                    q.push(i-1);
                }

                for(int idx : mp[arr[i]]){ 
                    if(!vis[idx]){
                    vis[idx]=true;
                    q.push(idx);
                    }
                }

                mp[arr[i]].clear();
                
            }
            jumps++;
        }

        return -1;
    }
};
