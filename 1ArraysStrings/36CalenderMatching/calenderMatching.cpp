#include <bits/stdc++.h>
using namespace std;

struct StringMeeting {
  string start;
  string end;
};

struct Meeting {
    int start;
    int end;
    Meeting(int start,int end) {
        this->start=start;
        this->end=end;
    }
};

int timeToMins(string time) {
    int idx = time.find(":");
    string hour = time.substr(0,idx);
    string mins = time.substr(idx+1);
    return stoi(hour)*60+stoi(mins);
}

vector<Meeting> getUpdatedCalender(vector<StringMeeting> calender,StringMeeting dailyBounds) {
    calender.insert(calender.begin(),StringMeeting({"00:00",dailyBounds.start}));
    calender.push_back(StringMeeting({dailyBounds.end,"23:59"}));
    vector<Meeting> newCalender;
    for(auto time : calender)
        newCalender.push_back(Meeting(timeToMins(time.start),timeToMins(time.end)));
    return newCalender;
}

vector<Meeting> getMergedCalender(vector<Meeting> calender1, vector<Meeting> calender2) {
    int i=0,j=0;
    vector<Meeting> newCalender;
    while(i<calender1.size() && j<calender2.size())
        if(calender1[i].start<calender2[j].start)
            newCalender.push_back(calender1[i++]);
        else
            newCalender.push_back(calender2[j++]);
    while(i<calender1.size())
        newCalender.push_back(calender1[i++]);
    while(j<calender2.size())
        newCalender.push_back(calender2[j++]);
    return newCalender;
}

vector<Meeting> getFlattenedCalender(vector<Meeting> calender) {
    for(int i=1;i<calender.size();) {
        if(calender[i-1].end>=calender[i].start){
            calender[i-1].end=max(calender[i].end,calender[i-1].end);
            calender.erase(calender.begin()+i);
        } else
            i++;
    }
    return calender;
}

vector<Meeting> getFreeSlots(vector<Meeting> calender,int timeslot) {
    vector<Meeting> freeSlots;
    for(int i=1;i<calender.size();i++)
        if(calender[i].start-calender[i-1].end>=timeslot)
            freeSlots.push_back(Meeting(calender[i-1].end,calender[i].start));
    return freeSlots;
}

string minsToTime(int time) {
    string hours = to_string(time/60);
    string mins = (time%60<10)?"0"+to_string(time%60):to_string(time%60);
    return hours+":"+mins;
}

vector<StringMeeting> getStringifiedCalender(vector<Meeting> calender) {
    vector<StringMeeting> newCalender;
    for(auto time : calender)
        newCalender.push_back({minsToTime(time.start),minsToTime(time.end)});
    return newCalender;
}

vector<StringMeeting> calendarMatching(vector<StringMeeting> calendar1,StringMeeting dailyBounds1,
    vector<StringMeeting> calendar2,StringMeeting dailyBounds2,int meetingDuration) {
    vector<Meeting> updatedCalender1 = getUpdatedCalender(calendar1,dailyBounds1);
    vector<Meeting> updatedCalender2 = getUpdatedCalender(calendar2,dailyBounds2);
    vector<Meeting> mergedCalender = getMergedCalender(updatedCalender1,updatedCalender2);
    vector<Meeting> flattenCalender = getFlattenedCalender(mergedCalender);
    vector<Meeting> freeSlots = getFreeSlots(flattenCalender,meetingDuration);
    vector<StringMeeting> resultCalender = getStringifiedCalender(freeSlots);
    return resultCalender;
}

bool compareCalendars(vector<StringMeeting> calendar1,
                      vector<StringMeeting> calendar2) {
  if (calendar1.size() != calendar2.size()) {
    return false;
  }
  for (int i = 0; i < calendar1.size(); i++) {
    if (calendar1[i].start != calendar2[i].start ||
        calendar1[i].end != calendar2[i].end)
      return false;
  }
  return true;
}

int main() {
    vector<StringMeeting> calendar1 = {{"9:00", "10:30"}, {"12:00", "13:00"}, {"16:00", "18:00"}};
    StringMeeting dailyBounds1 = {"9:00", "20:00"};
    vector<StringMeeting> calendar2 = {{"10:00", "11:30"},{"12:30", "14:30"},{"14:30", "15:00"},{"16:00", "17:00"}};
    StringMeeting dailyBounds2 = {"10:00", "18:30"};
    int meetingDuration = 30;
    vector<StringMeeting> expected = {{"11:30", "12:00"}, {"15:00", "16:00"}, {"18:00", "18:30"}};
    vector<StringMeeting> actual = calendarMatching(calendar1, dailyBounds1, calendar2, dailyBounds2, meetingDuration);
    cout<<(compareCalendars(expected, actual))<<endl;
    return 0;
}