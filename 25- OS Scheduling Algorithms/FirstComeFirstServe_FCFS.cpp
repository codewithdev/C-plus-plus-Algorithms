/*
https://en.wikipedia.org/wiki/FIFO_(computing_and_electronics)
*/

#include<iostream>
using namespace std;

struct process_node{
	int pid; // Process Id
	int atime; // Arrival Time
	int etime; // Execution Time
};

int main(){
	int count,ind,jnd,time=0,ftime,wtime,ttime;
	float mttime;
	cout << "Number of processes: ";
	cin >> count;
	struct process_node arr[count],temp;
	for(ind=0;ind<count;ind++){
		arr[ind].pid=ind+1;
		cout << arr[ind].pid << " ETime and ATime: ";
		cin >> arr[ind].etime >> arr[ind].atime;
	}
	for(ind=0;ind<count;ind++)
	for(jnd=1;jnd<count;jnd++)
		if (arr[jnd-1].atime>arr[jnd].atime){

			temp=arr[jnd-1];
			arr[jnd-1]=arr[jnd];
			arr[jnd]=temp;

		}
	cout << "Execution Order: \n";
	cout << "PID\tAT\tET\tWT\tFT\tTAT\tMTAT\n";
	for(ind=0;ind<count;ind++){
		if (time<arr[ind].atime) // Checking CPU idle conditions
			time=arr[ind].atime;
		ftime=arr[ind].etime+time;
		wtime=time-arr[ind].atime;
		ttime=ftime-arr[ind].atime;
		mttime=ttime/(arr[ind].etime+0.0);
		printf("P%d\t%d\t%d\t%d\t%d\t%d\t%.2f\n",arr[ind].pid,arr[ind].atime,arr[ind].etime,wtime,ftime,ttime,mttime);
		time=ftime;
	}

	cout << "Total Execution Time: " << time << endl;
	return 0;
}
