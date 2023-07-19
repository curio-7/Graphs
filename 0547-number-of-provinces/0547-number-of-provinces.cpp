typedef vector<int> vi;
struct DSU
{
	int n;
	vi p;
	vi size;
	DSU(int N)
	{
		n = N;
		p.assign(n + 1, -1);
		size.assign(n + 1, 1);
		for (int i = 0; i <= n; i++)p[i] = i;
	}
	int Find(int i)
	{
		if (p[i] == i)return i;
		return p[i] = Find(p[i]);
	}
	void Merge(int a, int b) // b ko a me Merge
	{
		a = Find(a), b = Find(b);
		if (a != b)
		{
			p[b] = a;
			size[a] += size[b];
		}
	}
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU ds(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1) ds.Merge(i,j);
            }
        }
        
        int connected = 0;
        for(int i=0;i<n;i++){
            if(ds.Find(i)==i)connected++;
        }
        
        return connected;
    }
};