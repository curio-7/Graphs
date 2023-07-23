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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        DSU ds(n);
        
        for(int i = 0;i<pairs.size();++i){
            int idx1 = pairs[i][0];
            int idx2 = pairs[i][1];
            ds.Merge(idx1,idx2);
        }
        
        unordered_map<int,vi>mp;
        for(int i = 0;i<ds.p.size();i++){
            int par = ds.p[i];
            mp[ds.Find(par)].push_back(i);
        }
        
        for(auto&x:mp){
            string temp;
            for(int i=0;i<x.second.size();i++) temp += s[x.second[i]];
            sort(begin(temp),end(temp));
            for(int i=0;i<x.second.size();i++) s[x.second[i]] = temp[i];
        }
        
        return s;
        
    }
};