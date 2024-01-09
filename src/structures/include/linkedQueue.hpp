#pragma once

/** @file LinkedQueue.hpp
 *  @brief A class for a queue created from linked lists
 *  @author Momchil Mladenov, 5MI0800232, Group 3
*/

/**
 * @class LinkedQueue
*/

template <class T>
class LinkedQueue
{
private:
    /**
     * @struct Node
    */
    struct Node
    {
        T value; //!< Templated storage of the node's value
        Node* next; //!< Pointer to the next node
        Node* previous; //!< Pointer to the prevoius node

        //! Constructor for node with given deafult values if left blank
        Node(const T& value, Node* next = nullptr, Node* previous = nullptr)
            : value(value), next(next), previous(previous) {}
    };

    Node* frontNode; //!< Pointer to the first node in list
    Node* backNode; //!< Pointer to the last node in list

    //! Dealocation of the member and all descendents
    void deallocate()
    {
        while (!this->empty()) 
        {
            this->dequeue();
        }
    }

    //! Copy constructor
    //! @param other The list the deep copy is made of
    void copy(const LinkedQueue<T>& other)
    {
        Node* temp = other.frontNode;

        while (temp)
        {
            this->enqueue(temp->value);
            temp = temp->next;
        }
    }

public:
    //! Default constructor
    LinkedQueue() : frontNode(nullptr), backNode(nullptr) {}

    //! Copy constructor
    LinkedQueue(const LinkedQueue<T>& other)
        : LinkedQueue() 
    {
        this->copy(other);
    }

    //! Operator =
    LinkedQueue& operator = (const LinkedQueue<T>& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }
    
    //! Shows the element in the front of the list
    //! @return Said element
    const T& front() const
    {
        if (this->empty()) 
        {
            throw std::out_of_range("Queue is empty");
        }
        return this->frontNode->value;
    }

    //! Removes the element in the front of the list
    void dequeue()
    {
        if (this->empty()) 
        {
            throw std::out_of_range("Queue is empty");
        }

        Node* temp = this->frontNode;
        this->frontNode = this->frontNode->next;
        if (this->frontNode) 
        {
            this->frontNode->previous = nullptr;
        }
        delete temp;
    }

    //! Pushes element in the back of the list
    //! @param element The item being added
    void enqueue(const T& element)
    {
        Node* newNode = new Node(element, nullptr, this->backNode);
        if (this->empty()) 
        {
            this->frontNode = newNode;
        }
        else 
        {
            this->backNode->next = newNode;
        }
        this->backNode = newNode;
    }

    //! Checks if the list is empty
    //! @return Bool value
    bool empty() const
    {
        return this->frontNode == nullptr;
    }

    //! Calculates the size of the list
    //! @return Size of the list
    std::size_t size() const{
        std::size_t result = 0;
        Node* current = frontNode;
        while(current != nullptr){
            current = current->next;
            ++result;
        }

        return result;
    }

    //! Destuctor
    ~LinkedQueue()
    {
        this->deallocate();
    }
};