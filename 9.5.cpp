#include <iostream>
using namespace std;

int search(string s[], int low, int high, string x){
    if(low > high) return -1;
    if(x == "") return -1;
    //Move mid to the middle
    int mid = (low + high) / 2;
    //If mid is empty, find closest non-empty string
    if(s[mid] == ""){
        int left = mid - 1;
        int right = mid + 1;
        while(true){
            if(left < low && right > high){
                return -1;
            } else if(right <= high && s[right] != ""){
                mid = right;
                break;
            } else if(left >= low && s[left] != ""){
                mid = left;
                break;
            }
            right++;
            left--;
        }
    }

    //Check for string, and recurse if necessary
    if(x == s[mid]){
        return mid;
    } else if(s[mid] < x){
        return search(s, mid + 1, high, x);
    } else{
        return search(s, low, mid - 1, x);
    }
}

int main(){
    string s[13] = {
        "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""
    };
    cout<<search(s, 0, 12, "ball")<<endl;
    return 0;
}
