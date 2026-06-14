class Solution {
public:
    int findSize(int x){
        int size=0;
        while(x/10){
            size++;
            x/=10;
        }
        return ++size; 
    }
    int reverse(int x) {
        int powerFactor=findSize(x)-1;
        int temp=0;
        long reversed=0;
        if(powerFactor==0) return x;
        while(powerFactor!=-1){
            temp=x%10;
            reversed+=temp*pow(10,powerFactor);
            powerFactor--;
            x/=10;
        }
        if(reversed>(pow(2,31)-1)||reversed<(pow(-2,31)))
        return 0;
        return reversed;
    }
};