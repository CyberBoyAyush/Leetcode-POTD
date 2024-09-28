class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // finding first event that starts on or after the start time
        auto it = st.lower_bound({start,end});

        // chekc with next event
        if(it != st.end() && it->first<end){
            return false;
        }


        // check with past event
        if(it != st.begin()){
            auto prevIt = prev(it);

            if(start < prevIt->second){
                return false;
            }
        }

        st.insert({start,end}); // insert in set
        return true;
    }
};
