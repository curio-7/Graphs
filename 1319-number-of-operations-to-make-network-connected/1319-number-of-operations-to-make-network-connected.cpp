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
    int makeConnected(int n, vector<vector<int>>& connections) {
        //so in this let suppose we have n components that are not connected hence we have to connnect then with n-1 edges right.
        // so our ans should be nComponents - 1;
        // but we only have to use given edges so count no of extra edges such that grpah still remain connected
        // hence if(extraEdges >= ans) return ans
        // else return -1 
        //so anytime we see dynamic connection happening we say disjoint set.
        //here we will connect graphs.
        //take first test case here we have 0->1 up = 0;
        //then 0->2 up = 0;
        //then 1->2 here it has extra edge since they have same up.
        //so ExtraEdge  =1;
        //comp = 2;
        //ans = 2-1; and (1>=1) hence return 1;
        //test case 2: 
        //it has 2 extra edges , noOfComp = 3, ans = 3-1=2, and (2>=2) hence ans = 2.
        //tc 3:
        //extra = 1, ans = 0, hence return -1;
        
        DSU ds(n);
        int extraEdge = 0;
        for(auto&x:connections){
            if(ds.Find(x[0]) == ds.Find(x[1]))extraEdge++;
            else ds.Merge(x[0],x[1]);
        }
        
        int cntC = 0;
        for(int i=0;i<n;i++){
            if(ds.Find(i) == i)cntC++;
        }
        
        int ans = cntC-1;
        return (extraEdge>=ans)?ans:-1;
    }
};
