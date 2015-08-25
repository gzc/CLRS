/**
 * C++: 二项堆
 *
 * @author skywang
 * @date 2014/04/02
 * @reference http://www.cnblogs.com/xuqiang/archive/2011/06/01/2065549.html
 */

#ifndef _BINOMIAL_TREE_HPP_
#define _BINOMIAL_TREE_HPP_

#include <iomanip>
#include <iostream>
using namespace std;

template <class T>
class BinomialNode {
public:
    T key;                      // 关键字(键值)
    int degree;                 // 度数
    BinomialNode<T> *child;     // 左孩子
    BinomialNode<T> *parent;    // 父节点
    BinomialNode<T> *next;      // 兄弟节点
    
    BinomialNode(T value):key(value), degree(0),
    child(NULL),parent(NULL),next(NULL) {}
};

template <class T>
class BinomialHeap {
private:
    BinomialNode<T> *mRoot;    // 根结点
    
public:
    BinomialHeap();
    ~BinomialHeap();
    
    // 新建key对应的节点，并将其插入到二项堆中
    void insert(T key);
    // 将二项堆中键值oldkey更新为newkey
    void update(T oldkey, T newkey);
    // 删除键值为key的节点
    void remove(T key);
    // 移除二项堆中的最小节点
    void extractMinimum();
    
    // 将other的二项堆合并到当前二项堆中
    void combine(BinomialHeap<T>* other);
    
    // 获取二项堆中的最小节点的键值
    T minimum();
    // 二项堆中是否包含键值key
    bool contains(T key);
    // 打印二项堆
    void print();
private:
    
    // 合并两个二项堆：将child合并到root中
    void link(BinomialNode<T>* child, BinomialNode<T>* root);
    // 将h1, h2中的根表合并成一个按度数递增的链表，返回合并后的根节点
    BinomialNode<T>* merge(BinomialNode<T>* h1, BinomialNode<T>* h2);
    // 合并二项堆：将h1, h2合并成一个堆，并返回合并后的堆
    BinomialNode<T>* combine(BinomialNode<T>* h1, BinomialNode<T>* h2);
    // 反转二项堆root，并返回反转后的根节点
    BinomialNode<T>* reverse(BinomialNode<T>* root);
    // 移除二项堆root中的最小节点，并返回删除节点后的二项树
    BinomialNode<T>* extractMinimum(BinomialNode<T>* root);
    // 删除节点：删除键值为key的节点，并返回删除节点后的二项树
    BinomialNode<T>* remove(BinomialNode<T> *root, T key);
    // 在二项树root中查找键值为key的节点
    BinomialNode<T>* search(BinomialNode<T>* root, T key);
    
    // 增加关键字的值：将二项堆中的节点node的键值增加为key。
    void increaseKey(BinomialNode<T>* node, T key);
    // 减少关键字的值：将二项堆中的节点node的键值减小为key
    void decreaseKey(BinomialNode<T>* node, T key);
    // 更新关键字的值：更新二项堆的节点node的键值为key
    void updateKey(BinomialNode<T>* node, T key);
    
    // 获取二项堆中的最小根节点
    void minimum(BinomialNode<T>* root, BinomialNode<T> *&prev_y, BinomialNode<T> *&y);
    // 打印二项堆
    void print(BinomialNode<T>* node, BinomialNode<T>* prev, int direction);
};

/*
 * 构造函数
 */
template <class T>
BinomialHeap<T>::BinomialHeap():mRoot(NULL)
{
}

/*
 * 析构函数
 */
template <class T>
BinomialHeap<T>::~BinomialHeap()
{
}

/*
 * 获取二项堆中的最小根节点
 *
 * 参数说明：
 *     root    -- 二项堆
 *     prev_y  -- [输出参数]最小根节点y的前一个根节点
 *     y       -- [输出参数]最小根节点
 */
template <class T>
void BinomialHeap<T>::minimum(BinomialNode<T>* root,
                              BinomialNode<T> *&prev_y, BinomialNode<T> *&y)
{
    BinomialNode<T> *x, *prev_x;    // x是用来遍历的当前节点
    
    if (root==NULL)
        return ;
    
    prev_x  = root;
    x       = root->next;
    prev_y = NULL;
    y      = root;
    // 找到最小节点
    while (x != NULL) {
        if (x->key < y->key) {
            y = x;
            prev_y = prev_x;
        }
        prev_x = x;
        x = x->next;
    }
}

/*
 * 获取二项堆中的最小节点的键值
 */
template <class T>
T BinomialHeap<T>::minimum()
{
    BinomialNode<T> *prev_y, *y;
    
    minimum(mRoot, prev_y, y);
    
    return y->key;
}


/*
 * 合并两个二项堆：将child合并到root中
 */
template <class T>
void BinomialHeap<T>::link(BinomialNode<T>* child, BinomialNode<T>* root)
{
    child->parent = root;
    child->next   = root->child;
    root->child = child;
    root->degree++;
}

/*
 * 将h1, h2中的根表合并成一个按度数递增的链表，返回合并后的根节点
 */
template <class T>
BinomialNode<T>* BinomialHeap<T>::merge(BinomialNode<T>* h1, BinomialNode<T>* h2)
{
    BinomialNode<T>* root = NULL; //heap为指向新堆根结点
    BinomialNode<T>** pos = &root;
    
    while (h1 && h2)
    {
        if (h1->degree < h2->degree)
        {
            *pos = h1;
            h1 = h1->next;
        }
        else
        {
            *pos = h2;
            h2 = h2->next;
        }
        pos = &(*pos)->next;
    }
    if (h1)
        *pos = h1;
    else
        *pos = h2;
    
    return root;
}

/*
 * 合并二项堆：将h1, h2合并成一个堆，并返回合并后的堆
 */
template <class T>
BinomialNode<T>* BinomialHeap<T>::combine(BinomialNode<T>* h1, BinomialNode<T>* h2)
{
    BinomialNode<T> *root;
    BinomialNode<T> *prev_x, *x, *next_x;
    
    // 将h1, h2中的根表合并成一个按度数递增的链表root
    root = merge(h1, h2);
    if (root == NULL)
        return NULL;
    
    prev_x = NULL;
    x      = root;
    next_x = x->next;
    
    while (next_x != NULL)
    {
        if (   (x->degree != next_x->degree)
            || ((next_x->next != NULL) && (next_x->degree == next_x->next->degree)))
        {
            // Case 1: x->degree != next_x->degree
            // Case 2: x->degree == next_x->degree == next_x->next->degree
            prev_x = x;
            x = next_x;
        }
        else if (x->key <= next_x->key)
        {
            // Case 3: x->degree == next_x->degree != next_x->next->degree
            //      && x->key    <= next_x->key
            x->next = next_x->next;
            link(next_x, x);
        }
        else
        {
            // Case 4: x->degree == next_x->degree != next_x->next->degree
            //      && x->key    >  next_x->key
            if (prev_x == NULL)
            {
                root = next_x;
            }
            else
            {
                prev_x->next = next_x;
            }
            link(x, next_x);
            x = next_x;
        }
        next_x = x->next;
    }
    
    return root;
}

/*
 * 将二项堆other合并到当前堆中
 */
template <class T>
void BinomialHeap<T>::combine(BinomialHeap<T> *other)
{
    if (other!=NULL && other->mRoot!=NULL)
        mRoot = combine(mRoot, other->mRoot);
}

/*
 * 新建key对应的节点，并将其插入到二项堆中。
 */
template <class T>
void BinomialHeap<T>::insert(T key)
{
    BinomialNode<T>* node;
    
    // 禁止插入相同的键值
    if (contains(key))
    {
        cout << "Insert Error: the key (" << key << ") is existed already!" << endl;
        return ;
    }
    
    node = new BinomialNode<T>(key);
    if (node==NULL)
        return ;
    
    mRoot = combine(mRoot, node);
}

/*
 * 反转二项堆root，并返回反转后的根节点
 */
template <class T>
BinomialNode<T>* BinomialHeap<T>::reverse(BinomialNode<T>* root)
{
    BinomialNode<T>* next;
    BinomialNode<T>* tail = NULL;
    
    if (!root)
        return root;
    
    root->parent = NULL;
    while (root->next)
    {
        next          = root->next;
        root->next = tail;
        tail          = root;
        root          = next;
        root->parent  = NULL;
    }
    root->next = tail;
    
    return root;
}

/*
 * 移除二项堆root中的最小节点，并返回删除节点后的二项树
 */
template <class T>
BinomialNode<T>* BinomialHeap<T>::extractMinimum(BinomialNode<T>* root)
{
    BinomialNode<T> *y, *prev_y;    // y是最小节点
    
    if (root==NULL)
        return root;
    
    // 找到"最小节点根y"和"它的前一个根节点prev_y"
    minimum(root, prev_y, y);
    
    if (prev_y == NULL)    // root的根节点就是最小根节点
        root = root->next;
    else                // root的根节点不是最小根节点
        prev_y->next = y->next;
    
    // 反转最小节点的左孩子，得到最小堆child；
    // 这样，就使得最小节点所在二项树的孩子们都脱离出来成为一棵独立的二项树(不包括最小节点)
    BinomialNode<T>* child = reverse(y->child);
    // 将"删除最小节点的二项堆child"和"root"进行合并。
    root = combine(root, child);
    
    // 删除最小节点
    delete y;
    
    return root;
}

template <class T>
void BinomialHeap<T>::extractMinimum()
{
    mRoot = extractMinimum(mRoot);
}

/*
 * 减少关键字的值：将二项堆中的节点node的键值减小为key。
 */
template <class T>
void BinomialHeap<T>::decreaseKey(BinomialNode<T>* node, T key)
{
    if(key>=node->key || contains(key))
    {
        cout << "decrease failed: the new key(" << key <<") is existed already, "
        << "or is no smaller than current key(" << node->key <<")" << endl;
        return ;
    }
    node->key = key;
    
    BinomialNode<T> *child, *parent;
    child = node;
    parent = node->parent;
    while(parent != NULL && child->key < parent->key)
    {
        swap(parent->key, child->key);
        child = parent;
        parent = child->parent;
    }
}

/*
 * 增加关键字的值：将二项堆中的节点node的键值增加为key。
 */
template <class T>
void BinomialHeap<T>::increaseKey(BinomialNode<T>* node, T key)
{
    if(key<=node->key || contains(key))
    {
        cout << "decrease failed: the new key(" << key <<") is existed already, "
        << "or is no greater than current key(" << node->key <<")" << endl;
        return ;
    }
    
    node->key = key;
    
    BinomialNode<T> *cur, *child, *least;
    cur = node;
    child = cur->child;
    while (child != NULL)
    {
        if(cur->key > child->key)
        {
            // 如果"当前节点" < "它的左孩子"，
            // 则在"它的孩子中(左孩子 和 左孩子的兄弟)"中，找出最小的节点；
            // 然后将"最小节点的值" 和 "当前节点的值"进行互换
            least = child;
            while(child->next != NULL)
            {
                if (least->key > child->next->key)
                {
                    least = child->next;
                }
                child = child->next;
            }
            // 交换最小节点和当前节点的值
            swap(least->key, cur->key);
            
            // 交换数据之后，再对"原最小节点"进行调整，使它满足最小堆的性质：父节点 <= 子节点
            cur = least;
            child = cur->child;
        }
        else
        {
            child = child->next;
        }
    }
}

/*
 * 更新二项堆的节点node的键值为key
 */
template <class T>
void BinomialHeap<T>::updateKey(BinomialNode<T>* node, T key)
{
    if (node == NULL)
        return ;
    
    if(key < node->key)
        decreaseKey(node, key);
    else if(key > node->key)
        increaseKey(node, key);
    else
        cout <<"No need to update!!!" <<endl;
}

/*
 * 将二项堆中键值oldkey更新为newkey
 */
template <class T>
void BinomialHeap<T>::update(T oldkey, T newkey)
{
    BinomialNode<T> *node;
    
    node = search(mRoot, oldkey);
    if (node != NULL)
        updateKey(node, newkey);
}

/*
 * 查找：在二项堆中查找键值为key的节点
 */
template <class T>
BinomialNode<T>* BinomialHeap<T>::search(BinomialNode<T>* root, T key)
{
    BinomialNode<T> *child;
    BinomialNode<T> *parent = root;
    
    parent = root;
    while (parent != NULL)
    {
        if (parent->key == key)
            return parent;
        else
        {
            if((child = search(parent->child, key)) != NULL)
                return child;
            parent = parent->next;
        }
    }
    
    return NULL;
}

/*
 * 二项堆中是否包含键值key
 */
template <class T>
bool BinomialHeap<T>::contains(T key)
{
    return search(mRoot, key)!=NULL ? true : false;
}

/*
 * 删除节点：删除键值为key的节点
 */
template <class T>
BinomialNode<T>* BinomialHeap<T>::remove(BinomialNode<T>* root, T key)
{
    BinomialNode<T> *node;
    BinomialNode<T> *parent, *prev, *pos;
    
    if (root==NULL)
        return root;
    
    // 查找键值为key的节点
    if ((node = search(root, key)) == NULL)
        return root;
    
    // 将被删除的节点的数据数据上移到它所在的二项树的根节点
    parent = node->parent;
    while (parent != NULL)
    {
        // 交换数据
        swap(node->key, parent->key);
        // 下一个父节点
        node   = parent;
        parent = node->parent;
    }
    
    // 找到node的前一个根节点(prev)
    prev = NULL;
    pos  = root;
    while (pos != node)
    {
        prev = pos;
        pos  = pos->next;
    }
    // 移除node节点
    if (prev)
        prev->next = node->next;
    else
        root = node->next;
    
    root = combine(root, reverse(node->child));
    
    delete node;
    
    return root;
}

template <class T>
void BinomialHeap<T>::remove(T key)
{
    mRoot = remove(mRoot, key);
}



/*
 * 打印"二项堆"
 *
 * 参数说明：
 *     node       -- 当前节点
 *     prev       -- 当前节点的前一个节点(父节点or兄弟节点)
 *     direction  --  1，表示当前节点是一个左孩子;
 *                    2，表示当前节点是一个兄弟节点。
 */
template <class T>
void BinomialHeap<T>::print(BinomialNode<T>* node, BinomialNode<T>* prev, int direction)
{
    while(node != NULL)
    {
        if(direction==1)    // node是根节点
            cout << "\t" << setw(2) << node->key << "(" << node->degree << ") is "<< setw(2) << prev->key << "'s child" << endl;
        else                // node是分支节点
            cout << "\t" << setw(2) << node->key << "(" << node->degree << ") is "<< setw(2) << prev->key << "'s next" << endl;
        
        if (node->child != NULL)
            print(node->child, node, 1);
        
        // 兄弟节点
        prev = node;
        node = node->next;
        direction = 2;
    }
}

template <class T>
void BinomialHeap<T>::print()
{
    BinomialNode<T> *p;
    if (mRoot == NULL)
        return ;
    
    cout << "== 二项堆( ";
    p = mRoot;
    while (p != NULL)
    {
        cout << "B" << p->degree << " ";
        p = p->next;
    }
    cout << ")的详细信息：" << endl;
    
    int i=0;
    p = mRoot;
    while (p != NULL)
    {
        i++;
        cout << i << ". 二项树B" << p->degree << ":" << endl;
        cout << "\t" << setw(2) << p->key << "(" << p->degree << ") is root" << endl;
        
        print(p->child, p, 1);
        p = p->next;
    }
    cout << endl;
}
#endif