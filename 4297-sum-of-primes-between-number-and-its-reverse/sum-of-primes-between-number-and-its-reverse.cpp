class Solution {
public:
    int prime(int no){
       if(no<=1) return 0;
        for(int i = 2; i<no; i++){
            if(no%i==0) return 0;
        }
        
        return no;
    }


    int sumOfPrimesInRange(int n) {
        int org = n;
        int rev = 0;
        int sum = 0;
        while(n>0){
            int digit = n%10;
            rev = rev*10 + digit;
            n = n/10;
        }
        int maxNO = max(org, rev);
        int minNo = min(org, rev);

        for(int i = minNo; i<=maxNO; i++){
            sum = sum + prime(i);
        }
        return sum;
    }
};