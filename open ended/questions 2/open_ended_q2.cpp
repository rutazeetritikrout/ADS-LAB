#include<bits/stdc++.h>
using namespace std;

bool isUnique(int n){
    int r, b[1000], p=0;
    while(n != 0){
        r = n%10;
        b[p] = r;
        n = n/10;
        p++;
    }
    for(int x=0; x<p; x++){
        //b[x] << " ";
    }
    for(int i=0; i<p; i++){
    
        for(int j=i+1; j<p; j++){
            //"b[i] = " << b[i] << " ";
            //"b[j] = " << b[j] << " ";
            if(b[i] == b[j]){
                //SAME;
                return false;
            }
            else{
                //UNIQUE;
            }
        }
    }
    return true;
}

int main(){
    int t, l, r, a[1000];
    cout<<"enter the number of test cases\t";
	cin >> t; 
    while(t--){
        cout<<"enter the lower limit\t";
		cin >> l;
		cout<<"enter the upper limit\t";
        cin >> r;
        for(int i=l; i<=r; i++){
            a[i] = i;
        }
        cout<<"the list of unique elements is\n";
        for(int i=l; i<=r; i++){
            if(isUnique(a[i])){
                cout << a[i] << " ";
            }
        }
        cout<<"\n\n";
    }


    return 0;
}
