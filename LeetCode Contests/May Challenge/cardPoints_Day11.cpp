/*
    Problem : There are several cards arranged in a row, and each card has an associated number of points The points are given in the integer array cardPoints.
        In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
        Your score is the sum of the points of the cards you have taken.
        Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

    Example 1:
    Input: cardPoints = [1,2,3,4,5,6,1], k = 3
    Output: 12
    Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

    Example 2:
    Input: cardPoints = [2,2,2], k = 2
    Output: 4
    Explanation: Regardless of which two cards you take, your score will always be 4.

    Example 3:
    Input: cardPoints = [9,7,7,9,7,7,9], k = 7
    Output: 55
    Explanation: You have to take all the cards. Your score is the sum of points of all cards.

    Example 4:
    Input: cardPoints = [1,1000,1], k = 1
    Output: 1
    Explanation: You cannot take the card in the middle. Your best score is 1. 

    Example 5:
    Input: cardPoints = [1,79,80,1,1,1,200,1], k = 3
    Output: 202

    Constraints:
    1 <= cardPoints.length <= 10^5
    1 <= cardPoints[i] <= 10^4
    1 <= k <= cardPoints.length
*/

class Solution {
public:
    
    /*
    int max(int x, int y){
        return x > y ? x : y ;
    }
    
    int getPoints(vector<int> &cardPoints, vector<vector<int>> &points, int i, int j, int k){
        int n = cardPoints.size() ;
        if(k == 1){
            // With DP
            points[i][n-1-j] = max(cardPoints[i], cardPoints[j]) ;
            return points[i][n-j-1] ;
            
            // without DP
            //return max(cardPoints[i], cardPoints[j]) ;
        }
        
        // With DP
        if(points[i][n-1-j] != 0)
            return points[i][n-j-1] ;
        
        points[i][n-1-j] = max(cardPoints[i] + getPoints(cardPoints, points, i+1, j, k-1),
                                cardPoints[j] + getPoints(cardPoints, points, i, j-1, k-1)) ;
        return points[i][n-1-j] ;
        
        /*
        // Without DP (Recursive)
        return max(cardPoints[i] + getPoints(cardPoints, i+1, j, k-1),
                                cardPoints[j] + getPoints(cardPoints, i, j-1, k-1)) ;
        
    } 
    */
    
    int maxScore(vector<int>& cardPoints, int k) {
        /*
        DP Solution (TLE)
        vector<vector<int>> points(k, vector<int>(k,0)) ;
        //return getPoints(cardPoints, points, 0, cardPoints.size()-1, k) ;
        return getPoints(cardPoints, points, 0, cardPoints.size()-1, k) ;
        */
        
        // Sliding window solution (Accepted)
        unsigned int sum = 0, maxSum = 0 ; 
        int n = cardPoints.size() ;
        for(int i = 0 ; i < k ; i++)
            sum += cardPoints[i] ;
        maxSum = sum ;
        
        for(int j = n-1, i = k-1 ; j >= n-k, i >= 0; j--, i--){
    
            sum -= cardPoints[i] ;
            sum += cardPoints[j] ;
            
            if(sum > maxSum)
                maxSum = sum ;
        }
        
        return maxSum ;
    }
};