// 各种排序

#include <iostream>

using namespace std;

const int maxn = 15, n = 10;
int a[maxn] = {0, 10, 4, 7, 1, 5, 3, 9, 7, 8, 2};

void selectionSort() {
    for (int i = 1; i <= n; i++) {
        int minPos = i;
        for (int j = i + 1; j <= n; j++) {
            if (a[minPos] > a[j]) {
                minPos = j;
            }
        }
        swap(a[minPos], a[i]);
    }
}

void insertSort() {
    for (int i = 2; i <= n; i++) {
        // 需要插到前面的位置去
        if (a[i - 1] > a[i]) {
            int val = a[i], j = i;
            while (j > 1 && a[j - 1] > val) {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = val;
        }
    }
}

void bubbleSort() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void quickSort(int curl, int curr) {
    int mid = a[curl + curr >> 1];
    int l = curl, r = curr;
    do {
        while (a[l] < mid) l++;
        while (a[r] > mid) r--;
        if (l <= r) {
            swap(a[l], a[r]);
            l++, r--;
        }
    } while (l <= r);
    if (curl < r) quickSort(curl, r);
    if (l < curr) quickSort(l, curr);
}

int c[20], ans = 0;

void mergeSort(int curl, int curr) {
    if (curl == curr) return;
    int mid = curl + curr >> 1, i = curl, j = mid + 1, k = curl;
    mergeSort(curl, mid), mergeSort(mid + 1, curr);
    while (i <= mid && j <= curr) {
        if (a[i] <= a[j]) c[k++] = a[i++];
        else c[k++] = a[j++], ans += mid - i + 1;
    }
    while (i <= mid) c[k++] = a[i++];
    while (j <= curr) c[k++] = a[j++];
    for (int i = curl; i <= curr; i++) a[i] = c[i];
}

void print() {
    for (int i = 1; i <= 10; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    // 选择排序
    // selectionSort();
    // 插入排序
    // insertSort();
    // 冒泡排序
    // bubbleSort();
    // 快速排序
    // quickSort(1, n);
    // 归并排序
    mergeSort(1, n);
    print();
    return 0;
}