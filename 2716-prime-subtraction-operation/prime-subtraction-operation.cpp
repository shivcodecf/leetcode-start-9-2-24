class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {

        int n = 10001;

         vector<bool> prime(n + 1, true);

  for (int p = 2; p * p <= n; p++) {


        // If prime[p] is not c


        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    // for (int p = 2; p <= n; p++)
    //     if (prime[p])
    //         cout << p << " ";

    vector<int>ans;

        
        for(int i=0;i<nums.size();i++)
        {  
            int check = 0,prev=0,next=0,flag=0,check1=0;

            if(i>0)
            {
              prev = nums[i-1];
             
            }
           

            for(int j=2;j<nums[i];j++)
            {
               if(prime[j])
               {
                   check = j;

                   if(i>0)
                   {
                      int x = nums[i]-j;

                   if(x>prev)
                   {  
                     check1 = j;
                   }

                   }
                  

                 


               }

               
               
            }

            if(i==0)
            {
                nums[i] = nums[i] - check;
            }
             
            
           else
            {
                // nums[i] = nums[i]-check;
                
                  
                  nums[i] = nums[i]-check1;
            }
             

            //  if(flag==0)
            //  {
            //     ans.push_back(nums[i]);
            //  }
           

        }

        for(int i=0;i<nums.size();i++)
        {
            cout <<nums[i]<<" ";
        }



        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=nums[i-1])
            {
                return false;
            }
        }

        return true;







    }
};