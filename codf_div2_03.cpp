#include <iostream>
using namespace std;


void solve(){
    int n;
    cin>>n;

    int caps[n];
    int box[n];

    int onecount=0;

    for(int i=0;i<n;i++){
        cin>>caps[i];
        
        if(caps[i]==1){
            onecount++;
        }
    }
    for(int i=0;i<n;i++){
        cin>>box[i];
        
    }

        


    


    for(int i=1;i<n;i++){
        if(caps[i-1]==0){
            if(box[i-1]>box[i]){

                if(caps[i-1])
                caps[i-1]=1;
                caps[i]=0;
            }
        }
    }

    for(int i=0;i<n;i++){
        // cout<<caps[i]<<" ";
    }
    cout<<endl;

    int sum=0;

    for(int i=0;i<n;i++){
        if(caps[i]==1){
            sum=sum+box[i];
        }
    }

    cout<<sum<<endl;



}


int main(){
    int N;
    cin>>N;

    while(N){
        solve();
        N--;
    }


    return 0;
}
