#include <iostream>
#include <iomanip>
using namespace std;

class Fcfs{
    int n;
    public:
    Fcfs(int n){
        this->n = n;
    }
    void waitingt(int wt[], int bt[], int tat[], float &twt);
    void turnaroundt(int at[], int tat[], int bt[], int ct[], int wt[], float &ttat);

};

void Fcfs :: waitingt(int wt[], int bt[], int tat[], float &twt)
{
    for(int i=0; i<n; i++){
        wt[i] = tat[i] - bt[i];
        twt += wt[i];
    }

}
void Fcfs :: turnaroundt(int at[], int tat[], int bt[], int ct[], int wt[], float &ttat)
{
    ct[0] = bt[0];
    //calculating complition time
    for(int i=1; i<n; i++)
    {
        if(at[i] > ct[i-1])
            ct[i] = at[i] + bt[i];
        else{
            ct[i] = bt[i] + ct[i-1];
        }
    }

    //calculating turn around time
    for(int i=0; i<n; i++)
    {
        tat[i] = ct[i] - at[i];
        ttat += tat[i];
    }
}

void sorting(int pID[], int at[], int bt[], int n){
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j=i; j<n; i++){
            if(at[i] > at[j]){
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = pID[i];
                pID[i] = pID[j];
                pID[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[i] = temp;
            }
        }
    }
}

int main()
{
    int np;
    cout << "Enter the number of processes : ";
    cin >> np;
    int bt[np], at[np], tat[np], wt[np], ct[np], pID[np];
    Fcfs obj(np);
    float ttat = 0, twt = 0;
    
    for(int i=0; i<np; i++)
    {
        pID[i] = i+1;
        cout << "(Arrival Time) P[" << pID[i] << "] : ";
        cin >> at[i];
        cout << "(Burst Time) P[" << pID[i] << "] : ";
        cin >> bt[i];
    }
    sorting(pID, at, bt, np);
    obj.turnaroundt(at, tat, bt, ct, wt, ttat);
    obj.waitingt(wt, bt, tat, twt);
    cout << endl;
    cout << "===================== Processes Details =====================" << endl;
    cout << "Processes\t Arrival Time\t Burst Time\t Waiting Time\t Turn Around Time" << endl;
    for(int i=0; i<np; i++)
    {
        cout << setw(5) << "P[" << pID[i] << "] " << setw(16) << at[i] << setw(16) << bt[i] << setw(16) << wt[i] << setw(16) << tat[i] << endl; 
    }
    cout << "Average Waiting Time = " << twt/np << endl;
    cout << "Average TurnAround Time = " << ttat/np << endl;
    return 0;
}