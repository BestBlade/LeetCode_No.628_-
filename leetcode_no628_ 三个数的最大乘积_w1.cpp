/* ------------------------------------------------------------------|
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-colors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	排序法
*
*	执行用时：52 ms, 在所有 C++ 提交中击败了92.07%的用户
*	内存消耗：27 MB, 在所有 C++ 提交中击败了75.22%的用户
*/

/*	
*
*	执行用时：32 ms, 在所有 C++ 提交中击败了99.43%的用户
*	内存消耗：27 MB, 在所有 C++ 提交中击败了79.95%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int maximumProduct(vector<int>& nums) {
    //o(logn)
    //sort(nums.begin(), nums.end());
    //int n = nums.size();
    //return max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;
    for (int& num : nums) {
        if (num > max1) {
            max3 = max2;
            max2 = max1;
            max1 = num;
        }
        else if (num > max2) {
            max3 = max2;
            max2 = num;
        }
        else if(num > max3){
            max3 = num;
        }

        if (num < min1) {
            min2 = min1;
            min1 = num;
        }
        else if (num < min2) {
            min2 = num;
        }
    }

    return max(min1 * min2 * max1, max1 * max2 * max3);
}

int main() {
    vector<int> nums = { -8,-7,-2,10,20 };
    maximumProduct(nums);
}