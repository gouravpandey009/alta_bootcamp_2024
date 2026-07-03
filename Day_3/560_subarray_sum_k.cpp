#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {

    unordered_map<int, int> prefixFrequency;

    prefixFrequency[0] = 1;

    int currentPrefix = 0;
    int totalSubarrays = 0;

    for (int number : nums) {

        currentPrefix += number;

        int requiredPrefix = currentPrefix - k;

        if (prefixFrequency.find(requiredPrefix) != prefixFrequency.end()) {
            totalSubarrays += prefixFrequency[requiredPrefix];
        }

        prefixFrequency[currentPrefix]++;
    }

    return totalSubarrays;
}

int main() {

    vector<int> nums = {1,1,1};

    int k = 2;

    cout << subarraySum(nums, k);

    return 0;
}