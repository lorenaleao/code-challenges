class Solution {
public:
    int sum_squares_digits(int n){
        int sum = 0;
        while(n){
            int digit = n % 10;
            n /= 10;
            sum += digit * digit;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> numbers;
        
        n = sum_squares_digits(n);
        
        while(numbers.count(n) == 0){
            numbers.insert(n);
            n = sum_squares_digits(n);
        }
        
        if(n == 1)
            return true;
        else
            return false;
    }
};