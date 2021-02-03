
int lengthOfLongestSubstring(char *s){
    bool table[128] = {false};      //stores if we've seen an ascii character
    char *start=s, *end=s;
    int max=0;
    
    while(*end){                    //have not reached '\0' null terminator
        if(table[*end]){            //if character has been seen before
            if(end-start > max)
                max = end-start;    //use mem address difference as number of chars
            
            while (*start != *end) {        //iterate from start to end character
                table[*start] = false;      //remove any table chars before duplicate char
                ++start;
            }
            
            ++start;                //iterate again to skip over duplicate
            ++end;                  //new end, have already checked last endpoint
        }
        else{
            table[*end] = true;
            ++end;
        }
    }
    
    if(end-start > max)
        return end-start;
    else
        return max;
}