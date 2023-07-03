#include <iostream>     // test output to visually indicate the noraml flow of programm
#include <windows.h>    // for pausing the console

using namespace std;

int ShellSort(int arr[], int n) {
    for ( int gap = n/2; gap > 0; gap /= 2 ) {                            //    cycle for changing gap size
        for (int i = gap; i < n; ++i) {                                   //    circle thru elements from number [gap] to [n]
            int temp = arr[i];
            int j;
            for (j = i; (j >= gap) && (arr[j - gap] > temp); j -=gap ) {  //    if position of current element >= gap AND element on the "left" of the gap is
                arr[j] = arr[j - gap];                                    //    Bigger than the current one  THEN  swap them   IF NO --> choose element [j-gap]
            }
            arr[j] = temp;                                                //    actually moving stored content of the array's element
        }  
    }
    return 0;
}

int main() {
    int arr[] = {1000, 16, 1, 4, 4, 78, 0, 10, 15, 45, 12, 66, 105}, i; // example array

    int n = sizeof(arr)/sizeof(arr[0]); // calculating it's length

    ShellSort(arr, n);

    cout << "I'm Kanye East";
    system("pause");

    return 0;
}