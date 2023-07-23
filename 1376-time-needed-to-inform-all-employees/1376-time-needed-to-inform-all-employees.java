class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        if(n == 1)return 0;
        
        int[] time = new int[n];
        List<List<Integer>> edge = new ArrayList<>();
        
        for(int i = 0;i < n;i++)edge.add(new ArrayList<>());
        
        for(int i = 0;i < n;i++){
            if(manager[i] != -1)
                edge.get(manager[i]).add(i);
        }
        
        int max = 0;
        Queue<Integer> q = new LinkedList<>();
        
        q.add(headID);
        
        while(!q.isEmpty()){
            int curr = q.poll();
            
            for(int sub : edge.get(curr)){
                time[sub] = time[curr] + informTime[curr];
                max = Math.max(max, time[sub]);
                q.add(sub);
            }
        }
        return max;
    }
}