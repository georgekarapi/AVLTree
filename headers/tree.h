struct node{
    int value;
    node *right = NULL;
    node *left = NULL;
    node *parent = NULL;
};
class Tree{
public:
    node *root = NULL;
    void print(node *leaf){ if(leaf == NULL){ return;}print(leaf->left);printf("%d \n",leaf->value);print(leaf->right); };
    node *smallest(node *leaf);
    void insert(int key);//Insert
    void print(){ print(root); };
    void del(int key);
    int getHeight(node*);
    node *search(int key);
    int isBalanced(node *leaf);
    void reconstruct(node *leaf);
};
void Tree::insert(int key){
    node *leaf,*leaf2;
    leaf = new node;
    leaf->value = key;
    if(root == NULL){
        root = leaf;
    }
    else{
        leaf2 = root;
        while(leaf2 != NULL){
            if(key < leaf2->value){//LEFT
                if(leaf2->left == NULL){
                    leaf2->left = leaf;
                    leaf->parent = leaf2;
                    break;
                }
                leaf2 = leaf2->left;
            }
            else if(key > leaf2->value){//RIGHT
                if(leaf2->right == NULL){
                    leaf2->right = leaf;
                    leaf->parent = leaf2;
                    break;
                }
                leaf2 = leaf2->right;
            }
            else{
                delete leaf;
                break;
            }
        }
        do{
            reconstruct(leaf2);
            if(leaf2->parent == NULL) break;
            leaf2 = leaf2->parent;
        }while(leaf != root);
    }
}

int Tree::getHeight(node *leaf) {
    if(leaf == NULL){
        return 0;
    }else{
        return 1 + (getHeight(leaf->left)>getHeight(leaf->right)?getHeight(leaf->left):getHeight(leaf->right));
    }
}

int Tree::isBalanced(node *leaf) {
    return (getHeight(leaf->right) - getHeight(leaf->left));
}

void Tree::reconstruct(node *leaf) {
    if(getHeight(leaf->right) - getHeight(leaf->left) > 1) {//
        if(getHeight(leaf->right->right) - getHeight(leaf->right->left) > 0) {//Left Rotation
            node *temp = leaf->right;
            leaf->right->parent = leaf->parent;
            if(temp->left !=NULL) temp->left->parent = leaf;
            leaf->right = leaf->right->left;
            leaf->parent = temp;
            temp->left = leaf;
            if(leaf == root) root = temp;
        }
    }
}

node *Tree::smallest(node *leaf){
    while(leaf->left != NULL){
        leaf = leaf->left;
    }
    return leaf;
}
void Tree::del(int key) {
    node *leaf,*l2,*temp;
    leaf = search(key);
    if(leaf != NULL) {
        if (root != NULL) {
            l2 = leaf->parent == NULL ? root : leaf->parent;
            if (leaf->right != NULL) {
                if (leaf->left == NULL) {
                    temp = l2->left == leaf ? l2->left = leaf->right : l2->right = leaf->right;
                    delete leaf;
                } else {
                    node *small = smallest(leaf->right);
                    temp = l2->left == leaf ? l2->left = leaf->right : l2->right = leaf->right;
                    small->left = leaf->left;
                    delete leaf;
                }
                if (l2 == root) {
                    root = temp;
                    root->parent = NULL;
                }
            } else if (leaf->left != NULL) {
                temp = l2->left == leaf ? l2->left = leaf->left : l2->right = leaf->left;
                delete leaf;
                if (l2 == root) {
                    root = temp;
                    root->parent = NULL;
                }
            } else {//NULL CHILDREN
                if (root->value == leaf->value) {//ROOT
                    delete root;
                    printf("The tree is now empty!\n");
                } else {
                    l2->left == leaf ? l2->left = NULL : l2->right = NULL;
                    delete leaf;
                }
            }
        } else {
            printf("There is no Tree\n");
        }
    }
    else{
        printf("There isn't such a value\n");
    }
}
node *Tree::search(int key){
    node *leaf = root;
    while(leaf != NULL) {
        if(key < leaf->value){
            leaf = leaf->left;
        }
        else if(key > leaf->value){
            leaf = leaf->right;
        }
        else if(key == leaf->value) {
            return leaf;
        }
    }
    return NULL;
}