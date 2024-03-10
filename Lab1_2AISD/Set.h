#include <iostream>

template<typename T>
struct node
{
    T key_value;
    node* left;
    node* right;
};

template<typename T>
class Set {
public:
    node<T>* _root;

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

    Set& operator=(const Set<T>& other) {
        if (this != &other) {

            this->_free_node(this->_root);
            this->_root = nullptr;


            this->_insert_all_child(other._root);
        }
        return *this;
    }

    void print()
    {
        this->_print_node(this->_root);
        std::cout << std::endl;
    }

    void insert(T key) {
        node<T>* p = new node<T>;
        p->key_value = key;
        p->left = nullptr;
        p->right = nullptr;

        if (this->_root == nullptr) {
            this->_root = p;
            return;
        }

        node<T>* ptr = this->_root;
        node<T>* parent = nullptr;

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

        node<T>* ptr = this->_root;

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
    void _print_node(node<T>* ptr) {
        if (ptr != nullptr) {
            std::cout << "  " << ptr->key_value << "     ";
            this->_print_node(ptr->left);

            this->_print_node(ptr->right);
        }
    }

    void _free_node(node<T>* ptr) {
        if (ptr != nullptr) {
            this->_free_node(ptr->left);
            this->_free_node(ptr->right);
            delete ptr;
            ptr = nullptr;
        }
    }

    node<T>* _delete_node(node<T>* root, int k)
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
            node<T>* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            node<T>* temp = root->left;
            delete root;
            return temp;
        }


        else {
            node<T>* succParent = root;


            node<T>* succ = root->right;
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

    node<T>* _insert_all_child(node<T>* ptr) {
        if (ptr == nullptr)
            return nullptr;

        node<T>* newNode = new node<T>;
        newNode->key_value = ptr->key_value;
        newNode->left = _insert_all_child(ptr->left);
        newNode->right = _insert_all_child(ptr->right);

        return newNode;
    }


    
};