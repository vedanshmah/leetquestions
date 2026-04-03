class EventManager {
public:
    set<pair<int,int>> st;
    unordered_map<int,int> mp;
    EventManager(vector<vector<int>>& events) {
        for(auto &event:events){
            int eid=event[0];
            int prio=event[1];
            mp[eid]=prio;
            st.insert({-prio,eid});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int oldprio=mp[eventId];
        st.erase({-oldprio,eventId});
        st.insert({-newPriority,eventId});
        mp[eventId]=newPriority;
    }
    
    int pollHighest() {
        if(st.empty()) return -1;
        auto it=st.begin();
        int eid=it->second;
        st.erase(it);
        mp.erase(eid);
        return eid;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */