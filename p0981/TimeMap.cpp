using namespace std;
#include <unordered_map>
#include <vector>
#include <string>
#include <utility> // for std::pair

class TimeMap {
    private:
        unordered_map<string, vector<pair<int, string>>> items;
    public:
        TimeMap() {
            // Do nothing
        }
        
        void set(string key, string value, int timestamp) {
            pair<int, string> newEntry(timestamp, value);
            items[key].push_back(newEntry);
        }
        
        string get(string key, int timestamp) {
            if (items.find(key) == items.end()){
                return "";
            }
    
            const vector<pair<int, string>>& values = items[key];  // vector of times pairs for this item
    
            if (timestamp < values[0].first){
                return "";
            }
    
            // binary search for closest lesser time
            int low = 0;
            int high = values.size() -1;
            while (low <= high){
                int mid = (high + low) / 2;
                if (timestamp == values[mid].first){
                    return values[mid].second;
                }
                if (values[mid].first > timestamp){
                    high = mid -1;
                } else {
                    low = mid +1;
                }
            }
            // now high will store the lower value
            return values[high].second;
    
        }
    };
    
    /**
     * Your TimeMap object will be instantiated and called as such:
     * TimeMap* obj = new TimeMap();
     * obj->set(key,value,timestamp);
     * string param_2 = obj->get(key,timestamp);
     */