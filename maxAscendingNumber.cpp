#include<iostream>
#include<algorithm>
#include<array>

using namespace std;

bool isSorted(int ar[], int size) {

    if (size == 0)
        return true;   // Edge case
    for(int i = 0;i<size;i++) {
        if(ar[i+1] >= ar[i])
            continue;
        else
            return false;
    }
     return true;
}
void printArray(int a[], int count) {
    for(int i = 0;i < count;i++)
        cout<<a[i];
    cout<<endl;
}
bool checkForZero(int a[], int count) {
    for(int i = 1;i<count;i++) {
        if(a[i] == 0)
            return true;
    }
    return false;
}
void sortLastWithZero(int a[],int count) {
    if(a[0] == 0)
        count--;
    for(int i=0;i<count-1;i++) {
        a[i] = 9;
    }
    printArray(a, count-1);
}
void makeNine(int a[], int i, int count) {
    for(int j =i;j<count;j++)
        a[j] = 9;
    printArray(a,count);
}
void sortLast(int a[], int count) {
    int i;
    for( i =0;i<count;i++) {
        if(a[i+1] >= a[i])
            continue;
        else
            break;
    }
    for(int j =i;j>=0;j--) {
        a[j] = a[j] - 1;
        if(j==0)
            makeNine(a,j+1,count);
        if(a[j] >= a[j-1]) {
            makeNine(a,i+1,count);
            return;
        }
    }
}
int main() {
    int count = 0;
    int a[20];
    cout<<"Enter the size of number"<<endl;
    cin>>count;
    cout<<"Enter the number"<<endl;
    for(int i = 0; i < count;i++){
        cin>>a[i];
    }
    bool check = isSorted(a, count);
    if(check) {
        printArray(a, count);
        return 0;
    }
    else {
        bool check = checkForZero(a, count);
        if(check) {
            sortLastWithZero(a, count);
            return 0;
        }
        else {
            sortLast(a, count);
        }
    }
    return 0;
}
