#include <iostream>
using namespace std;

class Node
{
public:
    bool val{};
    bool isLeaf{};
    Node *topLeft{};
    Node *topRight{};
    Node *bottomLeft{};
    Node *bottomRight{};

    Node() {}

    Node(bool _val, bool _isLeaf) : val(_val), isLeaf(_isLeaf)
    {
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
        : val(_val), isLeaf(_isLeaf), topLeft(_topLeft), topRight(_topRight), bottomLeft(_bottomLeft), bottomRight(_bottomRight)
    {
    }
};

class LogicOrOfTwoBinaryGridsRepresentedAsQuadTrees
{
public:
    Node *intersect(Node *quadTree1, Node *quadTree2)
    {
        if (quadTree1->isLeaf)
        {
            if (quadTree1->val)
            {
                return new Node(true, true);
            }
            return quadTree2;
        }
        if (quadTree2->isLeaf)
        {
            return intersect(quadTree2, quadTree1);
        }
        Node *o1 = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node *o2 = intersect(quadTree1->topRight, quadTree2->topRight);
        Node *o3 = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node *o4 = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if (o1->isLeaf && o2->isLeaf && o3->isLeaf && o4->isLeaf && o1->val == o2->val && o1->val == o3->val && o1->val == o4->val)
        {
            return new Node(o1->val, true);
        }
        return new Node(false, false, o1, o2, o3, o4);
    }
};

void del(Node *head)
{
    if (head->topLeft)
    {
        del(head->topLeft);
    }
    if (head->topRight)
    {
        del(head->topRight);
    }
    if (head->bottomLeft)
    {
        del(head->bottomLeft);
    }
    if (head->bottomRight)
    {
        del(head->bottomRight);
    }
    delete head;
}

void print(Node *head)
{
    cout << head->val << " , ";
    if (head->topLeft)
    {
        print(head->topLeft);
    }
    if (head->topRight)
    {
        print(head->topRight);
    }
    if (head->bottomLeft)
    {
        print(head->bottomLeft);
    }
    if (head->bottomRight)
    {
        print(head->bottomRight);
    }
    delete head;
}

int main()
{
    LogicOrOfTwoBinaryGridsRepresentedAsQuadTrees cls;

    Node *head1 = new Node(1, 0);
    head1->topLeft = new Node(1, 1);
    head1->topRight = new Node(1, 1);
    head1->bottomLeft = new Node(0, 1);
    head1->bottomRight = new Node(0, 1);
    Node *head2 = new Node(1, 0);
    head2->topLeft = new Node(1, 1);
    head2->topRight = new Node(1, 0);
    head2->bottomLeft = new Node(1, 1);
    head2->bottomRight = new Node(0, 1);
    head2->topRight->topLeft = new Node(0, 1);
    head2->topRight->topRight = new Node(0, 1);
    head2->topRight->bottomLeft = new Node(1, 1);
    head2->topRight->bottomRight = new Node(1, 1);
    Node *ret = cls.intersect(head1, head2);
    print(ret);
    cout << endl;
    del(ret);
    return 0;
}
