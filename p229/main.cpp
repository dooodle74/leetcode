#include <map>
#include <vector>
#include <iostream>
using namespace std;

// vector<int> majorityElement(vector<int>& nums) {
       
int main() {
    // vector<int> nums = {1,2,1,2,2,3,3,1};  
    vector<int> nums = {2,1,1,3,1,4,5,6};

    int threshold = nums.size()/3;
        int ans1 {0};
        int ans2 {0};
        int count1 {0};
        int count2 {0};

        for (int x : nums) {
            if (x == ans1){
                count1++;
            } else if (x == ans2) {
                count2++;
            } else if (count1 == 0){
                ans1 = x;
                count1 = 1;
            } else if (count2 == 0){
                ans2 = x;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        cout << "ans1: " << ans1 << endl;
        cout << "ans2: " << ans2 << endl;

        count1 = 0;
        count2 = 0;
        for (int x : nums){
            if (x == ans1){
                count1++;
            } else if (x == ans2) {
                count2++;
            }
        }
        vector<int> ans;
        if (count1 > threshold) {
            ans.push_back(ans1);
        }
        if (count2 > threshold) {
            ans.push_back(ans2);
        }

}