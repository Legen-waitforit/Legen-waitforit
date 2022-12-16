#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    int count = 0, base = 1;
    // cell 每轮一分为二，形成数列 1, 2, 4, 8, ..., 2^(n-1)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < base; j++) {
            count++;
        }
        base *= 2;
    }
    cout << "count = " << count << endl;
    //(2**n) - 1
    return 0;
}

/* 指数阶（递归实现） */
//O(2**n)
int expRecur(int n) {
    if (n == 1) return 1;
    return expRecur(n - 1) + expRecur(n - 1) + 1;
}

/* 对数阶（循环实现） */
//O(logn)
//对数阶常出现于「二分查找」和「分治算法」中，体现 “一分为多” 、“化繁为简” 的算法思想
int logarithmic(float n) {
    int count = 0;
    while (n > 1) {
        n = n / 2;
        count++;
    }
    return count;
}

/* 对数阶（递归实现） */
//O(logn)
int logRecur(float n) {
    if (n <= 1) return 0;
    return logRecur(n / 2) + 1;
}

/* 线性对数阶 */
//主流排序算法的时间复杂度都是 O(nlogn) ，例如快速排序、归并排序、堆排序等。
int linearLogRecur(float n) {
    if (n <= 1) return 1;
    int count = linearLogRecur(n / 2) + 
                linearLogRecur(n / 2);
    for (int i = 0; i < n; i++) {
        count++;
    }
    return count;
}

/* 阶乘阶（递归实现） */
//O(n!)
int factorialRecur(int n) {
    if (n == 0) return 1;
    int count = 0;
    // 从 1 个分裂出 n 个
    for (int i = 0; i < n; i++) {
        count += factorialRecur(n - 1);
    }
    return count;
}

/* 线性阶（递归实现） */
//空间复杂度 O(n)
void linearRecur(int n) {
    cout << "递归 n = " << n << endl;
    if (n == 1) return;
    linearRecur(n - 1);
}


/* 平方阶 */
//空间复杂度 O(n^2)
void quadratic(int n) {
    // 二维列表占用 O(n^2) 空间
    vector<vector<int>> numMatrix;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            tmp.push_back(0);
        }
        numMatrix.push_back(tmp);
    }
}

/* 平方阶（递归实现） */
//以下递归函数中，同时存在n个未返回的algorihtm() ，并且每个函数中都初始化了一个数组，长度分别为n,n-1,n-2,..2,1,平均长度为n/2
//空间为O(n^2)
int quadraticRecur(int n) {
    if (n <= 0) return 0;
    vector<int> nums(n);
    cout << "递归 n = " << n << " 中的 nums 长度 = " << nums.size() << endl;
    return quadraticRecur(n - 1);
}


/* 指数阶（建立满二叉树） */
//指数阶常见于二叉树。高度为  的「满二叉树」的结点数量为2^n -1
//空间为O(2^n)
TreeNode* buildTree(int n) {
    if (n == 0) return nullptr;
    TreeNode* root = new TreeNode(0);
    root->left = buildTree(n - 1);
    root->right = buildTree(n - 1);
    return root;
}

//对数阶常见于分治算法、数据类型转换等。例如「归并排序」


//两数之和 辅助哈希表法
vector<int> twoSum(vector<int>& nums, int target) {
        
    int size = nums.size();
    // 辅助哈希表，空间复杂度 O(n)
    unordered_map<int, int> dic;
    // 单层循环，时间复杂度 O(n)
    for (int i = 0; i < size; i++) {
        if (dic.find(target - nums[i]) != dic.end()) {
            return { dic[target - nums[i]], i };
        }
        dic.emplace(nums[i], i);
    }
    return {};
}


/* 初始化链表 1 -> 3 -> 2 -> 5 -> 4 */
// 初始化各个结点 
ListNode* n0 = new ListNode(1);
ListNode* n1 = new ListNode(3);
ListNode* n2 = new ListNode(2);
ListNode* n3 = new ListNode(5);
ListNode* n4 = new ListNode(4);
// 构建引用指向
n0->next = n1;
n1->next = n2;
n2->next = n3;
n3->next = n4;


/* 在链表的结点 n0 之后插入结点 P */
void insert(ListNode* n0, ListNode* P) {
    //n1为一开始n0后面的节点
    ListNode* n1 = n0->next;
    n0->next = P;
    P->next = n1;
}

/* 删除链表的结点 n0 之后的首个结点 */
void remove(ListNode* n0) {
    if (n0->next == nullptr)
        return;
    // n0 -> P -> n1
    ListNode* P = n0->next;
    ListNode* n1 = P->next;
    n0->next = n1;
}

/* 在链表中查找值为 target 的首个结点 */
//输出target索引
int find(ListNode* head, int target) {
    int index = 0;
    while (head != nullptr) {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}
/* 链表结点结构体 */
struct ListNode {
    int val;         // 结点值
    ListNode *next;  // 指向后继结点的指针（引用）
    ListNode *prev;  // 指向前驱结点的指针（引用）
    ListNode(int x) : val(x), next(nullptr) {}  // 构造函数
};

//列表可以被理解为长度可变的数组，因此也常被称为「动态数组 Dynamic Array」
/* 初始化列表 */
vector<int> list = { 1, 3, 2, 5, 4 };
/* 访问元素 */
int num = list[1];  // 访问索引 1 处的元素
/* 更新元素 */
list[1] = 0;  // 将索引 1 处的元素更新为 0

//在列表中添加、插入、删除元素。 相对于数组，列表可以自由地添加与删除元素。在列表尾部添加元素的时间复杂度为 O(1)，但是插入与删除元素的效率仍与数组一样低，时间复杂度为 O(N)
/* 清空列表 */
list.clear();
/* 尾部添加元素 */
list.push_back(1);
list.push_back(3);
list.push_back(2);
list.push_back(5);
list.push_back(4);
/* 中间插入元素 */
list.insert(list.begin() + 3, 6);  // 在索引 3 处插入数字 6

/* 删除元素 */
list.erase(list.begin() + 3);      // 删除索引 3 处的元素

/* 通过索引遍历列表 */
int count = 0;
for (int i = 0; i < list.size(); i++) {
    count++;
}
/* 直接遍历列表元素 */
count = 0;
for (int n : list) {
    count++;
}

/* 拼接两个列表 */
vector<int> list1 = { 6, 8, 7, 10, 9 };
// 将列表 list1 拼接到 list 之后
list.insert(list.end(), list1.begin(), list1.end());

/* 排序列表 */
sort(list.begin(), list.end());  // 排序后，列表元素从小到大排列

class MyList {
private:
    int* nums;                // 数组（存储列表元素）
    int numsCapacity = 10;    // 列表容量
    int numsSize = 0;         // 列表长度（即当前元素数量）
    int extendRatio = 2;      // 每次列表扩容的倍数

public:
    /* 构造函数 */
    MyList() {
        nums = new int[numsCapacity];
    }

    /* 获取列表长度（即当前元素数量）*/
    int size() {
        return numsSize;
    }

    /* 获取列表容量 */
    int capacity() {
        return numsCapacity;
    }

    /* 访问元素 */
    int get(int index) {
        // 索引如果越界则抛出异常，下同
        if (index >= size())
            throw out_of_range("索引越界");
        return nums[index];
    }

    /* 更新元素 */
    void set(int index, int num) {
        if (index >= size())
            throw out_of_range("索引越界");
        nums[index] = num;
    }

    /* 尾部添加元素 */
    void add(int num) {
        // 元素数量超出容量时，触发扩容机制
        if (size() == capacity())
            extendCapacity();
        nums[size()] = num;
        // 更新元素数量
        numsSize++;
    }

    /* 中间插入元素 */
    void insert(int index, int num) {
        if (index >= size())
            throw out_of_range("索引越界");
        // 元素数量超出容量时，触发扩容机制
        if (size() == capacity())
            extendCapacity();
        // 索引 i 以及之后的元素都向后移动一位
        for (int j = size() - 1; j >= index; j--) {
            nums[j + 1] = nums[j];
        }
        nums[index] = num;
        // 更新元素数量
        numsSize++;
    }

    /* 删除元素 */
    int remove(int index) {
        if (index >= size())
            throw out_of_range("索引越界");
        int num = nums[index];
        // 索引 i 之后的元素都向前移动一位
        for (int j = index; j < size() - 1; j++) {
            nums[j] = nums[j + 1];
        }
        // 更新元素数量
        numsSize--;
        // 返回被删除元素
        return num;
    }

    /* 列表扩容 */
    void extendCapacity() {
        // 新建一个长度为 size * extendRatio 的数组，并将原数组拷贝到新数组
        int newCapacity = capacity() * extendRatio;
        int* extend = new int[newCapacity];
        // 将原数组中的所有元素复制到新数组
        for (int i = 0; i < size(); i++) {
            extend[i] = nums[i];
        }
        int* temp = nums;
        nums = extend;
        delete[] temp;
        numsCapacity = newCapacity;
    }
};


/* 初始化栈 */
stack<int> stack;

/* 元素入栈 */
stack.push(1);
stack.push(3);
stack.push(2);
stack.push(5);
stack.push(4);

/* 访问栈顶元素 */
int top = stack.top();

/* 元素出栈 */
stack.pop();

/* 获取栈的长度 */
int size = stack.size();

/* 判断是否为空 */
bool empty = stack.empty();

/* 基于链表实现的栈 */
class LinkedListStack {
private:
    ListNode* stackTop; // 将头结点作为栈顶
    int stkSize;        // 栈的长度

public:
    LinkedListStack() {
        stackTop = nullptr;
        stkSize = 0;
    }
    /* 获取栈的长度 */
    int size() {
        return stkSize;
    }
    /* 判断栈是否为空 */
    bool empty() {
        return size() == 0;
    }
    /* 入栈 */
    void push(int num) {
        ListNode* node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;
        stkSize++;
    }
    /* 出栈 */
    int pop() {
        int num = top();
        stackTop = stackTop->next;
        stkSize--;
        return num;
    }
    /* 访问栈顶元素 */
    int top() {
        if (size() == 0)
            throw out_of_range("栈为空");
        return stackTop->val;
    }
};

/* 基于数组实现的栈 */
class ArrayStack {
private:
    vector<int> stack;

public:
    /* 获取栈的长度 */
    int size() {
        return stack.size();
    }
    /* 判断栈是否为空 */
    bool empty() {
        return stack.empty();
    }
    /* 入栈 */
    void push(int num) {
        stack.push_back(num);
    }
    /* 出栈 */
    int pop() {
        int oldTop = stack.back();
        stack.pop_back();
        return oldTop;
    }
    /* 访问栈顶元素 */
    int top() {
        return stack.back();
    }
    /* 访问索引 index 处元素 */
    int get(int index) {
        return stack[index];
    }
};

/* 初始化队列 */
queue<int> queue;

/* 元素入队 */
queue.push(1);
queue.push(3);
queue.push(2);
queue.push(5);
queue.push(4);

/* 访问队首元素 */
int front = queue.front();

/* 元素出队 */
queue.pop();

/* 获取队列的长度 */
int size = queue.size();

/* 判断队列是否为空 */
bool empty = queue.empty();

/* 基于链表实现的队列 */
class LinkedListQueue {
private:
    ListNode *front, *rear;  // 头结点 front ，尾结点 rear 
    int queSize;

public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
        queSize = 0;
    }
    /* 获取队列的长度 */
    int size() {
        return queSize;
    }
    /* 判断队列是否为空 */
    bool empty() {
        return queSize == 0;
    }
    /* 入队 */
    void offer(int num) {
        // 尾结点后添加 num
        ListNode* node = new ListNode(num);
        // 如果队列为空，则令头、尾结点都指向该结点
        if (front == nullptr) {
            front = node;
            rear = node;
        }
        // 如果队列不为空，则将该结点添加到尾结点后
        else {
            rear->next = node;
            rear = node;
        }
        queSize++;
    }
    /* 出队 */
    int poll() {
        int num = peek();
        // 删除头结点
        front = front->next;
        queSize--;
        return num;
    }
    /* 访问队首元素 */
    int peek() {
        if (size() == 0)
            throw out_of_range("队列为空");
        return front->val;
    }
};

/* 基于环形数组实现的队列 */
class ArrayQueue {
private:
    int *nums;      // 用于存储队列元素的数组
    int cap;        // 队列容量
    int front = 0;  // 头指针，指向队首
    int rear = 0;   // 尾指针，指向队尾 + 1

public:
    ArrayQueue(int capacity) {
        // 初始化数组
        cap = capacity;
        nums = new int[capacity];
    }
    /* 获取队列的容量 */
    int capacity() {
        return cap;
    }
    /* 获取队列的长度 */
    int size() {
        // 由于将数组看作为环形，可能 rear < front ，因此需要取余数
        return (capacity() + rear - front) % capacity();
    }
    /* 判断队列是否为空 */
    bool empty() {
        return rear - front == 0;
    }
    /* 入队 */
    void offer(int num) {
        if (size() == capacity()) {
            cout << "队列已满" << endl;
            return;
        }
        // 尾结点后添加 num
        nums[rear] = num;
        // 尾指针向后移动一位，越过尾部后返回到数组头部
        rear = (rear + 1) % capacity();
    }
    /* 出队 */
    int poll() {
        int num = peek();
        // 队头指针向后移动一位，若越过尾部则返回到数组头部
        front = (front + 1) % capacity();
        return num;
    }
    /* 访问队首元素 */
    int peek() {
        // 删除头结点
        if (empty())
            throw out_of_range("队列为空");
        return nums[front];
    }
    /* 访问指定位置元素 */
    int get(int index) {
        if (index >= size())
            throw out_of_range("索引越界");
        return nums[(front + index) % capacity()]
    }
};

/* 初始化双向队列 */
deque<int> deque;

/* 元素入队 */
deque.push_back(2);   // 添加至队尾
deque.push_back(5);
deque.push_back(4);
deque.push_front(3);  // 添加至队首
deque.push_front(1);

/* 访问元素 */
int front = deque.front(); // 队首元素
int back = deque.back();   // 队尾元素

/* 元素出队 */
deque.pop_front();  // 队首元素出队
deque.pop_back();   // 队尾元素出队

/* 获取双向队列的长度 */
int size = deque.size();

/* 判断双向队列是否为空 */
bool empty = deque.empty();

