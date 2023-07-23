class Graph {
    private List<Pair<Integer, Integer>>[] graph; 
    private int N;

    public Graph(int n, int[][] edges) {
        N = n;
        graph = new ArrayList[N+1];
        for (int i = 0; i <= n; i++) 
            graph[i] = new ArrayList<>();

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].add(new Pair<>(v, w));
        }
    }

    public void addEdge(int[] edge) {
        int u = edge[0], v = edge[1], w = edge[2];
        graph[u].add(new Pair<>(v, w));
    }

    public int shortestPath(int start, int end) {
        
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(
            (a, b) -> a.getValue() - b.getValue());
        
        int[] dist = new int[N+1]; // distance array
        Arrays.fill(dist, Integer.MAX_VALUE);

        dist[start] = 0;
        pq.add(new Pair<>(start, 0));

        while (!pq.isEmpty()) {
            Pair<Integer, Integer> node = pq.poll();
            int vtx = node.getKey();

            for (Pair<Integer, Integer> nbr : graph[vtx]) {
                int nbrNode = nbr.getKey();
                int nbrDist = nbr.getValue();

                if (dist[vtx] + nbrDist < dist[nbrNode]) { 
                // (WSF for current vtx + dist to reach this nbr) < (current saved dist)
                    dist[nbrNode] = dist[vtx] + nbrDist;
                    // update the dist array with current distance added
                    pq.add(new Pair<>(nbrNode, dist[nbrNode]));
                }
            }
        }

        return dist[end] == Integer.MAX_VALUE ? -1 : dist[end];
    }
}
/**
 * Your Graph object will be instantiated and called as such:
 * Graph obj = new Graph(n, edges);
 * obj.addEdge(edge);
 * int param_2 = obj.shortestPath(node1,node2);
 */