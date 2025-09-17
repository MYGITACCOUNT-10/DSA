#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <utility> // Required for std::pair

using namespace std;

class FoodRatings {
private:
    
    unordered_map<string, int> FoodToRating;
    unordered_map<string, string> FoodToCuisine;
    
    unordered_map<string, set<pair<int, string>>> CuisineToFood;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {

        for (int i = 0; i < foods.size(); i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            // Populate the helper maps
            FoodToRating[food] = rating;
            FoodToCuisine[food] = cuisine;

            // Insert into the sorted set with a negative rating
            CuisineToFood[cuisine].insert({-rating, food});

            //Food will store lexicographically that is ascending order.
            //Therefore we need to store the rating in negative to sort in same manner.
            //Positive rating will lead to ascending order of the arrangement.
            //Therefore using negative to sort in descending order.
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = FoodToCuisine[food];
        int oldRating = FoodToRating[food]; // Corrected: Get the old rating

        //Removing the old entry
        CuisineToFood[cuisine].erase({-oldRating, food});

        //adding the new entry
        CuisineToFood[cuisine].insert({-newRating, food}); // Corrected: Use newRating and proper pair syntax

        //Updating the rating
        FoodToRating[food] = newRating; // Corrected: Update map with the new integer rating
    }

    string highestRated(string cuisine) {
        pair<int, string> highest = *CuisineToFood[cuisine].begin();
        return highest.second; // Corrected: Fixed typo "highes" to "highest"
    }
};

//By default, it sorts in ascending (smallest to largest) order.
//When sorting a pair<int, string>, it first compares the int values. If they are different, it
//orders the pairs based on the int. If the int values are the same, it then compares the string values alphabetically to break the tie.

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */