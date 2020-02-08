int romanToInt(char * s){
    int len = strlen(s);
    int result = 0;
    for(int i = 0; i < len; ++i){
        switch(s[i]){
            case 'M':
                result += 1000;
                break;
            case 'D':
                result += 500;
                break;              
            case 'C':{
                if(i < len-1){
                    if(s[i+1] == 'M'){
                        result += 900;
                        ++i;
                        continue;
                    }
                    else if(s[i+1] == 'D'){
                        result += 400;
                        ++i;
                        continue;
                    }
                    else{
                        result += 100;
                    }
                }
                else
                    result += 100;
                break;
            }
            case 'L':
                result += 50;
                break;
            case 'X':{
                if(i < len-1){
                    if(s[i+1] == 'C'){
                        result += 90;
                        ++i;
                        continue;
                    }
                    else if(s[i+1] == 'L'){
                        result += 40;
                        ++i;
                        continue;
                    }
                    else{
                        result += 10;
                    }
                }
                else
                    result += 10;
                break;
            }
            case 'V':
                result += 5;
                break;       
            case 'I':{
                if(i < len-1){
                    if(s[i+1] == 'X'){
                        result += 9;
                        ++i;
                        continue;
                    }
                    else if(s[i+1] == 'V'){
                        result += 4;
                        ++i;
                        continue;
                    }
                    else{
                        result += 1;
                    }
                }
                else
                    result += 1;
                break;
            }
        }   
    }
    return result;
}

