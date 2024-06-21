class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
      
      int n=customers.size();

      
      vector<int>v,v1;

      int sum=0,Total=0;

      for(int i=0;i<n;i++)
      {

        sum+=customers[i];
        v.push_back(sum);
       
      }

      sum=0;
      int maxi1=0;

      for(int i=0;i<n;i++)
      {

        if(grumpy[i]==0){

        sum+=customers[i];
        Total+=customers[i];

        }
        else {
            maxi1=max(maxi1,customers[i]);
        }

        v1.push_back(sum);

      }

      if(minutes==1)
      {
        return maxi1+Total;
      }


      int i = 0,j = minutes-1,maxi=-1,ind=-1;

      int check = (v[j]-v1[j]);

      int currentSum1 = v[j]; 
      int currentSum2 = v1[j]; 
      int temp=0,temp1=0;


      if(check>maxi)
      { 

        maxi = check;
        ind = j;
        temp1= v1[j];
        temp= v[j];


       
      }
      if(n==minutes)
      {
        return v[n-1];
      }

      
      



      

      while(i<n && j<n)
      {
        
        currentSum1= v[i];
        currentSum2= v1[i];

        j++;
        i++;

        int x=0,y=0;

          if(j<n)
          {
              x= v[j]-currentSum1;
              y= v1[j]-currentSum2;
             
          }
          else {
            break;
          }
         
         
           
          
         
        

        check = (x-y);

        if(check>maxi)
        {
             maxi = check;
             ind = j;
             temp=x;
             temp1=y;

        }


      }

      return Total - temp1 + temp;





   

      







       









      
        
    }
};