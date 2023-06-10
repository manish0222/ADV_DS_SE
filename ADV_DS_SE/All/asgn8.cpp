#include <iostream>
#include <vector>
#include <climits>
using namespace std;
                              // total combinations are (2n
					//                C
					//		   n)/(n+1)   ie for 3 we get 5 ways	


			/*	****************************
				KEYS MUST BE IN SORTED ORDER
			 ****************************************** */
				
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k)
        : key(k), left(nullptr), right(nullptr) {}
};

// Helper function to construct the optimal binary search tree
pair<Node*, int> constructOptimalBST(const vector<int>& keys, const vector<int>& frequencies, int start, int end) {
    if (start > end) {
        return {nullptr, 0};
    }

    int minCost = INT_MAX;
    int minIndex = -1;

    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += frequencies[i];
    }

    for (int i = start; i <= end; i++) {
        int cost = sum + ((i > start) ? constructOptimalBST(keys, frequencies, start, i - 1).second : 0) +
                   ((i < end) ? constructOptimalBST(keys, frequencies, i + 1, end).second : 0);

        if (cost < minCost) {
            minCost = cost;
            minIndex = i;
        }
    }

    Node* root = new Node(keys[minIndex]);

    auto leftSubtree = constructOptimalBST(keys, frequencies, start, minIndex - 1);
    auto rightSubtree = constructOptimalBST(keys, frequencies, minIndex + 1, end);

    root->left = leftSubtree.first;
    root->right = rightSubtree.first;

    int totalCost = minCost;

    return {root, totalCost};
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(!root) return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    vector<int> keys = {10, 12, 20};
    vector<int> frequencies = {34, 8, 50};

    auto result = constructOptimalBST(keys, frequencies, 0, keys.size() - 1);

    Node* root = result.first;
    int cost = result.second;

    cout << "Optimal Binary Search Tree Cost: " << cost << endl;
    cout<<"Inorder ";inorder(root);cout<<endl;
    cout<<"Preorder ";preorder(root);cout<<endl;

    return 0;
}






					//approach 2




// A naive recursive implementation of
// optimal binary search tree problem
// #include <bits/stdc++.h>
// using namespace std;

// class OBST{
// public:
//     int *keys,*freq,n;
//   // A utility function to get sum of
// // array elements freq[i] to freq[j]
//     void setArr(int keys[],int freq[],int n){
//         this->keys=keys;
//         this->freq=freq;
//         this->n=n;
//     }
    
//     // int sum(int freq[], int i, int j);

// // A recursive function to calculate
// // cost of optimal binary search tree
//     int optCost(int freq[], int i, int j)
//     {
//     	// Base cases
//     	if (j < i) // no elements in this subarray
//     		return 0;
//     	if (j == i) // one element in this subarray
//     		return freq[i];
    	
//     	// Get sum of freq[i], freq[i+1], ... freq[j]
//     	int fsum = sum(freq, i, j);
    	
//     	// Initialize minimum value
//     	int min = INT_MAX;
    	
//     	// One by one consider all elements
//     	// as root and recursively find cost
//     	// of the BST, compare the cost with
//     	// min and update min if needed
//     	for (int r = i; r <= j; ++r)
//     	{
//     		int cost = optCost(freq, i, r - 1) +
//     				optCost(freq, r + 1, j);
//     		if (cost < min)
//     			min = cost;
//     	}
    	
//     	// Return minimum value
//         return min + fsum;
//     }

// // The main function that calculates
// // minimum cost of a Binary Search Tree.
// // It mainly uses optCost() to find
// // the optimal cost.
//     int optimalSearchTree(int keys[],
//     					int freq[], int n)
//     {
//     	// Here array keys[] is assumed to be
//     	// sorted in increasing order. If keys[]
//     	// is not sorted, then add code to sort
//     	// keys, and rearrange freq[] accordingly.
//     	return optCost(freq, 0, n - 1);
//     }
    
//     // A utility function to get sum of
//     // array elements freq[i] to freq[j]
//     int sum(int freq[], int i, int j)
//     {
//     	int s = 0;
//     	for (int k = i; k <= j; k++)
//     	s += freq[k];
//     	return s;
//     }
//     int partition(int keys[],int freq[],int l,int h){
//         int i=l,j=h-1,pivot=l;
//         while(i<j){
//             while(keys[i]<=keys[pivot]){
//                 i++;
//                 if(i==h){i=h-1;break;}
//             }
//             while(keys[j]>keys[pivot]){
//                 j--;
//                 if(j<0){j=0;break;}
//             }
//             if(i<j){
//                 swap(keys[i],keys[j]);
//                 swap(freq[i],freq[j]);
//             }
//         }
//         swap(keys[j],keys[pivot]);
//         swap(freq[j],freq[pivot]);
//         return j;
//     }
    
//     void quicksort(int keys[],int freq[],int i,int j){
//         if(i<j){
//             quicksort(keys,freq,i,partition(keys,freq,i,j));
//             quicksort(keys,freq,partition(keys,freq,i,j)+1,j);
//         }
//     }  
// };
// // Driver Code
// int main()
// {
//     OBST obj;
// 	int keys[] = {10, 12, 20};
// 	int freq[] = {34, 8, 50};	
// 	int n = sizeof(keys) / sizeof(keys[0]);
// 	obj.setArr(keys,freq,n);
// 	cout << "Cost of Optimal BST is "
// 		<< obj.optimalSearchTree(keys, freq, n);
// 	return 0;
// }

