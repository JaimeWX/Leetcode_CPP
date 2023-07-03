class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char,int> magazine_map;
        unordered_map<char,int> ransomNote_map;
        for(int i=0; i<magazine.size(); i++)
        {
            magazine_map[magazine[i]]++;
        }
        for(int i=0; i<ransomNote.size(); i++)
        {
            ransomNote_map[ransomNote[i]]++;
        }
        for(unordered_map<char,int>::iterator it = ransomNote_map.begin(); it != ransomNote_map.end(); it++)
        {
            auto iter = magazine_map.find(it->first);
            if(iter != magazine_map.end())
            {
                if(iter->second < it->second)
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};