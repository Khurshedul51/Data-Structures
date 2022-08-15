#include <bits/stdc++.h>
using namespace std;
#define max 10001;


int arr[max];
long long segmentTree[max*4]; // size of segment-tree-array should sizeof(arr)*4

void buildSegmentTree(int nodeIndex, int leftRange, int rightRange){
    /**
     * nodeIndex: index of the current node in the segment tree
     * leftRange: left limit of the current segment
     * rightRange: right limit of the current segment
     * Time Complexity: O(nlogn)
     * Space Complexity: O(n)
    */
    /* Base Case: leftRange == rightRange, i.e. this represents a single element from the array 
       which is the situation of a leaf node. The segment tree will 
       store this element i.e. if(leftRange == rightRange), st[nodeIndex] = arr[leftRange).
    */
    if(leftRange == rightRange) {
        segmentTree[nodeIndex] = arr[leftRange];
        return;
    }
    // Devide step: devide the array into two halves
    int mid = leftRange + (rightRange - leftRange)/2;
    // Conquer step
    int leftNodeIndex = 2*nodeIndex;
    int rightNodeIndex = 2*nodeIndex + 1;
    buildSegmentTree(leftNodeIndex, leftRange, mid);// left child
    buildSegmentTree(rightNodeIndex, mid+1, rightNodeIndex);// right child
    // Combine step: it can be different for different types of queries. below is for query sum
    segmentTree[nodeIndex] = segmentTree[leftNodeIndex] + segmentTree[rightNodeIndex];
}

long long rangeSumQuery(int nodeIndex, int leftRange, int rightRange, int left, int right){
    /**
     * nodeIndex: index of the current node in the segment tree
     * leftRange: left limit of the current segment
     * rightRange: right limit of the current segment
     * left: left limit of the given query segment
     * right: right limit of the given query segment
     * Time Complexity: O(logn)
    */
    if(right < leftRange || left > rightRange) {
        // Range represented by current node is completely outside the given range
        return 0;
    }
    else if(left <= leftRange && right <= rightRange) {
        // Range represented by current node is completely inside the given range
        return segmentTree[nodeIndex];
    }
    // Range represented by current node is partially inside and partially outside the given range
    int mid = leftRange + (rightRange - leftRange)/2;
    int leftNodeIndex = 2*nodeIndex;
    int rightNodeIndex = 2*nodeIndex + 1;
    long long leftResult = rangeSumQuery(leftNodeIndex, leftRange, mid, left, right);
    long long rightResult = rangeSumQuery(rightNodeIndex, mid+1, rightRange, left, right);
    return leftResult + rightResult;
}

void update(int nodeIndex, int leftRange, int rightRange, int index, int newValue){
    /**
     * Time Complexity: O(logn)
    */
    if(leftRange == rightRange){
        // leaf node
        arr[index] += newValue;
        segmentTree[nodeIndex] += newValue;
    }
    else {
        int mid = leftRange + (rightRange - leftRange)/2;
        int leftNodeIndex = 2*nodeIndex;
        int rightNodeIndex = 2*nodeIndex + 1;
        if(leftRange <= index && index <= mid){
            // If index is in the left child, recurse on the left child
            update(leftNodeIndex, leftRange, mid, index, newValue);
        }
        else {
            // If index is in the right child, recurse on the right child
            update(rightNodeIndex, mid+1, rightNodeIndex, index, newValue);
        }
        // current node will have the sum of both of its children
        segmentTree[nodeIndex] = segmentTree[leftNodeIndex] + segmentTree[rightNodeIndex];
    }
}

