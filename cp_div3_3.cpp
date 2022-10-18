#include <iostream>
using namespace std;

int solve(){
    int n;
    cin>>n;

    char current;
    cin>>current;
    

    string s;
    cin>>s;

    int rhash[n];
    int ghash[n];
    int yhash[n];

    for(int i=0;i<n;i++){
        rhash[i]=-1;
        ghash[i]=-1;
        yhash[i]=-1;
    }
    
    int rr=0;
    int yy=0;
    int gg=0;
    

    int gmax=0;
    int gmin=0;
    for(int i=0;i<n;i++){
        if(s[i]=='r'){
            rhash[rr++]=i;
        }
        else if(s[i]=='y'){
            yhash[yy++]=i;
        }
        else if(s[i]=='g'){
            ghash[gg++]=i;
            if(gmax<i){
                gmax=i;
            }
        }
    }

    for(int i=0;i<gg;i++){
        // cout<<ghash[i]<<" ";
    }

    // return 0;

    int maxtime=0;

    if(current=='g'){
        cout<<0;
    }
    else if(current=='r'){
        
        int time=0;
        for(int i=0;i<rr;i++){
            if(rhash[i]<gmax){
                time=gmax-rhash[i];
                if(time>maxtime){
                    maxtime=time;
                }
            }
            else{
                time=n-rhash[i]+ghash[0];
                if(time>maxtime){
                    maxtime=time;
                }
            }
        }
    }
    else if(current=='y'){
        // cout<<'1';
        // int maxtime=0;
        int time=0;
        for(int i=0;i<yy;i++){
            if(yhash[i]<gmax){
                
                time=gmax-yhash[i];
                // cout<<time<<" "<<maxtime<<endl;
                if(time>maxtime){
                    maxtime=time;
                }
            }
            else{
                time=n-yhash[i]+ghash[0];
                if(time>maxtime){
                    maxtime=time;
                }
            }
        }
    }
    cout<<maxtime<<endl;
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
