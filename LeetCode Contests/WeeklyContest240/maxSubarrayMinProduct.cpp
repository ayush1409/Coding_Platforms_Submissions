class Solution {
public:
    unsigned long long int max(unsigned long long int x, unsigned long long int y){
        return x > y ? x : y ;
    }
    int maxSumMinProduct(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0] ;
         unsigned long long int min = nums[0], maxProduct = nums[0] * nums[0], sum = nums[0] ; 
        
        for(int i = 1 ; i < nums.size() ; i++){
            if(min >= nums[i] && min*(sum + nums[i]) > nums[i] * nums[i]){
                min = nums[i] ;
                sum += nums[i] ;
                maxProduct = max(maxProduct, min*sum) ;
            }
            else if( min * (sum + nums[i]) > nums[i] * nums[i]){
                sum += nums[i] ;
                maxProduct = max(maxProduct, min*sum) ;
            }
            else{
                sum = nums[i] ;
                min = nums[i] ;
                maxProduct = max(maxProduct, nums[i] * nums[i]) ;
            }
        }

        return (int)(maxProduct % (unsigned long long int)(pow(10,9) + 7)) ;
        
    }
};