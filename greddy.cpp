#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  
    int n2 = right - mid;     

    
    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] >= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

   
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

       
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

       
        merge(arr, left, mid, right);
    }
}


void coinChangeGreedy(vector<int>& coins, int amount) {
    mergeSort(coins, 0, coins.size() - 1); 

    
    vector<int> coinCount(coins.size(), 0);

    for (int i = 0; i < coins.size(); ++i) {
        if (amount >= coins[i]) {
            coinCount[i] = amount / coins[i];  
            amount = amount % coins[i];       
        }
    }

    for (int i = 0; i < coins.size(); ++i) {
        if (coinCount[i] > 0) {
            cout << "Jumlah Keping " << coins[i] << "-an sebanyak : " << coinCount[i] << endl;
        }
    }
}


void coinChangeKnapsack(vector<int>& coins, int amount) {
    int n = coins.size();

    
    vector<int> dp(amount + 1, INT_MAX);  
    dp[0] = 0;  

  
    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < n; ++j) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[amount] == INT_MAX) {
        cout << "Tidak bisa ditukar dengan koin yang ada!" << endl;
    } else {
        cout << "Jumlah koin minimum yang dibutuhkan (Knapsack): " << dp[amount] << endl;
    }
}

int main() {
    int n, amount;

    cout << "***** Penukaran Koin dengan Algoritma Greedy dan Knapsack *****" << endl;

    cout << "Tuliskan Banyaknya Koin : ";
    cin >> n;

    vector<int> coins(n);

    cout << "Masukan Jenis Koin : " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

 
    cout << "Masukan Nilai yang ditukarkan : ";
    cin >> amount;

    cout << "\n***** Hasil Algoritma Greedy *****" << endl;
    coinChangeGreedy(coins, amount);

   
    cout << "\n***** Hasil Algoritma Knapsack *****" << endl;
    coinChangeKnapsack(coins, amount);

    cout << "Andika Dwi Putra" << endl;
    cout << "NIM       : 23533795" << endl;
    cout << "Kelas     : 4B" << endl;
    return 0;
}
