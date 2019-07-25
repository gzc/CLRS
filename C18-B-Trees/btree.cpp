#include<iostream>
#include<stack>
#include<queue>
using namespace std;

//#define DEBUG 1

/************************************************************************
 *                                                                      *
 *                              I provided these API                    *
 * 1. B_tree_insert(T k)                                                *
 * 2. PrintTree(int kind)                                               *
 * 3. get_minimum()                                                     *
 * 4. get_maximum()                                                     *
 * 5. search(T k)                                                       *
 * 6. bool remove(const T &key)                                         *
 ************************************************************************/
 

template<class T>
class Btree
{
private:
    static const int t = 3;
    
    struct Node
    {
        bool isLeaf;
        int n;
        T keyValue[t+1];
        Node *pChild[2*t+1];
        
        Node(bool b=true, int _n=0) : isLeaf(b), n(_n){}
    };
    
    Node *bRoot;
    
    //statistics
    int nodeNum;
    
public:
    Btree()
    {
        nodeNum = 0;
        B_tree_create();
    }
    
    void viewStatistics()
    {
        cout << "-----------------------------Statistics-----------------------------" << endl;
        cout << "BUILD " << nodeNum << " nodes" << endl;
        cout << "-----------------------------Statistics-----------------------------" << endl;
    }
    
    void B_tree_insert(T k)
    {
        Node *r = bRoot;
        if (r->n == 2*t - 1)
        {
            Node *s = allocate_node();
            bRoot = s;
            s->isLeaf = false;
            s->pChild[1] = r;
            B_tree_split_child(s, 1, r);
            B_tree_insert_nonfull(s, k);
        } else {
            B_tree_insert_nonfull(r, k);
        }
    }
    
    /*
     * 1 means integer
     * 2 means character
     */
    void PrintTree(int kind = 1) const //打印树的关键字
    {
        queue<Node*> myqueue;
        myqueue.push(bRoot);
        int depth = 0;
        
        while(!myqueue.empty())
        {
            queue<Node*> nextlevel;
            cout << "depth : " << depth << endl;
            
            while(!myqueue.empty())
            {
                Node* temp = myqueue.front();
                myqueue.pop();
                
                cout << "[";
                for(int i = 1;i <= temp->n;i++)
                {
                    if(kind == 2)cout << (char)temp->keyValue[i] << " ";
                    else cout << temp->keyValue[i] << " ";
                }
                cout << "]";
                
                if(!temp->isLeaf)
                    for(int i = 1;i <= temp->n+1;i++)
                        nextlevel.push(temp->pChild[i]);
            }
            cout << endl;
            depth++;
            myqueue = nextlevel;
        }
    }
    
    T get_minimum() const
    {
        return B_TREE_FIND_MIN(bRoot);
    }
    
    T get_maximum() const
    {
        return B_TREE_FIND_MAX(bRoot);
    }
    
    bool search(T k)
    {
        int index = 0;
        Node *temp = B_tree_search(bRoot, k, &index);
        if(temp != nullptr) return true;
        return false;
    }
    
    //just test predecessor
    
    /*
    T get_root_pre()
    {
        return B_tree_find_predecessor(bRoot, 1);
    }
     */
    
    bool remove(const T &key)    //从B中删除结点key
    {
        if (!search(key))  //不存在
        {
            return false;
        }
        
        if (bRoot->n == 1 && bRoot->isLeaf)//特殊情况处理
        {
            clear();
            return true;
        }
        recursive_remove(bRoot, key);
        return true;
    }
    
    void clear()                      //清空B树
    {
        recursive_clear(bRoot);
        bRoot = nullptr;
    }
    
    //删除节点
    void deleteNode(Node *pNode)
    {
        if (pNode != nullptr)
        {
            delete pNode;
            pNode = nullptr;
        }
    }
    
private:
    
    Node *allocate_node()
    {
        Node *node = new Node();
        nodeNum++;
        
#ifdef DEBUG
        cout << "allocate a new node" << endl;
#endif
        
        return node;
    }
    
    void disk_write(Node *x) const
    {
#ifdef DEBUG
        cout << "write disk" << endl;
#endif
    }
    
    void disk_read(Node *x) const
    {
#ifdef DEBUG
        cout << "read disk" << endl;
#endif
    }
    
    void B_tree_create()
    {
        bRoot = allocate_node();
        disk_write(bRoot);
    }
    
    void B_tree_split_child(Node *x, int i, Node *y)
    {
        Node *z = allocate_node();
        z->isLeaf = y->isLeaf;
        z->n = t - 1;
        
        for(int j = 1; j <= t-1; j++)
            z->keyValue[j] = y->keyValue[j+t];
        
        if (!y->isLeaf)
            for(int j = 1;j <= t;j++)
                z->pChild[j] = y->pChild[j+t];
        
        y->n = t - 1;
        for(int j = x->n+1;j >= i+1;j--)
            x->pChild[j+1] = x->pChild[j];
        x->pChild[i+1] = z;
        for(int j = x->n;j >= i;j--)
            x->keyValue[j+1] = x->keyValue[j];
        x->keyValue[i] = y->keyValue[t];
        x->n++;
        
        disk_write(y);
        disk_write(z);
        disk_write(x);
    }
    
    void B_tree_insert_nonfull(Node *x, T k)
    {
        int i = x->n;
        
        if(x->isLeaf)
        {
            while(i >= 1 && k < x->keyValue[i])
            {
                x->keyValue[i+1] = x->keyValue[i];
                i--;
            }
            x->keyValue[i+1] = k;
            x->n++;
            disk_write(x);
        } else {
            while(i >= 1 && k < x->keyValue[i]) i--;
            i++;
            disk_read(x->pChild[i]);
            if(x->pChild[i]->n == 2*t - 1)
            {
                B_tree_split_child(x, i, x->pChild[i]);
                if(k > x->keyValue[i])
                    i++;
            }
            B_tree_insert_nonfull(x->pChild[i], k);
        }
    }
    
    /*
     *find the minimum key in btree
     */
    T B_TREE_FIND_MIN(Node *x) const
    //PRE: x is a node on the B-tree T. The top level call is B-TREE-FIND-MIN(T.root).
    {
        if (x == nullptr)
        {
            cerr << "The tree is empty" << endl;
            return -1;
        } else if (x->isLeaf) //x is leaf
        {
            return x->keyValue[1]; //return the minimum key of x
        } else
        {
            disk_read(x->pChild[1]);
            return B_TREE_FIND_MIN(x->pChild[1]);
        }
    }
    
    /*
     *find the maximum key in btree
     */
    T B_TREE_FIND_MAX(Node *x) const
    {
        if (x == nullptr)
        {
            cerr << "The tree is empty" << endl;
            return -1;
        } else if (x->isLeaf) //x is leaf
        {
            return x->keyValue[x->n]; //return the minimum key of x
        } else
        {
            disk_read(x->pChild[x->n+1]);
            return B_TREE_FIND_MAX(x->pChild[x->n+1]);
        }
    }
    
    T B_tree_find_predecessor(Node *x, int i)
    {
        if(!x->isLeaf)
        {
            disk_read(x->pChild[i]);
            return B_TREE_FIND_MAX(x->pChild[i]);
        } else if(i > 1){
            return x->keyValue[i-1];
        } else {
            Node *z = x;
            stack<Node*> mystack;
            buildPath(bRoot, x->keyValue[i], mystack);
            
            while(1)
            {
                if(mystack.empty())
                {
                    cerr << "No predecessor";
                    return -1;
                }
                
                Node *y = mystack.top();
                mystack.pop();
                int j = 1;
                disk_read(y->pChild[1]);
                
                while(y->pChild[j] != x)
                {
                    j++;
                    disk_read(y->pChild[j]);
                }
                
                if(j == 1) z = y;
                else return y->keyValue[j-1];
            }
        }
    }
    
    void buildPath(Node *x, T k, stack<Node*>& mystack)
    {
        int i = 1;
        while(i <= x->n && k > x->keyValue[i]) i++;
        if (i <= x->n && k == x->keyValue[i]) return;
        if (x->isLeaf) return;
        else
        {
            disk_read(x->pChild[i]);
            mystack.push(x);
            buildPath(x->pChild[i], k, mystack);
        }
    }
    
    Node* B_tree_search(Node *x, T k, int *index)
    {
        int i = 1;
        while(i <= x->n && k > x->keyValue[i]) i++;
        if (i <= x->n && k == x->keyValue[i])
        {
            *index = i;
            return x;
        }
        
        if (x->isLeaf) return nullptr;
        else
        {
            disk_read(x->pChild[i]);
            return B_tree_search(x->pChild[i], k, index);
        }
    }
    
    //删除树
    void recursive_clear(Node *pNode)
    {
        if (pNode != nullptr)
        {
            if (!pNode->isLeaf)
            {
                for(int i = 1; i <= pNode->n + 1; ++i)
                    recursive_clear(pNode->pChild[i]);
            }
            deleteNode(pNode);
        }
    }
    
    //递归的删除关键字
    void recursive_remove(Node *pNode, const T &key)
    {
        int i = 1;
        while(i <= pNode->n && key > pNode->keyValue[i])
            ++i;
        if (i <= pNode->n && key == pNode->keyValue[i])//关键字key在节点pNode中
        {
            if (pNode->isLeaf)//pNode是个叶节点
            {
                //从pNode中删除k
                pNode->n--;
                for (; i <= pNode->n; ++i)
                    pNode->keyValue[i] = pNode->keyValue[i+1];
                return;
            }
            else//pNode是个内节点
            {
                Node *pChildPrev = pNode->pChild[i];//节点pNode中前于key的子节点
                Node *pChildNext = pNode->pChild[i+1];//节点pNode中后于key的子节点
                if (pChildPrev->n >= t)//节点pChildPrev中至少包含CHILD_MIN个关键字
                {
                    T prevKey = getPredecessor(pChildPrev); //获取key的前驱关键字
                    recursive_remove(pChildPrev, prevKey);
                    pNode->keyValue[i] = prevKey;     //替换成key的前驱关键字
                    return;
                }
                else if (pChildNext->n >= t)//节点pChildNext中至少包含CHILD_MIN个关键字
                {
                    T nextKey = getSuccessor(pChildNext); //获取key的后继关键字
                    recursive_remove(pChildNext, nextKey);
                    pNode->keyValue[i] = nextKey;     //替换成key的后继关键字
                    return;
                }
                else//节点pChildPrev和pChildNext中都只包含CHILD_MIN-1个关键字
                {
                    mergeChild(pNode, i);
                    recursive_remove(pChildPrev, key);
                }
            }
        }
        else//关键字key不在节点pNode中
        {
            Node *pChildNode = pNode->pChild[i];//包含key的子树根节点
            if (pChildNode->n == t-1)//只有t-1个关键字
            {
                Node *pLeft = i > 1 ? pNode->pChild[i-1] : NULL;  //左兄弟节点
                Node *pRight = i <= pNode->n ? pNode->pChild[i+1] : NULL;//右兄弟节点
                int j;
                if (pLeft && pLeft->n >= t)//左兄弟节点至少有CHILD_MIN个关键字
                {
                    //父节点中i-1的关键字下移至pChildNode中
                    for (j = pChildNode->n+1; j > 1; --j)
                    {
                        pChildNode->keyValue[j] = pChildNode->keyValue[j-1];
                    }
                    pChildNode->keyValue[1] = pNode->keyValue[i-1];
                    
                    if (!pLeft->isLeaf)
                    {
                        for (j=pChildNode->n+2; j > 1; --j) //pLeft节点中合适的子女指针移植到pChildNode中
                        {
                            pChildNode->pChild[j] = pChildNode->pChild[j-1];
                        }
                        pChildNode->pChild[1] = pLeft->pChild[pLeft->n];
                    }
                    ++pChildNode->n;
                    pNode->keyValue[i] = pLeft->keyValue[pLeft->n];//pLeft节点中的最大关键字上升到pNode中
                    --pLeft->n;
                }
                else if (pRight && pRight->n >= t)//右兄弟节点至少有CHILD_MIN个关键字
                {
                    //父节点中i的关键字下移至pChildNode中
                    pChildNode->keyValue[pChildNode->n+1] = pNode->keyValue[i];
                    ++pChildNode->n;
                    pNode->keyValue[i] = pRight->keyValue[1];//pRight节点中的最小关键字上升到pNode中
                    --pRight->n;
                    for (j = 1; j <= pRight->n; ++j)
                    {
                        pRight->keyValue[j] = pRight->keyValue[j+1];
                    }
                    if (!pRight->isLeaf)
                    {
                        pChildNode->pChild[pChildNode->n+1] = pRight->pChild[1];//pRight节点中合适的子女指针移植到pChildNode中
                        for (j = 1; j <= pRight->n+1; ++j)
                        {
                            pRight->pChild[j] = pRight->pChild[j+1];
                        }
                    }
                }
                //左右兄弟节点都只包含CHILD_MIN-1个节点
                else if (pLeft)//与左兄弟合并
                {
                    mergeChild(pNode, i-1);
                    pChildNode = pLeft;
                }
                else if (pRight)//与右兄弟合并
                {
                    mergeChild(pNode, i);
                }
            }
            recursive_remove(pChildNode, key);
        }
    }
    
    //合并两个子节点
    void mergeChild(Node *pParent, int index)
    {
        Node *pChild1 = pParent->pChild[index];
        Node *pChild2 = pParent->pChild[index+1];
        //将pChild2数据合并到pChild1
        pChild1->n = 2*t-1;
        pChild1->keyValue[t] = pParent->keyValue[index];//将父节点index的值下移
        for (int i = 1; i <= t-1; ++i)
            pChild1->keyValue[t+i] = pChild2->keyValue[i];
        if (!pChild1->isLeaf)
            for (int i = 1; i <= t; ++i)
                pChild1->pChild[i+t] = pChild2->pChild[i];
        
        //父节点删除index的key，index后的往前移一位
        pParent->n--;
        for(int i = index; i <= pParent->n; ++i)
        {
            pParent->keyValue[i] = pParent->keyValue[i+1];
            pParent->pChild[i+1] = pParent->pChild[i+2];
        }
        deleteNode(pChild2);  //删除pChild2
        if(pParent->n == 0)
        {
            deleteNode(pParent);
            if (pParent == bRoot){
                bRoot = pChild1;
            }
        }
    }
    
    T getPredecessor(Node *pNode)//找到前驱关键字
    {
        while (!pNode->isLeaf)
        {
            pNode = pNode->pChild[pNode->n+1];
        }
        return pNode->keyValue[pNode->n];
    }
    
    T getSuccessor(Node *pNode)//找到后继关键字
    {
        while (!pNode->isLeaf)
        {
            pNode = pNode->pChild[1];
        }
        return pNode->keyValue[1];
    }
    
};


int main() {
    
    
    Btree<int> tree;
    
    for(int i = 1;i < 20;i++)
    {
        tree.B_tree_insert(i);
        //cout << " n = " << i << endl;
        //tree.viewStatistics();
    }
    
    tree.remove(19);
    tree.PrintTree();
    
    //cout << "The minimum key is : " << tree.get_minimum() << endl;
    //cout << "The maximum key is : " << tree.get_maximum() << endl;
    //cout << "The pre of the root is : " << tree.get_root_pre() << endl;
    
    /*
    bool fff = tree.search(5);
    if(fff)
    {
        cout << "find 5 in the tree " << endl;
    }
    */
    
    return 0;
}
