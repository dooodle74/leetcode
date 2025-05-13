#include <map>
#include <vector>
#include <iostream>
using namespace std;

// vector<int> majorityElement(vector<int>& nums) {
       
int main() {
    // vector<int> nums = {1,2,1,2,2,3,3,1};  
    vector<int> nums = {2,1,1,3,1,4,5,6};

    int threshold = nums.size()/3;
        int negative_threshold = -static_cast<int>(nums.size()) / 3; // stupid ahh size_t behavior
        // ans1 loop
        int ans1;
        int count {0};
        for (int x : nums){
            if (x == ans1){
                count++;
            } else if (count <= negative_threshold){
                ans1 = x;
                count = 1;
            } else {
                count--;
            }
        }

        // ans2 loop
        int ans2;
        count = 0;
        for (int x : nums){
            if (x == ans1){
                continue;
            }
            if (count == 0){
                ans2 = x;
                count = 1;
            } else if (x == ans2){
                count++;
            } else {
                count--;
            }
        }

        cout << "ans1: " << ans1 << endl;
        cout << "ans2: " << ans2 << endl;
        
        // verify
        int num1_total {0};
        int num2_total {0};
        for (int x : nums){
            if (x == ans1){
                num1_total++;
            } else if (x == ans2) {
                num2_total++;
            }
        }
        vector<int> ans;
        if (num1_total > threshold) {
            ans.push_back(ans1);
        }
        if (num2_total > threshold) {
            ans.push_back(ans2);
        }

        return 0;

}