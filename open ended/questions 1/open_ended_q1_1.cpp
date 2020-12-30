#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,i;
    cout<<"enter the number of test cases\t";
	cin>>t;
    while(t--){
        cout<<"enter the number of elements in the array\t";
		cin>>n;
        int arr[n];
        for(i=0;i<n;i++){
            cout<<"enter the element\t";
			cin>>arr[i];
        }
        //std::sort(arr,arr+n);
        int temp;
        for(int j = 0; j<n; j++) {
   			for(int k = j+1; k<n; k++){
      			if(arr[k] < arr[j]){
         			temp = arr[j];
         			arr[j] = arr[k];
         			arr[k] = temp;
      			}
   			}
		}
        cout<<"the elements are\t";
		for(i=0;i<n-2;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
