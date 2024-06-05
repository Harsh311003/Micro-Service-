#include <bits/stdc++.h>
using namespace std;


#include <iostream>
#include <vector>
using namespace std;
const int MAX_SUM = 500100;
const int MAX_NODES = 500;
struct Node
{
    int value;
    int childCount;
    vector<int> children;
    bool sum[MAX_SUM + 1];
    Node()
    {
        value = -1;
        childCount = 0;
        for (int i = 1; i <= MAX_SUM; i++)
        {
            sum[i] = false;
        }
    }
};
Node nodes[MAX_NODES + 1];
int processTree(int nodeNumber)
{
    Node &currentNode = nodes[nodeNumber];
    int minChildSum = MAX_SUM;
    for (int k = 0; k < currentNode.childCount; k++)
    {
        int childNumber = currentNode.children[k];
        minChildSum = min(minChildSum, processTree(childNumber));
    }
    if (!currentNode.childCount) // leaf node
    {
        for (int i = 0; i <= currentNode.value; i++)
        {
            currentNode.sum[i] = true;
        }
        return currentNode.value;
    }
    int maxSum = 0;
    for (int j = 1; j <= minChildSum; j++)
    {
        bool sumPossible = true;
        for (int k = 0; k < currentNode.childCount; k++)
        {
            Node &childNode = nodes[currentNode.children[k]];
            if (childNode.sum[j] == false)
            {
                sumPossible = false;
                break;
            }
        }
        if (sumPossible)
        {
            for (int i = 0; i <= currentNode.value; i++)
            {
                int s = i + currentNode.childCount j;
                currentNode.sum[s] = true;
                maxSum = max(maxSum, s);
            }
        }
    }
    return maxSum;
}
int resultt()
{
    int ans = 0;
    Node &root = nodes[1];
    for (int i = 0; i < MAX_SUM; i++)
    {
        ans = max(ans, root.sum[i] == true ? i : 0);
    }
    return ans;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int TC = 0;
    cin >> TC;

    while (TC--)
    {
        int nodeCount = 0;
        int nodeNumber = -1;
        cin >> nodeCount;
        int value = -1;
        int childCount = -1;
        while (nodeCount--)
        {
            cin >> nodeNumber >> value >> childCount;
            nodes[nodeNumber].value = value;
            nodes[nodeNumber].childCount = childCount;
            int childToScan = nodes[nodeNumber].childCount;
            while (childToScan--)
            {
                int childNumber = -1;
                cin >> childNumber;
                nodes[nodeNumber].children.push_back(childNumber);
            }
        }

        processTree(1);

        cout << resultt() << endl;
    }
}


vector<int> singleNumber(vector<int> &nums)
{
    int xr = 0;
    for(auto val : nums)xr ^= val;

    int x = 0, y;

    int bit = 0;
    while( ((xr>>bit)&1)==0 ) bit++;

    for(auto val : nums){
        if((val>>bit)&1) x ^= val;
        else y ^= val;
    }
    
    return {x, y};
}
 