# 竞赛中c++语言输入输出的注意事项

## 1. printf scanf

优势：

1. 可以格式化输入输出
2. 效率比较高（运行快）

### 1.1 输入字符串时的一个要点：

```c++
//例如：现在想要输入"Hello World"，并输入
char s[15];
scanf("%s", s);//此处输入"Hello World"
printf("%s", s);//仅输出"Hello“
//原因，%s碰到空格或回车就不再读入了

//解决方法如下：
char s[15];
scanf("%[^\n]", s);//利用正则表达式（意义为除了回车）
printf("%s", s);
```

## 2. cin cout

### 2.1 使用cin cout如何保留x位小数输出

```c++
//在输入/出前加入参数
cout << fixed << setprecision(3) << ...
```

### 2.2 cin输入字符串时遇到空格或者回车时也会停止

### 2.3 取消同步流（加快读入输出的效率）

使cin/cout与scanf/printf的速度相差无几

```c++
//取消同步流
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
```





























