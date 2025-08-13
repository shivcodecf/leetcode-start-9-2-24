class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();

        int m = nums2.size();

        int i = 0, j = 0;

        int mid = (n + m) / 2;

        int c = 0;

        double ans  = 0;

        vector<int>v;

        if(n==0 || m==0)
        {
            if(n)
            {
              sort(nums1.begin(),nums1.end());

              if(n%2)
              {
                return  nums1[n/2];
              }
              else {
                return (float) (nums1[n/2]+nums1[n/2 - 1])/2;
              }

              
            }

            else {

            sort(nums2.begin(),nums2.end());

              if(m%2)
              {
                return  nums2[m/2];
              }
              else {
                return (float)(nums2[m/2]+nums2[m/2 - 1])/2;
              }

            }
        }

      

       

        while (i < n && j < m) {                              

             


            if ( i<n && j<m && (nums1[i] > nums2[j])  ) {     

                v.push_back(nums2[j]);    
              

                j++;           

                c++;

                if ((n + m) % 2) {

                    if (v.size() > mid) {

                        ans = v.back();

                        return ans;
                    }

                }


                else {

                 
                   if(v.size()>mid)
                   {  

                  

                    int a = v.back();

                    v.pop_back();

                    int b = v.back();

                    ans = (double)(a+b)/2;

                    return ans;


                   }


                }

               


            }




            else if( i<n && j<m  &&  (nums1[i]<=nums2[j])  ) { 


                v.push_back(nums1[i]);

                i++;

                c++;

                  if ((n + m) % 2) {

                    if (v.size() > mid) {

                        ans = v.back();

                        return ans;
                    }

                }


                else {

                 
                   if(v.size()>mid)
                   {

                   

                    int a = v.back();

                    v.pop_back();

                    int b = v.back();

                    ans = (double)(a+b)/2;

                    return ans;


                   }


                }


            }


        }

        cout <<i<<" "<<j<<endl;


        if(v.size() <= mid)
        {
            
            if(i<n)
            {    
                
                for(int k=i;k<n;k++)
                { 

                   v.push_back(nums1[k]);

                     if ((n + m) % 2) {

                    if (v.size() > mid) {

                        ans = v.back();

                        return ans;
                    }

                }

                   else 
                   {
                    if(v.size()>mid)
                   {

                    int a = v.back();

                    v.pop_back();

                    int b = v.back();

                    ans = (double)(a+b)/2;

                    return ans;

                   }
                    
                   }

                }

            }

            else {


                 for(int k=j;k<m;k++)
                { 

                      v.push_back(nums2[k]);


                     if ((n + m) % 2) {

                    if (v.size() > mid) {

                        ans = v.back();

                        return ans;
                    }

                    }



                   else 
                   {

                    if(v.size()>mid)
                    {

                         int a = v.back();

                    v.pop_back();

                    int b = v.back();

                    ans = (double)(a+b)/2;

                    return ans;

                    }
                    
                   
                   }

                }

            }


        }




        

        return 0;
    }
};