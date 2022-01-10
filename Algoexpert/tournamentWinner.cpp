#include <vector>
#include <bits/stdc++.h>

using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  unordered_map<string, int> winner ;
	for(int i = 0 ; i < competitions.size() ; i++){
		if(results[i]){
			// home team won
			if(winner.find(competitions[i][0]) == winner.end())
				winner.insert({competitions[i][0], 1}) ;
			else
				winner[competitions[i][0]]++ ;
		}
		else{
			// away team won
			if(winner.find(competitions[i][1]) == winner.end())
				winner.insert({competitions[i][1], 1}) ;
			else
				winner[competitions[i][1]]++ ;
		}
	}
	int mostMatchWon = 0 ;
	string winningTeam = "" ;
	
	for(auto itr : winner){
		if(itr.second > mostMatchWon)
			mostMatchWon = itr.second, winningTeam = itr.first ;
	}
	
  return winningTeam ;
}
