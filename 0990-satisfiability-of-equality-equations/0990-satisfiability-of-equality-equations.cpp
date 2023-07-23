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
    bool equationsPossible(vector<string>& eq) {
        int n = eq.size();
        DSU ds(26);
        
        for(int i = 0;i<n;i++){
            int chr1 = eq[i][0]-'a';
            int chr2 = eq[i][3]-'a';
            char sign1 = eq[i][1];
            
            if(sign1 == '='){
                ds.Merge(chr1,chr2);
            }
        }
        for(int i = 0;i<n;i++){
            int chr1 = eq[i][0]-'a';
            int chr2 = eq[i][3]-'a';
            char sign1 = eq[i][1];
            
            if(sign1 == '!' && ds.Find(chr1)==ds.Find(chr2)){
                return false;
            }
        }
        return true;
    }
};