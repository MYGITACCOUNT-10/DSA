class TaskManager {
private:
    // Map: taskId -> (userId, priority)
    unordered_map<int, pair<int, int>> taskMap;
  
    // Set to maintain tasks sorted by priority (descending) and taskId (descending)
    // Stores pairs of (-priority, -taskId) for automatic sorting
    set<pair<int, int>> prioritySet;

public:
   
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    
    void add(int userId, int taskId, int priority) {
        // Store task information in the map
        taskMap[taskId] = {userId, priority};
      
        // Insert into set with negative values for descending order
        // Higher priority and higher taskId will come first
        prioritySet.insert({-priority, -taskId});
    }

    
    void edit(int taskId, int newPriority) {
        // Get current task information
        auto [userId, oldPriority] = taskMap[taskId];
      
        // Remove old entry from the priority set
        prioritySet.erase({-oldPriority, -taskId});
      
        // Insert new entry with updated priority
        prioritySet.insert({-newPriority, -taskId});
      
        // Update the task map with new priority
        taskMap[taskId] = {userId, newPriority};
    }

    
    void rmv(int taskId) {
        // Get task information before removal
        auto [userId, priority] = taskMap[taskId];
      
        // Remove from priority set
        prioritySet.erase({-priority, -taskId});
      
        // Remove from task map
        taskMap.erase(taskId);
    }

    int execTop() {
        // Check if there are any tasks to execute
        if (prioritySet.empty()) {
            return -1;
        }
      
        // Get the highest priority task (first element in set)
        auto topTask = *prioritySet.begin();
        prioritySet.erase(prioritySet.begin());
      
        // Extract taskId (negate to get original value)
        int taskId = -topTask.second;
      
        // Get userId from the task map
        int userId = taskMap[taskId].first;
      
        // Remove task from map
        taskMap.erase(taskId);
      
        return userId;
    }
};