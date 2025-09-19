class Spreadsheet {
private:
    unordered_map<string,int>cellvalues;
public:
    Spreadsheet(int rows) {
        //No initialization required for hashmap
        
    }
    
    void setCell(string cell, int value) {
        cellvalues[cell]=value;
        
    }
    
    void resetCell(string cell) {

        cellvalues.erase(cell);
        
    }
    

    int getValue(string formula) 
    { int result = 0;
      
        // Remove the '=' prefix and create a string stream for parsing
        stringstream formulaStream(formula.substr(1));
        string token;
      
        // Parse the formula by splitting on '+' delimiter
        while (getline(formulaStream, token, '+')) {
            // Check if token is a numeric value
            if (isdigit(token[0])) {
                // Convert string to integer and add to result
                result += stoi(token);
            } else {
                // Token is a cell reference
                // Add cell value if it exists, otherwise add 0
                result += cellvalues.count(token) ? cellvalues[token] : 0;
            }
        }

        return result;
    }
    
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */