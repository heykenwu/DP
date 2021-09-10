int tribonacci(int n){
    if(n == 0) {
        return n;
    }
    int a = 0;
    int b = 1;
    int c = 1;
    int count;
    int result = 1;
    for(count = 2;count <n; count++){
        result= a+b+c;
        a = b;
        b = c;
        c = result;
    }
    return c;
}