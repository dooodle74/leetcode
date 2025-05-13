#include <map>
#include <vector>
#include <iostream>
using namespace std;

// vector<int> majorityElement(vector<int>& nums) {
       
int main() {
    vector<int> nums = {1,2,1,2,2,3,3,1};  

    // ans1 loop
    int ans1;
    int max_height {0};
    int count {0};
    for (int x : nums){
        if (count == 0 - max_height){
            ans1 = x;
            count = 1;
        } else if (x == ans1){
            count++;
        } else {
            count--;
        }
    }

    cout << "ans1: " << ans1 << endl;

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
    cout << "num1_total: " << num1_total << endl;
    cout << "num2_total: " << num2_total << endl;

    vector<int> ans;
    if (num1_total > nums.size()/3) {
        ans.push_back(ans1);
    }
    if (num2_total > nums.size()/3) {
        ans.push_back(ans2);
    }
    cout << "ans: ";
    for (int x : ans){
        cout << x << " ";
    }
    cout << endl;

}