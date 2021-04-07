#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//109. 有序链表转换二叉搜索树
class ConvertSortedListToBinarySearchTree {
    /*给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
    本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
    */
    //本题可以将链表转换为vector，再构造二叉树（该方法如108）在此不实现
public:
    TreeNode* sortedListToBST(ListNode* head) {
        //通过查找中间节点 构造二叉树
        return build1(head, nullptr);
    }
private:
    ListNode* findMid(ListNode* head, ListNode* end) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != end && fast->next != end) {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    //注意 这里start包含 end不包含
    TreeNode* build1(ListNode* start, ListNode* end) {
        if (start == end)
            return nullptr;
        ListNode* mid = findMid(start, end);
        TreeNode* head = new TreeNode(mid->val);
        head->left = build1(start, mid);
        head->right = build1(mid->next, end);
        return head;
    }
public:
    TreeNode* sortedListToBST2(ListNode* head) {
        //通过知道链表长度 构造二叉树(先搭结构 后填值)
        int len = length(head);
        return Build2(head, 0, len-1);
    }
private:
    //获取链表长度
    int length(ListNode* head){
        int size = 0;
        while(head){
            ++size;
            head=head->next;
        }
        return size; 
    }
    TreeNode* Build2(ListNode*& head, int start, int end){
        if(start > end)
            return nullptr;
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode();
        root->left = Build2(head, start, mid-1);
        root->val = head->val;
        head=head->next;
        root->right = Build2(head, mid+1,end);
        return root;
    }
public:
    void DropTree(TreeNode* root) {
        //删除树
        if (root->left)
            DropTree(root->left);
        if (root->right)
            DropTree(root->right);
        cout << root->val << ",";
        delete root;
    }
    void DropList(ListNode* root){
        ListNode* p = root;
        while(p){
            root = p;
            p=p->next;
            delete root;
        }
    }
};

int main(int argc, char const* argv[])
{
    ConvertSortedListToBinarySearchTree cls;

    ListNode* head = new ListNode(-10);
    ListNode* p = head;
    p->next = new ListNode(-3);
    p=p->next;
    p->next = new ListNode(0);
    p=p->next;
    p->next = new ListNode(5);
    p=p->next;
    p->next = new ListNode(9);
    p=p->next;
    TreeNode* th = cls.sortedListToBST2(head);
    cout << "[";
    cls.DropTree(th);
    cout << "]" << endl;
    cls.DropList(head);
    return 0;
}
