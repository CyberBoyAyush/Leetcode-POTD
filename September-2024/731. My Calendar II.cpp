class MyCalendarTwo {
public:
    vector<pair<int,int>> doubleBookings;
    vector<pair<int,int>> allBookings;

    bool checkOverlap(int a1, int b1, int a2,int b2){
        return max(a1, a2) < min(b1, b2); 
    }

    pair<int,int> findRegion(int a1, int b1, int a2,int b2){
        return {max(a1, a2), min(b1, b2)};
    }
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // check for triple booking
        for(auto region : doubleBookings){
            if(checkOverlap(region.first, region.second, start,end)){
                return false; // tripple overlap found
            }
        }

        // now if not triple than chekc for double booking
        for(auto booking : allBookings){
            if(checkOverlap(booking.first,booking.second, start,end)){
                doubleBookings.push_back(findRegion(booking.first,booking.second, start,end));
            }
        }

        // other wise no overlap can push it
        allBookings.push_back({start,end});
        return true;
    }
};
