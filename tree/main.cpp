#include <stdio.h>

// g++ -std=c++11 -Wall -O3 -m64 -g3 -o ./bin/lin_release/main main.cpp
// g++ -std=c++11 -Wall -O0 -m64 -g3 -o ./bin/lin_debug/main -DDEBUG main.cpp
// cl -Ox /Z7 /W3 /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe
// cl -Od /Z7 /W3 /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe
// cl -Ox /Z7 /W3 /EHsc /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe & .\bin\win_release\main.exe
// cl -Od /Z7 /W3 /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe & .\bin\win_release\main.exe

#include <iostream>
using namespace std;

class Tree {
public:
    class TreeNode {
    public:
        TreeNode(int pVal){
            uVal = pVal;
            uRight = uLeft = nullptr;
        }
        int         uVal;
        TreeNode*   uRight;
        TreeNode*   uLeft;
    };

    Tree() {vRoot = nullptr;};
   ~Tree() {}; // todo: travese and delete all

    void Insert  (int pVal);    
    void Delete  (int pVal);

    enum eTType{
        INORDER,
        POSTORDER,
        PREORDER
    };

    void Traversal(eTType pType);

    int Height ();

private:
    void InOrder(TreeNode* pNode);
    void PreOrder(TreeNode* pNode);
    void PostOrder(TreeNode* pNode);

    int Height(TreeNode* pNode);

    bool Find    (int pVal, TreeNode** pCurr, TreeNode** pPrev);

    TreeNode* vRoot;
};

bool Tree::Find    (int pVal, TreeNode** pCurr, TreeNode** pPrev)
{
    *pCurr = vRoot;
    *pPrev = nullptr;

    while (*pCurr) {
        if ((*pCurr)->uVal == pVal) {
            return true;
        }

        *pPrev = (*pCurr);
        (*pCurr) = ((*pCurr)->uVal > pVal) ? (*pCurr)->uLeft : (*pCurr)->uRight;
    };

    return false;
}

void Tree::Insert (int pVal)
{
    TreeNode* curr;
    TreeNode* prev;

    if (Find(pVal,&curr,&prev))  {
        return;
    }

    curr = new TreeNode(pVal);

    if (!vRoot) {
        //assert that prev must be null
        vRoot = curr;
        return;
    }

    if (prev->uVal > pVal) {
        prev->uLeft = curr;
    } else {
        prev->uRight = curr;
    }
}


void Tree::Delete (int pVal)
{
    TreeNode* curr;
    TreeNode* prev;

    if (!Find(pVal,&curr,&prev))  {
        return;
    }

    // if node to be deleted has no child
    // if node to be deleted has one child
    // if node to be deleted has two children
    // 
    //if (vRoot == curr) {
    //    //assert that prev must be null
    //    vRoot = nullptr;
    //    delete curr;
    //    return;
    //}
    //
    //if (prev->uVal > pVal) {
    //    prev->uLeft = nullptr;
    //} else {
    //    prev->uRight = nullptr;
    //}
    delete curr;
}

int Tree::Height()
{
    return Height(vRoot);
}

int Tree::Height(TreeNode* pNode)
{
    int rh = 0;
    int lh = 0;
    if (!pNode) {
        return 0;
    }

    rh = Height(pNode->uRight);
    lh = Height(pNode->uLeft);

    return (rh > lh) ? (rh+1) : (lh+1);
}

// Increasing order
void Tree::Traversal(eTType pType)
{
    TreeNode* curr = vRoot;
    switch(pType) {
    case INORDER:
        InOrder(vRoot); break;
    case POSTORDER:
        PostOrder(vRoot); break;
    case PREORDER:
        PreOrder(vRoot); break;
    default:
        break;
    };
}

void Tree::InOrder(TreeNode* pNode)
{
    if (pNode) {
        InOrder(pNode->uLeft);
        printf("%d\n", pNode->uVal);
        InOrder(pNode->uRight);
    }
}

void Tree::PostOrder(TreeNode* pNode)
{
    if (pNode) {
        PostOrder(pNode->uLeft);
        PostOrder(pNode->uRight);
        printf("%d\n", pNode->uVal);        
    }
}

void Tree::PreOrder(TreeNode* pNode)
{
    if (pNode) {
        printf("%d\n", pNode->uVal);        
        PreOrder(pNode->uLeft);
        PreOrder(pNode->uRight);
    }
}

int main ()
{
    Tree t;
    t.Insert(100);
    printf("Height: %d\n", t.Height());
    t.Insert(200);
    printf("Height: %d\n", t.Height());
    t.Insert(300);
    printf("Height: %d\n", t.Height());
    t.Insert(90);
    printf("Height: %d\n", t.Height());
    t.Insert(80);
    printf("Height: %d\n", t.Height());
    t.Insert(70);
    printf("Height: %d\n", t.Height());
    t.Insert(95);
    printf("Height: %d\n", t.Height());
    t.Insert(150);
    printf("Height: %d\n", t.Height());
    t.Insert(250);
    printf("Height: %d\n", t.Height());
    printf("INORDER\n");
    t.Traversal(Tree::INORDER);
    printf("POSTORDER\n");
    t.Traversal(Tree::POSTORDER);
    printf("PREORDER\n");
    t.Traversal(Tree::PREORDER);

    t.Insert(400);
    printf("Height: %d\n", t.Height());
    t.Insert(500);
    printf("Height: %d\n", t.Height());
    return 0;
}
