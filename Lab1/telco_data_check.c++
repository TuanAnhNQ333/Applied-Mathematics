#include "bits/stdc++.h"
#include<iostream>
#include <sstream>
using namespace std;

struct CallLog {
    string from_number;
    string to_number;
    string date;
    string from_time;
    string end_time;
};

// Hàmkiểmtratínhhợplệcủasốđiệnthoại
bool isValidPhoneNumber(const string& number) {
    if (number.size()!= 10) return false;
    for (int i = 0; i<number.size(); i++) {
        if (!(number[i] >= '0' && number[i] <= '9')) return false;
    }
    return true;
}

// Hàmtínhtổngthờigiancuộcgọitheogiây
int calculateDuration(const string& start, const string& end) {
    int startTime=  3600*((start[0]-'0')*10 + start[1]-'0')
                    + 60*((start[3]-'0')*10 + start[4]-'0')
                    + ((start[6]-'0')*10 + start[7]-'0');
    int endTime=  3600*((end[0]-'0')*10 + end[1]-'0')
                    + 60*((end[3]-'0')*10 + end[4]-'0')
                    + ((end[6]-'0')*10 + end[7]-'0');
    return endTime - startTime;
}

int main() {
    vector<CallLog>logs;
    unordered_map<string, int>calls_from;
    unordered_map<string, long long>total_time_from;
    string line;


    while (true) {
        getline(cin, line);
        if (line == "#") break;
        if (line.find("call") == 0) {
        stringstream ss(line);
            string keyword, from_number, to_number, date, from_time, end_time;
            ss >> keyword >>from_number>>to_number>> date >>from_time>>end_time;

        logs.push_back({from_number, to_number, date, from_time, end_time});
        calls_from[from_number]++;
        total_time_from[from_number] += calculateDuration(from_time, end_time);
        }
    }

    while (true) {
        cin>>line;
        if (line == "#") break;
        if (line == "?check_phone_number") {
            bool all_valid = true;
            for (const auto&log : logs) {
                if (!isValidPhoneNumber(log.from_number) || !isValidPhoneNumber(log.to_number)) {
        all_valid = false;
        break;
                }
            }
        cout<< (all_valid ?1 : 0) <<endl;
        } else if (line == "?number_calls_from") {
            string phone_number;
        cin>>phone_number;
        cout<<calls_from[phone_number] <<endl;
        } else if (line == "?number_total_calls") {
        cout<<logs.size() <<endl;
        } else if (line == "?count_time_calls_from") {
            string phone_number;
cin>>phone_number;
cout<<total_time_from[phone_number] <<endl;
        }
    }

    return 0;
}

