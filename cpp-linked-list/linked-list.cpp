#include <iostream>

class Node
{
  private:
    int32_t data;
    Node*   next = nullptr;

  public:
    Node( int32_t data ) : data{ data } {}

    void insertNodeAtEnd( int32_t value )
    {
        Node* currNode = this;

        // We iterate over the list to find the last node
        while ( currNode->next != nullptr )
        {
            currNode = currNode->next;
        }

        // At this point we reached the end
        Node* newNode  = new Node( value );
        currNode->next = newNode;
    }

    Node* insertNodeAtHead( int32_t value )
    {
        // We know that we have to add the new node at the beginning
        // We just need to adjust the next element of the new node to point to
        // the last head
        Node* newNode = new Node( value );
        newNode->next = this;

        return newNode;
    }

    Node* deleteNode( int32_t value )
    {
        // If the head node contains the value we want to delete
        if ( data == value )
        {
            Node* newHead = next;
            delete this;
            return newHead;
        }

        Node* currNode = this;

        while ( currNode->next != nullptr )
        {
            if ( currNode->next->data == value )
            {
                // We save the address of the node which is to be deleted in tmp
                Node* tmp = currNode->next;

                // We adjust the next of the current node pointing to the node
                // after the to be deleted one Basically we just skip the node
                // in between
                currNode->next = currNode->next->next;
                delete tmp;
                return this;
            }

            currNode = currNode->next;
        }

        return this;
    }

    bool searchNode( int32_t value )
    {
        Node* currNode = this;
        while ( currNode != nullptr )
        {
            if ( currNode->data == value )
            {
                return true;
            }

            currNode = currNode->next;
        }

        return false;
    }

    bool isEmpty() { return ( next == nullptr ); }

    int32_t getSize()
    {
        int32_t len{ 0 };
        auto*   node = this;

        while ( node != nullptr )
        {
            len++;
            node = node->next;
        }

        return len;
    }

    void showList()
    {
        Node*   currNode = this;
        int32_t index{ 0 };
        while ( currNode != nullptr )
        {
            std::cout << " -- N(" << index++ << ") Val(" << currNode->data
                      << ") -- " << std::endl;
            currNode = currNode->next;
        }
    }
};

int main()
{

    Node* head = new Node( 0 );

    head->insertNodeAtEnd( 1 );
    head->insertNodeAtEnd( 2 );
    head->insertNodeAtEnd( 3 );
    head = head->insertNodeAtHead( 5 );

    std::cout << "Original List:" << std::endl;
    head->showList();

    // Delete a node
    head = head->deleteNode( 2 );
    std::cout << "After deleting node with value 2:" << std::endl;
    head->showList();

    int32_t searchValue = 2;
    if ( head->searchNode( searchValue ) )
    {
        std::cout << "Node with value " << searchValue << " found."
                  << std::endl;
    }
    else
    {
        std::cout << "Node with value " << searchValue << " not found."
                  << std::endl;
    }

    return 0;
}