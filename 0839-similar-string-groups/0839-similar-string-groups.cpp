typedef vector<int> vi;
class DSU
{
	int n;
	vi p;
	vi size;
	public:
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
    bool comp(string &a,string &b){
        int n=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i] && (++n)>2){
                return false;
            }
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DSU ds(n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(comp(strs[i],strs[j])){
                    ds.Merge(i,j);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(ds.Find(i)==i)cnt++;
        }
        return cnt;
    }
};