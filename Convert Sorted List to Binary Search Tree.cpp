/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        vector<int> result = LinkedList_TO_Array(head);

        return TreeBuilder(result, 0, result.size() - 1);
    }

    vector<int> LinkedList_TO_Array(ListNode *head)
    {
        vector<int> result;
        while (head != nullptr)
        {
            result.push_back(head->val);
            head = head->next;
        }
        return result;
    }

    TreeNode *TreeBuilder(vector<int> &array, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(array[mid]);
        root->left = TreeBuilder(array, left, mid - 1);
        root->right = TreeBuilder(array, mid + 1, right);
        return root;
    }
};
