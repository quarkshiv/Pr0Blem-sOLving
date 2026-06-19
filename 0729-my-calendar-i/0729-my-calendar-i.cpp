class MyCalendar {
public:
vector<vector<int>>ans;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
       for(auto it : ans){
             if(startTime<it[1] && endTime>it[0])return false;
       }
       ans.push_back({startTime,endTime});
       return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */