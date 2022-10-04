#include "stack_interface.h"
#include "Node.h"

template<class ItemType>
class Stack : public StackInterface<ItemType> {
private:
    int itemCount;
    Node<ItemType>* headptr;
public: 
    Stack() {
        itemCount = 0;
        headptr = nullptr;
    }// End Def ctor

    // Stack(const Stack &old_stack){
    //     //cpy ctor with deep copy.
    //     headptr = nullptr;
    //     itemCount = 0;
    //     // NEED TO DEEP COPY HERE
    // }

    bool isEmpty() const {return (itemCount == 0);} //end isEmpty

    bool push(const ItemType& newEntry) {
        Node<ItemType>* newNodePtr = new Node<ItemType>;//Create new node
        newNodePtr->setItem(newEntry);//load item into it
        newNodePtr->setNext(headptr); //Make it pointing at prev first item
        headptr = newNodePtr; //Make it beginning of line by having head pnt at it
        itemCount++; // Update item count
        return true;
    } // End push

    bool pop() {
        if(isEmpty()) return false; //Cannot remove something if there is nothing.
        Node<ItemType>* delnodeptr = headptr; //Point at first item(The item to remove)
        headptr=headptr->getNext(); //"Remove" The first item from the list 
        delnodeptr->setNext(nullptr); 
        delete delnodeptr; // Delete the previous first item
        itemCount--; //Update item count
        return true;

    } // End pop

    ItemType peek() const {return headptr->getItem();}

    void display(){
        Node<ItemType>* tmpPtr = headptr;
        for(int ele_index = 0; ele_index < itemCount; ele_index++){
            std::cout << "[" << ele_index + 1 << "]: " << tmpPtr->getItem() << std::endl;
            tmpPtr = tmpPtr->getNext();
        }
    } //End Display

    void clear() {
        while(!isEmpty()){
            pop();
        }
    } // End clear

    ~Stack() { clear(); } //Destructor
};