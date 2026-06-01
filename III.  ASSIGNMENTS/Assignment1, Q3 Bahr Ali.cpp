#include <iostream>
using namespace std;

class Day{
    private:
    string days[7] = {"Mon","Tue","Wed","Thur","Fri","Sat","Sun"};

int currentDay;

int findCurrentday(string d){
    for(int i = 0; i<7; ++i){
        if(days[i]==d) return i;
    }
    return 0;
}

public:
Day(string d= "Sun"){
    currentDay = findCurrentday(d);
}
void setDay(string d){
    currentDay = findCurrentday(d);
}

void printDay() const {
    cout << days[currentDay] << endl;
}

string getDay() const {
    return days[currentDay];
}
string nextDay() const{
    return days[(currentDay + 1) % 7];
}
string prevDay() const {
    return days[(currentDay + 6)%7];
}
string addDays(int n) const {
    return days[(currentDay + n) % 7];
}

};

int main(){
    Day today("Mon");

    cout <<"Today is                      : "; today.printDay();
    cout <<"Next day                      : "; cout<<today.nextDay() << endl;
    cout <<"Previous day                  : "; cout<<today.prevDay() << endl;
    cout <<"Adding 4 days                 : "; cout<<today.addDays(4) << endl;
    cout <<"Adding 13 days (from tuesday) : "; Day tuesday("Tue"); cout<<tuesday.addDays(13) << endl;



return 0;
}