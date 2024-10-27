#pragma once
#include<string>
#include<vector>

std::string dayOfTheWeek(int day, int month, int year) {
    //std::vector<string> daysOfWeek {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    std::vector<std::string> zellerMap {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    if(month == 1 || month == 2){
        month += 12;
        year -= 1;
    }
    int K = year % 100; // year of the century
    int J = year / 100; // zero-based century

    int f = day + ((13*(month + 1)) / 5) + K + (K/4) + (J/4) - 2*J;
    int dayindex = ((f + 6) % 7 + 7) % 7; // ensure dayindex positive
    //return daysOfWeek[dayindex];
    return zellerMap[((f % 7) + 7 ) % 7];
}