#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
};

struct node* createNode(int key) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void Preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(struct node* root) {
    if (root != NULL) {
        Inorder(root->left);
        printf("%d ", root->key);
        Inorder(root->right);
    }
}

void Postorder(struct node* root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ", root->key);
    }
}

struct node* insert(struct node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    return root;
}

struct node* search(struct node* root, int item) {
    if (root == NULL || root->key == item) {
        return root;
    }

    if (item < root->key) {
        return search(root->left, item);
    } else {
        return search(root->right, item);
    }
}

struct node* findMin(struct node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* Delete(struct node* root, int value) {
    if (root == NULL) return root;

    if (value < root->key) {
        root->left = Delete(root->left, value);
    } else if (value > root->key) {
        root->right = Delete(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            struct node* temp = root;
            root = root->right;
            free(temp);
            return root;
        } else if (root->right == NULL) {
            struct node* temp = root;
            root = root->left;
            free(temp);
            return root;
        } else {
            struct node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = Delete(root->right, temp->key);
        }
    }
    
    return root;
}

int main() {
    struct node *root = NULL;

    int choice, item;

    do {
        printf("\n1. Insert\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Search\n6. Delete\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &item);
                root = insert(root, item);
                break;
            case 2:
                printf("Preorder Traversal: ");
                Preorder(root);
                break;
            case 3:
                printf("Inorder Traversal: ");
                Inorder(root);
                break;
            case 4:
                printf("Postorder Traversal: ");
                Postorder(root);
                break;
            case 5:
                printf("Enter data to search: ");
                scanf("%d", &item);
                struct node* foundNode = search(root, item);
                if (foundNode != NULL)
                    printf("The node %d exists.\n", item);
                else
                    printf("The node %d does not exist.\n", item);
                break;
            case 6:
                printf("Enter data to delete: ");
                scanf("%d", &item);
                root = Delete(root, item);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid entry! Please try again.\n");
                break;
        }
        
    } while(choice != 7);

    return 0;
}
