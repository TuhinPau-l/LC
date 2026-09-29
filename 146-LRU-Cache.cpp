
struct Node
{
    int key,value;
    Node* prev,*next;
    Node(int key,int value)
    {
        this->key=key;
        this->value=value;
        prev=NULL;
        next=NULL;
    }
};


class LRUCache {
    unordered_map<int,Node*>mpp;
    int capacity;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head; 
        
    }
    
    int get(int key) {
        
        if(!mpp.contains(key))
        return -1;

        Node* node=mpp[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }
    
    void put(int key, int value) {

        if(mpp.contains(key))
        {
            Node* node=mpp[key];
            node->value=value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else
        {
            if(mpp.size()==capacity)
            {
                Node* node=tail->prev;
                deleteNode(node);
                mpp.erase(node->key);
            }

            Node* node=new Node(key,value);
            insertAfterHead(node);
            mpp[key]=node;
        }
        
    }
    void deleteNode(Node* node)
    {
        Node* prevNode,*afterNode;
        prevNode=node->prev;
        afterNode=node->next;
        prevNode->next=afterNode;
        afterNode->prev=prevNode;
    }
    void insertAfterHead(Node* node)
    {
        Node* currAfterHead;
        currAfterHead=head->next;
        currAfterHead->prev=node;
        node->next=currAfterHead;
        head->next=node;
        node->prev=head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */