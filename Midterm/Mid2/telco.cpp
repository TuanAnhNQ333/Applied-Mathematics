#include<iostream>
#include<string>
#include<map>
using namespace std;
bool checkPhoneNumber(string pNum) {
    if(pNum.length() != 10) return false;
    for(auto a : pNum) {
        if(a < '0' || a > '9') {
            return false;
        }
    }
    return true;
}
int countTimeInt(string fTime, string eTime) {
    int start =  3600*((fTime[0]-'0')*10 + fTime[1]-'0')
                    + 60*((fTime[3]-'0')*10 + fTime[4]-'0')
                    + ((fTime[6]-'0')*10 + fTime[7]-'0');
    int end =  3600*((eTime[0]-'0')*10 + eTime[1]-'0')
                    + 60*((eTime[3]-'0')*10 + eTime[4]-'0')
                    + ((eTime[6]-'0')*10 + eTime[7]-'0');
    return end - start;
}
map<string, int> numberCalls;
map<string, int> timeCallFrom;
int checkPhone = 1; int numCall = 0;
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string type; cin>>type;
    while(type != "#") {
        string fNum, tNum, date, fTime, eTime;
        cin>>fNum>>tNum>>date>>fTime>>eTime;
        if(!checkPhoneNumber(fNum) || !checkPhoneNumber(tNum)) {
            checkPhone = 0;
        }
        numCall ++;
        numberCalls[fNum] ++;
        timeCallFrom[fNum] += countTimeInt(fTime, eTime);
        cin>>type;           
    }    
    cin>>type;
    while(type!="#") {
        if(type == "?check_phone_number") 
            { cout << checkPhone << endl;}
        else if(type == "?number_total_calls") 
            { cout << numCall << endl;}
        else if(type == "?number_calls_from") 
            {string num; cin >> num;
            cout << numberCalls[num] << endl;}
        else if(type == "?count_time_calls_from") 
            {string num; cin >> num;
            cout << timeCallFrom[num] << endl;}
        cin >> type;
    }   
    return 0;
}                                       