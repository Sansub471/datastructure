#pragma once

// 278. First Bad Version
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int n){} // Dummy to prevent compiler complain

int firstBadVersion(int n) {
    int low = 1, high = n;
    int pos = -1;
    while(low <= high ){
        int mid = low + (high - low + 1) / 2; // +1 adds bias towards high, helps faster convergence sometimes
        bool badChk = isBadVersion(mid);
        if(badChk){
            high = mid - 1;
            pos = mid;
        }else{
            low = mid + 1;
        }
    }
    return pos;
}