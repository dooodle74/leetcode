#include <vector>
#include <iostream>
using namespace std;

int main(){
    string s = "AABABBA";
    int k = 1;
    
    if (s.size() < 2){
        return 1;
    }

    vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 
    'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int maxLength {0};
    
    for (char target : alphabet) {
        int left {0};
        int replaced {0};

        for (int right = 0; right < s.size(); right++){
            if (s[right] != target){
                replaced++;
            }
            while (replaced > k){
                // check current left first...
                if (s[left] != target){
                    replaced--;
                }
                // ..before going to next 
                left++;
            }
            maxLength = max(maxLength, right-left+1);
        }
        // this letter done
    }
    return maxLength;
}