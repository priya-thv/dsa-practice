class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count1=0;
        int count=0;
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        while(i<j){
            if(people[j]==limit){
                count1++;
                j--;
            }else if((people[i]+people[j])<=limit){
                count++;
                i++;
                j--;
            }else if((people[i]+people[j])>limit){
                j--;
            }
        }
        int d=people.size()-(count*2)-count1;
        return d+count+count1;

    }
};
