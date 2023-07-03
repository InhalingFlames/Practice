#include <iostream>     // test output to visually indicate the noraml flow of programm
#include <windows.h>    // for pausing the console
#include <fstream> //работа с файлами
#include <ctime> // генератор случайных чисел
#include <iomanip>

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

void FileHandling(int array[], int n, string name) {
    ofstream f(name.c_str());
    if (f.is_open()) {
        for (int i = 0; i < n; i++)
            f << array[i] << endl;
        f.close();
        }
    else cout << "Ошибка записи в файл " << name.c_str() << endl;   
}

int main() {
    int i, n;

    cout << "Введите размер массива (>1): " << endl;
    do {
        cout << "size = ";
        cin >> n;
        if ( (!(cin.good())) || (n < 2) ) {
            cout << "Неверно введен размер массива size " << endl;
            cin.clear();
            cin.get();
        }
    } while ((!(cin.good())) || (n < 2));

    int *arr = new int[n];
    string name1 = "input.txt";
    string name2 = "output.txt";

    // создание случайного массива
    for( int a1=0; a1 < n; a1++) {
        arr[a1] = (rand() % 2001) - 1000;
    }

    FileHandling(arr, n, name1); // запись в файл

    // вычисление времени работы
    time_t start = clock();
    ShellSort(arr, n);
    time_t stop = clock();
    double time = (stop - start) / 1000.0;

    FileHandling(arr, n, name2);

    cout << endl << "Время выполнения сортировки - " << time << " секунд " << endl;

    system("pause");
    return 0;
}