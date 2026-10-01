class Solution {
public:

    bool isfreqSame(int freq1[] , int freq2[]){
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }

        return true;
    }


    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i=0; i<s1.length(); i++){
            freq [s1[i] - 'a']++;

        }

        int windsize = s1.length();
        for(int i=0; i<s2.length(); i++){
            int windIdx = 0 , Idx=i;
            int windfreq[26] = {0};

            while(windIdx < windsize && Idx < s2.length()){
                windfreq[s2[Idx] - 'a']++;
                windIdx++ ; Idx++;
            }

            if(isfreqSame(freq , windfreq)){
                return true;
            }
        }
        return false;

    }
};