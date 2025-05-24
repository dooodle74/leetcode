#include <vector>
#include <map>
#include <iostream>
using namespace std;

int main(){
    string s = "AABABBA";
    int k=1;
    if (s.size() < 2){
        return 1;
    }
    // init a map of all chars, dynamically update and determine max in each window
    unordered_map<char, int> counts;
    // know which letter is most frequent - just keep track of count
    // no need keep track replaced count - just check if valid for each window

    int maxLength {0};
    int left {0};
    int maxFrequency {0}; // do not care which one

    for (int right = 0; right < s.size(); right++){
        // loop does the left shift - update current target
        counts[s[right]]++;
        maxFrequency = max(maxFrequency, counts[s[right]]);
        
        // valid window iff size - maxFreq <= k
        // we do not care about updating max-frequency (it cannot go higher)
        // take care of updating in next loop iter
        while (right-left+1 - maxFrequency > k){
            counts[s[left]]--;
            left++;
        }
        maxLength = max(maxLength, right-left+1);
    }

    return maxLength;
}