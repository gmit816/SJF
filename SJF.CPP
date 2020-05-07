#include<iostream>
using namespace std;
int p[100][6];

void swap(int &a, int &b){
	int tmp= a;
	a=b;
	b=tmp;
}

void byarrival(int n, int p[1000][6]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(p[j][1]>p[j+1][1]){
				for(int k=0;k<5;k++){
					swap(p[j][k], p[j+1][k]);
				}
			}
		}
	}
}
void core(int n, int p[1000][6]){
	int tmp, var;
	p[0][3]=p[0][1]+p[0][2];
	p[0][5]=p[0][3]-p[0][1];
	p[0][4]=p[0][5]-p[0][2];
	for(int i=1;i<n;i++){
		tmp=p[i-1][3];
		int sh=p[i][2];
		for(int j=i;j<n;j++){
			if(tmp>=p[j][1]&&sh>=p[j][2]){
				sh=p[j][2];
				var=j;
			}
		}
		p[var][3]=tmp+p[var][2];
		p[var][5]=p[var][3]-p[var][1];
		p[var][4]=p[var][5]-p[var][2];
		for(int k=0;k<6;k++){
			swap(p[var][k],p[i][k]);
		}
	}
}
int main(){
	int n, tmp;
	cout<<"Enter number of processes:";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter Process ID:";
		cin>>p[i][0];
		cout<<"Enter Arrival Time:";
		cin>>p[i][1];
		cout<<"Enter Burst Time:";
		cin>>p[i][2];
	}
	byarrival(n,p);
	core(n,p);
	cout<<"P#"<<"\t"<<"AT"<<"\t"<<"BT"<<"\t"<<"CT"<<"\t"<<"WT"<<"\t"<<"TAT"<<"\n";
	for(int k=0;k<n;k++){
		cout<<p[k][0]<<"\t"<<p[k][1]<<"\t"<<p[k][2]<<"\t"<<p[k][3]<<"\t"<<p[k][4]<<"\t"<<p[k][5]<<"\n";
	}
	int avg_wt=0,avg_tat=0;
	for(int i=0;i<n;i++){
	    avg_wt+=p[i][4];
	    avg_tat+=p[i][5];
	}
	avg_wt/=n;
	avg_tat/=n;
	cout<<"Average Waititng Time is: "<<avg_wt<<"\nAverage Turn Around Time is: "<<avg_tat<<"\nCompletion Time is: "<<p[n-1][5]+p[n-1][1]<<"\n";
	return 0;
}