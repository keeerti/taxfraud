#include <iostream>
using namespace std;


int replace(int A[],int B[],int n,int x){
    int opp=0;
    for(int i=0;i<n;i++){
        if(A[i]!=B[i]){
            A[i]=1-A[i];
            opp++;
        }
        if(opp==x){
            break;
        }
    }
    return opp;
}

bool check(int A[],int B[],int n){
    for(int i=0;i<n;i++){
        if(A[i]!=B[i]){
            return false;
        }
    }
    return true;
}


int decide(int A[],int B[],int n){
    int count0A=0;
    int count0B=0;
    for(int i=0;i<n;i++){
        if(A[i]==0){
            count0A++;
        }
        if(B[i]==0){
            count0B++;
        }
    }
    if(count0A==count0B){
        return 0;
    }
    else{
        if(count0A-count0B<0){
            return -1*(count0A-count0B);
        }
        else{
            return count0A-count0B;
        }
    }
}




int main(){
    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        
        int n;
        cin>>n;
        int A[n];
        int B[n];

        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        for(int i=0;i<n;i++){
            cin>>B[i];
        }

        if(check(A,B,n)){
            cout<<0<<endl;
        }
        else{
            int output=decide(A,B,n);

            if(output==0){
                cout<<1<<endl;
            }
            else{
                replace(A,B,n,output);

                if(check(A,B,n)){
                    cout<<output<<endl;
                }
                else{
                    cout<<output+1<<endl;
                }
            }
        }
    }
    return 0;
}
