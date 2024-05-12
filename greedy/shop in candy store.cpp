
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        // Write Your Code here
        vector<int>v;
        sort(candies,candies+N);
        int mini=0;
        int buy=0;
        int free=N-1;
        while(buy<=free){
            mini=mini+candies[buy];
            buy++;
            free=free-k;
        }
        int maxi=0;
        buy=N-1;
        free=0;
        while(free<=buy){
            maxi=maxi+candies[buy];
            buy--;
            free=free+k;
            
        }
        v.push_back(mini);
        v.push_back(maxi);
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
