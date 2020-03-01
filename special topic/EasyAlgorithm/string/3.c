int firstUniqChar(char * s){
    char* slow = s;
    char* fast = s;
    while(slow[0] && fast[0]){
        if(slow[0] == fast[0] && slow != fast){
            slow++;
            fast = s;
        }
        else{
            fast++;
        }
    }
    if(!slow[0]) return -1;
    return (slow - s); 
}

