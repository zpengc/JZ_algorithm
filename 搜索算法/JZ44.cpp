int findNthDigit(int n) {
        if(n<10)
            return n;
        int i = 1;
        long long s = 10;
        int pre = 0;
        
        while(n > s)
        {
            i++;
            pre = s;
            s += 9*pow(10, i-1)*i;
        }
        int num = (n-pre)/i + pow(10, i-1);
        string temp = to_string(num);
        int pos = (n - pre ) % i;
        return temp[pos] - '0';
    }