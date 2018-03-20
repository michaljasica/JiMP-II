//
// Created by malikmontana on 15.03.18.
//

#include <cmath>
#include "SmartTree.h"

namespace datastructures{


    std::unique_ptr <SmartTree> CreateLeaf(int value){
        auto wsk = std::make_unique<SmartTree>();
        wsk->left= nullptr;
        wsk->right= nullptr;
        wsk->value=value;
        return wsk;
    }

    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        tree->left=move(left_subtree);
        return tree;
    }

    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        tree->right=move(right_subtree);
        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if (unique_ptr!= nullptr){
            if(unique_ptr->left!= nullptr)
                PrintTreeInOrder(unique_ptr->left,out);
            *out<<unique_ptr->value<<", ";
            if(unique_ptr->right!= nullptr)
                PrintTreeInOrder(unique_ptr->right,out);
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree){
        std::string tmp;

        tmp+="["+std::to_string(tree->value)+" ";

        if(tree->left!= nullptr)
            tmp+=DumpTree(tree->left);
        else
            tmp+="[none]";

        tmp+=" ";
        if(tree->right!= nullptr)
            tmp+=DumpTree(tree->right);
        else
            tmp+="[none]";
        tmp+="]";

        return tmp;
    }

    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree){
        if(tree.length()==0)
            return nullptr;

        std::string tmp,left="[",right="[";
        int bracket=1;
        int i,value=0;

        for (i=0;i<tree.length();i++){
            if(isdigit(tree[i]))
                tmp+=tree[i];
            if(tree[i]=='n' || tree[i]=='o' || tree[i]=='e')
                tmp+=tree[i];
            if(tree[i]==' ')
                break;
        }

        for(i=i+2;i<tree.length();i++){
            left+=tree[i];

            if(tree[i]=='[')
                bracket+=1;
            if(tree[i]==']')
                bracket-=1;

            if(bracket==0)
                break;
        }

        bracket=1;
        for(i=i+3;i<tree.length();i++){
            right+=tree[i];

            if(tree[i]=='[')
                bracket+=1;
            if(tree[i]==']')
                bracket-=1;

            if(bracket==0)
                break;
        }

        if(tmp[0]=='n')
            return nullptr;

        for (int i=tmp.length()-1;i>=0;i--){
            value+=(tmp[i]-48)*pow(10,tmp.length()-i-1);
        }

        if(tree[1]=='-')
            value=0-value;

        std::unique_ptr <SmartTree> parent = CreateLeaf(value);
        parent->left=RestoreTree(left);
        parent->right=RestoreTree(right);

        return parent;
    }

}