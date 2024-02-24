#include <iostream>

template<typename T>
struct Node
{
    T key_value;
    Node* left;
    Node* right;
};

template<typename T>
class Set {
public:
    Set() {
        this->_root = nullptr;
    }

    Set(Set<T>& other) {
        this->_root = nullptr;
        this->_insert_all_child(other._root);
    }

    ~Set() {
        this->_free_node(this->_root);
    }

    void print()
    {
        this->_print_node(this->_root);
        std::cout << std::endl;
    }

    void insert(T key) {
        Node<T>* p = new Node<T>;
        p->key_value = key;
        p->left = nullptr;
        p->right = nullptr;

        if (this->_root == nullptr) {
            this->_root = p;
            return;
        }

        Node<T>* ptr = this->_root;
        Node<T>* parent = nullptr;

        while (ptr != nullptr) {
            parent = ptr;
            if (key < ptr->key_value)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if (key < parent->key_value)
            parent->left = p;
        else
            parent->right = p;
    }

    bool contains(T key) {
        if (this->_root == nullptr)
            return false;

        Node<T>* ptr = this->_root;

        while (ptr != nullptr) {
            if (ptr->key_value == key)
                return true;
            if (key < ptr->key_value)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        return false;
    }

    bool erase(T key) {
        if (!this->contains(key))
            return false;
        this->_root = this->_delete_node(this->_root, key);
        return true;
    }

private:
    void _print_node(Node<T>* ptr) {
        if (ptr != nullptr) {
            this->_print_node(ptr->left);
            std::cout << "  " << ptr->key_value << "     ";
            this->_print_node(ptr->right);
        }
    }

    void _free_node(Node<T>* ptr) {
        if (ptr != nullptr) {
            this->_free_node(ptr->left);
            this->_free_node(ptr->right);
            delete ptr;
            ptr = nullptr;
        }
    }

    Node<T>* _delete_node(Node<T>* root, int k)
    {
        
        if (root == NULL)
            return root;

        if (root->key_value > k) {
            root->left = this->_delete_node(root->left, k);
            return root;
        }
        else if (root->key_value < k) {
            root->right = this->_delete_node(root->right, k);
            return root;
        }

        
        if (root->left == NULL) {
            Node<T>* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node<T>* temp = root->left;
            delete root;
            return temp;
        }

        
        else {
            Node<T>* succParent = root;

            
            Node<T>* succ = root->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }

            if (succParent != root)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            root->key_value = succ->key_value;

            delete succ;
            return root;
        }
    }

    void _insert_all_child(Node<T>* ptr) {
        if (ptr == nullptr)
            return;
        this->insert(ptr->key_value);
        this->_insert_all_child(ptr->left);
        this->_insert_all_child(ptr->right);
    }

    Node<T>* _root;
};

