class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for (auto prerequisite : prerequisites) {
        int course = prerequisite[1]; 
        int prereq = prerequisite[0];
        adj[course].push_back(prereq); 
    }
        vector<int> indegree(numCourses, 0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if( indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>tobo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            tobo.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if( indegree[it]==0)
                {
                    q.push(it);
                }
                
            }
        }
        vector<int>empty;
        if(tobo.size()!=numCourses)
        {
            return empty;
        }
        return tobo; 
        
    }
};