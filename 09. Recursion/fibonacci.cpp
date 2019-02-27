/*
17 jan 2020

1. Recursive O(2^n)
2. Memoized DP O(n)
3. Bottom up DP
4. Bottom up DP without Array
5. #TDOD
 Matrix and golden ratio approach
 */

//1. Recursive O(2^n)
    int fib(int N) {
        if (N == 0)
            return 0;
        if (N <= 2)
            return 1;
        return fib(N-1) + fib(N - 2);
    }

// 2. Memoized DP O(n)
    int a[35], k = 0;
    int fib(int N) {
        if (N == k) return a[k];
        if (N == 0)
             a[0] = 0;
        else if (N <= 2){
            a[N] = 1;
            k = N;}
        else {
            a[N] = fib(N - 1) + fib(N - 2);
            k++;
            
        }
        return a[N];
    }

// 3. Bottom up DP
    
    int fib(int N) {
        int a[35];
        for (int i = 0; i <= N; i++){
        if (i == 0)
             a[i] = 0;
        else if (i <= 2)
            a[i] = 1;
        else 
            a[i] = a[i - 1] + a[i - 2];
        }
        return a[N];
    }

// 3. Bottom up DP
    
    int fib(int N) {
        int a = 0, b = 1, c;
        if(N ==0) return 0;
        if (N == 1) return 1;
        while(N-- > 1){
            c = a+b;
            a = b; b = c;
        }
        return c;
    }