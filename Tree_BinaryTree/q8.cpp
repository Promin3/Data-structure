//
// Created by 朱俊杰 on 2022/11/9.
//

#include <cstddef>
#include "vector"
using namespace std;
struct Node{
    int data;
    Node* lchild;
    Node* rchild;
    Node(int _data){
        data=_data;
        lchild=NULL;
        rchild=NULL;
    }
};
vector<int> layer,in;
int n;

Node* buildBiTree(vector<int> layer,vector<int> in,int inL,int inR)
{
    if(layer.size()==0 || inL>inR) return nullptr;
    int rootVal=layer[0];
    Node* root=new Node(rootVal);
    int pos=inL;
    while(in[pos]!=rootVal) pos++;

    vector<int> layerLeft,layerRight;//存放左、右子树的层序序列
    for(int i=1;i<layer.size();i++){
        int j;
        for(j=inL;j<pos;j++){
            if(layer[i]==in[j]){
                layerLeft.push_back(layer[i]);  //如果在pos前找到，插入左子树
                break;
            }
        }
        if(j==pos) layerRight.push_back(layer[i]);  //超过pos，插入右子树（层序遍历保持左右子树层序遍历顺序的一致性）
    }
    root->lchild=buildBiTree(layerLeft,in,inL,pos-1);
    root->rchild=buildBiTree(layerRight,in,pos+1,inR);

    return root;
}