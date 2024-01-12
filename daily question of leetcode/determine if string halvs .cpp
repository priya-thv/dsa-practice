class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        string a="";
        string b="";
        for(int i=0;i<n/2;i++){
            a.push_back(s[i]);
            b.push_back(s[n/2+i]);
        }
        int c=0,c1=0;
        for(int i=0;i<a.size();i++){
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||
            a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'){
                c++;
            }
            if(b[i]=='a'||b[i]=='e'||b[i]=='i'||b[i]=='o'||b[i]=='u'||b[i]=='A'||
            b[i]=='E'||b[i]=='I'||b[i]=='O'||b[i]=='U'){
                c1++;
            }
        }
        if(c==c1)return true;

        return false;
    }
};
