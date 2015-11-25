#include <stdio.h>
#include <limits.h>
#include <vector>
using namespace std;

class MaxHeap {
public:
    MaxHeap();
    void InsertElem (int p);
    //void DeleteElem (int p);
    void DeleteMax  ();

    int FindMax     ();
    int PopMax      ();

    void WlakAndPrint();

private:
    void MaxHeapify (int pos);

    int LeftChild   (int pos);
    int RightChild  (int pos);
    int Parent      (int pos);

    int IsLeaf      (int pos);

    // todo(need siblings?)

    vector<int> vHeap;
};

#define GROWBY    10
MaxHeap::MaxHeap()
{
    vHeap.reserve(10);
}

int MaxHeap::FindMax ()
{
    if (vHeap.empty()) 
        return INT_MAX;

    return vHeap[0];
}


int MaxHeap::PopMax ()
{
    if (vHeap.empty()) 
        return INT_MAX;

    int ret = vHeap[0];
    DeleteMax();
    return ret;
}

void MaxHeap::DeleteMax ()
{
    // set last element in the heap as root
    vHeap[0] = vHeap[vHeap.size()-1];
    vHeap.pop_back();

    // masheapify
    MaxHeapify(0);
}

void MaxHeap::MaxHeapify (int pos)
{
    int size = vHeap.size();
    int right, left, largest;
    while (pos >= 0 && pos < size && !IsLeaf(pos)) {

        // check if curr node is largest among it's children
        right = RightChild(pos);
        left  = LeftChild(pos);
        largest = pos;

        if (right < size && vHeap[right] > vHeap[pos]) {
            largest = right;
        }

		if (left < size && vHeap[left] > vHeap[largest]) {
            largest = left;
        }

        if (largest == pos) 
            break;

        // swap the largest and curr
        int temp = vHeap[largest];
        vHeap[largest] = vHeap[pos];
        vHeap[pos] = temp;

        pos = largest;
    };
}

void MaxHeap::InsertElem (int p)
{
    int pos  = vHeap.size();
    int parent = Parent(pos);

    if (pos == 0) {
        vHeap.push_back(p);
		return;
    }

    if (vHeap.size() == vHeap.capacity()) 
        vHeap.reserve(vHeap.size() + GROWBY);

    vHeap.push_back(p);

    // move up and see until parent > this
    while (parent != -1 && vHeap[parent] < vHeap[pos]) {
        int temp = vHeap[parent];
        vHeap[parent] = vHeap[pos];
        vHeap[pos] = temp;
        pos = parent;
        parent = Parent(pos);
    }
}

int MaxHeap::LeftChild   (int pos)
{
    int child = (2 * pos) + 1;
    if (child < vHeap.size()) {
        return child;
    }
    return -1;
}

int MaxHeap::RightChild  (int pos)
{
    int child = (2 * pos) + 2;
    if (child < vHeap.size()) {
        return child;
    }
    return -1;
}

int MaxHeap::Parent      (int pos)
{
    int child = (pos-1)/2;
    if (child >=0 && child < vHeap.size()) {
        return child;
    }
    return -1;
}

int MaxHeap::IsLeaf      (int pos)
{
    if (pos >=(vHeap.size())/2 && (pos <vHeap.size())) {
        return true;
    }
    return false;
}

void MaxHeap::WlakAndPrint()
{
    for(auto& it : vHeap) {
        printf("%d\n", it);
    }
}

int main()
{
    MaxHeap m;
    m.InsertElem(10);
    m.InsertElem(1);
    m.InsertElem(12);
    m.InsertElem(4);
    m.InsertElem(100);
    m.InsertElem(120);
    m.InsertElem(300);
    m.InsertElem(5);

    int i = m.PopMax();
    while (i != INT_MAX) {
        printf ("%d\n", i);
        i = m.PopMax();
    }
}
