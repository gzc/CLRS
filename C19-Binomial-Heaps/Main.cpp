/**
 * C 语言: 二项堆
 *
 * @author skywang
 * @date 2014/04/02
 */

#include <iostream>
#include "BinomialHeap.h"
using namespace std;

#define DEBUG 0

// 共7个 = 1+2+4
int a[] = {12,  7, 25, 15, 28,
    33, 41};
// 共13个 = 1+4+8
int b[] = {18, 35, 20, 42,  9,
    31, 23,  6, 48, 11,
    24, 52, 13 };

// 验证"二项堆的插入操作"
void testInsert()
{
    int i;
    int alen=sizeof(a)/sizeof(a[0]);
    BinomialHeap<int>* ha=new BinomialHeap<int>();
    
    cout << "== 二项堆(ha)中依次添加: ";
    for(i=0; i<alen; i++)
    {
        cout << a[i] <<" ";
        ha->insert(a[i]);
    }
    cout << endl;
    cout << "== 二项堆(ha)的详细信息: " << endl;
    ha->print();
}

// 验证"二项堆的合并操作"
void testUnion()
{
    int i;
    int alen=sizeof(a)/sizeof(a[0]);
    int blen=sizeof(b)/sizeof(b[0]);
    BinomialHeap<int>* ha=new BinomialHeap<int>();
    BinomialHeap<int>* hb=new BinomialHeap<int>();
    
    cout << "== 二项堆(ha)中依次添加: ";
    for(i=0; i<alen; i++)
    {
        cout << a[i] <<" ";
        ha->insert(a[i]);
    }
    cout << endl;
    cout << "== 二项堆(ha)的详细信息: " << endl;
    ha->print();
    
    
    cout << "== 二项堆(hb)中依次添加: ";
    for(i=0; i<blen; i++)
    {
        cout << b[i] <<" ";
        hb->insert(b[i]);
    }
    cout << endl;
    cout << "== 二项堆(hb)的详细信息: " << endl;
    hb->print();
    
    
    // 将"二项堆hb"合并到"二项堆ha"中。
    ha->combine(hb);
    cout << "== 合并ha和hb后的详细信息: " << endl;
    ha->print();
}

// 验证"二项堆的删除操作"
void testDelete()
{
    int i;
    int blen=sizeof(b)/sizeof(b[0]);
    BinomialHeap<int>* hb=new BinomialHeap<int>();
    
    cout << "== 二项堆(hb)中依次添加: ";
    for(i=0; i<blen; i++)
    {
        cout << b[i] <<" ";
        hb->insert(b[i]);
    }
    cout << endl;
    cout << "== 二项堆(hb)的详细信息: " << endl;
    hb->print();
    
    
    // 将"二项堆hb"合并到"二项堆ha"中。
    hb->remove(20);
    cout << "== 删除节点20后的详细信息: " << endl;
    hb->print();
}

// 验证"二项堆的更新(减少)操作"
void testDecrease()
{
    int i;
    int blen=sizeof(b)/sizeof(b[0]);
    BinomialHeap<int>* hb=new BinomialHeap<int>();
    
    cout << "== 二项堆(hb)中依次添加: ";
    for(i=0; i<blen; i++)
    {
        cout << b[i] <<" ";
        hb->insert(b[i]);
    }
    cout << endl;
    cout << "== 二项堆(hb)的详细信息: " << endl;
    hb->print();
    
    
    // 将节点20更新为2
    hb->update(20, 2);
    cout << "== 更新节点20->2后的详细信息: " << endl;
    hb->print();
}

// 验证"二项堆的更新(增加)操作"
void testIncrease()
{
    int i;
    int blen=sizeof(b)/sizeof(b[0]);
    BinomialHeap<int>* hb=new BinomialHeap<int>();
    
    cout << "== 二项堆(hb)中依次添加: ";
    for(i=0; i<blen; i++)
    {
        cout << b[i] <<" ";
        hb->insert(b[i]);
    }
    cout << endl;
    cout << "== 二项堆(hb)的详细信息: " << endl;
    hb->print();
    
    
    // 将节点6更新为60
    hb->update(6, 60);
    cout << "== 更新节点6->60后的详细信息: " << endl;
    hb->print();
}

int main()
{
    // 1. 验证"二项堆的插入操作"
    testInsert();
    // 2. 验证"二项堆的合并操作"
    //testUnion();
    // 3. 验证"二项堆的删除操作"
    //testDelete();
    // 4. 验证"二项堆的更新(减少)操作"
    //testDecrease();
    // 5. 验证"二项堆的更新(增加)操作"
    //testIncrease();
    
    return 0;
}