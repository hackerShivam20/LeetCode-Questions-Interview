class Solution {
public:
    bool isCircularSentence(string sentence){
        int n = sentence.length();

        if(sentence[0] != sentence[n-1]) return false;

        for(int i=1;i<n-2;i++){
            if(sentence[i+1] == ' '){
                if(sentence[i] != sentence[i+2]) return false;
            }
        }
        return true;
    }
};