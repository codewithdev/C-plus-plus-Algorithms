/* https://en.wikipedia.org/wiki/Shortest_job_next */

#include<iostream>
using namespace std;

struct process_node
{
	int pid;	 // Process Id
	int atime; // Arrival Time
	int etime; // Execution Time
	int rtime; // Remaining Time
	int ftime; // Final TIme
};

int main()
{
	int count, ind, jnd, time = 0, min_pid, min_rtime, wtime, ttime, completed = 0;
	float mttime;

	cout << "Enter number of processes: ";
	cin >> count;
	struct process_node arr[count], temp;
	for (ind = 0; ind < count; ind++)
	{
		arr[ind].pid = ind + 1;
		cout << arr[ind].pid << " ETime and ATime: ";
		cin >> arr[ind].etime >> arr[ind].atime;
		arr[ind].rtime = arr[ind].etime;
	}
	for (ind = 0; ind < count; ind++)
		for (jnd = 1; jnd < count; jnd++)
			if (arr[jnd - 1].atime > arr[jnd].atime)
			{
				temp = arr[jnd - 1];
				arr[jnd - 1] = arr[jnd];
				arr[jnd] = temp;
			}

	cout << "PID\tAT\tET\tFT\tWT\tTAT\tMTAT\n";

	while (completed < count)
	{
		min_rtime = 10000000;
		min_pid = -1;
		for (ind = 0; ind < count; ind++)
		{
			if (arr[ind].rtime > 0 && arr[ind].atime <= time && arr[ind].rtime < min_rtime)
			{
				min_pid = ind;
				min_rtime = arr[ind].rtime;
			}
		}
		if (min_pid == -1)
		{
			time++;
			continue;
		}
		ind = min_pid;
		time += arr[ind].rtime;
		arr[ind].rtime = 0;
		arr[ind].ftime = time;

		printf("P%d\t%d\t%d/%d", arr[ind].pid, arr[ind].atime, arr[ind].etime - arr[ind].rtime, arr[ind].etime);
		if (arr[ind].rtime == 0)
		{
			completed++;
			wtime = arr[ind].ftime - (arr[ind].atime + arr[ind].etime);
			ttime = arr[ind].ftime - arr[ind].atime;
			mttime = (float)ttime / arr[ind].etime;
			printf("\t%d\t%d\t%d\t%.2f", arr[ind].ftime, wtime, ttime, mttime);
		}
		cout << endl;
	}

	cout << "Total Execution Time: " << time << endl;
	return 0;
}
