int fib(int n){
    if(n == 0) {
        return n;
    }
    int a = 0;
    int b = 1;
    int count;
    int c = 1;
    for(count = 1;count <n; count++){
        c= a+b;
        a = b;
        b = c;
    }
    return c;
}