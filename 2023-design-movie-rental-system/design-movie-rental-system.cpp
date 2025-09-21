class MovieRentingSystem {

    // Store unrented movies: movie_id -> sorted set of (price, shop_id)
    unordered_map<int,set<pair<int, int>>> unrented;
  
    // Store price lookup: (shop_id, movie_id) -> price
    map<pair<int, int>, int> shopAndMovieToPrice;
  
    // Store currently rented movies: sorted set of (price, shop_id, movie_id)
    set<tuple<int, int, int>> rented;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {

        for(auto &entry:entries)
        {
            int shop_id=entry[0];
            int movie_id=entry[1];
            int price=entry[2];

            unrented[movie_id].insert({price,shop_id});
            shopAndMovieToPrice[{shop_id, movie_id}] = price;
        }
        
    }
    
    vector<int> search(int movie) {

        if(unrented.find(movie)==unrented.end()) return {};

        vector<int>result;
        int count=1;
        for (const auto& [price, shop] : unrented[movie]) 
        {
            if (count >5) break;
            result.push_back(shop);
            count++;
            
        }

        return result;
    }


    
    void rent(int shop, int movie) {

        int price= shopAndMovieToPrice[{shop,movie}];

        //remove from the specific movie of specific shopn adn price from unrented
        unrented[movie].erase({price, shop});

        rented.insert({price,shop,movie});
        
    }
    
    void drop(int shop, int movie) {

        // Get the price for this shop-movie combination
        int price = shopAndMovieToPrice[{shop, movie}];

        // Remove from rented inventory
        rented.erase({price, shop, movie});

        // Add back to unrented inventory
        unrented[movie].insert({price, shop});
      
      

        
    }
    
    vector<vector<int>> report() {

        vector<vector<int>> result;
        int count=0;

        if(!rented.empty())
        {
            for(auto &[price, shop_id, movie_id]:rented)
            {   
                if(count>=5) break;
                result.push_back({shop_id,movie_id});
                count++;
            }
           
        }

        return result;
        
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */