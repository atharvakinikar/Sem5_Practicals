#include<iostream>
using namespace std;
bool completed_flag=false;

bool kes_completed(bool finish[],int n){
    for(int i=0;i<n;i++){
        if(finish[i]==false){
            return false;
        }
    }
    return true;
}

int main(){

    int Available[3]={2,1,0};
    bool finish[5]={false,false,false,false,false};
    
    int Allocation[5][3]={
        {1,1,2},
        {2,1,2},
        {4,0,1},
        {0,2,0},
        {1,1,2}
    };
    
    int Max[5][3]={
        {4,3,3},
        {3,2,2},
        {9,0,2},
        {7,5,3},
        {1,1,2}
    };
    int Need[5][3];

    //computing need matrix
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            Need[i][j]=Max[i][j]-Allocation[i][j];
        }
    }

    // for(int i=0;i<5;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<Need[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int k=0;k<50;k++){
        bool check_deadlock=true;

        for(int i=0;i<5;i++){
        bool check_pro=true;
        if(!finish[i]){
            for(int j=0;j<3;j++){
                if((Need[i][j]>Available[j])){
                    check_pro=false;
                }
                if(check_pro==false)break;
            }
            if(check_pro==true){
                check_deadlock=false;
                for(int j=0;j<3;j++){
                    Available[j]=Available[j]+Allocation[i][j];
                }
                finish[i]=true;
                cout<<i<<endl;
            }
        }
        }

        completed_flag=kes_completed(finish,5);
        if(completed_flag){
            cout<<"All processess completed without deadlock!"<<endl;
            break;
        }

        if(check_deadlock){
            cout<<"System is in deadlock state!!"<<endl;
            break;
        }        
    }
    
}