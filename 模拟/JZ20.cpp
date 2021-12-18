bool isNumeric(string str) {
        // write code here
        int start = 0;
        while(str[start]==' ')
        {
            start++;
        }
        int end = str.size()-1;
        while(str[end]==' ')
        {
            end--;
        }
        if(str[start]=='+' || str[start]=='-')
            start++;
        bool expo = false;
        bool digit = false;
        int num_point = 0;
        while(start<=end)
        {
            if(str[start]=='+' || str[start]=='-')
            {
                if(!expo)
                    return false;
                if(start>0 && str[start-1]!='e' && str[start-1]!='E')
                    return false;
            }
            else if(str[start]=='.')
            {
                if(num_point>0 || expo)
                    return false;
                num_point++;
            }
            else if(str[start]=='e' || str[start]=='E')
            {
                if(expo || !digit)
                    return false;
                expo = true;
                digit = false;
            }
            else if(str[start]>='0' && str[start]<='9')
            {
                digit = true;
            }
            else
                return false;
            start++;
        }
        return digit;
    }