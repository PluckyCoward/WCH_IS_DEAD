class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> map={{"Jan","01"},{"Feb","02"},{"Mar","03"},{"Apr","04"},{"May","05"},{"Jun","06"},{"Jul","07"},{"Aug","08"},{"Sep","09"},{"Oct","10"},{"Nov","11"},{"Dec","12"}};
        string day, month, year;
        year = date.substr(date.length() - 4, 4);
        month = map[date.substr(date.length() - 8, 3)];
        day = date.substr(0, date.length() - 11);
        if(day.length() == 1)
            day = '0'+day;
        return year + '-' + month + '-' + day;
    }
};