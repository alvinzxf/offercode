class Solution
{
public:
	static bool compare(const string &str1,const string &str2)
	{
		string s1=str1+str2;
		string s2=str2+str1;
		return s1<s2;
	}
	string PrintMinNumber(vector<int>numbers)
	{
		string result;
		if(numbers.size()<=0)
			return result;
	
		vector<string>strNum;
		for(int i=0;i<numbers.size();i++)
		{
			stringstream ss;
			ss<<numbers[i];
			string s=ss.str();
			strNum.push_back(s);

		}
		sort(strNum.begin(),strNum.end(),compare);
		for(int i=0;i<strNum.size();i++)
			result.append(strNum[i]);
		return result;
	}
	
};