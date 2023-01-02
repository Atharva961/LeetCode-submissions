class Solution {
public:
    bool detectCapitalUse(string word) {
        bool a = true;
        bool b = true;
        bool c = true;
        
        //Case 1
        for(char i:word)
        {
            if(islower(i))
            {
                a = false;
                break;
            }
        }
        
        //Case 2
        for(char i:word)
        {
            if(isupper(i))
            {
                b = false;
                break;
            }
        }
                
        //Case 3
        if(!isupper(word[0])) c = false;
        else
        {
            for(int i=1; i<word.size(); i++)
            {
                if(isupper(word[i]))
                {
                    c = false;
                    break;
                }
            }
        }
        
        return a||b||c;
    }
};