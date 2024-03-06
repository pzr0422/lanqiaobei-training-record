# 算法竞赛中常用的STL(c++)

## 1. vector

### 1.1 vector的特性

vector的主要作用在于代替==数组==

c语言中，声明的数组必须是==定长==的，后续如果想要添加非常的不方便， vector的==动态性==很好地解决了这一点

总而言之，vector是==动态数组容器==，只能够存储==相同类型==的数据，能根据需求==自动改变大小==

vector的声明方法如下：

```c++
vector<Type> v; 
```

### 1.2 vector中元素的访问

可以用数组式的[  ]，或者使用at()函数

遍历vector时，可以使用size()函数，其中需要注意：

size()的返回值是==unsigned int==类型，如果vector为空的话，size()-1就会是一个很大的正数（计算机存储规则），在循环时要注意这一点，结束条件最好选择"< size()", 而不是"<=size() - 1"

```c++
for(int i = 0; i < v.size(); i++){
	...
}
```

### 1.3 添加和删除元素

#### 1.3.1 push_back

在vector容器末端添加元素

此函数声明如下：

```c++
void push_back(const T& value)
```

#### 1.3.2 pop_back

删除vector容器的首元素/尾元素

```c++
void pop_back()
```

#### 1.3.3 insert

在指定位置插入元素，vector大小也跟着变化

示例：

```c++
v.insert(v.begin() + 2, 3);//表示在下标为2的地方插入3
```

#### 1.3.4 erase（多和unique函数合用，用于去除重复元素）

删除指定位置或指定区间的元素，vector大小也跟着变化

示例：

```c++
//注意：调用unique()函数后，重复的元素只是被放在了后面，并没有被删除
vector<int> v = {1, 1, 2, 2, 3};
auto it = unique(v.begin(), v.end());//此时v中元素为1, 2, 3, 1, 2
//此处it的值为指向末尾1的指针
v.erase(it, v.end());//利用unique的返回值，将重复的元素去除

//也可以将unique函数的调用直接放进erase函数里当做参数（也算是一种活用）
v.erase(unique(v.begin(), v.end()), v.end());
```

也可以进入我的主页，查看==《竞赛中常用的库函数》==这篇文章

### 1.4 判空操作（empty）

### 1.5 提供迭代器（使用begin()和end()）

使用迭代器==遍历==vector的示例

```c++
vector<int> vec = {10, 20, 30};
for(auto it = vec.begin(); it != vec.end(); it++){
    cout << *it << ' '; 
}
```

其中需要注意：

1. 使用迭代器进行遍历时，并没有==大小关系==，也就是这里的判断条件不能写成“it < vec.end()”
2. 使用迭代器所指向的元素时，记得加上“*”来解引用
3. 对于迭代器，==“++”==符号已经==重载==过了，不用担心这里会出问题

### 1.6 clear（清空向量）

直接==清空==vector中的元素，使其变为空向量

```c++
v.clear();
```

## 2. stack

### 2.1 定义与结构

经典的==栈==结构

### 2.2 常用函数

1.  push(x)-->将元素x压入栈中
2. pop()-->将栈顶元素弹出
3. top()-->返回栈顶元素的值
4. empty()-->判空
5. size()-->返回栈中元素的个数

注意：stack==不能遍历==

## 3. queue

### 3.1 常用函数

1.  push(x)-->将元素x插入队尾
2. pop()-->将队首元素弹出
3. front()-->返回队首元素的值，==但不会弹出==，常与pop()合用
4. empty()-->判空
5. size()-->返回队列中元素的个数

## 4. ==priority_queue==（重要）（经常碰到）

### 4.1 优先队列的特点

其中元素是按照==从大到小==的位置排序的，也就是说top()返回的元素是整个队列中==最大的==

优先队列默认为==大根堆==

优先队列实际上是==堆==结构

### 4.2 常用函数

1.  push(x)-->将元素x插入队尾
2. pop()-->将队首元素弹出
3. top()-->返回队首元素的值（整个队列中最大）
4. empty()-->判空
5. size()-->返回队列中元素的个数

### 4.3 如何修改优先队列的比较函数

```c++
struct Compare{
	bool operator () (int a, int b){
        //自定义的比较函数
        return a > b;
    }
}

//声明：
priority_queue<int, vector<int>, Compare> pq;//第二个参数是底层容器类型
//或：
priority_queue<int, vector<int>, greater<int>> pq;//第三个参数默认是less<int>
```



## 5. deque（双端队列）

允许在==两端==进行高效的==插入和删除==操作（也就是说，当题目对两端的要求较高时可以使用deque容器）

### 5.1 常用函数

1. pop_back()-->删除队尾元素
2. pop_front()-->删除队首元素
3. push_back(x)-->向队尾添加元素x
4. push_front(x)-->向队首添加元素x
5. front()-->返回队首元素
6. back()-->返回队尾元素
7. empty()-->判空
8. size()-->返回队列中元素的个数
9. clear()-->清空队列

### 5.2 常用来实现==单调队列==

## 6. pair

可以将两个==不同类型==的数据组合在一起，方便存储与输出

### 6.1 pair当中的参数

1. first
2. second

### 6.2 用法

```c++
pair<int, double> p1(1, 3,14);
pair<char, string> p2('a', "Hello");

cout << p1.first << ' ' << p1.second << endl;
cout << p2.first << ' ' << p2.second << endl;
```

可以使用函数==make_pair==来初始化pair

### 6.3 嵌套（例：三维坐标点）

```
pair<int, pair<int, int>> p3(3, make_pair(4, 5));
```

### 6.4 排序规则

pair自带的排序规则：

1. 先按照first成员的大小进行==升序==排序
2. 如果first成员的大小一致，那么就按照second成员的大小进行==升序==排序

根据以上规则，在使用sort这类函数对pair排序时，会先根据first成员进行排序

## 7. set

### 7.1 定义和结构

用于存储一组==唯一==的元素，并按照一定的排序规则进行排序，默认为==升序==排列（可以传入自定义比较函数改变排序方式）

```
set<int, greater<int>> s1;
```

值得注意的是，set中==不允许==出现重复的元素，当插入一个重复的元素时，set会自动忽略该元素 

### 7.2 常用函数

1. insert(x)
2. erase(x)
3. find(x)-->返回x所在的==迭代器==，如果x==不存在==，那么就返回==end迭代器==
4. lower_bound()
5. upper_bound()
6. begin()
7. end()
8. ==rbegin()==-->返回指向集合==末尾==的==逆向==迭代器
9. ==rend==()-->返回指向集合==起始位置==的==逆向==迭代器

## 8. multi_set（可以存放重复元素）

需要注意：

multi_set中如果有重复元素x，那么调用erase(x)后，会将所有重复的x删掉，如果只想删除一个，那么就要传入迭代器：

```
st.erase(st.find(x));//删除第一个出现的x
```

## 9. map

是一种==关联容器==，用于存储一对==键值对==（key/value）

默认是==升序排列==

### 9.1 常用函数

1. insert({k,v})
2. erase(key)，或者可以传入迭代器构成的区间，但一般不用这种形式
3. find(key)-->返回
4. count(key)-->多用于判断某个key是否存在
5. size()-->统计元素个数
6. begin()
7. end()
8. empty()
9. clear()
10. lower_bound()
11. upper_bound()

### 9.2 声明及应用

```c++
map<int, string> myMap = {{1, "Apple"}, {2, "Banana"}, {3, "Orange"}};
//插入元素（使用pair插入）
myMap.insert(make_pair(4, "Grapes"));
//或:myMap.insert({4, "Grapes"});

cout << "Value at Key2: " << myMap[2] << endl;//返回"Banana"（返回值）

//遍历map中的元素
for(auto &pair : myMap){
    cout << "Key: " << pair.first << ' ' << "Value: " << pair.second << endl;
}
```















































