// Time Limit Exceed
// Problem: https://leetcode.com/problems/smallest-sufficient-team/

class Solution {
public:
    
    void createMaskedPeople(vector<string> &reqSkills, vector<vector<string>> &people, vector<bitset<16>> &maskedPeople){
        unordered_set<string> s ;
        
        for(int i = 0 ; i < people.size() ; i++){
            for(auto skill: people[i])
                s.insert(skill);
            
            for(int j = 0 ; j < reqSkills.size() ; j++){
                if(s.find(reqSkills[j]) != s.end())
                    maskedPeople[i][j] = true ;
                else
                    maskedPeople[i][j] = false ;
            }
            s.clear() ;
        }
    }
    
    void getSufficientTeam(vector<bitset<16>> &maskedPeople, int i, bitset<16> ans, vector<int> &peopleSelected, vector<int> &result, int &minPeopleCount, int skillCount){
        if(i > maskedPeople.size())
            return ;
        
        if(i == maskedPeople.size()){
            if(peopleSelected.size() < minPeopleCount && ans.count() == skillCount){
                result = peopleSelected;
                minPeopleCount = peopleSelected.size() ;
            }
            return ;
        }
        
        // select ith person
        peopleSelected.push_back(i) ;
        getSufficientTeam(maskedPeople, i+1,ans | maskedPeople[i],peopleSelected, result, minPeopleCount,skillCount) ;
        peopleSelected.pop_back() ;
        
        // not selecting ith person
        getSufficientTeam(maskedPeople, i+1, ans, peopleSelected, result, minPeopleCount, skillCount) ;
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = people.size() ;
        const int skillsRequired = req_skills.size() ;
        vector<bitset<skillsRequired>> maskedPeople(n) ;
        vector<int> result ;
        bitset<skillsRequired> ans ;
        vector<int> peopleSelected ;
        int minPeopleCount = 70 ;
        
        createMaskedPeople(req_skills, people, maskedPeople) ;
        
        getSufficientTeam(maskedPeople, 0, ans, peopleSelected, result, minPeopleCount, req_skills.size()) ;
        
        return result ;
    }
};