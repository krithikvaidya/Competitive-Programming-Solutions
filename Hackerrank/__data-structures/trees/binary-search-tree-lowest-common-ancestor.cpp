

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) {
        int min, max;
        if(v1 > v2)
        {
            min = v2;
            max = v1;
        }
        else
        {
            min = v1;
            max = v2;
        }

		while(!(root -> data >= min && root -> data <= max))
        {
            if(min > root -> data)
                root = root -> right;
            else
                root = root -> left;
        }

        return root;
    }


