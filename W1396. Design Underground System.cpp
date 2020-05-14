class UndergroundSystem {
public:
    //站点时间哈希表 startstation，endstation，totaltime，count行程数目
    unordered_map<string, unordered_map<string, pair<int, int>>> stationMap;
    //乘客乘车信息哈希表，id，stationName,time
	unordered_map<int, pair<string, int> > userMap;
    UndergroundSystem() {

    }
    
    void checkIn(int id, string stationName, int t) {
        userMap[id].first = stationName;
        userMap[id].second = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        int time = t - userMap[id].second;
        string startStation = userMap[id].first;
        stationMap[startStation][stationName].first += time;
        stationMap[startStation][stationName].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double totalTime = stationMap[startStation][endStation].first;
        double count = stationMap[startStation][endStation].second;
        return totalTime / count;
    }
};