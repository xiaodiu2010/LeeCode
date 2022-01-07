
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i=0; i < nums.size(); i++){
            int val = nums[i];
            int val_t = target - val;
            auto found = map.find(val_t);
            if(found != map.end()){
                return {map.at(val_t), i};
            } 
            map[val] = i;
        }
        return {-1,-1};
    }
};