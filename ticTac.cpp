#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int n;
	int result=0;
	cin>>n;
	int array[n][n];
	// Array input
		for (int i=0;i<n;i++){
				for (int j=0;j<n;j++){
					cin>>array[i][j];
				}
			}

			int player;
    // Array ouput
	   	for (int i=0;i<n;i++){
				for (int j=0;j<n;j++){
					cout<<array[i][j];
				}
				cout<<endl;
			}
			
     // initial state
     int initial=0;
	int null=0;
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(array[i][j]==-1)
			null++;
		}
	}
	if (null==n*n) {
	    initial=1;
	    cout<<"Initial state";
	} 
	
	
	// invalid case
	int invalid=0;
	int p1=0;
	int p2=0;
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(array[i][j]==1) p1++;
			if(array[i][j]==2) p2++;
		}
	}
	if (p1>p2 && p1-p2>1){
	    invalid=1;
	    cout<<"Invalid 1 more than 2";
	} 
	else if (p2>p1 && p2-p1>1){
	    invalid=1;
	    cout<<"invalid 2 more than 1"<<p2<<endl<<p1;
	}
	
			
	
	// Case 1:equal row
	int count=0;
	for (int i=0;i<n;i++){
	count =0;                                  
		for(int j=0;j<n-1;j++){
			if(array[i][j]==array[i][j+1]){
				count++;
				player=array[i][j];
			}
			else{
				break;
			}
		}
		if(count==n-1 && invalid==0 && initial==0){
		    cout<<player<<" wins";
		    result=1;
		    break;
		}
	}
	
	
	// case 2:equal column
	count=0;
		for (int i=0;i<n;i++){
		count=0;                                 
		for(int j=0;j<n-1;j++){
			if(array[j][i]==array[j+1][i]){
				count++;
				player=array[i][j];
			}
			else if(array[j][i]!=array[j+1][i]){
				break;
			}
		}
		if(count==n-1 && invalid==0 && initial==0){
		    cout<<player<<" wins";
		    result=1;
		    break;
		}
	}
	
	
	// case 3: diagonal 1
	count=0;
		for (int i=0;i<n-1;i++){                                  
		   if(array[i][i]==array[i+1][i+1]){
		   	count++;
		   	player=array[i][i];
		   }
	}
		if(count==n-1 && invalid==0 && initial==0){
		    cout<<player<<" wins";
		    result=1;
		}
		
		
	// case 4:equal d2
	count =0;
	int j=0;
		for (int i=n;i>0;i--){                                  
		    if(array[i][j]==array[i-1][j+1]){
		    	count++;
		    	player=array[i][j];
		    	j++;
			}
	}
		if(count==n-1 && invalid==0 && initial==0){
		    cout<<player<<" wins";
		    result=1;
		}
		
	
	
	// Draw case // Intermediate case
	int inter=0;
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(array[i][j]==-1)
			inter=1;
		}
	}
	if (result==0 && inter==0 && invalid==0 && initial==0) {
		cout<<"draw";
	}
	
	
	else if(result==0 && inter==1 && invalid==0 && initial==0) cout<<"Intermediate";
	
	
}
	

   	
