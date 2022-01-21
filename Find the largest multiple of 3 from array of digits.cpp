// Find the largest multiple of 3 from array of digits
// https://leetcode.com/problems/largest-multiple-of-three/
// https://www.youtube.com/watch?v=3GsK-H_dI9o
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int sum=0;
        int n=digits.size();
        sort(digits.begin(),digits.end());
        for(int i=0;i<n;i++){
            sum+=digits[i];
        }
        
        
        
        if(sum%3==0){
            if(digits[n-1]==0){
                return "0";
            }
            string ans="";
            for(int i=n-1;i>=0;i--){
                ans+=digits[i]+'0';
            }
            return ans;
        }
        else if(sum%3==1){
            bool idealFound=false;
            for(int i=0;i<n;i++){
                if(digits[i]%3==1){
                    idealFound=true;
                    digits[i]=-1;
                    break;
                }
            }
            
            if(!idealFound){
                int idxs[2];
                idxs[0]=-1;
                idxs[1]=-1;
                for(int i=0;i<n;i++){
                    if(digits[i]%3==2){
                        if(idxs[0]==-1){
                            idxs[0]=i;
                        }
                        else{
                            idxs[1]=i;
                        }
                    }
                }
                
                if(idxs[1]!=-1){
                    digits[idxs[0]]=-1;
                    digits[idxs[1]]=-1;
                }
                else{
                    return "";
                }
            }
        }
        else if(sum%3==2){
            bool idealFound=false;
            for(int i=0;i<n;i++){
                if(digits[i]%3==2){
                    idealFound=true;
                    digits[i]=-1;
                    break;
                }
            }
            
            if(!idealFound){
                int idxs[2];
                idxs[0]=-1;
                idxs[1]=-1;
                for(int i=0;i<n;i++){
                    if(digits[i]%3==1){
                        if(idxs[0]==-1){
                            idxs[0]=i;
                        }
                        else{
                            idxs[1]=i;
                        }
                    }
                }
                
                if(idxs[1]!=-1){
                    digits[idxs[0]]=-1;
                    digits[idxs[1]]=-1;
                }
                else{
                    return "";
                }
            }
        }
        
        string ans="";
        for(int i=n-1;i>=0;i--){
            if(digits[i]!=-1){
                if(ans.length()==1 && ans[0]=='0' && digits[i]==0){
                    continue;
                }
                ans+=digits[i]+'0';
            }
        }
        return ans;
    }
};

