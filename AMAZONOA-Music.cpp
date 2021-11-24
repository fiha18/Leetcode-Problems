#include<bits/stdc++.h>
using namespace std;

pair<int,int> musicRuntime(int targetTime,vector<int> time)
{
	if(targetTime < 0)
		return pair<int,int>(-1,-1);
	map<int,int> map;
	for (int i = 0; i < time.size(); ++i)
	{
		map.insert(pair<int,int>(time[i],i));
	}
	int minVal = INT_MAX, maxVal = -1,id1 = -1,id2 = -1,flag = 0;
	for (int i = 0; i < time.size(); ++i)
	{
		int t = targetTime - time[i];
		if(map.find(t)!=map.end())
		{
			flag = 1;
			if(t > maxVal)
			{
				maxVal = t;
				minVal = time[i];
				id1 = i;
				id2 = map[t];
			}
		}
	}
	
	return pair<int,int>(id1,id2);
}

int main()
{
	int n;
	cin >> n;
	vector<int> time;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		time.push_back(x);
	}

	int runDuration;
	cin >> runDuration;
	int targetTime = runDuration - 30;

	pair<int,int> res = musicRuntime(targetTime,time);
	cout<< res.first << " " << res.second << endl;
	return 0;
}