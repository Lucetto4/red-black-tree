#include "redBlackTree.h"
#include <iostream>
using namespace std;    
    
    redBlackTree::redBlackTree(){

    }
    
    redBlackTree::~redBlackTree(){
    rbdestructor(root);
    }
    void redBlackTree::rbdestructor(Node* curr){
        if(curr!=nullptr){
            rbdestructor(curr->left);
            rbdestructor(curr->right);
            delete curr;
        }
    }
    void redBlackTree::insert(int value){
        Node* curr=root;
        Node*parent =nullptr;
        while(curr!=nullptr){
        parent=curr;
        if(value>curr->data){
            curr=curr->right;
        }
        else if(value<curr->data){
            curr=curr->left;
        }
        else{
            curr->count++;
            return;
        }
        }

        Node* newN=new Node;
        newN->color=true;
        newN->data=value;
        newN->left=nullptr;
        newN->right=nullptr;
        newN->parent = parent;
        newN->count=1;
        if (parent==nullptr){
            root=newN;
        }
        else if(value>parent->data){
            parent->right=newN;
        }
        else{
            parent->left=newN;
        }
        insFix(newN);
        
    }
    void redBlackTree::insFix(Node* newN){
        while(newN!=root&& newN->parent->color==true){
            Node* Par=newN->parent;
            Node* Gp =Par->parent;
            if(!Gp){
                break;
            }
            Node* Unc;
            if(Par==Gp->left){
                Unc=Gp->right;
            }
            else{
                Unc=Gp->left;
            }  

            if(Unc&&Unc->color==true){
                Par->color=false;
                Unc->color=false;
                Gp->color=true;
                newN = Gp;
            }
            else{
                if(Par==Gp->left&&newN==Par->right){
                    rotateLeft(Par);
                    newN = Par;
                    Par = newN->parent;
                    if (Par != nullptr) {
                    Gp = Par->parent;}
                    else{Gp = nullptr;}
                    if (!Gp) break;
                }
                else if(Par==Gp->right&&newN==Par->left){
                    rotateRight(Par);
                    newN = Par;
                    Par = newN->parent;
                    if (Par != nullptr) {
                    Gp = Par->parent;}
                    else{Gp = nullptr;}
                    if (!Gp) break;
                }
                Par->color=false;
                Gp->color=true;

                if(Par==Gp->left){
                    rotateRight(Gp);
                }
                else if(Par==Gp->right){
                    rotateLeft(Gp);
                }
            }
                
        }
        if (root) root->color = false;
    }
    void redBlackTree::rotateLeft(Node* current){
        if(!current||current->right==nullptr){
            return;
        }
        Node*update =current->right;
        if(update->left){
            update->left->parent=current;
        }
         if(current->parent==nullptr){
            root =update;
        }
        else if(current->parent->left==current){
            current->parent->left=update;
        }
        else{
             current->parent->right=update;
        }
        
        current->right=update->left;
        update->left=current;
        update->parent=current->parent;
        current->parent=update;
       
    }
    void redBlackTree::rotateRight(Node* current){
         if(!current||current->left==nullptr){
            return;
        }
        Node*update =current->left;
        if(update->right){
            update->right->parent=current;
        }
         if(current->parent==nullptr){
            root =update;
        }
        else if(current->parent->right==current){
            current->parent->right=update;
        }
        else{
             current->parent->left=update;
        }
       
        current->left=update->right;
        update->right=current;
        update->parent=current->parent;
        current->parent=update;
       

    }
    
    void redBlackTree::remove(int value){

    }
    void redBlackTree::print(){
        cout<<"Printed tree in order: ";
        printfunc(root);
        cout<<endl;
    }
    void redBlackTree::printfunc(Node* curr){
        if(curr!=nullptr){
            printfunc(curr->left);
            string color;
            if(curr->color==true){
                color="R";
            }
            else{
                color="B";
            }
            cout<<color<<":"<<curr->data<<" ";
            printfunc(curr->right);
            
        }
    }
    void redBlackTree::getValCount(int value){
         Node* curr = root;
    while (curr) {
        if (value < curr->data) {
            curr = curr->left;
        } else if (value > curr->data) {
            curr = curr->right;
        } else {
            cout << value << " occurs " << curr->count << " time"<< (curr->count == 1 ? "" : "s") <<endl;
            return;
        }
    }
    cout << value << " not found"<<endl;    }