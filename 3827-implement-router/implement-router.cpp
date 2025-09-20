// Helper to combine packet attributes into a string key for duplicate detection.
string makeKey(int source, int destination, int timestamp) {
    ostringstream oss;
    oss << source << "-" << destination << "-" << timestamp;
    return oss.str();
}

class Router {
private:
    int memoryLimit;
    // Queue to store packets in FIFO order; each packet is represented as a tuple.
    queue<tuple<int,int,int>> packetQueue;
    // Set for duplicate detection.
    unordered_set<string> packetSet;
    // Mapping from destination to sorted vector of timestamps.
    unordered_map<int, vector<int>> destMap;
    
    // Remove the oldest packet.
    void removeOldestPacket() {
        if (!packetQueue.empty()) {
            auto [source, destination, timestamp] = packetQueue.front();
            packetQueue.pop();
            string key = makeKey(source, destination, timestamp);
            packetSet.erase(key);
            // Remove timestamp from destination map.
            auto &vec = destMap[destination];
            if (!vec.empty() && vec.front() == timestamp) {
                vec.erase(vec.begin());
            } else {
                // In case it's not at the beginning, remove by value.
                auto it = find(vec.begin(), vec.end(), timestamp);
                if(it != vec.end()){
                    vec.erase(it);
                }
            }
        }
    }
    
public:
    Router(int memoryLimit): memoryLimit(memoryLimit) { }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);
        // Check for duplicate.
        if(packetSet.find(key) != packetSet.end())
            return false;
        
        // If memory limit is reached, remove the oldest packet.
        if(packetQueue.size() >= (size_t)memoryLimit){
            removeOldestPacket();
        }
        
        // Add the new packet.
        packetQueue.push({source, destination, timestamp});
        packetSet.insert(key);
        // Since packets arrive in non-decreasing order, append the timestamp.
        destMap[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(packetQueue.empty())
            return {};
        auto [source, destination, timestamp] = packetQueue.front();
        packetQueue.pop();
        string key = makeKey(source, destination, timestamp);
        packetSet.erase(key);
        auto &vec = destMap[destination];
        if(!vec.empty() && vec.front() == timestamp){
            vec.erase(vec.begin());
        } else{
            auto it = find(vec.begin(), vec.end(), timestamp);
            if(it != vec.end()){
                vec.erase(it);
            }
        }
        return {source, destination, timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(destMap.find(destination) == destMap.end())
            return 0;
        auto &vec = destMap[destination];
        // lower_bound and upper_bound from algorithm (vector is sorted).
        auto lower = lower_bound(vec.begin(), vec.end(), startTime);
        auto upper = upper_bound(vec.begin(), vec.end(), endTime);
        return upper - lower;
    }
};