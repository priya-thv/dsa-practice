class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size(),m=version2.size();
        
        for(int i=0,j=0;(i<n )|| (j<m);i++,j++){
            int x1=0,x2=0;
            while((i<n) && (version1[i]!='.')){
                x1=x1*10+(version1[i]-'0');
                i++;
            }
            while((j<m) && (version2[j]!='.')){
                x2=x2*10+(version2[j]-'0');
                j++;
            }
            if(x1>x2)return 1;
            if(x2>x1)return -1;
        }

        return 0;
    }
};
