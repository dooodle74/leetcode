#include <map>
#include <vector>
#include <iostream>
using namespace std;

// vector<int> majorityElement(vector<int>& nums) {
       
int main() {
    // vector<int> nums = {1,2,1,2,2,3,3,1};  
    vector<int> nums = {2,1,1,3,1,4,5,6};

    // ans1 loop
    int ans1 = nums[0];
    // int max_height {0};
    int count {0};
    int iters {0};
    for (int x : nums){
        cout << "iters: " << iters++ << endl;
        cout << "x: " << x << endl;
        cout << "count: " << count << endl;
        cout << "ans1: " << ans1 << endl;
        if (count <= -static_cast<int>(nums.size()) / 3){
            cout << "if 1" << endl;
            ans1 = x;
            count = -static_cast<int>(nums.size()) / 3 ;
        } else if (x == ans1){
            cout << "if 2" << endl;
            count++;
        } else {
            cout << "if 3" << endl;
            count--;
        }
        cout << "new ans1: " << ans1 << endl;
        cout << "new count: " << count << endl;
        cout << "------------------------" << endl;
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