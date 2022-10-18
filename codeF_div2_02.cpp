#include <bits/stdc++.h>
using namespace std;
 

void display( int n)
{

    if(n==2){
        cout<<"2 1\n"<<endl;
    }
    else{
        cout<<"1 ";
        for (int i = n; i > 1; i--) {
            cout <<i << " ";
        }
        cout<<endl;
    }
  
}
 
void solve(){
    int n;
    cin>>n;

    int temp;

    display(n);
    
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
