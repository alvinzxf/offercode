/*
数字在排序数组中出现的次数

题目描述
统计一个数字在排序数组中出现的次数
*/

class Solution{
public:
    int GetNumberOfK(vector<int>data,int k)
    {
        if(data.empty())return 0;
        int result = 0;
        int first = GetFirtK(data,k,0,data.size()-1);
        int last = GetLastK(data,k,0,data.size()-1);
        if(first>-1&&last>-1)
            result = last - first+1;
        return result;
    }

    int GetFirtK(vector<int>&data,int k,int start,int end)
    {
        if(start>end)return -1;
        int MiddleIndex = start+(end-start)/2;
        int MiddleData = data[MiddleIndex];
        if(MiddleData==k)
        {
            if(MiddleIndex==start||data[MiddleIndex-1]!=k)
                return MiddleIndex;
            else
                end = MiddleIndex-1;
        }
        else if(MiddleData>k)
            end = MiddleIndex-1;
        else
            start = MiddleIndex+1;
        return GetFirtK(data,k,start,end);
    }

    int GetLastK(vector<int>&data,int k,int start,int end)
    {
        if(start>end)return -1;
        int MiddleIndex = start+(end-start)/2;
        int MiddleData = data[MiddleIndex];
        if(MiddleData==k)
        {
            if(MiddleIndex==end||data[MiddleIndex+1]!=k)
                return MiddleIndex;
            else
                start = MiddleIndex+1;
        }
        else if(MiddleData>k)
            end = MiddleIndex-1;
        else
            start = MiddleIndex+1;
        return GetLastK(data,k,start,end);
    }
};


/**********************调试*****************************/
class Solution{
public:
    int GetNumberOfK(vector<int>data,int k)
    {
        if(data.empty())return 0;
        int result = 0;
        int start = 0;
        int end = data.size()-1;

        while(end>start)
        {
             int Mid = start+(end-start)/2;
            if(data[Mid]==k)
            {
                int LeftCount = GetLeftK(data,k,start,Mid);
                int RightCount = GetRightK(data,k,Mid+1,end);
                return LeftCount+RightCount;
            }
            else if(data[Mid]>k)
                end = Mid-1;
            else
                start = Mid+1;
        }
       return 0;
    }
    int GetLeftK(vector<int>&data,int k,int start,int end)
    {
        int LeftSize = 0;
        if(start>end)return -1;
        for(;end>start;end--)
        {
            if(data[end]!=k)
                return LeftSize;
            LeftSize++;
        }
        return LeftSize;
    }

    int GetRightK(vector<int>&data,int k,int start,int end)
    {
        int RightSize = 0;
        if(start>end)return -1;
        for(;start<end;start++)
        {
            if(data[start]!=k)
                return RightSize;
            RightSize++;
        }
        return RightSize;
    }
};


/**********************调试*****************************/
class Solution
{
public:
    int GetNumberOfK(vector<int>data,int k)
    {
        if(data.empty())return 0;
        int index = FindNumberK(data,k,0,data.size()-1);
        int Size = 1;
        //int RightSize = 0;
        int left = index;
        int right = index;
        while(--left>=0 &&data[left]==k)Size++;
        
        while(++right<=data.size()&&data[right]==k)Size++;
        return Size;
    }
    int FindNumberK(vector<int>&data,int k,int start,int end)
    {
        if(start>end)return -1;
        int Mid = 0;
        while(start<end)
        {
            Mid = start+(end - start)/2;
            if(data[Mid]==k)
                return Mid;
            else if(data[Mid]>k)
                end = Mid-1;
            else
                start = Mid+1;
        }
        return Mid;
    }
};
