struct TrieNode
{
    TrieNode* children[10]; //0,1,2,3,4,5,6,7,8,9
};

class Solution {
public:

  TrieNode* getTrieNode(){

    TrieNode* node = new TrieNode();

    for(int i=0;i<10;i++)
    {
        node->children[i] = NULL;
    }

    return node;

  }

  void insert(int num,TrieNode* root)
  {
    TrieNode* crawl = root;

    string s = to_string(num);

    for(char ch:s)
    { 

       int idx = ch-'0';

       if(crawl->children[idx]==NULL)
       {
        crawl ->children[idx] = getTrieNode();
       }

       crawl = crawl->children[idx];

    }

  }
  // return len of longest prefix
  int search(int num,TrieNode* root)
  {
       TrieNode*crawl = root;

       string s = to_string(num);

       int res=0;

       for(char ch:s)
       {
        int idx = ch-'0';
        if(crawl->children[idx])
        {   
            res++;
            crawl = crawl->children[idx];
        }
        else {
            break;
        }
       } 

       return res;
  }





    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        TrieNode* root = getTrieNode();

        for(int num : arr1)
        {
            insert(num,root);
        }

        int result =0;

        for(int num : arr2)
        {
            result = max(search(num,root),result);
        }

        return result;


        
    }


};