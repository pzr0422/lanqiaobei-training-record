# c++ string的用法

## 1. 优点

### 1.1 内存空间自动管理

### 1.2 安全性--防止越界

### 1.3 兼容迭代器

## 2. 声明方式

### 2.1 直接用一个字符串来赋值

```c++
string str1 = "hello, world"
```

### 2.2 用其他的string变量赋值

```c++
string str2 = str1;
```

### 2.3 使用子字符串/部分字符串(substr)来赋值

```c++
string str3 = str2.substr(0, 5);//“hello”
//substr的两个参数的意思分别为“起始位置”和“截取长度”
string str4 = str2.substr(0);//"hello, world"
//若忽略第二个参数“截取长度”，则直接截取到字符串的末尾位置
```

### 2.4 把string看作类，使用构造函数来初始化

```c++
char *charArray = "hello";
string str5(charArray);

//使用重复字符初始化
string str6(5, 'a');
```

## 3. 关于getline()函数

getline函数通常用于读入一行字符串（遇到空格或者回车不会停下）

对比另一种方式：

```c++
cin >> str1;//如果str1里有空格或者回车，就停止输入
```

## 4. 基本操作

### 4.1 c_str（将string类型的变量转变为c风格字符串）

如果想要用==printf==来打印string类型的变量str, 那么就要使用string类中的方法的c_str

```c++
printf("%s", str.c_str());
```

### 4.2 获取字符串长度（length/size）（使用的时候在前面加上强制类型转换(int)）

```c++
int len = str.length();
//int len = str.size();
```

### 4.3 字符串拼接（append或+）

```c++
string str1 = "hello";
string str2 = "world";
string str3 = str1.append(str2);
string str4 = str1 + str2;
```

### 4.4 字符串查找（find）

作用：返回子字符串的起始位置， 若没有找到，则返回-1

```c++
string str1 = "Hello, World!";
int pos = str1.find("World");//pos = 7
```

### 4.5 字符串替换（replace）

```c++
string str1 = "Hello, World!";
str1.replace(7, 5, "universe");// str1 = "Hello, universe"
//参数的含义：replace(要替换的起始位置， 替换的长度， 替换成什么)
```

### 4.6 提取子字符串（substr）

上面已经提到过：

```c++
string str3 = str2.substr(0, 5);//“hello”
//substr的两个参数的意思分别为“起始位置”和“截取长度”
string str4 = str2.substr(0);//"hello, world"
//若忽略第二个参数“截取长度”，则直接截取到字符串的末尾位置
```

这里尤其要注意参数==不要越界==

### 4.7 字符串比较（compare）

这里的compare是按照==字典序==来比较的

```c++
string str1 = "aaa";
string str2 = "bbb";
int result = str1.compare(str2);//result < 0 
```

值得注意的是，由于==string==高度封装，也可以直接用“>”, “<”, “==”来比较

### 4.8 遍历

```c++
string str = "Hello";
//1.使用下标进行枚举
for(int i = 0; i < str.length(); i++){
	cout << str[i];
}

//2.使用auto类型进行枚举
for(auto i : str){
    cout << i;
    i = 'a';//此处的修改没有起作用，i只是复制了原str中的字符，这个语句只能修改i的值
}

for(auto &i = str){
    cout << i;
    i = 'a';//此处的修改有作用，i作为str中字符的引用，改变i可以改变str中的字符
}
```

### 4.9 字符串反转（reverse）

```c++
string str = "...";
reverse(str.begin(), str.end());//反转的起始位置和终止位置
```



































