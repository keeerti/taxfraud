#include <iostream>
using namespace std;



int subarray(int A[],int n){

	int subarr=0;

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(A[i]<(i+1)){
				j=n+1;
				i++;
			}
			if(A[j]>=j+1){
				subarr++;
			}
			else{
				j=n+1;
			}
			cout<<A[j]<<" ";
		}
		cout<<endl;
	}
	return subarr;
	
}


int main(){
	cout <<"\n=========================================\n\n";

	int N;
	cin>>N;

	for(int i=0;i<N;i++){
		int n;
		cin>>n;
		int A[n];
		for(int j=0;j<n;j++){
			cin>>A[i];			
		}
		cout<<subarray(A,n)<<endl;
		
	}
	





	cout <<"\n=========================================\n\n";
	return 0;
}
