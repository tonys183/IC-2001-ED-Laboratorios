#include <iostream>
using namespace std;

int quickSortSheeps(int sheepsDogs[], string nameDogs[], int start, int end){
    int pivot=sheepsDogs[end];
    int i=(start-1);

    for(int j=start;j<=end-1;j++){
        if(sheepsDogs[j]>pivot){
            i++;
            swap(sheepsDogs[i],sheepsDogs[j]);
            swap(nameDogs[i],nameDogs[j]);
        }
    }
    swap(sheepsDogs[i+1],sheepsDogs[end]);
    swap(nameDogs[i+1],nameDogs[end]);
    return (i+1);
}

int quickSortNames(string printNames[], int start, int end){
    string pivot=printNames[end];
    int i=(start-1);

    for(int j=start;j<=end-1;j++){
        if(printNames[j]<pivot){
            i++;
            swap(printNames[i],printNames[j]);
        }
    }
    swap(printNames[i+1],printNames[end]);
    return (i+1);
}
       
void solveSheeps(int sheepsDogs[], string nameDogs[], int start, int end){
    if(start<end){
        int quick=quickSortSheeps(sheepsDogs,nameDogs,start,end);
        solveSheeps(sheepsDogs,nameDogs,start,quick-1);
        solveSheeps(sheepsDogs,nameDogs,quick+1,end);
    }
}
       
void solveNames(string printNames[], int start, int end){
    if(start<end){
        int quick=quickSortNames(printNames,start,end);
        solveNames(printNames,start,quick-1);
        solveNames(printNames,quick+1,end);
    }
}

int main(){
    int T, sheepsDogs[1000];
    string nameDogs[1000];
    long long int totalOvejas = 1;
    
    cin >> T;
    for(int i=0; i<T;i++) cin >> nameDogs[i] >> sheepsDogs[i];
    solveSheeps(sheepsDogs,nameDogs,0,T-1);

    int numPerros = min(T, 3);
    string printNames[numPerros];
    for (int i = 0; i < numPerros; ++i) {
        totalOvejas *= sheepsDogs[i];
        printNames[i] = nameDogs[i];
    }
    solveNames(printNames,0,numPerros-1);

    for (int i = 0; i < numPerros; ++i) {
        cout << printNames[i];
        if (i < numPerros - 1) cout << " ";
    }
    cout << " " << totalOvejas << endl;
    return 0;
}