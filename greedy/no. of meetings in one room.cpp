class Solution {
public:
    int cal(vector<int>& energy, int i,int k){
        int total=0;
        for(int x=i;x<energy.size();x+=k){
            total+=energy[x];
            cout<<total<<endl;
        }
        return total;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int maxi=INT_MIN;
        for(int i=0;i<energy.size();i++){
            maxi=max(maxi,cal(energy,i,k));
        }
        return maxi;
    }
};
