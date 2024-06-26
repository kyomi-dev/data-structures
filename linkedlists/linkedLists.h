typedef struct Node {
    int data;
    struct Node* next;
} Node;

void display(Node* node);

Node* create(int value);

bool insert(Node** head, int value, size_t position);

bool del(Node** head, size_t position);

bool concatenate(Node** firstHead, Node** secondHead);

bool isSorted(Node* firstHead);

bool merge(Node** firstHead, Node** secondHead);

bool isLoop(Node* first);