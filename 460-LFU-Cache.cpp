
struct Node
{
    int key, value, cnt;
    Node* prev;
    Node* next;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
       
        cnt = 1;
    }
};

class LFUCache
{
    unordered_map<int, Node*> keyNode;
    map<int, list<Node*>> freqListMap;

    int capacity;
    int currCapacity;
    int minFreq;

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        currCapacity = 0;
        minFreq = 0;
    }

    void updateFreqListMap(Node* node)
    {
        int oldFreq = node->cnt;

        // Reference to the existing list; no copying
        auto& currentList = freqListMap[oldFreq];
        currentList.remove(node);

        if (oldFreq == minFreq && currentList.empty())
        {
            minFreq++;

            // Remove the empty frequency entry
            freqListMap.erase(oldFreq);
        }

        node->cnt++;

        // Direct reference to the higher-frequency list
        auto& nextList = freqListMap[node->cnt];
        nextList.push_front(node);
    }

    int get(int key)
    {
        auto it = keyNode.find(key);

        if (it == keyNode.end())
            return -1;

        Node* node = it->second;
        int val = node->value;

        updateFreqListMap(node);

        return val;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;

        auto it = keyNode.find(key);

        if (it != keyNode.end())
        {
            Node* node = it->second;
            node->value = value;

            updateFreqListMap(node);
            return;
        }

        if (currCapacity == capacity)
        {
            // Reference to the minimum-frequency list
            auto& leastList = freqListMap[minFreq];

            Node* victim = leastList.back();

            keyNode.erase(victim->key);
            leastList.pop_back();

            if (leastList.empty())
                freqListMap.erase(minFreq);

            delete victim;
            currCapacity--;
        }

        Node* node = new Node(key, value);

        minFreq = 1;

        // Directly modify the list in the map
        auto& newList = freqListMap[1];
        newList.push_front(node);

        keyNode[key] = node;
        currCapacity++;
    }
};
