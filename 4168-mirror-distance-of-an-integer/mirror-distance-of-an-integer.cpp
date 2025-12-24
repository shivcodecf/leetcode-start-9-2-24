class Solution {
public:
    int mirrorDistance(int n) {

        int x = n;

        string s = to_string(n);

        string s1 = "";

        while(n>0)
        {
            int x = n%10;
            s1+=x+'0';
            n = n/10;
        }

        cout <<s1<<endl;

       int num = stoi(s1);

       cout <<num<<endl;

       return abs(x-num);


        
    }
};